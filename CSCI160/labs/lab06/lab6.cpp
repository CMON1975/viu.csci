/*  Christopher "Jack" Nilssen
    lab6.cpp
    This program records the seating capacity of a number of vehicles, then prints the results.
 */

#include <cstdio>

//max number of vehicles supported
const int MaxVehicles = 25;
//max vehicle seating capacity supported
const int MaxCapacity = 36;

//gets the number of vehicles from the user, with error checking
int getInteger(int min, int max);

//fills array with vehicle capacities
void getCapacities(int vehicles[], int numVehicles);

//prints the vehicle capacities
void printResults(int vehicles[], int numVehicles);

int main()
{
    // the array of vehicle capacities, and the number of vehicles actually in use
    int vehicleCaps[MaxVehicles];

    // provide the program overview
    printf("\nThis program will obtain and display the seating capacity ");
    printf("of a collection of vehicles\n\n");

    // get the number of vehicles actually in use
    printf("How many vehicles are there in total?\n");
    int numVehicles = getInteger(1, MaxVehicles);
    printf("\n");

    // get the vehicle capacities
    getCapacities(vehicleCaps, numVehicles);

    // display the vehicle capacities
    printResults(vehicleCaps, numVehicles);

    //end program  
    return 0;
}

//gets the number of vehicles from the user, with error checking
int getInteger(int min, int max)
{
    int result = 0;
    int valsRead = 0;
    do {
        printf("Please enter an integer in the range %d..%d (inclusive): ", min, max);
        valsRead = scanf("%d", &result);
        if (valsRead < 1) {
            printf("That was not an integer, please try again\n");
            scanf("%*s");
        } else if (result < min) {
            printf("That was less than %d, please try again\n", min);
        } else if (result > max) {
            printf("That was greater than %d, please try again\n", max);
        }
    } while ((valsRead < 1) || (result < min) || (result > max));
    return result;
}

//fills array with vehicle capacities
void getCapacities(int vehicles[], int numVehicles)
{
    for(int i=0; i< numVehicles; i++){
        printf("What is the capacity for vehicle %d\n", i+1);
        vehicles[i] = getInteger(0, MaxCapacity);
    }
    return;
}

//prints the vehicle capacities
void printResults(int vehicles[], int numVehicles)
{
    // declare value for summing/printing total capacity
    int totalCapacity = 0;

    printf("The vehicle capacities are: ");
    for(int i=0; i< numVehicles; i++){
        totalCapacity+=vehicles[i]; //sum values iteratively
        if(i<numVehicles-1){
            printf("%d, ", vehicles[i]); //prior to end of array use , separator
        }
        else {
            printf("%d\n", vehicles[i]); //at end of array make new line
        }
    }
    printf("The total capacity of all vehicles is: %d\n", totalCapacity);
    return;
}
