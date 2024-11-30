// CHRISTOPHER NILSSEN - FMST_test.cpp for LAB A CSCI 260 F2402
// Simple test function.

#include <iostream>
#include "FindMST.cpp"

using std::cout;
using std::endl;

int main() {
    int numOfNodes = 5;

    // allocate memory for the adjacency matrix
    double **graph = new double*[numOfNodes];
    for (int i = 0; i < numOfNodes; ++i) {
        graph[i] = new double[numOfNodes];
        for (int j = 0; j < numOfNodes; ++j) {
            graph[i][j] = 0.0; // initialize all weights to 0.0
        }
    }

    // add edges to the graph
    graph[0][1] = 2.0;
    graph[1][0] = 2.0;

    graph[0][3] = 6.0;
    graph[3][0] = 6.0;

    graph[1][2] = 3.0;
    graph[2][1] = 3.0;

    graph[1][3] = 8.0;
    graph[3][1] = 8.0;

    graph[1][4] = 5.0;
    graph[4][1] = 5.0;

    graph[2][4] = 7.0;
    graph[4][2] = 7.0;

    graph[3][4] = 9.0;
    graph[4][3] = 9.0;

    // call the MinimumSpanningTree function
    double **mst = MinimumSpanningTree(graph, numOfNodes);

    // display the MST adjacency matrix
    cout << "Minimum Spanning Tree adjacency matrix:" << endl;
    for (int i = 0; i < numOfNodes; ++i) {
        for (int j = 0; j < numOfNodes; ++j) {
            cout << mst[i][j] << " ";
        }
        cout << endl;
    }

    // clean up memory
    for (int i = 0; i < numOfNodes; ++i) {
        delete[] graph[i];
        delete[] mst[i];
    }
    delete[] graph;
    delete[] mst;

    return 0;
}
