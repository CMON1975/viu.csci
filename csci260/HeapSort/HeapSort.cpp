#include "HeapSort.h"

void heapSort(double dataArray[], int arraySize)
{
    int currentIndex, heapSize, leftChildIndex, rightChildIndex, smallestIndex;

    // **Heap Construction Stage (Building a Min-Heap)**
    for (int i = 1; i < arraySize; ++i)
    {
        currentIndex = i;
        // sift-up to maintain the min-heap property
        while (currentIndex > 0 && dataArray[currentIndex] < dataArray[(currentIndex - 1) / 2])
        {
            // swap current node with its parent
            swap(dataArray, currentIndex, (currentIndex - 1) / 2);
            currentIndex = (currentIndex - 1) / 2; // move up to the parent
        }
    }

    // **Heap Sort Stage (Extracing Minimum Elements)**
    for (heapSize = arraySize - 1; heapSize > 0; --heapSize)
    {
        // move current smallest element to the end of the array
        swap(dataArray, 0, heapSize);
        currentIndex = 0;

        while (true)
        {
            leftChildIndex = 2 * currentIndex + 1;
            rightChildIndex = 2 * currentIndex + 2;
            smallestIndex = currentIndex;

            // find the smallest among current node and its children
            if (leftChildIndex < heapSize && dataArray[leftChildIndex] < dataArray[smallestIndex])
            {
                smallestIndex = leftChildIndex;
            }
            if (rightChildIndex < heapSize && dataArray[rightChildIndex] < dataArray[smallestIndex])
            {
                smallestIndex = rightChildIndex;
            }

            // if the smallest is not the current node, swap and continue sifting down
            if (smallestIndex != currentIndex)
            {
                swap(dataArray, currentIndex, smallestIndex);
                currentIndex = smallestIndex;
            }
            else
            {
                break; // the heap property is restored
            }
        }
    }
}

// helper function to swap two elements in the array A
void swap(double A[], int i, int j)
{
    double temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}