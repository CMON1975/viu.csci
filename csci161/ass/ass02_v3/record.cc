/******************************************************************************* 
	File: record.cc
	Author: Christopher Nilssen (Jack)
	Date: Jan 19/07
	Updated: Feb 11/07

	Overview: creates menu item objects and handles their display

	Notes: A better name than "Record" would have helped during implementation.
	Also contains a lot of redundant overdesign that I was too tired to remove.

	References: record.h
*******************************************************************************/
#include "record.h"
using namespace std;
Record::Record() { }
Record::~Record() { }
void Record::Display() //display record information
{
	cout << item_num << ". " << item_name;
	//spacing code here
	int spaces = whitespace - item_name.length();
	for (int i = 0; i < spaces; i++) cout << " "; 
  if(item_name != "None of the above") cout << item_price << endl;
  else cout << endl;
}
void Record::SetName(string name_in)
{
  item_name = name_in;
}
void Record::SetPrice(double price_in)
{
  item_price = price_in;
}
void Record::SetNum(int num_in)
{
	item_num = num_in;
}
string Record::GetName()
{
	return item_name;
}
double Record::GetPrice()
{
	return item_price;
}
int Record::GetNum()
{
	return item_num;
}
