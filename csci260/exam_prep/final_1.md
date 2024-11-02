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