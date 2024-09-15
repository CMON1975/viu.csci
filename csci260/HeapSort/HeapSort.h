#ifndef HEAPSORT_H
#define HEAPSORT_H

class HeapSort
{
public:
    void heapSort(double dataArray[], int arraySize);

private:
    void swap(double dataArray[], int i, int j);
};

#endif // HEAPSORT_H