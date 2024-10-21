#include <iostream> 
#include "record.h"

using namespace std;

Record::Record() { }

Record::~Record() { }

void Record::Display()
{
  std::cout << "Item: " << item_name << std::endl;
  std::cout << "Price: " << item_price << std::endl;
}

void Record::DisplayMenu(int item_num)
{
	cout << item_num << ". " << item_name << "			" << item_price << endl; 
}

void Record::SetName(std::string name_in)
{
  item_name = name_in;
}
void Record::SetPrice(double price_in)
{
  item_price = price_in;
}
