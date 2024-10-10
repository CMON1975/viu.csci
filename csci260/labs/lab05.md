# Lab 05

Implement an AVL tree class with the following interface:
```
class AVLTree
{
public:
    AVLTree();
    ~AVLTree();
    void inOrder() const;
    void preOrder() const;
    void postOrder() const;
    void insert(double k);
    void remove(double k); // optional
private:
    struct TreeNode {
        double data;
        TreeNode *left;
        TreeNode *right;
        int balance;
    };

    TreeNode *root;
};

To simplify the implementation, we assume that the AVL tree will be used to store numbers only.