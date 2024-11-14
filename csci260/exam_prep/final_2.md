# 2019 Final Exam
**1. Suppose you are given an array A that contains N unique integer numbers in the range of [0..N] in sorted order (from smallest to largest). Note that there must be one number in the range [0..N] that is not in the array A. Describe an algorithm that runs in $\Theta(\log N)$ time for finding the integer number that is not in array A.**

**Algorithm to find the missing number in $\Theta(\log N)$ time:**
1. **Initialize:**
    - Set `low = 0` and `high = N - 1`.
2. **Binary Search Loop:**
    - While `low ≤ high`:
        - Calculate `mid = (low + high) / 2`.
        - If `A[mid] == mid`:
            - Missing number is in the right half.
            - Set `low = mid + 1`.
        - Else:
            - Missing number is in the left half (including `mid`).
            - Set `high = mid - 1`.
3. **Result:**
    - The missing number is `low`.

**Explanation:**
- In a complete array without missing numbers, each element `A[i]` should equal its index `i`.
- If a number is missing, all elements after the missing number will have `A[i] > i`.
- The binary search efficiently locates the points where `A[i]` deviates from `i`, which indicates the missing number.

**Time Complexity:**
- The algorithm runs in $\Theta(\log N)$ time due to the binary search approach.
---

**2. Given the following red-black tree that stores integer numbers:**
```
             B10
           /     \
         B5       B42
        / \      /   \
      B2   B9   R23   B48
          /     / \
         R7   B15  B27
              / \    \
           R12  R20   R35
```
(a) If we ignore the color property of the nodes in the above tree, is it also an AVL tree? Justify your answer.
    No, the tree is not an AVL tree. At node 42, the left subtree has height 2, and the right subtree has height 0, resulting in a balance factor of 2. This exceeds the AVL tree balance requirement that the balance factor must be -1, 0, or 1.
(b) Draw the (2,4)-tree that is equivalent to the above given red-black tree.
```
                    10
            /                 \
        [5]                   [23, 42]
       /   \              /      |      \
    [2]  [7,9]  [12, 15, 20]  [27,35]  [48]
```
(c) Draw the resulting red-black tree by inserting number 19 to the above given red-black tree. Clearly indicate whether/where the re-coloring and/or tri-node-restructuring operations are required.
- **Insertion Steps:**
    - Insert 19 as a red node as the left child of node 20.
    - **Violation:** Red parent (20) with red child (19).
    - **Uncle Node:** Node 12 (red).
    - **Action:** Recolor nodes:
        - Set nodes 12 and 20 to black.
        - Set node 15 to red.
    - **Violation:** Red parent (23) with red child (15).
    - **Uncle Node:** Node 27 (black).
    - **Right Rotation:** Node 23.
    - **Recolor:** Set node 15 to black and 23 to red.
```
             B10
           /     \
         B5       B42
        / \      /   \
      B2   B9   B15   B48
          /     / \
         R7   R12  R23
                \    \
                B20   B27
                /       \
              R19       R35
                   
```