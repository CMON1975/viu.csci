#ifndef LIST_H 
#define LIST_H

#include "record.h"

struct Node {
  Record * data;
  Node * next;
  Node * prev;
};

class List {
  public:
    List();
    ~List();
    bool Insert(Record *);
    void DisplayAll();
    void LoadMenu(std::string input_file_name); //build menu data from file
  private:
    Node * list_name;
};

#endif 
