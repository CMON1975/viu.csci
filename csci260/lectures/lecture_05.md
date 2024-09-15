# Lecture 5: Set and Dictionary *Prof's Notes*
* Set: a collection of unique objects; Multi-set (Bag): a collection of objects.
* Operations on a set:
    - Membership check
    - Math operations: set union, set intersection, set difference
    - Set equivalency check
    - insert a new object into a set
    - remove an object from a set
    - Assistant functionalities: isEmpty, getSize, etc.
* Dictionary: A set of objects where each object can be uniquely identified by its key.
* Dictionary operations:
    - lookup
    - insert
    - remove
    - assistant operations
* Variations of Dictionary operations:
    - get all keys
    - get all objects
    - get all objects with a given key (for multi-set typed dictionary)
    - closest key before/after a given key
    - closest object before/after a given key/object
## Basic Implementation of Dictionary
### Basic common interface:
```
class Dictionary {
    public:
        Dictionary();
        Dictionary(int cap);
        ~Dictionary();
        Data &lookup(Key) throw (NotFound);
        Data &remove(Key) throw (NotFound);
        void insert(Key, Data &) throw (DuplicateKey, Full);
    // START unordered array:
    private:
        int capacity;
        int size;
        Key *keys;
        Data **data;
        int find(Key);
};

Dictionary::Dictionary()
{
    capacity = DEFAULTCAPACITY;
    size = 0;
    keys = new Key[capacity];
    data = new Data*[capacity];
}

Dictionary::Dictionary(int cap)
{
    if (cap <= 0)
        cap = DEFAULTCAPACITY;
    capacity = cap;
    size = 0;
    keys = new Key[capacity];
    data = new Data*[capacity];
}

Dictionary::~Dictionary()
{
    delete [] keys;
    delete [] data;
}

int Dictionary::find(Key k)
{
    for (int i = 0; i < size; ++i)
        if (keys[i] == k)
            return i;
    return -1;
}

Data &Dictionary::lookup(Key k) throw (NotFound)
{
    int index = find(k);
    if (index == -1)
        throw NotFound();
    return *(data[index]);
}

void Dictionary::insert(Key k, Data &d) throw (DuplicateKey, Full)
{
    if (size >= capacity)
        throw Full();
    int index = find(k);
    if (index != -1)
        throw DuplicateKey();

    keys[size] = k;
    data[size] = &d;
    ++size;
}

Data &Dictionary::remove(Key k) throw (NotFound)
{
    int index = find(k);
    if (index == -1)
        throw NotFound();
    
    Data &markedData = *(data[index]);
    --size;
    if (index < size) {
        keys[index] = keys[size];
        data[index] = data[size];
    }
    return markedData;
}
// END: unordered array
    // START: ordered array
        private: int capacity;
        int size;
        Key *keys;
        Data **data;
        int find(Key);
    };

Dictionary::Dictionary()
{
    capacity = DEFAULTCAPACITY;
    size = 0;
    keys = new Key[capacity];
    data = new Data*[capacity];
}

Dictionary::Dictionary(int cap)
{
    if (cap <= 0)
        cap = DEFAULTCAPACITY;
    capacity = cap;
    size = 0;
    keys = new Key[capacity];
    data = new Data*[capacity];
}

Dictionary::~Dictionary()
{
    delete [] keys;
    delete [] data;
}

int Dictionary::find(Key k)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (keys[mid] == k)
            return mid;
        else if (keys[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

Data &Dictionary::lookup(Key k) throw (NotFound)
{
    int index = find(k);
    if (index >= size || keys[index] !=k)
        throw NotFound();
    return *(data[index]);
}

void Dictionary::insert(Key k, Data &d) throw (DuplicateKey, Full) {
    if (size >= capacity)
        throw Full();
    int index = find(k);
    if (index < size && keys[index] == k)
        throw DuplicateKey();

    // Shift elements to the right to make space
    for (int i = size; i > index; --i) {
        keys[i] = keys[i - 1];
        data[i] = data[i - 1];
    }
    keys[index] = k;
    data[index] = &d;
    ++size;
}

Data &Dictionary::remove(Key k) throw (NotFound)
{
    int index = find(k);
    if (index >= size || keys[index] !=k )
        throw NotFound();

    Data &markedData = *(data[index]);
    --size;
    for( ; index < size; ++index) {
        keys[index] = keys[index + 1];
        data[index] = data[index + 1];
    }
    return markedData;
}
// END: ordered array
    // START: pointer-based list
    private:
        int capacity;
        int size;
        struct Node {
            Key key;
            Data *data;
            Node *prev;
            Node *next;
        };
        Node *find(Key);
        Node *list;
    };

Dictionary::Dictionary()
{
    capacity = 0;
    size = 0;
    list = new Node;
    list->prev = list->next = list;
}

Dictionary::Dictionary(int cap)
{
    capacity = cap;
    size = 0;
    list = new Node;
    list->prev = list->next = list;
}

Dictionary::~Dictionary()
{
    Node *ptr = list->next;
    while (ptr != list) {
        Node *temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
    delete list;
}

Dictionary::Node *Dictionary::find(Key k)
{
    Node *ptr = list->next;
    while (ptr != list && ptr->key != k)
        ptr = ptr->next;
    
    return ptr;
}

Data &Dictionary::lookup(Key k) throw (NotFound)
{
    Node *index = find(k);
    if (index == list)
        throw NotFound();
    return *(index->data);
}

void Dictionary::insert(Key k, Data &d) throw (DuplicateKey, Full)
{
    if (capacity > 0 && size >= capacity)
        throw Full();
    
    Node *index = find(k);
    if (index != list)
        throw DuplicateKey();

    Node *ptr = new Node;
    ptr->key = k;
    ptr->data = &d;
    ptr->next = list;
    ptr->prev = list->prev;
    list->prev->next = ptr;
    list->prev = ptr;
    ++size;
}

Data &Dictionary::remove(Key k) throw (NotFound)
{
    Node *index = find(k);
    if (index == list)
        throw NotFound();

    index->next->prev = index->prev;
    index->prev->next = index->next;
    Data &markedData = *(index->data);
    delete index;
    --size;
    return markedData;
}
// END: pointer-based list
class NotFound : public std::exception {
    const char *what() const noexcept override {
        return "Key not found in dictionary.";
    }
};

class DuplicateKey : public std::exception {
    const char *what() const noexcept override {
        return "Duplicate key insertion attempted.";
    }
};

class Full : public std::exception {
    const char *what() const noexcept override {
        return "Dictionary is full.";
    }
};

```
### Performance:
| &sp; | loopup | insert | remove |
| --- | --- | --- | --- |
| unordered array | $O(n)$ | $O(1)$ | $O(1)$ |
| ordered array | $O(\log n)$ | $O(n)$ | $O(n)$ |
| linked list | $O(n)$ | $O(1)$ | $O(1)$ |

# In-class Notes
## Heap Sort (con't)
**heap is always array-based**
```
void heapSort(double dataArray[], int arraySize) {
    int currentIndex, heapSize, leftChildIndex, rightChildIndex, smallestIndex;

    // **Heap Construction Stage (Building a Min-Heap)**
    for (int i = 1; i < arraySize; ++i) {
        currentIndex = i;
        // sift-up to maintain the min-heap property
        while (currentIndex > 0 && dataArray[currentIndex] < dataArray[(currentIndex - 1) / 2]) {
            // swap current node with its parent
            swap(dataArray, currentIndex, (currentIndex - 1) / 2);
            currentIndex = (currentIndex - 1) / 2; // move up to the parent
        }
    }

    // **Heap Sort Stage (Extracing Minimum Elements)**
    for (heapSize = arraySize - 1; heapSize > 0; --heapSize) {
        // move current smallest element to the end of the array
        swap(dataArray, 0, heapSize);
        currentIndex = 0;

        while (true) {
            leftChildIndex = 2 * currentIndex + 1;
            rightChildIndex = 2 * currentIndex + 2;
            smallestIndex = currentIndex;

            // find the smallest among current node and its children
            if (leftChildIndex < heapSize && dataArray[leftChildIndex] < dataArray[smallestIndex]) {
                smallestIndex = leftChildIndex;
            }
            if (rightChildIndex < heapSize && dataArray[rightChildIndex] < dataArray[smallestIndex]) {
                smallestIndex = rightChildIndex;
            }

            // if the smallest is not the current node, swap and continue sifting down
            if (smallestIndex != currentIndex) {
                swap(dataArray, currentIndex, smallestIndex);
                currentIndex = smallestIndex;
            } else {
                break; // the heap property is restored
            }
        }
    }
}

// helper function to swap two elements in the array A
void swap(double A[], int i, int j) {
    double temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
```

## In-place Sort
**Definition:**
An **in-place sorting algorithm** is one that sorts the elements by modifying the original data structure directly, using only a small, constant amount of extra memory. The algorithm may involve swapping, shifting, or moving elements within the data structure, but it doesn't require additional arrays or significant extra storage proportional to the input size.
**Key Points:**
1. **In-Place Sorting Definition:**
    - An in-place sorting algorithm rearranges the elements within the original data structure (e.g., an array) and uses only a small, constant amount of extra memory--typically $O(1)$ space.
    - It directly modifies the input data without requiring significant additional storage.
2. **Operations Beyond Swapping:**
    - Many in-place sorting algorithms involve operations other than swapping, such as shifting or moving elements.
        - **Insertion Sort**: Elements are shifted to make room for the element being inserted, without necessarily swapping.
        - **Shell Sort:** Similar to insertion sort but with a gap sequence; elements are moved over gaps.
3. **Recursion and Stack Space:**
    - Some in-place sorting algorithms use recursion (e.g., in-place quicksort), which requires additional stack space proportional to the depth of recursion ($O(\log n)$ for balanced partitions).
    - Despite this, they are often still considered in-place because the extra space isn't directly proportional to the input size $n$.

**Examples of in-place sorts:**
1. Insertion Sort
    - Builds the final sorted array one item at a time by comparing each new element to those already sorted and inserting it into the correct position.
2. Bubble Sort
    - Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
3. Quicksort (In-Place Version)
    - Divides the array into partitions and recursively sorts them. Uses a pivot element to partition the array into subarrays. Is in-place when implemented with partitioning schemes like Lomuto or Hoare's method.
4. Selection Sort
    - Repeatedly selects the minimum (or maximum) element from the unsorted portion and moves it to the end of the sorted portion.
5. Heap Sort
    - Converts the array into a max-heap or min-heap and then repeatedly extracts the largest (or smallest) element to build the sorted array.
6. Shell Sort
    - An extension of insertion sort that allows the exchange of items that are far apart by sorting elements at specific intervals.
7. Comb Sort
    - Improves on bubble sort by eliminating small values near the end of the list and reducing the gap between compared elements more efficiently.
8. Cocktail Shaker Sort
    - A variation of bubble sort that sorts in both directions on each pass through the list, effectively "shaking" the elements into place.
9. Gnome Sort
    - Moves elements to their proper positions by swapping them with preceding elements, similar to a roaming gnome swapping misplaced flower pots.
10. Cycle Sort
    - Minimizes the number of writes by determining the correct position of each element and placing it there.
11. Smooth Sort
    - A variation of heap sort that sorts neatly sorted sequences more efficiently.
12. In-Place Merge Sort (Optimized Versions)
    - Traditional merge sort requires $O(n)$ extra space, but optimized in-place versions exist that reduce space usage.
### Notes
- **Recursion Stack Space:**
    - Some algorithms like quicksotr use recursion, which adds extra space proportional to the depth of the recursion ($O(\log n)$ for balanaced partitions).
    - Despite this, they are generally considered in-place because the additional space is not proportional to the input size $n$.
- **Not-in-Place Algorithms:**
    - **Merge Sort:** Standard merge sort is not in-place because it requires $O(n)$ extra space for merging.
    - **Radix Sort and Counting Sort:** There are not in-place as they require additional arrays proportional to the input size.

### Stability
**Definition of Stability:**
- A sorting algorithm is said to be **stable** if it **preserves the relative order of records with equal keys** (values).
- In other words, if two elements are equal according to the sorting criterion, a stable sort will ensure that their order remains the same in the sorted output as it was in the input.

**Importance of Stability:**
- **Data Integrity:**
    - When sorting complex data structures (like records or objects with multiple fields), stability ensures that secondary information is not lost.
- **Multi-Level Sorting:**
    - Stability allows for sorting on multiple criteria by performing consecutive sorts on different keys.
    - For example, first sort by last name (stable sort), then by first name. The stability ensures that the ordering by first name doesn't distrupt the ordering by last name.
---
### Stable Sorting Algorithms
**Algorithms That Guarantee Stability:**
1. Insertion Sort:
    * **Time Complexity:** $O(n^2)$
    * **Usage:** Efficient for small datasets or nearly sorted data.
2. Merge Sort:
    * **Time Complexity:** $O(n \log n)$
    * **Trade-off:** Requires extra memory for merging.
3. Bubble Sort:
    - **Time Complexity:** $O(n^2)$
    - **Usage:** Generally not used due to inefficiency.
4. TimSort:
    - **Time Complexity:** $O(n \log n)$
    - **Usage:** Hybrid sorting algorithm used in Python's and Java's standard libraries.
5. Counting Sort:
    - **Time Complexity:** $O(n + k)$, where $k$ is the range of input values.
    - **Usage:** Efficient for integers within a limited range.
6. Radix Sort:
    - **Time Complexity:** $O(nk)$, where $k$ is the number of digits.
    - **Usage:** Useful for sorting numbers or strings with a fixed length.

## Time Efficiency
- **Little o:** Describes functions that grow **strictly slower** than a reference function.
- **Big O:** Provides an upper limit on how a function can grow.
- **Big Omega:** Provides a lower limit on the growth rate.
- **Little Omega:** Similar to little o, used to describe functions that grow **strictly faster** than a reference function.
- **Theta:** Indicates that two functions grow at the same rate, up to constant factors.
### Understanding the Relationships
- **Big O and Big Omega:**
    - Big O is like $<=$ (less than or equal to) in asymptotic terms.
    - Big Omega is like $>=$ (greater than or equal to).
    - They provide upper and lover bounds, respectively.
- **Theta:**
    - Theta is like $=$ (equal to) in asymptotic terms.
    - It means the function is both $O(g(n))$ and $Ω(g(n))$.
- **Little o and Little Omega:**
    - Little o is like $<$ (strictly less than).
    - Little omega is like $>$ (strictly greater than).
    - They provide strict bounds without constants.

## Sets
A set is a collection of unique objects. Map<key, obj>.
A multi-set or bag can be non-unique.
- insert
- remove
- membership check (check for existing unique)
    - oid or address

### Diamond inheritance problem.
Make sure to use the `virtual` keyword in C++ if a `Class D` is expected to inherit from `Class B` and `Class C` which both inherit from a `Class A`.