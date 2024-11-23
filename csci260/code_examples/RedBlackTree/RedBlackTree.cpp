#include <iostream>
#include <queue>

using std::queue;
using std::cout;
using std::endl;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left;
    Node *right;
    Node *parent;

    Node(int value)
        : data(value), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node *root;

    void rotateLeft(Node *&root, Node *&node) {
        // perform left rotation
        Node *nodeRight = node->right;
        node->right = nodeRight->left;
        if (nodeRight->left != nullptr) {
            nodeRight->left->parent = node;
        }
        nodeRight->parent = node->parent;
        if (node->parent == nullptr) {
            root = nodeRight;
        } else if (node == node->parent->left) {
            node->parent->left = nodeRight;
        } else {
            node->parent->right = nodeRight;
        }
        nodeRight->left = node;
        node->parent = nodeRight;
    }

    void rotateRight(Node *&root, Node *&node) {
        // perform right rotation
        Node *nodeLeft = node->left;
        node->left = nodeLeft->right;
        if (nodeLeft->right != nullptr) {
            nodeLeft->right->parent = node;
        }
        nodeLeft->parent = node->parent;
        if (node->parent == nullptr) {
            root = nodeLeft;
        } else if (node == node->parent->left) {
            node->parent->left = nodeLeft;
        } else {
            node->parent->right = nodeLeft;
        }
        nodeLeft->right = node;
        node->parent = nodeLeft;
    }

    void fixViolation(Node *&root, Node *&node) {
        Node *parent = nullptr;
        Node *grandparent = nullptr;

        while (node != root && node->color == RED && node->parent->color == RED) {
            parent = node->parent;
            grandparent = parent->parent;

            if (parent == grandparent->left) {
                Node *uncle = grandparent->right;
                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                } else {
                    if (node == parent->right) {
                        rotateLeft(root, parent);
                        node = parent;
                        parent = node->parent;
                    }
                    rotateRight(root, grandparent);
                    std::swap(parent->color, grandparent->color);
                    node = parent;
                }
            } else {
                Node *uncle = grandparent->left;
                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                } else {
                    if (node == parent->left) {
                        rotateRight(root, parent);
                        node = parent;
                        parent = node->parent;
                    }
                    rotateLeft(root, grandparent);
                    std::swap(parent->color, grandparent->color);
                    node = parent;
                }
            }
        }
        root->color = BLACK;
    }

    void insertBST(Node *&root, Node *&node) {
        if (root == nullptr) {
            root = node;
            return;
        }

        if (node->data < root->data) {
            if (root->left == nullptr) {
                root->left = node;
                node->parent = root;
            } else {
                insertBST(root->left, node);
            }
        } else if (node->data > root->data) {
            if (root->right == nullptr) {
                root->right = node;
                node->parent = root;
            } else {
                insertBST(root->right, node);
            }
        }
    }

public:
    RedBlackTree() : root(nullptr) {}

    void insert(int value) {
        Node *node = new Node(value);
        insertBST(root, node);
        fixViolation(root, node);
    }

    void insertSequence(int *arr, int size) {
        for (int i = 0; i < size; ++i) {
            insert(arr[i]);
        }
    }

    void inorder(Node *node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        cout << node->data << (node->color == RED ? " (R)" : " (B)") << " ";
        inorder(node->right);

    }
    void displayInorder() {
        inorder(root);
        cout << endl;
    }

    void preorder(Node *node) {
        if (node == nullptr) {
            return;
        }
        cout << node->data << (node->color == RED ? " (R)" : " (B)") << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void displayPreorder() {
        preorder(root);
        cout << endl;
    }

    void drawTree() {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    // Perform level-order traversal to organize nodes by depth
    queue<Node*> q;
    q.push(root);

    int depth = 0;
    int maxDepth = calculateDepth(root); // Helper to calculate tree depth

    while (!q.empty()) {
        int levelSize = q.size();
        int indent = (1 << (maxDepth - depth)) - 1; // Spacing for this depth
        cout << std::string(indent, ' ');

        for (int i = 0; i < levelSize; ++i) {
            Node *node = q.front();
            q.pop();

            if (node == nullptr) {
                cout << "   "; // Placeholder for null nodes
                q.push(nullptr);
                q.push(nullptr);
            } else {
                cout << node->data << (node->color == RED ? "(R)" : "(B)");
                q.push(node->left);
                q.push(node->right);
            }

            cout << std::string(2 * indent, ' '); // Spacing between nodes
        }
        cout << endl;
        ++depth;

        if (depth > maxDepth) {
            break; // Avoid infinite loops due to null placeholders
        }
    }
}

// Helper to calculate tree depth
int calculateDepth(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    int leftDepth = calculateDepth(node->left);
    int rightDepth = calculateDepth(node->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}
};

int main() {
    RedBlackTree tree;
    
    int numbers[] = {53, 36, 5, 50, 43, 13, 8, 88, 62, 78, 97, 33, 28, 4, 58};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    tree.insertSequence(numbers, size);

    cout << "In-order: ";
    tree.displayInorder();
    cout << "Pre-order: ";
    tree.displayPreorder();
    tree.drawTree();

    return 0;
}