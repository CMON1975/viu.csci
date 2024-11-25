# Lecture 26
## Graphs
Graphs are abstract data structures consisting of **vertices (nodes)** and **edges (connections)**. They can be directed or undirected and weighted or unweighted.

### Typical Operations (Viewing)
1. **Get All Vertices**
    - `getAllVertices()`
        - Returns a collection of all vertices in the graph.
        - Example usage: Counting vertices, iterating over them.
2. **Get All Edges**
    - `getAllEdges()`
        - Returns a collection of all edges in the graph.
        - Example usage: Calculating edge density in the graph.
3. **Incident Edges**
    - `incidentEdges(Vertex V)`
        - Returns all edges connected to vertex `V`. In directed graphs, it may distinguish between incoming and outgoing edges.
        - Example usage: Finding neighbors or determining the degree of `V`.
4. **Ends of an Edge**
    - `endsOfEdge(Edge E)`
        - Returns the vertices connected by edge `E`.
        - In directed graphs, it identifies the source and destination of the edge.
5. **Adjacency Check**
    - `isAdjacent(Vertex V1, Vertex V2)`
        - Returns `true` if at least one edge directly connects `V1` and `V2`.
        - Example usage: Testing for direct connections in the graph.
6. **Connectivity Check**
    - `isConnected(Vertex V1, Vertex V2)`
        - Returns `true` if there is a path (one or more edges) connecting `V1` to `V2`.
        - Example usage: Determining reachability or checking if the graph is fully connected.

### Editing Operations
1. **Add a Vertex**
    - `addVertex(Vertex V)`
        - Adds a new vertex `V` to the graph.
        - Example usage: Extending the graph with new nodes.
2. **Add an Edge**
    - `addEdge(Vertex V1, Vertex V2)`
        - Adds an edge between vertices `V1` and `V2`. May specify weight or direction for weighted/directed graphs.
        - Example usage: Creating a connection between two nodes.
3. **Remove a Vertex**
    - `removeVertex(Vertex V)`
        - Removes vertex `V` from the graph and all edges incident to it.
        - Example usage: Simplifying the graph by eliminating nodes.
4. **Remove an Edge**
    - `removeEdge(Edge E)`
        - Removes edge `E` from the graph.
        - Example usage: Breaking a connection or simplifying the graph.

### Concrete Data Structures
**Adjacency Matrix**
- **Definition:** A 2D array where `matrix[i][j]` indicates the presence (and optionally weight) of an edge between vertex `i` and vertex `j`.
    - **Advantages:**
        - Fast adjacency checks: $O(1)$.
        - Simple representation for dense graphs.
    - **Disadvantages:**
        - Space complexity is $O(V^2)$, inefficient for sparse graphs.
    - **Implementation Tip:**
        - For undirected graphs, ensure `matrix[i][j] == matrix [j][i]`.

**Adjacency List**
- **Definition:** A collection of lists (or hash maps) where each vertex has a list of its adjacent vertices.
    - **Advantages:**
        - Space-efficient for sparse graphs: $O(V + E)$.
        - Easier traversal of neighbors.
    - **Disadvantages:**
        - Slower adjacency checks: $O(d)$, where $d$ is the degree of the vertex.
    - **Implementation Tip:**
        - Use lists for simplicity or hash maps for faster lookups.

### Additional Notes
- For directed graphs, incident edges may need to differentiate between **incoming** and **outgoing** edges.
- Weighted graphs store additional information (e.g., edge weights) in adjacency matrices or lists.
- Consider graph traversal algorithms (e.g., BFS, DFS) for operations like `isConnected`.

## Data Structure and Graph Implementation
### Core Graph Elements
1. **Vertex and Edge Objects**
    - **Application Dependent:** Vertex and edge representations often depend on the problem domain. They can be class-based, containing application-specific data (e.g., labels, attributes).
    - **Example:**
        ```cpp
        class Vertex {
            int id;
            string label;
            // other attributes
        };
        class Edge {
            Vertex source, destination;
            int weight; // optional for weighted graphs
        };
        ```
2. **Sets of Vertices and Edges**
    - These are **application-independent** abstractions, implemented using standard collections.
    - Examples:
        - **Vertex Set:** Implemented using arrays, vectors, or hash maps for efficient lookups and storage.
        - **Edge Set:** Use hash maps (or dictionaries) for efficient access, e.g., `Dictionary<<source, destination>, EdgeData>`.
    - **Scalability:** Choose the data structure based on the requirements:
        - **Small Graphs:** Arrays or vectors for simplicity.
        - **Large Graphs:** Hash maps or linked lists for better scalability.
3. **Vertex Implementation's Effect on Edges 
    - If vertices are identified by implicit indices (e.g., array indices), edge structures reference these indices directly.
    - Example:
        - Vertex dictionary: `Dictionary<id, Vertex>`.
        - Array of vertices: The index acts as an implicit vertex ID>

---

### Edge Representation 
1. **Edge Storage with Maps**
    - Use a dictionary or hash map for edges:
    `Dictionary<<source, destination>, info>`
        - `Info` can include attributes like weight or other metadata.
    - Example for weighted graphs:
        ```cpp
        unordered_map<pair<int, int>, int> edgeWeights;
        edgeWeights[{1, 2}] = 5; // Edge from vertex 1 to vertext 2 with weight 5
        ```
2. **Adjacency List**
    - Represents graph connections as an array of lists:
        - Each array element corresponds to a vertex.
        - Each list contains IDs of connected vertices.
    - Example for an undirected graph:
        ```cpp
        vector<vector<int>> adjList;
        adjList[0].push_back(1);    // add edge 0-1
        adjList[1].push_back(0);    // add edge 1-0
        ```
3. **Adjacency Matrix**
    - A 2D array where:
        - **X-Axis:** Destination vertices.
        - **Y-Axis:** Source vertices.
        - Value is `1` if a connection exists, otherwise `0`. For weighted graphs, store the weight instead of a binary value.
    - Example:
        ```cpp
        vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
        adjMatrix[0][1] = 1;    // edge from vertex 0 to vertex 1
4. **Avoiding Cyclic Dependencies**
    - Design carefully to prevent classes (e.g., `Vertex` and `Edge`) from circular references.
    - Strategies:
        - Use unique IDs instead of direct object references.
        - Keep edges and vertices decoupled; resolve relations through a graph manager class.
5. **Directed vs. Undirected Graphs**
    - Ensure implementation handles the type consistently:
        - **Undirected Graphs:** Each edge must be represented bidirectionally (e.g., in both adjacency list entries or as symmetric matrix entries).
        - **Directed Graphs:** Only represent edges in the specified direction.
6. **Weighted Graphs**
    - Store weights in the edge representation (e.g., adjacency list or matrix).
    Example:
        - Adjacency list: `Dictionary<Vertex, List<(Vertex, Weight)>>`.
        - Adjacency matrix: Store weights directly in the matrix cells.

---

### Adding and Removing Elements
1. **Adding/Removing Edges**
    - **Adjacency List:**
        - Adding: Append the destination vertex to the source vertex's list.
        - Removing: Locate and remove the destination vertex from the list.
        - Example:
            ```cpp
            adjList[source].push_back(destination); // add
            adjList[source].remove(destination);    // remove
            ```
    - **Adjacency Matrix:**
        - Adding: Update the corresponding cell to `1` (or the weight for weighted graphs).
        - Removing: Set the corresponding cell to `0`.
        - Example:
            ```cpp
            adjMatrix[source][destination] = 1; // add
            adjMatrix[source][destination] = 0; // remove
            ```
2. **Adding/Removing Vertices**
    - **Adjacency List:**
        - Flexible for dynamic graphs since you can grow or shrink lists independently.
    - **Adjacency Matrix:**
        - Less flexible; requires resizing the matrix when adding/removing vertices:
            - Add a new row and column for the new vertex.
            - Remove the row and column associated with the removed vertex.
        - Example for resizing:
            ```cpp
            adjMatrix.resize(newSize, vector<int>(newSize, 0));
            ```

---

### Summary of Key Trade-Offs

| Feature | Adjacency List | Adjacency Matrix
| :- | :- | :-
| **Space Efficiency** | $O(V+E)$, best for sparse | $O(V^2)$, good for dense
| **Adjacency Check** | $O(d)$ (d = degrees) | $O(1)$
| **Ease of Updates** | Flexible, dynamic | Static, resizing required
| **Weighted Graphs** | Supports with additional data | Directory store in matrix

---


    


