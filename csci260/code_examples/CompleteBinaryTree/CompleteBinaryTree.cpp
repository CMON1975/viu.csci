#include <queue>

using std::queue;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void insert(Node** root, int key) {
    Node* newNode = new Node{key, nullptr, nullptr};
    if (*root = nullptr) {
        *root = newNode;
        return;
    }

    queue<Node*> q;
    q.push(*root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newNode;
            return;
        } else {
            q.push(temp->left);
        }

        if(!temp->right) {
            temp->right = newNode;
            return;
        } else {
            q.push(temp->right);
        }
    }
}

bool isCompleteBinaryTree(Node* root) {
    if (!root) return true;

    queue<Node*> q;
    q.push(root);
    bool flag = false;

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left) {
            if (flag) return false;
            q.push(temp->left);
        } else {
            flag = true;
        }

        if (temp->right) {
            if (flag) return false;
            q.push(temp->right);
        } else {
            flag = true;
        }
    }
    return true;
}