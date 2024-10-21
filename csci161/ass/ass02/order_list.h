#ifndef LIST_H 
#define LIST_H

#include "record.h"

struct Node {
  List * data;
  Node * next;
  Node * prev;
};

class List {
  public:
    List();
    ~List();
    bool Insert(Record &);
    void DisplayAll();
  private:
    Node * list_name;
};

#endif 
