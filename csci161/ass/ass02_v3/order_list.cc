/******************************************************************************* 
	File: order_list.cc
	Author: Christopher Nilssen (Jack)
	Date: Jan 19/07
	Updated: Feb 11/07

	Overview: constructs linked list for order handling.

	Notes: "list_name" was also a terrible choice for a head pointer var.

	References: order_list.h
*******************************************************************************/
#include <cassert> 
#include <fstream>
#include <cstdlib>
#include "order_list.h"
using namespace std;
OrderList::OrderList()
{
  list_name = new Node; //init main pointer
  list_name->next = list_name; //link
  list_name->prev = list_name; //link
}
OrderList::~OrderList() //recursive destructor
{ 
	Node *cur = list_name->next;
	Node *tmp;
	while (cur != list_name) {
		tmp = cur->next;
		delete cur;
		cur = tmp;
	}
	delete list_name;
}
bool OrderList::Insert(Order *record) //inserts order
{
  Node *ptr = new Node; //init node
  ptr->data = record; //load data
  ptr->prev = list_name; //point node's previous to list
  ptr->next = list_name->next; //point node's next to list's next
  ptr->prev->next = ptr; //link
  ptr->next->prev = ptr; //link
  return true;
}
void OrderList::RemoveFirst() //remove "first" item from list
{
	Node *tmp = list_name->prev; //create temp pointer
	list_name->prev->prev->next = list_name; //fix links
	list_name->prev = list_name->prev->prev;
	delete tmp->data; //delete data
	delete tmp; //delete pointer
}
void OrderList::DisplayAll() //displays all orders
{
	Node *cur = list_name->prev;
	while (cur != list_name){
		cur->data->Display();
		cur = cur->prev;
	}	
}

