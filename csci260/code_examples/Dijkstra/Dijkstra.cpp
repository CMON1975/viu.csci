#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

// define a pair for convenience, where the first is the distance, and the second is the node
typedef pair<int, int> pii;

// function to perform Dijkstra's algorithm
vector<int> dijkstra(int source, const vector<vector<pii>>& graph) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX); // distance array, initially set to infinity (INT_MAX)
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap (priority queue)

    // initialize source
    dist[source] = 0;
    pq.push({0, source}); // push the source with distance 0

    while (!pq.empty()) {
        int u = pq.top().second; // get the node with the smallest distance
        int u_dist = pq.top().first;
        pq.pop();

        // for each neighbor v of u, check if a shorter path can be found
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.second;
            int weight = neighbor.first;

            // if a shorter path to v is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // push the updated distance to the priority queue
            }
        }
    }

    return dist;
}

int main() {
    // number of nodes and edges
    int n = 5;
    vector<vector<pii>> graph(n);

    // create an undirected weighted graph (adjacency list)
    // add edges in the form: (weight, node)
    graph[0].push_back({10, 1});
    graph[0].push_back({5, 3});
    graph[1].push_back({1, 2});
    graph[1].push_back({2, 3});
    graph[2].push_back({4, 4});
    graph[3].push_back({3, 1});
    graph[3].push_back({9, 2});
    graph[3].push_back({2, 4});
    graph[4].push_back({6, 0});
    graph[4].push_back({7, 2});

    // run Dijkstra's algorithm from the source node 0
    vector<int> distances = dijkstra(0, graph);

    // print the shortest distances to all nodes from the souce
    for (int i = 0; i < n; ++i) {
        cout << "Distance from node 0 to node " << i << " is " << distances[i] << endl;
    }

    return 0;
}