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