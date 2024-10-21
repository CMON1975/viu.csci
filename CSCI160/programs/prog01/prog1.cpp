// Christopher "Jack" Nilssen
// prog1.cpp
//
// This program gets the user to enter a number of days, as an integer,
//    and converts it to a number of years, weeks, and days.

#include <cstdio>

const int Year = 365;
const int Week = 7;

//user instructions
void Instructions();

//Function gets furlongs from user
int GetDays();

//Function performs conversion
void ConvertDays(int days);

int main()
{   
    //display instructions
    Instructions();
    
    //get days from user
    int userDays = GetDays();
    
    //perform conversion
    ConvertDays(userDays);

    //end program
    return 0;
}

//user instructions
void Instructions(){
    //state program function to user
    printf("Welcome to the days-to-years conversion program.\n");
    printf("You will be asked to enter an integer number of days, e.g. 934,\n");
    printf("then the program will compute & display the number of years, weeks, and days");
    printf(" \nthis represents (assuming %d days per year and ", Year); 
    printf("%d days per week).\n\n", Week);
    
    //end function
    return;
}

//get days from user
int GetDays()
{
    //variables for user input, computed output
    int days;
   
    //ask user for and store input
    printf("Please enter the number of days, e.g. 934: ");
    scanf("%d", &days);

    //end function
    return days;
}

void ConvertDays(int userDays)
{
    //variables for computed output
    int years, weeks, days;

    //perform conversion and print results to screen
    years = userDays / Year; //divide days by year size to obtain number of years
    weeks = (userDays % Year) / Week; //divide the leftover days by week size to get weeks
    days = userDays % Year % Week; //obtain the remaining remaining days to get days
    printf("%d day(s) is equivalent to %d year(s), %d week(s), and %d day(s).\n", 
       userDays, years, weeks, days);

    //end function
    return;
}
