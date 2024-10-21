#include <iostream>
#include "linked_list.h"

using namespace std;

int ReadProcessId()
{
  int process_id;
  string null_clear; //string for clearing read buffer
  cout << "PROCESS ID (INT): "; //ask user for id
  cin >> process_id; //read id
  getline(cin, null_clear); //clear buffer
  return process_id;
}

char ReadCommand()
{
  char cmd;
  string null_clear;
  cout << "Q TO QUIT\n"
    << "A TO ADD DATA RECORD\n"
    << "S TO SEARCH\n"
    << "V TO VIEW ALL\n";
  cin >> cmd; //read command
  getline(cin, null_clear); //clear buffer
  return toupper(cmd);
}

int main()
{
  LinkedList records;
  
  MyClass *record;
  bool success = false;
  int process_id;
  
  char cmd = ReadCommand();
  
  while (cmd != 'Q') {
    switch (cmd) {
      case 'A':
        record = new MyClass;
        success = records.Insert(*record);
        if (!success) {
          cout << "DUPLICATE ERROR\n";
          delete record;
        }
        break;
      case 'S':
        process_id = ReadProcessId();
        try {
          MyClass & p = records.Search(process_id);
          p.Display();
        } catch (string & e) {
          cout << e << endl;
        }
        break;
      case 'V':
        if (records.GetListSize() == 0) cout << "NO RECORDS\n";
        else records.DisplayAll();
        break;
      default:
        cout << "UNKNOWN COMMAND\n";
        break;
    }
    cmd = ReadCommand();
  }
}
