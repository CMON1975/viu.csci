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

**properties**: FILO (First In, Last Out)
- `pop(push(s.obj)) == obj;`
- `top(push(s.obj)) == obj;`
- `isEmpty(new()) == true;`
- `isEmpty(push(S.obj)) == false;`

Use preconditions (comments are simplest) to put responsibility for handling exceptions on the user.

- [x] Practice implementing Stack with both array and linked list. *See associated code StackArray.h and StackList.h*

Document on semantic level, show the purpose of code only if it is not readily apparent.

### Queue

| new | enQ (enqueue) | deQ (dequeue) |
| --- | --- | --- |

**properties**: FIFO (First In, First Out)

```front(enQ(new().obj)) == obj;
deQ(enQ(new().obj)) == new();
front(enQ(enQ(Q,obj1),obj2)) == front(enQ(Q,obj1));
deQ(enQ(enQ(Q,obj1),obj2)) == enQ(deQ(enQ(Q.obj1)),obj2)
```
**Breakdown of last above:**
Left-hand side:
1. `enQ(Q, obj1)`: This means enqueue `obj1` to the queue `Q`.
2. `enQ(enQ(Q, obj1), obj2)`: After enqueuing `obj1`, this adds `obj2` to the resulting queue.
3. `deQ(enQ(enQ(q, obj1), obj2))`: Dequeue the first element from the queue that now contains both `obj1` and `obj2`. This should result in a queue with just `obj2`.
Right-hand side:
1. `enQ(Q, obj1)`: As before, enqueue `obj1` to the queue `Q`.
2. `deQ(enQ(Q, obj1))`: Dequeue the first element (i.e., `obj1`), leaving an empty queue.
3. `enQ(deQ(enQ(Q, obj1)), obj2)`: Enqueue `obj2` to the result of the dequeue operation, which was an empty queue.

This is illustrating that:
* Enqueueing two objects (`obj1 and obj2`) and then dequeueing the queue leaves you with `obj2` at the front of the queue.
* Alternatively, you can enqueue one object (`obj1`), dequeue it (making the queue empty), and then enqueue the second object (`obj2`), resulting in the same final queue.

Both sides yield the same outcome: a queue with `obj2` in it.

In essence, this identity highlights how operations on a queue work with respect to its order of elements and serves to reinforce the FIFO principle.

**array-based implementation of Q must be circular**

## Linked list versus array: which is better?
### 1. Linked List Implementation
How it works:
* A linked list consists of nodes, where each node holds a data value and a pointer to the next node.
* For a queue, you typically maintain two pointers: one for the front (where elements are dequeued) and one for the read (where elements are enqueued).
Pros:
* *Dynamic Size*: The linked list grows and shrinks dynamically, meaning you don't need to worry about the size of the queue ahead of time.
* *Constant Time Operations*: Both the enqueue (at the rear) and dequeue (from the front) are `O(1)` operations since you're just manipulating pointers.
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
* *Fixed Capacity*: The array has a fixed size. If the queue grows beyond that size, you must resize the array, which involces copying all the elements to a new array--an `O(n)` operation.
* *Wasted Space*: If the queue is significantly smaller than the array's capacity, you end up wasting memory.
* *Potentially More Complex Enqueue/Dequeue*: Implementing a circular array adds complexity compared to a simple linked list. Keeping track of the wrap-around behavior for both front and rear indices requires careful attention.
### 3. Comparison
| Aspect | Linked List Queue | Array Queue |
| --- | --- | --- |
| *Memory Use* | Dynamic; no wasted space, but extra overhead for pointers. | Fixed or dynamically resized; some space may be wasted. |
| *Time Complexity* | `0(1)` for both enqueue and dequeue operations. | `0(1)` for enqueue and dequeue, but resizing is `O(n)` when necessary. |
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

## Prof's Notes (Transcribed with corrections)
### ADT: Stack
* Stacks: Overview
    * hold ordered list of elements
    * last-in, first-out (LIFO) ordering
    * The term "stack" is based on the concept of stacking new elements one on top of another as they arrive, and processing whatever is on top of the stack when we get the opportunity.
* Stack ADT
    * need to include the type of data being stacked
    * plus the typical stack operations. These include:
        * constructors to create an empty stack
        * destructors to clean up a stack once finished with it
        * a method which takes a new element and adds it to the stack, typically called `push`
        * a method to look at the element on the top of the stack, typically called `top`
        * a method to remove and discard the top stack element, typically called `pop`
        * a method which checks if the stack is full
        * a method which checks if the stack is empty
    * Note that, by convention, we can only examine the top stack element.
* Stack applications
    * language-parsing operations: evaluating computations, trying to derive meaning from text or from source code, etc
    * in information storage during program execution: storing parameters, local variables, and other key data for subroutine calls
    * Examples:
        * a stack-based algorithm for printing a string of characters backwards:
        * a stack-based algorithm for seeing if all the brackts matching in a source code file:
```
while not end-of-file:
    get the next character
    if the character is a left (open) bracket, push it on the stack
    if the character is a right (close) bracket
        if the stack is empty,
            generate an error message (unmatched closing bracket)
            and exit
        if the bracket type is different than the brack type on the 
            top of the stack, generate an error message (unmatched closing bracket) and exit
        otherwise pop the top bracket off the stack
        
    if the stack is not empty, generate an error message
        (unmatched opening bracket) and exit
```
* Array-based implementation
    * The header file: `stack.h`
```
#include
using namespace std;
#ifndef STACK_H
#define STACK_H

// DEFAULTMAX --- default maximum stack size
const int DEFAULTMAX = 128;

// StackElement is used to determine the type of
// data stored in the stack
typedef char StackElement;

// defaultelement can be used as a default
// stack element value
const char defaultelement = '\0';

// Stack class, using an array-based implementation,
// where the constructor dynamically allocates
// the array using either the DEFAULTMAX size or
// a size specified by passing a positive integer
// parameter to the constructor
//
// the usual stack operations are available:
//      top, pop, push, isempty, and isfull
//
class stack {
    public:
        stack();            // default constructor
        stack(int size);    // constructor for passed size
        ~stack();           // destructor
        // push new data on stack
        void push(StackElement data);
        void pop();         // remove the top stack element
        // get a copy of top stack element
        StackElement top();
        bool isempty();     // return True iff stack is empty
        bool isfull();      // return True iff stack is full
    private:
        StackElement *sptr;
        int maxsize;
        int currentsize;
};
#endif
```
* The stack implementation: stack.cpp
```
#include "stack.h"
//  privately accessible data fields
//  for the stack class:
//      StackElement *sptr;
//      int maxsize;
//      int currentsize;

// default constructor, the maximum stack size is 
//      determined by DEFAULTMAX const in stack.h
stack::stack()
{
    maxsize = DEFAULTMAX;
    currentsize = 0;
    sptr = new StackElement[maxsize];
}

// constructor using the passed size
// as the maximum stack size
// if the passed size is a positive integer,
// otherwise uses DEFAULTMAX
stack::stack(int size)
{
    if (size > 0) maxisize = size;
    else maxsize = DEFAULTMAX;
    currentsize = 0;
    sptr = new StackElement[maxsize];
}

// destructor - deallocate stack space
stack::~stack()
{
    delete [] sptr;
}

// push new data on stack
void stack::push(StackElement data)
{
    // check to ensure stack is not already full
    if (currentsize < maxsize) {
        // add new element to top space on stack
        // and increment size counter
        // (index of top element)
        sptr[currentsize++] = data
    } else {
        cerr << "Cannot push onto a full stack" << endl;
    }
}

/ remove top element
void stack::pop()
{
    // check to ensure stack is not already empty
    if (currentsize > 0) {
        // decrement size counter
        // (which is also index of top element)
        currentsize--;
    } else {
        cerr << "Cannot pop from an empty stack"
             << endl;
    }
}

// get copy of top stack element
StackElement stack::top()
{
    // check to ensure stack is not currently empty
    if (currentsize > 0) {
        // return copy of top element
        return (sptr[currentsize-1]);
    } else {
        cerr << "Cannot examine top of empty stack, "
             << "returning default value" << endl;
        return defaultelement;
    }
}

// return True iff stack is empty
bool stack::isempty()
{
    return (currentsize == 0);
}

// return True iff stack is full
bool stack::isfull()
{
    return (currensize == maxsize);
}
```
* Stack Application Example
 * This application takes a series of command line arguments and prints each argument backwards, using a stack to reverse the characters in each string:
```
#include "stack.h"
using namespace std;
// this program takes each of its command line
// arguments and uses a stack to print the argument
// out backwards

void printbackwards(char *str);

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        printbackwards(argv[i]);
        cout << " ";
    }
    cout << endl;
    return 0;
}

void printbackwards(char *str)
{
    int index = 0;
    int length;
    stack *mystack;

    // allocate a stack just a little bigger 
    // than you need
    length = strlen(str);
    mystack = new stack(length+1);
    
    // push the string contents onto the stack
    // one character at a time until you hit
    // the end of the string
    while (index < length) {
        mystack->push(str[index]);
        index++;
    }

    // pop the stack contents off and print them
    // one at a time until the stack is empty
    while (mystack->isempty() == False) {
        cout << mystack->top();
        mystack->pop();
    }

    delete mystack;
}
```
* Stack Application Example
 * This application takes a series of command line arguments and determins whether or not each is a palindrome (i.e., is spelled the same way forward and backwards) using a stack to check the characters in each string:
 ```
 #include "stack.h"
 using namespace.std;
 // this program takes each of its command line
 // arguments and uses a stack to determine
 // if the argument is a palindrome

 bool ispalindrome(char *str);

 int main(int argc, char *argv[])
 {
    for (int i = 0; i < argc; i++) {
        cout << argv[i];
        if (ispalindrome(argv[i])) {
            cout << " is a palindrome" << endl;
        } else {
            cout << " is not a palindrome << endl;
        }
    }
    return 0;
 }

 bool ispalindrome(char *str)
 {
    int index = 0;
    int length;
    stack *mystack;

    length = strlen(str);
    mystack = new stack(length+1);

    // push the string contents onto the stack
    // one character at a time until you
    // hit the end of the string
    while (str[index] != '\0') {
        mystack->push(str[index]);
        index++;
    }

    // pop the stack contents off and compare them
    // to the string contents one at a time until
    // you find a difference or the stack is empty
    index = 0;
    while (!(mystack->isempty())) {
        if (mystack->top() != str[index++]) {
            delete mystack;
            return false;
        } else {
            mystack->pop();
        }
    }

    delete mystack;
    return true;
 }
 ```
### ADT: Queue
* Queues: Overview
    * Queue ADT: first in, first out (FIFO)
    * a constructor, which creates and initializes a new (empty) queue
    * an Enqueue operation, which takes a new data item and (as long as the queue is not full) adds it to the end of the queue
    * a Dequeue operation, which removes a data item from the front of the queue (as long as the queue is not empty) and returns it
    * a destructor, which deallocates a queue which is no longer needed
    * an isempty operation, which returns true if the queue is empty and false otherwise
    * an isfull operation, which returns true if the queue is full and false otherwise
    * a getsize operation, which returns a count of the number of items currently in the queue
* Pointer-based Queue Interface
```
class Queue {
    public:
        // the public interface
        Queue();            // initializes queue with default maxsize
        Queue(int max)      // initializes queue with specified maxsize
        ~Queue();           // deallocates queue
        void enqueue(QElem& e)  // adds e to queue if queue isn't full
        QElem & dequeue();  // removes/returns front queue element
                            // if queue isn't empty
        int getsize();      // returns current count of queue elements
        bool isempty();     // returns true iff queue is empty
        bool isfull();      // returns true iff queue is full
        void printQ();      // prints current queue contents
    
    private:
        // the "inaccessible" implementation details
        struct Node {
            QElem *data;
            Node *prev;
            Node *next;
        };
        Node *Q;        // a pointer to the front queue element
        int maxQsize;   // the chosen maximum queue size
        int actQsize;   // the actual number of elements in queue
};
```
* Implementation
```
#include "pointerq.h"

Queue::Queue()
{
    Q = new Node;
    maxQsize = DEFAULTMAXSIZE;
    actQsize = 0;
    Q->prev = Q;
    Q->next = Q;
    Q->data = NULL;
}

Queue::Queue(int max)
{
    Q = new Node;
    maxQsize = max;
    actQsize = 0;
    Q->prev = Q;
    Q->next = Q;
    Q->data = NULL;
}

Queue::~Queue()
{
    Node *temp;
    while (Q->next != Q) {
        Q->next = Q->next->next;
        delete Q->next->prev;
        Q->next->prev = Q;
    }
    delete Q;
    actQsize = 0;
    maxQsize = DEFAULTMAXSIZE;
}

void Queue::enqueue(QElem & e)
{
    Node *temp = NULL;
    if (actQsize < maxQsize) {
        temp = new Node;
    }
    if (temp == NULL) {
        throw string("ERROR: queue overflow");
    }
    temp->data = &e;
    temp->prev = Q->prev;
    temp->next = Q;
    Q->prev->next = temp;
    Q->prev = temp;
    actQsize++;
}

QElem & Queue::dequeue()
{
    if (actQsize == 0) {
        throw string("ERROR: queue underflow");
    }
    QElem & e = *(Q->next->data);
    Q->next = Q->next->next;
    delete Q->next->prev;
    Q->next->prev = Q;
    actQsize--;
    return e;
}

int Queue::getsize()
{
    return actQsize;
}

bool Queue::isempty()
{
    return (actQsize == 0);
}

bool Queue::isfull()
{
    return (actQsize == maxQsize);
}

void Queue::printQ()
{
    cout << "The queue has " << actQsize << " of " << maxQsize;
    cout << " possible elements:" << endl;

    Node *temp = Q->next;
    int i = 0;
    while (temp != Q) {
        cout << temp->data;
        i++;
        if (((i % 5) == 0) || (i == actQsize))
            cout << endl;
        else cout << " ";
    }
}
```
* Array Queue Interface
```
class Queue {
    public:
        Queue();            // initializes queue with default maxsize
        Queue(int max);     // initializes queue with specified maxsize
        ~Queue();           // deallocates queue
        void enqueue(QElem & e);    // adds e to queue if queue isn't full
        QElement & dequeue();   // removes/returns front queue element
                                // if queue isn't empty
        int getsize();      // returns current count of queue elements
        bool isempty();     // returns true iff queue is empty
        bool isfull();      // returns true iff queue is empty
        void printQ();      // prints current queue contents
    
    private:
        QElem **Q;      // a pointer to the front queue element
        int maxQsize;   // the chosen maximum queue size
        int actQsize;   // the actual number of elements in the queue
        int front;      // current position of the first element in queue
        int back;       // current position of the last element in queue
};
```
* Implementation
```
#include "arrayq.h"

Queue::Queue()
{
    Q = new (QElem *)[DEFAULTMAXSIZE];
    maxQsize = DEFAULTMAXSIZE;
    actQsize = 0;
    front = 0;
    back = -1;
}

Queue::Queue(int max)
{
    Q = new (QElem *)[max];
    maxQsize = max;
    actQsize = 0;
    front = 0;
    back = -1;   
}

Queue::~Queue()
{
    delete [] Q;
    front = 0;
    back = -1;
    actQsize = 0;
    maxQsize = 0;
}

void Queue::enqueue(QElem & e)
{
    if (actQsize >= maxQsize) {
        throw string("ERROR: queue overflow");
    }
    back++;
    back = back % maxQsize;
    Q[back] = &e;
    actQsize++;
}

QElem & Queue::dequeue()
{
    if (actQsize == 0) {
        throw string ("ERROR: queue underflow");
    } else {
        QElem & e = *Q[front];
        front++;
        front = front % maxQsize;
        actQsize--;
        return e;
    }
}

int Queue::setsize()
{
    return actQsize;
}

boolean Queue::isempty()
{
    return (actQsize == 0);
}

boolean Queue:isfull()
{
    return (actQsize == maxQsize);
}

void Queue::printQ()
{
    int index;
    index = front;
    cout << "The queue has " << actQsize << " of " << maxQsize;
    cout << " possible elements:" << endl;

    for (int i = 1, index = front; i <= actQsize; i++, index++) {
        index = index % maxQsize;
        cout << *Q[index];
        if (((i % 5) == 0) || (i == actQsize))
            cout << endl;
        else
            cout << " ";
    }
}