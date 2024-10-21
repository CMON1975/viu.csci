/*  Christopher "Jack" Nilssen
    lab7.cpp
    This program takes a single word as a command line argument, treats it as a text string,
    and makes an all-uppercase duplicate of it, with error-check for pre-existing capitalization 
*/

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>

// convert a null-terminated text string to uppercase with error checking (pre-capitalized arg)
bool convertToUpper(char str[]);

// check if the number of arguments was correct
bool checkArgs(int args, char *argv[]);

// print conversion
void printResults(char *argv[]);

int main(int argc, char *argv[])
{
    if (checkArgs(argc, argv)){ //if 1 arg entered, capitalize and print
        printResults(argv);
    }
    // end the program
    return 0;
}

// check if the number of arguments was correct
bool checkArgs(int args, char *argv[])
{
    if(args != 2){
        printf("An incorrect number of arguments was provided\n");
        printf("This program allows you to enter one word as a command line argument,\n");
        printf("and it then provides an uppercase translation of it, e.g.\n");
        printf("    ./lab7x Original\n");
        printf("    The original string was\n");
        printf("    \"Original\"\n");
        printf("    and the uppercase is\n");
        printf("    \"ORIGINAL\"\n");
        return false;
    }
    else {
        return true;
    }
}

// display results
void printResults(char *argv[])
{
    printf("The original string was\n"); //print original string
    printf("    \"%s\"\n", argv[1]); 
    if(!convertToUpper(argv[1])) { //test for and convert string to uppercase
        printf("and the uppercase is\n");
        printf("    \"%s\"\n", argv[1]);
    }
    else { //print special case
        printf("and was already uppercase\n");
    }   
    return;
}

// convert a null-terminated text string to uppercase with error checking (pre-capitalized arg)
bool convertToUpper(char str[])
{
    bool converted = false; //switch to test for conversions
    int upperCount = 0; //count for number of existing uppercase chars

    int stringLength = strlen(str); //size of incoming string

    for(int i=0;i<stringLength;i++){ 
        if(!isupper(str[i])) { //iterate over and capitalize incoming string char by char
            str[i] = toupper(str[i]);
        }
        else { //unless already capitalized
            upperCount++;
        }
    }

    if(upperCount == stringLength) { //if the number of pre-existing caps is the same as string length
        converted = true;
    }

    return converted;
}
