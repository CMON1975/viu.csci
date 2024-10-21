/*  Christopher "Jack" Nilssen
    lab2.cpp

    This program computes the liquid capacity of a fish tank in litres
    based on user-defined dimensions. */

#include <cstdio>

//  constant value for number of cubic inches in one litre
const double InchesPerLitre = 61.0;

//  describe program to the user
void Instructions();

//  prompt user for dimensions
void GetDimensions(double &length, double &width, double &depth);

/*  read and return an inches value (no error checking currently performed) */
double getInches();

/*  given the tank dimensions in inches, compute and return
    the capacity of the tank in litres (no error checking currently performed) */
double getCapacity(double length, double width, double depth);

//  print all values
void PrintResults(double length, double width, double depth, double capacity);

int main()
{
    //  variables to hold the dimensions and capacity
    double userLength, userWidth, userDepth, totalCapacity;
    //  describe the program to the user
    Instructions();
    //  get and store the tank dimensions
    GetDimensions(userLength, userWidth, userDepth);
    //  calculate and store the capacity in litres
    totalCapacity = getCapacity(userLength, userWidth, userDepth);
    //  display the results
    PrintResults(userLength, userWidth, userDepth, totalCapacity);
    //  end the program
    return 0;
}

//  describe program to the user
void Instructions()
{
    printf("Welcome to the capacity-caluclator, a program to compute\n");
    printf("   the capacity of your fish tank based on its dimensions.\n");
    printf("You will be prompted to enter the length, width, and depth of the tank\n");
    printf("   (in inches), and the capacity (in litres) will be displayed.\n\n");
    return;
}

//  prompt user for dimensions
void GetDimensions(double &length, double &width, double &depth)
{
    printf("Please enter the tank length in inches, e.g. 10.5\n");
    length = getInches();
    printf("Please enter the tank width in inches, e.g. 24.5\n");
    width = getInches();
    printf("Please enter the tank depth in inches, e.g. 6.5\n");
    depth = getInches();
    return;
}

/*  read and return an inches value (no error checking currently performed) */
double getInches()
{
    double inches;
    scanf("%lf", &inches);
    return inches;
}

/*  given the tank dimensions in inches, compute and return
    the capacity of the tank in litres (no error checking currently performed) */
double getCapacity(double length, double width, double depth)
{
    double capacity;
    capacity = (length*width*depth)/InchesPerLitre;
    return capacity;
}

//  print all values
void PrintResults(double length, double width, double depth, double capacity)
{
    printf("A tank that is %0.2lf x %0.2lf x %0.2lf inches has a capacity of %0.2lf litres.\n",
        length, width, depth, capacity);
    return;
}
