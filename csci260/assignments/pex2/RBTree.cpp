// CHRISTOPHER NILSSEN RBTree.cpp for ASSIGNMENT 02 CSCI 260 F2402
#include "RBTree.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// implementation of the RBTreeNode constructor
RBTreeNode::RBTreeNode(Customer* cust)
    : customer(cust), color(RED), parent(nullptr), left(nullptr), right(nullptr) {
    // constructor body (empty since initialization is done above)
}

// implementation of the RBTree constructor
RBTree::RBTree() {
    // initialize the NIL node
    NIL = new RBTreeNode(nullptr);
    NIL->color = BLACK;
    NIL->left = NIL->right = NIL->parent = NIL;
    root = NIL;
}

// implementation of the RBTree destructor
RBTree::~RBTree() {
    destroyTree(root);
    delete NIL;
}

// helper function to destroy the tree and free memory
void RBTree::destroyTree(RBTreeNode* node) {
    if (node != NIL) {
        destroyTree(node->left);
        destroyTree(node->right);
        // delete node->customer; // optional deletion of customer data via tree, not optimal
        delete node;
    }
}

// left rotate around node x
void RBTree::leftRotate(RBTreeNode* x) {
    RBTreeNode* y = x->right;
    x->right = y->left;
    if (y->left != NIL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NIL) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// right rotate around node y
void RBTree::rightRotate(RBTreeNode* y) {
    RBTreeNode* x = y->left;
    y->left = x->right;
    if (x->right != NIL) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NIL) {
        root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}

// insert a new customer into the red-black tree
void RBTree::insert(Customer* customer) {
    RBTreeNode* z = new RBTreeNode(customer);
    z->left = z->right = z->parent = NIL;

    RBTreeNode* y = NIL;
    RBTreeNode* x = root;

    while (x != NIL) {
        y = x;
        if (z->customer->customerID < x->customer->customerID) {
            x = x->left;
        } else if (z->customer->customerID > x->customer->customerID) {
            x = x->right;
        } else {
            // customerID already exists, do not insert
            delete z->customer;
            delete z;
            return;
        }
    }

    z->parent = y;
    if (y == NIL) {
        root = z;
    } else if (z->customer->customerID < y->customer->customerID) {
        y->left = z;
    } else {
        y->right = z;
    }

    z->color = RED;
    insertFixup(z);
}

// fix up the tree after insertion to maintain red-black properties
void RBTree::insertFixup(RBTreeNode* z) {
    while (z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            RBTreeNode* y = z->parent->parent->right; // uncle
            if (y->color == RED) {
                // case 1: uncle is red
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    // case 2: z is right child
                    z = z->parent;
                    leftRotate(z);
                }
                // case 3: z is left child
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } else {
            // mirror cases for when z's parent is right child
            RBTreeNode* y = z->parent->parent->left; // uncle
            if (y->color == RED) {
                // case 1: uncle is red
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    // case 2: z is left child
                    z = z->parent;
                    rightRotate(z);
                }
                // case 3: z is right child
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

// search for a customer by customerID
RBTreeNode* RBTree::search(int customerID) const {
    RBTreeNode* current = root;
    while (current != NIL) {
        if (customerID == current->customer->customerID) {
            return current;
        } else if (customerID < current->customer->customerID) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nullptr; // customer not found
}

// public method to perform in-order traversal
void RBTree::inOrderTraversal() const {
    inOrderTraversalHelper(root);
}

// helper function for in-order traversal
void RBTree::inOrderTraversalHelper(RBTreeNode* node) const {
    if (node != NIL) {
        inOrderTraversalHelper(node->left);
        // process the node's customer data
        cout << "Customer ID: " << node->customer->customerID
             << ", Name: " << node->customer->name << endl;
        inOrderTraversalHelper(node->right);
    }
}

// method to check for empty tree
bool RBTree::isEmpty() const {
    return root == NIL;
}
