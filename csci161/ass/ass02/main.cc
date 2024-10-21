#include "list.h" 

#include <cassert>

int main()
{
  List drink_menu = List();
  List burger_menu = List();
  List sidedish_menu = List();
  
  drink_menu.LoadMenu("drink.txt");
  drink_menu.DisplayAll();
} 
