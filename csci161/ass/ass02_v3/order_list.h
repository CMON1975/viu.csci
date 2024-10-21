/******************************************************************************* 
	File: order_list.h
	Author: Christopher Nilssen (Jack)
	Date: Jan 19/07
	Updated: Feb 11/07

	Overview: header for order_list.cc

	Notes: again, lots of duplicate code between this and menu handling leads me
	to believe that I've redundantly over-designed this part of the program.
	I also had issues making the list head private. I could likely resolve these 		
	with more practice.
	
	References: order.h
*******************************************************************************/
#ifndef ORDER_LIST_H 
#define ORDER_LIST_H
#include "order.h"
struct Node {
  Order * data;
  Node * next;
  Node * prev;
};
class OrderList {
  public:
    OrderList();
    ~OrderList();
    bool Insert(Order *record); //inserts order
    void RemoveFirst(); //removes "first" item from list
    void DisplayAll(); //displays all orders
    void LoadMenu(std::string); //build menu data from file
  	Node * list_name; //master list, had issues making this private
  private:
    int cur_order; //current order count
};
#endif 
