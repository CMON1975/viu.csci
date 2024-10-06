# Day 6: Binary Tree Reconstruction
- **Topics Covered**:
    - Reconstructing a binary tree from traversal (pre-order, in-order, post-order).
- **Study Activities**:
    - **Travesal Technique**: Review the properties of each tree traversal method.
    - **Reconstruction Algorithm**: Learn the step-by-step process to rebuild a tree.
    - **Visualization**: Draw trees based on traversal data.
- **Practice**:
    - Given different traversal sequences, reconstruct the corresponding binary trees.
    - Verify your reconstructed trees by peforming traversals.

---
## 1. What are the proprerties of the binary tree traversal methods (pre-order, in-order, post-order)?
**Binary tree traversal** refers to the process of visiting each node in a binary tree data structure exactly once in a systematic way. The three primary methods of depth-first traversal are **pre-order**, **in-order**, and **post-order**. Each method differs in the order in which it visits the root and subtrees. Below are the properties and characteristics of each traversal method.

---
### 1. Pre-Order Traversal
#### Traversal Order:
1. Visit the root node.
2. Traverse the left subtree in pre-order.
3. Traverse the right subtree in pre-order.

#### Proprties:
- **Root-First:** The root node is processed before its child nodes.
- **Reconstruction:** Pre-order traversal can be used to copy the tree or to reconstruct it when combined with in-order traversal.
- **Prefix Expression:** In expression trees, pre-order traversal yields prefix notation (Polish notation) of the expression.
- **Implementation:** Can be implemented recursively or iteratively using a stack.

#### Use Cases:
- **Serialization/Deserialization:** Used in algorithms that need to serialize a tree structure (e.g., saving a tree to a file).
- **Hierarchy Representation:** Useful for representing hierarchical data where parent nodes need to be processed before child nodes.
- **Creating a Copy:** Helps in creating a clone of the original tree.

#### Example:
For the following tree:
```
      A
     / \
    B   C
   / \   \
  D   E   F
```
Pre-order traversal sequence: **A B D E C F**

---
### 2. In-Order Traversal
#### Traversal Order:
1. Traverse the left subtree in in-order.
2. Visit the root node.
3. Traverse the right subtree in in-order.

#### Proprties:
- **Left-Root-Right:** Processes the left subtree before the root and the right subtree after.
- **Binary Search Tree (BST) Property:** In-order traversal of a BST results in nodes being visited in ascending sorted order.
- **Expression Trees:** In in-order traversal, parentheses are needed to preserve the correct order of operations in expressions.

#### Use Cases:
- **Sorting:** Extracts elements from a BST in sorted order.
- **Expressing Evaluation:** Used in expression trees to obtain infix expressions.
- **Symmetric Traversal:** Provides a natural way to traverse a tree symmetrically.

#### Example:
For the same tree:

In-order traversal sequence: **D B E A C F**

### 3. Post-Order Traversal
#### Traversal Order:
1. Traverse the left subtree in post-order.
2. Traverse the right subtree in post-order.
3. Visit the root node.

#### Properties:
- **Root-Last:** The root node is processed after its child nodes.
- **Deletion:** Useful for deleting trees; nodes are deleted from the leaves up to the root.
- **Postfix Expression:** In expression trees, post-order traversal yields postfix notation (Reverse Polish notation) of the expression.
- **Dependency Resolution:** Can be used to resolve dependencies (children before parents).

#### Use Cases:
- **Memory Deallocation:** Used when freeing memory allocated for nodes in languages without automatic garbage collection.
- **Expression Evaluation:** Evaluates expressions in expression trees by computing the value of subtrees before combining them.
- **Compilers:** Utilized in syntax tree traversal for code generation.

#### Example:
For the same tree:

Post-order traversal sequence: **D E B F C A**

---
## 2. What's the step-by-step process to rebuild a binary tree?
### Prerequisites
- **Understand Tree Traversals:**
    - **Pre-order Traversal:** Root ➔ Left Subtree ➔ Right Subtree
    - **In-order Traversal:** Left Subtree ➔ Root ➔ Right Subtree
    - **Post-order Traversal:** Left Subtree ➔ Right Subtree ➔ Root
- **Know the Tree Structure:**
    - **Binary Tree:** Each node has at most two children (left and right).
    - **Unique Elements:** Assume all tree elements (node values) are unique for simplicity.
### Scenario 1: Rebuilding from In-Order and Pre-Order Traversals
**Step 1: Identify the Root Node**
- **Pre-order Traversal:** The first element is always the root of the tree.
- **Action:** Take the first element of the pre-order sequence as the root.

**Step 2: Split In-Order Traversal into Subtrees**
- **Find Root in In-Order Traversal:** Locate the index of the root node in the in-order sequence.
- **Action:**
    - Elements to the **left** of the root in the in-order traversal belong to the **left subtree**.
    - Elements to the **right** of the root in the in-order traversal belong to the **right subtree**.

**Step 3: Split Pre-Order Traversal into Subtrees**
- **Calculate Subtree Sizes:**
    - Number of nodes in the left subtree is equal to the number of elements before the root in the in-order sequence.
- **Action:**
    - Skip the root element in pre-order traversal.
    - The next **n** elements correspond to the left subtree, where **n** is the number of nodes in the left subtree.
    - The remaining elements correspond to the right subtree.

**Step 4: Recursively Rebuild Subtrees**
- **Left Subtree:**
    - **Pre-order:** Use the identified left subtree pre-order sequence.
    - **In-order:** Use the left part of the in-order sequence.
    - **Action:** Recursively apply steps 1-4 to rebuild the left subtree.
- **Right Subtree:**
    - **Pre-order:** Use the identified right subtree pre-order sequence.
    - **In-order:** Use the right part of the in-order sequence.
    - **Action:** Recursively apply steps 1-4 to rebuild the right subtree.

**Step 5: Assemble the Tree**
- **Action:** Attach the rebuilt left and right subtrees to the root node.

### Example:
Given:
- **Pre-order Traversal:** `A B D E C F`
- **In-order Traversal:** `D B E A C F`

**Rebuilding Process:**
1. **Root Node:**
    - Pre-order first element: `A`
2. **Split In-Order Traversal:**
    - In-order sequence: `D B E [A] C F`
    - Left Subtree In-order: `D B E`
    - Right Subtree In-order: `C F`
3. **Split Pre-Order Traversal:**
    - Left Subtree Size: 3 (elements before `A` in-order)
    - Left Subtree Pre-order: `B D E` (next 3 elements after `A`)
    - Right Subtree Pre-order: `C F`
4. **Rebuild Left Subtree:**
    - **Root:** `B` (first element of left pre-order)
    - **In-order Left Subtree:** `D [B] E`
        - Left: `D`
        - Right: `E`
    - **Pre-order Left Subtree:**
        - Left: `D`
        - Right: `E`
    - **Construct Subtrees:**
        - Left Child of `B`:`D`
        - Right Child of `B`:`E`
5. **Rebuild Right Subtree:**
    - **Root:** `C` (first element of right pre-order)
    - **In-order Right Subtree:** `[C] F`
        - Left: empty
        - Right: `F`
    - **Pre-order Right Subtree:**
        - Right `F`
    - **Construct Subrees:**
        - Right Child of `C`:`F`
6. **Assemble the Tree:**
    ```
            A
           / \
          B   C
         / \   \
        D   E   F
    ```
### Scenario 2: Rebuilding from In-Order and Post-Order Traversals
The process is similar, but with adjustments:
**Step 1: Identify the Root Node**
- **Post-order Traversal:** The last element is always the root.
- **Action:** Take the last element of the post-order sequence as the root.

**Steps 2-5: Similar to the previous scenario, but using post-order traversal to split subtrees.**

### Example:
Given:
- **In-order Traversal:** `D B E A C F`
- **Post-order Traversal:** `D E B F C A`

**Process:**
1. **Root Node:** `A` (last element of post-order)
2. **Split In-Order Traversal:**
    - Left Subtree In-order: `D B E`
    - Right Subtree In order: `C F`
3. **Split Post-Order Traversal:**
    - Left Subtree Size: 3 (elements before root in in-order)
    - Left Subtree Post-order: `D E B`
    - Right Subtree Post-order: `F C`
4. **Rebuild Subtrees:** Recursively apply the steps to left and right subtrees.

---
### General Algorithm in Pseudocode
```
function buildTree(preOrder, inOrder):
    if preOrder is empty or inOrder is empty:
        return null

    rootValue = preOrder[0]
    root = new Node(rootValue)

    rootIndexInOrder = findIndex(inOrder, rootValue)

    leftInOrder = inOrder[0 : rootIndexInOrder]
    rightInOrder = inOrder[rootIndexInOrder + 1 : end]

    leftPreOrder = preOrder[1 : 1 + length(leftInOrder)]
    rightPreOrder = preOrder[1 + length(leftInOrder) : end]

    root.left = buildTree(leftPreOrder, leftInOrder)
    root.right = buildTree(rightPreOrder, rightInOrder)

    return root
```
#### Considerations
- **Unique Elements:** The above method assumes all elements are unique. If duplicates exist, additional information is needed to uniquely reconstruct the tree.
- **Time Complexity:**
    - Each recursive call involves slicing arrays and searching for the root index.
    - **Optimizations:**
        - Use a hash map to store in-order indices for O(1) access.
        - Avoid slicing by passing indices instead of creating new arrays.
---
### Conclusion
Rebuilding a binary tree from traversal sequences involves recursively identifying root noods and splitting traversal arrays into left and right subtrees. By carefully following the steps and utilizing the properties of tree traversals, you can reconstruct the original tree structure.

---
