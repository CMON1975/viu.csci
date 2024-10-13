# Written Assignment 1
CHRISTOPHER NILSSEN CSCI 260 F2402
#### 1. Given a binary tree, where each of its tree nodes has the following struct `TreeNode` type:
```
struct TreeNode {
    int key;
    Data * data;
    TreeNode *left;
    TreeNode *right;
};
```
write a C++ function style algorithm to check whether this binary tree is an AVL tree where in-order traversal lists the keys sorted from the smallest to the largest.
The prototype of the function is shown below:
```
bool isAVLTree(TreeNode *root)
```
(Note that you can write assistant function(s) to help with the checks.)

```
struct Data {
    // whatever's required for the data structure
};

// tree node per spec
struct TreeNode {
    int key;
    Data *data;
    TreeNode *left;
    TreeNode *right;
}

// binary search tree checker
bool isBST(TreeNode *node, TreeNode *minNode, TreeNode *maxNode) {
    if (node == NULL)
        return true;

    if ((minNode != NULL && node->key <= minNode->key) || (maxNode != NULL && node->key >= maxNode->key))
        return false;

    // recursively go through tree
    return isBST(node->left, minNode, node) && isBST(node->right, node, maxNode);
}

// tree height calculator
int getHeight(TreeNode *node) {
    if (node == NULL)
        return 0;

    // recursive checks
    int leftHeight == getHeight(node->left);
    int rightHeight == getHeight(node->right);

    int height;
    if (leftHeight > rightHeight)
        height = leftHeight + 1;
    else
        height = rightHeight + 1;

    return height;
}

// tree balance check
bool isBalanced(TreeNode *node) {
    if (node == NULL)
        return true;

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    int heightDifference = leftHeight - rightheight;
    if (heightDifference < 0)
        heightDifference = -heightDifference; // absolute value fix

    if (heightDifference > 1)
        return false;

    return isBalanced(node->left) && isBalanced(node->right);
}

// AVL tree check
bool isAVLTree(TreeNode *root) {
    if (root == NULL)
        return true;

    if (!isBST(root, NULL, NULL))
        return false;
    
    if (!isBalanced(root))
        return false;

    return true;
}
```
---
#### 2. Suppose you are given an array A that contains N unique integer numbers in the range of [0..N] in sorted order (from smallest to largest). Note that there must be one number in the range [0..N] that is not in the array A. Write a C++ function style algorithm that can find the missing integer (the integer that is not in array A) in $Θ(\log N)$ time.

A binary search ($\Theta\log N$) is in order:
```
int findMissingInt(const int A[], int N) {
    int low = 0;
    int high = N - 1; // A has N elements

    while (low <= high) {
        int mid = low + (high - low) / 2;
    
        if (A[mid] > mid) {
            // target int at or before mid
            high = mid - 1;
        } else {
            // target is after mid
            low = mid + 1;
        }
    }

    // low is the smallest index where A[i] > i, thus the target int
    return low;
}
```
---
#### 3. Given the following strings and their corresponding hash codes, draw the resulting 13-cell hash table by inserting these strings in the given order to the hash table and using linear probing to resolve (possible) collisions.

| string | hash code 
| :--- | :--- 
| brute | 10 
| force | 11
| greedy | 7
| backtracking | 10
| dynamic | 7
| programming | 8
| abstract | 0
| methodology | 9

- Attempt to insert `brute` at index 10. No collision. Insert at index 10.
- Attempt to insert `force` at index 11. No collision. Insert at index 11.
- Attempt to insert `greedy` at index 7. No collision. Insert at index 7.
- Attempt to insert `backtracking` at index 10. Collision. 
    - Probe index 11. Collision.
    - Probe index 12. No collision. Insert at index 12.
- Attempt to insert `dynamic` at index 7. Collision.
    - Probe index 8. No collision. Insert at index 8.
- Attempt to insert `programming` at index 8. Collision.
    - Probe index 9. No collision. Insert at index 9.
- Attempt to insert `abstract` at index 0. No collision. Insert at index 0.
- Attempt to insert `methodology` at index 9. Collision.
    - Probe index 10. Collision.
    - Probe index 11. Collision.
    - Probe index 12. Collsion.
    - Wrap around and probe index 0. Collision.
    - Probe index 1. No collision. Insert at index 1.

Resulting array:
| index | string
| :- | :-
| 0 | abstract
| 1 | methodology
| 2 | empty
| 3 | empty
| 4 | empty
| 5 | empty
| 6 | empty
| 7 | greedy
| 8 | dynamic
| 9 | programming
| 10 | brute
| 11 | force
| 12 | backtracking

---
#### 4. Find a Big-O characterization of the running time for the function shown below. Explain briefly how you reached your conclusion, including how you chose the problem size to perform the analysis.
```
// one layer neural netword forward calculations;
// there are M neurons in the previous layer, and
// inputs[M] are the M outputs from these M neurons respectively;
// there are N neurons in the current layer;
Algorithm AIForward
    (double weights[M][N], double inputs[M], double outputs[N], int M, int N)
{
    for (int i = 0; i < N; i++) {
        p = 0
        for (int j = 0; j < M; j++) {
            p = p + weights[j][i] * inputs[j]
        }
        outputs[i] = 1/(1+pow(e, -p));
    }
}
```
**Problem Size:**
- $M$: Number of neurons in the previous layer.
- $N$: Number of neurons in the current layer.

**Algorithm Analysis:**
1. **Outer Loop ($i$ from $0$ to $N - 1$):**
    - Runs $N$ times, for each neuron in the current layer.
2. **Inner Loop ($j$ from $0$ to $M - 1$):**
    - Runs $M$ times for each iteration of the outer loop.
    - Calculates the weighted sum for each neuron in the current layer.
    - **Operations inside the inner loop:**
        - Multiplication: `weight[j][i] * inputs[j]` O(1)
        - Addition: `p = p + ...` O(1)
        - Total time per inner loop iteration: O(1)
3. **Operations after the Inner Loop:**
    - Activation function computation: `outputs[i] = 1 / (1 + pow(e, -p))`
    - Exponential and division operations are considered O(1) (constant time) in algorithmic analysis.

**Total Computations:**
- **Inner Loop Operations:**
    - $N$ (outer loop iterations) * $M$ (inner loop iterations) * O(1) = O($M \times N)$
- **Outer Loop Operations (excluding inner loop):**
    - $N$ * O(1) = O($N$)
- **Combined Total Operations:**
    - $O(M\times N) + O(N) \approx O(M\times N)$ since $M\times N$ dominates if $M\ge 1$.

**Conclusion:**
The running time of the `AIForward` function grows proportionally with the product of $M$ and $N$. Therefore, the Big-O characterization is:
$$
O(M \times N)
$$

---
#### 5. Consider the following recurrence equation that defines $T(N)$ as
$$
\begin{align}
&T(N) = 2\text{, if } N = 1 \nonumber \\
&T(N) = 2T(N-1) + 2 \text{, otherwise}. \nonumber
\end{align}
$$
Prove by induction that $T(N) = N^{(N+1)}-2$.

**Base Case $(N = 1)$**

First, we verify that the formula holds for $N=1$.

**Left Side (Recurrence Relation):**

Given $T(1) = 2$.

**Right Side (Closed-Form Formula):**
$$
T(1) = 2^{1+1} - 2 = 2^2 - 2 = 4 - 2 = 2.
$$

**Conclusion:**

Since both sides equal 2, the formula holds for $N = 1$.

**Inductive Step:**

Assume that the formula holds for some integer $N = k\ge 1$; that is,
$$
T(k) = 2^{k+1} - 2.
$$

This assumption is the **inductive hypothesis**.

We need to show that the formula also holds for $N = k + 1$; that is,
$$
T(k+1) = 2^{(k+1)+1}-2 = 2^{k+2}-2
$$

**Proof:**

Starting with the recurrence relation for $T(k+1)$:
$$
\begin{aligned}
T(k+1) &= 2T(k) + 2 \\
&= 2(2^{k+1}-2) + 2 \text( {by the inductive hypothesis}) \\
&= 2 \cdot 2^{k+1} - 4 + 2 \\
&= 2^{k+2} - 2 
\end{aligned}
$$

Since $T(k+1) = 2^{k+2} -2$, the formula holds for $N = k + 1$.

By the principle of mathermatical induction, the formula $T(N) = 2^{N+1} - 2$ holds for all integers $N\ge 1$.

---
#### 6. Consider the following recurrence equation that defines $T(N)$ as
$$
\begin{align}
&T(N) = 2\text{, if } N = 1 \nonumber \\
&T(N) = T(N-1) + 2N \text{, otherwise}. \nonumber
\end{align}
$$
Solve this recurrence equation and prove your solution by induction.

---
#### 7. Characterize each of the following recurrence equations using the master theorem (assuming that $T(N) = c \text{ for } N \le d \text{, for constants } c > 0 \text{, and } d \ge 1$). Explain your reasons briefly.
- $T(N) = 2T(N/2) + 100$
- $T(N) = 2T(N/2) + N$
- $T(N) = 6T(N/3) + N^2$
- $T(N) = 4T(N/2) + (N\log N)^3$
- $T(N) = T(N/2) + \log^2N$
- $T(N) = 8T(N/2) + N^2\log N$
