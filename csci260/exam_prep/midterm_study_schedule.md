# Study Schedule
## Day 1: Priority Queue ADT Operations
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
## Day 2: Implementing Priority Queue with Unsorted Arrays
- **Topics Covered**:
    - Removal operation in an unsorted array-based priority queue.
    - C++ implementation of the removal function.
- **Study Activities**:
    - **Algorithm Analysis**: Understand how removal works in an unsorted array.
    - **Code Practice**: Implement the removal function in C++.
    - **Time Complexity**: Analyze the time complexity of insertion and removal operations.
- **Practice**:
    - Modify the code to handle edge cases (e.g., when the array is empty).
    - Compare the efficiency of unsorted arrays versus other implementations.
## Day 3: Sorting Algorithms and Time Complexity
- **Topics Covered**:
    - Theoretical limits of comparison-based sorting algorithms.
    - Non-comparison-based sorting algorithms (Counting Sort, Radix Sort).
- **Study Activities**:
    - **Review Comparison Sorts**: Understand why $O(n\log n)$ is the lower bound.
    - **Study Non-Comparison Sorts**: Lean how Counting Sort and Radix Sort achieve linear time under certain conditions.
- **Practice**:
    - Implement Counting Sort and Radix Sort for integer arrays.
    - Solve problems that require choosing the appropriate sorting algorithm.
## Day 4: Hash Tables and the Lookup Operations
- **Topics Covered**:
    - Implementing the `lookup` method in a hash table.
    - C++ implementation using open addressing.
- **Study Activities**:
    - **Hash Functions**: Review how hash functions distribute keys.
    - **Collision Resolution**: Understand open addressing and how linear probing works.
    - **Code Practice**: Implement the `lookup` function in C++.
- **Practice**:
    - Write test cases to verify your `lookup` implementation.
    - Analyze the impact of load factors on performance.
## Day 5: Master Theorem and Recurrence Relations
- **Topics Covered**:
    - Solving recurrence relations using the Master Theorem.
    - Applying it to divide-and-conquer algorithms.
- **Study Activities**:
    - **Hash Functions**: Review how hash functions distribute keys.
    - **Collision Resolution**: Understand open addressing and how linear probing works.
    - **Code Practice**: Implement the `lookup` function in C++.
- **Practice**:
    - Write test cases to verify your `lookup` implementation.
    - Analyze the impact of load factors on performance.
## Day 5: Master Theorem and Recurrence Relations
- **Topics Covered**:
    - Solving recurrence relations using the Master Theorem.
    - Applying it to divide-and-conquer algorithms.
- **Study Activities**:
    - **Master Theorem Cases**: Review the three cases and their conditions.
    - **Problem Solving**: Solve various recurrence relations using the Master Theorem.
    - **Understanding Limitations**: Identify when the Master Theorem cannot be applied.
- **Practice**:
    - Derive the time complexity of given recursive algorithms.
    - Create your own recurrence relations and solve them.
## Day 6: Binary Tree Reconstruction
- **Topics Covered**:
    - Reconstructing a binary tree from traversal (pre-order, in-order, post-order).
- **Study Activities**:
    - **Travesal Technique**: Review the properties of each tree traversal method.
    - **Reconstruction Algorithm**: Learn the step-by-step process to rebuild a tree.
    - **Visualization**: Draw trees based on traversal data.
- **Practice**:
    - Given different traversal sequences, reconstruct the corresponding binary trees.
    - Verify your reconstructed trees by peforming traversals.
## Day 7: Dictionary ADT Operations
- **Topics Covered**:
    - Main operations of the Dictionary ADT.
    - Parameter and functionality of each operation.
- **Study Activities**:
    - **Operation Details**: Understand insert, remove, search, update, and other operations.
    - **Implementations**: Explore how dictionaries are implemented using hash tables or balance trees.
- **Practice**:
    - Implement a simple dictionary in C++ using a hash table.
    - Write functions for each dictionary operation.
## Day 8: Lookup in a Sorted Array-Based Dictionary
- **Topics Covered**:
    - Implementing the `lookup` operation using binary search.
- **Study Activities**:
    - **Binary Search Algorithm**: Review how binary seach works in sorted arrays.
    - **Code Implementation**: Write the `lookup` function in C++.
    - **Edge Cases**: Consider how to handle keys not present in the array.
- **Practice**:
    - Analyze the time complexity of lookup operations.
    - Modify your implementation to return additional information (e.g., insertion point for missing keys).
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
## Day 10: Heaps vs. Sorted Arrays for Priority Queues
- **Topics Covered**:
    - Advantages and disadvantages of using heaps compared to sorted arrays.
- **Study Activities**:
    - **Performance Analysis**: Compare time complexities for insertion and deletion.
    - **Use Cases**: Determine scenarios where one implementation is preferred over the other.
- **Practice**:
    - Create a priority queue using both a heap and a sorted array.
    - Measure and compare the performance of both implementations with lare datasets.
## Day 11: upHeap Operation
- **Topics Covered**:
    - Purpose and algorithm of the upHeap operation in heaps.
- **Study Activities**:
    - **Insertion in Heaps**: Review how new elements are addeds.
    - **upHeap Mechanism**: Understand how upHeap restored the heap property.
    - **Algorithm Steps**: Memorize the steps involved in upHeap.
- **Practice**:
    - Write the upHeap function in C++.
    - Insert multiple elements into a heap and trace the upHeap process.
## Day 12: Collision Handling in Hash Tables
- **Topics Covered**:
    - What collisions are and why they occur.
    - Methods to resolve collisions: separate chaining and open addressing.
- **Study Activities**:
    - **Hash Function Limitations**: Understand why collisions are inevitable.
    - **Separate Chaining**: Learn how linked lists are used at each bucket.
    - **Open Addressing**: Study linear probing, quadratic probing, and double hashing.
- **Practice**:
    - Implement both collision resolution methods in C++.
    - Test your hash table with data designed to cause collisions.
## Day 13: Recurrence Relations in Recursive Algorithms
- **Topics Covered**:
    - Writing recurrence relations for recursive functions.
    - Solving linear recurrence relations.
- **Study Activities**:
    - **Identify Recurrence Patterns**: Learn how to express the running time recursively.
    - **Solving Techniques**: Use methods like unrolling and induction.
- **Practice**:
    - Write recurrence relations for various recursive functions.
    - Solve them to find the time complexity.
## Day 14: AVL Trees and Rotations
- **Topics Covered**:
    - Understanding AVL tree properties.
    - Double rotations (Left-Right and Right-Left rotations).
- **Study Activities**:
    - **Balancing Factor**: Learn how to calculate and interpret it.
    - **Rotations Algorithms**: Study the steps involved in single and double rotations.
    - **Insertion Impact**: Determine how inserting certain values affects tree balance.
- **Practice**:
    - Insert elements that cause double rotations and perform the rotations.
    - Draw the AVL tree before and after rotations.
## Day 15: Proofs by Induction
- **Topics Covered**:
    - Proving statements using mathematical induction.
    - Applying induction to recurrence relations.
- **Study Activities**:
    - **Induction Steps**: Review the base case and inductive step.
    - **Common Pitfalls**: Understand where mistakes often occur in proofs.
- **Practice**:
    - Prove the correctness of formulas derived from recurrence relations.
    - Practice proofs with varying levels of complexity.
## Day 16: Comprehensive Review of Key Concepts
- **Topics Covered**:
    - Revisit challenging topics based on your self-assessment.
    - Clarify any lingering doubts.
- **Study Activities**:
    - **Summary Nodes**: Create concise summaries for each topic.
    - **Concept Mapping**: Draw connections between
- **Practice**:
    - Teach a topic to someone else or explain it aloud to reinforce understanding.
    - Solve additional practice problems from textbooks or online resources.
## Day 17: Practice Exam Simulation
- **Activities**:
    - **Simulated Exam**: Take a timed practice exam covering all topics.
    - **Review Answers**: Check your solutions and understanding any mistakes.
- **Focus**:
    - **Time Management**: Practice completing questions within the allotted time.
    - **Exam Strategies**: Identify which questions to tackle first based on your strengths.
## Day 18: Final Revision and Relaxation
- **Activities**:
    - **Final Review**: Go over key formulas, algorithms, and definitions.
    - **Mindfulness**: Engage in activities to reduce stress (e.g., light exercise, meditation).
- **Focus:**
    - **Confidence Building**: Acknowledge your preparation efforts.
    - **Rest**: Ensure you are well-rested before the exam day.
---
## Additional Tips
- **Consistent Practice**: Regularly solve problems related to each day's topics to reinforce learning.
- **Resource Utilization**: Use textbooks, online tutorials, and coding platforms to supplement your study.
- **Ask for Help**: If you're stuck on a concept, don't hesitate to reach out to professors or peers for clarification.
- **Healthy Habits**: Maintain a balanced diet and get adequate sleep to keep your mind sharp.