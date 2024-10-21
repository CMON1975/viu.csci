#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "menu.h"
#include "list.h"
#include "record.h"

using namespace std;

Menu::Menu() { }

Menu::~Menu() { }

List Menu::LoadMenu(string input_file_name) //build menu data from file
{
	menu_list = new List();
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
    Record food_item = Record(); //init new record
    food_item.SetName(food_name); //load name into record
    food_item.SetPrice(food_price); //load price into record
    menu_list->Insert(food_item); //insert record in list
  }
  fin.close(); //close the file
  return menu_list;
}

void Menu::Display()
{
	
}