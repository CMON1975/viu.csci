#include "PriorityQueue.h"

using std::out_of_range;
using std::swap;

// maintains heap by moving index element upwards
template <typename T>
void MinHeap<T>::heapifyUp(int index)
{
    if (index == 0)
        return; // root

    int parentIndex = (index - 1) / 2;
    if (heap[index] < heap[parentIndex])
    {
        std::swap(heap[index], heap[parentIndex]);
        heapifyUp(parentIndex); // tail-recursive
    }
}

// maintains heap by moving index element downwards
template <typename T>
void MinHeap<T>::heapifyDown(int index)
{
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
    {
        smallest = leftChild;
    }
    if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
    {
        smallest = rightChild;
    }

    if (smallest != index)
    {
        std::swap(heap[index], heap[smallest]);
        heapifyDown(smallest); // tail-recursive
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
        throw std::out_of_range("Heap is empty");
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