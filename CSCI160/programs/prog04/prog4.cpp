/*  Christopher "Jack" Nilssen
    prog4.cpp
    This program prompts the user to enter a value in a specific range, and if the user provides
    an invalid response it repeatedly prompts the user until a valid response is obtained. 
    Once a valid response is obtained, it will print the integers from the lower limit of the
    range to the user's input (rounded).*/

#include <cstdio>

//  prints instructions to user
void instructions(float minRange, float maxRange);    

//  gets value from user
float getInRange(float minRange, float maxRange);

//  checks for valid input
bool checkValue(int validScan, float userValue, float minRange, float maxRange);

//  prints ints from 0 to user value
void printInts(float userValue, int count);

int main()
{
    //  set range of acceptable values
    float minRange = 0;
    float maxRange = 10;
    float userValue = -100;
   
    //  print instructions
    instructions(minRange, maxRange);

    //  get value from user (and check for validity, then complete operation)
    userValue = getInRange(minRange, maxRange);
    
    //  print result
    printf("The integers from %g to %g are:\n", minRange, userValue);
    
    //  recursively print numbers from minimum up to user's value
    printInts(userValue, minRange);

    return 0;
}

//  prints instructions to user
void instructions(float minRange, float maxRange)
{
    printf("In this program you will simply be asked to enter a number in the range ");
    printf("%g..%g. ", minRange, maxRange);
    printf("If you supply an invalid value the program will tell you what you have done wrong");
    printf("and ask you to try again.  This cycle will continue until you provide a valid ");
    printf("response.\n\n");
    
    return;
}

//  gets value from user
float getInRange(float minRange, float maxRange)
{   
    //  initialize user variable
    float userValue = 0;
    
    //  ask for input using constants
    printf("Please enter a number in the range %g to %g\n", minRange, maxRange);

    //  take user input and also store general non-numeric input error check value
    int validScan = scanf("%f", &userValue);
    
    //  check for valid input
    bool isValid = checkValue(validScan, userValue, minRange, maxRange);

    if(!isValid) {
        scanf("%*s"); // clear buffer
        userValue = getInRange(minRange, maxRange); // recurse
    }
    
    return userValue;
}

//  checks for valid input
bool checkValue(int validScan, float userValue, float minRange, float maxRange)
{
    //  initialize/reset validity boolean
    bool validData = false;

    //  checks
    if(validScan != 1){ //  non-numeric entry
        scanf("%*s"); // clear buffer
        printf("That is not a valid number, please try again\n");
    }
    else if (userValue > maxRange){ //  entry too large
        printf("Error: the value %g is too large, please try again\n", userValue);
    }
    else if (userValue < minRange){ //  entry too small
        printf("Error: the value %g is too small, please try again\n", userValue);
    }
    else if(userValue <= maxRange && userValue >= minRange){ // valid entry
        validData = true;
    }
    return validData;
}

//  prints whole integer values from minRange to user's value (or below if decimal)
void printInts(float userValue, int count)
{
    if(count < userValue){  //  uses incoming minRange to choke values
        printf("%d\n", count);
        count++;
        printInts(userValue, count);   // recurse
    }
    else return;
}