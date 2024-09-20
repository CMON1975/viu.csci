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

 # My notes:
 - Hash functions produce hash code from string input.
 - For integers of increasing value, hash value can take the last few integers as values and associate with memory location.
 - Hash code is used to validate documents.
 - Documents are fundamentally long strings. A hash function is run on the document to provide the receiver with the ability to verify the document.
 - Decoding from hash code is extremely difficult without the hash function.
 - Hash functions are used for cryptography.

 ## Compression:
 - Data loss can cause collision.
 - Using a good hash table guarantees constant time operation.

 ## Trees:
 - **Definition:** A tree is a special type of **acyclic graph**. A graph is **acyclic** if there are no cycles, meaning it is impossible to start from a node and return to it by traversing the edges of the graph. In other words, there is no continuous path that allows you to traverse the graph from end to end and return to the starting node.
- **Nodes and Edges:** A tree consists of **nodes** (which hold data or represent elements) and **edges** (connections between nodes). In tree structures:
    - **Nodes** represent elements in the tree.
    - **Edges** represent relationships between nodes (typically parent-child relationships).
    - **Root:** The **root node** is the topmost node in the tree. It has **no parent**. All other nodes in the tree are descendants of the root.
    - **Parent and Child Relationships:**
        - A **parent** node has one or more **child** nodes.
        - Each **child** node has **exactly one parent**.
        - A node with **no children** is called a **leaf node**.
    - **Siblings:** Nodes that share the same parent are called **siblings**.
 
 A **recursive tree** is a heirarchical data structure in which each node contains a value and links (references) to its child nodes, and the structure itself is defined recursively. In a recursive tree, each subtree of the tree is also a tree, meaning that the definition of the tree applies to any of its nodes and their descendants. This recursive nature makes it easy to reason about and perform recursive operations on trees, such as traversals or modifying nodes.
 
 A basic recursive tree has the following elements:
 - **Node:** The fundamental unit of the tree, which contains a value (data) and pointers (links) to its child nodes.
 - **Root:** The topmost node in the tree, with no parent.
 - **Children:** Nodes that descend from a parent node.
 - **Leaf:** A node with no children.
 - **Subtree:** A portion of the tree that itself forms a tree, rooted at a node.

 ### Recursive Definition:
 - A tree is either empty (contains no nodes) or consists of a root node and zero or more child trees, which are themselves trees.

 ### Example:
 ```
 Tree:
        A
       / \
      B   C
     / \    
    D   E 

Recursive structure:
- A is the root.
- B and C are children of A.
- D and E are children of B.
- Each of B, C, D, and E can be considered as a root of their own subtrees.
```
Recursion is often used when working with trees because many operations, like traversals (in-order, pre-order, post-order), searches, and modifications, naturally lend themselves to being solved by breaking the problem into smaller, self-similar subproblems (working on subtrees).

- An **internal node** has children.
- **Leaf nodes** do not.
- All nodes in the subtrees connected to a node are called **descendants**.
- **Height:** The number of nodes that descend along the longest branch.
- **Depth:** How many steps are needed from the root (0) down to the lowest leaf.
- **Edge:** Represents the link or connection between two nodes.

### Method of Traversal:
- Must be able to systematically visit every node.
- Order matters:
    - Pre-order: First root, then subtrees from left to right.
    - Post-order: First subtrees from left to right, and root last.
    - Binary Search Tree In-order: First the left subtree, then root, then right subtree.

#### Pre-order Traversal Pseudocode (Recursive)
```
PreOrderTraverse(node):
    if node is not NULL:
        visit(node)         // process the current node (root)
        PreOrderTravers(node.left)  // recursively traverse the left subtree
        PreOrderTravers(node.right)  // recursively traverse the right subtree

      A
     / \
    B   C
   / \
  D   E
```
The pre-order traversal would visit the nodes in this order: `A → B → D → E → C`.
This traversal pattern is useful for tasks like copying a tree or evaluating expressions in expression trees.

#### Post-order Traversal Pseudocode (Recursive)
```
PostOrderTraverse(node):
    if node is not NULL:   
        PostOrderTraverse(node.left)    // recursively traverse the left subtree
        PostOrderTraverse(node.right)   // recursively traverse the right subtree
        visit(node)                     // process the current node (root)

      A
     / \
    B   C
   / \
  D   E
```
The post-order traversal would visit the nodes in this order: `D → E → B → C → A`.
This traversal is useful for tasks like deleting a tree or evaluating postfix expressions.

#### In-order Traversal Pseudocode
```
InOrderTraverse(node):
    if node is not NULL:
        InOrderTraverse(node.left)  // recursively traverse the left subtree
        visit(node)                 // process the current node (root)
        InOrderTraverse(node.right) // recursively traverse the right subtree

      A
     / \
    B   C
   / \
  D   E
```
The in-order traversal would visit the nodes in this order: `D → B → E → A → C`.
In-order traversal is particularly useful for **binary search trees (BST)** because it visits nodes in **ascending order** when the tree is properly structured.

### Implementation
- **n-ary tree:** Each node can have up to n children.
- Use an array for child nodes.
        