#include <cassert> 
#include "list.h"

List::List()
{
  list_name = new Node;
  list_name->next = list_name;
  list_name->prev = list_name;
}

List::~List() 
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

bool List::Insert(Order &record)
{
  Node *ptr = new Node;
  ptr->data = &record;
  ptr->prev = list_name;
  ptr->next = list_name->next;
  ptr->prev->next = ptr;
  ptr->next->prev = ptr;
  return true;
}

void List::DisplayAll()
{
	Node *cur = list_name->next;
	while (cur != list_name){
		cur->data->Display();
		cur = cur->next;
	}	
}
