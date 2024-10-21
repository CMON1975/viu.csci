#include <cassert> 
#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "list.h"

using namespace std;

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

bool List::Insert(Record *record)
{
  Node *ptr = new Node; //init node
  ptr->data = record; //load data
  ptr->prev = list_name; //point node's previous to list
  ptr->next = list_name->next; //point node's next to list's next
  ptr->prev->next = ptr;
  ptr->next->prev = ptr;
  return true;
}

void List::DisplayAll()
{
	Node *cur = list_name->next;
	int item_num = 1;
	while (cur != list_name){
		cur->data->DisplayMenu(item_num++);
		cur = cur->next;
	}	
}

void List::LoadMenu(string input_file_name) //build menu data from file
{
  ifstream fin; //file in stream
  string food_name; //food name definition
  string food_price_t; //temp food price definition
  double food_price; //double conversion of food price
  int num_entries; //number of entries
  fin.open(input_file_name.c_str()); //open the file
  fin >> num_entries; //first line int is number of entries
  fin.ignore(); //clear whitespace
  for(int i=0;i<num_entries;i++){ //load and convert data from file
    getline(fin, food_name); //get name
    getline(fin, food_price_t); //get price as string
    food_price = atof(food_price_t.c_str()); //convert price string to double
    Record *food_item = new Record(); //init new record
    food_item->SetName(food_name); //load name into record
    food_item->SetPrice(food_price); //load price into record
    this->Insert(food_item); //insert record in list
  }
  fin.close(); //close the file
}
