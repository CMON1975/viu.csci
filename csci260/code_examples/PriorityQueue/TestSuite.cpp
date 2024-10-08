#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include "PriorityQueueArray.cpp"
#include "PriorityQueueHeap.cpp"

using std::vector;
using std::mt19937;
using std::uniform_int_distribution;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::cout;

int main() {
    const int dataSize = 200000; // adjust as needed
    vector<int> data(dataSize);

    // generate random data
    mt19937 rng(42);    // fixed see for reproducibility
    uniform_int_distribution<int> dist(1, 200000);
    for (int &val : data) {
        val = dist(rng);
    }

    // heap-based priority queue test
    {
        PriorityQueueHeap heapPQ;
        auto start = high_resolution_clock::now();

        // insertions
        for (int val : data) {
            heapPQ.insert(val);
        }

        // extractions
        while (!heapPQ.isEmpty()) {
            heapPQ.extractMax();
        }

        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;
        cout << "Heap-based PQ Time: " << elapsed.count() << " seconds\n";
    }

    // sorted array-based priority queue test
    {
        PriorityQueueArray sortedArrayPQ;
        auto start = high_resolution_clock::now();

        // insertions
        for (int val : data) {
            sortedArrayPQ.insert(val);
        }

        // extractions
        while (!sortedArrayPQ.isEmpty()) {
            sortedArrayPQ.extractMax();
        }

        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;
        cout << "Sorted Array-based PQ Time: " << elapsed.count() << " seconds\n";
    }

    return 0;
}