# Priority Queue ADT Operations
## Overview
- **Topics Covered**:
    - Main operations of the Priority Queue ADT
    - Parameters and functionality of each operation.
- **Study Activities**:
    - **Review Definitions**: Understand the purpose of priority queues and where they are used.
    - **Summarize Operations**: Create a table listing each operation, its parameters, and functionality.
    - **Real-World Applications**: Research examples where priority queues are utilized (e.g. task scheduling, Dijkstra's algorithm).
- **Practice**:
    - Write pseudocode for each priority queue operation.
    - Explain how priority queues differ from regular queues.
## Questions
1. What is the purpose of priority queues and where are they used?
    - A priority queue is a data structure that ensures elements are processed based on their priority. Higher-priority elements are dequeued before lower-priority ones, regardless of their order of arrival.
    - Used in:
        - **Hospital admittance** (prioritizing patients based on the severity of their condition).
        - **Handling PC jobs** (prioritizing system processes over user-initiated processes).
        - **Network routing** (packets with higher priority are transmitted first).
        - **Scheduling tasks in operating systems** (ensuring critical tasks are completed before less critical ones).
        - **Event-driven simulations** (where events are processed in order of priority or urgency).
2. Create a table listing each operation, its parameters, and functionality.
    | operation | parameters | functionality 
    | :--- | :--- | :--- 
    | `insert` | `priority, id` | Adds a new object to the queue, placing it in the correct position based on its priority.
    | `remove` | `id` | Removes object with the specified `id` from the queue.
    | `lookup` | `id` | Finds and returns the object with the specified `id`, without removing it.
    | `highest priority` | None | Returns the object with the highest priority (does not remove it).
    | `lowest priority` | None| Returns the object with the lowest priority (does not remove it).
    | `remove highest` | None | Removes and returns the object with the highest priority.
    | `remove lowest` | None | Removes and returns the object with the lowest priority.

3. How are priority queues utilized in task scheduling? In Dijkstra's algorithm?
    - **Task Scheduling**:
        - In task scheduling, tasks are assigned different priorities, and the operating system or scheduler ensures that the highest-priority task is executed first. Tasks with lower priority wait until the higher-priority tasks are completed. This ensures that important tasks (like system-critical operations) are handled before less important ones. The priority queue dynamically adjusts as tasks are added or completed, always keeping the highest-priority task at the front.
    - **Dijkstra's Algorithm**:
        - In Dijkstra's algorithm (used to find the shortest path between nodes in a graph), a priority queue is crucial for selecting the next node to process.
            - At each step of the algorithm, the node with the smallest tentative distance (the shortest distance from the starting that has been found so far) is dequeued from the priority queue.
            - The priority queue helps efficiently track which node has the smallest distance, allowing Dijkstra's algorithm to run in an optimized manner. Without a priority queue, the algorithm would need to scan the entire set of nodes to find the smallest distance, slowing it down.
4. Write pseudocode for each priority queue operation.
    - `insert`:
        ```
        insert(priority, id):
            Create a new entry with (priortiy, id)
            Add the entry to the priority queue
            Rebalance the queue to maintain heap property (if using a heap)
        ```

    - `remove`:
        ```
        remove(id):
            Search for the entry with the given id in the priority queue
            Remove the entry
            Rebalance the queue (if needed)
        ```
    - `lookup`:
        ```
        lookup(id):
            Search for the entry with the given id
            If found:
                Return the entry (priority, id)
            Else:
                Return "Not found"
        ```
    - `highest priority`:
        ```
        highest priority():
            If the queue is not empty:
                Return the entry at the front/top of the queue (which has the highest priority)
            Else:
                Return "Queue is empty"
        ```
    - `lowest priority`:
        ```
        lowest priority():
            If the queue is not empty:
                Return the entry at the back/bottom of the queue (which has the lowest priority)
            Else:
                Return "Queue is empty"
        ```
    - `remove highest`:
        ```
        remove highest():
            If the queue is not empty:
                Remove the entry with the highest priority (front/top of the queue)
                Rebalance the queue
            Else:
                Return "Queue is empty"
        ```
    - `remove lowest`:
        ```
        remove lowest():
            If the queue is not empty:
                Remove the entry with the lowest priority (bottom of the queue)
                Rebalance the queue
            Else: Return "Queue is empty"
        ```
5. How do priority queues differ from regular queues?

Priority queues and regular queues are both types of data structures used to store and retrieve elements, but they operate quite differently due to the way they manage the order of elements.
Here's a breakdown of the differences:
### 1. Order of Processing:
- **Regular Queue:**
    - Follows a **First-In, First-Out (FIFO)** model.
    - The element that is inserted first will be the first one to be removed. This ensures that elements are processed in the exact order in which they arrive.
- **Priority Queue:**
    - Follows an order based on **priority** rather than the order of insertion.
    - Elements with the **highest priority** (or sometimes lowest, depending on the implementation) are processed first, regardless of when they were added.
### 2. Insertion of Elements:
- **Regular Queue**:
    - Elements are always added to the back of the queue.
- **Priority Queue**:
    - Elements are added based on their priority. They may be inserted at any position within the queue to maintain the correct order of processing according to their priority.
### 3. Retrieval of Elements:
- **Regular Queue:**
    - When an element is removed, it is always the one at the front (oldest element in the queue).
- **Priority Queue:**
    - The element with the **highest priority** is always removed first, regardless of where it is in the queue. This is achieved using data structures like heaps to efficiently manage element retrieval based on priority.
### 4. Use Cases
- **Regular Queue:**
    - Suitable for situations where **order of arrival** is important, like waiting lines (e.g., a printer queue or a customer support queue).
- **Priority Queue:**
    - Used in situations where certain elements are more important and need to be handled sooner (e.g., task scheduling, hospital emergency rooms, or algorithms like Dijkstra's for finding the shortest path).
### 5. Efficiency of Access:
- **Regular Queue:**
    - Both insertion and removal operations are typically **O(1)** because you're simply adding to the end and removing from the front.
- **Priority Queue:**
    - Insertion and removal are typically **O(log n)** when using a heap-based implementation, since elements need to be sorted by priority.
### Summary Table:
| Feature | Regular Queue | Priority Queue
| :- | :- | :-
| **Ordering** | FIFO (First-In, First-Out) | Based on priority (not arrival time)
| **Insertion Point** | At the back | Anywhere, based on priority
| **Removal Point** | From the front | Highest priority element
| **Use Case** | Time-ordered processes (e.g., lines) | Priority-based processes (e.g., task scheduling)
| **Time Complexity** | O(1) for insert and remove | O(log n) for insert and remove (heap-based)