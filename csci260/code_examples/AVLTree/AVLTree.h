#ifndef AVLTREE_H
#define AVLTREE_H

class AVLTree
{
  public:
    AVLTree();
    ~AVLTree();
    void inOrder() const;
    void preOrder() const;
    void postOrder() const;
    void insert(double k);
  private:
    struct Node {
        double data;
        Node *left;
        Node *right;
        int balance;
    };

    Node *root;
    void destroy(Node *);
    void inOrder(Node *) const;
    void preOrder(Node *) const;
    void postOrder(Node *) const;
    bool insert(Node * &, double k);
    void leftRotation(Node *&);
    void rightRotation(Node *&);
    void adjustBalanceLeft(Node*&);
    void adjustBalanceRight(Node*&);
    void updateBalancesDoubleLeft(Node*&);
    void updateBalancesDoubleRight(Node*&);

};

#endif