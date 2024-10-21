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
};

// binary search tree checker
bool isBST(TreeNode *node, TreeNode *minNode, TreeNode *maxNode) {
    if (node == nullptr)
        return true;

    if ((minNode != nullptr && node->key <= minNode->key) || (maxNode != nullptr && node->key >= maxNode->key))
        return false;

    // recursively go through tree
    return isBST(node->left, minNode, node) && isBST(node->right, node, maxNode);
}

// tree height and balance checker (optimized)
int checkHeightAndBalance(TreeNode *node, bool &isBalanced) {
    if (node == nullptr)
        return 0;

    int leftHeight = checkHeightAndBalance(node->left, isBalanced);
    int rightHeight = checkHeightAndBalance(node->right, isBalanced);

    // check balance at current node
    if (abs(leftHeight - rightHeight) > 1)
        isBalanced = false;

    // return the height of the current node
    return std::max(leftHeight, rightHeight) + 1;
}

// AVL tree check
bool isAVLTree(TreeNode *root) {
    if (root == nullptr)
        return true;

    if (!isBST(root, nullptr, nullptr))
        return false;
    
    bool balanced = true;
    checkHeightAndBalance(root, balanced);
    
    return balanced;
}
```
---
#### 2. Suppose you are given an array A that contains N unique integer numbers in the range of [0..N] in sorted order (from smallest to largest). Note that there must be one number in the range [0..N] that is not in the array A. Write a C++ function style algorithm that can find the missing integer (the integer that is not in array A) in $Θ(\log N)$ time.

A binary search ($\Theta\log N$) is in order:
```
int findMissingInt(const int A[], int N) {
    int low = 0;
    int high = N - 1;  // A has N elements (so the valid index range is 0 to N-1)

    while (low <= high) {
        int mid = low + (high - low) / 2;
    
        if (A[mid] > mid) {
            // missing integer must be at or before index 'mid'
            high = mid - 1;
        } else {
            // missing integer must be after index 'mid'
            low = mid + 1;
        }
    }

    // 'low' now points to the missing integer
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
| :--- | :---
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
&= 2(2^{k+1}-2) + 2 \text{( by the inductive hypothesis)} \\
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

- $T(1) = 2$
- $T(2) = T(1) + 2(2) = 2 + 4 = 6$
- $T(3) = T(2) + 2(3) = 6 + 6 = 12$
- $T(4) = T(3) + 2(4) = 12 + 8 = 20$
- $T(5) = T(4) + 2(5) = 20 + 10 = 30$

**Pattern and assumed closed-form solution:**
$$
T(N) = N(N+1) 
$$

**Base Case $N = 1$**

First, we verify that the formula holds for $N = 1$.

**Left Side (Recurrence Relation):**

Given T(1) = 2.

**Right Side (Closed-Form Formula)**
$$
1(1+1) = 1\times 2 = 2
$$

**Conclusion:**

Since both sides equal 2, the formula holds for $N = 1$.

**Inductive Step:**

Assume that the formula holds for some integer $N = k\ge 1$; that is,
$$
T(k) = k(k+1)
$$

This assumption is the **Inductive hypothesis**.

We need to show that the formula also holds for $N=k+1$, i.e., we need to show:
$$
T(k+1) = (k+1)((k+1)+1) = (k+1)(k+2)
$$

Using the recurrence relation, we know:
$$
T(k+1) = T(k) + 2(k+1).
$$

Substitute the inductive hypothesis $T(k) = k(k+1)$ into this equation:
$$
T(k+1) = k(k+1) + 2(k+1)
$$

Factor out $(k+1)$:
$$
T(k+1) = (k+1)(k+2)
$$

This matches the closed-form solution for $T(k+1)$, so the inductive step holds.

**Conclusion:**
By the principle of mathematical induction, the closed-form solution to the recurrence relation is:
$$
T(N) = N(N+1).
$$


---
#### 7. Characterize each of the following recurrence equations using the master theorem (assuming that $T(N) = c \text{ for } N \le d \text{, for constants } c > 0 \text{, and } d \ge 1$). Explain your reasons briefly.
- $T(N) = 2T(N/2) + 100$
    - $a = 2, b = 2, f(N) = 100$
    - $N^{\log_ba} = N^{\log_22} = N^1 = N$
    - $f(N)$ grows slower than $N$ (since $f(N) = 100 is constant), this is Case 1 of the Master Theorem.
    - Since $f(N) = O(N^{\log_ba-\epsilon})$ for some $\epsilon > 0$, then $T(N) = \Theta(N^{\log_ba})$
    - Thus, $T(N) = \Theta(N)$
- $T(N) = 2T(N/2) + N$
    - $a = 2, b = 2, f(N) = N$
    - $N^{\log_ba} = N^{\log_22} = N^1 = N$
    - $f(N)$ grows at the same rate as $N$, this is Case 2 of the Master Theorem.
    - $f(N) = \Theta(N^{\log_ba} \cdot \log^kN)$ for some $k\ge 0$.
    - Thus, $T(N) = \Theta(N\log N)$
- $T(N) = 6T(N/3) + N^2$
    - $a =6, b =3, f(N) = N^2$
    - $N^{\log_ba} = N^{\log_36} < N^2$
    - $f(N)$ grows faster than $N$, this is Case 3 of the Master Theorem.
    - Since $f(N) = \Omega(N^{\log_ba+\epsilon})$ for some $\epsilon > 0$, and $f(N)$ satisfies the regularity condition, we conclude:
    - Thus, $T(N) = \Theta(f(N)) = \Theta(N^2)$
- $T(N) = 4T(N/2) + (N\log N)^3$
    - $a = 4$, $b = 2$, $f(N) = (N\log N)^3$
    - $N^{\log_b a} = N^{\log_2 4} = N^{2}$
    - $f(N) = N^3 (\log N)^3$
    - Since $f(N)$ grows faster than $N^{2}$ (because of the extra $N$ and $\log N$ factors), this is Case 3 of the Master Theorem.
    - We verify the regularity condition:
        - Compute $a f(N/b)$:
            - $f(N/b) = \left(\frac{N}{2}\log\frac{N}{2}\right)^3 = \left(\frac{N}{2}\left(\log N - 1\right)\right)^3$
            - $a f(N/b) = 4 \times \left(\frac{N}{2}\left(\log N - 1\right)\right)^3 = N^3 \left(\log N - 1\right)^3$
        - Compute $c f(N)$:
            - $f(N) = N^3 (\log N)^3$
            - For large $N$, $\left(\log N - 1\right)^3 \approx (\log N)^3$, so $a f(N/b) \leq c f(N)$ with $c = 1$
        - Since $c < a$, the regularity condition is satisfied.
    - Thus, $T(N) = \Theta(f(N)) = \Theta\left(N^3 (\log N)^3\right)$
- $T(N) = T(N/2) + \log^2N$
    - $a = 1$, $b = 2$, $f(N) = \log^2 N$
    - $N^{\log_b a} = N^{\log_2 1} = N^{0} = 1$
    - Since $f(N) = \Theta(N^{0} \log^k N)$ with $k = 2$, this is Case 2 of the Master Theorem.
    - Therefore, $T(N) = \Theta(N^{0} \log^{k+1} N) = \Theta(\log^{3} N)$
- $T(N) = 8T(N/2) + N^2\log N$
    - $a = 8$, $b = 2$, $f(N) = N^2\log N$
    - $N^{\log_b a} = N^{\log_2 8} = N^{3}$
    - Since $f(N) = N^2 \log N$ grows slower than $N^{3}$, this is Case 1 of the Master Theorem.
    - Because $f(N) = O\left(N^{\log_b a - \epsilon}\right)$ for some $\epsilon > 0$, we have $T(N) = \Theta\left(N^{\log_b a}\right)$
    - Thus, $T(N) = \Theta(N^{3})$
