// Queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept> // For standard exceptions

class Queue
{
private:
    int *arr;     // Array to store queue elements
    int front;    // Index of the front element
    int rear;     // Index of the rear element
    int size;     // Current number of elements in the queue
    int capacity; // Maximum capacity of the queue

public:
    // Constructor
    Queue(int capacity);

    // Destructor
    ~Queue();

    // Check if the queue is full
    bool isFull() const;

    // Check if the queue is empty
    bool isEmpty() const;

    // Enqueue (add an element to the rear)
    void enqueue(int element);

    // Dequeue (remove an element from the front)
    int dequeue();

    // Peek (get the front element)
    int peek() const;

    // Get current size of the queue
    int getSize() const;
};

#endif // QUEUE_H
