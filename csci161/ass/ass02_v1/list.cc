#include "list.h"
#include "record.h"

List::List()
{
  list_ptr = new Node; //init new list
  list_ptr-> next = list_ptr; //point forward to self
  list_ptr-> prev = list_ptr; //point back to self
  std::cout << "LIST MADE" << std::endl;
}

List::~List() 
{
  
}

void List::DisplayAll(bool forward = true)
{


  Node *ptr; //container for position
  if(forward){ //display forward
    ptr = list_ptr->next; //jump over dummy
    while(ptr!=list_ptr){
      std::cout << "RECORD SHOW" << std::endl;
      //ptr->data->Display(); //display
      ptr=ptr->next; //move forward
    }
  } else { //display reverse
    ptr = list_ptr->prev; //jump over dummy
    while(ptr!=list_ptr){
      //ptr->data->Display(); //display
      ptr=ptr->prev; //move back
    }
  }
}

void List::Insert(Record *record_in)
{
  Node *ptr;
  ptr->data = record_in->data_ptr;
  ptr->prev = list_ptr;
  ptr->next = list_ptr->next;
  ptr->prev->next = ptr;
  ptr->next->prev = ptr;
}
