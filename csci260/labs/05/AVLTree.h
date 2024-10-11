// CHRISTOPHER NILSSEN AVLTree.h for LAB 05 CSCI 260 F2402
#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;

class AVLTree
{
public:
    AVLTree();
    ~AVLTree();
    void inOrder() const;
    void preOrder() const;
    void postOrder() const;
    void insert(double k);
    void remove(double k);
private:
    struct TreeNode {
        double data;
        TreeNode *left;
        TreeNode *right;
        int balance; // stores height
    };

    TreeNode *root;

    // helper functions for rotation and deletion clean code
    TreeNode* rotateRight(TreeNode* y);
    TreeNode* rotateLeft(TreeNode* x);
    TreeNode* insertNode(TreeNode* node, double key);
    TreeNode* deleteNode(TreeNode* node, double key);
};

#endif // AVLTREE_H