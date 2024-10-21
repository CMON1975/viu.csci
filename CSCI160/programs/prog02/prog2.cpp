/*  Christopher "Jack" Nilssen
    prog2.cpp

    This program computes and displays the result of compound interest over a period of years, 
    allows the user to select the number of years, the frequency of compounding, the principal
    amount, and the annual interest rate. */

#include <cstdio>
#include <cmath>

//  describe program to the user
void Instructions();

//  prompt user for values
void GetValues(double &principal, double &term, double &frequency, double &interest);

/*  read and return a value (no error checking currently performed) */
double getValue();

/*  given the values of principal, term, frequency, and interest, compute and return
    the results of the compounding formula principal*(1+(interest/frequency)^(term*frequency)
    (no error checking currently performed) */
double getResults(double principal, double term, double frequency, double interest);

// print all values
void PrintResults(double principal, double term, double frequency, double interest,
    double result);

int main()
{
    //  variables to hold the user values and resulting compounded interest
    double userPrincipal, userTerm, userFrequency, userInterest, compoundInterest;
    //  describe the program to the user
    Instructions();
    //  prompt user for values
    GetValues(userPrincipal, userTerm, userFrequency, userInterest);
    // calculate and store the compoundInterest
    compoundInterest = getResults(userPrincipal, userTerm, userFrequency, userInterest);
    // display the results
    PrintResults(userPrincipal, userTerm, userFrequency, userInterest, compoundInterest);
    // end the program
    return 0;
}

// describe program to the user
void Instructions()
{
    printf("Welcome to InterestCalc, a program that calculates the result\n");
    printf("   of compound interest over a period of years.\n\n");
    printf("You will be asked to specify an initial monetary amount,\n");
    printf("   the term of the calculation, the annual interest rate,\n");
    printf("   and the frequency at which interest is compounded.\n");
    return;
}

// prompt user for values
void GetValues(double &principal, double &term, double &frequency, double &interest)
{
    printf("Please enter the principal (initial amount of money): ");
    principal = getValue();
    printf("Please enter the term for the calculation (number of years): ");
    term = getValue();
    printf("Please enter the number of times per year interest should be compounded ");
    printf("(e.g. 12 for monthly): ");
    frequency = getValue();
    printf("Please enter the interest rate as a fraction (e.g. 0.05 for a 5%% annual ");
    printf("interest rate): "); 
    interest = getValue();
    return;
}

/*  read and return a value (no error checking currently performed) */
double getValue()
{
    double value;
    scanf("%lf", &value);
    return value;
}

/*  given the values of principal, term, frequency, and interest, compute and return
    the results of the compounding formula principal*(1+(interest/frequency)^(term*frequency)
    (no error checking currently performed) */
double getResults(double principal, double term, double frequency, double interest)
{
    double compoundInterest;
    compoundInterest = principal*pow((1+(interest/frequency)),(term*frequency));
    return compoundInterest;
}

// print all values
void PrintResults(double principal, double term, double frequency, double interest,
    double result)
{
    // convert interest to a non-decimal value
    interest = interest*100;

    printf("With a principal of $%0.2lf, ", principal);
    printf("annual interest rate of %0.0lf%%,\n", interest);
    printf("   compounded %0.0lf time(s) per year over %0.0lf year(s),\n", frequency, term);
    printf("the amount of money at the end of the term will be $%0.2lf\n", result);
    return;
}
