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

## Prof's Notes
### Graph Algorithms
**Typical Applications of Graphs:**
- Transportation maps
- Communication networks
- Anything involving a set of objects and their connectivity.

**Graph ADT**
- A set of V vertices (nodes) representing a set of objects
- A multi-set E of edges (arcs), pairs of vertices from V, representing connections or relationships betwen pairs of objects represented by the vertices from V.

**Definition**
- Edge: <u, v>, where u,v is in V; u and v are called end vertices or end points;
- Directed edge: ordered pair <u, v> where <u, v> is not the same as <v, u>; u is called the origin and v is called the destination;
- Undirected edge: unordered pair <u, v> is the sames a <v, u>, sometimes denoted as {u, v};
- Symmetric relation: (e.g., a bi-directional road map) if A is connected to B, then B must be connected by road to A. Undirected edge can be used to represent such a relationship.
- Asymmetric relation: (e.g., report to) if A reports to B, usually B doesn't report to A. So, a directed edge is necessary to represent this kind of relationship.
- Undirected graph contains only undirected edges;
- Directed graph contains only directed edges;
- Mixed graph contains both undirected and directed edges;
- Unweighted graph: all edges have the same weight (usually just 1)
- Weighted graph: each edge has a weight, the weights of the edges may be different.
- Adjacent: two vertices, which are end points of the same edge, are adjacent.
- Outgoing edges and incoming edges;
- Degree, in-degree, out-degree;
- Parallel edges (multiple edges), self-loop;
- Simple graph: graphs with neither parallel edges nor self-loops;
- Path: a sequence of alternating vertices and edges that starts at a vertex and ends at a vertex, and each vertex is the origin of its successor edge and the destination of its predecessor edge;
- Cycle: a path starts and ends at the same vertex;
- simple path: each vertex in the path is distinct;
- simple cycle: each vertex, except the start and end one is distinct;
- Directed path, directed cycle;
- Sub graph;
- Connected graph
- Tree: connected and acyclic graph

Some theorm involving degrees of vertices and number of edges; a simple graph with n vertices has at most n(n-1) edges.

**Graph Operations**
- Graph queries
    - Number of vertices
    - Number of edges
    - Iterator of vertices
    - Iterator of edges
    - IncidentEdges(v)
    - EndVertices(e)
    - AreAdjacent(v, w)
- Graph updates
    - InsertVertex(v)
    - InsertEdge(v, w, e)
    - RemoveVertex(v)
    - RemoveEdge(e)
    - SetDirectionFrom(e, v)
    - SetDirectionTo(e, v)

**Concrete data structures to implement a graph**
- Vertex Objects
- Edge Objects
- Edge List Structure
- Adjacency List Structure:
    A representation of a directed graph with n vertices using an array of n lists of vertices. List i contains vertex j if there is an edge from vertex i to vertex j. A weighted graph may be represented with a list of vertex/weight pairs. An undirected graph may be represented by having vertex j in the list for vertex i and vertex i in the list for vertex j.
- Adjacency Matrix Structure
    A representation of a directed graph with n vertices using a matrix where the entry at (i, j) is 1 if there is an edge between vertices i and j; otherwise the entry is 0. A weighted graph may be represented using the weight as the entry. An undirected graph may be represented using the same entry in both (i, j) and (j, i) or using an upper triangular matrix.

**Graph Traversal**
- Depth-first search -- Backtracking Algorithm:
    ```
    Algorithm DFS(graph G, start_node v)
        for each edge e in G.incidentEdges(v) do
            If e is not marked then
                w = G.opposite(v, e);
                If w is not marked then
                    Mark w;
                    Mark e as discovery edge;
                    DFS(G, w);
                Else
                    mark e as back edge;
    ```
- Breadth-first search -- Traverse graph by layers (as in tree traverse)
    ```
    Algorithm BFS(graph G, start_node v)
        Create an empty queue Q;
        Mark v;
        Q.enqueue(v);
        While not Q.isEmpty()
            w = Q.dequeue();
            For each edge e in G.incidentEdges(w) do
                If e is not marked then
                    u = G.opposite(w, e);
                    If u is not marked then
                        Mark u;
                        Mark e as discovery edge;
                        Q.enqueue(u);
                    Else mark e as back edge;
    ```
- Typical applications of Graph Traversal
    - Testing connectivity
    - Detecting cycles in G
    - Finding a path between a pair of vertices
    - Crawling the web
    - Systematically examining each vertex and edge in G, etc.

**Other typical graph algorithms**
- Toplogical Sort
    - Definition: Consider a directed acyclic graph G = <V,E>, a toplogical sort of the vertices of G is a sequence $S = \{v_1, v_2, ..., v_n\}$ in which each element of $v_i$ in V appears exactly once. For a pair of distinct vertices $v_i$ and $v_j$ in the sequence S, if $<v_i, v_j>$ is an edge in G, then $i<j$ in S.
    - Algorithm to create such a topological sort:
        ```
        Algorithm TopologicalSort(Graph G)
            Create an empty sequence S;
            repeat until G is empty
                select a vertex whose in-degree is zero;
                append this vertex to S;
                remove this vertex and all the edges emanating from it from G;
        ```
- Single source shortest path
    - Un-weighted undirected simple graph -- BFS
    - Weighted simple graph -- Dijkstra's Algorithm (works for all graphs with all positive weights)
        ```
        // each node will have a label
        // (flag: visited_flag, d:distance_to_source, p:previous_node)
        // weight(x, y) = +inf int there isn't an edge from x to y
        Algorithm Dijkstra(Graph G, start_node v1, destination_node v2)
            set all nodes' labels as (false, +inf, -);
            set current node w as the start_node v1;
            set current node's label as (false, 0, -);
            while current node w is not the destination node v2
                set w.flag to true;
                for each unvisited node x (x's flag is false)
                    if (w.d + weight(w,x) < x.d)
                        set x's label as (false, w.d + weight(w, x), w);
                find a node y that is unvisited and has the smallest y.d;
                set current node w to be node y;
        ```
    - Weighted directed acyclic graph -- DAG algorithm using topological sort
        ```
        Algorithm DAG(Graph G, start_node v_s)
            compute a topological sort sequence S for G;
            // S = {v1, v2, ..., vn}
            D[v_s] = 0;
            for eadch node v different from v_s
                D[v] = +inf;
            for i = 1 to n - 1 do
                for each edge <v_1, u> in G
                    if (D[v_i] + weight(v_i, u) < D[u])
                        set D[u] = D[v_i] + weight(v_i, u);
        ```
- All-pairs shortest paths
    - A dynamic programming algorithm by S.Warshall, R.W. Floyd, and P.Z. Ingerman -- works as long as there are no negative weight cycles
        ```
        // G has n nodes
        // weight(i, j) stores the weight of the edge from node i to node j
        // weight(i, j) is +inf if there is no edge from node i to node j
        // weight(i, i) is 0
        Algorithm allPairs(Graph G)
            for i = 0 to n - 1
                for j = 0 to n - 1
                    if weight(i, j) != +inf
                        D[i][j] = weight(i, j);
                        next[i][j] = j;
                    else
                        D[i][j] = +inf;
                        next[i][j] = null;
                for k = 0 to n - 1
                    for i = 0 to n - 1
                        for j = 0 to n - 1
                            if (D[i][j] > D[i][k] + D[k][j])
                                D[i][j] = D[i][k] + D[k][j]
                                next[i][j] = next[i][k];
        ```
    - Matrix Multiplication
        ```
        // G has n nodes
        // weight(i, j) stores the weight of the edge from node i to node j
        // weight(i, j) is +inf if there is no edge from node i to node j
        // weight(i, i) is 0
        Algorithm allPairs(Graph G)
            for i = 0 to n - 1
                for j = 0 to n - 1
                    A[0, i, j] = weight(i, j);
            for k = 1 to n - 1
                for i = 0 to n - 1
                    for j = 0 to n - 1
                        A[k, i, j] = A[k - 1, i, j]
                        for m = 0 to n - 1
                            if A[k, i, j] > A[k - 1, i, m] + weight(m, j) 
                                A[k, i, j] > A[k - 1, i, m] + weight(m, j)
        ```
- Minimum Spanning trees
    - The spanning tree of a connected graph is a tree that contains every vertex of the graph, and the edge set of the tree is the subset of the edge set of the graph
    - The minimum spanning tree is a spanning tree with the smallest total weight of the edges.
    - If the graph is an unweighted graph, then the minimum spanning tree is the tree with only the discovery edges while traversing the graph.
    - Calculate the minimum spanning tree of a weighted graph -- Kruskal algorithm
        ```
        // Graph G has n vertices
        Algorithm MinimumSpanningTree(Graph G)
            create an empty tree T;
            for each vertex v in G
                define an elementary cluster C(v) = {v};
                create an empty priority Q;
                for each edge e in G, using e's weight as key
                    Q.insert(e's weight, e);
                while T has fewer than n - 1 edges
                    <u, v> = Q.removeMin();
                    if u and v are not in the same cluster then
                        add the edge <u, v> to T;
                        merge u's and v's cluster to one;
                return tree T;
        ```
    - Calculate the minimum spanning tree of a weighted graph -- Prim-Jarnik algorithm
        ```
        // Graph G has n vertices
        Algorithm MinimumSpanningTree(Graph G)
            pick any vertex v of G;
            D[v] = 0;
            for each vertex u <> v
                D[u] = +inf;
            initialize an empty tree T;
            using D[u] as priority to create a priority queue Q
                that includes an entry of (D[u], (u, null)) for each vertex u in G;
            while not Q.isEmpty()
                (u, e) = Q.removeMin(); // e can be null
                add vertex u and edge e to T;
                for each vertex z adjacent to u and z is not in T
                    if weight(u, z) < D[z] then
                        D[z] = weight(u, z);
                        change the entry of z in Q to (D[z], (z, (u, z)));
            return tree T;
        ```
