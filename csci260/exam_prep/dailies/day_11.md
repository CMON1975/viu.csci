## Day 11: upHeap Operation
- **Topics Covered**:
    - Purpose and algorithm of the upHeap operation in heaps.
- **Study Activities**:
    - **Insertion in Heaps**: Review how new elements are added.
    - **upHeap Mechanism**: Understand how upHeap restores the heap property.
    - **Algorithm Steps**: Memorize the steps involved in upHeap.
- **Practice**:
    - Write the upHeap function in C++.
    - Insert multiple elements into a heap and trace the upHeap process.

---
### 1. How are new elements added to a heap ADT?
In a heap Abstract Data Type (ADT), new elements are added through a process that maintains the heap's structural and order properties. Here's how it's done:
1. **Insert at the Next Available Position:**
    - **Action:** Place the new element at the next available spot in the heap, which is typically the leftmost empty position at the bottom level.
    - **Implementation:** In an array representation, append the new element to the end of the array.
2. **Restore the Heap Property Using upHeap (Percolate-Up):**
    - **Purpose:** The initial insertion might violate the heap property (e.g., in a max-heap, a child node is greater than its parent).
    - **Process:**
        - Compare the newly added element with its parent node.
        - If the heap property is violated, swap the new element with its parent.
        - Repeat this comparison and swapping process up the tree until the heap property is restored or the root is reached.

**Why This Method Works:**
- **Structural Integrity:** By inserting at the next available position, the heap remains a complete binary tree.
- **Order Integrity:** The upHeap operations ensures that all parent nodes satisfy the heap property relative to their children.

**Example in a Max-Heap:**
- **Insert Element:** Add the new value to the bottom level at the leftmost position.
- **Compare with Parent:** If the new value is greater than its parent, swap them.
- **Repeat:** Continue comparing and swapping until the new value is less than or equal to its parent.

**Key Points:**
- The insertion process maintains both the **shape property** (complete binary tree) and the **heap property** (order between parent and child nodes).
- The **upHeap** operation is essential for re-establishing the heap order after insertion.

**Visual Representation:**
1. **Before Insertion:**
```
     50
    /  \
   30  40
  /  
 20   
```
2. **After Inserting 60:**
    - Place 60 at the next available spot.
        ```
             50
            /  \
           30  40
          /  \
        20    60
        ```
3. **Perform upHeap:**
    - Swap 60 with 30.
        ```
             50
            /  \
           60  40
          /  \
        20    30
        ```
    - Swap 60 with 50.
        ```
             60
            /  \
           50  40
          /  \
        20    30
        ```
The heap now maintains its max-heap property after the new element is added.

---
### 2. How does upHeap restore the heap property?
The upHeap operation is essential for maintaining the integrity of a heap after insertion. By repeatedly swapping the newly inserted element with its parent when necessary, upHeap restores the heap property efficiently, ensuring that the heap continues to function correctly for subsequent operations like peek or extract.

**Key Points**
- **Efficiency:**
    - The upheap operation takes **O(log n)** time in the worst case, where `n` is the number of elements in the heap, since the height of the heap is logarithmic relative to its size.
- **In-Place Operations:**
    - upHeap adjusts the positions of elements within the existing data structure without requiring additional memory for restructuring.

---
### 4. Write the pseudocode and a C++ implementation of the upHeap function.
**Pseudocode of the upHeap Function**
Here is the pseudocode for the `upHeap` function, which restores the heap property after inserting a new element into a **max-heap** using **0-based indexing** (arrays starting at index 0).
```
function upHeap(heap, index):
    while index > 0:
        parentIndex = (index - 1) /2
        if heap[index] > heap[parentIndex]:
            swap heap[index] with heap[parentIndex]
            index = parent[Index]
        else: 
            break
```
**Explanation:**
- **heap:** The array representing the heap.
- **index:** The index of the newly inserted element.
- **parentIndex:** The index of the parent node.
- **Process:**
    - While the current index is not the root (index > 0):
        - Calculate the parent index.
        - Compare the current element with its parent.
        - If the current element is greater than the parent (for a max-heap), swap them.
        - Update the current index to the parent index.
        - If not greater, the heap property is satisfied, and the loop ends.

**C++ Implementation of the upHeap Function**
```
#include <iostream>
#include <vector>
#include <algorithm>    // for swap

using std::swap;
using std::vector;
using std::cout;
using std::endl;

// function to perform upheap operation in a max-heap
void upHeap(vector<int>& heap, int index) {
    while (index > 0) {
        // calculate parent index
        int parentIndex = (index - 1) / 2;

        // if the current element is greater than the parent, swap them
        if (heap[index] > heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);

            // move up to the parent's index
            index = parentIndex;
        } else {
            // the heap property is restored
            break;
        }
    }
}

// heap print
void printHeap(const vector<int>& heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

// example usage
int main() {
    vector<int> heap; // our heap represented as a vector

    // elements to insert into the heap
    vector<int> elementsToInsert = {15, 10, 20, 17, 8};

    // insert each element and perform upHeap
    for (int elem : elementsToInsert) {
        // add the new element to the end of the heap
        heap.push_back(elem);

        // restore the heap property
        upHeap(heap, heap.size() - 1);

        // print the heap after each insertion
        cout << "Heap after inserting " << elem << ": ";
        printHeap(heap);
    }

    return 0;
}
```

---
### 5. Insert multiple elements into a heap and trace the upHeap process.
Let's walk through the process of inserting multiple elements into a **max-heap** and trace the `upHeap` (also known as "bubble-up" or "percolate-up") operation after each insertion. We'll use the following sequence of elements:

**Elements to insert:** 15, 10, 20, 17, 8

**Understanding Heap Representation**
A heap is typically represented as a binary tree and can be efficiently stored in an array. In array representation:
- The **root** element is at index 1 (we'll ignore index 0 for simplicity).
- For any node at index `i`:
    - **Parent index:** `i / 2` (integer division).
    - **Left child index:** `2 * i`.
    - **Right child index:** `2 * i + 1`.

**Step-by-Step Insertion and upHeap Tracing**

**Initial Heap:**
- The heap is empty.

**Step 1: Insert 15**
- **Insert Postion:** Index 1.
- **Action:** Place 15 at the root.
- **upHeap:** Not needed (first element).

**Heap Array:** `[ , 15]`

---
**Step 2: Insert 10**
- **Insert Postion:** Index 2.
- **Action:** Place 10 as the left child of 15.
- **Parent Index:** `2 / 2 = 1`.
- **Compare:** 10 vs. 15.
- **upHeap:** Not needed (10 $\le$ 15).

**Heap Array:** `[ , 15, 10]`

---
**Step 2: Insert 20**
- **Insert Postion:**  Index 3.
- **Action:** Place 20 as the right child of 15.
- **Parent Index:**  `3 / 2 = 1`
- **Compare:**  20 vs. 15.
- **upHeap Needed:** Yes (20 > 15).

**upHeap Process:**
1. **Swap:** 20 and 15.
2. **Update Position:** 20 is now at index 1; 15 is at index 3.
3. **New Parent Index:** `1 / 2 = 0` (root reached).
4. **upHeap Ends.**

**Heap Array after upHeap:** `[ , 20, 10, 15]`

---
**Step 2: Insert 17**
- **Insert Postion:** Index 4.
- **Action:** Place 17 as the left child of 10.
- **Parent Index:** `4 / 2 = 2`
- **Compare:** 17 vs. 10.
- **upHeap Needed:** Yes (17 > 10).

**upHeapProcess:**
1. **Swap:** 17 and 10.
2. **Update Position:** 17 is now at index 2; 10 is at index 4.
3. **New Parent Index:** `2 / 2 = 1`.
4. **Compare:** 17 vs. 20.
5. **upHeap Ends:** 17 $\le$ 20.

**Heap Array after upHeap:** `[ , 20, 17, 15, 10]`

---
**Step 5: Insert 8:**
- **Insert Position:** Index 5.
- **Action:** Place 8 as the right child of 17.
- **Parent Index:** `5 / 2 = 2`.
- **Compare:** 8 vs. 17.
- **upHeap:** Not needed (8 $\le$ 17).

**Heap Array:** `[ , 20, 17, 15, 10, 8]`

---
**Final Heap Structure**
**Array Representation:** `[ , 20, 17, 15, 10, 8]`

**Tree Representation:**
```
     20
    /  \
   17  15
  /  \
 10   8
```
**Summary of upHeap Operations**
- **Inserted 15:** No upHeap needed.
- **Inserted 10:** No upHeap needed.
- **Inserted 20:** Swapped with 15.
- **Inserted 17:** Swapped with 10.
- **Inserted 8:** No upHeap needed.

**Conclusion**
By tracing the `upHeap` process after each insertion, we ensure that the heap maintains its **max-heap property**: Every parent node is greater than or equal to its child nodes. This step-by-step approach illustrates how `upHeap` restores the heap structure efficiently.