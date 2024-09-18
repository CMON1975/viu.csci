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
    void heapifyUp(size_t index);

    // maintains heap by moving index element downwards
    void heapifyDown(size_t index);

public:
    // enqueue new element
    void insert(const T &value);

    // get root element
    const T &getMin() const;

    // remove and return root
    T extractMin();

    // empty check
    bool isEmpty() const;

    // heap size
    int size() const;
};

#include "PriorityQueue.tpp"

#endif // PRIORITYQUEUE_H