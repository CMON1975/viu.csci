#ifndef NARYTREE_H
#define NARYTREE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Tree
{
public:
    // n represents the maximum children allowed for each node in the tree
    Tree(int n);
    ~Tree();

    // traversal methods
    void preOrder() const;
    void postOrder() const;

    int getHeight() const; // height of the tree
    int getSize() const; // number of nodes in the tree

    // insert as root, the old root becomes the child of this new root
    void insert(string data);

    // parent should already be in the tree
    void insert(const string parentData, string childData);

    // display descendant strings of the given parameter string
    void listDescendants(const string data) const;
    // display child strings of the given parameter string
    void listChildren(const string data ) const;

private:
    struct Node {
        string data;
        vector<Node *> children;
    };

    Node *root;
    int n; // max number of children per node

    // helpers
    void deleteSubtree(Node *node);
    Node *findNode(Node *node, const string &data) const;
    bool contains(const string &data) const;

    void preOrder(Node *node) const;
    void postOrder(Node *node) const;
    int getHeight(Node *node) const;
    int getSize(Node *node) const;
    void listDescendants(Node *node) const;
};

#endif // NARYTREE_H