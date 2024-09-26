# Lecture 10 AVL Tree
The AVL tree is a type of self-balancing binary search tree. The key property of an AVL tree is that the heights of the two child subtrees of any node differ by a most one. If at any time the heights differ by more than one, rebalancing is done to restore this property.
## 1. Binary Search Tree (BST) Basics:
- Each node in a BST has at most two children.
- For each node, all values in the left subtree are smaller, and all values in the right subtree are larger.
- In an unbalanced BST, operations like searching, inserting, and deleting can degrade to O(n) in the worst case.
## 2. AVL Tree:
- Named after its inventors, Adelson-Velsky and Landis.
- It ensures that the tree remains balanced after every insertion and deletion, maintaining O(log n) time complexity for these operations.
- The balance factor (BF) of a node is calculated as the difference between the height of the left and right subtrees:
\[
    \text{BF = height of left subtree - height of right subtree}
\]
- The AVL tree property requires that the balance factor of each node is either -1, 0, or 1. If a node's balance factor goes outside this range, the tree is rebalanced.
## 3. Rotations:
To maintain balance, rotations are performed:
- **Single Right Rotation (LL Rotation)**: Used when the left subtree is higher than allowed (left-heavy).
- **Single Left Rotation (RR Rotation)**: Used when the right subtree is too high (right-heavy).
- **Left-Right (LR Rotation)**: A combination of left and right rotations, performed when a node is left-right heavy.
- **Right-Left (RL Rotation)**: A combination of right and left rotations, performed when a node is right-left heavy.
## 4. Insertion:
- After inserting a new node, we check the balance factor of each node on the path from the inserted node up to the root.
- If any node becomes unbalanced, one of the rotations (LL, RR, LR, RL) is performed to restore the AVL property.
## 5. Deletion:
- Similar to insertion, after a node is deleted, the balance factor of nodes is checked, and rotations are performed if necessary to maintain balance.
### Example:
Let's walk through an insertion in an AVL tree:
1. **Start with an empty tree and insert values 10, 20, 30.**
    - After inserting 10, 20, 30 sequentially into a regular BST, the tree would become unbalanced (right-heavy).
    - The balance factor at node 10 would become -2 (indicating imbalance).
    - To fix this, we perform a **left rotation (RR rotation)** at node 10, making 20 the new root.

After insertion and the rotation:
```
    20
   /  \
  10  30
```
## Key Advantages of AVL Trees:
- Maintains balance automaticall, ensuring that operations are efficient (O(log n)).
- Useful in situations where frequent inserts and deletes occur, and performance degradation due to imbalance must be avoided.

## Proof of $O(\log n)$ `lookup`:
### Step 1: AVL Tree Height Bounds
An AVL tree maintains balance by ensuring that for every node, the height difference between the left and right subtrees is at most 1. Because of this, the height of an AVL tree grows logarithmically in relation to the number of nodes $n$.
1. **Minimum and Maxmimum Nodes in an AVL Tree of Height $H$**:
    - The smallest AVL tree of height $H$ has the fewest nodes when each level of the tree is as unbalanced as possible (but still valid according to AVL rules). In the worst-case scenario for an AVL tree of height $H$, there will be approximately $2^{\frac{H}{2}}$ nodes, giving the inequality:
        \[
            2^{\frac{H}{2}} \le N
        \]
    - The largest AVL tree of height $H$ has the maximum number of nodes when it is a complete tree, which contains $2^H-1$ nodes, giving the inequality:
        \[
            N \le 2^H-1
        \]
### Steo 2: Relating Height $H$ to Number of Nodes $N$
From these two bounds, we can deduce the following inequality:
\[
2^{\frac{H}{2}} \leq N \leq 2^H -1
\]
Taking the logarithm of both sides of this inequality gives us:
\[
\frac{H}{2} \le \log N \le H    
\]
Multiplying the first part by 2, we get:
\[
H \le 2 \log N
\]
Thus, the height $H$ is at most $2 \log N$, meaning $H$ grows logarithmically with respect tot he number of nodes $N$.
### Step 3: Conclusion
Since AVL tree operations such as `lookup` depend on traversing the tree from the root to a leaf node (which takes $H$ steps in the worst case), and we've shown that $H$ is $O(\log N)$, we conclude:
\[
H \in O(\log N)
\]
This explains why `lookup` in an AVL tree is $O(\log n)$

In summary:
- An AVL tree ensures balance by limiting the height to $O(\log n)$.
- This logarithmic height guarantees that operations like `lookup`, which involve traversing the tree, take $O(\log n)$ time.

## C++ Implementation
### 1. Node Structure
Each node in the tree stores its key, left and right child pointers, and the height of the subtree rooted at that node. We'll also define a constructor for the node.
```
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};
```
### 2. AVL Tree Class
The AVL tree class will encapsulate functions to perform the following operations:
- **Insert a node.**
- **Balance the tree** after insertion.
- **Peform rotations** to maintain the AVL balance.
- **Utility functions** like `getHeight()`, `getBalance()`, and `max()`.

```
class AVLTree {
private:
    Node* root;

    int getHeight(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int getBalance(Node* node) {
        if (node == nullptr) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    // rotation functions
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);

    // recursive insertion function
    Node* insert(Node* node, int key);

    // utility function to balance the tree
    Node* balance(Node* node, int key);

public:
    AVLTree() : root(nullptr) {}

    // public insert function
    void insert(int key) {
        root = insert(root, key);
    }

    // in-order traversal for printing tree nodes
    void inOrder(Node* node);
    void printInOrder() {
        inOrder(root);
    }
};
```
### 3. Rotations
There are two basic types of rotations:
- ** Right Rotation(single)**: This is used when the left subtree is taller (left-heavy).
- ** Left Rotation(single)**: This is used when the right subtree is taller (right-heavy).

Sometimes a combination of rotations is needed for more complex cases (like LR and RL rotations).

#### Right Rotation
```
Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // perform rotation
    x->right = y;
    y->left = T2;

    // update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // return the new root
    return x;
}
```

#### Left Rotation
```
Node* AVLTree::leftRotate(Node* y) {
    Node* y = x->right;
    Node* T2 = y->left;

    // perform rotation
    y->left = x;
    x->right = T2;

    // update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // return the new root
    return y;
}
```

### 4. Insertion
We perform a regular BST insertion and then check the balance factor of each node. If it's unbalanced, we perform the appropriate rotation.
```
Node* AVLTree::insert(Node* node, int key) {
    // 1. Perform the normal BST insertion
    if (node == nullptr) {
        return new Node(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        // dupe keys not allowed
        return node;
    }

    // 2. Update the height of this ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Get the balance factor of this node
    int balance = getBalance(node);

    // 4. If this node becomes unbalanced, there are 4 cases:

    // Left Left Case
    if (balance > 1 && key < node-left->key) {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // return the (unchanged) node pointer
    return node;
}
```
### 5. Traversal (In-Order)
This will help print the tree and verify insertions.
```
void AVLTree::inOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        std::cout << node->key << " ";
        inOrder(node-right);
    }
}
```
### 6. Usage Example
```
int main() {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    std::cout << "In-order traversal of the constructed AVL tree is: ";
    tree.printInOrder();
    std::cout << std::endl;

    return 0;
}
```
### 7. What Happens During Insertions?
- When a value is inserted, the tree adjusts itself using rotations to maintain the AVL property (balance factor between -1 and 1).
- If inserting a node causes the tree to become unbalanced (either left-heavy or right-heavy), the correct rotation (single or double) will fix the imbalance.

### Additional Enhancements:
You can implement other functionalities like deletion, balancing the tree after deletions, and searching in a similar recursive fashion. Each time you modify the tree, ensure that it remains balanced by checking the balance factor and performing the appropriate rotations.

## Study Tools
- [Interactive Tree Visualizer](https://tree-visualizer.netlify.app/)