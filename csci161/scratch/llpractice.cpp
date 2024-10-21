//**********************************************************************************************
//
// File: llpractice.cpp
// Author: Christopher Nilssen (Jack)
// Date: January 13, 2016
// Updated: January 13, 2016
//
// Purpose: This program creates a doubly-linked list with a generic add function.
//
// Notes: For practice purposes only. Assumes doubly-linked circular list with single dummy
//    node.
//
// References: 
//**********************************************************************************************

#include <iostream>

using namespace std;

//==BEGIN GLOBALS===============================================================================
//data
struct Record {
   unsigned int pid; //process id
   string name; //sample data
};

struct Node {
   Record *data; //pointer to record data
   Node *next; //pointer to next record in linked list
   Node *prev; //pointer to previous record in linked list
};
//==END GLOBALS=================================================================================

//==BEGIN FORWARD DECLARATIONS==================================================================
//create empty linked list
Node *createEmptyList();

//insert record to front of linked list
void insert(Node *dummy, Record *data);

//display single record contents
void displayRecord(Record *data);

//traverse all records, with switchable direction
void traverse(Node *dummy, bool forward);

//general node removal
Record *remove(Node *victim);

//display menu
void displayMenu(Node *dummy, bool firstRun);

//take user input for menu choices
char userInput();

//operate menu based on user's input
void useMenu(char optionIn, Node *dummy, unsigned int currentPid);

//read user input and create a new data record
Record *readData(unsigned int currentPid);

//error message for no orders
void displayEmpty();
//==END FORWARD DECLARATIONS====================================================================

int main()
{
   int currentPid = 0; //initialize order numbers

   Node *dummy = createEmptyList(); //initialize dummy node
   
   displayMenu(dummy, true); //display menu for 1st time
   useMenu(userInput(), dummy, currentPid); //go interactive

   while(dummy->next!=dummy){ //clear list
      remove(dummy->next);  
   }
   delete dummy; //clear dummy
   return 0;
}

//create empty linked list
Node *createEmptyList()
{
   Node *ptr = new Node; //initialize dummy pointer
   ptr->next = ptr; //circularly link forward
   ptr->prev = ptr; //circularly link backward
   return ptr;
}

//insert record to front of linked list
void insert(Node *insertionPoint, Record *data)
{
   //setup new node
   Node *ptr = new Node; //create new pointer for incoming data
   ptr->data = data; //set pointer with incoming data
   //set up new node's links
   ptr->prev = insertionPoint; //point back to insertion point (ip)
   ptr->next = insertionPoint->next; //point forward to what ip is currently pointing to
   //insert new node by updating existing nodes
   ptr->prev->next = ptr; //set previous item's next (ip->next) to point to pointer
   ptr->next->prev = ptr; //set next item's previous (ip) to point to pointer
}

//display single record contents
void displayRecord(Record *data)
{
   cout << "-----------------------------------" << endl;
   cout << "id: " << data->pid << endl;
   cout << "      name: " << data->name << endl;
}

//traverse all records, with switchable direction
void traverse(Node *dummy, bool forward)
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

//general node removal
Record *remove(Node *victim)
{
   Record *ptr = victim->data; //cache for return
   //break forward and back links
   victim->prev->next = victim->next; 
   victim->next->prev = victim->prev;
   
   delete victim->data; //clear data
   delete victim; //clear victim

   return ptr;
}

//display menu
void displayMenu(Node *dummy, bool firstRun = false)
{
   if(firstRun) { //check for first-time run and display welcome message
      cout << "\n*** Linked List Test ***\n\n";
   }
   
   cout << "\n(E)nter new record.\n"
      << "(C)lear first record.\n"
      << "(V)iew all records.\n"
      << "(H)elp - re-display this menu.\n"
      << "(T)erminate this program.\n";
}

//take user input for menu choices
char userInput()
{
   char input; //var for user's input
   cout << "-----------------------------------\n"
      << "Command: ";
   cin >> input;
   return input; //return input
}

//operate menu based on user's input
void useMenu(char optionIn, Node *dummy, unsigned int currentPid)
{
   Record *data; //container for new order data

   bool dataExists = false; //simple switch for existing orders
   if(dummy->next!=dummy){
      dataExists = true;
   }

   switch(toupper(optionIn)){
      case 'E': //enter new record
         data = readData(currentPid);
         insert(dummy, data);
         cout<<"Your data is successfully submitted."
            <<" Your data id number is " << data-> pid << "." << endl;
         currentPid++; 
         break;
      case 'C': //clear first record
         if(dataExists){
            displayRecord(dummy->prev->data);
            cout << "This record has been cleared." << endl;
            remove(dummy->prev);
         } else {
            displayEmpty();
         }
         break;
      case 'V': //view orders
         if(dataExists) traverse(dummy, false);
         else displayEmpty();
         break;
      case 'H': //"help": display menu
         displayMenu(dummy); //remind user of acceptable options
         break;
      case 'T': //check for outstanding orders and terminate the program          
         if(dataExists){
            cout << "\nProgram can not terminate.\n"
               << "There are still records in the list.\n" << endl;
         } else {
            cout << "The total number of records processed was "
               << currentPid << "." << endl;
            return;
         }
         break;
      default: //ez input error check
         cout << "\n!! You pressed something I don't recognize, please try again. !!" << endl;
         displayMenu(dummy); //remind user of acceptable options
         break;
   }
   useMenu(userInput(), dummy, currentPid); //accept input
}

//read user input and create a new data record
Record *readData(unsigned int currentPid)
{
   Record *data = new Record; //initialize record

   string bufferClearer; //init null string for buffer clear   
   data->pid = currentPid; //assign current order number to id
   getline(cin, bufferClearer); //buffer clear   
   
   cout << "Please enter a name " << endl;
   getline(cin, data->name);

   return data;
}

//display no orders message
void displayEmpty()
{
   cout << "\nThere are currently no records in the record list.\n" << endl;
}
