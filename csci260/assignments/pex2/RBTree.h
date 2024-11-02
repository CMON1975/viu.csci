// CHRISTOPHER NILSSEN RBTree.h for ASSIGNMENT 02 CSCI 260 F2402
#ifndef RBTREE_H
#define RBTREE_H

#include "Customer.h"

using std::string;

enum Color { RED, BLACK };

class RBTreeNode {
public:
    Customer* customer;
    Color color;
    RBTreeNode* parent;
    RBTreeNode* left;
    RBTreeNode* right;

    // constructor
    RBTreeNode(Customer* cust);
};

class RBTree {
private:
    RBTreeNode* root;
    RBTreeNode* NIL; // sentinel NIL node

    // helper functions
    void leftRotate(RBTreeNode* x);
    void rightRotate(RBTreeNode* y);
    void insertFixup(RBTreeNode* z);
    void destroyTree(RBTreeNode* node);

public:
    RBTree();
    ~RBTree();

    void insert(Customer* customer);
    RBTreeNode* search(int customerID) const;
    void inOrderTraversal() const;
    bool isEmpty() const;

private:
    void inOrderTraversalHelper(RBTreeNode* node) const;
};

#endif // RBTREE_H
