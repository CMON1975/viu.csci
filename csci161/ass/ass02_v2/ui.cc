#include "ui.h"
#include "order_list.h"
#include <cstdio>

using namespace std;

UI::UI() 
{ 
	//init menus
	burger_menu = new FoodMenu();
	sidedish_menu = new FoodMenu();
	drink_menu = new FoodMenu();
	//load menus
	burger_menu->LoadMenu("burger.txt");
	sidedish_menu->LoadMenu("sidedish.txt");
	drink_menu->LoadMenu("drink.txt");
}
UI::~UI() { }
char UI::MainMenuChoice() //main UI option
{
	char choice;
	cin >> choice;
	return toupper(choice);
}
int UI::OrderChoice() //ordering option
{
	int choice;
	cin >> choice;
	return choice;
}

void UI::DisplayMain() //main menu
{
	cout <<	"Enter O to make an order" << endl
		   << "   or S to serve an order" << endl
		   << "   or V to view all orders" << endl
		   << "   or H for help (displays this menu)" << endl
		   << "   or T to terminate this program" << endl
		   << endl
		   << endl;
	cout << "Please enter your choice: ";
}

//operate menu based on user's input
void UI::UseMenu(char option_in, OrderList *order_list)
{
   bool order_exists = false; //simple check for existing orders
   if(order_list->list_name->next!=order_list->list_name) order_exists = true;

   switch(option_in){
      case 'O': //enter new order
         TakeOrder();
         break;
      case 'S': //serve an order
         cout << "SERVE" << endl;
         break;
      case 'V': //view orders
         cout << "VIEW" << endl;
         break;
      case 'H': //"help": display menu
         DisplayMain(); //remind user of acceptable options
         break;
      case 'T': //check for outstanding orders and terminate the program          
         if(order_exists){
            cout << "\nProgram can not terminate.\n" 
                 << "There are still orders in the order list.\n" << endl;
         } else return;
         break;
      default: //ez input error check
         cout << "\n!! Unrecognized command, please try again. !!" << endl;
         DisplayMain(); //remind user of acceptable options
         break;
   }
   UseMenu(MainMenuChoice(), order_list); //accept input
}
void UI::TakeOrder() //new order handling
{
	std::cout << "Please choose your burger:" << std::endl;
	burger_menu->DisplayAll(); //display burger menu
	int burger_order = OrderChoice(); //take order
	std::cout << "Please choose your sidedish:" << std::endl;
	sidedish_menu->DisplayAll(); //display sidedish menu
	int sidedish_order = OrderChoice(); //take order
	std::cout << "Please choose your drink:" << std::endl;
	drink_menu->DisplayAll(); //display drink menu
	int drink_order = OrderChoice(); //take order
}
