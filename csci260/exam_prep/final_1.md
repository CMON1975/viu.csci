# 2018 Final Exam
1. Answer the following questions succinctly (briefly and clearly):
    1. **Describe how the KMP failure function is defined. That is, explain its logical meaning.**
    **KMP Failure Function Definition:** The KMP failure function, often denoted as $F(j)$, is defined for each position $j$ in the pattern string. It represents the length of the longest proper prefix of the substring $P[0..j]$ that is also a suffix ending at position $j$. This function logically indicates how many characters can be skipped when a mismatch occurs, allowing the algorithm to avoid redundant comparisons by reusing previous match information.
    2. **List the main operations of the abstract data type Dictionary, and 2 distinct concrete data structures that can be used to implement one.**
        - **Main Operations**:
            - **Insert(key, value):** Adds a key-value pair to the dictionary.
            - **Delete(key):** Remove the key-value pair associated with the key.
            - **Search(key):** Retrieve the value associated with the key.
        - **Concrete Data Structures:**
            - **Hash Table**
            - **Binary Search Tree (e.g., AVL Tree, Red-Black Tree)**
            - **Skip List**
    3. **List the main operations of the ADT Priority Queue, and 2 distinct data structures that can be used to implement one.**
        - **Main Operations:**
            - **Insert(item)**: Add an item with a priority to the queue.
            - **FindMin/DeleteMin**: Retrieve or remove the item with the minimum priority (for a min-priority queue).
        - **Data Structures:**
            - **Binary Heap (Min-Heap or Max-Heap)**
            - **Sorted Linked List or Array**
    4. **What is the difference between the two statements "$f(n)$ is in $O(n \log n)$" and "$f(n)$ is in $\theta(n\log n)$"?**
        - $f(n) \in O(n\log n)$: Indicates that $f(n)$ grows no faster than $n \log n$ asymptotically; it provides an upper bound.
        - $f(n) \in \Theta(n\log n)$: Specifies that $f(n)$ grows at the same rate as $n \log n$; it provides both an upper and lower bound.
    5. **Is it possible to perform binary search on a sorted doubly linked list? If yes, how? If no, why?**
    No, it is not practical to perform binary search on a doubly linked list because linked lists do not support direct indexing. Accessing the middle element requires $O(n)$ time, eliminating the $O(\log n)$ advantage of binary search.
    6. Describe two distinct methods to resolve the conflict problem in a hash table.
        - **Chaining**: Store collided elements in a linked list or another secondary data structure at each hash table index.
        - **Open Addressing**: Find another slot in the table for the collided element using a probing sequence (e.g., linear or quadratic probing, or double hashing).
    7. **Suppose a hash table is used to store data records whose key fields are character string type. Is it possible to traverse the hash table and display all data records stored in the hash table in ascending order of the keys? If yes, how? If no, why?**
    No, because a hash table does not maintain elements in any particular order. To display records in ascending order of the keys, you would need to extract all keys, sort them externally, and then retrieve the corresponding records, which negates the constant-time access advantage of hash tables.

2. **Given the following struct used to implement the data records stored in a 2-4 tree:
    ```cpp
    struct Data {
        int key;
        string data;
    }
    ```
    1. **Describe the concrete data structure that implements a 2-4 tree node.**
    A 2-4 tree node can be implemented using a struct that contains:
        - `int numKeys;` // number of jeys in the node (1 to 3)
        - `Data keys[3];` // array storing up to 3 `Data` elements (keys), sorted in ascending order.
        - `Node* children[4];` // array of pointers to child nodes (up to 4 children).
        - `bool isLeaf;` // indicates if the node is a leaf

    **C++ Struct Example**
    ```cpp
    struct Node {
        int numKeys;    
        Data keys[3];   
        Node* children[4]; 
        bool isLeaf;       
    };
    ```

    **Key and Child Relationships**:
    - **Keys:** Stored in `keys[0]` to `keys[numKeys - 1]`, in ascending order.
    - **Children:**
        - `children[0]` points to keys less than `keys[0]`.
        - `children[i]` (for `1 <= i <= numKeys`) points to keys between `keys[i - 1]` and `keys[i]`.
        - `childen[numKeys]` points to keys greater than `keys[numKeys - 1]`.
    
    2. **Suppose the in-order traversal of the 2-4 tree would display the data records in ascending order of the keys. Develop a C++ function that takes the 2-4 tree root node as its parameter and displays the data records in *descending* order of the keys.**
    To display the records in descending order, perform a **reverse in-order traversal**:
    ```cpp
    void displayDesccending(Node* node) {
        if (node == nullptr) return;

        int i;
        for (i = node->numKeys; i >= 0; --i) {
            // traverse the rightmost child first
            if (!node->isLeaf) {
                displayDescending(node->children[i]);
            }
            // output the key and data if i > 0
            if (i > 0) {
                cout << node->keys[i - 1].key << ": " << node-keys[i - 1].data << endl;
            }
        }
    }
    ```
    **Explanation:**
        - **Traversal Order:** Starts from the rightmost child and moves left, ensuring larger keys are processed first.
        - **Base Case:** If the node is `nullptr`, the function returns.
        - **Recursive Calls:** Only made for non-leaf nodes (`!node->isLeaf`).
        - **Output:** Prints the keys and associated data in descending order.

3. **Using pseudocode, describe an algorithm that finds the first occurence of the pattern of 6 consecutive lowercase letters in a given string. The algorithm should return the index of the first letter of the pattern in the given string, or -1 if such pattern doesn't exist in the given string. For example, if the given string is "abc6defg <u>abc6defg</u>h", then the underlined text is the pattern found and the returned index value should be 9.**
    ```pseudocode
    function findFirstPattern(s):
        n = length of s
        for i from 0 to n - 6:
            isPattern = true
            for j from 0 to 5:
                if s[i + j] not in 'a' to 'z':
                    isPattern = false
                    break
            if isPattern:
                return i 
        return -1
    ```

4. **In the international telephone system, each country is assigned with a country calling code. The following table shows some examples of the codes and corresponding names:**

    | Country Code | Country Name 
    | :- | :-
    | 1 | USA and Canada
    | 52 | Mexico
    | 44 | UK
    | 86 | China
    | 91 | India
    | 355 | Albania
    | 359 | Bulgaria
    | 855 | Cambodia

    It is guaranteed that none of the country codes is the prefix of other country codes.
    1. Define a concrete data structure for node used in a standard trie for the purpose of mapping the country codes to the corresponding country names.
    ```cpp
    struct TrieNode {
        TrieNode* children[10]; // pointers for digits 0-9
        string countryName;     // nonempty if node represents a country code
        TrieNode() : countryName("") {
            for (int i = 0; i < 10; ++i)
                children[i] = nullptr;
        }
    };
    ```
    - **Children**: An array of 10 pointers (`children[0]` to `children[9]`) for each possible digit.
    - **Country Name**: Stores the country name if the node represents the end of a country code.

    2. Suppose that a standard trie has been constructed using the concrete data structure you defined in the previous question. Using C++ pseudocode, describe an algorithm that takes a string of country code as its parameter and returns the corresponding country name. If the country code provided is invalid, return an empty string.
    ```cpp
    string getCountryName(TrieNode* root, string code) {
        TrieNode* node = root;
        for (char c : code) {
            int index = c - '0';    // convert digit character to index
            if (node->children[index] == nullptr)
                return "";  // invalid country code
            node = node->children[index];
        }
        return node->countryName;   // returns empty string if invalide
    }
    ```
    - **Traverse the Trie**:
        - For each digit in the input `code`, mode to the corresponding child node.
        - If a child does not exist (`nullptr`), the code is invalid.
    - **Return Value:**
        - If traversal complete, return `node->countryName`.
        - If `countryName` is empty, the code is invalid.
    
5. **Consider the following recurrence equation, defining $T(n)$ as:**
    $$
    T(n) = 
    \begin{cases} 
        1 & \text{if } n = 1 \\ 
        T(n-1) + n & \text{if } n > 1 
    \end{cases}
    $$
    Solve $T(n)$, and prove your solution by induction.

    **Closed-form Expression**:
    $T(n) = \frac{n(n+1)}{2}$ (found by expanding $T(n)$ which results in the sum of the first $n$ natural numbers.

    **Proof by Induction**:
    **Base Case $(n=1)$:
    $T(1) = 1$
    Closed-form calculation:
    $\frac{1\times (1+1)}{2}=\frac{1\times 2}{2}=1$
    Thus, the base case holds.
    **Inductive Step:**
    Assume the formula holds for some $k\ge 1$:
    $T(k) = \frac{k(k+1)}{2}$
    We need to show that:
    $T(k+1) = \frac{(k+1)(k+2)}{2}$
    Compute $T(k+1)$:
    $$ 
        \begin{align}
        T(k+1)  &= T(k)+(k+1) \\
        &= \frac{k(k+1)}{2}+(k+1) \text{ (by induction hypothesis)} \\
        &= (k+1)\left(\frac{k}{2}+1\right) \\
        &= (k+1)\left(\frac{k+2}{2}\right) \\
        &= \frac{(k+1)(k+2)}{2} \\
        \end{align}
    $$

    Therefore, $T(k+1)$ satisfies the closed-form expression.

6. **Using Lempel-Ziv algorithm to encode (compress) the following message string:**
    `around the house there are three green trees`
    with the following requirements:
    - The alphabet consists of 12 characters (shown below):
        $\sum = \{ , a, d, e, g, h, n, o, r, s, t, u\}$
    - 5 bits should be used to code each entry in the dictionary.
    - When fully filled, the dictionary should simply stop accepting new entries.

    Show both the final dictionary entries and sequence of the codes.

    **Final Dictionary Entries**:
    | Index | Entry
    | :- | :-
    | 1 | a
    | 2 | r
    | 3 | o
    | 4 | u
    | 5 | n
    | 6 | d
    | 7 | ' '
    | 8 | t
    | 9 | h
    | 10 | e
    | 11 | ' h'
    | 12 | ou
    | 13 | s
    | 14 | e'
    | 15 | th
    | 16 | er
    | 17 | e a
    | 18 | re
    | 19 | 't'
    | 20 | hr
    | 21 | ee
    | 22 | ' g'
    | 23 | ree
    | 24 | n '
    | 25 | tr
    | 26 | ees

    **Sequence of Codes:**
    1. (0, a)
    2. (0, r)
    3. (0, o)
    4. (0, u)
    5. (0, n)
    6. (0, d)
    7. (0, ' ')
    8. (0, t)
    9. (0, h)
    10. (0, e)
    11. (7, h)
    12. (3, u)
    13. (0, s)
    14. (10, ' ')
    15. (8, h)
    16. (10, r)
    17. (14, a)
    18. (2, e)
    19. (7, t)
    20. (9, r)
    21. (10, e)
    22. (7, g)
    23. (18, e)
    24. (5, ' ')
    25. (8, r)
    26. (21, s)

    **Explanation:**
    - **Alphabet**: $\sum = \{ , a, d, e, g, h, n, o, r, s, t, u\}$
    - **Dictionary Limit**: 5 bits per entry ⇒ max 32 entries.
    - **Encoding Process:** Used LZ78 algorithm to encode the message.
    - **Dictionary Filling:** Stopped adding new entries after reaching the limit or when the message ended.

7. **Given the following adjacency matrix of the graph G, where A to F are identities of the vertices in G, a positive number in row i and column j represents a directed edge from vertex i to vertex j with a given weight, and 0 means no such edge from vertex i to vertex j.**

    | | A | B | C | D | E | F
    | :- | :- | :- | :- | :- | :- | :-
    | A | 0 | 0 | 15 | 12 | 0 | 0
    | B | 5 | 0 | 0 | 0 | 6 | 0
    | C | 0 | 0 | 0 | 0 | 0 | 25
    | D | 0 | 19 | 0 | 0 | 0 | 0
    | E | 0 | 0 | 0 | 0 | 0 | 8
    | F | 0 | 0 | 0 | 0 | 0 | 0

    1. Draw the graph G that is consistent with the above given adjacency matrix.
    2. Order the vertices as they are visited in a DFS (depth first search) traversal starting at vertex A.
    3. Draw the minimum spanning tree of the graph G. For the purpose of the question only, treat all the edges as undirected ones.
    4. Using C/C++ pseudocode, describe an algorithm that determines whether there is a cyclic path in graph G that involves a given vertex (passed through a parameter).
    ```cpp
    bool isCyclicUtil(int v, bool visited[], bool recStack[], int adj[][6], int numVertices) {
        visited[v] = true;
        recStack[v] = true;

        for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
            if (adj[v][neighbor] != 0) {    // if edge exists
                if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack, adj, numVertices))
                    return true;
                else if (recStack[neighbor])
                    return true;
            }
        }
        recStack[v] = false;
        return false;
    }

    bool hasCycleFromVertex(int start, int adj[][6], int numVertices) {
        bool visited[6] = {false};  // tracks visited nodes
        bool recStack[6] = {false}; // tracks current recursion path

        return isCyclicUtil(start, visited, recStack, adj, numVertices);
    }
    ```