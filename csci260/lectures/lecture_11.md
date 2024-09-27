# Lecture 11 Threaded Trees
A **Threaded Tree** is a variation of a binary tree where "threads" are used to make in-order traversal more efficient by reducing the need for stack or recursion. It is a binary tree with pointers that help traverse the tree in an in-order sequence without needing extra memory for storing nodes on the stack.

In a **standard binary tree**:
- Each node has two pointers: one to the left child and one to the right child.
- If a node doesn't have a left or right child, these pointers are `null`.

In a **threaded tree**, these `null` pointers are replaced with pointers (threads) to the next node in an in-order traversal sequence. This allows traversal without recursion or a stack.
#### Types of Threaded Trees:
1. **Single Threaded Tree**:
    - **Left-threaded tree**: If a node doesn't have a left child, its left pointer points to its in-order predecessor.
    - **Right-threaded tree**: If a node doesn't have a right child, its right pointer points to its in-order successor.
2. **Double Threaded Tree**:
    - In this type, both the `null` left and right pointers are replaced by threads. The left pointer points to the in-order predecessor, and the right pointer points to the in-order successor.

#### Structure:
Each node in a threaded tree may have additional information to indicate whether its left or right pointer is a thread (pointing to another node) or a regular child pointer. This can be done using flags or sentinel values.
```
struct ThreadedNode {
    int data;
    ThreadedNode* left;
    ThreadedNode* right;
    bool leftThread; // true if left is a thread
    bool rightThread; // true if right is a thread
}
```
#### In-order Traversal in a Threaded Tree:
To traverse a threaded binary tree in-order:
1. Start at the leftmost node.
2. Use the right threads to visit the in-order successor of each node until the traversal is complete.
3. If the right pointer is a thread, follow it to the next node. Otherwise, go to the leftmosts node of the right subtree.

#### Advantages of Threaded Trees:
- **Efficient Traversal**: You can traverse the tree without recursion or a stack.
- **Space Saving**: It reduces space consumption by utilizing unused `null` pointers.
- **No Extra Memory for Stack**: The threads provide a way to traverse the tree without needing extra memory (like a call stack for recursion).

#### Example:
For a binary tree:
```
    20
   /  \
  10  30
```
- In a **right-threaded tree**, if 10 has no right child, its right pointer will point to 20 (its in-order successor).
- In a **left-threaded tree**, if 30 has no left child, its left pointer will point to 20 (its in-order predecessor).

#### Applications:
- **Morris Traversal**: This algorithm uses the idea of threading to perform in-order traversal of a binary tree with O(1) space.
- **Data structures where quick in-order traversal is necessary** without the overhead of recursion or a stack.

#### Study Tips:
- **Understand how traversal works**: Focus on how the threading mechanism replaces recursion during traversal.
- **Visualize with diagrams:** Draw threaded trees and in-order traversal to see how threads connect nodes.
- **Compare with regular binary trees**: Identify the difference in space efficiency and traversal logic between a standard binary tree and a threaded tree.

#### Pseudocode for Insertion in a Right-Threaded Binary Tree:
1. **If the tree is empty**:
    - Create a new node and set it as the root.
2. **Otherwise:**
    - Start at the root.
    - Repeat until you find the correct spot:
        - If the value to insert is less than the current node's value:
            - If the left child exists, move left.
            - If no left child, insert a new node as the left child and thread its right pointer to point back to the current node (in-order successor).
        - If the value to insert is greater than or equal to the current node's value:
            - If the right child exists and it's not a thread, move right.
            - If no right child or right is a thread, insert a new node as the right child. Set the new node's right pointer to the current node's successor (the current node's right thread).
            - Update the current node's right thread to point to the new node.
3. **Set thread flags**:
    - Update the `rightThread` flag for the newly inserted node to ensure correct threading.

#### C++ Code Implementation
```
#include <iostream>
using namespace std;

// structure of a threaded binary tree node
struct ThreadedNode {
    int data;
    ThreadNode* left;
    ThreadNode* right;
    bool rightThread; // true if right pointer is a thread

    // constructor for new nodes
    ThreadedNode(int value) {
        data = value;
        int = right = nullptr;
        rightThread = false;
    }
};

class ThreadedTree {
publi:
    ThreadedNode* root;

    // constructor to initialize empty tree
    ThreadedTree() {
        root = nullptr;
    }

    // function to insert a new node
    void insert(int value) {
        // if the tree is empty, create a new node and set it as root
        if (root == nullptr) {
            root = new ThreadedNode(value);
            return;
        }

        ThreadedNode* current = root;
        ThreadedNode* parent = nullptr;
        bool isLeftChild = false;

        // traverse the tree to find the correct place for insertion
        while (current != nullptr) {
            parent = current;
            if (value < current->data) {
                // if there's a left child, move left
                if (current->left != nullptr) {
                    current = current->left;
                } else {
                    isLeftChild = true;
                    break;
                }
            } else {
                // if right pointer is not a thread, move right
                if (current->right != nullptr && !current->rightThread) {
                    current = current->right;
                } else {
                    isLeftChild = false;
                    break;
                }
            }
        }

        // create the new node
        ThreadedNode* newNode = new ThreadedNode(value);

        if (isLeftChild) {
            parent->left = newNode;
            // thread the new node's right pointer to its in-order successor
            newNode->right = parent;
            newNode->rightThread = true;
        } else {
            // if inserting as a right child
            if (parent->rightThread) {
                newNode->right = parent->right; // point to in-order successor
            }
            parent->rightt = newNode;
            parent-rightThread = false; // new node is no longer a thread
            newNode->rightThread = true;
        }
    }

    // in-order traversal using threads
    void inorderTraversal() {
        ThreadedNode* current = leftmost(root);
        while (current != nullptr) {
            cout << current->data << " ";
            if (current-rightThread) {
                current = current->right;
            } else {
                current = leftmost(current->right);
            }
        }
    }
private:
    // helper function to find the leftmost node
    ThreadedNode* leftmost(ThreadedNode *node) {
        if (node == nullptr) return nullptr;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};

int main() {
    ThreadedTree t;
    t.insert(20);
    t.insert(10);
    t.insert(30);
    t.insert(5);
    t.insert(15);

    cout << "In-order traversal: ";
    t.inorderTraversal();   // output: 5 10 15 20 30
    cout << endl;

    return 0;
}
```
##### Explanation:
1. **Insertion Logic**:
    - The tree is traversed using the current node (`current`) to find where the new value should go.
    - If the new value is smaller than the current node's data, it tries to move left; if there's no left child, it inserts the new node there.
    - If the new value is larger, it checks if there's a valid right child. If the right pointer is a thread (i.e., it points to the in-order succesor), it inserts the new node there.
2. **Threading:**
    - When inserting, the algorithm checks whether the right pointer is a thread and updates the `rightThread` flags accordingly.
    - The right pointer of the newly inserted node is set to the in-order successor.
3. **In-order Traversal**:
    - The `inorderTraversal()` method uses threads to traverse the tree in-order without recursion or stack.

This approach ensures efficient in-order traversal while maintaining the properties of a threaded binary tree.