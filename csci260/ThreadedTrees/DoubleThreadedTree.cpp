#include <iostream>
using namespace std;

// structure of a threaded binary tree node
struct ThreadedNode {
    int data;
    ThreadedNode* left;
    ThreadedNode* right;
    bool leftThread; // true if left pointer is a thread
    bool rightThread; // true if right pointer is a thread

    // constructor for new nodes
    ThreadedNode(int value) {
        data = value;
        left = right = nullptr;
        leftThread = rightThread = true;
    }
};

class DoubleThreadedTree {
public:
    ThreadedNode* root;

    // constructor to initialize empty tree
    DoubleThreadedTree() {
        root = nullptr;
    }

    // function to insert a new node
    void insert(int value) {
        // if the tree is empty, create a new node and set it as root
        if (root == nullptr) {
            root = new ThreadedNode(value);
            return;
        }

        ThreadedNode* current = root;
        ThreadedNode* parent = nullptr;
        bool isLeftChild = false;

        // traverse the tree to find the correct place for insertion
        while (current != nullptr) {
            parent = current;
            if (value < current->data) {
                // move left if possible
                if (!current->leftThread) {
                    current = current->left;
                } else {
                    isLeftChild = true;
                    break;
                }
            } else {
                // move right if possible and right is not a thread
                if (!current->rightThread) {
                    current = current->right;
                } else {
                    isLeftChild = false;
                    break;
                }
            }
        }

        // create the new node
        ThreadedNode* newNode = new ThreadedNode(value);

        if (isLeftChild) {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->leftThread = false; // no longer a thread
            parent->left = newNode;
        } else {
            newNode->right = parent->right;
            newNode->left = parent;
            parent->rightThread = false; // no longer a thread
            parent->right = newNode;
        }
    }

    // in-order traversal using threads
    void inorderTraversal() {
        ThreadedNode* current = leftmost(root);
        while (current != nullptr) {
            cout << current->data << " ";
            if (current->rightThread) {
                current = current->right;
            } else {
                current = leftmost(current->right);
            }
        }
    }

    // reverse in-order traversal using threads
    void reverseInorderTraversal() {
        ThreadedNode* current = rightmost(root);
        while (current != nullptr) {
            cout << current->data << " ";
            if (current->leftThread) {
                current = current->left;
            } else {
                current = rightmost(current->left);
            }
        }
    }

private:
    // helper function to find the leftmost node
    ThreadedNode* leftmost(ThreadedNode *node) {
        if (node == nullptr) return nullptr;
        while (node->left != nullptr && !node->leftThread) {
            node = node->left;
        }
        return node;
    }

    // helper function to find the rightmost node
    ThreadedNode* rightmost(ThreadedNode *node) {
        if (node == nullptr) return nullptr;
        while (node->right != nullptr && !node->rightThread) {
            node = node->right;
        }
        return node;
    }
};

int main(){
    DoubleThreadedTree t;
    t.insert(5);
    t.insert(10);
    t.insert(15);
    t.insert(30);
    t.insert(20);
    t.insert(0);
    t.insert(100);

    cout << "In-order traversal: ";
    t.inorderTraversal();
    cout << endl;

    cout << "Reverse in-order traversal: ";
    t.reverseInorderTraversal();
    cout << endl;

    return 0;
}