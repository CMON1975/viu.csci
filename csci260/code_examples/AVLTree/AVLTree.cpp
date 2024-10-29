#include <iostream>
#include "AVLTree.h"
using namespace std;

AVLTree::AVLTree() : root(0) {}

AVLTree::~AVLTree() {
    destroy(root);
}

void AVLTree::destroy(Node* r) {
    if (r == 0) return;
    destroy(r->left);
    destroy(r->right);
    delete r;
}

void AVLTree::inOrder() const {
    inOrder(root);
    cout << endl;
}

void AVLTree::inOrder(Node* r) const {
    if (r == 0) return;
    inOrder(r->left);
    cout << r->data << "(" << r->balance << ")" << " ";
    inOrder(r->right);
}

void AVLTree::preOrder() const {
    preOrder(root);
    cout << endl;
}

void AVLTree::preOrder(Node* r) const {
    if (r == 0) return;
    cout << r->data << "(" << r->balance << ")" << " ";
    preOrder(r->left);
    preOrder(r->right);
}

void AVLTree::postOrder() const {
    postOrder(root);
    cout << endl;
}

void AVLTree::postOrder(Node* r) const {
    if (r == 0) return;
    postOrder(r->left);
    postOrder(r->right);
    cout << r->data << "(" << r->balance << ")" << " ";
}

void AVLTree::insert(double k) {
    insert(root, k);
}

bool AVLTree::insert(Node*& curr, double k) {
    if (curr == 0) {
        curr = new Node{k, 0, 0, 0};
        return true;
    }

    if (curr->data == k) {
        cout << "Duplicate Key\n";
        return false;
    }

    bool heightIncreased;
    if (k < curr->data) {
        heightIncreased = insert(curr->left, k);
        if (heightIncreased) adjustBalanceLeft(curr);
    } else {
        heightIncreased = insert(curr->right, k);
        if (heightIncreased) adjustBalanceRight(curr);
    }
    return heightIncreased;
}

void AVLTree::leftRotation(Node*& ptr) {
    Node* temp = ptr->right;
    ptr->right = temp->left;
    temp->left = ptr;

    // Update balance factors
    if (temp->balance == 1) {  // Left-heavy case
        ptr->balance = 0;
        temp->balance = 0;
    } else if (temp->balance == 0) {  // Equal height before rotation
        ptr->balance = 1;
        temp->balance = -1;
    }
    ptr = temp;
}



void AVLTree::rightRotation(Node*& ptr) {
    Node* temp = ptr->left;
    ptr->left = temp->right;
    temp->right = ptr;

    // Update balance factors
    if (temp->balance == -1) {  // Right-heavy case
        ptr->balance = 0;
        temp->balance = 0;
    } else if (temp->balance == 0) {  // Equal height before rotation
        ptr->balance = -1;
        temp->balance = 1;
    }
    ptr = temp;
}



void AVLTree::adjustBalanceLeft(Node*& curr) {
    if (curr->balance == 1) {
        curr->balance = 0;
    } else if (curr->balance == 0) {
        curr->balance = -1;
    } else {
        // Double rotation: Left-Right
        if (curr->left->balance == 1) {
            leftRotation(curr->left);
            rightRotation(curr);
            updateBalancesDoubleLeft(curr);
        } else {
            rightRotation(curr);
            curr->balance = 0;
            curr->right->balance = 0;
        }
    }
}


void AVLTree::adjustBalanceRight(Node*& curr) {
    if (curr->balance == -1) {
        curr->balance = 0;
    } else if (curr->balance == 0) {
        curr->balance = 1;
    } else {
        // Double rotation case: Right-Left
        if (curr->right->balance == -1) {
            rightRotation(curr->right);
            leftRotation(curr);
            updateBalancesDoubleRight(curr);
        } else {  // Single left rotation
            leftRotation(curr);
            curr->balance = 0;
            curr->left->balance = 0;
        }
    }
}



void AVLTree::updateBalancesDoubleLeft(Node*& curr) {
    if (curr->balance == -1) {
        curr->left->balance = 0;
        curr->right->balance = 1;
    } else if (curr->balance == 0) {
        curr->left->balance = 0;
        curr->right->balance = 0;
    } else {
        curr->left->balance = -1;
        curr->right->balance = 0;
    }
    curr->balance = 0;
}


void AVLTree::updateBalancesDoubleRight(Node*& curr) {
    if (curr->balance == 1) {
        curr->left->balance = -1;
        curr->right->balance = 0;
    } else if (curr->balance == 0) {
        curr->left->balance = 0;
        curr->right->balance = 0;
    } else {
        curr->left->balance = 0;
        curr->right->balance = 1;
    }
    curr->balance = 0;
}


