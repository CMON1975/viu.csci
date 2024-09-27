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

### (b) Heap can be used to implement the ADT priority queue. Compared with using sorted array, what is the advantage and disadvantage of using heap as the ADT priority queue's implementation?

### (c) In which heap operation do we need to perform the upHeap opration? What is the purpose of performing the upHeap operation?

### (d) Describe the algorithm of the upHeap operation.

### (a) Describe a typical application that uses a hash table as its implementation.

### (b) What is a collision in a hash table? Why is collision a problem in hash table?

### (c) Describe the two distinct methods commonly used to solve the collision problem in hash table.

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

### An AVL tree that stores integer numbers in its nodes is shown below:
```
          7
        /   \
       5    20
      / \   / \
     3   7 15  25
          /  \
         10  17
```
Inserting numbers in which range (or ranges) would case a double rotation? Show the tree (or trees) after the rotation (You can use x to represent the newly inserted number).

### Given the following recurrence equation that defines $T(N)$ as:
\[
T(N) = \begin{cases}
2, & \text{if } N = 1 \\
T(N-1)+2N & \text{if } N > 1
\end{cases}
\]
Prove, by induction, that $T(N) = N^2+N$