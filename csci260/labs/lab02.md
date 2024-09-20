Implement a capacity limited singly linked list using array as its concrete data structure.

The interface of such a singly linked list that stores double numbers is shown below:
```
class LinkedList {
    public:
        // constructor
        LinkedList(int capacity);

        // ignore duplicates, return false if list full
        bool insert(double newData);

        // return the index of the array cell that contains parameter data
        // or return -1 if data doesn't exist in the list
        int find(double data);

        // return false if oldData doesn't exist in the list
        // or if the list is already full
        bool insertAfter(double oldData, double newData);

        // return false if data doesn't exist in the list
        bool remove(double data);

        // destructor
        ~LinkedList();
    
    private:
        struct Cell {
            double data;    // data part of the linked list node
            int next;       // link part of the linked list node
        };
        // suggested data fields
        int capacity;
        int size;
        Cell *DataPile;
        int freeListHead;
        int listHead;
        // any other data fields that could be useful
};
```