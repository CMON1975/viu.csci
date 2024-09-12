# Lecture 4: ADT Heap
During the lecture I wondered what was the best method for showing test cases and results for C++ code. According to GPT it's Google Test, but that level of unit testing and reporting is beyond the scope of CSCI 260. To keep it simple, I'll be using `script` with hand-rolled standard tests. Basically, the professor is only interested in seeing a logged output of the implemented testing.

This lecture opened with a diagram of a complete tree (as per the last lecture) and an explanation of how to handle an individual node with pointers:
| `parent*` |
| --- | 
| `data: priority(item)` |

| `left child*` | `right child*` |
| --- | --- |

However, this is a waste of memory.
**Note**: In a complete tree, count from the root at `0` and in-order across descending levels from left to right.

**for node $i$:** 
* parent at $(i - 2) /2$
* left at $i * 2 + 1$
* right at $i * 2 + 2$
1. root at `A[0]`
2. `A[i]'s` parent at `A[(i - 1) / 2] if i > 0`
`A[i]`'s left child at `A[i * 2 + 1] if i * 2 + 1 < size`
`A[i]`'s right child at `A[i * 2 + 2] if i * 2 + 2 < size`
3. next available space at `A[size] if size < capacity`
4. last item at `A[size-1]`

```
// interface
class Heap {
    public:
        Heap(int capacity = 100);  // default capacity is 100 if no argument is passed
        void insert(double, Item &obj);
            throw (FullHeap);

        Item &removeMin();
            throw (EmptyHeap);
        ~Heap();
        bool isEmpty();
        bool isFull();
        int getSize();
        double minKey();    // bonus functionality
        Item &minItem();    // bonus functionality

    private:
        struct Cell {
            double priority;
            Item *obj;
        };
        Cell *A;
        int capacity;
        int size;
        void upheap(int curr);      // recursion
        void downheap(int curr);    // recursion
        void swap(int i, int j);

    Heap::Heap(int capacity) {
        this->capacity = capacity;
        A = new Cell[this->capacity];
        size = 0;
    }

    // further definitions
    bool Heap:isEmpty() { return size == 0; }
    bool Heap:isFull() { return size == capacity; }

    void Heap::insert(double key, Item &obj) {
        if (size >= capacity)
            throw FullHeap;
        A[size].priority = key;
        A[size].obj = &obj;
        ++size;
        upheap(size - 1);
    }

    // tail-recursive function, recursive
    void Heap::upheap(int curr)
    {
        if (curr == 0)
            return;
        if (A[curr].priority >= A[(curr - 1) / 2].priority)
            return;
        swap(curr, (curr-1) / 2);
    }

    // iterative version of above (more efficient)
    void Heap::upheap(int curr)
    {
        int parent = (curr - 1) / 2;
        while( curr > 0 && A[curr].priority < A[parent].priority) {
            swap(curr, parent);
            curr = parent;
            parent = (curr - 1) / 2;
        }
    }

    Item &Heap::removeMin()
    {
        if (size == 0)
            throw EmptyHeap;
        Item &toRemove = *(A[0].obj);
        swap (0, size - 1);
        --size;
        downheap(0);
        return toRemove;
    }

    void Heap::downheap(int curr)
    {
        int left = (curr * 2) + 1;        
        int right = (curr * 2) + 2;
        if (left >= size) // curr is leaf node
            return;
        if (right >= size)
            right = -1; // no right child

        int minPos = curr;
        if (A[left].priority < A[minPos].priority)
            minPos = left;
        if (right != -1 && A[right].priority < A[minPos].priority)
            minPos = right;

        if (minPos != curr) {
            swap(curr, minPos);
            downheap(minPos);
        }
    }

    void Heap::swap(int i, int j) {
        Cell temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
};

// exception classes
class FullHeap : public std::exception {
    const char* what() const noexcept override {
        return "Heap is full!";
    }
};

class EmptyHeap : public std::exception {
    const char* what() const noexcept override {
        return "Heap is empty!";
    }
}
```
## Heap Sort
Time complexity: $O(n \log n)$
### Steps in Heap Sort:
1. **Build a heap**:
    - First, you take the unsorted array and insert all its elements into a heap (usually a MaxHeap for ascending order sorting, though MinHeap can be used for descending order sorting). The heap helps in maintaining the largest (or smallest) element at the root.
    - If you're using a MaxHeap, the largest element will always be at the root (`A[0]`), making it easy to extract the maximum.
2. **Extract elements from the heap:**
    - After building the heap, you repeatedly remove the root element (which is the maximum in a MaxHeap) and place it at the end of the array. This process leaves the remaining elements in the heap to be sorted.
    - After each extraction, the heap property is restored using the **downheap** operation to maintain the structure.

### Detailed Procedure:
1. **Heapify the array:**
    - You first "heapify" the array, which means converting it into a MaxHeap (if sorting in ascending order). You can do this by inserting each element one by one into the heap, or more efficiently, by using the **heapify** process on the entire array. The heapify process ensures that the array satisfies the MaxHeap property.
2. **Sort by repeatedly removing the root:**
    - Once the array is heapified, you can sort if by repeatedly removing the root (the largest element in a MaxHeap) and swapping it with the last element of the heap. After each swap, you reduce the heap size and restore the heap property using `downheap`.

### High-level Pseudocode for Heap Sort:
```
// Function to heapify a subtree rooted at index i
void downheap(int A[], int n, int i) {
    int largest = i;        // initialize largest as root
    int left = 2 * i + 1;   // left child
    int right = 2 * i + 2;  // right child

    // if left child is larger than root
    if (left < n && A[left] > A[largest])
        largest = left;

    // if the right child is larger than the largest so far
    if (right < n && A[right] > A[largest])
        largest = right;

    // if largest is not root, swap and continue heapify process
    if (largest != i) {
        swap(A[i], A[largest]);
        downheap(A, n, largest);
    }
}

// main function to do heap sort
void heapSort(int A[], int n) {
    // build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        downheap(A, n, i);

    // extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // move current root (largest) to end
        swap(A[0], A[i]);

        // call downheap on the reduced heap
        downheap(A, i, 0);
    }
}
```
### Explanation:
1. **Heapify the array:** The first `for` loop starts from the middle of the array (since it's a binary tree) and applies `downheap` to each element. This builds the MaxHeap.
2. **Sorting:** The second `for` loop extracts the maximum element (root of the heap) by swapping it with the last element of the unsorted portion. The heap size is reduced by one, and the `downheap` operation is applied to restore the heap property for the remaining unsorted elements.

### Time Complexity:
* **Heapify step:** $O(n)$
* **Extract and restore heap step:** $O( n \log n)$
Thus, the overall time complexity of Heap Sort is $O(n \log n)$, which makes it efficient for large datasets.

### Summary of Heap Sort:
1. **Build a heap** from the input data.
2. **Extract the maximum (or minimum)** repeatedly to get the sorted order.
3. The largest (or smallest) elements are placed at the end of the array, resulting in a sorted array.
