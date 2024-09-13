// heapsort_test.cpp
#include <iostream>
#include "HeapSort.h"
using std::cout;
using std::endl;

int main()
{
    // Define a simple array to be sorted
    double dataArray[] = {4.5, 2.3, 5.6, 1.2, 3.4};
    int arraySize = sizeof(dataArray) / sizeof(dataArray[0]);

    // Output the original array
    cout << "Original array:" << endl;
    for (int i = 0; i < arraySize; ++i)
    {
        cout << dataArray[i] << " ";
    }
    cout << endl;

    // Sort the array using heapSort
    heapSort(dataArray, arraySize);

    // Output the sorted array
    cout << "Sorted array:" << endl;
    for (int i = 0; i < arraySize; ++i)
    {
        cout << dataArray[i] << " ";
    }
    cout << endl;

    return 0;
}
