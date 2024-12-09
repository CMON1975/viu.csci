# Learning Outcomes for Algorithms and Data Structures
1. Identify common/standard problems.
2. Enumerate and implement some of their algorithmic solutions.
3. Select and implement appropriate abstract data types to solve problems.
4. Analyze, compare, and select optimal algorithmic solutions.

Application Dependent Business Logic
&darr;
Application Independent; Common Standard; Abstract Data Types
&darr;
Application Dependent Data Objects

# Topics
- ATDs:
    - queue, stack, dictionary, hashtable, trees, trie, graph
    1. definition/properties
    2. operations/expected performances
    3. implementation:
        - concrete data structure
        - methods implementation
    actual performance
    4. typical applications
- Queue: circular array
- Stack: array
- Priority Queue: heap or list (sorted or unsorted)
- Dictionary: sorted or unsorted list, hashtable, tree, skip list
    - methods of insertion
    - methods of collision avoidance
- Graph: 
    - trees, trie
    - <V, E> set of vertices, set of edges
    - set of vertices + adjacency matrix (possibly multiple)
- Trees:
    - Binary Search Tree
    - AVL tree
    - Red-Black tree
    - multiway tree
    - A-B (particularly 2-4) tree

# Algorithms
- Graph algorithms (shortest path, minimum spanning tree, topological sort, traversal)
    - how traversal assists in debugging
- Exact string matching: brute force, BM, KMP, KR
- Data encoding/decoding and compression:
    - Huffman code tree
    - Lempel-Ziv algorithm
- Selection and Sorting
    - bubble, swap, etc
- Memory Management

# Algorithm Analysis
- problem size
- asymptotic analysis
    - O, o, $\Omega$, $\omega$, $\Theta$
- iterative or recursive algorithms
    - primitive operations count as a function of problem size
- recurrence equation for recursive algorithms
    - solve it, prove by induction
    - apply master theorem

# Methodologies
- brute force
- greedy
- backtracking
- dynamic programming
- randomization