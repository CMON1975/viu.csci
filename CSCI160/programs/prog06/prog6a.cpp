/*  Christopher "Jack" Nilssen
    prog6.cpp
    This program gets the user to enter a series of up to one hundred non-zero numbers, storing
    them in an array. The program stops reading as soon as any one of the following happens:

    they enter a non-number, e.g. "foo",
    they enter zero as a number, e.g. 0 or 0.00,
    they have entered one hundred numbers. 

    Once the program has stopped reading/storing numbers, it then displays all the negative 
    numbers the user entered, in the same order they entered them, then it displays all the 
    positive numbers entered, in the same order they were entered. 
 */

#include <cstdio>

//max number user entries
const int MaxNumbers = 100;

//text dump user instructions at launch
void userWelcome();

//fills an array with non-zero numbers from the user (up to MaxNumbers) and returns size
int fillArray(float userNumbers[]);

//gets a number from the user, with error checking
float getNumber();

//sort the user numbers from least to greatest
void sortNumbers(int arraySize, float userNumbers[]);

//swap floats in array
void swap(float &a, float &b);

//prints the sorted results, separated by sign
void printResults(int arraySize, float userNumbers[]);

int main()
{
    // the array of user numbers
    float userNumbers[MaxNumbers];

    // the number of user numbers
    int arraySize;

    // provide the program overview
    userWelcome();

    //fills an array of non-zero numbers from the user (up to MaxNumbers), with error checking
    arraySize = fillArray(userNumbers);

    if(arraySize>1){ //checking for more than one value to sort
        // sort the user numbers
        sortNumbers(arraySize, userNumbers);
    }
    if(arraySize>0){ //check for empty array to avoid report
        // display the sorted results
        printResults(arraySize, userNumbers);
    }

    else { //exit due to zero array
        printf("\nLeaving the program because you gave me nothing to do.\n\n");
    }

    //end program  
    return 0;
}

//text dump user instructions at launch
void userWelcome()
{
    printf("Welcome to the number-saver.\n\n");

    printf("You will be asked to enter up to %d non-zero numbers,\n", MaxNumbers);
    printf("ending with a zero or a non-number.\n\n");

    printf("Once all values have been entered, all the negative numbers\n");
    printf("will be displayed (in the order entered) then all the positive\n");
    printf("numbers will be displayed (in the order entered).\n\n");
}

//fills an array with non-zero numbers from the user (up to MaxNumbers) and returns size
int fillArray(float userNumbers[])
{
    int index = 0; //initialize starting point for array fill
    
    do { //loop, filling the array until user ends or hits maximum entries
        userNumbers[index] = getNumber(); //fill the current index with a float
        if(userNumbers[index] == 0) { //user entered zero, exit loop
            return index;
            break;
        }
        else {
            index++; //user entered a valid number, continue
        }
    } while (index < MaxNumbers);
    return index;   
}

//gets an array of non-zero numbers from the user (up to MaxNumbers), with error checking
float getNumber()
{
    float result = 0; //actual value read for return
    int valsRead = 0; //error check
    do {
        printf("Please enter a non-zero number (0 or a non-number to end):  ");
        valsRead = scanf("%f", &result); //scan
        if (valsRead < 1) { //check
            printf("That was not a number, please try again\n");
            scanf("%*s"); //clear
        }
    } while (valsRead < 1); //repeat until valid entry
    return result;
}

//sort the user numbers from least to greatest
void sortNumbers(int arraySize, float userNumbers[])
{
    bool sorted = false; //check for sortedness

    while (!sorted) { //until sorted
        for(int i=0;i<arraySize-1;i++){ //loop through array up to user's values
            if(userNumbers[i]>userNumbers[i+1]){ //if next in sequence smaller, 
                swap(userNumbers[i], userNumbers[i+1]); //swap in sequence
                sorted = false;
                i = -1; //return to start
            }
            else { //when no more sorting to be done
                sorted = true;
            }
        }
    } 
    return;
}

//prints the sorted results, separated by sign
void printResults(int arraySize, float userNumbers[])
{
    int totalNegatives = 0;
    int totalPositives = 0; //initialize counters to minimize report array sizes
    
    for(int i=0;i<arraySize;i++){
        if(userNumbers[i]<0){
            totalNegatives++;
        }
        if(userNumbers[i]>0){
            totalPositives++;
        }
    } //iterate through collected array and count number of negatives and positives

    float negatives[totalNegatives];
    float positives[totalPositives]; //initialize report arrays of exact size

    for(int i=0;i<totalNegatives;i++){
        negatives[i] = userNumbers[i]; //fill negative value array
    }

    for (int i=0;i<totalPositives;i++){
        positives[i] = userNumbers[totalNegatives+i]; //fill positive array
    }

    if(totalNegatives>0){ //check for no values

        if(totalNegatives>1){ //grammar check for UX
            printf("The negative numbers entered were: ");
        }
        else {
            printf("The negative number entered was: ");
        }

        for(int i=0;i<totalNegatives;i++){  //print the negative numbers
            if(i<totalNegatives-1){ //for all numbers under final value, add comma
                printf("%g, ",negatives[i]);
            }
            else { //for final value, no comma and new line
                printf("%g\n",negatives[i]);
            }
        }
    }
    else {
        printf("There were no negative numbers entered.\n");
    }
    
    if(totalPositives>0){ //check for no values
        
        if(totalPositives>1){ //grammar check for UX
            printf("The positive numbers entered were: ");
        }
        else {
            printf("The positive number entered was: ");
        }
        
        for(int i=0;i<totalPositives;i++){  //print the positive numbers
            if(i<totalPositives-1){ //for all numbers under final value, add comma
                printf("%g, ",positives[i]);
            }
            else { //for final value, no comma and new line
                printf("%g\n",positives[i]);
            }
        }
    }
    else {
        printf("There were no positive numbers entered.\n");
    }
    return;
}

//swap two results in float array
void swap(float &a, float &b)
{
    float temp;
    temp = a;
    a = b;
    b = temp;
    return;
}
