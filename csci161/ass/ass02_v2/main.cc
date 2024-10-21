#include "ui.h"
#include "order_list.h"
#include "food_menu.h"

int main()
{
	/*//init menus
	FoodMenu *burger_menu = new FoodMenu();
	FoodMenu *sidedish_menu = new FoodMenu();
	FoodMenu *drink_menu = new FoodMenu();
	//load menus
	burger_menu->LoadMenu("burger.txt");
	sidedish_menu->LoadMenu("sidedish.txt");
	drink_menu->LoadMenu("drink.txt");*/
	UI ui = UI(); //init ui
	OrderList *orders = new OrderList(); //init order list
	
	ui.DisplayMain(); //show main menu
	char user_input = ui.MainMenuChoice(); //run menu system
	ui.UseMenu(user_input, orders);
	
	
	/*
	//if make new order:
	std::cout << "Please choose your burger:" << std::endl;
	burger_menu->DisplayAll(); //display burger menu
	int burger_order = ui.OrderChoice(); //take order
	std::cout << "Please choose your sidedish:" << std::endl;
	sidedish_menu->DisplayAll(); //display sidedish menu
	int sidedish_order = ui.OrderChoice(); //take order
	std::cout << "Please choose your drink:" << std::endl;
	drink_menu->DisplayAll(); //display drink menu
	int drink_order = ui.OrderChoice(); //take order
	*/
}