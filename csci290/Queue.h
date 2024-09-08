#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept> // For standard exceptions
using namespace std;

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
    Queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~Queue()
    {
        delete[] arr;
    }

    // Check if the queue is full
    bool isFull() const
    {
        return size == capacity;
    }

    // Check if the queue is empty
    bool isEmpty() const
    {
        return size == 0;
    }

    // Enqueue (add an element to the rear)
    void enqueue(int element)
    {
        if (isFull())
        {
            throw overflow_error("Queue is full! Cannot enqueue.");
        }

        // Circularly increment rear index
        rear = (rear + 1) % capacity;
        arr[rear] = element;
        size++;
    }

    // Dequeue (remove an element from the front)
    int dequeue()
    {
        if (isEmpty())
        {
            throw underflow_error("Queue is empty! Cannot dequeue.");
        }

        int element = arr[front];
        // Circularly increment front index
        front = (front + 1) % capacity;
        size--;
        return element;
    }

    // Peek (get the front element)
    int peek() const
    {
        if (isEmpty())
        {
            throw underflow_error("Queue is empty! Cannot peek.");
        }
        return arr[front];
    }

    // Get current size of the queue
    int getSize() const
    {
        return size;
    }
};

#endif
