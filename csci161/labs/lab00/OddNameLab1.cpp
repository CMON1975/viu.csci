//********************************************************************
//
// File: OddNameLab1.cpp
// Author: Christopher Nilssen (Jack)
// Date: January 09, 2017
// Updated: January 11, 2017
//
// Purpose: This program allows user to enter (E) and display (D) records with an integer number
// (called id) and a string (called name) in each record.
//
// Notes: This program uses a singly linked list to maintain the list of the records.
//
// References: 
//********************************************************************

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

#pragma region globals
//Data
struct Record {
  int id;
  string name;
};

//Node
struct Node {
   Record *data; //pointer to process
   Node *next; //pointer to next item in list
};
//first-run switch
static bool FirstRun = true;
#pragma endregion

#pragma region forward_declarations
//make a new empty list
Node *createEmptyList();

//read user input and create a new data record
Record *readData();

//display menu
void displayMenu();

//take user input for menu choices
char userInput();

//operate input on menu options
void useMenu(char optionIn, Node *&head);

//count number of records
int countRecords(Node *head);

//add record to front of linked list
void addToFront(Node *head, Record *data);

//insert, maintaining ascending order
void insert(Node *head, Record *data);

//display single record contents
void displayRecord(Record *data);

//display all records
void displayRecords(Node *head);

//remove head record (cleanup)
void removeFront(Node *&head);

//empty record check
bool isEmpty(Node *head);
#pragma endregion

int main()
{
   Node *head = createEmptyList(); //initialize dummy node
   
   displayMenu(); //go interactive
   useMenu(userInput(),head); //go interactive
   while(head->next){ //clear list
      removeFront(head->next);  
   }
   removeFront(head); //clear dummy
   
   return 0;
}

//display menu
void displayMenu()
{
   if(FirstRun) { //check for first-time run and display welcome message
      cout << "\n*** Welcome to Linked List Recorder ***\n\n";
      FirstRun = false;
   }
   
   cout << "\nEnter E to enter a record\n";
   cout << "   or D to display records\n";
   cout << "   or H for help (displays this menu)\n";
   cout << "   or T to terminate this program\n\n";
}

//take user input for menu choices
char userInput()
{
   char input; //var for user's input
   cout << "-----------------------------------\n";
   cout << "Please enter your choice: ";
   cin >> input;
   return input; //return input
}

//operate menu based on user's input
void useMenu(char optionIn, Node *&head)
{
   switch(toupper(optionIn)){
      case 'E': //enter new record
         addToFront(head, readData());
         break;
      case 'D':
         displayRecords(head);
         break;
      case 'H':
         displayMenu(); //remind user of acceptable options
         break;
      case 'T':         
         //display number of records before closing out
         cout << "\nTotal number of records this session: " << countRecords(head) << "\n";
         return;
         break;
      default:
         cout << "\n!!! You pressed something I don't recognize, please try again. !!!\n";
         displayMenu(); //remind user of acceptable options
         break;
   }
   useMenu(userInput(), head); //accept input
}

//count number of records
int countRecords(Node *head)
{
   int count = 0;
   head = head->next; //jump over dummy
   while(head){
      count++;
      head = head->next;
   }
   return count;
}

//read user input and create a new data record
Record *readData()
{
    string restOfLine;
    Record *data = new Record;
    cout << "Please enter the id: ";
    cin >> data->id;
    getline(cin, restOfLine);
    cout << "Please enter the name: ";
    getline(cin, data->name);

    return data;
}

//make a new empty list
Node *createEmptyList()
{
   Node *ptr = new Node; //create pointer for new node
   ptr->next = 0; //init next pointer
   ptr->data = 0; //init data field(s)  
   return ptr;
}

//add record to front of linked list
void addToFront(Node *head, Record *data)
{
   /*//setup new node (pushing old records back and adding new to front)
   Node *ptr = new Node; //create a pointer
   ptr->data = data; //set new pointer's data to incoming data
   ptr->next = head->next; //set new pointer's next to whatever head's is
   head->next = ptr; //point head to new node */
   
   //prepare new node
   Node *ptr = new Node; //create a pointer
   ptr->data = data; //set new pointer's data to incoming data
   ptr->next = 0; //nullify new pointer's next to signify end of list
   
   insert(head,data);
   
   /*while (head->next){ //find the end of the list
      head = head->next;
   }
   head->next = ptr; //append new node*/
   
}

//insert, maintaining ascending order
void insert(Node *head, Record *data)
{
   Node *tmp = new Node; //temporary container node
   tmp->data = data; //set temp to incoming data
   Node *ptr = head; //assign head
   while(ptr->next && ptr->next->data->id < data->id){
      ptr = ptr->next;
   }
   tmp->next = ptr->next;
   ptr->next = tmp;
}

//display single record contents
void displayRecord(Record *data)
{
   cout << "-----------------------------------\n";
   cout << "Record id: " << data->id << "\n";
   cout << "     name: " << data->name << "\n";
}

//display all records
void displayRecords(Node *head)
{
   head = head->next; //jump over dummy
   while(head){
      displayRecord(head->data);
      head = head->next;
   }
}

//remove head record (cleanup)
void removeFront(Node *&head)
{
   if(head){ //null check
      Node *victim = head; //put head in guillotine
      head = head->next; //set actual head to next
      delete victim->data; //clear data struct
      delete victim; //kill pointer space
   }
}

//empty record check
bool isEmpty(Node *head)
{
   return (head->next == 0);
}
