# Lecture 28
## Graph Algorithms, con't.
### Minimum Spanning Tree (MST)
- **Definition:** A **spanning tree** is a subset of a graph $G$ that:
    1. Connects all vertices $(V_T=V_G)$.
    2. Uses the minimum number of edges $(E_T \subseteq E_G)$.
    3. Contains no cycles.
- **Weighted Graph:** MST applies only to graphs where edges have weights.
    - The MST minimizes the total weight:
    $$
    \sum W(E_T)
    $$
    This is the smallest sum of weights among all possible spanning trees.
- **Properties of the Graph:**
    1. **Undirected:** MST is only defined for undirected graphs.
    2. **Connected:** Every vertex must be reachable from every other vertex.
    3. **Simple Graph:** No duplicate edges or self-loops (reflexive edges).

---

### Algorithm for Finding an MST
**Example of Generic Algorithm:**
1. **Initialize:**
    - Start with an empty tree $(T = 0)$.
    - Use a priority queue (min-heap) to store all edges by weight.
2. **Iterate:**
    - Repeatedly extract the smallest edge from the queue (`removeMin`).
    - Add the edge to $T$ **if it doesn't form a cycle:**
        - If one end of the edge is not already in the tree, include the edge.
        - If both endes are already in the tree, discard the edge.
3. **Stop:**
    - When the tree contains exactly $V-1$ edges (for $V$ vertices), the MST is complete.

---

### Popular MST Algorithms
**Prim's Algorithm:**
- **Approach:** Builds the MST incrementally, starting with an arbitrary vertex.
- **Steps:**
    1. Initialize a priority queue to store edges with weights.
    2. Add all edges incident to the starting vertex.
    3. Extract the minimum weight edge that connects a new vertex to the MST.
    4. Repeat until all vertices are included.
- **Time Complexity:** $O(E\log V)$ (using a binary heap).

---

**Kruskal's Algorithm:**
- **Approach:** Greedy algorithm that sorts all edges by weight and adds them to the MST if they don't form a cycle.
- **Steps:**
    1. Sort all edges by weight.
    2. Process edges in increasing order of weight.
    3. Use a **union-find (disjoint-set)** data structure to detect cycles efficiently.
- **Time Complexity:** $O(E\log E)$ or $O(E\log V)$.

---

### Applications of MST
- Network design: Minimizing cost in electrical, communication, or transportation networks.
- Approximation algorithms for NP-hard problems (e.g., TSP).
- Clustering in machine learning.

---

## All-Pairs Shortest Path (APSP)
### Definition
- **Goal:** Find the shortest path between all pairs of vertices in a graph.
- **Input:** Weighted, directed/undirected graph. Edges can have positive weights or infinity if no edge exists between two vertices.
- **Output:** A distance matrix where:
    - `A[i][j]`: The shortest distance from vertex $i$ to vertex $j$.

---

### Approaches to APSP
1. **Matrix Multiplication Method**
    - Uses **adjacency matrix** multiplication to determine shortest paths:
        - `A[i][j]`: Weight of the edge from $i$ to $j$.
        - Update the matrix iteratively to consider paths of increasing lengths.

**Algorithm Steps:**
1. Initialize a matrix `A[0]`:
    - `A[0][i][j]` = weight(i, j), where:
        - 0 if i == j.
        - +inf if no direct edge exists.
2. Iteratively update the matrix A[k] for k = 1 to n - 1:
    - For each pair of vertices i, j:
        - Compute the shortest path using intermediate vertices up to k.
        - Update the distance:
            A[k][i][j] = min(A[k - 1][i][j], A[k - 1][i][m] + weight(m, j))
        for all vertices $m$.
3. Stop when $A^k = A^{k+1}$ (closure condition).

**Complexity:**
- **Time Complexity:** $O(n^4)$ (due to nested loops and matrix size).

**Note:**
- **Closure of Connectivity:**
    - If $A^k = A^{k+1}$, further iterations will not change the matrix. This indicates all shortest paths have been computed.

---

2. **Floyd-Warshall Algorithm**
    - **Dynamic Programming** approach to APSP.
    - Iterativel considers each vertex as an intermediate point.
    - **Steps:**
        1. Initialize A[i][j] = weight(i, j).
        2. For each vertex $k$, update:
            A[i][j] = min(A[i][j], A[i][k] + A[k][j])
        3. Repeat until all vertices have been considered.
    - **Time Complexity:** $O(n^3)$.
    - **Space Complexity:** $O(n^2)$.

---

### Comparison of APSP Methods

| Method | Time Complexity | Notes
| :- | :- | :-
| **Matrix Multiplication** | $O(n^4)$ | Simple but inefficient for large graphs.
| **Floyd-Warshall** | $O(n^3)$ | Preferred for dense graphs or adjacency matrices.
| **Dijkstra for APSP** | $O(V \cdot (E+V\log V))$ | Faster for sparse graphs with non-negative weights

---

### Applications of APSP
- Route optimization in navigation systems.
- Analyzing reachability in communication networks.
- Solving games and puzzles involving shortest paths.
