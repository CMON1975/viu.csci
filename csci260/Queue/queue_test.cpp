// queue_test.cpp
#include <iostream>
#include "Queue.h"

using std::cerr;
using std::cout;
using std::endl;
using std::overflow_error;
using std::underflow_error;

int main()
{
    // Declare the Queue outside the try blocks
    Queue q(5);

    try
    {
        // Enqueue elements into the queue
        cout << "Enqueuing elements: 10, 20, 30, 40, 50" << endl;
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);

        // Attempt to enqueue another element to a full queue
        cout << "Attempting to enqueue 60 into a full queue..." << endl;
        q.enqueue(60); // This should throw an exception
    }
    catch (const overflow_error &e)
    {
        cerr << "Overflow error: " << e.what() << endl;
    }

    try
    {
        // Dequeue elements from the queue
        cout << "Dequeuing elements:" << endl;
        while (!q.isEmpty())
        {
            cout << q.dequeue() << " ";
        }
        cout << endl;

        // Attempt to dequeue from an empty queue
        cout << "Attempting to dequeue from an empty queue..." << endl;
        q.dequeue(); // This should throw an exception
    }
    catch (const underflow_error &e)
    {
        cerr << "Underflow error: " << e.what() << endl;
    }

    try
    {
        // Peek at the front element of an empty queue
        cout << "Attempting to peek at an empty queue..." << endl;
        int frontElement = q.peek(); // This should throw an exception
        cout << "Front element is: " << frontElement << endl;
    }
    catch (const underflow_error &e)
    {
        cerr << "Underflow error: " << e.what() << endl;
    }

    return 0;
}
