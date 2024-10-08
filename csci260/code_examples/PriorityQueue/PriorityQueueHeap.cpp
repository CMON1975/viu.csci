#include <iostream>
#include <vector>
#include <stdexcept>

using std::swap;
using std::vector;
using std::runtime_error;
using std::cout;

class PriorityQueueHeap {
private:
    vector<int> heap;

    void siftUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] >= heap[index])
                break;
            swap(heap[parent], heap[index]);
            index = parent;
        }
    }

    void siftDown(int index) {
        int size = heap.size();
        while (index < size) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest == index)
                break;

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty())
            throw runtime_error("Priority queue is empty");
        int maxValue = heap.front();
        heap.front() = heap.back();
        heap.pop_back();
        if (!heap.empty())
            siftDown(0);
        return maxValue;
    }

    bool isEmpty() const {
        return heap.empty();
    }
};