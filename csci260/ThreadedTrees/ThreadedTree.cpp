#include <iostream>
using namespace std;

// structure of a threaded binary tree node
struct ThreadedNode {
    int data;
    ThreadedNode* left;
    ThreadedNode* right;
    bool rightThread; // true if right pointer is a thread

    // constructor for new nodes
    ThreadedNode(int value) {
        data = value;
        left = right = nullptr;
        rightThread = false;
    }
};

class ThreadedTree {
public:
    ThreadedNode* root;

    // constructor to initialize empty tree
    ThreadedTree() {
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
                // if there's a left child, move left
                if (current->left != nullptr) {
                    current = current->left;
                } else {
                    isLeftChild = true;
                    break;
                }
            } else {
                // if right pointer is not a thread, move right
                if (current->right != nullptr && !current->rightThread) {
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
            parent->left = newNode;
            // thread the new node's right pointer to its in-order successor
            newNode->right = parent;
            newNode->rightThread = true;
        } else {
            // if inserting as a right child
            if (parent->rightThread) {
                newNode->right = parent->right; // point to in-order successor
            }
            parent->right = newNode;
            parent->rightThread = false; // new node is no longer a thread
            newNode->rightThread = true;
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
private:
    // helper function to find the leftmost node
    ThreadedNode* leftmost(ThreadedNode *node) {
        if (node == nullptr) return nullptr;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};

int main(){
    ThreadedTree t;
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

    return 0;
}