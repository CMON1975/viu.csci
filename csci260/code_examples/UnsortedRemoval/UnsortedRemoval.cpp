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