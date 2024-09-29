# Written Assignment 1
CHRISTOPHER NILSSEN CSCI 260 F2402
1. Given a binary tree, where each of its tree nodes has the following struct `TreeNode` type:
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
`bool isAVLTree(TreeNode *root)`
(Note that you can write assistant function(s) to help with the checks.)

2. Suppose you are given an array A that contains N unique integer numbers in the range of [0..N] in sorted order (from smallest to largest). Note that there must be one number in the range [0..N] that is not in the array A. Write a C++ function style algorithm that can find the missing integer (the integer that is not in array A) in $Θ(\log N)$ time.

3. Given the following strings and their corresponding hash codes, draw the resulting 13-cell hash table by inserting these strings in the given order to the hash table and using linear probing to resolve (possible) collisions.

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

4. Find a Big-O characterization of the running time for the function shown below. Explain briefly how you reached your conclusion, including how you chose the problem size to perform the analysis.
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
            p = p + weight[j][i] * inputs[j]
        }
        outputs[i] = 1/(1+pow(e, -p));
    }
}
```

5. Consider the following recurrence equation that defines $T(N)$ as
$$
\begin{align}
&T(N) = 2\text{, if } N = 1 \nonumber \\
&T(N) = 2T(N-1) + 2 \text{, otherwise}. \nonumber
\end{align}
$$
Prove, but induction, that $T(N) = N^{(N+1)}-2$.

6. Consider the following recurrence equation that defines $T(N)$ as
$$
\begin{align}
&T(N) = 2\text{, if } N = 1 \nonumber \\
&T(N) = T(N-1) + 2N \text{, otherwise}. \nonumber
\end{align}
$$
Solve this recurrence equation and prove your solution by induction.

7. Characterize each of the following recurrence equations using the master theorem (assuming that $T(N) = c \text{ for } N \le d \text{, for constants } c > 0 \text{, and } d \ge 1$). Explain your reasons briefly.
    - $T(N) = 2T(N/2) + 100$
    - $T(N) = 2T(N/2) + N$
    - $T(N) = 6T(N/3) + N^2$
    - $T(N) = 4T(N/2) + (N\log N)^3$
    - $T(N) = T(N/2) + \log^2N$
    - $T(N) = 8T(N/2) + N^2\log N$
