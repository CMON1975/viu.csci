#include <fstream>
#include "food_menu.h"
using namespace std;
FoodMenu::FoodMenu()
{
  menu_name = new Menu;
  menu_name->next = menu_name;
  menu_name->prev = menu_name;
}
FoodMenu::~FoodMenu() 
{ 
	Menu *cur = menu_name->next;
	Menu *tmp;
	while (cur != menu_name) {
		tmp = cur->next;
		delete cur;
		cur = tmp;
	}
	delete menu_name;
}
bool FoodMenu::Insert(Record *data)
{
  Menu *ptr = new Menu; //init node
  ptr->data = data; //load data
  ptr->prev = menu_name; //point node's previous to list
  ptr->next = menu_name->next; //point node's next to list's next
  ptr->prev->next = ptr;
  ptr->next->prev = ptr;
  return true;
}
void FoodMenu::DisplayAll()
{
	//please choose cout here? TODO
	Menu *cur = menu_name->prev;
	while (cur != menu_name){
		cur->data->Display();
		cur = cur->prev;
	}	
}
void FoodMenu::LoadMenu(string input_file_name) //build menu data from file
{
  ifstream fin; //file in stream
  string food_name; //food name definition
  string food_price_t; //temp food price definition
  double food_price; //double conversion of food price
  int item_num = 1; //item numerator
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
    food_item->SetNum(item_num++); //set item number
    this->Insert(food_item); //insert record in list
  }
  //set "none of above" item
  Record *food_item = new Record();
  food_item->SetName("None of the above");
  food_item->SetPrice(0);
  food_item->SetNum(item_num);
  this->Insert(food_item);
  fin.close(); //close the file
}
