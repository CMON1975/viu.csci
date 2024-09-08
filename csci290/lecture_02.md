# Abstract Data Types vs. Data Strucutres
## Ad Hoc Notes
Groups and Sets in abstract math define custom operators.
The "what" is more important than the "how"
Separation of interface from implementation, hidden information.
### Stack
| new | push | pop |
| --- | --- | --- |
| `array` | `A[top] = obj;` | `top--;` |
| `top = 0;` | `top++;` | `victim = list;` |
| `list = 0;` | `new node; N.next = list; list = N;` | `list = list -> next` |
*properties*: ==FILO (First In, Last Out)==
- `pop(push(s.obj)) == obj;`
- `top(push(s.obj)) == obj;`
- `isEmpty(new()) == true;`
- `isEmpty(push(S.obj)) == false;`

Use preconditions (comments are simplest) to put responsibility for handling exceptions on the user.

- [x] Practice implementing Stack with both array and linked list. ==See associated code StackArray.h and StackList.h==

Document on semantic level, show the purpose of code only if it is not readily apparent.

### Queue
| new | enQ (enqueue) | deQ (dequeue) |
*properties*: ==FIFO (First In, First Out)==

```front(enQ(new().obj)) == obj;
deQ(enQ(new().obj)) == new();
front(enQ(enQ(Q,obj1),obj2)) == front(enQ(Q,obj1));
deQ(enQ(enQ(Q,obj1),obj2)) == enQ(deQ(enQ(Q.obj1)),obj2)```

*Breakdown of last above:*
Left-hand side:
1. ==enQ(Q, obj1)==: This means enqueue ==obj1== to the queue ==Q==.
2. ==enQ(enQ(Q, obj1), obj2)==: After enqueuing ==obj1==, this adds ==obj2== to the resulting queue.
3. ==deQ(enQ(enQ(q, obj1), obj2))==: Dequeue the first element from the queue that now contains both ==obj1== and ==obj2==. This should result in a queue with just ==obj2==.
Right-hand side:
1. ==enQ(Q, obj1)==: As before, enqueue ==obj1== to the queue ==Q==.
2. ==deQ(enQ(Q, obj1))==: Dequeue the first element (i.e., ==obj1==), leaving an empty queue.
3. ==enQ(deQ(enQ(Q, obj1)), obj2)==: Enqueue ==obj2== to the result of the dequeue operation, which was an empty queue.

This is illustrating that:
* Enqueueing two objects (==obj1 and obj2==) and then dequeueing the queue leaves you with ==obj2== at the front of the queue.
* Alternatively, you can enqueue one object (==obj1==), dequeue it (making the queue empty), and then enqueue the second object (==obj2==), resulting in the same final queue.

Both sides yield the same outcome: a queue with ==obj2== in it.

In essence, this identity highlights how operations on a queue work with respect to its order of elements and serves to reinforce the FIFO principle.

==array-based implementation of Q must be circular==

*Linked list versus array: which is better?*
### 1. Linked List Implementation
How it works:
* A linked list consists of nodes, where each node holds a data value and a pointer to the next node.
* For a queue, you typically maintain two pointers: one for the front (where elements are dequeued) and one for the read (where elements are enqueued).
Pros:
* *Dynamic Size*: The linked list grows and shrinks dynamically, meaning you don't need to worry about the size of the queue ahead of time.
* *Constant Time Operations*: Both the enqueue (at the rear) and dequeue (from the front) are ==O(1)== operations since you're just manipulating pointers.
* *No Waste of Memory*: You don't allocate more memory than you need, unlike arrays where a portion of the allocated space might remain unused if the queue is small.
Cons: 
* *Memory Overhead*: Each element in the queue has a memory overhead due to the pointer needed for each node.
* *Cache Inefficiency*: Linked lists are generally less cache-friendly since nodes are scattered throughout memory, leading to slower access times compared to arrays.
* *Complexity*: Requires more careful memory management (e.g., manual deallocation or smart pointers), which can increase the complexity of the code.
### 2. Array Implentation
How it works:
* The queue is represented as a circular array. You have two indices, one for the front (where elements are dequeued) and one for the rear (where elements are enqueued).
* When the rear or front reaches the end of the array, it wraps around to the beginning (hence "circular").
Pros:
* *Contiguous Memory*: Arrays provide better cache performance since elements are stored contiguously in memory.
* *Low Overhead*: There's no extra memory overhead from storing pointers, making array-based queues more memory-efficient per element.
* *Simple Memory Management*: Memory allocation is straightforward since the entire queue is allocated as a single block.
Cons:
* *Fixed Capacity*: The array has a fixed size. If the queue grows beyond that size, you must resize the array, which involces copying all the elements to a new array--an ==O(n)== operation.
* *Wasted Space*: If the queue is significantly smaller than the array's capacity, you end up wasting memory.
* *Potentially More Complex Enqueue/Dequeue*: Implementing a circular array adds complexity compared to a simple linked list. Keeping track of the wrap-around behavior for both front and rear indices requires careful attention.
### 3. Comparison
| Aspect | Linked List Queue | Array Queue |
| --- | --- | --- |
| *Memory Use* | Dynamic; no wasted space, but extra overhead for pointers. | Fixed or dynamically resized; some space may be wasted. |
| *Time Complexity* | ==0(1)== for both enqueue and dequeue operations. | ==0(1)== for enqueue and dequeue, but resizing is ==O(n)== when necessary. |
| *Cache Efficiency* | Poor (non-contiguous memory). | Good (contiguous memory). |
| *Implementation* | More complex (managing pointers, freeing memory). | Simpler, but managing resizing and wrap-around logic is trickier. |
| *Scalability* | Grows and shrinks dynamically with no need for resizing. | Must resize when capacity is exceeded. |
### When to Use Each:
* *Linked List Queue*: This is ideal if you expect the queue size to change frequently and you don't know the maximum size upfront. The linked list's dynamic nature ensures you don't need to worry about reallocating memory.
* *Array Queue*: This is better suited for scenarios where you have an upper bound on the size of the queue, and you prioritize performance. The array's cache efficiency can make it faster for small to medium-sized queues where resizing doesn't happen often.
In summary, if memory overhead and dynamic resizing are your primary concerns, the linked list implementation might be preferable. However, if performance is a priority and you can tolerate resizing or predict a fixed capacity, an array-based queue can be more efficient.

Professor prefers double, circularly linked list with dummy node(s).

Stack implementations: function calls, HTML tag matching, undo/redo functionality in text editors, expression evaluation (postfix/infix conversion), depth-first search in graphs.
Queue implementations: job queues, accessing shared resources, CPU time slicing, breadth-first search in graphs, print queues for printers.