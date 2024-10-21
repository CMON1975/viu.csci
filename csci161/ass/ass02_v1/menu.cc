#include <iostream>
#include <cstdlib>
#include <fstream>
#include "record.h"
#include "menu.h"
#include "list.h"

using namespace std;

Menu::Menu() { }

Menu::~Menu() { }

Menu::Menu(string input_file_name) //build menu data from file
{
  menu_list = new List(); //init new list
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
    Record *food_item = new Record; //init new record
    food_item->SetName(food_name); //load name into record
    food_item->SetPrice(food_price); //load price into record
    //insert record in list
    menu_list->Insert(food_item);
  }
  
  fin.close(); //close the file
}

void Menu::Display()
{
  menu_list->DisplayAll();
}
