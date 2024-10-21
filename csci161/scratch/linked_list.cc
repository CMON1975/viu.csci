#include "linked_list.h"

LinkedList::LinkedList() //constructor
{
  list_head = new Node; //create pointer for list read head
  list_head->next = list_head; //point forward to self
  list_head->prev = list_head; //point backward to self
  list_size = 0; //init size of list as zero
}

LinkedList::~LinkedList() //destructor
{
  Node* cur = list_head->next; //bypass list head and set pointer
  Node *tmp; //temporary pointer for link maintenance
  while (cur != list_head) {
    tmp = cur->next; //cache next record
    delete cur->data; //delete data from current record
    delete cur; //delete current DEBUG
    cur = tmp; //set current to cached record
  }
  delete list_head;
}

bool LinkedList::Insert(MyClass &record)
{
  Node* cur = list_head->next; //bypass list head and set pointer
  while (cur != list_head) {
    if (cur->data->GetProcessId() == record.GetProcessId()) {
      return false; //no match
    }
    cur = cur->next; //advance in list
  }
  cur->data = &record; //assign incoming data to pointer's data
  cur->prev = list_head; //point previous to dummy
  cur->next = list_head->next; //point next to dummy's next
  cur->prev->next = cur; //set previous item's next to point to pointer
  cur->next->prev = cur; //set next item's previous to point to pointer
  list_size++; //increment list size
  return true; //successful insertion
}
void LinkedList::DisplayAll()
{
  Node* cur = list_head->next; //bypass list head and set pointer
  while (cur != 0) {
    cur->data->Display();
    cur = cur->next;
  }
}

int LinkedList::GetListSize()
{
  return list_size;
}


MyClass & LinkedList::Search(int process_id) throw (std::string)
{
  Node* cur = list_head->next; //bypass list head and set pointer
  while (cur != 0) {
    if (cur->data->GetProcessId() == process_id) {
      MyClass & data = *(cur->data);
      return data;
    }
    cur = cur->next;
  }
  throw std::string("DATA NOT FOUND");
}
