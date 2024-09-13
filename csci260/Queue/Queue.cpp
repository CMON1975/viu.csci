// Queue.cpp
#include "Queue.h"
#include <stdexcept>

using std::overflow_error;
using std::underflow_error;

Queue::Queue(int capacity)
{
    this->capacity = capacity;
    arr = new int[capacity];
    front = 0;
    rear = -1;
    size = 0;
}

Queue::~Queue()
{
    delete[] arr;
}

bool Queue::isFull() const
{
    return size == capacity;
}

bool Queue::isEmpty() const
{
    return size == 0;
}

void Queue::enqueue(int element)
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

int Queue::dequeue()
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

int Queue::peek() const
{
    if (isEmpty())
    {
        throw underflow_error("Queue is empty! Cannot peek.");
    }
    return arr[front];
}

int Queue::getSize() const
{
    return size;
}
