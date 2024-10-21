//*****************************************************************************
//
// File: Pex1.cpp
// Author: Christopher Nilssen (Jack)
// Date: January 11, 2017
// Updated: January 13, 2017
//
// Purpose: This program helps a fast food chain store (such as a McDonald's
// store) its customer orders. A single customer order record contains three
// items: a burger, a side dish and a drink. Each customer order is assigned
// (by the  program)  a three-digit order number that is between 100 and 999
// (inclusive). 
//
// Notes: This program uses a doubly linked list to maintain the list of the
// records, with a single dummy pointer node.
//
// References: 
//*****************************************************************************
#include <iostream>
using namespace std;
//====================================================================
//Data
struct Record {
   int id;
   string burger;
   string sidedish;
   string drink;
};
//Node
struct Node {
   Record *data; //pointer to process
   Node *next; //pointer to next item in list
   Node *prev; //pointer to previous item in list
};

//mins and maxes for order numbers, 
const int MinOrder = 100;
const int MaxOrder = 999;
//====================================================================

//====================================================================
//make a new empty list
Node *createEmptyList();

//read user input and create a new data record
Record *readData(int currentOrder);

//display menu
void displayMenu(Node *dummy, bool firstRun);

//take user input for menu choices
char userInput();

//operate input on menu options
void useMenu(char optionIn, Node *dummy, int currentOrder);

//add record to front of linked list
void insertRecord(Node *dummy, Record *data);

//display single record contents
void displayRecord(Record *data);

//displayAll all records
void displayAll(Node *dummy, bool forward);

//general node removal (with return, no confirm check
Record *remove(Node *victim);

//error message for no orders
void displayEmpty();
//====================================================================

int main()
{
   int currentOrder = MinOrder; //initialize order numbers

   Node *dummy = createEmptyList(); //initialize dummy node
   
   displayMenu(dummy, true); //display menu for 1st time
   useMenu(userInput(), dummy, currentOrder); //go interactive

   while(dummy->next!=dummy){ //clear list
      remove(dummy->next);  
   }
   delete dummy; //clear dummy
   
   return 0;
}

//display menu
void displayMenu(Node *dummy, bool firstRun = false)
{
   if(firstRun) { //check for first-time run and display welcome message
      cout << "\n*** Welcome to Fast Food Ordering System ***\n\n";
   }
   
   cout << "\nEnter O to make a new order\n"
      << "   or S to serve an order\n"
      << "   or V to view all orders\n"
      << "   or H for help (displays this menu)\n"
      << "   or T to terminate this program\n";
}

//take user input for menu choices
char userInput()
{
   char input; //var for user's input
   cout << "-----------------------------------\n"
      << "Please enter your choice: ";
   cin >> input;
   return input; //return input
}

//operate menu based on user's input
void useMenu(char optionIn, Node *dummy, int currentOrder)
{
   Record *order; //container for new order data

   bool orderExists = false; //simple switch for existing orders
   if(dummy->next!=dummy){
      orderExists = true;
   }

   switch(toupper(optionIn)){
      case 'O': //enter new order
         if(currentOrder<=MaxOrder){
            order = readData(currentOrder);
            insertRecord(dummy, order);
            cout << "Your order is successfully submitted."
               << " Your order number is " << order->id << "." << endl;
            currentOrder++; 
         } else {
            cout << "The system is unable to accept any further orders.\n"
               << "Please speak with a customer service representative." << endl;
         }
         break;
      case 'S': //serve an order
         if(orderExists){
            displayRecord(dummy->prev->data);
            cout << "This order is served." << endl;
            remove(dummy->prev);
         } else {
            displayEmpty();
         }
         break;
      case 'V': //view orders
         if(orderExists) displayAll(dummy, false);
         else displayEmpty();
         //displayAll(dummy, true);
         break;
      case 'H': //"help": display menu
         displayMenu(dummy); //remind user of acceptable options
         break;
      case 'T': //check for outstanding orders and terminate the program          
         if(orderExists){
            cout << "\nProgram can not terminate.\n" 
               << "There are still orders in the order list.\n" << endl;
         } else {
            cout << "The total number of orders processed is " 
               << currentOrder-MinOrder << "." << endl;
            return;
         }
         break;
      default: //ez input error check
         cout << "\n!! You pressed something I don't recognize, please try again. !!" << endl;
         displayMenu(dummy); //remind user of acceptable options
         break;
   }
   useMenu(userInput(), dummy, currentOrder); //accept input
}

//read user input and create a new data record
Record *readData(int currentOrder)
{
   Record *data = new Record; //initialize record

   string bufferClearer; //init null string for buffer clear   
   data->id = currentOrder; //assign current order number to id
   getline(cin, bufferClearer); //buffer clear   
   
   cout << "Please enter your choice for burger: " << endl;
   getline(cin, data->burger);
   cout << "Please enter your choice for sidedish: " << endl;
   getline(cin, data->sidedish);
   cout << "Please enter your choice for drink: " << endl;
   getline(cin, data->drink);
   return data;
}

//make a new empty list
Node *createEmptyList()
{
   Node *ptr = new Node; //create pointer for new node
   ptr->next = ptr; //point to self
   ptr->prev = ptr; //point to self
   return ptr;
}

//add record to front of linked list
void insertRecord(Node *dummy, Record *data)
{
   Node *ptr = new Node; //create pointer for new node
   ptr->data = data; //assign incoming data to pointer's data
   ptr->prev = dummy; //point previous to dummy
   ptr->next = dummy->next; //point next to dummy's next
   ptr->prev->next = ptr; //set previous item's next to point to pointer
   ptr->next->prev = ptr; //set next item's previous to point to pointer
}

//display single record contents
void displayRecord(Record *data)
{
   cout << "-----------------------------------\n"
      << "Order number: " << data->id << "\n"
      << "      burger: " << data->burger << "\n"
      << "    sidedish: " << data->sidedish << "\n"
      << "       drink: " << data->drink << "\n";
}

//display all records
void displayAll(Node *dummy, bool forward)
{
   Node *ptr; //container for position
   if(forward){ //display forward
      ptr = dummy->next; //jump over dummy
      while(ptr!=dummy){
         displayRecord(ptr->data); //display
         ptr=ptr->next; //move forward
      }
   } else { //display reverse
      ptr = dummy->prev; //jump over dummy
      while(ptr!=dummy){
         displayRecord(ptr->data); //display
         ptr=ptr->prev; //move back
      }
   }   
}

//general node removal (with return, no confirm check)
Record *remove(Node *victim)
{
   Record *ptr = victim->data; //catch data for return

   victim->prev->next = victim->next; //bypass victim
   victim->next->prev = victim->prev; //bypass victim
   delete victim->data; //kill victim's data
   delete victim; //kill victim

   return ptr; //if needed
}

//display no orders message
void displayEmpty()
{
   cout << "\nThere are currently no orders in the order list.\n" << endl;
}
