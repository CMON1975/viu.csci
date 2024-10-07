#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

template <typename T>
int lookup(const vector<T>& array, const T& key) {
    int low = 0;
    int high = static_cast<int>(array.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == key) {
            return mid; // key found at index mid
        } else if (array[mid] < key) {
            low = mid + 1; // search the right half
        } else {
            high = mid - 1; // search in the left half
        }
    }

    // after the loop, `low` is the insertion point.
    if (low < static_cast<int>(array.size()) && array[low] == key) {
        return low; // key found at index 'low'
    } else {
        // key not found, returns negative insertion point
        return -low -1; 
    }
}

int main() {
    vector<int> sortedArray = {1, 3, 5, 9, 11, 13};
    int key = 7;
    int result = lookup(sortedArray, key);

    if (result >= 0) {
        cout << "Key " << key << " found at index: " << result << endl;
    } else {
        int insertionPoint = -result -1;
        cout << "Key " << key << " not found." << endl;
        cout << "It can be inserted at index: " << insertionPoint << endl;
    }

    return 0;
}