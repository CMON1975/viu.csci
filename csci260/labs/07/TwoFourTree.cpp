// CHRISTOPHER NILSSEN TwoFourTree.cpp for LAB 07 CSCI 260 F2402
#include <iostream>
#include <string>

using std::string;

class Node {
public:
    Node();
    ~Node();

    int num_keys;
    int keys[3];        // max 3 keys
    string data[3];     // associated data per key
    Node* children[4];  // max 4 children

    bool is_leaf();
};

Node::Node() {
    num_keys = 0;
    for (int i = 0; i < 4; ++i) {
        children[i] = nullptr;
    }
}

Node::~Node() {
    // unnecessary in this implementation
}

bool Node::is_leaf() {
    return children[0] == nullptr;
}

class TwoFourTree {
public:
    TwoFourTree();          // create empty tree
    ~TwoFourTree();         // delete data when deleting nodes
    bool insert(int, string);   // return false if dupe found
    bool lookup(int, string&);   // return false if no such key

private:
    Node* root;

    // helpers
    void delete_tree(Node* node);
    void split_child(Node* parent, int index);
    void insert_nonfull(Node* node, int key, const string& data);
    bool lookup(Node* node, int key, string&data);
};

TwoFourTree::TwoFourTree() {
    root = nullptr;
}

TwoFourTree::~TwoFourTree() {
    delete_tree(root);
}

void TwoFourTree::delete_tree(Node* node) {
    if (node != nullptr) {
        if (!node->is_leaf()) {
            for (int i = 0; i <= node->num_keys; ++i) {
                delete_tree(node->children[i]);
            }
        }
        delete node;
    }
}

bool TwoFourTree::insert(int key, string data) {
    // check for dupe
    string tmp;
    if (lookup(key, tmp)) {
        return false;   // dupe found
    }

    // if tree empty, create root
    if (root == nullptr) {
        root = new Node();
        root->keys[0] = key;
        root->data[0] = data;
        root->num_keys = 1;
        return true;
    }

    // if root full, spliut
    if (root->num_keys == 3) {
        Node* s = new Node();
        s->children[0] = root;
        split_child(s, 0);
        root = s;
    }

    // insert key into root with space
    insert_nonfull(root, key, data);
    return true;
}

void TwoFourTree::split_child(Node* parent, int index) {
    Node* y = parent->children[index];
    Node* z = new Node();
    z->num_keys = 1;

    // copy last key and data from y to z
    z->keys[0] = y->keys[2];
    z->data[0] = y->data[2];

    // copy children if y isn't leaf
    if (!y->is_leaf()) {
        z->children[0] = y->children[2];
        z->children[1] = y->children[3];
    }

    y->num_keys = 1;

    // move keys and children in parent to make space
    for (int j = parent->num_keys; j > index; --j) {
        parent->keys[j] = parent->keys[j - 1];
        parent->data[j] = parent->data[j - 1];
        parent->children[j + 1] = parent->children[j];
    }

    // insert middle key into parent
    parent->keys[index] = y->keys[1];
    parent->data[index] = y->data[1];
    parent->children[index + 1] = z;
    ++parent->num_keys;

    // null unused pointers
    y->children[2] = y->children[3] = nullptr;
}

void TwoFourTree::insert_nonfull(Node* node, int key, const string& data) {
    int i = node->num_keys - 1;

    if (node->is_leaf()) {
        // move keys and data to insert new key
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            node->data[i + 1] = node->data[i];
            --i;
        }
        node->keys[i + 1] = key;
        node->data[i + 1] = data;
        ++node->num_keys;
    } else {
        // find child to insert into
        while (i >= 0 && key < node->keys[i]) {
            --i;
        }
        ++i;

        // split child if full
        if (node->children[i]->num_keys == 3) {
            split_child(node, i);
            if (key > node->keys[i]) {
                ++i;
            }
        }
        insert_nonfull(node->children[i], key, data);
    }
}

bool TwoFourTree::lookup(int key, string&data) {
    return lookup(root, key, data);
}

bool TwoFourTree::lookup(Node* node, int key, string& data) {
    if (node == nullptr) {
        return false;
    }
    int i = 0;

    // find first key >= search key
    while (i < node->num_keys && key > node->keys[i]) {
        ++i;
    }

    if (i < node->num_keys && key == node->keys[i]) {
        data = node->data[i];
        return true;
    } else if (node->is_leaf()) {
        return false;
    } else {
        return lookup(node->children[i], key, data);
    }
}