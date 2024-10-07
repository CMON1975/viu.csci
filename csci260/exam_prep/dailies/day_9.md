## Day 9: Understanding Heaps
- **Topics Covered**:
    - Definition and properties of heaps.
    - Structural and heap order properties.
- **Study Activities**:
    - **Heap Structure**: Understand complete binary trees.
    - **Heap Order Property**: Learn the differences between max-heaps and min-heaps.
    - **Visualization**: Draw sample heaps and identify their properties.
- **Practice**:
    - Implement a heap data structure in C++.
    - Insert elements and ensure the heap property is maintained.
---
### 1. Explain complete binary trees.
A **complete binary tree** is a specific type of binary tree in which all levels are completely filled except possibly for the last level, which is filled from left to right. This property makes complete binary trees particularly efficient for certain data structures and algorithms, such as heaps and priority queues.

---
#### Definition:
A **complete binary tree** is a binary tree that satisfied the following conditions:
1. **All levels are fully filled**, except possibly the last level.
2. **In the last level**, all nodes are as far left as possible.

---
#### Characteristics of Complete Binary Trees:
1. **Node Arrangement:**
    - Nodes are filled level by level from left to right without gaps.
    - No missing nodes are allowed in any level except possibly the last.
2. **Height of the Tree:**
    - For a complete binary tree with $n$ nodes, the height $h$ is $\lfloor \log_2n \rfloor$.
3. **Relationship Between Nodes:**
    - Each node at index $i$ has:
        - **Left Child** at index $2i+1$ (assuming zero-based indexing).
        - **Right Child** at index$2i+2$.
        - **Parent** at index $\lfloor \frac{i-1}{2}\rfloor$
4. **Storage Efficiency:**
    - Can be efficiently represented using arrays due to predictable relationships between indices.
    - No need for explicit pointers to child nodes.

---
#### Visual Representation:
Consider the following compete binary tree:
```
       1
     /   \
    2     3
   / \   / 
  4   5 6
```
- **Level 0:** Node 1
- **Level 1:** Nodes 2 and 3
- **Level 2:** Nodes 4, 5, and 6
- **Last Level:** Level 2 is not completely filled, but nodes are filled from left to right without gaps.

---
#### Array Representation:
Due to their structure, complete binary trees are often stores in arrays. Here's how the above tree would be represented:
| Index | Node Value
| :- | :-
| 0 | 1
| 1 | 2
| 2 | 3
| 3 | 4
| 4 | 5
| 5 | 6

**Index Relationships:**
- **Left Child: $\text{left}(i)=2i+1$**
- **Right Child: $\text{right}(i)=2i+2$**
- **Parent: $\text{parent}(i)=\lfloor \frac{i-1}{2} \rfloor$**

---
#### Properties:
1. **Efficient Traversal:**
    - Easy to traverse the tree using iterative methods due to the array representation.
2. **Space Utilization:**
    - No space wasted on pointers; memory allocation is compact.
3. **Balanced Tree:**
    - The tree is balanced in terms of depth, leading to efficient operations.
4. **Application in Heaps:**
    - Complete binary trees form the basis of binary heaps (both min-heaps and max-heaps).

---
#### Comparison with Other Binary Trees:
- **Full Binary Tree:**
    - Every node has 0 or 2 children.
    - Not all levels need to be fully filled.
- **Perfect Binary Tree:**
    - All internal nodes have two children.
    - All leaf nodes are at the same level.
    - A perfect binary tree is both full and complete.
- **Complete Binary Tree:**
    - All levels are fully filled except possibly the last.
    - Last level nodes are filled from left to right.

**Illustration:**
- **Full Binary Tree Example:**
```
       1
      / \
     2   3
    / \
   4   5
```
- **Perfect Binary Tree Example:**
```
        1
      /   \
     2     3
    / \   / \
   4  5   6  7
```
- **Complete Binary Tree Example:**
```
        1
      /   \
     2     3
    / \   / 
   4  5   6  
```

---
#### Applications:
1. **Heaps and Priority Queues:**
    - Binary heaps are complete binary trees that satisfy the heap property.
    - Used in implementing priority queues and efficient sorting algorithms like heapsort.
2. **Scheduling Algorithms:**
    - Task scheduling where tasks are organized in a heirarchy.
3. **Binary Indexed Trees (Fenwick Trees):**
    - Used for efficient implementation of cumulative frequency tables.
4. **Memory Allocation:**
    - Used in scenarios where memory allocation needs to be managed efficiently without fragmentation.

---
#### Operations on Complete Binary Trees:
**Insertion:**
- **Algorithm:**
    - Insert the new node at the first available position at the last level to maintain completeness.
    - Typically implemented using a queue to perform level-order traversal until a node with missing child is found.

**Deletion:**
- **Algorithm:**
    - Replace the node to be deleted with the last node in the deepest level.
    - Delete the last node to maintain completeness.
    - Adjust the tree accordingly.
- **Steps:**
    1. Find the node to be deleted.
    2. Find the deepest and rightmost node.
    3. Replace the data of the node to be deleted with the deepest node's data.
    4. Delete the deepest node.

---
#### Advantages of Complete Binary Trees:
1. **Efficient Operations:**
    - Insertion and deletion can be done in O(log n) time due to the balanced nature.
2. **Predictable Structure:**
    - The shape of the tree is predictable, which simplifies the implementation of certain algorithms.
3. **Optimal Height:**
    - The height of a complete binary tree is minimized, leading to efficient traversal times.

---
#### Implementation Details:
**Representing a Complete Binary Tree Using an Array:**
- **Indexing:**
    - **Root Node:** At index 0.
    - **Parent Node:** For node at index $i$, parent is at $\lfloor \frac{i-1}{2} \rfloor$.
    - **Left Child:** For node at index $i$, left child is at $2i+1$.
    - **Right Child:** For node at index $i$, right child is at $2i+2$.
- **Benefits:**
    - Eliminates the need for explicit pointers.
    - Improves cache performance due to sequential memory allocation.

**Implementing Heaps Using Complete Binary Trees:**
- **Heap Property:**
    - **Max-Heap:** Every parent node is greater than or equal to its children.
    - **Min-Heap:** Every parent node is less than or equal to its children.
- **Heap Operations:**
    - **Insert:**
        - Add the new element at the end of the array.
        - Heapify up to maintain the heap property.
    - **Delete (Extract Min/Max):**
        - Replace the root with the last element.
        - Heapify down to maintain the heap property.

---
#### Complexity Analysis:
- **Insertion and Deletion:**
    - Time Complexity: O(log n)
    - Due to the need to traverse up or down the tree, which has height $\log^2n$.
- **Accessing Elements:**
    - Accessing the root (max or min element) is O(1).

---
#### Examples and Practice Problems:
1. **Problem:** Given an array representing a complete binary tree, convert it into a max-heap.
    - **Solution:** Perform heapify operations starting from the last non-leaf node up to the root.
2. **Problem:** Determine whether a given binary tree is a complete binary tree.
    - **Solution:** Use level-order traversal to ensure no gaps exist in the nodes from left to right.

---
#### Checking if a Binary Tree is Complete:
- **Algorithm:**
    1. Perform a level-order traversal using a queue.
    2. Once a node is encountered that doesn't have both children, all subsequent nodes must be leaf nodes.
    3. If a non-full node is followed by a node with children, the tree is not complete.

---
#### Key Takeaways:
- A complete binary tree is a highly structures binary tree that ensures efficient operations.
- The array representation of complete binary trees simplifies storage and manipulation.
- They are foundational in implementing efficient data structures like heaps.
- Understanding complete binary trees is essential for optimizing algorithms that require balanced trees.

---
#### Conclusion:
Complete binary trees play a crucial role in computer science, particularly in data structures and algorithms that require efficient storage and retrieval operations. Their structured nature ensures operations remain efficient even as the amount of data scales, making them indispensable for tasks like sorting, scheduling, and implementing priority queues.

By mastering complete binary trees, you'll gain a deeper understanding of how to optimize algorithms and data structures for performance-critical applications.

---
### 2. What are the differences between max-heaps and min-heaps?
#### Key Differences Between Max-Heaps and Min-Heaps:
1. **Heap Property:**
    - **Max-Heap:** Parent nodes are **greater than or equal to** their child nodes.
    - **Min-Heap:** Parent nodes are **less than or equal to** their child nodes.
2. **Root Node Value:**
    - **Max-Heap:** Root node has the **maximum** value.
    - **Min-Heap:** Root node has the **minimum** value.
3. **Usage Scenarios:**
    - **Max-Heap:**
        - Ideal for algorithms where quick access to the maximum element is required.
        - Used in applications like priority queues where higher values have higher priority.
    - **Min-Heap:**
        - Ideal for algorithms where quick access to the minimum element is required.
        - Used in Dijkstra's algorithm for finding the shortes path, where lower values have higher priority.
4. **Insertion and Deletion Behavior:**
    - **Max-Heap:**
        - When inserting, values bubble up to maintain the max-heap property.
        - Deletion typically involves removing the maximum element.
    - **Min-Heap:**
        - When inserting, values bubble up to maintain the min-heap property.
        - Deletion typically involves removing the minimum element.

---
#### Conclusion:
- **Max-Heaps and Min-Heaps** are variations of the binary heap data structure that differ based on the heap property they enforce.
- The **primary difference** lies in whether the parent node is greater than or less than its child nodes.
- Both structures are essential in computer science for optimizing various algorithms that require efficient retrieval of the maximum or minimum elements.
- **Understanding the differences** between max-heaps and min-heaps allows you to choose the appropriate data structure for your specific application needs.

---
