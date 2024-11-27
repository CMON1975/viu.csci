# Lecture 29
## Minimum Spanning Tree (MST) Algorithms (Continued)
### Kruskal's Algorithm
- **Overview:**
    - A **greedy algorithm** that selects edges in order of weight.
    - Does **not maintain a single connected tree** throughout the process; instead, it gradually connects disjoint sets (or components) of the graph.
- **Steps:**
    1. Sort all edges by weight.
    2. Use a **union-find (disjoint-set)** data structure to efficiently check if adding an edge will form a cycle.
    3. Add the edge to the MST if it connects two previously disconnected components.
    4. Stop when the MST contains $V - 1$ edges.
- **Properties:**
    - Efficient for sparse graphs.
    - Time complexity: $O(E\log E)$, primarily due to sorting the edges.

---

### Prim-Jarnik Algorithm
- **Overview:**
    - A **greedy algorithm** that builds the MST incrementally by always adding the smallest edge that connects a vertex in the tree to a vertex outside it.
- **Steps:**
    1. Start with any vertex and include in the MST.
    2. Maintain a priority queue to track the smallest weight edges that can extend the MST.
    3. Extract the smallest edge, add it to the MST, and update the queue with new edges from the added vertex.
    4. Repeat until all vertices  are in the MST.
- **Properties:**
    - Suitable for dense graphs.
    - Time complexity:
        - $O(E\log V)$ using a binary heap.
        - $O(V^2)$ with a simple adjacency matrix representation.

---

## All-Pairs Shortest Path (APSP)
### Overview
- **Goal:** Find the shortest paths between every pair of vertices in a graph.
- **Techniques:**
    1. **Dynamic Programming:** Floyd-Warshall algorithm.
    2. **Brute Force:** Matrix-based iterative method (inefficient).

---

### Floyd-Warshall Algorithm (Dynamic Programming)
- **Input:**
    - A weighted graph with $n$ vertices.
    - D[i][j]: The weight of the edge between vertices $i$ and $j$, or +inf if no edge exists.
    - D[i][i] = 0 (distance from a vertex to itself).
- **Steps:**
    1. Initialize $D$ with the graph's weights.
    2. Iteratively refine D[i][j] using each vertex $k$ as an intermediate point:
    D[i][j] = min(D[i][j], D[i][k] + D[k][j])
    3. Track the **next vertex** for reconstructing the path.
- **Complexity:**
    - Time: $O(n^3)$ (three nested loops)
    - Space: $O(n^2)$

---

### Brute Force (Naive Matrix Multiplication)
- **Idea:**
    - Use repeated iterations of matrix multiplication to update the shortest paths for paths of increasing lengths.
- **Steps:**
    1. Initialize D[i][j] based on direct weights.
    2. For each pair $i$, $j$, check all possible intermediate vertices $m$ and update:
    D[i][j] = min(D[i][j], D[i][m] + weight(m, j))
- **Complexity:**
    - Time: $O(n^4)$, much slower than Floyd-Warshall.

---

## Programming Methodology
### Overview of Approaches
1. **Brute Force:**
    - **Definition:** Systematically explore every possible solution to find the best one.
    - **Advantages:** Simple and exhaustive.
    - **Disadvantages:** Inefficient for large problems.
2. **Greedy Algorithm:**
    - **Definition:** Makes the best immediate choice at each step, assuming it leads to a global optimum.
    - **Examples:**
        - Kruskal's and Prim's algorithms for MST.
        - Huffman coding for optimal prefix codes.
    - **Limitations:** Does not guarantee optimal solutions for all problems (e.g., TSP).
3. **Backtracking:**
    - **Definition:** Explores paths to a solution and backtracks when a path fails.
    - **Examples:**
        - Solving mazes.
        - N-Queens problem.
    - **Key Feature:** Allows exploration of all possibilities while pruning infeasible solutions.
4. **Divide and Conquer (Top-Down):**
    - **Definition:** Breaks a problem into smaller, independent subproblems, solves them recursively, and combines the solutions.
    - **Examples:**
        - Quicksort.
        - Mergesort.
    - **Advantages:** Efficient for problems that can be decomposed into independent subproblems.
5. **Dynamic Programming (Bottom-Up):**
    - **Definition:** Solves overlapping subproblems incrementally, storing intermediate results to avoid redundant computation.
    - **Examples:**
        - Fibonacci sequence.
        - Floyd-Warshall for APSP.
        - Knapsack problem.
6. **Randomized Algorithms:**
    - **Definition:** Uses random choices to explore solutions.
    - **When to Use:**
        - Problemns with no clear heuristic or structure.
        - Generating approximate solutions quickly for optimization problems.
    - **Examples:**
        - Monte Carlo simulations.
        - Randomized quicksort.

---

## Examples of Methodology in Action
**Dynamic Programming Example: Fibonacci Numbers**
```cpp
int Fibo(int n) {
    int result[n + 1];
    result[0] = result[1] = 1;

    for (int i = 2; i <= n; ++i) {
        result[i] = result[i - 1] + result[i - 2];
    }

    return result[n];
}
```
- **Complexity:**
    - Time: $O(n)$.
    - Space: $O(n)$ (or $O(1)$ with space optimization).

---

## Comparison of Approaches
| Approach | Strengths | Weaknesses | Example Problems
| :- | :- | :- | :-
| Brute Force | Simple, guaranteed solution | Exponential time complexity | TSP, N-Queens
| Greedy Algorithm | Fast, simple for some problems | Not always globally optimal | MST, Huffman coding
| Backtracking | Explores all possibilities | Inefficient for large solution spaces | Sudoku, N-Queens
| Divide-and-Conquer | Efficient for independent subproblems | High memory usage | APSP, Knapsack problem
| Randomized | Quick approximations | No guarantees of correctness | Monte Carlo, quicksort

---

## Prof's Notes
### Programming Methodologies
A problem can be viewed as a sequence of decisions to be made.

A **Brute Force** algorithm solves a problem by exhaustively ennumerating all the possibilities.
Example: brute force string matching.

A **Greedy** algorithm always makes the (seemingly) best choice in each decision. Once a decision has been made, that decision is never reconsidered.
Example: hill climbing; Huffman encoding; Dijkstra's shortest path.

A **Backtracking** algorithms systematically considers all possible outcomes for each decision, just like the brute force algorithms. But backtracking algorithms can deted when an exhaustive search is unnecessary. Therefore, backtracking algorithms can perform much better than brute force ones when solving the same problem.
Example: eight queen; depth first traversal.

A **Divide and Conquer** algorithm divides a problem into several (usually smaller) sub-problems, solves each sub-problem independently, then combines the solutiuons to obtain the solution to the original problem. Divide and conquer algorithms are often implemented using recursion. And generally, the sub-problems are non-overlapping.
Example: quick sort; merge sort.

A **Dynamic Programming** algorithm solves a series of sub-problems to solve the original problem. The series of sub-rpobleems is devised carefully in such a way that each subsequent solution is obtained by combining the solutions to one or more of the sub-problems that have already been solved. All intermediate solutions are kept in a table in order to prevent unnecessary duplication of efforts.
Example: matrix chain product, all pairs shortest path (Floyd-Warshall).

A **Randomized** algorithm has an element of randomness involved in solving a problem.
Example: skip list.