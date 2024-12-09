**To perform DFS of graph:**
1. Build adjacency list: List nodes, then list their connections i.e., A [(B,10), (C,12)]
2. Select starting node then visit an adjacent node (arbitrary). Add node and visited node to visit order i.e. A,B
3. Backtrack if nodes in visited node list have already been visited.
4. Stop when all nodes visited.

**To show Djikstra's steps:**
1. Create table with columns for vertices, distance, and if done.
2. From starting vertex, distance is 0. Update distances to adjacent vertices. Mark vertex done.
    1. choose X, dist Y
        - update A = N1, B = N2, C = N3
        - X done
3. Continue by choosing next not done vertice with lowest distance in table, repeat 2.
4. Repeat until all vertices marked as done.

**Failure function:**
1. Create table with rows for pattern, index, and f array.
2. Count consecutive repetitions of prefixes in previous characters from current position in pattern.
Note: The function in KMP is to intelligently manage pattern shifts when mismatches occur, achieving linear-time string matching.

**ADT Requirements:**
1. **Definition and Properties:**
    A clear description of what the ADT represents and its key characteristics.
2. **Operations and Expected Performance:**
    A list of operations the ATD supports (e.g., add, remove, find) along with their expected functional behavior and time complexity in an abstract sense.
3. **Implementation and Actual Performance:**
    Details about how the ADT could be implemented using concrete data structures and how these affect performance.
4. **Typical Applications:**
    Examples of real-world problems or scenarios where this ADT is useful.

**Growth Rates**
| Growth Rate | Type | Example Algorithms | Comparison
| :- | :- | :- | :-
| $O(1)$ | Constant Time | Hash table lookups | Fastest
| $O(\log N)$ | Logarithmic | Binary Search | Very Fast
| $O(N)$ | Linear | Linear Search | Moderate
| $O(N\log N)$ | Log-Linear | Merge Sort, Quick Sort | Manageable
| $O(N^2)$ | Quadratic | Bubble Sort, Selection Sort | Slow
| $O(N^3)$ | Cubic | Matrix multiplication | Slower
| $O(2^N)$ | Exponential | Subset generation, TSP brute force | Very Slow
| $O(N!)$ | Factorial | Permutations, brute-force TSP | Slowers

**Recursive Functions:**
1. **Write the Recurrence**
    Given code or description, identify $a$, $b$, and $f(N)$:
    - $a$: number of recursive calls
    - $b$: reduction factor (N is divided by b each recursive call)
    - $f(N)$: the non-recursive work per call (combine steps, parition steps, etc.)
2. **Apply the Master Theorem**
    The Master Theorem handles recurrences of the form:
    $T(N) = aT(\frac{N}{b} + f(N))$
    Identify $N^{(\log_ba)}$ and compare it to $f(N)$.
3. **Classification**
    1. If $f(N) = O(N^{\log_ba-\epsilon})$ for some $\epsilon > 0$, then $T(N) = \Theta(N^{log_ba})$
    2. If $f(N) = \Theta(N^{\log_ba} \times \log^k N)$ for some $k \ge 0$, then $T(N) = \Theta(N^{\log_ba} \times log^{k+1}N)$
    3. If $f(N) = \Omega(N^{\log_ba + \epsilon})$ for some $\epsilon > 0$ and regularity conditions hold, then $T(N) = \Theta(f(N))$.
4. **Substitute and Solve**
    Compare $f(N)$ and $N^{\log_ba}$, determine the case, and write down the corresponding complexity.
5. **Confirm with Examples**
    Check if the final complexity matches your intuition (e.g., if $f(N)$ grows a bit faster than $N$, expect an extra log factor in the solution).

**Induction Proof**
1. **Identify and Write Down the Recurrence and the Supposed Closed-Form**
2. **Verify the Base Case**
3. **State the Induction Hypothesis Clearly and Explicitly**
4. **Write Down the Inductive Step Setup**
5. **Use the Recurrence and Substitute the Hypothesis**
6. **Perform the Algebraic Simplification Carefully and Step-by-Step**
7. **State the Conclusion Clearly**

**Red-Black Tree**
1. Initial insertion: find correct leaf position and add as red.
2. Check for violation: if parent of new node is red:
    - red parent and red uncle: recolor parent and uncle to black, recolor grandparent to red, check again for violations from grandparent.
    - red parent and black uncle, zig-zag: rotate to convert to line
    - red parent and black uncle, line configuration: rotate on grandparent, swap colors of former grandparent and parent
3. Ensure root is black, repeate until stable.

**Conversion to 2-4 Tree**
```
                     50(B)
                /            \
            36(B)             62(B)
            /  \           /        \
         8(R)   43(B)   53(B)       88(B)
        /   \              \       /     \
    5(B)    28(B)          58(R)  78(R)  97(R)
    /      /    \
  4(R)   13(R)  33(R)
```

```
                          [50]
              /                        \
          [8, 36]                       [62]
     /       |        \             /           \
[4, 5]  [13, 28, 33]  [43]     [53, 58]    [78, 88, 97]
```
- Black parents become singular container nodes
- Red children folded up into black parents

**Data Structures, Properties and Implementations, Associated Algorithms, Typical Applications**
- Queue: FIFO; enqueue, dequeue in O(1) amortized; breath-first search, scheduling
- Stack: FILO; push, pop in O(1); expression eval, backtracking, function calls
- Heap: complete binary tree with heap-order; insert O(log n), extract-min/max O(log n); priority queues, scheduling, shortest-path algos
- Priority Queue: maintain priority order; insert, extract-min/max O(log n); event simulation, Dijkstra's algorithm
- Hash Table: key-value mapping with hash func; insert, lookup, remove average O(1); symbol tables, caches, dictionaries
- Dictionary (Map): key-value structure w/unique keys; insert, lookup, remove O(log n) with balanced tree or O(1) with hash table; fast lookups in databases, language runtimes
- Binary Seach Tree: ordered binary tree; insert, lookup, remove O(h) (h = tree height); searching, range inquiries
- AVL Tree: self-balancing BST; insert, lookup, remove O(log n); indexing, search-intensive applications
- Red-Black Tree: self-balancing BST (color property); insert, lookup, remove O(log n); standard library implementations (C++ map)
- Multiway Search Tree: nodes with multiple keys; insert, lookup, remove O(log n); efficient external memory searches, database indexing
- (2,4)-Tree, B-Tree: balanced multiway search trees; insert, lookup, remove O(log n); used in databases, filesystems
- Skip List: linked-list layers with probabilistic balancing; insert, lookup, remove O(log n); concurrent indexes; in-memory databases
- Trie: keyted by characteristics (prefix-based); insert, lookup O(m) (m = key length); autocomplete, dictionary lookups
- Graph: collection of vertices and edges; add vert/edge O(1), lookup adjacency O(1) or O(V) depending on structure; modeling networks, shortest-path, connectivitive problems

**Programming Methodologies**
- Brute Force: tries all possibilities; often exponential O(2^n); small inputs, verify solutions
- Greedy: pick best local option at each step; often O(n log n) or better; interval scheduling, Huffman encoding, MST algorithms
- Backtracking: explore solution space, backtrack on dead ends; often exponential but prunes paths; constraint satisfaction (e.g., Sudoku, N-Queens)
- Divide and Conquer: split problems into subproblems, solve recursively, combine results; often O(n log n); sorting (mergesort, quicksort), binary search, FFT
- Dynamic Programming: break problems into overlapping subproblems, reuse solutions; polynomial time (O(n²), O(n·m), etc.); optimization problems (Knapsack, shortest paths, sequence alignment)
- Randomization: introduce randomness for simplicity or efficiency; expected polynomial time; quicksort (average O(n log n)), randomized primality tests; hashing

**P and NP**
- complexity class P: decision problems *solvable* in polynomial time by a deterministic Turing machine; practical tractability benchmark
- complexity class NP: decision problems *verifiable* in polynomial time by a deterministic Turing machine; includes many hard-to-solve (but easy-to-check) problems
- NP-completeness: NP problems that are as hard as any other NP problem (every NP problem reduces to them in polynomial time); if any NP-complete problem can be solved in P, then P = NP
- NP-hard: at least as hard as NP-complete problems, but not necessarily in NP; covers problems that might not even be decidable in polynomial time

**Memory Management, Key Concepts, Methods**
- Issues: fixed vs. varying-size records; response time vs. space efficicency; explicit vs. implicit freeing
- Goals: allocate requested sizes; maintain large contiguous free areas; combine freed spaces
- Costs: memory utilization (avoid frag.); overhead for managment structures; allocation time efficiency
- Implicit Freeing (garbage coll.):
    - reference counts: increment/decrement for references; issues: limited size, overhead per pointer operation, poor locality, cycles not collected
    - mark & sweep: mark reachable objects, then compact; reduced fragmentation but expensive due to copying
- Explict Freeing: application explicitly calls allocate (malloc/new) and free (free/delete)
- Allocation Heuristics: best fit: smallest fitting block; worst fit: largest block; first fit: first suitable block found
- Examples: boundary-tag: doubly linked free blocks with O(n) search, O(1) free; buddy system: predefined block sizes, quick merge with buddy, faster but can cause internal fragmentation

**String Matching Algorithms, Key Ideas, Complexity**
- Problem Definition: given text s (length n) and pattern p (length m ≤ n), find i where p is a substring of s.
- Brute Force (BF): compare p to every possible substring of s; O(n*m) worst case, easy to implement, works with any alphabet; no pre-processing
- Boyer-Moore (BM): use last occurence of mismatches character to skip ahead; pre-process pattern to build a "last" array; best case ~O(n/m), worst case O(n*m) but rare; requires fixed finite alphabet
- Knuth-Morris-Pratt (KMP): use failure function to reuse partial mathes; pre-process pattern for failure function; O(n+m) time complexity; works with unknown/infinite alphabets
- Combined KMP-BM: use both KMP's partial match info and BM's mismatch info; pre-process pattern for skip distances; O(n/m + m) time complexity; requires fixed finite alphabet
- Karp-Rabin (KR): uses hashing to quickly compare substrings; pre-process pattern hash, roll hash over s; average O(n+m), worst case O(n*m); useful for multiple pattern search, plagiarism detection

**Hash Table, Key Concepts, Methods**
- Basics: use bucket array of size N to store key-value pairs; ideal: insert, remove, lookup in O(1) average
- Issues & Solutions: choosing N large enough for low load factor but not wasteful; keys may not be integers or in [0, N-1] → need a hash function; collisions inevitable → need collision resolution
- Hash Functions: generate integer hash codes and compresses into [0, N-1]; polynomial hash for strings (use constants like 33, 37, 39, 41); MAD compression: h(k) = ((a*k + b) mod P) mod N. with prime P
- Collision Resolution:
    - Separate Chaining: each bucket points to a linked list (or another structure); load factor α = n/N affects performance, rehash when large
    - Open Addressing: no external structure, find another sport using a probe sequence; Linear probing: g(j) = j (simple but clustering); Quadratic probing: g(j) = j^2 (less clustering, may miss spots); Double hashing: g(j, k) = k'(k) (second hash), reduces clustering
- Universal Hashing: randomly pick hash function from a universal family; ensures low collision probability and good average performance