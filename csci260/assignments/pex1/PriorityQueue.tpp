// PriorityQueue.tpp

#include "PriorityQueue.h"

using std::out_of_range;
using std::swap;

// maintains heap by moving index element upwards
template <typename T>
void MinHeap<T>::heapifyUp(size_t index)
{
    while (index > 0)
    {
        size_t parentIndex = (index - 1) / 2;
        if (heap[index] < heap[parentIndex])
        {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        }
        else
        {
            break;
        }
    }
}

// maintains heap by moving index element downwards
template <typename T>
void MinHeap<T>::heapifyDown(size_t index)
{
    size_t smallest = index;
    size_t size = heap.size();

    while (true)
    {
        size_t leftChild = 2 * index + 1;
        size_t rightChild = 2 * index + 2;

        if (leftChild < size && heap[leftChild] < heap[smallest])
        {
            smallest = leftChild;
        }
        if (rightChild < size && heap[rightChild] < heap[smallest])
        {
            smallest = rightChild;
        }

        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            index = smallest;
        }
        else
        {
            break;
        }
    }
}

// enqueue new element
template <typename T>
void MinHeap<T>::insert(const T &value)
{
    heap.push_back(value);      // add new at heap end
    heapifyUp(heap.size() - 1); // restore heap
}

// get root element
template <typename T>
const T &MinHeap<T>::getMin() const
{
    if (heap.empty())
    {
        throw std::out_of_range("Heap is empty");
    }
    return heap[0]; // root
}

// remove and return root
template <typename T>
T MinHeap<T>::extractMin()
{
    if (heap.empty())
    {
        throw out_of_range("Heap is empty");
    }
    T minValue = heap[0];
    heap[0] = heap.back(); // move last element to root
    heap.pop_back();       // remove last element
    if (!heap.empty())
    {
        heapifyDown(0); // restore heap
    }
    return minValue;
}

// empty check
template <typename T>
bool MinHeap<T>::isEmpty() const
{
    return heap.empty();
}

// heap size
template <typename T>
size_t MinHeap<T>::size() const
{
    return heap.size();
}