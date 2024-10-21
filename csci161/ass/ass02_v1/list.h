#ifndef LIST_H
#define LIST_H

#include "record.h"

struct Node {
  Data * data;
  Node * next;
  Node * prev;
};

class List {
  public:
    List(); //constructor
    ~List(); //destructor
    void Insert(Record *record_in); //insert
    void DisplayAll(bool forward); //show all records in list
  private:
    Node * list_ptr; //master pointer to list
    int list_size; //size of list
};

#endif
