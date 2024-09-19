# Binary Search Tree (Prof's Notes):
- General tree structure, implementation and operations
    - Height of a tree
    - Depth of a node
    - Traversal
- A binary search tree satisfies the following conditions:
    - It is a binary tree;
    - Each tree node stores exactly one object;
    - The objects have a total ordering;
    - For each tree node and the object stored in this node, the objects stored in its left subtree are smaller than this object, and the objects sotred in its right subtree are larger than this object.
- Most common application using BST: to implement a dictionary.
- BST implementation: usually pointer-based.
```
Tree node struct:
    data pointer;
    left child pointer;
    right child pointer;
    optional key field;
    optional parent pointer;

BST operations:
lookup(Key k)
    ptr = root;
    while (ptr != 0 && ptr->key != k) {
        if (ptr->key > k)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    if (ptr == 0)
        throw not found exception
    else
        return ptr->data;

insert(Key k, Data d)
    if (root == 0) {
        root = new Node;
        root->key = k;
        root->data = d;
    } else {
        parent = 0;
        ptr = root;
        while (ptr !=0 && ptr->key != k) {
            parent = ptr;
            if (ptr->key > k) {
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }
        if (ptr != 0)
            throw duplicate key exception
        else {
            Node* newNode = new Node;
            newNode->key = k;
            newNode->data = d;
            if (parent->key > k) {
                parent-left= newNode;
            } else {
                parent->right = newNode;
            }
        }
    }

remove(Key k)
    left = true;
    parent = 0;
    ptr = root;
    while (ptr != 0 && ptr->key != k) {
        parent = ptr;
        if (ptr->key > k) {
            ptr = ptr->left;
            left = true;
        } else {
            ptr = ptr->right;
            left = false;
        }
    }
    if (ptr == 0)
        throw not found exception
    else {
        if (ptr->left == 0) {
            if (left)
                parent->left = ptr->right;
            else
                parent->right = ptr->right;
            delete ptr;
        } else if (ptr->right == 0) {
            if (left)
                parent->left = ptr->left;
            else
                parent->right = ptr->left;
            delete ptr;
        } else {
            parent = ptr;
            victim = ptr->right;
            left = false;
            while (victim->left != 0) {
                parent = victim;
                victim = victim->left;
                left = true;
            }
            // swap the data and key between ptr and victim;
            ptr->data = victim->data;
            ptr->key = victim->key;

            if (left)
                parent->left = victim->right;
            else
                parent->right = victim->right;
            delete victim;
        }
    }
 ```