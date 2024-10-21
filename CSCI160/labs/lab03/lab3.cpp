/*  Christopher "Jack" Nilssen
    lab3.cpp
    This program gets the user to enter a student's assignment mark on an assignment,
    enter what the maximum possible assignment mark was, and computer the mark the
    student received as a percent. */

#include <cstdio>

//  describe program to the user
void Instructions();

//  prompt user for values
void GetValues(double &studentMark, double &maxMark);

//  read and return a value
double getValue();

//  error check input
bool errorCheck(int scanCheck);

/*  given the values of student's assignment mark, and maximum possible mark, compute results
    using studentMark divided by maxMark. */
double getResults(double studentMark, double maxMark);

// print all values
void PrintResults(double studentMark, double maxMark, double result);

int main()
{
    //  variables to hold the user values and result
    double studentMark, maxMark, result;
    //  describe the program to the user
    Instructions();
    //  prompt user for values
    GetValues(studentMark, maxMark);
    // calculate and store the compoundInterest
    result = getResults(studentMark, maxMark);
    // display the results
    PrintResults(studentMark, maxMark, result);
    // end the program
    return 0;
}

// describe program to the user
void Instructions()
{
    printf("This program will get you to enter a student's assignment mark\n");
    printf("   and the maximum possible mark, check them for validity,\n");
    printf("   and calculate their mark as a percent.\n\n");
    return;
}

// prompt user for values
void GetValues(double &studentMark, double &maxMark)
{
    printf("Please provide the student mark as a non-negative number, e.g. 10.5\n");
    studentMark = getValue();
    printf("Please provide the maximum possible mark on the assignment, e.g. 16\n");
    maxMark = getValue();
    return;
}

//  read and return a value  
double getValue()
{
    double value; 
    int scanCheck = scanf("%lf", &value); //get error check value and read user input
    
    if(!errorCheck(scanCheck) || value < 0){ //if invalid or less and zero, fail and try again
        printf("That is an invalid value, please press enter and try again.\n");
        scanf("%*c"); //waits for input
        value = getValue();
        return value;
    }
    else {
        return value;
    }
}

//  check input for errors
bool errorCheck(int scanCheck)
{
    bool check;
    if(scanCheck == 1){
        check = true;
    }
    else {
        check = false;
    }
    return check;
}

/*  given the values of student's assignment mark, and maximum possible mark, compute results
    using studentMark divided by maxMark. */
double getResults(double studentMark, double maxMark)
{
    double result;
    result = studentMark/maxMark*100; //also multiply by 100 to get a formatted % value
    return result;
}

// print all values
void PrintResults(double studentMark, double maxMark, double result)
{
    printf("The student got %0.1lf out of %.0lf, or %.2lf%%\n", studentMark, maxMark, result);
    return;
}
