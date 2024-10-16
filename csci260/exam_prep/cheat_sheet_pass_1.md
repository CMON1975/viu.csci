## 1. Abstract Data Types (ADTs)

#### Stack

- **Operations:** `push(x)`, `pop()`, `top()`, `isEmpty()`

- **LIFO** (Last-In, First-Out)

- **Implementations:** Array, Linked List

- **Applications:** Expression evaluation, function call management.

#### Queue

- **Operations:** `enqueue(x)`, `dequeue()`, `front()`, `isEmpty()`

- **FIFO** (First-In, First-Out)

- **Implementations:** Array (circular), Linked List

- **Applications:** Scheduling, BFS traversal

#### Priority Queue

- **Operations:**
  
  - `insert(element, priority)`
  
  - `extractMin()/extractMax()`
  
  - `peekMin()/peekMax()`

- **Implementations:**
  
  - **Heap** (Binary Heap)
    
    - **Min-Heap:** parent $\le$ children
    
    - **Max-Heap:** parent $\ge$ children
  
  - **Unsorted/Sorted Arrays**

- **Applications:** Dijkstra's algorithm, task scheduling

#### Linked List

- **Operations:** `insert(x)`, `delete(x)`, `find(x)`

- **Types:** Singly, Doubly linked

- **Applications:** Implement stacks/queues, adjacency lists

#### Hash Table

- **Operations:** `insert(key, value)`, `delete(key)`, `find(key)`

- **Collision Resolution:**
  
  - **Separate Chaining:** Linked lists at each index
  
  - **Open Addressing:** 
    
    - **Linear Probing**
    
    - **Quadratic Probing**
    
    - **Double Hashing**

- **Applications:** Symbol tables, dictionaries, caching

#### Binary Search Tree (BST)

- **Operations:** `insert(key)`, `delete(key)`, `find(key)`, `inOrderTraversal()`

- **Property:** Left subtree $\le$ node < right subtree

- **Applications:** Efficient searching, sorted data retrieval

#### AVL Tree

- **Self-balancing BST**

- **Balance Factor:** height(left) - height(right) $\in$ {-1, 0, +1}

- **Rotations:**
  
  - **Single Rotations:** Left (LL), Right (RR)
  
  - **Double Rotations:** Left-Right (LR), Right-Left (RL)

- **Applications:** Maintain O(log n) search time

#### Heap (Binary Heap)

- **Complete binary tree**

- **Heap Property:**
  
  - **Min-Heap:** parent $\le$ children
  
  - **Max-Heap:** parent $\ge$ children

- **Operations:**
  
  - `insert(x)` with **upHeap**
  
  - `extractMin()/extractMax()` with **downHeap**
  
  - `heapify()` to build heap from array

- **Applications:** Priority queues, Heap Sort

---

## 2. Algorithm Analysis

#### Big O Notation

- **Common Complexities:** $O(1), O(\log n), O(n), O(n\log n), O(n^2)$

#### Master Theorem

For recurrences: $T(n) = aT(\frac{n}{b})+ f(n)$

- **Case 1:** If $f(n) = O(n^{\log_ba-\epsilon})\Rightarrow T(n)=\Theta(n^{\log_ba})$

- **Case 2:** If $f(n)=\Theta(n^{\log_ba}\log^kn)\Rightarrow T(n)=\Theta(n^{\log_ba}log^{k+1}n)$

- **Case 3:** If $f(n)=\Omega(n^{\log_ba+\epsilon})$ and $af(\frac{n}{b})\le cf(n)$ for $c<1\Rightarrow T(n)=\Theta(f(n))$

---

## 3. Implementation Notes (C++)

##### Heap Implementation (Min-Heap)

```cpp
void heapifyUp(int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap[index] < heap[parent]) {
        swap(heap[index], heap[parent]);
        heapifyUp(parent);
    }
}

void insert(int val) {
    heap.push_back(val);
    heapifyUp(heap.size() - 1);
}
```

##### AVL Tree Single Left Rotation

```cpp
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    // update heights if necessary
    return y;
}
```

##### Hash Table Lookup with Open Addressing

```cpp
string HashTable::lookup(int k) {
    int position = h(k);
    int start = position;
    while (data[position].status != Empty) {
        if (data[position].status == Occupied && data[positio].key == k) {
            return data[position].element;
        }
        position = (position + 1) % table_size;
        if (position == start) break;
    }
    throw "Key not found";
}
```

---

## 4. Key Concepts

##### Heap Properties

- **Complete Binary Tree:** All levels filled except possibly the last, filled left to right.

- **Heap Property:** In a min-heap, parent $\le$ children; in a max-heap, parent $\ge$ children.

- **Array Representation:**
  
  - **Parent:** (i - 1) / 2
  
  - **Left Child:** 2i + 1
  
  - **Right Child:** 2i + 2

##### Heap Oprations

- **Insert:**
  
  - Add element at end.
  
  - Perform **upHeap** to restore heap property.

- **ExtractMin/ExtractMax:**
  
  - Replace root with last element.   
  
  - Perform **downHeap** to restore heap property.

- **upHeap Algorithm:**
  
  - While node < parent (min-heap), swap with parent.

- **downHeap Algorithm:**
  
  - While node > child (min-heap), swap with smaller child.

##### Hash Table Collision Resolution

- **Separate Chaining:** Each slot contains a linked list.

- **Open Addressing:**
  
  - **Linear Probing:** Next slot sequentiall.
  
  - **Quadratic Probing:** Use quadratic function.
  
  - **Double Hashing:** Use second hash function.

##### Binary Tree Traversals

- **Pre-order:** Root, Left, Right.

- **In Order:** Left, Root, Right.

- **Post-order:** Left, Right, Root

- **Tree Reconstruction:** Use Pre-order and In-order traversals.

---

## 5. Sample Problems

##### Checking if Array is a Heap

```cpp
bool isHeap(int A[], int N) {
    for (int i = 0; i <= (N - 2) / 2; ++i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < N && A[i] > A[left]) return false; //Min-heap check
        if (right < N && A[i] > A[right]) return false;
    }
    return true;
}
```

##### AVL Tree Rotations

- **Single Left Rotation** (Right-Right Case):
  
  - Used when a node is unbalanced due to insertion in right subtree's right child.

- **Algorithm Steps:**
  
  - Let `x` be the unbalanced node.
  
  - `y = x->right`.
  
  - `x->right = y->left`.
  
  - `y->left = x`.
  
  - Update heights.

##### Priority Queue with Unsorted Array

- **Removing Highest Priority Element:**
  
  - **Algorithm:**
    
    - Scan array to find the highest priority element (O(n)).
    
    - Remove it and replace with last element. 
    
    - Decrease size.

---

## 6. ADT Operations

##### Priority Queue Operations

- **insert(element, priority)**

- **extractMin()/extractMax():** Remove element with highest priority.

- **peekMin()/peekMax():** Return highest priority element without removing.

- **decreaseKey(key, newPriority)**

- **Time Complexities:**
  
  - **Heap:** insert O(log n), extractMin O(log n)
  
  - **Unsorted Array:** insert O(1), extractMin O(n)
  
  - **Sorted Array:** insert O(1), extractMin O(1)

##### Dictionary ADT Operations

- **insert(key, value)**

- **remove(key)**

- **search(key)** 

- **update(key, newValue)**

- **containsKey(key)**

- **keys(), values()**

---

## 7. Recurrence Equations and Induction

##### Example Proof by Induction

Given: $T(n) = T(n-1)+2n$, with $T(1) = 2

Prove: $T(n) = n^2 + n$

- **Base Case $(n=1)$**:
  
  - $T(1) = 1^2 + 1 = 2$ (holds true)

- **Inductive Step:**
  
  - Assume $T(k) = k^2 + k$
  
  - Show $T(k+1) = (k+1)^2 + (k + 1)$
  
  - $T(k+1) = T(k) = 2(k+1)$
  
  - Substitute $T(k): T(k+1) = k^2 + k + 2k + 2 = (k+1)^2 + (k+1)$

---

## 8. Sorting Algorithms

- **Comparison-Based Sorting:**
  
  - **Lower Bound:** O(n log n)
  
  - **Algorithms:** Merge Sort, Heap Sort

- **Non-Comparison-Based Sorting:**
  
  - **Linear Time:** O(n) under specific conditions
  
  - **Algorithms:** Counting Sort, Radix Sort
  
  - **Conditions:** Limited range of integer keys.

---

## 9. Time Complexities

##### Heap Operations

- **insert:** O(log n)

- **extractMin/Max:** O(log n)

- **buildHeap:** O(n)

##### Hash Table Operations

- **Average Case:** O(1) for insert, delete, search

- **Worst Case:** O(n) due to collisions

---

**Note:** Always consider edge cases and underlying data structure's impact on operation complexities. Focus on understanding the algorithms and their applications to solve problems effectively.
