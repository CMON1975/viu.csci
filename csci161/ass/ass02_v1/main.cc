#include "list.h"
#include "menu.h"

int main()
{
  Menu burger_menu = Menu("burger.txt");
  Menu sidedish_menu = Menu("sidedish.txt");
  Menu drink_menu = Menu("drink.txt");
  
  burger_menu.Display();
}
