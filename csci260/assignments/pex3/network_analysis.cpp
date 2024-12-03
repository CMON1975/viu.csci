#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using std::ifstream;
using std::ofstream;
using std::string;
using std::cerr;
using std::endl;

const int MAX_SERVERS = 100; // maximum number of servers
double costMatrix[MAX_SERVERS][MAX_SERVERS]; // adjacency matrix for costs
int capacityMatrix[MAX_SERVERS][MAX_SERVERS]; // adjacency matrix for capacities
bool visited[MAX_SERVERS]; // visited array for dfs
int totalVolume[MAX_SERVERS][MAX_SERVERS] = {0}; // accumulated required volume of demands

// function to find server index
int findServerIndex(string servers[], int serverCount, const string &name) {
    for (int i = 0; i < serverCount; ++i) {
        if (servers[i] == name) {
            return i;
        }
    }
    return -1;
}

// dijkstra's algorithm to find the lowest cost path
bool dijkstra(int source, int destination, int serverCount, int path[], int &pathLength) {
    double dist[MAX_SERVERS];
    int prev[MAX_SERVERS];
    bool visited[MAX_SERVERS] = {false};

    for (int i = 0; i < serverCount; ++i) {
        dist[i] = 1e9; // set to a very large value
        prev[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < serverCount - 1; ++count) {
        int u = -1;

        // find the unvisited node with the smallest distance
        for (int i = 0; i < serverCount; ++i) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        if (dist[u] == 1e9) break; // remaining nodes are not reachable
        visited[u] = true;

        // update distances for neighbors
        for (int v = 0; v < serverCount; ++v) {
            if (!visited[v] && costMatrix[u][v] > 0) {
                double newDist = dist[u] + costMatrix[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    prev[v] = u;
                }
            }
        }
    }

    // reconstruct the path
    if (dist[destination] == 1e9) return false; // destination not reachable

    pathLength = 0;
    for (int v = destination; v != -1; v = prev[v]) {
        path[pathLength++] = v;
    }
    // reverse path to get source -> destination
    for (int i = 0; i < pathLength / 2; ++i) {
        int temp = path[i];
        path[i] = path[pathLength - i - 1];
        path[pathLength - i - 1] = temp;
    }

    return true;
}

// function to analyze and write results
void analyzeInfrastructure(const string &filename) {
    ifstream inputFile(filename.c_str());
    if (!inputFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    ofstream outputFile("techAnalysisResult.txt");
    if (!outputFile) {
        cerr << "Error: Unable to create output file" << endl;
        return;
    }

    // initialize matrices
    for (int i = 0; i < MAX_SERVERS; ++i) {
        for (int j = 0; j < MAX_SERVERS; ++j) {
            costMatrix[i][j] = 0;
            capacityMatrix[i][j] = 0;
        }
    }

    // read server data
    int serverCount;
    inputFile >> serverCount;
    string servers[MAX_SERVERS];
    for (int i = 0; i < serverCount; ++i) {
        inputFile >> servers[i];
    }

    // read link data
    int linkCount;
    inputFile >> linkCount;
    for (int i = 0; i < linkCount; ++i) {
        string server1, server2;
        double cost;
        int capacity;
        inputFile >> server1 >> server2 >> cost >> capacity;

        int index1 = findServerIndex(servers, serverCount, server1);
        int index2 = findServerIndex(servers, serverCount, server2);
        costMatrix[index1][index2] = cost;
        costMatrix[index2][index1] = cost;
        capacityMatrix[index1][index2] = capacity;
        capacityMatrix[index2][index1] = capacity;
    }

    // debug: print matrices
    std::cout << "Cost Matrix:" << endl;
    for (int i = 0; i < serverCount; ++i) {
        for (int j = 0; j < serverCount; ++j) {
            std::cout << std::setw(10) << costMatrix[i][j] << " ";
        }
        std::cout << endl;
    }

    std::cout << "Capacity Matrix:" << endl;
    for (int i = 0; i < serverCount; ++i) {
        for (int j = 0; j < serverCount; ++j) {
            std::cout << std::setw(10) << capacityMatrix[i][j] << " ";
        }
        std::cout << endl;
    }

    // read demand data
    int demandCount;
    inputFile >> demandCount;
    string demands[demandCount][3]; // stores demands as {server1, server2, volume}
    for (int i = 0; i < demandCount; ++i) {
        inputFile >> demands[i][0] >> demands[i][1] >> demands[i][2];
    }

    inputFile.close();

    outputFile << "Technology Analysis based on data in file " << filename << endl << endl;
    outputFile << "The following communication demand(s) can't be met" << endl;
    outputFile << "by current infrastructure due to lack of routes" << endl;
    outputFile << "between the two servers:" << endl;

    bool canMeetAll = true;
    int additionalCapacity[MAX_SERVERS][MAX_SERVERS] = {0};
    int path[MAX_SERVERS], pathLength;

    // Loop to process all demands
    for (int i = 0; i < demandCount; ++i) {
        string server1 = demands[i][0];
        string server2 = demands[i][1];
        int volume = atoi(demands[i][2].c_str());

        int index1 = findServerIndex(servers, serverCount, server1);
        int index2 = findServerIndex(servers, serverCount, server2);

        if (dijkstra(index1, index2, serverCount, path, pathLength)) {
            for (int j = 0; j < pathLength - 1; ++j) {
                int from = path[j];
                int to = path[j + 1];

                // Accumulate the volume for each link in the path
                totalVolume[from][to] += volume;
                totalVolume[to][from] += volume;
            }
        } else {
            outputFile << server1 << " " << server2 << " " << volume << endl;
            canMeetAll = false;
        }
    }

    // Compute additional capacities after processing all demands
    for (int i = 0; i < serverCount; ++i) {
        for (int j = 0; j < serverCount; ++j) {
            if (totalVolume[i][j] > capacityMatrix[i][j]) {
                additionalCapacity[i][j] = totalVolume[i][j] - capacityMatrix[i][j];
            }
        }
    }

    // Generate the final report
    outputFile << endl;
    outputFile << "In order to meet the rest of the communication demands" << endl;
    outputFile << "with the lowest cost, the following direct link(s)" << endl;
    outputFile << "must expand their capacity:" << endl;

    bool capacityExpansionNeeded = false;
    for (int i = 0; i < serverCount; ++i) {
        for (int j = i + 1; j < serverCount; ++j) { // ensure no duplicates
            if (additionalCapacity[i][j] > 0) {
                capacityExpansionNeeded = true;
                outputFile << servers[i] << " to " << servers[j]
                        << " from " << capacityMatrix[i][j]
                        << " to " << (capacityMatrix[i][j] + additionalCapacity[i][j]) << endl;
            }
        }
    }


    if (canMeetAll) {
        outputFile << "None" << endl;
    }

    std::cout << "Additional Capacity Matrix:" << endl;
    for (int i = 0; i < serverCount; ++i) {
        for (int j = 0; j < serverCount; ++j) {
            std::cout << std::setw(10) << additionalCapacity[i][j] << " ";
        }
        std::cout << endl;
    }

    std::cout << "Final Capacity Matrix (after updates):" << endl;
    for (int i = 0; i < serverCount; ++i) {
        for (int j = 0; j < serverCount; ++j) {
            if (additionalCapacity[i][j] > 0) {
                std::cout << servers[i] << " to " << servers[j] << " requires capacity expansion to "
                        << capacityMatrix[i][j] + additionalCapacity[i][j] << endl;
            }
        }
    }

    outputFile << "=== End of Report ===" << endl;
    outputFile.close();
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    analyzeInfrastructure(argv[1]);
    return 0;
}
