/******************************************************************************* 
	File: food_menu.h
	Author: Christopher Nilssen (Jack)
	Date: Jan 19/07
	Updated: Feb 11/07

	Overview: header for food_menu.cc

	Notes: difficulty deciding on "Record" name and associated variable name
	CheckRecord likely redundant, or at least an inelegant solution.

	References: food_menu.cc, record.h
*******************************************************************************/
#ifndef FOOD_MENU_H 
#define FOOD_MENU_H
#include "record.h"
struct Menu {
  Record * data;
  Menu * next;
  Menu * prev;
};
class FoodMenu {
  public:
    FoodMenu();
    ~FoodMenu();
    bool Insert(Record *data); //inserts records into menu list
    void DisplayAll(); //displays all loaded data
    void LoadMenu(std::string); //build menu data from file
    bool CheckRecord(int choice); //confirms existence of record
    Record * GetRecord(int choice); //gets record data
  private:
    Menu * menu_name; //primary menu pointer
};
#endif 
