// CHRISTOPHER NILSSEN NaryTree.cpp for LAB 04 CSCI 260 F2402
#include "NaryTree.h"
#include <iostream>

using std::cout;
using std::endl;

Tree::Tree(int n) {
    this->n = n;
    root = nullptr;
}

Tree::~Tree() {
    deleteSubtree(root);
}

void Tree::deleteSubtree(Node *node) {
    if (node == nullptr)
        return;
    for (Node *child : node->children)
        deleteSubtree(child);
    delete node;
}

void Tree::insert(string data) {
    if (contains(data)) {
        cout << "Duplicate data not allowed\n";
        return;
    }
    Node *newNode = new Node();
    newNode->data = data;
    if (root != nullptr) {
        if (newNode->children.size() >= static_cast<size_t>(n)) {
            cout << "Cannot add old root as child, max children reached\n";
            delete newNode;
            return;
        }
        newNode->children.push_back(root);
    }
    root = newNode;
}

void Tree::insert(const string parentData, string childData) {
    if (contains(childData)) {
        cout << "Duplicate data not allowed\n";
        return;
    }
    Node *parentNode = findNode(root, parentData);
    if (parentNode == nullptr) {
        cout << "Parent not found\n";
        return;
    }
    if (parentNode->children.size() >= static_cast<size_t>(n)) {
        cout << "Cannot add child, max children reached\n";
        return;
    }
    Node *childNode = new Node();
    childNode->data = childData;
    parentNode->children.push_back(childNode);
}

Tree::Node *Tree::findNode(Node *node, const string &data) const {
    if (node == nullptr)
        return nullptr;
    if (node->data == data)
        return node;
    for (Node *child : node->children) {
        Node *found = findNode(child, data);
        if (found != nullptr)
            return found;
    }
    return nullptr;
}

bool Tree::contains(const string &data) const {
    return (findNode(root, data) != nullptr);
}

void Tree::preOrder() const {
    preOrder(root);
    cout << endl;
}

void Tree::preOrder(Node *node) const {
    if (node == nullptr)
        return;
    cout << node->data << " ";
    for (Node *child : node->children)
        preOrder(child);
}

void Tree::postOrder() const {
    postOrder(root);
    cout << endl;
}

void Tree::postOrder(Node *node) const {
    if (node == nullptr)
        return;
    for (Node *child : node->children)
        postOrder(child);
    cout << node->data << " ";
}

int Tree::getHeight() const {
    return getHeight(root);
}

int Tree::getHeight(Node *node) const {
    if (node == nullptr)
        return 0;
    int maxChildHeight = 0;
    for (Node *child : node->children) {
        int childHeight = getHeight(child);
        if (childHeight > maxChildHeight)
            maxChildHeight = childHeight;
    }
    return maxChildHeight + 1;
}

int Tree::getSize() const {
    return getSize(root);
}

int Tree::getSize(Node *node) const {
    if (node == nullptr)
        return 0;
    int size = 1;
    for (Node *child : node->children) {
        size += getSize(child);
    }
    return size;
}

void Tree::listDescendants(const string data) const {
    Node *node = findNode(root, data);
    if (node == nullptr) {
        cout << "Node not found\n";
        return;
    }
    listDescendants(node);
    cout << endl;
}

void Tree::listDescendants(Node *node) const {
    for (Node *child : node->children) {
        cout << child->data << " ";
        listDescendants(child);
    }
}

void Tree::listChildren(const string data) const {
    Node *node = findNode(root, data);
    if (node == nullptr) {
        cout << "Node not found\n";
        return;
    }
    for (Node *child : node->children) {
        cout << child->data << " ";
    }
    cout << endl;
}

int main() {
    Tree tree(3); // each node can have at most 3 children

    tree.insert("root");
    tree.insert("root", "child1");
    tree.insert("root", "child2");
    tree.insert("child1", "grandchild1");
    tree.insert("child1", "grandchild2");
    tree.insert("child2", "grandchild3");

    cout << "Pre-order traversal: ";
    tree.preOrder();

    cout << "Post-order traversal: ";
    tree.postOrder();

    cout << "Height of the tree: " << tree.getHeight() << endl;
    cout << "Size of the tree: " << tree.getSize() << endl;

    cout << "Children of 'root': ";
    tree.listChildren("root");

    cout << "Descendants of 'child1': ";
    tree.listDescendants("child1");

    return 0;
}
