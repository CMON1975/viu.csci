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

**3. Write a C++ like algorithm that takes a string, an integer array whose size is 26, as its parameters and generates the frequency table (as the ones used in Huffman Encoding) for letters. This algorithm should be case-insensitive (i.e., treading upper-case letters the same as lower-case ones) and ignore all other characters that are not letters.**

```cpp
void GenerateFrequencyTable(string s, int freq[26]) {
    // assume frequency array initialized to zero

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];

        // check if the character is a letter
        if (isLetter(c)) {
            // convert to lowercase
            c = toLowerCase(c);

            // map 'a' - 'z' to 0-25
            int index = c - 'a';

            // increment the frequency
            ++freq[index];
        }
    }
}

// helper to check if the character is a letter
bool isLetter(char c) {
    return ( (c >= 'a' && c <= 'z') || (c >= 'A' && c<= 'Z') );
}

// helper to convert uppercase to lowercase
char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A'); // ASCII value adjustment
    else
        return c;
}
```

**4. Given the following undirected and weighted graph G:**

```
A: [(B,10), (C,12), (D,4)]
B: [(A,10), (C,15), (E,2)]
C: [(A,12), (B,15),(D,29),(E,3),(F,11)]
D:[(A,4),(C,29),(H,30)]
E:[(B,2), (C,3), (F,20)]
F:[(C,11),(E,20),(H,27)]
H:[(D,30),(F,27)]
```

(a) Order the vertices as they are visited in the depth first traversal starting at vertex D. List all the **discovery** edges.

| Current Node | Visited Nodes
| :- | :-
| D | D
| A | D, A
| B | D, A, B
| C | D, A, B, C
| E | D, A, B, C, E
| F | D, A, B, C, E, F
| H | D, A, B, C, E, F, H

Remarkably, there was no need for backtracking in this traversal. The DFS order of vertices is **D, A, B, C, E, F, H** and the list of discovery edges is **D-A, A-B, B-C, C-E, E-F, and F-H.**

(b) Draw the adjacency matrix for the given graph.

|  | A | B | C | D | E | F | H
| :- | :- | :- | :- | :- | :- | :- | :-
| **A** | 0 | 10 | 12 | 4 | 0 | 0 | 0
| **B** | 10 | 0 | 15 | 0 | 2 | 0 | 0
| **C** | 12 | 15 | 0 | 29 | 3 | 11 | 0
| **D** | 4 | 0 | 29 | 0 | 0 | 0 | 30
| **E** | 0 | 2 | 3 | 0 | 0 | 20 | 0
| **F** | 0 | 0 | 11 | 0 | 20 | 0 | 27
| **H** | 0 | 0 | 0 | 30 | 0 | 27 | 0

(c) Show the execution steps of the Dijstra's algorithm of single-source shortest path to all (reachable) vertices starting at vertex B.

1. choose B, dist 0;
    - update A = 10, C = 15, E = 2;
    - B done;
2. choose E, dist 2;
    - update C via E: 2 + 3 = 5 (was 15);
    - update F via E: 2 + 20 = 22;
    - E done;
3. choose C, dist 3;
    - update D: 5 + 29 = 34;
    - update F: 5 + 11 = 16 (was 22);
    - C done;
4. choose A, dist 10;
    - update D: 10 + 4 = 14 (was 34);
    - A done;
5. choose D, dist 14;
    - update H: 14 + 30 = 44;
    - D done;
6. choose F, dist 16;
    - update H: 16 + 27 = 43 (was 44);
    - F done;
7. choose H, no updates;
    - H done;

Final distances: B:0, C:5, D:14, E:2, F:16, H:43

**5. Suppose that you are given two arrays, _alphabet_ and _code_. Each element of _alphabet_ contains an alphabet character, and the same position element of _code_ contains the huffman code of that alphabet character. Each Huffman code is stored as a string of 0's and 1's. The two arrays have the same (positive) size and the size is known. Describe an alagorithm that constructs a Huffman tree based on these two arrays. You need to design a concrete data structure for each node of the Huffman tree first.**

**Data structure for a Huffman tree node:**
```cpp
struct HuffmanNode {
    char letter;    // holds the character if this is a leaf node
    HuffmanNode *left;  // left child
    HuffmanNode *right; // right child
    // non-leaf nodes may have letter set to a placeholder like '\0'
};
```

**Algorithm to construct the Huffman tree from given arrays:**
1. The root node is initialized as a placeholder node with its `letter` set to `\0` to signify that it is not a leaf."
2. for each character in the alphabet array and its corresponding code in the code array:
    - start from the root node.
    - for each bit in the code, where each bit corresponds to a left (`0`) or right (`1`) movement from the current node:
        - if the bit is '0':
            - if the left child does not exist, create it with letter '\0' and null children
            - move to the left child
        - if the bit is '1':
            - if right child does not exist, create it with the letter '\0' and null children
            - mode to the right child
        - once you reach the end of the code, set the current node's letter to the corresponding character from the alphabet array (indicating it is now a leaf node).
    The algorithm assumes the arrays `alphabet` and `code` are consistent, i.e., the codes provided uniquely represent the characters in the alphabet.

**Time complexity:**
If there are n characters and each code is of average length k, the complexity of building the tree is O(n * k).

**Why this is efficient:**
- The tree is constructed in a single pass over the codes.
- Each code insertion is straightforward and does not require searching since the code path is directly given.
- The final tree can then be used for decoding operations in O(k) time per character (where k is the length of a Huffman code).

**6. Given the following strings and their corresponding hash codes, draw the resulting 13-cell hash table by inserting these strings in the given order to the hash table and using linear probing to resolve possible collisions.**

| string | hash code
| :- | :-
| brute | 10
| force | 11
| greedy | 7
| backtracking | 10
| dynamic | 7
| programming | 8
| abstract | 0
| methodology | 9

| index | string
| :- | :-
| 0 | abstract
| 1 | methodology
| 2 |
| 3 |
| 4 |
| 5 |
| 6 |
| 7 | greedy
| 8 | dynamic
| 9 | programming
| 10 | brute
| 11 | force
| 12 | backtracking

**7. Given the following pattern string p:**
`papaya paste`
(a) Draw the failure function of the above given pattern string p.

|pattern | p | a | p | a | y | a |  | p | a | s | t | e 
| :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :-
| **index** | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11
| **f array** | 0 | 0 | 1 | 2 | 0 | 0 | 0 | 1 | 2 | 0 | 0 | 0

(b) What is in general a failure function's use in the KMP string matching algorithm?
The failure function helps efficiently handle mismatches by indicating how much of the pattern can be reused. It stores the length of the longest proper prefix of the pattern that matches a suffix ending at each postion, enabling the algorithm to avoid re-checking already matched characters.

(c) Why can using a failure function improve the runtime efficiency of the string matching algorithm?
The failure function improves efficiencyt by ensuring that the pattern shifts intelligently on mismatches, avoiding redundant comparisons. This reduces the time complexity of the KMP algorithm to O(n + m) where n is the text length and m is the pattern length.

**8. If you are asked to create a new abstract data type (for example, Classroom ADT) how can you proceed to do it? What must be included in your description of the new ADT?**

An ADT requires the following four things:
1. **Definition and Properties:**
    A clear description of what the ADT represents and its key characteristics.
2. **Operations and Expected Performance:**
    A list of operations the ATD supports (e.g., add, remove, find) along with their expected functional behavior and time complexity in an abstract sense.
3. **Implementation and Actual Performance:**
    Details about how the ADT could be implemented using concrete data structures and how these affect performance.
4. **Typical Applications:**
    Examples of real-world problems or scenarios where this ADT is useful.

**9. We have two algorithms that can both solve the same problem. One has time effeciency $\Omega(N)$, and the other is in $O(N^2)$. Is there any way to judge which algorithm will give us better runtime efficiency when the problem size N is really large? Justify your answer.**

Yes, we can judge which algorithm will give better runtime efficiency when the problem size $N$ is very large. $O(N^2)$ represents quadratic growth, while $\Omega(N)$ is linear growth. As $N$ becomes very large, quadratic growth will significantly outpace linear growth, meaning the algorithm with time efficiency $\Omega(N)$ will have better runtime effeciency for large $N$. This can be easily illustrated on a graph where the quadratic curve grows much faster than the linear curve.

**10. Given the following recursive function:**
```cpp
void solve(int N)
{
    if (N <= 2)
        return;
    for(int i = 0; i < 3; i++) {
        solve(N/3);
    }
    f_combine(N);
}
```

Suppose thge function `f_combine` is non-recursive and runs in $N\log N$ time.
(a) Give a recurrence equation $T(n)$ for the runtime of the function `solve`.
`T(N) = 3T(N/3) + N*log(N)`
with a base case `T(N) = O(1)` when `N <= 2`.
(b) Solve this recurrence equation using the Master Theorem and briefly explain your reasoning process.
- `a = 3`, `b = 3` ⇒ `log_b(a) = log_3(3) = 1`
- `N^(log_b(a)) = N^1 = N`
- `f(N) = N*log(N) = N^(1)*log^(1)(N)`, which matches the second case of the Master Theorem with `k = 1`.
    Thus:
    `T(N) = Θ(N * (log(N))^2)`

**11. The external sorting algorithm introduced in the lectures is modeled after the internal merge-sort algorithm. Is it possible to design an external sorting algorithm modeled after the internal quick-sort algorithm?**
If the answer is yes, describe such an external sorting algorithm. If the answer is no, explain why such an external sorting algorithm is impossible.

Yes, it is possible. You can design an external sorting algorithm inspired by quick-sort by repeatedly performing an external "partition" step on large datasets stored on disk. However, it's typically less practical and less efficient than external merge-sort because ensuring good pivot selection and minimizing random disk accesses is challenging.