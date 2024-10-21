// "Furlong Calculator"
// Christopher Nilssen (Jack)
//
// This program converts user-entered furlongs to kilometers
//  using the factor 0.201168 and displays the result to
//  4 decimal places

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/* BEGIN FORWARD DECLARATIONS */
// conversion factor as constant
const double FACTOR = 0.201168;

// function to display user instructions
void Instructions();

// function to get user input
double GetInput();

// function to perform conversion
void Convert(double);
/* END FORWARD DECLARATIONS */

int main(){
 // display instructions
 Instructions();
    
 // get input from user
 double furlongs = GetInput();

 // perform conversion
 Convert(furlongs);

 // end program
 return 0;
}

void Instructions(){
 // state program function for user
 cout << "Welcome to the distance conversion program." << endl
    << "You will be asked to enter a distance in furlongs, i.e. 3.12.4," << endl
    << "then I will compute and display the converted distance in kilometers." << endl
    << endl;
}

double GetInput(){
 // variables for holding input
 string input = "";
 double furlongs = 0;
    
 while (true) {
    // ask user for and return input
    cout << "Please enter a distance in furlongs: ";
    // safe input for fast non-number error check
    // by testing string conversion to number
    getline(cin, input);
    stringstream testInput(input);
    if (testInput >> furlongs)
        break;
    cout << "Invalid number, please try again" << endl;
 }

 // return valid user input
 return furlongs;
}

void Convert(double furlongs){
 // variable for output
 double kilometers = 0;

 //perform conversion and print results to screen
 kilometers = furlongs * FACTOR;
 cout << furlongs << " furlong(s) is approx. " 
    << kilometers << " kilometers." << endl;
}
