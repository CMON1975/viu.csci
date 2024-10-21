/*  Christopher "Jack" Nilssen
    prog3.cpp

    This program asks the user to supply 3 integer fields for a time of day:
    hours, minutes, and seconds, where hours can be in the range of 0-23,
    while minutes and seconds can each be in the range 0-59. */

#include <cstdio>

//  constants for limits of time input
const int HoursUpper = 23;
const int MinSecUpper = 59;
const int AllLower = 0;

//  describe program to the user
void introduction();

//  read user input
bool readTime(int &hours, int &minutes, int &seconds);

//  master function to initiate input and format output
void formatTime();

//  clear the screen and move the cursor to the top left
void clear();

int main()
{
    //  run intro
    introduction();
    //  do complete time check and report
    formatTime();
    //  end program
    return 0;
}

//  describe program to the user
void introduction()
{
    clear(); //clear the screen
    printf("Welcome to JackTime, a program that asks you for the time,\n");
    printf("    checks for valid inputs, then spits it back all nicely formatted.\n\n");
    return;
}

//  read and check user input
bool readTime(int &hours, int &minutes, int &seconds)
{
    //  give user input instructions
    printf("Please enter 3 values for hours, minutes, and seconds,\n");
    printf("    with a single space between each value, ");
    printf("hours between %d and %d,\n", AllLower, HoursUpper);
    printf("    and minutes and seconds between %d and %d, ", AllLower, MinSecUpper);
    printf("E.g.: 19 45 23\n");
    printf(">"); // user prompt

    //  grab 3 integer values from user with spaces between then clear the screen
    int count = scanf("%d %d %d", &hours, &minutes, &seconds);
    clear();

    //  test for valid input
    if(count != 3){
        return false;
    }
    if((hours < AllLower) || (hours > HoursUpper)){ //  tests hours inside limits
        printf("%d is an invalid hours value.\n", hours);
        return false;
    }   
    if((minutes < AllLower) || (minutes > MinSecUpper)){ // tests minutes inside limits
        printf("%d is an invalid minutes value.\n", minutes);
        return false;
    }
    if((seconds < AllLower) || (seconds > MinSecUpper)){ // tests seconds inside limits
        printf("%d is an invalid seconds value.\n", seconds);
        return false;
    }
    else return true;
}

//  check input
void formatTime()
{
    int hours, minutes, seconds; //init variables for time
    bool validTime; //init variable for time check

    validTime = readTime(hours, minutes, seconds); //run the master time check 

    //  format values to add leading zeroes to values >10
    if(validTime){
        if(hours < 10 && minutes > 9 && seconds > 9){
            printf("Your time is - 0%d:%d:%d\n", hours, minutes, seconds);
        }
        else if(hours < 10 && minutes < 10 && seconds > 9){
            printf("Your time is - 0%d:0%d:%d\n", hours, minutes, seconds);
        }
        else if(hours < 10 && minutes < 10 && seconds < 10){
            printf("Your time is - 0%d:0%d:0%d\n", hours, minutes, seconds);
        }
        else if(hours > 9 && minutes < 10 && seconds < 10){
            printf("Your time is - %d:0%d:0%d\n", hours, minutes, seconds);
        }
        else if(hours > 9 && minutes > 9 && seconds < 10){
            printf("Your time is - %d:%d:0%d\n", hours, minutes, seconds);
        }
        else if(hours < 10 && minutes > 9 && seconds < 10){
            printf("Your time is - 0%d:%d:0%d\n", hours, minutes, seconds);
        }
        else if(hours > 9 && minutes < 10 && seconds > 9){
            printf("Your time is - %d:0%d:%d\n", hours, minutes, seconds);
        }        
    }
    else {
        scanf("%*c"); //wait for user input
        printf("Please try again.\n");
        formatTime();
    }
    return;
}

//  clear the screen and move the cursor to the top left
void clear(){
    printf("\033[2J\033[H");
    return;
}
