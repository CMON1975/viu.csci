### List the main operations of the ADT Dictionary. For each operation, describe its required parameters and its functionality.
#### Main Operations of the ADT Dictionary
A **Dictionary ADT** (also known as a **Map** or **Associative Array**) stores key-value pairs and allows efficient retrieval of values based on their keys.
1. **Insert (Put, Add)**
    - **Parameters:**
        - **Key:** The unique identifier for the value.
        - **Value:** The data associated with the key.
    - **Functionality:**
        - Adds a new key-value pair to the dictionary.
        - If the key already exists, the value is typically updated (depending on the implementation).
        - Ensure that each key in the dictionary is unique.

2. **Remove (Delete, Erase)**
    - **Parameters:**
        - **Key:** The key of the key-value pair to be removed.
    - **Functionality:**
        - Removes the key and its associated value from the dictionary.
        - If the key does not exist, the operation may do nothing or signal an error (implementation-dependent).

3. **Search (Find, Lookup, Get)**
    - **Parameters:**
        - **Key:** The key whose assoicated value is to be retrieved
    - **Functionality:**
        - Retrieves the value associated with the given key.
        - If the key is found, returns the corresponding value.
        - If the key is not found, may return a special value (e.g., `null` or `None`) or throw an exception.

4. **Update**
    - **Parameters:**
        - **Key:** The kew whose associated value needs to be updated.
        - **New Value:** The new value to associate with the key.
    - **Functionality:**
        - Updates the value associated with the specified key.
        - If the key does not exist, behavior may vary:
            - Some implementations insert the new key-value pair.
            - Others may signal an error or do nothing.

5. **ContainsKey (Exists, HasKey)**
    - **Parameters:**
        - **Key:** The key to check for existence in the dictionary.
    - **Functionality:**
        - Check if the dicationary contains the specified key.
        - Returns a boolean value:
            - **True** if the key exists.
            - **Fales** if the key does not exist.

6. **Size**
    - **Parameters:**
        - None.
    - **Functionality:**
        - Returns the number of key-value pairs currently stored in the dictionary.
        - Useful for understanding the current capacity or load of the dictionary.

7. **IsEmpty**
    - **Parameters:**
        - None.
    - **Functionality:**
        - Checks if the dictionary is empty (contains no key-value pairs).
        - Returns a boolean value:
            - **True** if the dictionary is empty.
            - **False** if it contains one or more key-value pairs.

8. **Clear**
    - **Parameters:**
        - None.
    - **Functionality:**
        - Removes all key-value pairs from the dictionary.
        - Resets the dictionary to its initial empty state.

9. **Keys**
    - **Parameters:**
        - None.
    - **Functionality:**
        - Returns a collection (e.g., list, set) of all keys present in the dictionary.
        - Useful for iterating over keys or performing bulk operations.

10. **Values**
    - **Parameters:**
        - None.
    - **Functionality:**
        - Returns a collection of all values stored in the dictionary.
        - The order of values may correspond to the order of their keys (implementation-dependent).

11. **Items (Entries, KeyValuePairs)**
    - **Parameters:**
        - None.
    - **Functionality:**
        - Returns a collection of all key-value pairs in the dictionary.
        - Each item in the collection is typically a tuple or object containing a key and its associated value.

#### Additional Operations (Implementation-Dependent)
- **Merge (Combine, Union):**
    - **Parameters:** Another dictionary.
    - **Functionality:** Combines another dictionary with the current one, possibly overwriting existing keys.

- **Clone (Copy):**
    - **Parameters:** None.
    - **Functionality:** Creates a shallow or deep copy of the dictionary.

#### Study Guidance on Mastering Dictionary Concepts
To effectively understand and master the concepts related to the Dictionary ADT, consider the following study tips:
1. **Grasp the Fundamental Concepts**
    - **Key-Value Pairing:**
        - Understand that dictionaries store data as pairs, with each key uniquely identifiying its value.
        - Recognize the importance of keys being unique within the dictionary.
    - **Hashing Basics:**
        - Learn how hashing functions map keys to indices in underlying data structures like hash tables.
        - Understand collision resolution strategies (e.g., chaining, open addressing).

2. **Study Common Implementations**
    - **Hash Tables:**
        - Most dictionaries are implemented using hash tables for efficient average-case performance.
        - Explore hopw hash functions, buckets, and load factors work.
    - **Balanced Trees (e.g., AVL Trees, Red-Black Trees):**
        - Some dictionaries use tree-based implementations to maintain order.
        - Understand how these trees balance themselves and allow for ordered traversals.
    - **Skip Lists and Tries:**
        - Learn about alternative structures that can be used to implement dictionaries, especially for string keys.

3. **Analyze Time Complexities**
    - **Operation Performance:**
        - **Hash Table Implementation:**
            - Average-case: O(1) for insert, remove, and search.
            - Worst-case: O(n) when collisions are poorly handled.
        - **Tree-Based Implementation:**
            - O(log n) for insert, remove, and search operations.
    - **Understand Factors Affecting Performance:**
        - Quality of the hash function.
        - Load factor and resizing strategies.
        - Tree balancing mechanisms.

4. **Practice Coding**
    - **Implement a Dictionary from Scratch:**
        - Start by coding a simple hash table with basic operations.
        - Handle collisions using methods like chaining or open addressing.
    - **Experiment with Different Data Structures:**
        - Implement dictionaries using balanced trees.
        - Compare performance with hash table implementations.

5. **Solve PRactical Problems**
    - **Use Cases:**
        - Apply dictionaries to solve problems like word counting, caching, and indexing.
        - Work on coding challenges that require efficient data retrieval and storage.
    - **Algorithm Integration:**
        - Understand how dictionaries are used in algorithms (e.g., memoization in dynamic programming, symbol tables in compliers).

6. **Visual Learning**
    - **Diagrams and Flowcharts:**
        - Visualize how data is stored and retrieved.
        - Draw hash tables showing key-value mappings and collision resolutions.
    - **Step-by-Step Execution:**
        - Trace through insertions and deletions to see how the internal state changes.

7. **Deepen Theoretical Understandiing**
    - **Collision Reduction Techniques:**
        - Study different methods like linear probing, quadratic probing, and double hashing.
    - **Amortized Analysis:**
        - Learn about the amortized cost of operations, especially in dynamic resizing scenarios.
    - **Universal and Perfect Hashing:**
        - Explore advanced hashing techniques that reduce collisions.

8. **Test Your Knowledge**
    - **Quizzes and Flashcards:**
        - Use flashcards to memorize key concepts and terminology.
    - **Interview Questions:**
        - Solve common interview problems involving dictionaries to reinforce your skills.

9. **Explore Real-World Applications**
    - **Databases and Indexing:**
        - Understand how dictionaries relate to indexing in databases.
    - **Caching Mechanisms:**
        - Learn how dictionaries are used in implementing caches for performance optimization.
    - **Language Interpreters and Compilers:**
        - Study the role of symbol tables (a type of dictionary) in managing variables and functions.

### Suppose that a sorted array is used to implement the dictionary, write a C++ function to illustrate the algorithm that implements the operation of `look up` an object with a given key (of integer type).

#### Understanding the Question
- **Dictionary Implementation:** The dictionary is implemented using a **sorted array**.
- **Operation to Implement:** We need to write a C++ function that performs a **lookup** for an object with a given key (integer type).
- **Objective:** Illustrate the algorithms used in the lookup operation.

#### Algorithm Overview
Since the array is **sorted** based on the keys, we can use **binary search** to efficiently find the object associated with a given key. Binary search reduces the search space by half with each comparison, resulting in a time complexity of $O( \log n)$.

#### C++ Function Implementation
```
#include <iostream>
#include <string>
#include <stdexcept>

// define the structure for dictionary entries (key-value pairs)
struct Entry {
    int key;
    std::string value;
};

// function to perform binary search on the sorted array
std::string lookup(const Entry dictionary[], int size, int searchKey) {
    int left = 0;
    int right = size - 1;

    // binary search loop
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (dictionary[mid].key == searchKey) {
            // key found, return the associated value
            return dictionary[mid].value;
        } else if (dictionary[mid].key < searchKey) {
            // search in the right half
            left = mid + 1;
        } else {
            // search the left half
            right = mid - 1;
        }
    }

    // key not found, throw exception
    throw std::runtime_error("Key not found in the dictionary.");
}
```
#### Explanation of the Code
##### Data Structures
- **Entry Structure:**
```
struct Entry {
    int key;
    std::string value;
};
```
- Represents a key-value pair in the dictionary.
- **key:** The integer key used for searching.
- **value:** The associated object or data.

##### Lookup Function
`std::string lookup(const Entry dictionary[], int size, int searchKey)`
- **Parameters:**
    - `const Entry dictionary[]`: The sorted array of dictionary entries.
    - `int size`: The number of elements in the dictionary.
    - `int searchKey`: The key to search for.
- **Return Values:**
    - Returns the `std::string` value associated with the `searchKey`.
- **Algorithm Steps:**
    1. **Initialization:**
        ```
        int left = 0;
        int right = size - 1;
        ```
        - `left`: The starting index of the search range.
        - `right`: The ending index of the search range.
    2. **Binary Search Loop:**
        ```
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // ... comparison logic ... 
        }
        ```
        - Continues as long as the search range is value (`left <= right`).
        - Calculates the middle index `mid` to avoid integer overflow.
    3. **Comparison Logic:**
        ```
        if (dictionary[mid].key == searchKey) {
            return dictionary[mid].value;
        } else if (dictionary[mid].key < searchKey) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        ```
        - **Case 1:** `dictionary[mid].key == searchKey`
            - The key is found; return the associated value.
        - **Case 2:** `dictionary[mid].key < searchKey`
            - The search key is in the right half; update `left`.
        - **Case 3:** `dictionary[mid].key > searchKey`
            - The search key is in the left half; update `right`.
    4. **Key Not Found**
        ```
        throw std::runtime_error("Key not found in the dictionary.");
        ```
        - The loop exits wtihout finding the key, an exception is thrown.
##### Usage Example
```
int main() {
    // initialize a sorted array of dictionary entries
    Entry dictionary[] = {
        {1, "Apple"},
        {3, "Banana"},
        {5, "Cherry"},
        {7, "Date"},
        {9, "Elderberry"},
        {11, "Fig"},
        {13, "Grape"}
    };
    int size = sizeof(dictionary) / sizeof(dictionary[0]);

    // key to search for
    int searchKey = 5;

    try {
        // perform the lookup
        std::string result = lookup(dictionary, size, searchKey);
        std::cout << "Key " << searchKey << " corresponds to value: " << result << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
```
**Expected Output:**
```
Key 5 corresponds to value: Cherry
```
If you search for a key that doesn't exist:
```
int searchKey = 6;
```
**Output:**
```
Key not found in the dictionary.
```

#### Detailed Explanation
##### Why Use Binary Search?
- **Efficiency:** Binary search has a time complexity of $O( \log n)$, making it much faster than linear search for large datasets.
- **Requirement:** The array must be sorted based on the keys.
##### Handling Edge Cases
- **Empty Dictionary:** If `size` is zero, `right` becomes `-1` and the loop doesn't execute.
- **Duplicate Keys:** Since it's a dictionary, keys are assumed to be unique. If duplicates exist, the algorithm would still find one occurance.
##### Exception Handling
- **Key Not Found:** An exception is thrown to indicate the key doesn't exist in the dictionary.
- **Alternative:** Instead of throwing an exception, you could return a special value or use a boolean flag.

#### Study Guidance
##### 1. Understand Binary Search Algorithm
- **Concept:**
    - Binary Search works by repeatedly dividint the search interval in half.
    - Requires a sorted array to function correctly.
- **Implementation Details:**
    - Be mindful of calculating the middle index to prevent integer overflow:
        ```
        int mid = left + (right - left) /2;
        ```
    - Understand the conditions for moving the `left` and `right` pointers.
- **Practice:**
    - Write binary search code from scratch without referring to notes.
    - Modify the algorithm to work with different data types or structures.
##### 2. Grasp Dictionary ADT Operations
- **Lookup Operations:**
    - Key component of Dictionary ADT.
    - Efficiency depends on the underlying data structure.
- **Other Operations:**
    - Insertion and deletion in a sorted array can be costly ($O\left(n\right)$) due to shifting elements.
    - Understand trade-offs when choosing an implementation.
##### 3. Analyze Time Complexity
- **Binary Search:**
    - Time Complexity: $O\left( \log n \right)$
    - Space Complexity: $O\left(1\right)$ for iterative implementation.
- **Compare with Other Methods:
    - Linear Search: $O\left(n\right)$
    - Hash Tables: Average-case $O(1)$, but requires hashing functions.
##### 4. Practice Coding
- **Implement Variations:**
    - Recursive version of binary search.
    - Implement lookup in unsorted arrays (linear search).
- **Error Handling:**
    - Practice robust exception handling.
    - Consider returning optional types (e.g., `std::optional` in C++ 17) instead of throwing exceptions.
##### 5. Deepen Understanding of Data Structures
- **Sorted Arrays:**
    - Advantages: Efficient search with binary search.
    - Disadvantages: Inefficient insertions and deletions.
- **Alternative Structures:**
    - **Binary Search Trees (BSTs):** Allow for efficient insertions, deletions, and lookups.
    - **Hash Tables:** Offer average-case $O\left(1\right)$ lookup but require good hash functions.
##### 6. Study Binary Search Trees
- **Implementation:**
    - Understand how BSTs store data.
    - Practice implementing lookup, insertion, and deletion in BSTs.
- **Balanced Trees:**
    - Learn about AVL Trees and Red-Black Trees for self-balancing properties.
##### 7. Explore Standard Libary Containers
- **C++ STL:**
    - **std::map:** Typically implemented as a Red-Black Tree.
    - **std:unordered_map:** Implemented using hash tables.
- **Usage:**
    - Practice using these containers for dictionary operations.
    - Understand their time complexities and when to use each.
##### 8. Visual Learning
- **Draw Diagrams:**
    - Visualize how binary search narrows down the search space.
    - Sketch the array and the `left`, `right`, and `mid` pointers at each step.
##### 9. Solve Practice Problems
- **Algorithm Challenges:**
    - Use platforms like LeetCode or HackerRank to solve binary search problems.
- **Debugging:**
    - Practice tracing your code with different inputs to find and fix errors.
##### 10. Learn About Algorithm Optimization
- **Edge Cases:**
    - Study how to handle duplicates, especially in variations like lower_bound and upper_bound.
- **Optimization Techniques:**
    - Understand how to optimize code for performance and readability.
#### Summary
- **Understanding the Problem:**
    - Implement a `lookup` function using binary search in a sorted array-based dictionary.
- **Implementation:**
    - Use binary search to achieve $O\left(\log n\right)$ time complexity.
    - Handle cases where the key is not found by throwing an exception or returning a special value.
- **Study Guidance:**
    - Focus on mastering binary search and understanding its application.
    - Explore alternative data structures and their trade-offs.
    - Practice coding and solving related problems to reinforce learning.

### (a) What is a heap? (Hint: describe the two main properties of a heap)
A heap is a specialized tree-based data structure that satisfied specific proprties, making it useful for implementing priority queues and for efficient sorting algorithms like Heap Sort. Heaps are typically implemented as binary trees, known as **binary heaps**, but there are also types like binomial heaps and Fibonacci heaps.
---
#### Two Main Properties of a Heap
A binary heap must satisfy two fundamental properties:
##### 1. Structural Property (Shape Property)
- **Complete Binary Tree**:
    - A heap is a **complete binary tree**, which means all levels of the tree are fully filled except possibly for the last level, which is filled from left to right.
    - **Implications**:
        - Ensures that the tree has minimal height, leading to efficient operations.
        - Allows the heap to be efficiently represented using an array.
##### 2. Heap Property (Order Property)
- **Heap Order Invariant**:
    - The value of each node must be **greater than or equal to** (in a **max-heap**) or **less than or equal to** (in a **min-heap**) the values of its children.
    - **Max_Heap**:
        - The **largest** element is at the root.
        - For every node $i$, the value of $i$ is greater than or equal to the values of its children.
    - **Min-Heap**:
        - The **smallest** element is at the root.
        - For every node $i$, the value of $i$ is less than of equal to the values of its children.
- **Implications**:
    - Enables quick access to the highest (max-heap) or lowest (min-heap) priority element.
    - Facilitates efficient implementation of priority queue operations.
---
#### Detailed Explanation
##### Structural Property (Complete Binary Tree)
- **Definition**:
    - A binary tree where all levels are fully filled except possibly the last level.
    - In the last level, all nodes are as far left as possible.
- **Representation Using Arrays**:
    - Because of its structure, a heap can be stored compactly in an array without pointers.
    - Indexing:
        - Parent of node at index $i$: $\lfloor \frac{i-1}{2} \rfloor$
        - Left child of node at index $i$: $2i+1$
        - Right child of node at index $i$: $2i+2$
##### Heap Property (Order Property)
- **Max-Heap Example**:
    - Root node has the maximum value.
    - Every parent node is greater than or equal to its child nodes.
- **Min-Heap Example**:
    - Root node has the minimum value.
    - Ever parent node is less than or equal to its child nodes.
- **Non-Sorted Order**:
    - Heaps are not sorted structures; they only guarantee the heap property.
    - This is no specific order between sibling nodes or across levels (other than parent-child relationships).
---
#### Visual Examples
##### Max-Heap Example:
```
       50
     /    \
    30     20
   /  \   /  \
  15  10 8   16
```
- **Heap Property**:
    - Root (50) $\geq$ Children (30, 20)
    - Node 30 $\geq$ Children (15, 10)
    - Node 20 $\geq$ Children (8, 16)

##### Min-Heap Examples:
```
       5
     /    \
    10     15
   /  \   /  \
  20  25 30  35
```
- **Heap Property**:
    - Root (5) $\leq$ Children (10, 15)
    - Node 10 $\leq$ Children (20, 25)
    - Node 15 $\leq$ Children (30, 35)
---
#### Common Operations on Heaps
- **Insert (Push)**:
    - Add a new element to the heap while maintaining the heap property.
    - Time Complexity: $O(\log n)$
- **Extract-Max / Extract-Min (Pop)**:
    - Remove and return the root element (maximum or minimum).
    - Reorganize the heap to maintain the heap property.
    - Time Complexity: $O(\log n)$
- **Peek**:
    - Access the root element without removing it.
    - Time Complexity: $O(1)$.
- **Heapify**:
    - Convert an arbitrary array into a heap.
    - Time Complexity: $O(n)$.
---
#### Applications of Heaps
- **Priority Queues**:
    - Implemented using heaps to manage elements with priorities efficiently.
- **Heap Sort**:
    - A comparison-based sorting algorithm that uses a heap to sort elements.
    - Time Complexity: $O\left(n\log n\right)$
- **Graph Algorithms**:
    - **Dijkstra's Algorithm**: Uses a min-heap to find the shortes paths.
    - **Prim's Algorithm**: Uses a min-heap to find the minimum spanning tree.
---
#### Study Guidance on Mastering Heap Concepts
To effecitvely understand and master heaps, focus on the following areas:
##### 1. Understand the Fundamentals
- **Tree Structures**:
    - Review binary trees, their properties, and traversal methods.
- **Complete Binary Trees**:
    - Grasp what makes a binary tree complete and how it differs from full and perfect binary trees.
##### 2. Learn Heap Operations in Depth
- **Insertion Algorithm**:
    - Understand how to insert elements and restore the heap property (up-heap or sift-up operation).
- **Deletion Algorithm**:
    - Learn how to remove the root and restore the heap property (down-heap or sift-down operation).
- **Heapify Process**:
    - Study the methods to build a heap from an unordered array.
##### 3. Practice Implementing Heaps
- **Code from Scratch**:
    - Write your own heap implementation in your preferred programming language.
    - Implement both max-heap and min-heap variants.
- **Use Arrays**:
    - Practice representing heaps using arrays and perform operations without explicit tree nodes.
##### 4. Analyze Time Complexities
- **Operation Costs**:
    - Know the time complexities for insertion, deletion, and heap construction.
- **Amortized Analysis**:
    - Understand how operations perform over a sequence of actions.
##### 5. Study Applications
- **Priority Queue**:
    - Implement a priority queue using a heap and solve related problems.
- **Heap Sort Algorithm**:
    - Understand how heap sort works and implement it.
- **Graph Algorithms**:
    - Apply heaps in algorithms like Dijkstra's and Prim's.
##### 6. Visual Learning
- **Draw Heaps**:
    - Visualize heaps by drawing them, especially after each operation.
- **Traces Operations**:
    - Step through insertion and deletion processess manually.
##### 7. Explore Advanced Topics
- **Heap Variants**:
    - Study other heap types like binomial heaps, Fibonacci heaps, and their use cases.
- **Parallel Heaps**:
    - Look into concurrent heap implementations if interested in multi-threaded applications.
##### 8. Implement Standard Library Heaps
- **Language-Specific Heaps**:
    - Use and understand heaps provided by standard libraries (e.g., `std::priority_queue` in C++ or `heapq` in Python).
- **Compare Implementations**:
    - Analyze how standard libraries implement heaps and their performance.
##### 9. Test Your Knowledge
- **Quizzes and Flashcards**:
    - Create or use existing flashcards to memories key properties and algorithms.
- **Explain Concepts**:
    - Write a blog post to reinforce your understanding.
---
#### Key Takeaways
- **Heaps are Complete Binary Trees**:
    - This structural property ensures efficient storage and operations.
- **Heap Order Property**:
    - Determins whether the heap is a max-heap or min-heap, essential for priority management.
- **Efficient Operations**:
    - Heaps allow for efficient insertion and extraction of the highest or lowers priority elements.
- **Practical Applications**:
    - Used in priority queues, sorting algorithms, and graph algorithms, making them a vital concept in computer science.

### (b) Heap can be used to implement the ADT priority queue. Compared with using sorted array, what is the advantage and disadvantage of using heap as the ADT priority queue's implementation?
#### Advantages of Using a Heap
1. **Efficient Insertions**:
    - **Time Complexity**:
        - **Heap**: Inserting a new element into a heap takes $O(\log n)$ time.
        - **Sorted Array**: Inserting into a sorted array requires $O(n)$ time because elements may need to be shifted to maintain order.
    - **Explanation**:
        - In a heap, the new element is added at the end (last position) and then "heapified" up to restore the heap property.
        - In a sorted array, maintaining the sorted order necessitates finding the correct insertion point and shifting subsequent elements.
2. **Efficient for Dynamic Data**:
    - **Use Case**:
        - Heaps are better suited for priority queues where the dataset changes frequently due to insertions and deletions.
    - **Explanation**:
        - The logarithmic time complexity for insertions and deletions makes heaps more adaptable to dynamic datasets.
#### Disadvantages of Using a Heap
1. **Slower Deletion of Highest Priority Element**:
    - **Time Complexity**:
        - **Heap**: Removing the highest priority element (the root) takes $O(\log n)$ time.
        - **Sorted Array**: Deleting the highest priority element takes $O(1)$ time since it's at a known position (either start or end of the array).
    - **Explanation**:
        - In a heap, after removing the root, the last element replaces it, and the heap must be restructured ("heapified down") to maintain the heap property.
        - In a sorted array, the highest prioirty element can be accessed and removed directly without additional restructuring.
2. **Inefficient Order Traversal**:
    - **Time Complexity**:
        - **Heap**: Retrieving all elements in a prioirty order requires $O(n\log n)$ time, as each extraction is $O(\log n)$.
        - **Sorted Array**: Traversing the array yields elements in priority order in $O(n)$ time.
    - **Explanation**:
        - Heaps do not store elements in a fully sorted order, so sequential access does not guarantee priority order.
        - Sorted arrays maintain elements in order, allowing for efficient iteration over all elements by priority.
3. **Higher Constant Factors**:
    - **Overhead**:
        - Heaps may have higher constant factors in their time complexities due to the overhead of maintaining the heap structure.
    - **Explanation:**
        - Operations like heapify involve more computational steps compared to the simple indexing in arrays.
---
#### Summary of Comparison
| Operation | Heap | Sorted Array |
| :--- | :--- | :--- |
| Insertion | $O(\log n)$ | $O(n) |
| Find Highest Prioirty | $O(1)$ | $O(1)$ |
| Delete Highest Priority | $O(\log n)$ | $O(1)$ |
| Iterate in Priority Order | $O(n\log n)$ | $O(n) |

- **Heap Advantages**:
    - Faster insertions for large datasets.
    - Better for dynamic data with frequent insertions and deletions.
- **Heap Disadvantages**:
    - Slower deletions of the highest priority element compared to a sorted array.
    - Less efficient for iterating over all elements in priority order.
---
#### Study Guidance on Mastering Heap and Priority Queue Implementations
##### 1. Analyze Different Implementations of Prioirty Queues
- **Understand Trade-offs**:
    - Compare various data structures used for priority queues, such as heaps, sorted arrays, unsorted arrays, and balanced trees.
    - Analyze their time complexities for different operations to understand when each implementation is most appropriate.
- **Practical Applications**:
    - Explore scenarios where one implementation outperforms others.
    - Consider factors like the frequency of insertions vs. deletions and the need for ordered traversal.
##### 2. Perform Empirical Analysis
- **Implement Both Structures**:
    - Code priority queues using both heaps and sorted arrays.
    - Measure the actual runtime of operations with different dataset sizes.
- **Experiment with Data Patterns**:
    - Test your implementations with various input patterns: (e.g., random, sorted, reverse-sorted data) to observe performance differences.

### (c) In which heap operation do we need to perform the upHeap opration? What is the purpose of performing the upHeap operation?
#### Answer:
##### Heap Operation Requiring upHeap:
- **Insertion Operation**: The **upHeap** operation is performed during the **insertion** of a new element into a heap.
##### Purpose of Performing upHeap:
- **Restoring the Heap Property**: The primary purpose of the upHeap operation is to **restore the heap property** after a new element has been added to the heap.
- **Process**:
    - **Placement of New Element**: When inserting, the new element is initially placed at the **next available position** at the bottom level of the heap (maintaining the complete binary tree structure).
    - **Comparisons and Swapping**:
        - The new element is compared with its **parent node**.
        - If the heap property is violated (e.g., in a max-heap, if the new element is greater than its parent), the two nodes are **swapped**.
        - This process continues **up the tree** until the heap property is satisfied at every level or the root is reached.
- **Outcome**:
    - Ensures that the heap remains a **valid max-heap** or **min-heap**.
    - Maintains the **structural integrity** and **order property** of the heap.
---
#### Detailed Explanation:
##### Insertion and upHeap in a Max-Heap:
1. **Insert the New Element**:
    - Place the new element at the **leftmost available spot** in the bottom level of the heap.
    - This maintains the **complete binary tree** structure.
2. **Perform upHeap(Sift-Up)**:
    - **Compare** the new element with its parent.
    - **Swap** if the new element is **greater** than its parent (for max-heap).
    - **Repeat** this process with the new parent until:
        - The new element is no longer greater than its parent.
        - The root node is reached.
3. **Result**:
    - The heap property is restored.
    - The new element is in the correct position according to the heap order.

##### Visual Example:
**Initial heap Before Insertion**:
```
       50
      /  \
     30  20
    /  \
   15  10
```
**Insert 40:**
- Place 40 at the next available position:
```
        50
      /   \
     30    20
    /  \   /
   15  10 40
```
**Perform upHeap**:
- **Compare 40 with Parent (20):
    - Since 40 > 20, swap them.
```
        50
      /   \
     30    40
    /  \   /
   15  10 20
```
- **Compare 40 with new Parent (50)**:
    - Since 40 < 50, no further action is needed.

**Final Heap After upHeap:**
```
        50
      /   \
     30    40
    /  \   /
   15  10 20
```
---
#### Study Guidance on Mastering upHeap and Heap Operations
##### Focus Areas:
1. **Understand Heap Properties**:
    - **Structural Property**: Recognize that a heap must be a complete binary tree.
    - **Heap Order Property**: Comprehend how the heap property (max-heap or min-heap) dictates parent-child relationships.
2. **Master upHeap Mechanism**:
    - **Algorithm Steps**:
        - Placement of the new element.
        - Iterative comparison and swapping with parent nodes.
    - **Termination Conditions**:
        - The heap property is restored.
        - The root node is reached without further swaps.
3. **Implement Heap Insertion and upHeap**:
    - **Coding Practice**:
        - Write functions to perform heap insertion and the upHeap operation.
        - Test with various input values to see how the heap structure changes.
4. **Trace Examples Manually**:
    - **Step-by-Step Walkthroughs**:
        - Manually insert elements into a heap and perform upHeap.
        - Draw the heap at each step to visualize the changes.
5. **Analyze Time Complexity**:
    - **Insertion Operation**:
        - Understand that the upHeap operation contributes to the $O(\log n)$ time complexity of insertion.
        - Recognize that the height of the heap (logarithmic in terms of the number of nodes) determines the maximum number of swaps.
6. **Differentiate Between upHeap and downHeap**:
    - **upHeap (Sift-Up)**:
        - Used during insertion.
        - Moves a node **up the tree** to restore the heap property.
7. **Relate to Real-World Applications**:
    - **Priority Queues**:
        - See how upHeap is essential for maintaining the correct order in priority queues implemented with heaps.
    - **Algorithms**:
        - Understand the role of heap operations in algorithms like Heap Sort.
---


### (d) Describe the algorithm of the upHeap operation.
#### Answer:
##### Algorithm of the upHeap Operation
The **upHeap** operation (also known as **sift-up** or **bubble-up**) is used in heap data structures during the **insertion** of a new element to restore the heap property. The algorithm moves the newly added element up the heap until the heap property is reestablished.
###### Algorithm Steps:
1. **Insert the New Element**:
    - Place the new element at the next available position in the heap (as the last node in the heap), maintaining the complete binary tree structure.
2. **Initialize Index Variables**:
    - Let `i` be the index of the newly inserted element.
    - Let `parent(i)` be the index of its parent node.
3. **While the Heap Property is Violated**:
    - **Condition**: While `i > 0` (i.e., `i` is not the root node) and the heap property is violated between `i` and `parent(i)`:
        - For a **max-heap**, the heap property is violated if `heap[parent(i)] < heap[i]`.
        - For a **min-heap**, the heap property is violated if `heap[parent(i)] > heap[i]`.
4. **Swap the Element with its Parent**:
    - Swap `heap[i]` with `heap[parent(i)]`.
5. **Update the Index**:
    - Set `i = parent(i)` to continue checking up the tree.
6. **Termination**:
    - The loop terminates when the heap property is satisfied or when the root node is reached.
###### Pseudocode:
```
function upHeap(heap, i):
    while i > 0 and heap[parent(i)] < heap[i]:
        swap(heap[i], heap[parent(i)])
        i = parent(i)
```
- **Note**: The comparison `heap[parent(i)] < heap[i]` is for a max-heap. For a min-heap, the comparison would need to be `heap[parent(i)] > heap[i]`.
###### Parent Index Calculation:
- For a heap stored in an array starting at index 0:
    - `parent(i) = (i - 1) / 2`
---
#### Example of upHeap in a Max-Heap:
##### Initial Heap Array:
| Index | 0 | 1 | 2 | 3 | 4 |
| :--- |  :--- | :--- | :--- | :--- | :--- |
| Value | 50 | 30 | 40 | 10 | 20 |
- **Heap Structure**:
```
        50
       /  \
      30   40
     /  \
    10  20
```
##### Insert new Element `60`:
- **Add `60` at the next available index (5)**

| Index | 0 | 1 | 2 | 3 | 4 | 5 |
| :--- |  :--- | :--- | :--- | :--- | :--- | :--- |
| Value | 50 | 30 | 40 | 10 | 20 | 60 |

- **Heap Structure**:
```
         50
       /   \
      30    40
     /  \   /
    10  20 60
```
##### Perform upHeap:
- **Step 1**: `i = 5`, `parent(i) = (5 -1) / 2 = 2`
    - Compare `heap[2]` (40) with `heap[5]` (60)
    - Since `60 > 40`, swap them.
- **Heap after swap**:

| Index | 0 | 1 | 2 | 3 | 4 | 5 |
| :--- |  :--- | :--- | :--- | :--- | :--- | :--- |
| Value | 50 | 30 | 60 | 10 | 20 | 40 |

- **Heap Structure**:
```
         50
       /   \
      30    60
     /  \   /
    10  20 40
```

- **Step 2**: Update `i = parent(i) = 2`
    - `parent(i) = (2 - 1) / 2 = 0`
    - Compare `heap[0]` (50) with `heap[2]` (60)
    - Since `60 > 50`, swap them.
- **Heap after swap**:

| Index | 0 | 1 | 2 | 3 | 4 | 5 |
| :--- |  :--- | :--- | :--- | :--- | :--- | :--- |
| Value | 60 | 30 | 50 | 10 | 20 | 40 |

- **Heap Structure**:
```
         60
       /   \
      30    50
     /  \   /
    10  20 40
```

- **Step 3**: Update `i = parent(i) = 0`
    - Now `i = 0`, so `i > 0` is false.
    - Terminate the upHeap operation.
##### Result:
- The heap property is restored.
- The new element `60` is correctly positioned at the root of the heap.
---
#### Purpose and Properties of upHeap:
- **Restores Heap Order**:
    - Ensures that after insertion, the heap maintains the max-heap or min-heap property.
- **Efficiency**:
    - The upHeap operation has a time complexity of $O(\log n)$, where $n$ is the number of elements in the heap.
    - This is because the maximum number of swaps is proportional to the height of the heap, which is $\log n$ for a complete binary tree.
---
#### Key Points:
- **When to Use**:
    - upHeap is used during the insertion of a new element into a heap.
- **How it Works**:
    - Moves the newly inserted element up the tree by swapping it with its parent until the heap property is satisfied.
- **Why it's Necessary**:
    - Insertion at the bottom of the heap may violate the heap property.
    - upHeap corrects this by moving the element to its proper position.
---
#### Study Guidance:
1. **Understand the Heap Structure**:
    - Know how heaps are represented as arrays.
    - Understand parent and child index calculations.
2. **Master the upHeap Logic**:
    - Practice writing the upHeap function.
    - Remember the termination conditions.
3. **Work Through Examples**:
    - Manually perform upHeap operations on sample heaps.
    - Visualize the heap at each step.
4. **Time Complexity Analysis**:
    - Understand why upHeap has $O(\log n)$ complexity.
5. **Differentiate Between upHeap and downHeap**:
    - Recognize when each is used and how they differ.
6. **Implement and Test**:
    - Code the heap insertion and upHeap operation.
    - Test with various datasets


### (a) Describe a typical application that uses a hash table as its implementation.
A common application that uses a hash table is the implementation of a **symbol table** in compilers and interpreters.
- **Explanation**:
    - **Symbol Table**:
        - Stores identifiers such as variable names, function names, and object instances.
        - Associates these identifiers with information like scope level, memory location, type, and value.
    - **Usage in Compilers**:
        - During compilation, quick access to symbol information is crucial for tasks like syntax checking, scope resolution, and code generation.
        - Hash tables provide efficient **average-case** $O(1)$ time complexity for insertion, lookup, and deletion operations.

Other applications include:
- **Database Indexing**: Fast retrieval of records using hashed keys.
- **Caching Mechanisms**: Quick storage and retrieval of frequently accessed data.
- **Implementing Dictionaries**: Key-value storage structures in programming languages (e.g., Python's `dict`, Java's `HashMap`).
---
### (b) What is a collision in a hash table? Why is collision a problem in hash table?
- **What is a Collision?**
    - A **collision** occurs when two different keys are mapped to the **same index** in a hash table by the hash function.
- **Why Collisions Are a Problem**:
    - **Data Overwrite Risk**:
        - Without proper handling, a new key-value pair could overwrite an existing one at the same index.
    - **Increased Search Time**:
        - Collisions can degrade the performance of the hash table.
        - Instead of constant time $O(1)$, operations may take longer, approaching $O(n)$ in the worst case.
    - **Retrieval Errors**:
        - If collisions are not correctly managed, retrieving a value using a key may return incorrect data or fail entirely.
---
### (c) Describe the two distinct methods commonly used to solve the collision problem in hash table.
1. **Separate Chaining (Open Hashing)**:
    - **Concept**:
        - Each slot in the hash table array contains a **linked list** or another secondary data structure (e.g., a dynamic array).
    - **How It Works**:
        - When a collision occurs, the new key-value pair is appended to the list at that index.
        - During lookup, the linked list is traversed to find the key.
    - **Advantages**:
        - Simple to implement.
        - The hash table can handle an unlimited number of entries (limited by memory).
    - **Disadvantages**:
        - Potentially increased memory usage due to additional data structures.
        - Lookup time becomes $O(k)$, where $k$ is the number of keys hashed to the same index.
2. **Open Addressing (Closed Hashing)**:
    - **Concept**:
        - All key-value pairs are stored within the hash table array itself.
        - When a collision occurs, a probing sequence is used to find the next available slot.
    - **Common Probing Techniques**:
        - **Linear Probing**:
            - Checks the next slot sequentially: $\text{Index} = (\text{hash(key)} + i) \text{mod table\_size}$, where $i$ increments by 1 each time.
        - **Quadratic Probing**:
            - Uses a quadratic function: $\text{Index} = (\text{hash(key)}+c_1i+c_2i^2) \text{mod table\_size}$.
        - **Double Hashing**:
            - Applies a second hash function: $\text{Index} = (\text{hash}_1(\text{key})+ i \times \text{hash}_2(\text{key}))\text{table\_size}$.
    - **Advantages**:
        - Avoids the overhead of additional data structures.
        - Better cache performance due to data locally.
    - **Disadvantages**:
        - Deletion is more complex (may require special markers like "tombstones").
        - Performance degrades as the table becomes fuller; requires maintaining a low load factor.
---
#### Study Guidance
##### Focus Areas:
1. **Hash Table Fundamentals**:
    - **Hash Functions**:
        - Understand how hash functions map keys to indices.
        - Learn characteristics of good hash functions: uniform distribution and low computation cost.
2. **Collision Handling Techniques**:
    - **Separate Chaining**:
        - Practice implementing hash tables using linked lists at each index.
        - Analyze how collision chains affect performance.
    - **Open Addressing:**
        - Master Different probing methods (linear, quadratic, double hashing).
        - Recognize issues like clustering and how they impact efficiency.
3. **Practical Implementation**:
    - **Coding Exercise**:
        - Write code for both separate chaining and open addressing hash tables.
        - Test with datasets designed to cause collisions.
4. **Performance Analysis**:
    - **Load Factor Impact**:
        - Study how the load factor (number of elements divided by table size) influences performance.
        - Understand strategies for resizing and rehashing.
5. **Applications and Use Cases**:
    - **Real-World Examples**:
        - Explore how hash tables are used in compilaers, databases, and caching.
        - Examine the consequences of poor collision handling in these contexts.

### Given the following C++ function-like algorithm:
```
int fun(int n)
{
    if (n <= 1)
        return 1;
    return n*fun(n-1);
}
```
Write the recurrence equation for the running time of the above algorithm.

#### Recurrence Equation for the Running Time
Let $T(n)$ represent the running time of the function `fun(n)`.

The recurrence relation for $T(n)$ can be expressed as:
1. **Base Case $(n \le 1)$**:
\[
T(n)=c_0    
\]
    - **Explanation**: When $n \le 1$, the function executes the `if` condition and returns `1`. The running time is a constant $c_0$, accounting for the comparison and return statement.
2. **Recursive Case $(n > 1)$**:
\[
T(n)=T(n - 1) + c
\]
    - **Explanation**:
        - **Recursive Call**: The function makes a call to `fun(n - 1)`, which takes times $T(n - 1)$.
        - **Multiplication**: The operation `n * fun(n - 1)` takes constant time $c_1$.
        - **Condition Check**: The `if` statement takes constant time $c_2$.
        - **Total Constant Time**: Combine $c_1$ and $c_2$ into a single constant $c = c_1 + c_2$.

Therefore, the recurrence equation is:
\[
    T(n)=T(n-1)+c, \text{ for } n > 1
\]
with the base case:
\[
    T(1)=c_0
\]

---
##### Solving the Recurrence
To find $T(n)$, we can solve the recurrence by **unrolling** it:
$$
\begin{align}
    T(n) & = T(n-1)+c \nonumber \\
    &= [T(n-2+c)] + c \nonumber \\
    &= T(n-2) + 2c \nonumber \\
    &= [T(n-3)=c]+2c \nonumber \\
    &=T(n-3) + 3c \nonumber \\
    &\vdots \nonumber \\
    &=T(n-k)+kc \nonumber \\
\end{align}
$$
When $k=n-1$:
$$
T(n) = T(1) + (n-1)c
$$
Substitute $T(1) = c_0$:
$$
T(n) = c_0+(n-1)c
$$

---
##### Time Complexity
- The function `fun(n)` has a running time that grows linearly with $n$.
- Therefore:
$$
T(n)=c_0+c(n-1)=Θ(n)
$$
- **Big O Notation**:
$$
T(n) \in O(n)
$$

---
#### Study Guidance
##### Key Focus Areas
1. **Setting Up Recurrence Relations**
    - **Identify Base and Recursive Cases**: Recognize where the function stops recursing (base case) and how the recursive case relates to smaller inputs.
    - **Account for All Operations**: Include the time taken by all operations in the function, both recursive calls and constant-time operations.
2. **Solving Linear Recurrences**:
    - **Unrolling the Recurrence**: Expand the recurrence step by step to find a pattern.
    - **Closed-Form Solution**: Derive a non-recursive expression representing $T(n)$.
3. **Understanding Time Complexity**:
    - **Linear Time**: Recognize that a recurrence of the form $T(n) = T(n -1)+c$ leads to a linear time complexity.
    - **Big O Notation**: Be comfortable expressing the final time complexity using Big O notation.
4. **Analyzing Recursive Algorithms**
    - **Recursive Calls**: Understand how the number of recursive calls affects the overall running time.
    - **Work Done per Call**: Note the operations performed in each call outside the recursion.
---

### An AVL tree that stores integer numbers in its nodes is shown below:
```
          7
        /   \
       5     20
      / \    / \
     3   7  15  25
           /  \
          10  17
```
Inserting numbers in which range (or ranges) would case a double rotation? Show the tree (or trees) after the rotation (You can use x to represent the newly inserted number).

#### Ranges Causing a Double Rotation:
- **First Range**: Inserting numbers **between 9 and 15** (i.e., 9 < x < 15).
    - **Explanation**: These numbers will be inserted into the **right subtree of node 10**, causing an imbalance at node 20 that requires a **Left-Right (LR) rotation**.
- **Second Range**: Inserting numbers between **16 and 19** (i.e., 16 < x < 20).
    - **Explanation**: These numbers will be inserted into the **left subtree of node 17**, leading to an imbalance at node 20 that necessitates a **Left-Right (LR) rotation**.

#### Trees After the Double Rotation**:
##### Example 1: Inserting x between 9 and 14 (e.g., x = 12)
1. **Initial Insertion**:
- Insert **x = 12** into the tree.
- Path: 7 → 20 →  15 → 10 →  **Insert x as the right child of 10**.

**Tree After Insertion**:
```
          7
        /   \
       5     20
      / \    / \
     3   7  15  25
           /  \
          10   17
           \
            x
```
2. **Imbalance Occurs**:
- **Node 20** becomes unbalanced with a balance factor of +2 (left-heavy).
- The imbalance is in the **Left-Right** case:
    - Left child (**15**) is left-heavy due to its right-heavy subtree (**10** with right child x).

3. **Performing Double Rotation (Left-Right Rotation at Node 20):**

**Step 1: Left Rotation on Node 10**
- Rotate left at node 10 to move x up.
```
          7
        /   \
       5     20
      / \    / \
     3   7  15  25
           /  \
          x    17
         / 
        10
```
**Step 2: Rotate right at node 20 to balance the tree
```
          7
        /   \
       5      x
      / \    / \
     3   7  15  20
           /   /  \
          10  17  25
```
**Balanced Tree After Rotation:**
- The AVL tree is now balanced.
- x has become the new parent of nodes 15 and 20.
---
##### Example 2: Inserting x between 16 and 19 (e.g., x = 18)
1. **Initial Insertion**:
- Insert **x = 18** into the tree.
- Path: 7 → 20 → 15 → 17 → **Insert x as the left child of 17**.

**Tree After Insertion:**
```
          7
        /   \
       5     20
      / \    / \
     3   7  15  25
           /  \
          10   17
               /
              x
```
2. **Imbalance Occurs:**
- **Node 20** becomes unbalanced with a balance factor of **+2** (left-heavy).
- The imbalance is a **Left-Right** case:
    - Left child (**15**) is right-heavy due to its left-heavy subtree (17 with left child x).

3. **Performing Double Rotation (Left-Right Rotation at Node 20):**

**Step 1: Right Rotation on Node 17**
- Rotate right at node 17 to move x up.
```
          7
        /   \
       5     20
      / \    / \
     3   7  15  25
           /  \
          10   x
                \
                17
```
**Step 2: Left Rotation on Node 20**
- Rotate left at node 20 to balance the tree.
```
          7
        /   \
       5      x
      / \    / \
     3   7  15  20
           /    / \
          10   17 25
```
**Balanced Tree After Rotation**:
- The AVL tree is now balanced.
- **x** has become the new parent of nodes 15 and 20.
---
#### Explanation of the Double Rotation:
- **Left-Right Rotation**: Occurs when a node's left subtree is right-heavy.
    - **First Rotation (Left or Right)**: Performed on the child to align the heavy subtree.
    - **Second Rotation (Right or Left)**: Performed on the unbalanced node to restore balance.
- In both examples, the imbalance at node 20 requires a Left-Right rotation to maintain the AVL property.
---
#### Key Points:
- **Double Rotations** are needed when a single rotation is insufficient to restore balance.
- **Identifying Ranges**:
    - Insertions causing the heavier subtree to be opposite the imbalance direction necessitate double rotations.
- **Understanding Rotations**:
    - Visualizing the tree before and after rotations helps in mastering AVL tree balancing.

### Given the following recurrence equation that defines $T(N)$ as:
\[
T(N) = \begin{cases}
2, & \text{if } N = 1 \\
T(N-1)+2N & \text{if } N > 1
\end{cases}
\]
Prove, by induction, that $T(N) = N^2+N$

**Base Case $(N=1)$:**
Compute $T(1)$ using both the recurrence and the proposed formula.
1. **Using the Recurrence**:
$$
T(1) = 2
$$
2. **Using the Proposed Formula**:
$$
T(1) =1^2 +1 = 1 + 1 = 2
$$

Since both computations yield $T(1)=2$, the base case holds.

---
**Inductive Hypothesis**
Assume that the formula holds for some integer $k \geq 1$:
$$
T(k) = k^2 + k
$$

---
**Inductive Step $(N=k+1)$:**
We need to show that:
$$
T(k+1)=(k+1)^2+(k+1)
$$
**Compute $T(k+1)$ using the recurrence:**
$$
T(k+1) = T(k)+2(k+1)
$$
**Substitute the inductive hypothesis $T(k) = k^2+k$:**
$$
\begin{align}
T(k+1) & = (k^2+k) + 2(k+1) \nonumber \\
    &= k^2 + k + 2k + 2 \nonumber \\
    &= k^2 + 3k + 2 \nonumber \\
\end{align}
$$
**Simplify the right-hand side of the proposed formula:**
$$
\begin{align}
(k+1)^2 + (k + 1) & = (k^2+2k+1) + k+1 \nonumber \\
    &= k^2 + k + 2k + 2 \nonumber \\
    &= k^2 + 3k + 2 \nonumber \\
\end{align}
$$
**Conclusion:**
$$
T(k+1) = k^2+3k+2 = (k+1)^2 + (k+1)
$$
Thus, $T(k + 1) = (k+1)^2 + (k+1)$.

Since the inductive step holds, by mathematical induction, the formula $T(N) = N^2+N$ is true for all integers $N\ge1$.

---
#### Study Guidance
To master proofs by induction and recurrence relations:
1. **Understand Mathematical Induction**:
    - Recognize the structure base case, inductive hypothesis, and inductive step.
    - Ensure the base case is valid.
    - Clearly show how the inductive step replies on the hypothesis.
2. **Work with Recurrence Relations**:
    - Learn to identify patterns in recursive definitions.
    - Practice solving recurrences by expanding terms and finding closed-form solutions.
3. **Algebraic Manipulation**:
    - Strengthen skills in simplifying expressions.
    - Carefully perform substitutions and simplifications.