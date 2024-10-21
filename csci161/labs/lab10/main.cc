/******************************************************************* 
File: main.cc
Author: Christopher Nilssen (Jack)
Date: Mar 31/07
Updated: Apr 4/07

Overview: This program manages a users homework assignments. It
takes a .txt file as a command-line argument. If the file doesn't
exist, it will be created. The user can then (assuming data exists
in some cases) list the assignments in the file, show a detailed
list of an assignment's data, remove an assignment from the system,
add an assignment to the system, display the options, and export
back to the file and exit. The system uses a dictionary ADT to 
manage the data.

Notes: More of the main could have been offloaded to functions.

References: dictionary.h, dict_except.h
*******************************************************************/
#include <iostream>
#include <fstream>
#include "dictionary.h"
using namespace std;
struct Record {
  string course_name;
  string assign_name;
  string homework_name;
  string submit_deadline;
  string teacher_info;
  string description;
};
char Prompt() { //simple input prompt
  cout << "> "; //indicator
  char choice = ' '; //choice placeholder
  choice = getchar(); //read choice
  while('\n' != getchar())
    ; //discard carriage return
  return choice;
}
void ShowFull(Record record_in) {
  cout << "Course: " << record_in.course_name << endl;
  cout << "Assignment: " << record_in.assign_name << endl;
  cout << "Submit deadline: " << record_in.submit_deadline << endl;
  cout << "Teacher info: " << record_in.teacher_info << endl;
  cout << "Description: " << record_in.description << endl;
}
void Menu() { //menu
  cout << "Please choose from the following commands (in parenthesis):" << endl;
  cout << "(1) list homework names." << endl;
  cout << "(2) show full homework information." << endl;
  cout << "(3) remove a homework from the system." << endl;
  cout << "(4) add a new homework to the system." << endl;
  cout << "(5) update the submit deadline of a homework." << endl;
  cout << "(6) display help." << endl;
  cout << "(0) export all homework to file and terminate the program." << endl;
}
string GetQuery() { //string for homework names entered by user
  cout << "Please enter a homework name: ";
  string query;
  getline(cin, query);
  return query;
}
void NotFoundMsg() { //report when homework entry not found
  cout << "Sorry, there's no homework with that name." << endl;
  cout << "Try (1) to get a complete list of homework in system." << endl;
}
Record *NewRecord() {
  Record *new_hw = new Record;
  string desc_check;
  string teacher_check;
  string submit_check;
  bool valid_desc = false;
  bool valid_teach = false;
  bool valid_submit = false;
  cout << "Enter the course name: ";
  getline(cin, new_hw->course_name); //1st word read is course name
  cout << "Enter the assignment name: ";
  getline(cin, new_hw->assign_name); //2nd word read is assignment name
  new_hw->homework_name = new_hw->course_name + " " + new_hw->assign_name;
  cout <<  "Enter the submit deadline: ";
  while(!valid_submit) { //check for empty teacher string
    getline(cin, submit_check);
    if(submit_check.length() > 0) {
      new_hw->submit_deadline = submit_check;
      valid_submit = true;
    }
    else {
      cout << "Submit deadline cannot be blank, please try again: ";
      valid_submit = false;
    }
  }
  cout << "Enter the teacher information: ";
  while(!valid_teach) { //check for empty submit string
    getline(cin, teacher_check);
    if(teacher_check.length() > 0) {
      new_hw->teacher_info = teacher_check;
      valid_teach = true;
    }
    else {
      cout << "Teacher info cannot be blank, please try again: ";
      valid_teach = false;
    }
  }
  cout << "Enter a description (255 character limit): ";
  while (!valid_desc) { //limit description to < 255 chars
    getline(cin, desc_check);
    if(desc_check.length() < 255) {
      new_hw->description = desc_check;
      valid_desc = true;
    }
    else {
      cout << "Description too long, please try again: ";
      valid_desc = false;
    }
  }
  return new_hw;
}
void SaveToFile(string filename, Dictionary<string, Record> & dict_in) {
  cout << "Saving to file " << filename << endl;
  ofstream fout;
  fout.open(filename.c_str());
  int num_entries = dict_in.GetSize();
  fout << num_entries << endl;
  Record temp_record;
  for (int i=0; i<num_entries; i++) {
    temp_record = dict_in.Dump(i);
    //iterate through data then write line by line
    fout << temp_record.course_name + " " + temp_record.assign_name << endl;
    fout << temp_record.submit_deadline << endl;
    fout << temp_record.teacher_info << endl;
    fout << temp_record.description << endl;
  }
  fout.close();
}
int main(int argc, char *argv[])
{
  //init dictionary
  Dictionary<string, Record> entries(100);
  //    = Dictionary<string, Record>(100);
  
  //check for appropriate command-line input
  if(argc != 2)
    cout << "correct use is " << argv[0] << " infile" << endl;

  //file opening
  ifstream fin; //input stream
  ofstream fout; //output stream
  string filename = argv[1];
  fin.open(filename.c_str()); //attempt to open and set to read
  if(!fin) { //null input
    cout << "Creating new input file " << filename << endl;
  } else {
    cout << filename << " opened, continuing." << endl;
    int num_entries = 0; //number of dictionary entries
    fin >> num_entries; //take 1st line of file as # of entries
    string empty_string; //buffer clear  

    for (int i=0; i<num_entries; i++) {
      Record *temp_record = new Record; //container for records
      fin >> temp_record->course_name; //1st word read is coure name
      fin >> temp_record->assign_name; //2nd word read is assignment name
      temp_record->homework_name = temp_record->course_name + " " + temp_record->assign_name;
      getline(fin, empty_string); //clear the previous line
      getline(fin, temp_record->submit_deadline);
      getline(fin, temp_record->teacher_info);
      getline(fin, temp_record->description);

      /*DEBUG confirm data read
	cout << "name: " << temp_record->homework_name << endl;
	cout << "dead: " << temp_record->submit_deadline << endl;
	cout << "teach: " << temp_record->teacher_info << endl;
	cout << "desc: " << temp_record->description << endl;*/

      entries.Insert(temp_record->homework_name, *temp_record); //insert entry
    }
  }
  fin.close(); //close file
  fout.open(filename.c_str()); //open write file

  Menu(); //list choices
  char choice = '\0';
  string hw_name = "";
  Record *new_hw;
  int size = 0;
  while (choice != '0') {
    choice = Prompt();
    switch (choice) {
    case '0': //exit
      //write to file
      SaveToFile(filename, entries);
      break;
    case '1': //display names
      size = entries.GetSize();
      if(size > 0) {
	cout << "The following " << size << " entries are in the system:" << endl;
	entries.DisplayKeys();
      } else {
	cout << "The system contains no entries." << endl;
      }
      break;
    case '2': //display full
      cout << "Display which entry?" << endl;
      hw_name = GetQuery();
      try { 
	ShowFull(entries.Lookup(hw_name));
      } catch (DictionaryEmpty & e) {
	cout << e.what() << endl;
      } catch (NotFound & e) {
	NotFoundMsg();
      }
      break;
    case '3': //remove
      cout << "Remove which entry?" << endl;
      hw_name = GetQuery();
      try { //remove if entry found
	Record victim = entries.Remove(hw_name);
	ShowFull(victim); //display record to confirm deletion
	char response = ' ';
	while(response != 'N' && response != 'Y') {
	  cout << "Remove this record? Y/N: ";
	  response = toupper(getchar());
	  while('\n' != getchar()); //discard carriage return
	  if(response == 'Y') {
	    cout << "Record removed from system." << endl;
	  } else if(response == 'N') {
	    cout << "Record returned to system." << endl;
	    entries.Insert(victim.homework_name, victim); //put back in system
	  } else {
	    cout << "Please enter (Y)es or (N)o: ";
	  }
	}
      } catch (NotFound & e) {
	NotFoundMsg();
      }
      break;
    case '4': //insert
      cout << "Insert new entry." << endl;
      new_hw = NewRecord();
      try { //if dictionary not full
	entries.Insert(new_hw->homework_name, *new_hw); //insert entry
	cout << "The following entry has been added to the system:" << endl;
	ShowFull(*new_hw); //show entry to confirm
      } catch (DictionaryFull & e) {
	cout << "The system is full, and you must (3) remove a record first." << endl;
      }
      break;
    case '5': //update
      cout << "Update which entry's deadline?" << endl;
      hw_name = GetQuery();
      try {//display old deadline
	cout << "Current deadline for " << hw_name << ": " 
	     << entries.Lookup(hw_name).submit_deadline << endl;
	//ask for new deadline
	cout << "Enter new deadline:";
	bool valid_submit = false;
	string submit_check;
	while(!valid_submit) { //check for empty teacher string
	  getline(cin, submit_check);
	  if(submit_check.length() > 0) {
	    entries.Lookup(hw_name).submit_deadline = submit_check; //change deadline
	    cout << "Deadline updated." << endl; //confirm change
	    valid_submit = true;
	  }
	  else {
	    cout << "Submit deadline cannot be blank, please try again: ";
	    valid_submit = false;
	  }
	}
      } catch (NotFound & e) {
	NotFoundMsg();
      }
      break;
    case '6': //help
      Menu(); //display menu
      break;
    default:
      cout << "Invalid choice, please try again or enter (6) for help." << endl;
      break;
    }
  }
  return 0; //exit program
}
