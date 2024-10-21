#include "record.h"
using namespace std;
Record::Record() { }
Record::~Record() { }
void Record::Display() //possible to handle line formatting here
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