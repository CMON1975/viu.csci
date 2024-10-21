/*  Christopher "Jack" Nilssen
    lab5.cpp
    This program promps the user for an integer, reads their response, and checks it for
    validity. Then it uses the valid integers and counts down by two's, stopping before 
    reaching sub-zero values. */

#include <cstdio>

int getInteger(); // read and error check a value from user
void countdown (int orig); // take a value, print it, minus 1, continue until 0

int main()
{
   printf("Please enter an integer value, then we will display a countdown by two\'s\n");
   int original = getInteger();
   countdown(original);
   printf("done!\n");
   return 0;
}

int getInteger() // read and error check a value from user
{
    int userVal = 0;
    int valsRead = 0;
    // create a userVal variable, and a valsRead variable
    do {
        // try a scanf, putting the user-entered value into userVal
        //     and the return value from scanf into valsRead
        valsRead = scanf("%d", &userVal);
        // if valsRead is 0 then print an error message
        //     and use scanf("%*s") to discard the user input
        if(valsRead == 0){
            printf("That is not a valid entry, please try again.\n");
            scanf("%*s");
        }        
        // otherwise if userVal is less than 0 then print an error message
        //     (but do NOT scanf %*s)
        else if(userVal<0){
            printf("That is not a valid entry, please try again\n");
        }
    } while ((valsRead == 0) || (userVal < 0));
   
    // then return the user value
    return userVal;
}

void countdown(int orig) // take a value, print it, minus 1, continue until 0
{
    // while orig >= 0
    while (orig >=0) {
        printf("%d\n", orig);   // print orig
        orig-=2;     // subtract 2 from orig
    }
    return;
}

