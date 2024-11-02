// CHRISTOPHER NILSSEN BST.cpp for ASSIGNMENT 02 CSCI 260 F2402
#include "BST.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// implementation of the BSTNode constructor
BSTNode::BSTNode(Customer* cust)
    : customer(cust), left(nullptr), right(nullptr) {
    // constructor body (empty since initialization is done above)
}

// implementation of the BST constructor
BST::BST() : root(nullptr) {
    // constructor body (empty)
}

// implementation of the BST destructor
BST::~BST() {
    destroyTree(root);
}

// helper function to destroy the tree and free memory
void BST::destroyTree(BSTNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        // delete node->customer; // optional deletion of customer data via tree, not optimal
        delete node;
    }
}

// insert a new customer into the binary search tree
void BST::insert(Customer* customer) {
    insertNode(root, customer);
}

// recursive helper function to insert a node
void BST::insertNode(BSTNode*& node, Customer* customer) {
    if (node == nullptr) {
        node = new BSTNode(customer);
    } else if (customer->email < node->customer->email) {
        insertNode(node->left, customer);
    } else if (customer->email > node->customer->email) {
        insertNode(node->right, customer);
    } else {
        // email already exists, do not insert
        // handle duplicate email if necessary
        // in this implementation, we do nothing
    }
}

// search for a customer by email
BSTNode* BST::search(const string& email) const {
    return searchNode(root, email);
}

// recursive helper function to search for a node
BSTNode* BST::searchNode(BSTNode* node, const string& email) const {
    if (node == nullptr) {
        return nullptr; // customer not found
    } else if (email == node->customer->email) {
        return node; // customer found
    } else if (email < node->customer->email) {
        return searchNode(node->left, email);
    } else {
        return searchNode(node->right, email);
    }
}

// public method to perform in-order traversal, accounts for no active subscribers
int BST::inOrderTraversal() const {
    int activeCount = 0;
    inOrderTraversalHelper(root, activeCount);
    return activeCount;
}

// helper function for in-order traversal
void BST::inOrderTraversalHelper(BSTNode* node, int& count) const {
    if (node != nullptr) {
        inOrderTraversalHelper(node->left, count);
        // process the node's customer data, account for spam command
        if (node->customer->isActive) {
            cout << "Email: " << node->customer->email
                 << ", Name: " << node->customer->name << endl;
            ++count;
        }
        inOrderTraversalHelper(node->right, count);
    }
}

// method to check for empty tree
bool BST::isEmpty() const {
    return root == nullptr;
}