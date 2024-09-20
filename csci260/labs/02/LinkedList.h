#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
public:
    // constructor
    LinkedList(int capacity);

    // destructor
    ~LinkedList();

    // insert data
    bool insert(double newData);

    // return array index of data or -1
    int find(double data);

    // insert new after old data
    bool insertAfter(double oldData, double newData);

    // remove data
    bool remove(double data);

private:
    struct Cell
    {
        double data;
        int next;
    };

    int capacity;
    int size;
    Cell *dataList;
    int freeListHead;
    int listHead;
};

#endif // LINKEDLIST_H
