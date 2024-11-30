// CHRISTOPHER NILSSEN - FindMST.cpp for LAB A CSCI 260 F2402
// Using Prim's algorithm and adjacency matrix implementation (adjacency list implementation shown in commented-out snippets)

#include <limits>
// #include <vector>    // adjacency list implementation (AL imp)

using std::numeric_limits;
// #using std::vector;  // AL imp

/* AL imp
struct Edge {
    int dest;
    double weight;    
}
*/

// douyble **MinimumSpanningTree(vector<Edge>* graph, int numOfNodes)   // AL imp
double **MinimumSpanningTree(double **graph, int numOfNodes) {
    // arrays to store the MST
    bool *inMST = new bool[numOfNodes];
    double *key = new double[numOfNodes];
    int *parent = new int[numOfNodes];

    // init all keys as +inf and inMST[] as false
    for (int i = 0; i < numOfNodes; ++i) {
        key[i] = numeric_limits<double>::infinity();
        inMST[i] = false;
    }

    // first node = MST root
    key[0] = 0.0;
    parent[0] = -1;

    // MST has numOfNodes verts
    for (int count = 0; count < numOfNodes - 1; ++count) {
        // find min key vert not yet in MST
        double min = numeric_limits<double>::infinity();
        int u = -1;

        for (int v = 0; v < numOfNodes; ++v) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        // update key and parent for adjacent verts of the selected vert
        for (int v = 0; v < numOfNodes; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent [v] = u;
                key[v] = graph[u][v];
            }
        }

        /* AL imp
        for (const Edge &edge : graph [u]) {
            int v = edge.dest;
            double weight = edge.weight;
            if (!inMST[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
        */
    }

    // construct MST adj matrix
    double **mst = new double*[numOfNodes];
    for (int i = 0; i < numOfNodes; ++i) {
        mst[i] = new double[numOfNodes];
        for (int j = 0; j < numOfNodes; ++j) {
            mst[i][j] = 0.0;
        }
    }

    // fill MST adj matrix with parent array
    for (int i = 1; i < numOfNodes; ++i) {
        int u = parent[i];
        int v = i;
        double weight = graph[u][v];
        mst[u][v] = weight;
        mst[v][u] = weight; // mirror for undirected graph
    }

    // clean up
    delete[] inMST;
    delete[] key;
    delete[] parent;

    return mst;
}