### Given an array of size $N$, each element in the array has the following struct data type:

```
struct Data {
    int priority; // the smaller the number, the higher the priority
    string content;
};
```

Write a C++ function to illustrate an algorithm that checks whether all the elements in the array form a heap.
`bool isHeap(Data A[], int N);`

1. **Understand the Heap Data Structure:**
   - **Heap Definition:** A heap is a specialized tree-based data structure that satisfied the _heap property_. In a **min-heap**, for any given node `i` (except the root), the priority of `i` is **not less than** the priority of its parent.
   - **Given Context:** Since "the smaller the number, the higher the priority," we are dealing with a **min-heap** based on the `priority` field.
2. **Array Representation of a Heap:**
   - **Indexing:** heaps are commonly represented using arrays. For a node at index `i` (0-based indexing):
     - **Left Child Index:** `2 * i + 1`
     - **Right Child Index:** `2 * i + 2`
     - **Parent Index:** `(i - 1) / 2` (integer division)

| 0   | 1    | 2     | 3    | 4     | 5    | 6     | 7    | 8     | 9    | 10    |
| --- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | ----- | ---- | ----- |
| i   | left | right |
|     | i    |       | left | right |
|     |      | i     |      |       | left | right |
|     |      |       | i    |       |      |       | left | right |
|     |      |       |      | i     |      |       |      |       | left | right |

3. **Algorithm to Check Heap Property:**

   - **Objective**: Verify that every parent node has a `priority` less than or equal to its children.
   - **Approach:**
     - Iterate over all parent nodes (from index `0` to `(N - 2) / 2`).
     - For each parent node:
       - Check if the left child exists and `A[i].priority <= A[left].priority`.
       - Check if the right child exists and `A[i].prioity <= A[right].priority`.
     - If any of these condtions fail, the array does not represent a heap.

4. **Steps to Prepare:**

   - **Review Heap Operations:**
     - Understand insertion, deletion, and heafiy processes.
     - Familiarize yourself with both min-heaps and max-heaps.
   - **Practice Index Calculations:**
     - Work on problems that require you to calculate parent and child indices.
   - **Write Code by Hand:**
     - Practice writing code without an IDE to simulate exam conditions.

5. \*\*Implementing the Function:
   Here's a step-by-step guide to writing the `isHeap` function:

```
bool isHeap(Data A[], int N) {
    // iterate over all parent nodes
    for (int i = 0; i <= (N - 2) / 2; ++i) {
        int left = 2 * i + 1;   // left child index
        int right = 2 * i + 2;  // right child index

        // check the left child
        if (left < N && A[i].priority > A[left].priority)
            return false;

        // check the right child
        if (right < N && A[i].priority > A[right].priority)
            return false;
    }
    return true;    // all nodes satisfy the heap proprty
}
```

**Explanation:**

- **Loop Condition:** `i <= (N - 2) / 2` ensures we only check parent nodes.
- **Left and Right Children:** Calculated using the heap property formula.
- **Boundary Checks:** Ensure that child indices are within array bounds.

6. **Test Your Understanding:**

   - **Create Test Cases:**
     - An array that is a valid heap.
     - An array that violates the heap property.
   - **Walk Through the Code:**
     - Manually trace the function with your test cases.

7. **Be Ready to Explain:**
   - **Why `(N - 2) /2`?**
     - In a complete binary tree, nodes from index `0` to `(N - 2) / 2` are parent nodes.
   - **Integer Division:**
     - Understand how integer division affects index calculations, especially in the parent index formula.
8. **Practice Similar Problems:**
   - **Heap Operations:**
     - Implement functions like `insert`, `deleteMin`, and `heapify`.
   - **Variations:**
     - Adapt the function for a max-heap.
     - Modifty the structure to use different data types.
9. **Additional Tips:**
   - **Edge Cases:**
     - Consider empty arrays or arrays with a single element.
   - **Time Complexity:**
     - Understand that this function runs in O(N) time.

---

### Each node in a binary tree has the data type `Node` as defined below:

```
struct Node {
    Data *dataptr;
    Node *left;
    Node *right;
};
```

Write a C++ function that performs the AVL tree's single left rotation on a critical node (passed into the function as a parameter).

1. **Understand AVL Trees and Rotations:**

   - **AVL Tree Basics:**
     - An **AVL tree** is a self-balancing binary search tree.
     - For every node, the difference in height between its left and right subtrees (balance factor) is at most 1.
     - When this balance factor becomes grater than 1 or less than -1 after insertions or deletions, the tree needs to be rebalanced using rotations.
   - **Rotations:**
     - **Single Left Rotation (Right-Right Case):** Applied when a node becomes unbalanced due to an insertion in its right subtree's right child.
     - **Single Right Rotation (Left-Left Case):** Applied when a node becomes unbalanced due to an insertion in its left subtree's left child.
     - **Double Rotations:** Combines both left and right rotations for more complex imbalance cases.

2. **Visualize Single Left Rotation:**
   - **Before Rotation:**

```
    x
     \
      y
     / \
    T2  T3
```

- **After Single Left Rotation:**

```
      y
     / \
    x   T3
     \
     T2
```

- **Explanation:**
  - `x` is the critical node (unbalanced node).
  - `y` is `x->right`.
  - `T2` is `y->left`.
  - The goal is to make `y` the new root of the subtree, with `x` as its left child.

3. **Implementing the Function:**
   - **Function Signature:**
     `void singleLeftRotation(Node*& criticalNode);`
   - **Why Use a Reference (`Node*&`):**
     - Passing `Node*&` allows the function to modify the pointer to the critical node itself, which is necessary if the critical node is the root of the subtree or tree.
4. **Step-by-Step Implementation:**

```
void singleLeftRotation(Node*& x) {
    // x is the critical node
    Node* y = x->right;         // y is x's right child
    if (y == nullptr) return;   // cannot perform rotation if y is null

    Node* T2 = y->left;         // T2 is y's left subtree

    // perform rotation
    y->left = x;
    x->right = T2;

    // update the critical node to point to the new root
    x = y;
}
```

**Explanation:**

- **Line by Line:**
  - `Node* y = x->right;`: Assigns `y` to be the right child of `x`.
  - `if (y == nullptr) return;`: Checks if the rotation is possible.
  - `Node* T2 = y->left;`: Saves `y`'s left subtree.
  - `y->left = x;`: Makes `x` the left child of `y`.
  - `x->right = T2;`: Assigns `T2` as the right child of `x`.
  - `x = y;`: Updates `x` to point to `y`, the new root of the subtree.

5. **Steps to Prepare:**
   - **Deep Dive into Rotations:**
     - **Understand the Conditions:** Know when each type of rotation is applied.
     - **Practice Drawing Trees:** Visual diagrams help in understanding how nodes are rearranged.
   - **Review Pointer Manipulation:**
     - **Passing Pointers by Reference:** Essential for modifying tree structures.
     - **Null Checks:** Always ensure pointers are valid before referencing.
   - **Write Code by Hand:**
     - **Simulate Exam Conditions:** Practice coding on paper to get comfortable without and IDE.
   - **Understand Edge Cases:**
     - **Null Pointers:** What if `x` or `y` is `nullptr`?
     - **Single Node Trees:** How does the rotation affect minimal trees?
6. **Test Your Implementation:**
   - **Create Sample Trees:**
     - Build trees that require a single left rotation.
     - Manually perform the rotation to know the expected result.
   - **Trace the Function:**
     - Step through your code with the sample trees.
     - Verify that the nodes are correctly rearranged.
7. **Be Ready to Explain:**
   - **Why Each Step is Necessary:**
     - **Updating `x->right`:** To reattach `T2` after rotation.
     - **Reassigning `x`:** Critical for updating the root of the subtree.
   - **Impact on Balance Factors:**
     - Although not included in the struct, understand how rotations affect node heights and balance factors.
8. **Expand Your Knowledge:**
   - **Implement Other Rotations:**
     - **Single Right Rotation:**
       - Function for the left-left case.
     - **Double Rotations:**
       - Left-Right and Right-Left rotations for more complex imbalances.
   - **Modify the Struct for Practice:**
     - Add a `height` or `balanceFactor` field to `Node` to simulate a full AVL implementation.
9. **Additional Tips:**
   - **Understand Tree Traversal:**
     - Knowing how to traverse and modify trees is crucial.
   - **Memory Management:**
     - Be cautious with dynamic memory if allocation is involved.
   - **Think About Integration:**
     - Consider how this rotation function fits into the larger context of AVL tree insertions and deletions.

---

**Sample Function in Context:**
Let's consider how this function might be used during an insertion that unbalances the tree.

```
void insert(Node*& root, Data* newDatat) {
    // standard BST insertion code
    // ...

    // after insertion, check balance factors
    // if unbalanced, perform rotations
    int balance = getBalance(root);

    // right right case
    if (balance < -1 && newData->priority > root->right->dataptr->priority)
        singleLeftRotation(root);

    // other cases...
}
```

**Note:**

- `getBalance(Node* node)`: A function that calculates the balance factor of a node.
- **Balance Factors:**
  - `balance > 1`: Left-heavy tree.
  - `balance < -1`: Right-heavy tree.

---

**Practice Problems:**

1. **Implement `getBalance(Node* node):`**
   - Write a function to calculate the balance factor of a node.
2. **Write a Function for Single Right Rotation:**
   - Similar to the single left rotation but for the left-left case.
3. **Simulate Insertions:**
   - Insert nodes into an AVL tree and apply rotations when necessary.

---

### List the main operations of a priority queue ADT. For each operation, describe its required parameters and its functionality.

1. **Insert (Enqueue, Add)**

- **Parameters:**
  - **Element:** The data item to be inserted.
  - **Priority:** (Optional if the element inherently has a priority) The priority level associated with the element.
- **Functionality:**
  - Adds a new element to the priority queue with its associated prioirty.
  - The queue rearranges itself (if necessary) to maintain the correct orderering based on priority.
  - In a min-priority queue, elements with lower priority values are served before those with higher values; in a max-priority queue, it's the opposite.

2. **Extract-Min / Extract-Max (Dequeue, Remove)**
   - **Parameters:**
     - None.
   - **Functionality:**
     - Removes and returns the element with the highest prioirty queue from the queue.
       - **Extract-Min** removes the element with the lowest priority value (min-priority queue).
       - **Extract-Max** removes the element with the highest priority value (max-priority queue).
     - The queue reorders itself after removal to maintain the priority structure.
3. **Peek (Find-Min / Find-Max, Top, Front)**
   - **Parameters:**
     - None.
   - **Functionality:**
     - Returns (without removing) the element with the highest priority.
       - **Find-Min** returns the element with the lowest priority value.
       - **Find-Max** returns the element with the highest priority value.
     - Allows you to inspect the next element to be removed without altering the queue.
4. **Decrease-Key / Increase-Key**
   - **Parameters:**
     - **Element Reference:** A reference or handle to the element whose priority needs to be changed.
     - **New Priority:** The updated priority value.
     - **Functionality:**
       - Adjusts the priority of a given element within the queue.
         - **Decrease-Key** is commonly used in min-priority queues.
         - **Increase-Key** is used in max-priority queues.
       - After the update, the queue reorganizes itself to maintain the correct priority order.
5. **Is-Empty**
   - **Parameters:**
     - None.
   - **Functionality:**
     - Checks if the priority queue contains any elements.
     - Returns a boolean value:
       - **True** if the queue is empty.
       - **False** if it contains one or more elements.
6. **Size**
   - **Parameters:**
     - None.
   - **Functionality:**
     - Returns the number of elements currently in the priority queue.
     - Useful for monitoring the queue's length and managing resources.
7. **Clear**
   - **Parameters:**
     - None.
   - **Functionality:**
     - Removes all elements from the priority queue.
     - Resets the queue to its initial empty state.
8. **Merge**
   - **Parameters:**
     - **Another Priority Queue:** The queue to be merged with the current one.
   - **Functionality:**
     - Combines two priority queues into one.
     - All elements from both queues are reorganized to maintain the correct priority order.

---

#### Study Guidance on Mastering Priority Queue Concepts

To effectively understand and master the concepts related to priority queues, consider the following study tips:

1. **Understand the Use-Cases:**
   - Learn where priority queues are applied, such as in Dijkstra's algorithm for shortest paths, Huffman coding, and task scheduling systems.
2. **Implementation Details:**
   - Study different implementations like binary heaps, binomial heaps, and Fibonacci heaps.
   - Understand how each operation works internally and their time complexities.
3. **Practice Coding:**
   - Implement a priority queue in your preferred programming language.
   - Start with a simple array-based implementation, then move on to heap-based implementations.
4. **Visual Learning:**
   - Use diagrams to visualized how elements are added and removed.
   - Trace through simple operations step-by-step.
5. ** Solve Problems:**
   - Work on practice problems from textbooks or online resources.
   - Implement algorithms that utilize priority queues to reinforce your understanding.
6. **Time Complexity Analysis:**
   - For each operation, know the best, average, and worst-case time complexities.
   - Understand how the choice of underlying data structure affects performance.
7. **Ask Questions:**
   - If certain concepts are unclear, don't hesitate to seek help from professors or peers.
   - Participate in study groups or online forums.

---

### Suppose that an unsorted array is used to implement the priority queue. Write a C++ function to illustrate the algorithm that implements the operation of removing the object with the highest priority.

When a priority queue is implemented using an unsorted array, removing the object with the highest priority involves scanning the entire array to find that object and then removing it. Here is a C++ function that illustrates this algorithm:

```
#include <iostream>
#include <stdexcept>

// define the structure for elements in the priority queue
struct Element {
    int value;
    int priority;
};

// function to remove the object with the highest priority from the priority queue
Element removeHighestPriority(Element pq[], int &n) {
    if (n == 0) {
        throw std::out_of_range("Priority queue is empty");
    }

    // assume the first element has the highest priority
    int highestPriorityIndex = 0;

    // loop to find the index of the highest priority element
    for (int i = 1; i < n; ++i) {
        if (pq[i].priority > pq[highestPriorityIndex].priority) {
            highestPriorityIndex = i;
        }
    }

    // store the highest priority element to return it later
    Element highestPriorityElement = pq[highestPriorityIndex];

    // replace the removed element with the last element to fill the gap
    pq[highestPriorityIndex] = ph[n - 1];

    // decrease the size of the priority queue
    --n;

    // return the removed element
    return highestPriorityElement;
}
```

**Explanation:**

1. **Function Parameters:**
   - **`Element pq[]`:** The unsorted array representing the priority queue.
   - **`int &n`:** A reference to the variable that holds the current size of the priority queue.
2. **Check for Empty Queue:**
   - The function first checks if the priority queue is empty by verifying if `n` is zero.
   - If the queue is empty, it throws an exception to indicate that there are no elements to remove.
3. **Find the Highest Priority Element:**
   - Initializes `highestPriorityIndex` to `0`, assuming the first element has the highest priority.
   - Iterates through the array starting from the second element (`i = 1`) to compare priorities.
   - If it finds an element with a higher priority (`pq[i].priority > pq[highestPriorityIndex].priority`), it updates `highestPriorityIndex` to `i`.
4. **Remove the Highest Priority Element:**
   - Stors the highest priority element in `highestPriorityElement` to return it later.
   - Replaces the element at `highestPriorityIndex` with the last element in the array (`pq[n - 1]`).
     - This step avoids the need to shift all subsequent elements, which would be less efficient.
   - Decrements `n` to reflect the new size of the priority queue.
5. **Return the Removed Element:**
   - Returns `highestPriorityElement`, which contains the value and priority of the removed object.

**Usage Example:**

```
int main(){
    // define an unsorted array to act as the priority queue
    Element pq[100];
    int n = 5; // current size of the priority queue

    // initialize the priority queue with some elements
    pq[0] = {10, 2}; // value = 10, priority = 2
    pq[1] = {20, 1}; // value = 20, priority = 1
    pq[2] = {30, 5}; // value = 30, priority = 5
    pq[3] = {40, 3}; // value = 40, priority = 3
    pq[4] = {50, 4}; // value = 50, priority = 4

    // remove elements based on priority and display them
    try {
        while (n > 0) {
            Element e = removeHighestPriority(pq, n);
            std::cout << "Removed element with value: " << e.value
                      << " and priority: " << e.priority << std::endl;
        }
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
```

**Expected Output:**

```
Removed element with value: 30 and priority: 5
Removed element with value: 50 and priority: 4
Removed element with value: 40 and priority: 3
Removed element with value: 10 and priority: 2
Removed element with value: 20 and priority: 1
```

**Explanation of the Output:**

- The elements are removed in order of decreasing priority.
- The elements with the highest priority (`priority = 5`) is removed first.

**Key Points to Rememeber:**

- **Time Complexity:** The removal operation has a time complexity of **O(n)** because it requires scanning all `n` elements to find the one with the highest priority.
- **Space Complexity:** The operation uses **O(1)** additional space since it only uses a few extra variables regardless of the size of the input.
- **Efficiency:** Replacing the removed element with the last element avoids shifting elements, making the removal operation more efficient that if you were to shift all elements after the removed one.

**Study Tips:**

- **Understand the Trade-offs:** Implementing a priority queue with an unsorted array makes insertion **O(1)** (simply add to the end) but makes removal **O(n)** because you need to search for the highest priority element.
- **Error Handling:** Always include checks for edge cases, such as attempting to remove an element from an empty queue.
- **Alternative Implementations:** For better performance on removal, consider using data strucutres like heaps, which can reduse the time complexity to **O(log n)**.
- **Practice:** Try modifying the function to handle different scenarios, such as implementing a min-priority queue (where lower numbers indicate higher priority) or handling duplicate priorities.

---

### Is it true that the best performance of all sorting algorithms is O(n log n) where n represents the number of elements to be sorted and may be a very large number? Justify your answer clearly and briefly. You can use examples in your justification.

**No, it is not true that the best performance of all sorting algorithms is $O(n \log n)$.** While comparison-based sorting algorithms have a lower bound of $Ω(n \log n)$ for their time complexity, there exist non-comparison-based sorting algorithms that can sort data in linear time $O(n)$ under certain conditions.

#### Justification:

1. **Comparison-Based Sorting Algorithms:**

- **Lower Bound of $Ω(n \log n)$:**
  - In comparison-based sorting, elements are ordered by comparing them using a binary relation (e.g., less than, greater than).
  - Decision tree models show that any comparison-based sorting algorithm requires at least $\log_2(n!)$ comparisons in the worst case.
  - Stirling's approximation leads to $\log_2(n!) \approx n\log_2 n - n$, establishing a lower bound of $Ω(n \log n)$.
- **Examples:**
  - **Merge Sort:** Consistently achieves $O(n \log n)$ time complexity in all cases.
  - **Heap Sort:** Also guarantees $O(n \log n)$ time complexity.
  - **Quick Sort:** Has an average-case time complexity of $O(n \log n)$ but a worst-case of $O(n^2)$.

2. **Non-Comparison-Based Sorting Algorithsm:**

   - **Possibility of Linear Time $O(n)$:**
     - These algorithms do not sort by comparing elements but use other properties like keys' digits or counts.
     - They can achieve $O(n)$ time complexity when certain conditions about the input are met, such as a limited range of integer keys.

- **Examples:**
  - **Counting Sort:**
    - **Time Complexity:** $O(n+k)$, where $k$ is the range of input values.
    - **How it Works:** Counts the occurences of each value and calculates positions based on cumulative counts.
    - **Use Case:** Efficient when $k=O(n)$, meaning the range of input values is not significantly larger than the number of elements.
  - **Radix Sort:**
    - **Time Complexity:** $O(n \times d)$, where $d$ is the number of digits.
    - **How it Works:** Processes each digit of the numbers, using a stable sort like Counting Sort at each digit level.
    - **Use Case:** Effective for numbers with a fixed number of digits (e.g., sorting 32-bit integers).
  - **Bucket Sort:**
    - **Time Complexity:** Average-case $O(n)$ when input is uniformly distributed.
    - **How It Works:** Distributes elements into buckets representing subranges and sorts each bucket individually.
    - **Use Case:** Ideal for uniformly distributed floating-point numbers in a known range.

#### Example Illustrating Linear Time Sorting:

**Scenario:** Sorting an array of one millon $(n = 1,000,000)$ integers ranging from 0 to 9999 $(k = 10,000)$.

- **Using Counting Sort:**
  - **Time Complexity:** $O(n + k) = O(1,000,000 + 10,000) = O(1,010,00)$.
  - **Performance:** Linear time because $k$ is relatively small and manageable.
  - **Result:** Slower sorting due to the $n \log n$ factor.
    **Conclusion from Example:**
- **Counting Sort** significantly outperforms comparison-based algorithms in this scenario due to its linear time complexity.
- **Applicability:** The advantage is evident when the range of input values $k$ is not excessively large compared to $n$.

#### Key Points to Remember:

- **Comparison-Based Sorting Limitations:**
  - **Lower Bound:** Cannot perform better than $O(n log n)$ in the general case.
  - **Reason:** Based on the fundamental limit of decision trees for comparisons.
- **Non-Comparison-Based Sorting Advantages:**
  - **Linear Time Possibility:** Achieve $O(n)$ time complexity under specific conditions.
  - **Conditions Required:** Limited range of keys, fixed-length digits, or uniform distribution.
  - **Not Universal:** These algorithms are not universally applicable to all sorting problems.
- **Understanding Data Characteristics:**
  - **Data Range and Distribution Matter:** Knowing the properties of the input data allows for choosing the most efficient sorting algorithm.
  - **Example:** Radix Sort is efficient for sorting strings of the same length or fixed-size integers.

#### Final Thoughts:

- **Best Performance Depends on Algorithm and Data:**
  - The "best" performance is context-dependent.
  - For general-purpose sorting without assumptions about the data, $O(n \log n)$ is the best achievable.
  - With additional information, better performance is possible.
- **Practical Implications:**
  - **Algorithm Selection:** Choose the sorting algorithm that best fits the data characteristics.
  - **Efficiency Gains:** Significant time savings can be achieved with the appropriate algorithm.

#### Summary:

While $O(n \log n)$ is the lower bound for comparison-based sorting algorithms, it is **not** the abosolute best performance for all sorting algorithms. **Non-comparison-based algorithms** like Counting Sort and Radix Sort can sort data in **linear time** $O(n)$ under certain conditions related to the input data's properties.

#### Study Tip:

- **Explore Different Sorting Algorithms:**
  - **Understand Their Mechanisms:** Learn how and why non-comparison-based algorithms can achieve linear time.
  - **Know Their Limitations:** Be aware of the conditions required for their optimal performance.
  - **Practice Implementing Them:** Reinforce understanding by coding these algorithms and testing them with various datasets.

### The private data fields of a class **HashTable** are shown below:

```
class HashTable {
    public:
        ...
    private:
        enum Status {Empty, Occupied, Removed};
        int h(int k); // hash function
        struct Cell {
            int key;
            string element;
            Status status;
        };
        Cell data[79];
        int size;
};

```
And the method `insert` of the `HashTable` class is shown below:
```
void HashTable::insert(int k, string e)
{
    if (size >= 79)
        throw "Hash Table Full";
    
    int position = h(k);
    while (data[position].status == Occupied)
        position = (position + 1) % 79;

    data[position].key = k;
    data[position].element = e;
    data[position].status = Occupied;
    size++;
}
```
Write a C++ function that implements the method `lookup` of the `HashTable` class.

Below is the implementation of the `lookup` method for the `HashTable` class. This method searches for a given key `k` in the hash table and returns the associated element if found. If the key is not found, it throws an exception indicating that the key does not exist in the hash table.
```
#include <string>
#include <stdexcept>

class HashTable {
    public:
        // other public methods...
        std::string lookup(int k);
    private:
        enum Status {Empty, Occupied, Removed};
        int h(int k); // hash function
        struct Cell {
            int key;
            string element;
            Status status;
        };
        Cell data[79];
        int size;
};

// implementation of the lookup method
std::string HashTable::lookup(int k) {
    int position = h(k);
    int start = position; // remember the starting position to avoid infinite loops

    // loop until we find an empty slot or return to the starting position
    while (data[position].status != Empty) {
        // check if the current cell is occupied and has the matching key
        if (data[position].status == Occupied && data[position].key == k) {
            return data[position].element; // key found, return the associated element
        }
        // move to the next position using linear probing
        position = (position + 1) % 79;

        // if we've looped back to the starting position, the key is not in the table
        if (position == start) {
            break;
        }
    }

    // if the key was not found, throw an exception
    throw std::runtime_error("Key not found in the hash table.");
}
```
#### **Explanation:**
1. **Function Signature:**
`std::string HashTable::lookup(int k)`
- The `lookup` method takes an integer `k` as a parameter.
- It returns the `std::string` element associated with the key.
- If the key is not found, it throws a `std::runtime_error` exception.
2. **Hash Function and Initial Position:**
```
int position = h(k);
int start = position;
```
- Computes the initial hash position for the key using the hash function `h(k)`. 
- Stores the starting position in `start` to detect if we've looped around the entire table.
3. **Probing Loop:**
```
while (data[position].status != Empty) {
    // ...
}
```
- Continues probing as long as the current cell is not `Empty`.
- An `Empty` status indicates that the key is not present in the table beyond this point.
4. **Key Comparison:**
```
if (data[position].status == Occupied && data[position].key == k) {
    return data[position].element;
}
```
- Checks if the current cell is `Occupied` and the keys match.
- If so, returns the associated element, indicating a successful lookup.
5. **Linear Probing:**
`position = (position + 1) % 79;`
- Moves to the next position using linear probing.
- Uses modulo operation to wrap around to the beginning if the end of the array is reached.
6. **Loop Termination Condition:**
```
if (position == start) {
    break;
}
```
- If we return to the starting position, it means we've traversed the entire table without finding the key.
- Breaks out of the loop to proceed to exception handling.
7. **Exception Handling:
`throw std::runtime_error("Key not found in the hash table.");
- Throws an exception indicating that the key was not found.
- Using `std::runtime_error` provides more specific exception handling.

#### Key Points:
- **Linear Probing:**
    - The hash table uses linear probing to resolve collisions.
    - Probes sequentially to the next index when a collision occurs.
- **Status Enumeration:**
    - **Empty:** The cell has never been used.
    - **Occupied:** The cell contains a valid key-element pair.
    - **Removed:** The cell previously held a key-element pair but has since been deleted.
- **Handling Removed Cells:**
    - The lookup method skips over cells marked as `Removed`.
    - This ensure that deleted keys do not interfere with the probing sequence.
- **Avoiding Infinite Loops:**
    - By keeping track of the starting position, we prevent infinite loops in a full table.
    - If we return to the starting position, it indicates that the key does not exist in the table.
- **Exception Throwing:**
    - Consisten with the `insert` method, which throws exceptions when errors occur.
    - Provides clear feedback to the caller about the failure of the operation.

#### Usage Example:
```
int main(){
    HashTable ht;
    // assume the hash function h(k) and other methods are properly defined

    // insert some key-element pairs into the hash table
    ht.insert(10, "Apple");
    ht.insert(20, "Banana");
    ht.insert(30, "Cherry");

    try {
        // lookup existing keys
        std::string fruit1 = ht.lookup(20);
        std::cout << "Key 20 corresponds to: " << fruit1 << std::endl;

        // attempt to lookup a non-existing key
        std::string fruit2 = ht.lookup(40); // this will throw an exception
        std::cout << "Key 40 corresponds to: " << fruit2 << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
```
**Expected Output:**
```
Key 20 corresponds to: Banana
Key not found in the hash table.
```

#### Additional Notes:
- **Consistency with Insert Method:**
    - The `lookup` method is consistent with the `insert` method in terms of collision resolution and probing sequence.
    - Ensure that keys are located using the same path they were inserted.
- **Performance Considerations:**
    - In the worst case, the `lookup` operation may need to inspect every cell in the hash table, resulting in $O(n)$ time complexity.
    - Proper hash function design and load factor management can help optimize performance.
- **Extensibility:**
    - If needed, you can modify the method to return a boolean indicating success or failure, and pass the found element via a reference parameter.

#### Study Tips:
- **Understand Open Addressing:**
    - Grasp how linear probing workds in open-addressed hash tables.
    - Know the implications of different cell status on the probing process.
- **Exception Handling:**
    - Be comfortable with using exceptions to handle error conditions in C++.
    - Ensure that exceptions are used judiciously to signal unexpected conditions.
- **Edge Cases:**
    - Consider scenarios where the table is full or nearly full.
    - Think about how deletions (cells marked as `Removed`) affect the lookup process.
- **Testing:**
    - Test the `lookup` method thoroughly with various cases, including:
        - Looking up keys that exist.
        - Looking up keys that have been removed.
        - Looking up keys that were never inserted.
        - Handling an empty hash table.
---
### On an input of size N, where N > 1, an algorithm solves a problem recursively by solving three (3) sub-problems of each of the size [N/3], and then "combining" them to form the final result in a further N log N steps. A problem of size 1 takes 5 steps to solve in this algorithm. The full runtime of the algorithms is reflected by the number of steps required.

#### (a) Present the recurrence equation T(N) for the runtime of the above described algorithm.
**Given:**
- The algorithm solves a problem of size $N$ recursively by:
    1. **Dividing:** It splits the problem into **three subproblems**, each of size $N/3$.
    2. **Conqueriing:** Solves each subproblem recursively.
    3. **Combining:** Combines the solutions of the subproblems in $N \log N$ steps.
- **Base Case:** A problem of size 1 takes 5 steps to solve.

**Recurrence Equation:**
The total runtime $T(N)$ can be expressed as the sum of:
1. **The time to solve the three subproblems:** Each of size $N/3$, so the total time is $3 \times T(N/3)$.
2. **The time to combine the solutions:** Which is $N \log N$ steps.

Therefore, the recurrence relation is:
\[
T(N) = \begin{cases}
5, & \text{if } N = 1 \\
3 \times T\left(\frac{N}{3}\right) + N \log N, & \text{if } N > 1
\end{cases}
\]

#### (b) Solve this recurrence equation, i.e., find a non-recurrence function g(N) such that $T(N) ∈ Θ(g(N))$.
To solve the recurrence:
\[
T(N) = 3 \times T\left(\frac{N}{3}\right) + N \log N
\]
We will use the **Master Theorem**, which provides a method to determine the time complexity of recurrence relations of the form:
\[
    T(N) = a \times T\left(\frac{N}{b}\right) + f(N)
\]
Where:
- $a \geq 1$: Number of subproblems.
- $b > 1$: Factor by which the subproblem size is reduced.
- $f(N)$: Cost of the work done outside the recursive calls (e.g., combining the solutions).

**Identify the Parameters:**
1. $a = 3$
2. $b = 3$
3. $f(N) = N \log N$

Compute $\log_ba$:
\[
    \log_ba= \log_33 = 1
\]
Compute $n^{\log_ba}$:
\[
    ^{\log_ba} = n^1 = n
\]

**Compare $f(N)$ with $n^{\log_ba}$:**
- $f(N) = N \log N = n \log n$
- $n^{\log_ba} = n$

So, $f(N) = n \log n = n^{\log_ba} \times \log n$
This means $f(N)$ is **polynomially larger** than $n^{\log_ba}$ by a factor of $\log n$.

**Apply the Master Theorem (Case 2):**
The Master Theorem defines three cases:
1. **Case 1:** If $f(N) = O(n^{\log_ba-𝜖}) \text{ for some } 𝜖 > 0, \text{ then } T(N)∈Θ(n^{\log_ba}) $.
2. **Case 2:** If $f(N) = Θ(n^{\log_ba}\log^kn) \text{ for } k \geq 0, \text{ then } T(N) ∈Θ(n^{\log_ba}\log^{k+1}n)$.
3. **Case 3:** If $f(N)=Ω(n^{\log_ba+𝜖}) \text{ for some } ϵ > 0, \text{ and if } a \times f\left( \frac{N}{b}\right) \leq c \times f(N) \text{ for some } c < 1 \text{ and sufficiently large }N, \text{ then } T(N) ∈Θ(f(N))$

**Our Situation:**
- $f(N) = n^{\log_ba}\log n$
- So, $f(N) = Θ(n^{\log_ba} \log n)$

Therefore, **Case 2 applies with $k = 1$.

**Conclusion Using Case 2:**
\[
T(N)∈Θ\left(n^{\log_ba}log^{k+1}n\right)
\]
Substitute $\log_ba=1$ and $k=1$:
\[
T(N)∈Θ\left(n^1 \log^{1+1}n\right)=Θ(n \log^2n)
\]

**Final Answer:**
The non-recursive function $g(N) is:
\[
g(N) = n \log^2n    
\]
Thus:
\[
T(N) ∈Θ(n\log^2n)
\]
#### Intuitive Explanation:
- **At Each Level:**
    - The total cost is proportional to $N$ times the log of the subproblem size.
- **Total Levels:** There are $\log_3N$ levels due to to the recursive division by 3.
- **Accumulated Cost:**
    - The accumulated cost over all levels involves summing logarithmic terms, leading to a quadratic logarithmic term $\log^2N$.

#### Conclusion:
The algorithm has a time complexity of $Θ(N\log^2N)$, which means the runtime grows proportionally to $N$ times the square of the logarithm of $N$.

#### Key Takeaways:
- **Master Theorem Application:**
    - Identifying the correct case in the Master Theoreem is crucial for solving recurrences.
- **Understanding $f(N)$:**
    - Comparing $f(N)$ to $n^{\log_ba}$ determines which case applies.
- **Non-Recursive Solution:**
    - Providing a closed-form function $g(N)$ helps in understanding the algorithm's efficiency.

#### Study Tips:
1. **Understand Recurrence Relations**
    - **Basics of Recurrence Relations:**
        - Recognize that recurrence relations express the runtime of recursive algorithms in terms of smaller input sizes.
        - Start by studying simple recurrences and progressively tackle more complex ones.
    - **Common Forms:**
        - Familiarize yourself with common recurrence patterns such as linear, divide-and-conquer, and exponential recurrences.
        - Pracitce writing recurrence relations from recursive algorithms.
2. **Master the Master Theorem**
    - **Learn the Three Cases:**
        - **Case 1:** $f(n) = O\left(n^{\log_ba-ϵ}\right)$
        - **Case 2:** $f(n) = Θ\left(n^{\log_ba}\log^kn\right)$
        - **Case 3:** $f(n) = Ω\left(n^{log_ba+ϵ}\right)$
    - **Parameters Identification:**
        - Practice identifying the parameters $a$, $b$, and $f(n)$ in different recurrence relations.
        - Understand how these parameters influence which case of the Master Theorem applies.
    - **Limitations:**
        - Be aware of when the Master Theorem cannot be applied (e.g., when $f(n)$ is not polynomially related to $n^{\log_ba}$).
3. **Practice Solving Recurrences**
    - **Work Throught Examples:**
        - Solve a variety of recurrence relations using the Master Theorem.
        - Start with textbook examples and then attempt more challenging problems.
    - **Alternative Methods:**
        - **Recursion Tree Method:** Visualize the recurrence as a tree to estimate the total cost.
        - **Iterations/Substitution Method:** Expand the recurrence step by step to identify patterns and derive a closed-form solution.
    - **Verify Solutions:**
        - Check your answers by plugging in small values of $N$ to see if the recurrence and your solution aggree.
4. **Strengthen Mathematical Foundations**
    - **Logarithms and Exponents:**
        - Review properties of logarithms, such as change of base, product, quotient, and power rules.
        - Understand how to manipulate logarithmic expressions.
    - **Big O, Theta, and Omega Notations:**
        - Clearly understand the definitions and differences between $O$, $Θ$, and $Ω$ notations.
        - Practice classifying functions based on their growth rates.
5. **Study Algorithm Design Techniques**
    - **Divide and Conquer:**
        - Understand how divide-and-conquer algorithms work and how they lead to specific recurrence relations.
        - Study classic algorithms like Merge Sort and Quick Sort.
    - **Algorithm Efficiency:**
        - Learn how different algorithmic strategies affect time complexity.
        - Analyze how combining steps contribute to the overall runtime.
6. **Apply Concepts to Real Algorithms**
    - **Case Studies:**
        - Examine how recurrence relations are derived from actual algorithms.
        - For example, analyze the recurrence for Merge Sort: $T(n) = 2T(n/2) + O(n).$
    - **Modify Algorithms:**
        - Experiment by changing parameters in algorithms (e.g., number of subproblmes, size reduction factor) and observe how the recurrence and complexity change.
7. **Practice Regularly**
    - **Problem Sets:**
        - Work on problems from your textbook or online platforms like LeetCode, HackerRank, and GeeksforGeeks.
    - **Timed Practice:**
        - Simulate exam conditions by solving problems within a time limit.
    - **Consistent Review:**
        - Regularly revisit challenging concepts to reinforce your understanding.

#### Additional Tips
- **Understand the Intuition:**
    - Don't just memorie forumlas; strive to understand the reasoning behind them.
- **Stay Organized:**
    - Keep a notebook summerizing key concepts, formulas, and problem-sovling stragegies.
- **Stay Curious:**
    - Explore how these concepts apply beyond your coursework, such as in real-world applications and advanced studies.

### Assuming that as set of integer numbers are stored in a general binary tree, one number in each node of the tree. When the tree is traversed, the numbers are printed out in the following order in each traversal:
- In pre-order traversal: 5, 1, 8, 6, 2, 3, 9, 4, 7
- In post-order traversal: 6, 2, 8, 1, 4, 9, 7, 3, 5
- In in-order traversal: 1, 6, 8, 2, 5, 9, 4, 3, 7

Draw a general binary tree that is consistent with the above provided information. Your tree should clearly show the integer numbers stored in each node. (Note that the values of the numbers don't have any significant meanings).

#### Reconstructing the Binary Tree:
We will use the pre-order and in-order traversals to reconstruct the tree becaue the pre-order traversal provides information about the root nades, and the in-order traversal helps us identify the left and right subtrees.
##### Step 1:Identify the Root Node
- Pre-order Traversal: The first element is always the root.
    - Root: 5.
##### Step 2: Split the In-order Traversal
- In-order Traversal: 1, 6, 8, 2, 5, 9, 4, 3, 7
    - Elements before 5 are in the left subtree: 1, 6, 8, 2
    - Elements after 5 are in the right subtree: 9, 4, 3, 7
##### Step 3: Split the Pre-order Traversal
- Remaining Pre-order Traversal after root: 1, 8, 6, 2, 3, 9, 4, 7
- Left Subtree Size: 4 elements (from in-order left subtree)
    - Left Subtree Pre-order: 1, 8, 6, 2
- Right Subtree Pre-order: 3, 9, 4, 7
##### Step 4: Reconstruct the Left Subtree of Root (Node 5)
**4.1 Root of Left Subtree**
- Pre-order: 1, 8, 6, 2
    - Root: 1

**4.2 Split In-order Traversal for Node 1**
- In-order Left of 1: None (no elements before 1)
- In-order Right of 1: 6, 8, 2

**4.3 Split Pre-order Traversal for Node 1**
- Left Subtree Pre-order: None
- Right Subtree Pre-order: 8, 6, 2

**4.4 Reconstruct th Right Subtree of Node 1**

4.4.1 Root of Right Subtree of Node 1
- Pre-order: 8, 6, 2
    - Root: 8

4.4.2 Split In-order Traversal for Node 8
- In-order Left of 8: 6 (elements before 8)
- In-order Right of 8: 2 (elements after 8)

4.4.3 Split Pre-Order Traversal for Node 8
- Left Subtree Pre-order: 6
- Right Subtree Pre-order: 2

4.4.4 Reconstruct Left and Right Subtrees of Node 8
- Left Child of Node 8: 6 (from pre-order and in-order)
- Right Child of Node 8: 2 (from pre-order and in-order)

##### Step 5: Reconstruct the Right Subtree of Root (Node 5)
**5.1 Root of Right Subtree**
- Pre-order: 3, 9, 4, 7
    - Root: 3

**5.2 Split In-order Traversal for Node 3**
- In-order Left of 3: 9, 4 (elements before 3)
- In-order Right of 3: 7 (elements after 3)

**5.3 Split Pre-order Traversal for Node 3**
- Left Subtree Pre-order: 9, 4 (size matches in-order left)
- Right Subtree Pre-order: 7

**5.4 Reconstruct the Left Subtree of Node 3**
5.4.1 Root of Left Subtree of Node 3
- Pre-order: 9, 4
    - Root: 9

5.4.2 Split In-order Traversal for Node 9
- In-order Left of 9: None
- In-order Right of 9: 4

5.4.3 Split Pre-order Traversal for Node 9
- Left Subtree Pre-order: None
- Right Subtree Pre-order: 4

5.4.4 Reconstruct Right Subtree of Node 9
- Right Child of Node 9: 4

5.5 Reconstruct the Right Subtree of Node 3
- Right Child of Node 3: 7

#### Final Binary Tree Structure:
```
          5
        /   \
       1     3
        \   / \
         8 9   7
        / \  \
       6   2  4
```
- **Node 5** is the root.
- **Left Subtree of 5:**
    - **Node 1** is the left child.
        - **Right Child of 1:** Node 8
            - **Left Child of 8:** Node 6
            - **Right Child of 8:** Node 2
- **Right Subtree of 5:**
    - **Node 3** is the right child.
        - **Left Child of 3:** Node 9
            - **Right Child of 9:** Node 4
        - **Right Child of 3:** Node 7
---
#### Study Tips for Tree Reconstruction
1. **Understand Tree Traversals:**
    - Pre-order (Root, Left, Right): Useful for identifying root nodes.
    - In-order (Left, Root, Right): Helps in determining the left and right subtrees.
    - Post-order (left, Right, Root): Can be used to verify the correctness of the reconstructed tree.
2. **Steps to Reconstruct a Binary Tree:**
    - **Identify the Root:**
        - Use the pre-order traversal to find the root node.
    - **Divide In-order Traversal:**
        - Split the in-order traversal into left and right subtrees based on the root.
    - **Divide Pre-order Traversal:**
        - Determine the pre-order sequences for left and right subtrees.
    - **Recursive Reconstruction:**
        - Apply the same steps recursively to reconstruct each subtree.
3. **Practice with Examples:**
    - Work on various problems with different traversal combinations (e.g., in-order and post-order).
    - Verify your reconstructed trees by performing traversals and comparing them with the given sequences.
4. **Visualize the Process:**
    - Draw the tree diagrams step by step.
    - Use placeholders for nodes if necessary to keep track of the structure.
5. **Understand Edge Cases:**
    - **No Left Subtree or Right Subtree:**
        - Be cautious when a node has only one child.
    - **Duplicate Values:**
        - Although not in this problem, be aware of how duplicates might affect the reconstructions.
6. **Reinforce Concepts:**
    - Review the properties of binary trees and traversal methods.
    - Understand how recursive functions can be used to implement tree traversals.