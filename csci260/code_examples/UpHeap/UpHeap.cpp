#include <iostream>
#include <vector>
#include <algorithm>    // for swap

using std::swap;
using std::vector;
using std::cout;
using std::endl;

// function to perform upheap operation in a max-heap
void upHeap(vector<int>& heap, int index) {
    while (index > 0) {
        // calculate parent index
        int parentIndex = (index - 1) / 2;

        // if the current element is greater than the parent, swap them
        if (heap[index] > heap[parentIndex]) {
            swap(heap[index], heap[parentIndex]);

            // move up to the parent's index
            index = parentIndex;
        } else {
            // the heap property is restored
            break;
        }
    }
}

// heap print
void printHeap(const vector<int>& heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

// example usage
int main() {
    vector<int> heap; // our heap represented as a vector

    // elements to insert into the heap
    vector<int> elementsToInsert = {15, 10, 20, 17, 8};

    // insert each element and perform upHeap
    for (int elem : elementsToInsert) {
        // add the new element to the end of the heap
        heap.push_back(elem);

        // restore the heap property
        upHeap(heap, heap.size() - 1);

        // print the heap after each insertion
        cout << "Heap after inserting " << elem << ": ";
        printHeap(heap);
    }

    return 0;
}