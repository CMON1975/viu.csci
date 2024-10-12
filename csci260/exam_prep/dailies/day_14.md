## Day 14: AVL Trees and Rotations
- **Topics Covered**:
    - Understanding AVL tree properties.
    - Double rotations (Left-Right and Right-Left rotations).
- **Study Activities**:
    - **Balancing Factor**: Learn how to calculate and interpret it.
    - **Rotations Algorithms**: Study the steps involved in single and double rotations.
    - **Insertion Impact**: Determine how inserting certain values affects tree balance.
- **Practice**:
    - Insert elements that cause double rotations and perform the rotations.
    - Draw the AVL tree before and after rotations.

### 1. How is the balancing factor in an AVL tree calculated and intrepreted?
In an AVL tree, **the balance factor** of a node is a measure used to check whether the tree remains balanced after insertions or deletions. It is calculated as the difference between the heights of the left and right subtrees of that node.

**For any given node `N`:**
$\text{Balance Factor (BF) = Height of Left Subtree - Height of Right Subtree}$
- **Interpretation:**
    - **BF = -1, 0, or 1:** The node is balanced.
    - **BF < -1 or BF > 1:** The node is unbalanced and requires balancing through rotations.

**Example:**
```
     N
    / \
   L   R
```
- If the height of the left subtree `L` is 2 and the right subtree `R` is 1, then:
    - **BF(N) = 2 - 1 = 1 (Balanced)**

---
### 2. What are the steps involved in single and double rotations?
**Single Rotations:**
- **Left Rotation (LL Rotation):**
    - Applied when a node is inserted into the right subtree of the right child, causing an imbalance.
    - **Steps:**
        1. Let `x` be the unbalanced node.
        2. Let `y` be the right child of `x`.
        3. Move `y` up to replace `x`.
        4. Make `x` the left child of `y`.
        5. Attach `y`'s original left subtree as the right subtree of `x`.
- **Right Rotation (RR Rotation):**
    - Applied when a node is inserted into the left subtree of the left child.
    - **Steps:**
        1. Let `x` be the unbalanced node.
        2. Let `y` be the left child of `x`.
        3. Move `y` up to replace `x`.
        4. Make `x` the right child of `y`.
        5. Attach `y`'s original right subtree as a left subtree of `x`.

**Double Rotations:**
    - **Left-Right Rotation (LR Rotation):**
        - Occurs when a node is inserted into the right subtree of the left child.
        - **Steps:**
            1. Perform a **left rotation** on the left child of the unbalanced node.
            2. Perform a **right rotation** on the unbalanced node.
    - **Right-Left Rotation (RL Rotation):**
        - Occurs when a node is inserted into the left subtree of the right child.
        - **Steps:**
            1. Perform a **right rotation** on the right child of the unbalanced node.
            2. Perform a **left rotation** on the unbalanced node.

---
### 3. How do inserting certain values affect tree balance?
- **Insertion Impact:**
    - Inserting values can cause the tree to become unbalanced if the heights of the subtree differ by more than 1.
    - **Skewed Insertions:** Adding nodes in sorted order (e.g., ascending or descending) can create a skewed tree resembling a linked list, causing maximum imbalance.
- **Balancing Mechanism:**
    - AVL Trees automatically perform rotations to rebalance after insertions.
    - The type of rotation depends on the insertion path:
        - **Same Side Insertions:** Single rotation suffices (LL or RR).
        - **Opposide Side Insertions:** Double rotation is needed (LR or RL).

---
### 4. Insert elements that cause double rotations and perform the rotation.
To illustrate how double rotations work in an AVL tree, let's consider an example that requires a **Left-Right (LR) Rotation**.

**Example Insertion Sequence Causing LR Rotation:**
- **Insertions: 30, 20, 25

**Step-by-Step Process:**
1. **Insert 30:**
```
   30
```
2. **Insert 20:**
```
   30
  /
 20 
```
3. **Insert 25:**
```
   30
  /
 20
  \
   25
```
At this point, the tree becomes unbalanced at node **30**.
- **Balance Factors:**
    - **BF(20)** = Height of Left Subtree - Height of Right Subtree = 0 - 1 = -1
    - **BF(30)** = Height of Left Subtree - Height of Right Subtree = 2 - 0 = -2 (Unbalanced)
- **Unbalanced at Node 30:**
    - The imbalance occurs due to a node inserted into the **right subtree of the left child** (i.e., Left-Right case).
    - **Required Rotation: Left-Right (LR) Rotation**

**Performing the LR Rotation:**
- **Step 1:** Perform a **Left Rotation** on node **20**.
**Before Left Rotation on 20:**
```
   30
  /
 20
  \
   25
```
**After Left Rotation on 20:**
```
    30
   /
  25
 /
20
```
- **Step 2:** Perform a **Right Rotation** on node 30.
**Before Right Rotation on 30:**
```
    30
   /
  25
 /
20
```
**After Right Rotation on 30:**
```
    25
   /  \
  20  30
```
Now, the tree is balanced, and all nodes have balance factors of -1, 0, or 1.

---
