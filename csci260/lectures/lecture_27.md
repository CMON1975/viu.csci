# Lecture 27
## Graph Algorithms 
### Traversal Basics
- **Purpose:** Systematically visit all elements (vertices and edges) in a graph.
- **Key Idea:** Traversing vertices naturally involves traversing incident edges.
- **Terminology:** Graph traversal is often referred to as "search".

### Types of Traversals
1. **Breadth-First Search (BFS)**
    - **Mechanism:** Explores vertices in layers, starting from the source vertex and visiting all its immediate neighbors before proceeding to their neighbors.
    - **Data Structure Used:** Queue
    - **Steps:**
        1. Enqueue the starting vertex and mark it as "in queue".
        2. Dequeue a vertex, visit it, and mark it as "visited".
        3. Enqueue all adjacent vertices that are "unvisited".
        4. Repeate until the queue is empty.
    - **Applications:**
        - Finding the shortes path in unweighted graphs.
        - Testing for graph connectivity.
2. **Depth-First Search (DFS)**
    - **Mechanism:** Explores as far along a branch as possible before backtracking.
    - **Data Structure Used:** Stack (or recursion, which uses the call stack implicitly)
    - **Steps:**
        1. Push the starting vertex onto the stack and mark it as "visited".
        2. Pop a vertex, visit it, and push all its unvisited adjacent vertices.
        3. Continue until the stack is empty.
    - **Applications:**
        - Detecting cycles.
        - Checking reachability.
        - Solving mazes or puzzles with a single solution path.

---

### Applications of Graph Traversal
1. **Connectivity Checks:**
    - **isConnected(Graph G):** Use BFS or DFS to determine if all vertices in the graph are reachable from any starting vertex.
    - **isConnected(Vertex V1, Vertex V2):** Test if a path exists between two specific vertices.
2. **Reachability:**
    - **isReachable(Vertex V1, Vertex V2):** Common in directed graphs. DFS is often preferred for this task.
3. **Cycle Detection:**
    - **isCyclic(Graph G):** A graph is cyclic if there exists a path such that traversal revisits a previously visited vertex.
        - **DFS:** Mark edges as "discovered" and detect cycles by checking back edges.
4. **Directed Acyclic Graphs (DAGs):**
    - A DAG has no cycles and can often represent heirarchical structures like trees.
5. **Web Crawling:**
    - Represents the web as a graph (pages as vertices, hyperlinks as edges).
    - Use BFS for breadth-based exploration or DFS for depth-based crawling strategies.
    - **Example Problem:** "Seven degrees of separation" email chain analysis.

---

### Toplogical Sort
- **Definition:** A topological sort of a directed acyclic graph (DAG) is a linear ordering of vertices such that for every directed edge ($u, v$), vertex $u$ comes before vertex $v$ in the ordering.
- **Algorithm:**
    1. Create an empty sequence $S$.
    2. Repeat until all vertices are removed from the graph:
        - Find a vertex with no incoming edges.
        - Append it to $S$.
        - Remove the vertex and all its outgoing edges.
- **Applications:**
    - Scheduling tasks with prerequisites.
    - Dependency resolution in software projects.
- **How many Topological Orders are Possible?**
    - **Answer:** For a DAG, the number of valid topological sorts depends on the structure and can be computed using combinatorial methods, though this is rarely practical for large graphs.

---

### Shortes Path Algorithms
1. **Single Source Shortest Path (Unweighted Graphs)**
    - **Goal**: Find the shortest path between a source vertex $V_S$ and a destination vertex $V_D$ in an unweighted graph.
    - **Algorithm:**
        - Use BFS:
            - Track the source node during traversal.
            - Update path length incrementally as you move to each layer.
        - Ties are inconsequential since all edge weights are equal.

---

2. **Dijkstra's Algorithm (Weighted Graphs)**
    - **Goal:** Find the shortest path from a source vertex $V_S$ to all other vertices in a graph with positive edge weights.
    - **Approach:** Greedy algorithm.
    - **Steps:**
        1. Maintain three components for each node:
            - `visited`: Indicates if the node is finalized.
            - `distance`: Shortest known distance from the source (initialized to +inf).
            - `previous`: Previous vertex in the shortest path.
        2. Initialize the source vertex's distance to 0.
        3. Use a priority queue (min-heap) to always process the vertex with the smallest distance.
        4. For each neighbor of the current vertex:
            - Update its distance if a shorter path is found.
        5. Mark the vertex as visited once processed.
    - **Handling Negative Weights:**
        - Adjust the algorithm by adding the smallest negative weight +1 to all weights, making them positive.
        - Alternatively, use **Bellman-Ford** for graphs with negative weights.
    - **Complexity:**
        - **Best: $O(V + E\log V)$** using a priority queue.
        - **Worst: $O(V^2)$** with a simple implementation.

---

### Summary of Algorithms by Use Case
| Problem | Recommended Algorithm | Complexity
| :- | :- | :-
| Traversal (Unweighted Graph) | BFS or DFS | $O(V+E)$
| Traversal (Weighted Graph) | DFS or Dijkstra | $O(V^2)$ or $O(V+E\log V)$
| Cycle Detection | DFS | $O(V+E)$
| Shortest Path (Unweighted) | BFS | $O(V+E)$
| Shortest Path (Weighted) | Dijkstra | $O(V^2)$ or $O(V+E\log V)$
| Toplogical Sort | Kahn's Algorithm (BFS) | $O(V+E)$