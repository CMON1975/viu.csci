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
