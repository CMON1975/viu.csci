## Day 10: Heaps vs. Sorted Arrays for Priority Queues
- **Topics Covered**:
    - Advantages and disadvantages of using heaps compared to sorted arrays.
- **Study Activities**:
    - **Performance Analysis**: Compare time complexities for insertion and deletion.
    - **Use Cases**: Determine scenarios where one implementation is preferred over the other.
- **Practice**:
    - Create a priority queue using both a heap and a sorted array.
    - Measure and compare the performance of both implementations with large datasets.

---
### 1. Compare the time complexities for insertion and deletion in heaps vs. sorted arrays for priority queues.
**Heaps (Binary Heaps):**
- **Insertion:** O(log n)
- **Deletion (Extract Max/Min):** O(log n)

**Sorted Arrays:**
- **Insertion:** O(n)
- **Deletion (Extract Max/Min):** O(1)

**Explanation:**
- **Heaps:** In a binary heap, each insertion requires "sifting up" the new element to maintain the heap property, which takes O(log n) time because the height of the heap is log n. Deletion (specifically, extracting the max or min element) involves removing the root and then "sifting down" the last element to restore the heap property, also taking O(log n) time.
- **Sorted Arrays:** Insertion into a sorted array requires finding the correct position and shifting all subsequent elements to make room, resulting in O(n) time complexity. However, deletion of the highest or lowest priority element is simply accessing and removing the first or last element, which is O(1).

---
### 2. In what scenarios would one implementation be preferred over the other?
**Use a Heap-Based Priority Queue When:**
- **Frequent Insertions and Deletions:** If your application requires frequent additions and removals, the O(log n) insertion and deletion times of a heap make it more efficient overall.
- **Dynamic Data:** When the dataset changes frequently, and you need balanced performance for both insertions and deletions.
- **Memory Efficiency:** Heaps generally use less memory overhead compared to maintaining a sorted array, especially for large datasets.

**Use a Sorted Array-Based Priority Queue When:**
- **Frequent Deletions, Rare Insertions:** If your application involves many deletions but few insertions, the O(1) deletion time is advantageous.
- **Static or Nearly Static Data:** When the dataset doesn't change often, and you need balanced performance for both insertions and deletions.
- **Fast Access Needed:** When immediate access to the highest or lowest priority element is critical.

**Scenarios Examples:**
- **Heap:** Real-time systems where tasks with varying priorities are continuously added and need timely scheduling.
- **Sorted Array:** Financial systems where a sorted order of transaction is maintained, and quick access to the highest priority transaction is necessary.

---
### 3. Create a priority queue using a heap. Pseudocode and C++.
**Pseudocode:**
```
Class PriorityQueue:
    Heap heap

    Function insert(value):
        heap.insert(value)

    Function extractMax():
        return heap.extractMax()

    Function isEmpty():
        return heap.isEmpty()

Class Heap:
    List array

    Function insert(value):
        array.append(value)
        siftUp(array.size - 1)

    Function extracMax():
        if array.size == 0:
            throw Error("Heap is empty")
        maxValue = array[0]
        array[0] = array[array.size - 1]
        array.pop()
        siftDown(0)
        return maxValue

    Function siftUp(index):
        while index > 0:
            parent = (index - 1) // 2
            if array[parent] >= array[index]:
                break
            swap(array[parent], array[index])
            index = parent
    
    Function siftDown(index):
        size = array.size
        while true:
            largest = index
            left = 2 * index + 1
            right = 2 * index + 2

            if left < size and array[left] > array[largest]:
                largest = left
            if right < size and array[right] > array[largest]:
                largest = right

            if largest = index:
                break

            swap(array[index], array[largest])
            index = largest
```

**C++ Implementation:**
```
#include <iostream>
#include <vector>
#include <stdexcept>

using std::swap;
using std::vector;
using std::runtime_error;
using std::cout;

class PriorityQueue {
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

// example usage
int main() {
    PriorityQueue pq;
    pq.insert(15);
    pq.insert(10);
    pq.insert(20);
    pq.insert(17);

    while (!pq.isEmpty()) {
        cout << pq.extractMax() << " ";
    }
    // output: 20 17 15 10
    return 0;
}
```

---
### 4. Create a priority queue using a sorted array. Pseudocode and C++.
**Pseudocode:**
```
Class PriorityQueue:
    List array  // sorted in decreasing order

    Function insert(value):
        if array.isEmpty():
            array.append(value)
        else:
            position = binarySearchInsertPosition(value)
            array.insert(position, value)

    Function extraMax():
        if array.isEmpty():
            throw Error("Priority queue is empty")
        return array.removeAt(0)

    Function isEmpty():
        return array.size == 0

    Function binarySearchInsertPosition(value):
        low = 0
        high = array.size
        while low < high:
            mid = (low + high) // 2
            if array[mid] < value:
                high = mid
            else:
                low = mid + 1
        return low
```

**C++ Implementation:**
```
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::vector;
using std::lower_bound;
using std::greater;
using std::runtime_error;
using std::cout;

class PriorityQueue {
private:
    vector<int> array;  // sorted in decreasing order

public:
    void insert(int value) {
        auto it = lower_bound(array.begin(), array.end(), value, greater<int>());
        array.insert(it, value);
    }

    int extractMax() {
        if (array.empty())
            throw runtime_error("Priority queue is empty");
        int maxValue = array.front();
        array.erase(array.begin());
        return maxValue;
    }

    bool isEmpty() const {
        return array.empty();
    }
};

// example usage
int main() {
    PriorityQueue pq;
    pq.insert(15);
    pq.insert(10);
    pq.insert(20);
    pq.insert(17);

    while (!pq.isEmpty()) {
        cout << pq.extractMax() << " ";
    }
    // output: 20 17 15 10
    return 0;
}
```

---
### 5. Measure and compare the performance of both implementations with large datasets.
**Experimental Setup:**
- **Datasets:** Generate large datasets with sizes $n = 10^4, 10^5, 10^6$.
- **Operations:** Perform a series of insertions followed by extractions.
- **Environment:** Use the same machine and compiler settings to ensure consistency.

**Testing Procedure:**
1. **Data Generation:** Use random number generators to create datasets.
2. **Timing:** Use high-resolution timers to measure the time taken for insertions and deletions seperately.
3. **Repetition:** Run each test multiple times to obtain average timings.

**Sample Code for Performance Measurement:**
```
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
    const int dataSize = 1000000; // adjust as needed
    vector<int> data(dataSize);

    // generate random data
    mt19937 rng(42);    // fixed see for reproducibility
    uniform_int_distribution<int> dist(1, 1000000);
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
```
**Expected Results:**
- **Heap-based Priority Queue:**
    - **Insertion Time:** Faster due to O(log n) per insertion.
    - **Deletion Time:** Slower per deletion compared to sorted array but overall efficient.
- **Sorted Array-based Priority Queue:**
    - **Insertion Time:** Significantly slower due to O(n) per insertion.
    - **Deletion Time:** Very fast due to O(1) per deletion.

**Analysis:**
- **Insertion Phase:** The heap-based implementation should complete insertions much faster than the sorted array-based implementation, especially as the dataset size increases.
- **Deletion Phase:** While the sorted array-based implementation has faster deletions, the overall time may still be higher due to the slow insertion phase.
- **Total Time:** The heap-based priority queue is expected to outperform the sorted array-based priority queue in total time for large datasets.

**Conclusion:**
- **Efficiency:** The heap-based priority queue is more efficient for applications involving large datasets with frequent insertions and deletions.
- **Scalability:** Heaps scale better with increasing data sizes due to logarithmic time complexities.
- **Use Cases:** Choose the implementation that best fits the specific requirements of your application, considering the trade-offs in time complexities for insertion and deletion operations.

---
**Note:** Actual performance may vary based on factors like hardware, compiler optimizations, and specific data characteristics. It's recommended to perform empirical tests tailored to your specific use case for accurate assessments.
