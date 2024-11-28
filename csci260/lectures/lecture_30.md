# Lecture 30
## Dynamic Programming
Dynamic programming is a method for efficiently solving complex problems by breaking them down into simpler subproblems. It is particularly useful for optimization problems. Dynamic programming algorithms have the following key properties:

### Properties:
1. **Optimal Substructure:** The optimal solution to a problem contains optimal solutions to its subproblems. This means that solving the larger problem relies on the solutions to smaller, similar problems.
2. **Overlapping Subproblems:** The problem can be broken down into subproblems that are reused multiple times. This allows us to store the results of subproblems (memoization) to avoid reduntand computations.
3. **Memoization or Tabulation:** Dynamic programming stores the results of subproblems to avoid recomputing them. This is typically done through a table or memoization.

---

## Matrix Chain Multiplication Problem 
### Problem Statement
Given a sequence of matrics $A_1, A_2, \dots, A_n$, we want to compute the product $A_1 A_2 \dots A_n$. The goal is to determine the most efficient way to parenthesize the product to minimize the total number of scalar multiplications.

**Note:** Matrix multiplication is associateve but not commutative. This means while the order of multiplication cannot change, the grouping (parentheses placement) can.

### Matrix Dimensions
Each matrix $A_i$ has dimensions $p_{i-1} \times p_i$, where $p_0,p_1,\dots,p_n$ is a sequence of dimensions. The multiplication cost of two matrices $A$ (of size $p \times q$) and $B$ (of size $q \times r$) is $p \times q \times r$ scalar multiplications.

---

## Dynamic Programming Solution
### Defining Subproblems
Let $m[i,j]$ denote the minimum number of scalar multiplications needed to compute the matrix $A_i A_{i+1} ... A_j$.

### Recursive Forumula
For $i \le j$, the minimal cost $m[i,j]$ can be computed using:
$$
m[i,j] = \begin{cases} 0 &\text{ if } i = j \\
\min_{i\le k < j} \{m[i,k] + m[k + 1, j] + p_{i-1} \times p_k \times p_j\} &\text{ if } i < j
\end{cases}
$$
- Explanation:
    - $m[i,k]$: Cost of computing $A_i \dots A_k$
    - $m[k + 1, j]$: Cost of computing $A_{k+1} \dots A_j$.
    - $p_{i-1} \times p_k \times p_j$: Cost of multiplying the two resulting matrices.
    - We consider all possible $k$ to find the minimum cost.

### Algorithm
```python
# Let M be a 2D array of size N x N to store minimal costs
# P is an array of dimensions p0, p1, ..., pn

def matrix_chain_order(P):
    N + len(P) - 1  # Number of matrices
    M = [[0 if i == j else float('inf') for j in range(N)] for i in range(N)]
    S = [[0 for j in range(N)] for i in range(N)]   # To store split positions

    for chain_len in range(2, N + 1):   # Chain lengths from 2 to N
        for i in range(N - chain_len + 1):
            j = i + chain_len - 1
            for k in range(i, j):
                q = M[i][k] + M[k + 1][j] + P[i] * P[k + 1] * P[j + 1]
                if q < M[i][j]:
                    M[i][j] = q
                    S[i][j] = k
    
    return M, S # M contains minimal costs, S contains split positions.
```

```cpp
#include <vector>
#include <climits>  // for INT_MAX

using std::vector;

void matrix_chain_order(const vector<int>& P, vector<vector<int>>& M, vector<vector<int>>& S) {
    int N = P.size() - 1;   // number of matrices

    // initialize M and S
    M.assign(N, vector<int>(N, 0));
    S.assign(N, vector<int>(N, 0));

    for (int chain_len = 2; chain_len <= N; ++chain_len) {  // chain lengths from 2 to N
        for (int i = 0; i < N - chain_len + 1; ++i) {
            int j = i + chain_len -1;
            M[i][j] = INT_MAX;  // set initial value to +inf
            for (int k = i; k < j; ++k) {
                int q = M[i][k] + M[k + 1][j] + P[i] * P[k + 1] * P[j + 1];
                if (q < M[i][j]) {
                    M[i][j] = q;
                    S[i][j] = k
                }
            }
        }
    }
}
```

- **Initialization:**
    - $M[i][i] = 0$ for all $i$.
- **Loop Structure:**
    - The outer loop iterates over the chain lengths from $2$ to $N$.
    - The inner loops iterate over possible starting indices $i$ and split positions $k$.

### Time Complexity
- The algorithm runs in $O(N^3)$ time due to the three nested loops.

---

## Populating the Cost Matrix
### Understanding the Grid
The grid represents the cost matrix $m[i,j]$, where $i$ and $j$ are matrix indices:

| | 1 | 2 | 3 | 4
| :- | :- | :- | :- | :-
| 1 | 0 | $m[1,2]$ | $m[1,3]$ | $m[1,4]$
| 2 | | 0 | $m[2,3]$ | $m[2,4]$
| 3 | | | 0 | $m[3,4]$
| 4 | | | | 0

- **Explanation:**
    - Diagonal entries $m[i,i]$ are zero because multiplying one matrix requires no scalar multiplications.
    - The upper triangular part contains the costs $m[i,j]$ for $i<j$.

### How is the Grid Populated?
1. **Initialize Diagonal:** Set $m[i,i] = 0$ for all $i$.
2. **Compute Costs for Chains of Length $l$:**
    - For chain lengths $l$ from $2$ to $N$:
        - For each possible $i$:
            - Compute $j = i + l - 1$
            - Initialize $m[i,j] = \infty$.
            - For each possible split position $k$ from $i$ to $j - 1$:
                - Compute $q = m[i,k] + m[k+1, j] + p_{i-1} \times p_k \times p_j$.
                - If $q < m[i,j]$, update $m[i,j]= q$ and record $k$.
3. **Example for $m[1,3]$:**
    - Possible split positions: $k = 1$ and $k = 2$.
    - Compute:
        - For $k = 1: q = m[1,1] + m[2,3] + p_0 \times p_1 \times p_3$
        - For $k = 2: q = m[1,2] + m[3,3] + p_0 \times p_2 \times p_3$
    - Choose the minimum $q$ to set $m[1,3]$

### How Are the Minimums Determined?
- **By Evaluating All Possible Splits:
    - For each $m[i,j]$ we consider all possible split positions $k$.
    - We calculate the cost $q$ for each split.
    - The minimal cost is the minimum of all $q$ values computed.

---

## Understanding the Minimums Expression
$$
\min = \begin{cases} m[1,1] + m[2,3] + p_0 \times p_1 \times p_3 &\text{ if } k = 1 \\
m[1,2] + m[3,3] + p_0 \times p_2 \times p_3 &\text{ if } k = 2
\end{cases}
$$

- **Explanation:**
    - This is the computation for $m[1,3]$.
    - We are considering two possible split points:
        - **Split at $k = 1$:**
            - Multiply the resut of $A_1$ (which is just $A_1$) and $A_2 A_3$.
            - Cost: $m[1,1] + m[2,3] + p_0 \times p_1 \times p_3$.
        - **Split at $k = 2$:**
            - Multiplay the result of $A_1 A_2$ and $A_3$.
            - Cost: $m[1,2] + m[3,3] + p_0 \times p_2 \times p_3$.
        - We choose the minimum of these two costs for $m[1,3]$.

---

## Diagonal Iteration
```plaintext
for k = 0 to +inf
    for i = 0 to k
        visit[i][k - i];
```
- In the context of the dynamic programming solution, we often fill the table $M[i][j]$ diagonally, starting from the shortest chains to the longest.
- However, in the standard algorithm, we use chain lengths $l$ and iterate accordingly.

---

## Putting It All Together
### Steps to Solve the Matrix Chain Multiplication Problem
1. **Determine the Dimensions:**
    - Create the dimension array $P$ with $N + 1$ elements.
    - Each matrix $A_i$ has dimensions $P[i - 1] \times P[i]$.
2. **Initialize the Cost Matrix:**
    - Set $M[i][i] = 0$ for all $i$.
3. **Compute Minimal Costs:**
    - Use the dynamic programming algorithm to fill the cost matrix $M$ and split matrix $S$.
4. **Retrieve the Optimal Parenthesization:**
    - Use the split matrix $S$ to reconstruct the optimal parenthesization.

### Example
Let's consider matrices $A_1,A_2,A_3,A_4$ with dimensions:
- $A_1:10 \times 30$
- $A_2:30 \times 5$
- $A_3:5 \times 60$
- $A_4:60 \times 10$

**Dimension Array P:**
$P=[10,30,5,60,10]$

**Applying the Algorithm:**
- **Initialization:**
    - $M[i][i] = 0$ for $i=1$ to $4$.
- **Compute $m[1,2]$:**
    - $q = 0 + 0 + 10 \times 30 \times 5 = 1500$
    - $M[1][2] = 1500$
- **Compute $m[2,3]$:**
    - $q = 0 + 0 + 30 \times 5 \times 60 = 9000$
    - $M[2][3] = 9000$
- **Compute $m[3,4]$:**
    - $q = 0 + 0 + 5 \times 60 \times 10 = 3000$
    - $M[3][4] = 3000$
- **Compute $m[1,3]$:**
    - For $k = 1$:
        - $q = 0 + 9000 + 10 \times 30 \times 60 = 27000$
    - For $k = 2$:
        - $q = 1500 + 0 + 10 \times 5 \times 60 = 4500$
    - $M[1][3] = 4500$ (minimum of 27000 and 4500)
- **Compute $m[2,4]$:**
    - For $k = 2$:
        - $q = 0 + 3000 + 30 \times 5 \times 10 = 4500$
    - For $k = 3$:
        - $q = 9000 + 0 + 30 \times 60 \times 10 = 27000$
    - $M[2][4] = 4500$ (minimum of 4500 and 27000)
- **Compute $m[1,4]$:**
    - For $k = 1$:
        - $q = 0 + 4500 + 10 \times 30 \times 10 = 7500$
    - For $k = 2$:
        - $q = 1500 + 3000 + 10 \times 5 \times 10 = 5000$
    - For $k = 3$:
        - $q = 4500 + 0 + 10 \times 60 \times 10 = 10500$
    - $M[1][4] = 5000$ (minimum of 7500, 5000, and 10500)

---

### Summary
- **Dynamic Programming:**
    - Breaks down the problem into overlapping subproblems.
    - Stores results to avoid redundant computations.
- **Matrix Chain Multiplication:**
    - Seeks the optimal parenthesization to minimize scalar multiplications.
    - Uses a cost matrix $M$ and a split matrix $S$.
- **Algorithm Complexity:**
    - Runs in $O(N^3)$ time.
- **Table Population:**
    - Fills the cost matrix by considering all chain lengths and possible split locations.
    - Selects the minimum costs at each step.

---
