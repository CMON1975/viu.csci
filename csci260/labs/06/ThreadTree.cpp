// CHRISTOPHER NILSSEN ThreadTree.cpp for LAB 06 CSCI 260 F2402
#include <iostream>

using std::cout;
using std::endl;

class ThreadTree {
private:
    struct Node {
        double key;
        Node* left;
        Node* right;
        bool leftThread;
        bool rightThread;
    
        Node(double k) : key(k), left(nullptr), right(nullptr), leftThread(true), rightThread(true) {}
    };

    Node* root;

public:
    ThreadTree() : root(nullptr) {}

    ~ThreadTree() {
        clearTree(root);
    }

    // in-order traversal (iterative)
    void inOrder() const {
        if (!root) return;
        Node* curr = leftmost(root); // start from leftmost node
        while (curr != nullptr) {
            cout << curr->key << " ";
            if (curr->rightThread) {
                curr = curr->right; // move to in-order successor
            } else {
                curr = leftmost(curr->right);   // move to leftmost node in the right subtree
            }
        }
        cout << endl;
    }

    // insert with key 'k'
    void insert(double k) {
        Node* parent = nullptr;
        Node* curr = root;

        // look for insertion point
        while (curr != nullptr) {
            parent = curr;
            if (k < curr->key) {
                if (!curr->leftThread) {
                    curr = curr->left;
                } else {
                    break;
                }
            } else if (k > curr->key) {
                if (!curr->rightThread) {
                    curr = curr->right;
                } else {
                    break;
                }
            } else {
                // no dupes
                return;
            }
        }

        // create new node
        Node* newNode = new Node(k);

        // insert as root if tree empty
        if (parent == nullptr) {
            root = newNode;
        } else if (k < parent->key) {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->leftThread = false;
            parent->left = newNode;
        } else {
            newNode->left = parent;
            newNode->right = parent->right;
            parent->rightThread = false;
            parent->right = newNode;
        }
    }

private:
    // find leftmost node starting from 'node'
    Node* leftmost(Node* node) const {
        if (!node) return nullptr;
        while (!node->leftThread) {
            node = node->left;
        }
        return node;
    }

    // recursive function to clear the tree
    void clearTree(Node* node) {
        if (node == nullptr) return;

        if (!node->leftThread) {
            clearTree(node->left);
        }
        if (!node->rightThread) {
            clearTree(node->right);
        }

        delete node;
    }
};
