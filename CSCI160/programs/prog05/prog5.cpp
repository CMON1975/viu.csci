/*  Christopher "Jack" Nilssen
    prog5.cpp
    This program draws an ascii circle of user-specified size */

#include <cstdio>
#include <cmath>

// constants for upper and lower circle size constraints
const int HighLimit = 20;
const int LowLimit = 1;

// gets radius value from user, with error checking
int getInteger();

// draws a "circle" based on user input
void drawCircle(int radius);

int main()
{
    // user instructions
    printf("Welcome to the circle-drawing program\n");
    printf("Please enter a circle radius as an integer in the range 1..20\n");
    // get radius value
    int radius = getInteger();
    // draw circle
    drawCircle(radius);
    // end program
    return 0;
}

// gets radius value from user, with error checking
int getInteger()
{
    // create a userVal variable, and a valsRead variable
    int userVal = 0;
    int valsRead = 0;
    // loop until valid entry made
    do {
        // try a scanf, putting the user-entered value into userVal
        //     and the return value from scanf into valsRead
        valsRead = scanf("%d", &userVal);
        // if valsRead is 0 then print an error message
        //     and use scanf("%*s") to discard the user input
        if(valsRead == 0){
            printf("That is not an integer, please try again.\n");
            scanf("%*s");
        }        
        // if userVal is < lower limit then print an error message
        else if(userVal<LowLimit){
            printf("That was less than %d, please try again\n", LowLimit);
        }
        // if userVal is > upper limit then print an error message
        else if(userVal>HighLimit){
            printf("That was greater than %d, please try again\n", HighLimit);
        }
    } while ((valsRead == 0) || (userVal < LowLimit) || (userVal > HighLimit));
   
    // then return the user value
    return userVal;
}

void drawCircle(int radius)
{
    // set the diameter based on user input
    int diameter = radius*2;
    // use float for distance for more accurate drawing
    float distance = 0;
    // nested loop produces circle
    for (int row = 0; row <= diameter; row++){ //each row from 0 to diameter, inclusive
       for (int col = 0; col <= diameter; col++) { //each column from 0 to diameter, inclusive
           distance = 4*pow(row-radius,2) + pow(col-radius,2);
           distance = sqrt(distance);
            if (distance > radius) {
                printf(" "); // print a space
            }
            else { // otherwise print an *
                printf("*");
            }
        }
        printf("\n"); // print a newline to end the row
    }
    return;
}
