// CHRISTOPHER NILSSEN - BST.h for ASSIGNMENT 02 CSCI 260 F2402
// Defines a binary search tree (BST) class for managing Customer objects by email. 
// Includes methods for insertion, email-based search, in-order traversal, and memory cleanup. 
// Uses a BSTNode structure to store each Customer and its child nodes.

#ifndef BST_H
#define BST_H

#include "Customer.h"

using std::string;

class BSTNode {
public:
    Customer* customer;
    BSTNode* left;
    BSTNode* right;

    // constructor
    BSTNode(Customer* cust);
};

class BST {
private:
    BSTNode* root;

    // helper functions
    void insertNode(BSTNode*& node, Customer* customer);
    BSTNode* searchNode(BSTNode* node, const string& email) const;
    void inOrderTraversalHelper(BSTNode* node, int& count) const;
    void destroyTree(BSTNode* node);

public:
    BST();
    ~BST();

    void insert(Customer* customer);
    BSTNode* search(const string& email) const;
    int inOrderTraversal() const;
    bool isEmpty() const;
};

#endif // BST_H
