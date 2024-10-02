# Implementing Priority Queue with Unsorted Arrays
## Overview
- **Topics Covered**:
    - Removal operation in an unsorted array-based priority queue.
    - C++ implementation of the removal function.
- **Study Activities**:
    - **Algorithm Analysis**: Understand how removal works in an unsorted array.
    - **Code Practice**: Implement the removal function in C++.
    - **Time Complexity**: Analyze the time complexity of insertion and removal operations.
- **Practice**:
    - Modify the code to handle edge cases (e.g., when the array is empty).
    - Compare the efficiency of unsorted arrays versus other implementations.
## Questions
1. How does removal work in an unsorted array?
In an **unsorted array**, the **removal operation** can be inefficient compared to other data structures, because you typically don't have an ordered structure that helps with searching or removal. Here's a step-by-step breakdown of how removal works in an unsorted array:
### Steps for Removal in an Unsorted Array:
1. **Search for the element:**
    - Since the array is unsorted, you have to scan the entire array (linear search) to find the element you want to remove. This takes **O(n)** time, where **n** is the number of elements in the array.
2. **Remove the element:**
    - Once you locate the element to remove, the next challenge is to actually delete it from the array. In most implementations, arrays are fixed-size, so you can't just remove an element and shrink the array. Instead, you typically perform one of these two strategies:
        1. **Shift all elements:** After finding an element, you can shift all subsequent elements left by one index to fill the gap left by the removed element. This operation also takes **O(n)** time because each subsequent element must be removed.
        2. **Replace with the last element:** An optimization is to replace the element to be removed with the last element in the array. This avoids the need to shift elements, resulting in **O(1)** time complexity for the removal itself (after the search). However, this approach **changes the order of elements**, which might not be acceptable in some cases.
3. **Update the size of the array:**
    - After removal, the size of the array is decremented by 1. If shifting elements was used, the array will now have the elements in their original order but with one less element. If the last-element replacement strategy was used, the size is updated, and the order of elements may change.
### Example of Removal with Replacement by Last Element:
Consider an unsorted array `[7, 3, 8, 5, 2]`, and we want to remove the element `8`.
1. **Search:** We scan the array and find `8` at the index `2`.
2. **Replace with the last element:** We replace `8` with the last element (`2`), giving us the array `[7, 3, 2, 5, 8]`.
4. **Remove the last element:** We remove `8` from the array, making the array `7, 3, 2, 5]`.
3. **Update the size:** We decrement the size by 1, so the array is now `[7, 3, 2, 5]` with 4 elements.

The result is effient removal but with the order of elements altered.
### Summary of Time Complexity:
- **Search for the element:** O(n)
- **Remove the element:**
    - Shifted elements: O(n)
    - Replacing with the last element: O(1)
### Conclusion:
Removing elements from an unsorted array can be inefficient due to the linear search required to find the element. However, the last-element replacement strategy provides a quick way to remove elements if maintaining the order of elements is not critical.

2. Give the pseudocode for the removal, then provide the function in C++.
### Pseudocode:
```
remove(array, size, element):
    1. Initialize index_found = -1
    2. For i from 0 to size - 1:
        If array[i] == element:
            Set index_found = i
            Break
    3. If index_found == -1:
        Return "Element not found"
    
    4. Replace array[index_found] with array[size - 1] (last element)
    5. Decrease the size by 1
    6. Return the modified array
```
### C++ Implementation:
```
#include <iostream>
#include <vector>

using namespace std;

// function to remove an element from an unsorted array
bool removeElement(vector<int>& arr, int& size, int element) {
    int index_found = -1;

    // step 1: search for the element in the array
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            index_found = i;
            break;
        }
    }

    // step 2: if element is not found, return false
    if (index_found == -1) {
        return false; // element not found
    }

    // step 3: replace the found element with the last element in the array
    arr[index_found] = arr[size - 1];

    // step 4: decrease the size of the array by 1
    size--;

    // return true indicating the removal was succesful
    return true;
}

int main() {
    // example array and size
    vector<int> arr = {7, 3, 8, 5, 2};
    int size = arr.size();

    // element to be removed
    int element_to_remove = 8;

    // call the removeElement function
    bool result = removeElement(arr, size, element_to_remove);

    if (result) {
        cout << "Array after removal: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
```
#### Explanation:
1. **Searching for the element:**
    - The function iterates through the array to find the element to remove. This takes **O(n)** time.
2. **Replacing the element with the last element:**
    - If the element is found, it replaces that element with the last element in the array. This operation is **O(1)**.
3. **Updating the size:**
    - After the removal, the size of the array is reduced by 1.
#### Sample Output:
If the initial array is `[7, 3, 8, 5, 2]` and the element `8` is removed.
```
Array after removal: 7 3 2 5
```
Here, the element `8` was replaced by `2` (the last element), and the array size was updated.
This function is efficient for scenarios where the order of elements does not matter, and quick removal is needed.

3. What is the time complexity of insertion and removal operations in an unsorted array-based priority queue? Why?
### Insertion:
- **Time complexity: O(1)**
- **Reason:** When inserting an element into an unsorted array, we simply add the element to the **end** of the array. No sorting or comparison is needed, as the array is unsorted. This makes insertion a constant-time operation, **O(1)**, because no matter how many elements are in the array, you always insert at the next available position.
### Removal (of the highest or lowest priority element):
- **Time complexity: O(n)**
- **Reason:** In an unsorted array, the highest or lowest priority element is not automatically placed in any specific position, so to remove it:
    1. We need to **scan the entire array** to find the element with the highest or lowest priority. This linear scan takes **O(n)** time, where **n** is the number of elements in the array.
    2. Once the element is found, removing it might involve shifting elements (if maintaining the array as a compact block), but the **dominant cost** is the search, which is **O(n)**.
### Summary:
| Operation | Time Complexity | Reason
| :- | :- | :-
| Insertion | **O(1)** | Simply appending the element at the end of the array (no sorting).
| Removal (highest/lowest priority) | **O(n)** | Linear scan to find the element with the highest or lowest priority.

### Why:
- **Insertion** is fast because we don't care about maintaining any specific order when adding new elements, allowing for constant-time insertion.
- **Removal** is slower because, without a sorted structure, we must scan the entire array to find the highest or lowest priority element before we can remove it.

In contrast, a **sorted array-based priority queue** would have **O(n)** insertion (due to keeping the array sorted) but **O(1)** removal (as the highest or lowest element would always be at the end or the beginning of the array).

4. Modify the removal code to handle edge cases (e.g., when the array is empty).

### Updated C++ Code:
```
#include <iostream>
#include <vector>
// #include <mutex> // Uncomment for concurrent modification handling

using namespace std;

// Function to remove all occurrences of an element from an unsorted array
bool removeAllOccurrences(vector<int>& arr, int& size, int element) {
    // Edge case: If the array is empty
    if (size == 0) {
        cout << "Array is empty, cannot remove element." << endl;
        return false;
    }

    bool removed = false;  // To check if we removed at least one occurrence
    int i = 0;

    // Placeholder for handling concurrent modifications (if needed)
    // mutex mtx;
    // lock_guard<mutex> lock(mtx); // Ensures thread-safe access to array in multithreaded environments

    // Iterate through the array and remove all occurrences of 'element'
    while (i < size) {
        if (arr[i] == element) {
            // Replace with the last element and reduce the size
            arr[i] = arr[size - 1];
            size--;  // Decrease size of the array
            removed = true;

            // Continue without incrementing 'i' to check the new element at index 'i'
        } else {
            i++;  // Only move to the next element if no removal happened at current index
        }
    }

    // Edge case: If no element was removed (i.e., element not found)
    if (!removed) {
        cout << "Element not found in the array." << endl;
        return false;
    }

    return true; // At least one occurrence was removed
}

int main() {
    // Example array and size
    vector<int> arr = {7, 3, 8, 5, 2, 8, 9, 8};  // Multiple occurrences of 8
    int size = arr.size();

    // Case 1: Remove element that has multiple occurrences
    int element_to_remove = 8;
    cout << "Removing element: " << element_to_remove << endl;
    bool result = removeAllOccurrences(arr, size, element_to_remove);

    if (result) {
        cout << "Array after removal: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Case 2: Trying to remove an element not present in the array
    element_to_remove = 10; // Element not in array
    cout << "Removing element: " << element_to_remove << endl;
    result = removeAllOccurrences(arr, size, element_to_remove);

    // Case 3: Trying to remove an element from an empty array
    vector<int> emptyArr; // Empty array
    size = emptyArr.size();
    element_to_remove = 1;
    cout << "Removing element from an empty array: " << element_to_remove << endl;
    result = removeAllOccurrences(emptyArr, size, element_to_remove);

    return 0;
}
```
### Key Adjustments and Edge Cases Covered:
1. **Empty Array:**
    - Before any removal is attempted, we check if the array is empty (`size == 0`). If it is, a message is printed and the function returns `false`.
2. **Element Not Found:**
    - If the element is not found in the array after a complete scan, the function outputs a message saying the element wasn't found and returns `false`.
3. **Multiple Occurences:**
    - The code now removes **all occurrences** of the specified element. It uses a loop that continues checking the current index after each removal, ensure that all instances of element are removed.
4. **Removing the Last Element:**
    - The last element is handled correctly by simply replacing the found element with the last one and reducing the size of the array.
5. **Concurrent Modifications** (commented):
    - Placeholders for a **mutex** are provided to ensure thread-safe access if concurrent modifications are a concern (in case you're dealing with multithreaded environments). You would uncomment the mutex code if needed.
### Sample Output:
```
Removing element: 8
Array after removal: 7 3 9 5 2 
Removing element: 10
Element not found in the array.
Removing element from an empty array: 1
Array is empty, cannot remove element.
```
### Additional Considerations:
- The code avoids unnecessary operations and outputs relevant messages for each edge case.
- The size of the array is properly updated throughout the function, so even if the last element or all elements are removed, the array behaves correctly.
- If needed, you could easily extend this to handle other scenarios, such as removing only the first **occurrence** or integrating this into a more complex data structure.

5. How does the efficiency of an unsorted array compare with other implementations?

### Summary of Time Complexities:
| Operation | Unsorted Array | Sorted Array | Heap | BST
| :- | :- | :- | :- | :-
| **Insertion** | O(1) | O(n) | O(log n) | O(log n)
| **Removal (highest/lowest)** | O(n) | O(1) | O(log n) | O(log n)
| **Lookup (highest/lowers)** | O(n) | O(1) | O(1) | O(log n)