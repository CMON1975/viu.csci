#include <cassert> 
#include <fstream>
#include <cstdlib>
#include "order_list.h"

using namespace std;

OrderList::OrderList()
{
  list_name = new Node;
  list_name->next = list_name;
  list_name->prev = list_name;
}

OrderList::~OrderList() 
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

bool OrderList::Insert(Order *record)
{
  Node *ptr = new Node; //init node
  ptr->data = record; //load data
  ptr->prev = list_name; //point node's previous to list
  ptr->next = list_name->next; //point node's next to list's next
  ptr->prev->next = ptr;
  ptr->next->prev = ptr;
  return true;
}

void OrderList::DisplayAll()
{
	Node *cur = list_name->next;
	int item_num = 1;
	while (cur != list_name){
		//display code here
		cur = cur->next;
	}	
}

