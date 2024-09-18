#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include <stdexcept>
#include <utility>

using std::vector;

template <typename T>
class MinHeap
{
private:
    vector<T> heap;

    // maintains heap by moving index element upwards
    void heapifyUp(int index);

    // maintains heap by moving index element downwards
    void heapifyDown(int index);

public:
    // enqueue new element
    void insert(const T &value);

    // get root element
    const T &getMin() const;

    // remove and return root
    T extractMin();

    // empty check
    bool isEmpty() const;
};

#include "PriorityQueue.tpp"

#endif // PRIORITYQUEUE_H