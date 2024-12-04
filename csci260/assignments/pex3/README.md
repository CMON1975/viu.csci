# README for Assignment 03 - Network Infrastructure Analysis
CHRISTOPHER NILSSEN CSCI 260 F2402

## Specification
This application analyzes a **network infrastructure** consisting of communication servers and bi-directional links. It evaluates whether the infrastructure can meet communication demands and identifies required link expansions to handle the lowest cost routing.

The system performs the following tasks:
1. **Connectivity Check:** Identifies communication demands that cannot be met due to a lack of routes between specified servers.
2. **Capacity Analysis:** Determines whether the infrastructure can meet all other demands at the lowest cost. If not, it identifies links that require capacity expansions and calculates the required increase.

## Design
The application is implemented using fundamental data structures and avoids advanced libraries to deepen understanding of computer science principles.

### Components:
1. **Graph Representation:**
    - The network is represented as adjacency matrices for:
      - Costs (`costMatrix`): Stores unit costs for bi-directional links.
      - Capacities (`capacityMatrix`): Tracks communication volume limits for bi-directional links.
2. **Pathfinding:**
    - Implements **Dijkstra's algorithm** for shortest path calculation.
3. **Volume Tracking:**
    - Accumulates required communication volumes (`totalVolume`) for each link based on demands.
4. **Output Generation:**
    - Produces a report specifying unmet demands and required link expansions.

**Design Rationale:**
- **Efficiency:** Dijkstra's algorithm ensures efficient shortest path calculations for large datasets.
- **Modularity:** Separates concerns between pathfinding, data representation, and output generation.
- **Simplicity:** Avoids external libraries, focusing on fundamental concepts.

## Implementation
### Data Structures
1. **Adjacency Matrices:**
    - **Cost Matrix (`costMatrix`)**: Represents the network's unit cost for each link.
    - **Capacity Matrix (`capacityMatrix`)**: Represents the volume capacity of each link.
    - **Volume Matrix (`totalVolume`)**: Tracks cumulative demands for each link.
2. **Path Array:**
    - Used to reconstruct paths from the source to the destination during shortest path calculations.

### Algorithms
1. **Shortest Path Calculation:**
    - **Algorithm:** Dijkstra's algorithm is used to find the lowest cost path between servers.
    - **Complexity:** O(n²) per demand for a graph with n servers.
2. **Demand Processing:**
    - Accumulates volume requirements for each link.
    - Compares required volumes to current capacities and calculates deficits where necessary.

### Memory Management
- Static arrays are used for simplicity and to ensure efficiency.
- No dynamic memory allocation is required, avoiding memory management issues.

## Testing
The program was tested with the given scenario:
1. **Connectivity Testing:**
    - Tested with a network where some servers were completely disconnected.
2. **Capacity Testing:**
    - Verified that capacity expansions were correctly calculated for multiple demands sharing the same links.
3. **Pathfinding Testing:**
    - Ensured that the shortest path was selected for each demand, minimizing costs.
4. **Edge Cases:**
    - Tested for minimal case, fully connected network, no feasible path, capacity exceeded, large volume and many demands, circular graph, and high cost vs low cost paths.

### Example Input
Input file format:
```
6 // number of servers followed with 6 names
Daisy
Heather
Iris
Jasmine
Rose
Violet
7 // number of direct links: two server names, unit cost and volume capacity
Daisy Iris 7.5 50
Daisy Heather 25.8 60
Daisy Violet 14.2 80
Heather Jasmine 12.7 28
Iris Jasmine 8.3 75
Iris Violet 3.5 35
Jasmine Violet 2.1 67
5 // number of communication demands: two server names, volume needed
Daisy Iris 38
Daisy Jasmine 52
Daisy Violet 62
Heather Violet 59
Heather Rose 15
```

### Example Output
Output file format:
```
Technology Analysis based on data in file input.txt

The following communication demand(s) can't be met
by current infrastructure due to lack of routes
between the two servers:
Heather Rose 15

In order to meet the rest of the communication demands
with the lowest cost, the following direct link(s)
must expand their capacity:
Daisy to Iris from 50 to 152
Heather to Jasmine from 28 to 59
Iris to Violet from 35 to 114
Jasmine to Violet from 67 to 111

=== End of Report ===
```

## Accomplishment
- Implemented Dijkstra's algorithm for shortest path calculation.
- Accumulated link volumes and calculated required capacity expansions.
- Produced clear, formatted output reports.

## Known Bugs
There are currently **no known bugs** in the application.

## Notes
- **Input File:** Ensure the input file adheres to the specified format for correct processing.
- **Output File:** The results are written to `techAnalysisResult.txt` in the working directory.
- The Makefile has been provided to automate the build process. Running `make` will generate the executable named `network_analysis`.
- Run the program with ./network_analysis input.txt
