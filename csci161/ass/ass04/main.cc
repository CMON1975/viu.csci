/******************************************************************************* 
File: main.cc
Author: Christopher Nilssen (Jack)
Date: Mar 5/07
Updated: Mar 13/07

Overview: This program takes a command-line argument of an input file, then checks
for mismatched or missing brackets from the set (), [], and {}. The program uses a
stack to manage the bracket data, which consists of the bracket itself, and the
line and column where it sits. If a missing or mismatched bracket is found, the
program reports the location of the error.

Notes: I'm very happy with my progress on this assignment, and my understanding
of stacks is complete.

References: stack.h
*******************************************************************************/
#include <iostream>
#include <fstream>
#include "stack.h"
using namespace std;
struct Data {
  char bracket;
  int line;
  int col;
};
Data NewPushableBracket(char bracket_in, int line_in, int col_in)
{ //creates new bracket data object for pushing onto stack
  Data bracket_to_push;
  bracket_to_push.bracket = bracket_in;
  bracket_to_push.line = line_in;
  bracket_to_push.col = col_in;
  return bracket_to_push;
}
int main(int argc, char *argv[])
{
  //init bracket stack
  Stack<Data> brackets;
  //check for appropriate command-line input
  if(argc != 2) 
    cout << "correct use is " << argv[0] << " infile" << endl;

  //file opening
  char * source_file = argv[1];
  FILE * fin; //pointer to position in file
  fin = fopen(source_file, "r"); //attempt to open input file, set to read
  if(!fin)
    cout << "No input file detected, aborting." << endl;
  else 
    cout << source_file << " opened, continuing." << endl;

  //counting
  int line_count = 1; //lines begin at 1
  int col_count = 0; //columns begin at 0
  char current_char; //container for current char
  char top_bracket = 'E'; //containt for top bracket check
  do {
    current_char = getc(fin); //set the current char from file
    if(current_char == '\n'){
      col_count = 0; //reset column count
      line_count++;   //incremement line count
    }
    bool can_push = false; //switch for pushing new bracket
    bool can_pop = false;  //switch for popping matches off
    bool is_mismatch = false; //switch for finding mismatch
    if(!brackets.IsEmpty()) //if a bracket is sitting on the stack
      top_bracket = brackets.Peek().bracket; //reference it
    switch(current_char){ //check for matches
    case ')':
      if(top_bracket == '(') //match
	can_pop = true; //open-close match exists, pop off top
      else
	is_mismatch = true; //core break condition
      break;
    case ']':
      if(top_bracket == '[') //match
	can_pop = true;
      else
	is_mismatch = true;
      break;
    case '}':
      if(top_bracket == '{') //match
	can_pop = true;
      else
	is_mismatch = true;
      break;
    case '(': //these 3 cases are "new open brackets", just push
      can_push = true;
      break;
    case '[':
      can_push = true;
      break;
    case '{':
      can_push = true;
      break;
    }
    if(can_push) //new open bracket, push it onto the stack
      brackets.Push(NewPushableBracket(current_char, line_count, col_count));
    if(can_pop) //open-close match, pop the top off the stack
      brackets.Pop();
    if(is_mismatch) { //handle a mismatch
      cout << "MISMATCH!" << endl;
      if(!brackets.IsEmpty()) { //exception for existing bracket in stack
	//print information regarding broken match
	cout << "Open bracket '" << top_bracket << "' at line " << brackets.Peek().line
	     << " and column " << brackets.Peek().col << endl
	     << " is mis-matched with closing bracket '"
	     << current_char << "' on line " << line_count << " and column " << col_count
	     << "." << endl;
      }
      else { //print information regarding dangling close
	cout << "Close bracket '" << current_char << "' on line " << line_count
	     << " and column " << col_count << " has no matching open bracket." << endl;
      }
    }
    col_count++; //increment column count
    } while (!feof(fin));
  //last check for unclosed brackets
  if(!brackets.IsEmpty()) {
    cout << "UNCLOSED BRACKET!" << endl;
    //print information regarding unclosed bracket
    cout << "Open bracket '" << brackets.Peek().bracket << "' at line " << brackets.Peek().line
	 << " and column " << brackets.Peek().col << " has no matching close bracket." << endl;
  }
  //file closing
  fclose(fin); 
  cout << source_file << " closed." << endl;
  //end the program
  return 0;
}
