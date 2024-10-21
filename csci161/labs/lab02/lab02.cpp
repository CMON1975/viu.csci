//**********************************************************************************************
//
// File: lab02.cpp
// Author: Christopher Nilssen (Jack)
// Date: January 16, 2017
// Updated: January 20, 2017
//
// Purpose: This program opens a text file named TechDictionary.txt (Format of the file: the 
// first line contains just one integer number that indicates how many records are stored in 
// this file; each line represents one record, and each record starts with one word as the 
// keyword, the rest of the line is the explanation of the keyword.) It then loads the data 
// stored in TechDictionary.txt into a linked list, repeatedly asks the user to enter a keyword,
// then displays the corresponding explanation. 
//
// Notes: The linked list is a single-linked list with a dummy.
//
// References: TechDictionary.txt
//**********************************************************************************************

#include <iostream>
#include <fstream>

using namespace std;

//==BEGIN GLOBALS===============================================================================
//Data
struct Record {
  string word;
  string definition;
};

//Node
struct Node {
   Record *data; //pointer to process
   Node *next; //pointer to next item in list
};
//==END GLOBALS=================================================================================

//==BEGIN FORWARD DECLARATIONS==================================================================
//make a new empty list
Node *createEmptyList();

//get filename from user
string getFilename();

//get query from user
string getQuery();

//add record to front of linked list
void addToFront(Node *head, Record *data);

//get entry data
string find(Node *listHead, string word);

//load data from textfile
void fillList(Node *listHead);

//search operations
void search(Node *listHead);

//general data removal (with return, no confirm check)
void destroyData(Node *listHead);

//general node removal
void destroyNodes(Node *& list);
//==END FORWARD DECLARATIONS====================================================================

int main()
{
   Node *listHead = createEmptyList();

   fillList(listHead); //load data from textfile

   search(listHead); //query

   destroyData(listHead); //clear records

   destroyNodes(listHead); //clear nodes

   delete listHead; //clear dummy

   return 0;
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
   //setup new node (pushing old records back and adding new to front)
   Node *ptr = new Node; //create a pointer
   ptr->data = data; //set new pointer's data to incoming data
   ptr->next = head->next; //set new pointer's next to whatever head's is
   head->next = ptr; //point head to new node 
}  

//get entry data
string find(Node *listHead, string query)
{
   string definition; //init return var

   //traverse the list, looking to match the incoming word
   while(listHead->next->data->word!=query) //jumps the dummy and searches
   {
      listHead = listHead->next;
   }

   definition = listHead->next->data->definition;
   
   //DEBUG Check for invalid input
   
   return definition;
}

//get filename from user
string getFilename()
{
   string filename;
   cout << "------------------------------------\n"
      << "Please enter file name: ";
   cin >> filename;
   return filename;
}

//get query from user
string getQuery()
{
   string query;
   cout << "------------------------------------\n"
      << "Please enter query: ";
   cin >> query;
   return query;
}

//load data from textfile
void fillList(Node *listHead)
{
   ifstream fin; // input stream
   string word; // output word
   string definition; // output definition
   int numEntries; // number of entries
   
   fin.open("TechDictionary.txt"); // open the file

   fin >> numEntries; // read first line of input file and take integer as number of entries

   for(int i=0;i<numEntries;i++){
      fin >> word;
      getline(fin, definition);
      
      cout << word << " " << definition << endl;
      //form data record;
      Record *data = new Record;      
      data->word = word;
      data->definition = definition;
      //put data record to linked list
      addToFront(listHead,data);
   }

   fin.close(); //close the file
}

//list operations
void search(Node *listHead)
{
   string query = getQuery(); //init var for user input
   
   while(query != "shutdown") //search for input word and return definition field
   {
      cout << query << " "
         << find(listHead, query)
         << endl; //print result
      query = getQuery();
   } 
}

//general data removal (with return, no confirm check)
void destroyData(Node *listHead)
{
   Node *tmp = listHead->next;
   while (tmp != listHead && tmp) {
      delete tmp->data;
      tmp = tmp->next;
   }
   delete tmp;
}

//general node removal
void destroyNodes(Node *& listHead)
{
   Node *tmp = listHead->next;
   Node *victim;
   while(tmp!=listHead && tmp) {
      victim = tmp;
      tmp = tmp->next;
      delete victim;
   }
   delete tmp;
}
