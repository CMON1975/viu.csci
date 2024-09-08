#include "Queue.h"
// Test the Queue implementation
int main()
{
    Queue q(5); // Create a queue with capacity 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();

    q.enqueue(60);

    cout << "Front element: " << q.peek() << endl;

    return 0;
}