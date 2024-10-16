# Cheat Sheet

## First Pass Content Begins
#### Abstract Data Types (ADTs):
1. **Stack:**
    - **Operations:** `push()`, `pop()`, `top()`, `isEmpty()`
    - **Implementation:** Array or Linked List
    - **Applications:** Undo feature in editors, parsing expressions (infix to postfix). DFS in graph algorithms.
2. **Queue:**
    - **Operations:** `enqueue()`, `dequeue()`, `front()`, `isEmpty()`
    - **Implementation:**  Array (circular) or Linked List
    - **Applications:** Scheduling tasks, BFS in graphs, printing jobs.
3. **Priority Queue:**
    - **Operations:** `insert()`, `deleteMax()` or `deleteMin`, `peekMax()` or `peekMin()`
    - **Implementation:** Binary Heap (max or min heap), unsorted/sorted arrays, balanced BSTs.
    - **Applications:** Dijikstra's algorithm, event-driven simulation, task scheduling.
4. **Linked List:**
    - **Operations:** `insert()`, `delete()`, `find()`, `isEmpty()`
    - **Implementation:** Singly or Doubly linked nodes
    - **Applications:** Implementing stacks/queues, adjacency lists in graphs.
5. **Hash Table:**
    - **Operations:** `insert()`, `delete()`, `find()`
    - **Implementation:** Array with hash function (open addressing or separate chaining)
    - **Applications:** Symbol tables, caching, dictionaries.
6. **Binary Search Tree (BST):**
    - **Operations:** `insert()`, `delete()`, `find()`, `inOrderTraversal()`
    - **Implementation:** Nodes with left and right children, organized by key comparison
    - **Applications:** Databases, priority queues, searching algorithms.
7. **AVL Tree (Self-Balancing Binary Search Tree):**
    - **Operations:** `insert()`, `delete()`, `find()`, `rotateLeft()`, `rotateRight()`, `getBalance()`
    - **Implementation:**
        - Maintain balance factor (`-1, 0, +1`) for each node.
        - **Rotations:**
            - **Left Rotation (LL):** When a node becomes unbalanced due to left-heavy insertion.
            - **Right Rotation (RR):** When a node becomes unbalanced due to right-heavy insertion.
            - **Left-Right Rotation (LR):** When the left child is right-heavy.
            - **Right-Left Rotation (RL):** When the right child is left-heavy.
        - **Balance Condition:** For every node, the height difference between left and right subtrees is no more than 1.
    - **Applications:** Database indexing, ordered data retrieval, maintaining balanced search operations.
8. **Heap (Complete Binary Tree):**
    - **Min-Heap:** Root has the smallest element, and each parent node is smaller than its children.
    - **Max-Heap:** Root has the largest element, and each parent node is larger than its children.
    - **Operations:** `insert()`, `deleteMax()` or `deleteMin()`, `peekMax()` or `peekMin()`
    - **Heapify Operations:**
        - **Heapify Up** (for insertions)
        - **Heapify Down** (for deletions)
    - **Applications:** Priority queues, heap sort, efficient merging of sorted arrays.

#### Algorithm Analysis
- **Iterative Analysis:** Count basic operations (comparisons, assignments) as a function of input size $N$.
    - Example: Linear search in an array has O(N) complexity.
- **Recursive Algorithms:**
    - Write the recurrence relation for each problem.
    - **Examples:**
        - Binary search recurrence: $T(N) = T(N/2) + O(1)$
        - Merge sort recurrence: $T(N) = 2T(N/2) + O(N)$
    - **Solving Recurrence Equations:** Use substitution or the Master Theorem.

#### Implementation Notes (C++):
1. **Stack (Array-based):**
```
class Stack {
    int top;
    int arr[MAX_SIZE];
public:
    Stack() { top = - 1}
    void push(int x) { arr[++top] = x; }
    void pop() { --top; }
    int peek() { return arr[top]; }
    bool isEmpty() { return top == -1; }
};
```
2. **Priority Queue (Heap-based):**
```
class MaxHeap {
    vector<int> heap;
public:
    void insert(int val);
    int deleteMax();
private:
    void heapifyUp(int index);
    void heapifyDown(int index);
};
```
3. **Hash Table (Separate Chaining):**
```
class HashTable {
    vector<list<int>> table;
    int hashFunction(int key) { return key % table.size(); }
public:
    void instert(int key);
    bool find(int key);
    void remove(int key);
};
```
4. **AVLTree Rotation:**
```
class AVLTree {
    struct Node {
        int key;
        Node *left, *right;
        int height;
    };

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
    }
};
```
5. **Heap Insert and Heapify:**
```
class MinHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int deleteMin() {
        int root = heap.front();
        heap.front() = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }
};
```
**Typical Applications:**
- **Stack:** Used in algorithms involving backtracking (e.g., maze solving, recursive calls).
- **Queue:** Used in BFS for shortest path and level order traversal of trees.
- **Prioirity Queue:** Optimizing task scheduling and network routing algorithms.
- **Hash Tables:** Efficient lookup in large datasets (e.g., in caches, symbol tables).
- **BST:** Used for efficient searching and sorting (in-order traversal returns sorted data).
- **AVL Tree:** Database indexing, ordered data retrieval, maintinaing balanced search operations.
- **Heap (Complete Binary Tree):** Priority queues, heap sort, efficient merging of sorted arrays.
- **Heap Sort:** Sorting algorithms, selecting the k largest (or smallest) elements from a list.
## First Pass Content Ends

---
## Previous Midterm Exam Content Begins
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
- **First Range**: Inserting numbers **between 9 and 14** (i.e., 9 < x < 15).
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

## Previous Midterm Content Ends

Please sift through this and help me formulate a consise, two-page cheat sheet for my upcoming midterm examination in second-year computer science abstract data types and algorithm design. Pay close attention to the previous midterm question examples, it is highly likely that similar questions will appear on the upcoming test.