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
    Compare $f(N)$ and $N^{\log_ba}$, determine th ecase, and write down the corresponding complexity.
5. **Confirm with Examples**
    Check if the final complexity matches your intuition (e.g., if $f(N)$ grows a bit faster than $N$, expect an extra log factor in the solution).
