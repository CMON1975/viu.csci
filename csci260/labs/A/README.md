CHRISTOPHER NILSSEN README.md for LAB A CSCI 260 F2402
# Minimum Spanning Tree (MST) Implementation

## Overview
The program computes the Minimum Spanning Tree of a given graph using Prim's algorithm. It reads a graph represented as an adjacency matrix, processes it to find the MST, and outputs the MST as an adjacency matrix.

## Files
- **FindMST.cpp**: Contains the implementation of the Prim algorithm using adjacency matrix graph expression, and optional adjacency list graph expression.
- **FMST_test.cpp**: Contains the main program logic, a simple test function.
- **Makefile**: Builds the `FMST_test` executable.

## Usage
To compile and run the program:
```bash
make
./FMST_test
```

## Code Explanation
### Graph Representation
- The graph is represented using an adjacency matrix.
- The adjacency matrix is a 2D array (double**) where graph[i][j] represents the weight of the edge between node i and node j.
- A weight of 0.0 indicates that there is no direct edge between the nodes.
### MinimumSpanningTree Function
- Function Signature:
```cpp
double **MinimumSpanningTree(double **graph, int numOfNodes);
```
- Purpose: Computes the MST of the given graph and returns it as an adjacency matrix.
- Algorithm Used: Prim's algorithm.
- Parameters:
    - graph: The adjacency matrix of the original graph.
    - numOfNodes: The number of nodes in the graph.
- Returns: An adjacency matrix representing the MST.

### Main Function
- Initializes a sample graph with 5 nodes.
- Adds edges and their corresponding weights to the adjacency matrix.
- Calls the MinimumSpanningTree function to compute the MST.
- Outputs the MST adjacency matrix to the console.
- Cleans up dynamically allocated memory before exiting.