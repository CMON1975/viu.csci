// CHRISTOPHER NILSSEN AVLTree.cpp for LAB 05 CSCI 260 F2402
#include "AVLTree.h"
#include <functional>
#include <stack>
#include <algorithm>

using std::stack;
using std::function;

AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree::~AVLTree() {
    // post-order iterate deletion
    if (root == nullptr)
        return;
    
    stack<TreeNode*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        TreeNode* node = nodeStack.top();
        nodeStack.pop();

        if (node->left != nullptr)
            nodeStack.push(node->left);
        if (node->right != nullptr)
            nodeStack.push(node->right);

        delete node;
    }
}

void AVLTree::inOrder() const {
    // traverse in-order
    stack<TreeNode*> stack;
    TreeNode* current = root;

    while (current != nullptr || !stack.empty())  {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();

        cout << current->data << " ";

        current = current->right;
    }
    cout << endl;
}

void AVLTree::preOrder() const {
    if (root == nullptr) {
        cout << endl;
        return;
    }

    stack<TreeNode*> stack;
    stack.push(root);
    
    while (!stack.empty()) {
        TreeNode* node = stack.top();
        cout << node->data << " ";
        stack.pop();

        if (node->right != nullptr)
            stack.push(node->right);
        if (node->left != nullptr)
            stack.push(node->left);
    }
    cout << endl;
}

void AVLTree::postOrder() const {
    if (root == nullptr) {
        cout << endl;
        return;
    }

    stack<TreeNode*> s1, s2;
    s1.push(root);
    TreeNode* node;

    while (!s1.empty()) {
        node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }

    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
    cout << endl;
}

AVLTree::TreeNode* AVLTree::rotateRight(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->balance = 1 + max(y->left ? y->left->balance : 0, y->right ? y->right->balance : 0);
    x->balance = 1 + max(x->left ? x->left->balance : 0, y->balance);

    return x;
}

AVLTree::TreeNode* AVLTree::rotateLeft(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->balance = 1 + max(x->left ? x->left->balance : 0, x->right ? x->right->balance : 0);
    y->balance = 1 + max(y->left ? y->left->balance : 0, y->right ? y->right->balance : 0);

    return y;
}

AVLTree::TreeNode* AVLTree::insertNode(TreeNode* node, double key) {
    if (node == nullptr) {
        return new TreeNode{ key, nullptr, nullptr, 1 };
    }

    if (key < node->data) {
        node->left = insertNode(node->left, key);
    } else if (key > node->data) {
        node->right = insertNode(node->right, key);
    } else {
        return node; // no duplicates
    }

    int leftHeight = node->left ? node->left->balance : 0;
    int rightHeight = node->right ? node->right->balance : 0;
    node->balance = 1 + max(leftHeight, rightHeight);

    int balance = leftHeight - rightHeight;

    // left left case
    if (balance > 1 && key < node->left->data) {
        return rotateRight(node);
    }

    // right right case
    if (balance < -1 && key > node->right->data) {
        return rotateLeft(node);
    }

    // left right case
    if (balance > 1 && key > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // right left case
    if (balance < -1 && key < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::insert(double k) {
    root = insertNode(root, k);
}

AVLTree::TreeNode* AVLTree::deleteNode(TreeNode* node, double key) {
    if (node == nullptr) {
        return node;
    }

    if (key < node->data) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->data) {
        node->right = deleteNode(node->right, key);
    } else {
        if ((node->left == nullptr) || (node->right == nullptr)) {
            TreeNode* temp = node->left ? node->left : node->right;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }

            delete temp;
        } else {
            TreeNode* temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }

            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
    }

    if (node == nullptr) {
        return node;
    }

    int leftHeight = node->left ? node->left->balance : 0;
    int rightHeight = node->right ? node->right->balance : 0;
    node->balance = 1 + max(leftHeight, rightHeight);

    int balance = leftHeight - rightHeight;

    // left left case
    if (balance > 1 && (node->left ? (node->left->left ? node->left->left->balance : 0) >= (node->left->right ? node->left->right->balance : 0) : false)) {
        return rotateRight(node);
    }

    // left right case
    if (balance > 1 && (node->left ? (node->left->left ? node->left->left->balance : 0) < (node->left->right ? node->left->right->balance : 0) : false)) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // right right case
    if (balance < -1 && (node->right ? (node->right->right ? node->right->right->balance : 0) >= (node->right->left ? node->right->left->balance : 0) : false)) {
        return rotateLeft(node);
    }

    // right left case
    if (balance < -1 && (node->right ? (node->right->right ? node->right->right->balance : 0) < (node->right->left ? node->right->left->balance : 0) : false)) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void AVLTree::remove(double k) {
    root = deleteNode(root, k);
}