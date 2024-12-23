/*******************************************************************************  
	File: ui.cc
	Author: Christopher Nilssen (Jack)
	Date: Jan 19/07
	Updated: Feb 11/07

	Overview: The "workhorse" of the program, this handles all menu functionality. 

	Notes: Not sure if I needed to do the "deletes" in the destructor.
	Absolutely the TakeOrder function feels hack-y, especially with the repeated
	functionality. As this is the 4th re-write of the program I'm going to leave
	it as a "rainy day" project to fix.
	Also used <iomanip> to call setprecision() and fixed to truncate decimal 	
	values on currencies.
	
	References: ui.h (which pulls from everything else via cascade)
*******************************************************************************/
#include "ui.h"
#include <cstdio>
#include <iomanip>
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
	//init orders
	order_number = 100;
	//init total sales
	total_sales = 0;
	//init orders processed
	orders_processed = 0;
}
UI::~UI() 
{ 
	delete burger_menu;
	delete sidedish_menu;
	delete drink_menu;
}
char UI::MainMenuChoice() //main UI option
{
	cout << "Please enter your choice: ";
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
}
//operate menu based on user's input
void UI::UseMenu(char option_in, OrderList *order_list)
{
   bool order_exists = false; //simple check for existing orders
   if(order_list->list_name->next!=order_list->list_name) order_exists = true;
   switch(option_in){
      case 'O': //enter new order
        TakeOrder(order_list);
        break;
      case 'S': //serve an order
        if(!order_exists) {
          cout << "\nThere is currently no order in the order list.\n\n" 
        			 << endl;
        }
        else {
        	order_list->list_name->prev->data->Display();
        	order_list->RemoveFirst();
        	orders_processed++; //increment orders processed
        	cout << endl;
        }
        break;
      case 'V': //view orders
        if(!order_exists) {
          cout << "\nThere is currently no order in the order list.\n\n" 
        			 << endl;
        } else {
        	order_list->DisplayAll();
        	cout << endl;
        }
        break;
      case 'H': //"help": display menu
        DisplayMain(); //remind user of acceptable options
        break;
      case 'T': //check for outstanding orders and terminate the program
        if(order_exists){
          cout << "\nProgram can not terminate.\n" 
               << "There are still orders in the order list.\n" << endl;
        } else {
        	string plural; //pluralization fix
        	if(orders_processed > 1) plural = " orders are ";
        	else plural = " order is ";
        	cout << orders_processed << plural << "processed with total sales "
        	     << "amount of $" << total_sales << endl << endl;
         	return;
        }
        break;
      default: //ez input error check
        cout << "\n\n!! Unrecognized command, please try again. !!\n" << endl;
        break;
   }
   UseMenu(MainMenuChoice(), order_list); //accept input
}
void UI::TakeOrder(OrderList *order_list) //new order handling
{
	bool valid_order = false; //switch for error check
	int burger_order; //vars for orders
	int sidedish_order;
	int drink_order;
	std::cout << "Please choose your burger:" << std::endl;
	burger_menu->DisplayAll(); //display burger menu
	while(!valid_order){
		burger_order = OrderChoice(); //take order
		//traverse the list to match the order number to the item
		valid_order = burger_menu->CheckRecord(burger_order);
	}
	valid_order = false; //reset switch
	std::cout << "Please choose your sidedish:" << std::endl;
	sidedish_menu->DisplayAll(); //display sidedish menu
	while(!valid_order){
		sidedish_order = OrderChoice(); //take order
		valid_order = sidedish_menu->CheckRecord(sidedish_order);
	}
	valid_order = false; //reset switch
	std::cout << "Please choose your drink:" << std::endl;
	drink_menu->DisplayAll(); //display drink menu
	while(!valid_order){
		drink_order = OrderChoice(); //take order
		valid_order = drink_menu->CheckRecord(drink_order);
	}
	//get verified records
	Record * burger = burger_menu->GetRecord(burger_order);
	Record * sidedish = sidedish_menu->GetRecord(sidedish_order);
	Record * drink = drink_menu->GetRecord(drink_order);
	//total price
	double pretax_price = burger->GetPrice() + sidedish->GetPrice() +
		drink->GetPrice();
	double total_price = pretax_price + (pretax_price * kTaxRate);
	//check for empty order
	if(total_price == 0) {
		cout << "\nEmpty Order. Discard.\n\n" << endl;
	} else { //create order object
	  Order * order = new Order(order_number, burger->GetName(), 
	  	sidedish->GetName(), drink->GetName());
		order_list->Insert(order); //insert order	
		//report success
		cout << "Your order is successfully submitted." << endl
			<< "Your order number is " << order_number << " and the total charge is "
			<< setprecision(2) << fixed << total_price << ".\n" << endl;
		order_number++; //increment order
		if(order_number > kMaxOrders) order_number = 100; //overflow reset
		total_sales+=total_price; //accumulate sale value
	}
}
