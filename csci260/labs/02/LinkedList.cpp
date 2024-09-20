#include "LinkedList.h"
#include <iostream>

// constructor
LinkedList::LinkedList(int capacity)
{
    this->capacity = capacity;
    this->size = 0;
    dataList = new Cell[capacity];
    freeListHead = 0;
    listHead = -1;

    // init free list
    for (int i = 0; i < capacity; ++i)
    {
        dataList[i].next = i + 1;
    }
    dataList[capacity - 1].next = -1; // end
}

// destructor
LinkedList::~LinkedList()
{
    delete[] dataList;
}

// insert and ignore dupes
bool LinkedList::insert(double newData)
{
    if (find(newData) != -1)
    {
        return true;
    }
    if (size == capacity)
    {
        return false;
    }
    int newCellIndex = freeListHead;
    freeListHead = dataList[freeListHead].next;

    dataList[newCellIndex].data = newData;
    dataList[newCellIndex].next = listHead;

    listHead = newCellIndex;

    ++size;

    return true;
}

// find index of data cell
int LinkedList::find(double data)
{
    int currentIndex = listHead;
    while (currentIndex != -1)
    {
        if (dataList[currentIndex].data == data)
        {
            return currentIndex;
        }
        currentIndex = dataList[currentIndex].next;
    }
    return -1; // data not found
}

// insert new after old data
bool LinkedList::insertAfter(double oldData, double newData)
{
    int oldIndex = find(oldData);
    // check for existing old data
    if (oldIndex == -1)
    {
        return false;
    }
    // check for dupe
    if (find(newData) != -1)
    {
        return true;
    }
    // check if full
    if (size == capacity)
    {
        return false;
    }

    int newCellIndex = freeListHead;
    freeListHead = dataList[freeListHead].next;

    dataList[newCellIndex].data = newData;
    dataList[newCellIndex].next = dataList[oldIndex].next;

    dataList[oldIndex].next = newCellIndex;

    ++size;

    return true;
}

// remove data from list
bool LinkedList::remove(double data)
{
    int currentIndex = listHead;
    int prevIndex = -1;
    while (currentIndex != -1)
    {
        if (dataList[currentIndex].data == data)
        {
            break; // found removal node
        }
        prevIndex = currentIndex;
        currentIndex = dataList[currentIndex].next;
    }
    if (currentIndex == -1)
    {
        return false; // no such data
    }
    if (prevIndex == -1)
    {
        listHead = dataList[currentIndex].next;
    }
    else
    {
        dataList[prevIndex].next = dataList[currentIndex].next;
    }

    dataList[currentIndex].next = freeListHead;
    freeListHead = currentIndex;

    --size;

    return true;
}
