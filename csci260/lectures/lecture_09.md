# Lecture 9 Prof Notes
## AVL Tree
- AVL tree is a height-balanced binary search tree.
- Balance factor: the difference between the height of right subtree and that of left subtree.
- For each node in an AVL tree, the height of its right subtree and left subtree differs at most 1.
- Theorem: the height of an AVL tree with N nodes is O(log N).
Proof: We prove that an AVL tree with height of h has at least Omega$\left(c^h\right)$ nodes for some constant $c > 1$.
**Base case:** $h = 1$, AVL tree must have 1 node, so $n(1) = 1$.
           $h = 2$, AVL tree must have at least 2 nodes,
           so $n(2) \geq 2 \geq 2^{\frac{2}{1}}$
**Induction step:** $\text{for } h > 2,$
        $n(h) \geq 1 + n(h - 1) + n(h -2)$
        $> 2 \times n(h-2)$
        $\geq 2 \times 2^{(h-2)/2}$
        $\geq 2^{\frac{h}{2}}$
        $\geq \sqrt{2^h}$
    Therefore, if $n(h) = N, h \leq 2 \log N$
- Maintaining the balance of the AVL tree
    - Insert a new node:
        - Perform the normal BST insert while keep track of the last critical node;
        - Update the balance factors of the affected nodes; the update only may propagate all the way to the root node;
        - If a critical node is found, fix the possible unbalance using a single or a double rotation;
        - The rotation shouldn't affect the height of the subtree, therefore, the rotation won't propagate upwards.
    - Remove a node:
        - Perform the normal BST removal while keeping track of the last critical node;
        - If a critical node is found, update the balance factors of the affected nodes;
        - If unbalance happened, fix it using a single or a double rotation and update the balance factors of the affected nodes;
        - Both the above actions may decrease the height of the subtree, therefore the action may propagate to the parent nodes until hitting the root node.

# My Notes
## Tree, continued
### Implementation
- **Pointer-based:** Uses pointers to represent links between nodes. Common for binary trees and sparse trees.
- **Array-based:** Useful for dense trees or when memory is constrained. Nodes are stored in contiguous memory, and relationships between parent and child nodes are computed via indices.
- **Parent pointers:** These are now acceptable for modern machines where memory and processing speed are abundant. They allow navigation back up a tree.
- **Descent via stack:** In constrained systems (e.g., embedded systems), we can avoid parent pointers by keeping track of the path using a stack and pop back to the route when needed.
- For **n-array tree** (where each node can have up to $n$ children):
    - Node at index `i` has its parent at index:
        \[
        \text{parent\_index} = \frac{i - 1}{n}
        \]
    -  Child node `j` of node `i` is at index:
        \[
        \text{child\_index} = (i \times n) + j
        \]
    - For a **perfect** tree, the total number of nodes is given by:
        \[
        \text{size}=2^h-1
        \]
        where `h` is the height of the tree.
- **Dense tree:** A tree where all possible positions at each level are filled with nodes.
- **Sparse tree:** A tree where some branches are much longer than others, and many levels may be missing nodes.
- **Perfect tree:** If you know the tree is perfect (all levels are fully filled except possibly the last), an array-based representation is ideal.
- **Uncertain structure:** When you're unsure about the tree's structure or expect a sparse tree, pointers are a better choice.
---

#### Binary Search Tree (BST)
- A BST is a binary tree where each node has up to two children.
- Each node stores a key and associated data (`<key, data>`) where `data` can be an object, value, or record.
- In-order traversal of the tree sorts the data according to the keys.
- You can verify the **BST property** by performing an in-order traversal and checking if the keys are in ascending (or descending) order.

###### Program Outline for BST Operations:
```
struct TreeNode {
    Data *obj;          // pointer to stored data
    Key k;              // optional if key is part of object
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent; // optional
};

class BST {
public:
    BST();
    Data & lookup(Key k);
    void insert(Key k, Data & obj);  // how to best handle exceptions? bool, int, other? If using error codes, document them in comments
    Data & remove(Key k);
    ~BST();
    
private:
    TreeNode *root;     // root of the BST
    void deleteSubtree(TreeNode *node); // cleanup
};
```
###### Lookup Operation:
```
Data &BST::lookup(Key k) {
    TreeNode *ptr = root;
    while (ptr != nullptr && ptr->k != k) {
        if (ptr->k > k)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    if (ptr == nullptr)
        throw std::runtime_error("Key not found.");
    else
        return ptr->obj;
}
```
###### Alternative Condensed Lookup
You can use a pointer to a pointer (`TreeNode **`) to modify the node pointer directly, for example, during insertion:
```
TreeNode **curr = &root;
while((*curr) != nullptr && (*curr)->k != k) {
    if((*curr)->k < k)
        curr = &((*curr)->right);
    else
        curr = &((*curr)->left);
}

if((*curr) == nullptr) {
    (*curr) = new TreeNode;
    (*curr)->k = k;
    (*curr)->obj = obj;  // assume obj is passed by references
    (*curr)->left = (*curr)->right = nullptr;
} else {
    throw std::runtime_error("Duplicate key");
}   
```
##### Pointer to a Pointer
In C++, the `**` in `TreeNode **curr = &root;` means that `curr` is a **pointer to a pointer** to a `TreeNode`. Let's break this down:
1. **Pointer to a pointer:** The type `TreeNode **` declares `curr` as a variable that holds the address of another pointer, which in turn points to a `TreeNode` object.
2. `&root`: The `&root` expression takes the address of `root`. In this case, `root` is likely a pointer to a `TreeNode` (i.e., `TreeNode *root`). So `&root` is a pointer to that pointer, which is of type `TreeNode **`.

Thus, `TreeNode **curr = &root;` means:
- `curr` is a pointer to a pointer to a `TreeNode`, and it's initialized with the address of `root`, which itself is a pointer to a `TreeNode`.

This is typically used in cased where you want to modify the pointer `root` itself (e.g., reassign it to point to a different node) from within a functioin or loop that operates on `curr`.

---
##### Predecessor and Successor
- **Predecessor:** Move one step left, then down the right branch as far as possible (until null).
- **Successor:** Move one step right, then down the left branch as far as possible (until null).

##### Removing a Node in a BST
```
void BST::remove(Key k) {
    TreeNode *parent = nullptr;
    TreeNode *ptr = root;
    bool isLeftChild = true;

    // find the node to be removed
    while (ptr != nullptr && ptr->k != k) {
        parent = ptr;
        if (ptr->k > k) {
            ptr = ptr->left;
            isLeftChild = true;
        } else {
            ptr = ptr->right;
            isLeftChild = false;
        }
    }

    if (ptr == nullptr) {
        throw std::runtime_error("Key not found");
    }

    // Case 1: Node has no children (leaf node)
    if (ptr->left == nullptr && ptr->right == nullptr) {
        if (ptr == root)
            root = nullptr;
        else if (isLeftChild)
            parent->left = nullptr;
        else
            parent->right = nullptr;
        delete ptr;
    }
    // Case 2: Node has one child (left or right)
    else if (ptr->left == nullptr) {
        if (ptr == root)
            root = ptr->right;
        else if (isLeftChild)
            parent->left = ptr->right;
        else
            parent->right = ptr->right;
        delete ptr;
    } else if (ptr->right == nullptr) {
        if (ptr == root)
            root = ptr->left;
        else if (isLeftChild)
            parent->left = ptr->left;
        else
            parent->right = ptr->left;
        delete ptr;
    }
    // Case 3: Node has two children
    else {
        TreeNode *successorParent = ptr;
        TreeNode *successor = ptr->right;
        isLeftChild = false;

        // Find the in-order successor (smallest node in right subtree)
        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
            isLeftChild = true;
        }

        // Swap data with the successor
        ptr->k = successor->k;
        ptr->obj = successor->obj;

        // Remove the successor node
        if (isLeftChild)
            successorParent->left = successor->right;
        else
            successorParent->right = successor->right;
        delete successor;
    }
}
```
---
##### Summary of Key Points
- **Pointer to a pointer (`**`) is often used when you need to modify a pointer itself inside a function (common in tree manipulations).
- **Parent pointers** are acceptable in modern systems but may not always be necessary.
- The **BST remove function** can often be simplified to focus on edge cases (left node, one child, two children) without redundant checks.

##### Testing BST Property
```
// Pseudo-code for testing the BST property
bool isBST(TreeNode *node, Key minKey, Key maxKey) {
    if (node == nullptr)
        return true;

    if (node->key <= minKey || node->key >= maxKey)
        return false;

    // Recursively check the left and right subtrees
    return isBST(node->left, minKey, node->key) &&
           isBST(node->right, node-key, maxKey);
}

// Function to initiate the BST property test
bool validateBST(TreeNode *root) {
    return isBST(root, INT_MIN, INT_MAX); // assuming INT_MIN/INT_MAX as key range
}
```