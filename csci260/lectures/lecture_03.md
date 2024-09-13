# Priority Queue
## Lab/Assignments
No need to separate labs into header files.
Assignments can follow code separation.
All files in a single directory is fine.
## Priority Queue ADT
Typical applications: to-do lists, triage order, hospital emergency room intake.
What is a priority queue (PQ)? A container <key, item> where `key` is the priority value.
A PQ always pulls the highest priority object out. Smaller number generally means higher priority. It can be numeric, characters, or user-defined codes.
### Operations
- insert
- removeMin()
- new()
- size()
- minKey() 
- minItem() 
### Total Order Relation
In the contect of the Priority Queue ADT (Abstract Data Type), a **total order relation** refers to a binary relation between elements of a set, where every pair of elements is comparable in a consistent way. In other words, for any two elements $a$ and $b$ in the set, one of the following must hold:
1. $a <= b$
2. $b <= a$
This relationship is characterized by three main properties:
1. **Antisymmetry:** If $a<=b$ and $b<=a$, then $a=b$.
2. **Transitivity:** If $a<=b$ and $b<=c$, then $a<=c$.
3. **Totality:** For any two elements $a$ and $b$, either $a<=b$ or $b<=a$.
In the context of a **Priority Queue**, the total order relation is what allows elements to be ranked, so that the priority of elements can be compared. For example, if a priority queue is used to manage tasks, a total order relation ensures that for any two tasks, you can determine which one has higher priority.
In contrast, a *partial order relation* would not necessarily allow comparison between all pairs of elements, meaning some elements might not be comparable.
### Implementation
1. unsorted list
    - insert: `<key, item>->list` this is $O(1)$ in a linked list.
    - removeMin(): selection of min key is $O(n)$, removal is $O(1)$, total $O(n)$.
2. sorted list
    - insert: finding the insertion point to maintain sorted state is $O(n) + O(1)$. Placing the `<key, item>` is $O(n)$.
    - removeMin(): finding the min key is $O(1)$, removal is $O(1)$.
    - Always expect to perform both insert and remove, therefore expect $O(n)$ time complexity.
3. heap
    - The main application of a heap is to implement a PQ.
    - The heap shares operations with the PQ, PQ is a container.
    - A heap has the structure of a complete binary tree[^1].
    - One `<key, item>` in each node.

**heap order**
- Node `v` has `<key, item>`.
- `v`'s parent's priority is higher or the same as `v`'s.
- No comparisons made across levels.
- The order must be maintained.

**Heap Implementation**
- We need a pointer to the root.
- We need a pointer to keep track of the next available branch.

**insert**
1. Attach `<key, item>` pair on next available branch.
2. Perform an "upheap" operation to properly place the new insertion: compare priority of inserted node to parent and swap places if parent is higher priority. $O(log (n))$

**removeMin()**
1. Swap root with last node, remove this new last node.
2. Perform a "downheap" operation to properly place the new insertion: compare and swap with child node if parent is of lower priority. $O(\log n)$

**height math**
| height | min # of nodes | max # of nodes |
| :---: | :---: | :---: |
| 1 | 1 | 1 |
| 2 | 2 | 3 |
| 3 | 4 | 7 |
| $n$ | $2^{n-1}$ | $2^n-1$ |

Height is approximately $O(\log n)$.

## Prof's Notes (transcribed and corrected)
### Priority Queue and Heap
* A Priority Queue (PQ) stores a collection of items. Each item is a pair of `<key, element>`. Usually but not always, the smaller the key the higher the priority.
* PQ operations:
    - insert
    - removeMin
    - minKey
    - minElement
    - other assistant operations: size, isEmpty, isFull, etc.
- Typical Applications: to-do list.
- Total order relation
    - keys in a priority queue can be arbitrary objects on which an order is defined
    - two distinct items in a priority queue can have the same key
    - mathematical concept of total order relation:
        - Reflexive property: $x <= x$
        - Antisymettric property: $x <= y$ and $y <= x$ implies $x = x$
        - Transitive property: $x <= y$ and $y <= z$ implies $x <= z$
- Implementation of priority queue
    - unsorted list -- insert $O(1)$, removeMin $O(n)$
    - sorted array -- insert $O(n)$, removeMin $O(1)$
    - heap -- insert $O(\log n)$, removeMin $O(\log n)$
- ADT Heap: A heap is a binary tree storing <key, element> pairs in its nodes and satisfying the following properties:
    - Heap Order: for every node `v` other than the root, `v`'s parent's priority is higher than or the same as `v`'s.
    - Complete Binary Tree[^1]
- Heap observations:
    - The height of a heap storing $n$ <key, element> pairs is $O(\log n)$
    - The element with the highest priority is always stored in the root node.
- Using heap to implement the priority queue
    - insert -- insert to the next spot after the last node, using upheap (starting from the new node, possible swap with parent) to restore the Heap Order
    - removeMin -- swap root and last element, remove the last element, using downheap (starting from root, possible swap with one of the child nodes) to restore the Heap Order
- Implementation of heap -- using array
    - root node is at array[0]
    - Given `array[i]`, its parent node is at `array[(i-1)/2]` if `i > 0`; its left child node is at `array[i * 2 + 1]` and its right child node is at `array[i * 2 + 2]`.
    - The last element in a heap with $n$ elements is at `array[n - 1]`.
    To insert a new element, insert into `array[n]` first, update `n`, then perform upheap to restore the Heap Order.
    - To `removeMin`, swap `array[0]` and `array[n - 1]` first, update `n`, then perform downheap to restore the Heap Order.
    - Performance: `insert` -- $O(\log n)$, `removeMin` -- $O(\log n)$, `minKey` -- $O(1)$, `minElement` -- $O(1)$.
- Heap Sort
    * Using an array-based heap
    * Put `n` elements one by one into the heap using method `insert`
    * Taking elements out one by one using method `removeMin`
    * Performance -- $O(n \log n)$
    * Space usage -- in place.

[^1]: A **complete binary tree** is a type of binary tree in which all levels are fully filled, except possibly for the last level. In the last level, all nodes are filled from left to right without any gaps.
A complete binary tree ensures that the tree is as balanced as possible, which is importat for maintaining efficient operations in data structures like heaps.