#ifndef ORDER_LIST_H 
#define ORDER_LIST_H

#include "order.h"
static int kMaxOrder = 100;
struct Node {
  Order * data;
  Node * next;
  Node * prev;
};

class OrderList {
  public:
    OrderList();
    ~OrderList();
    bool Insert(Order *);
    void DisplayAll();
    void LoadMenu(std::string); //build menu data from file
  	Node * list_name;
  private:
    int cur_order; //current order count
};

#endif 