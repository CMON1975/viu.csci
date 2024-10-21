/*  Christopher "Jack" Nilssen
    prog7.cpp
    This program allows the user to enter multiple words on the command line. For each word 
    entered, the program counts and displays how many characters the argument has and how many 
    of them are alphabetic. The program then displays the total number of characters in all 
    the words, and displays all the words concatenated together.  
*/

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>

//count and display the number of chars in the arg and how many of them are alphabetic
//concatenate all args and print with total chars
void mainPrint(int args, char *argv[]);

//count alpha chars and return value
int countAlphaChars(char str[], int length);

int main(int argc, char *argv[])
{
    mainPrint(argc, argv);
    return 0;
}

//count and display the number of chars in the arg and how many of them are alphabetic
//concatenate all args and print with total chars
void mainPrint(int args, char *argv[])
{
    int totalLength = 0; //init value for total of concat array

    for(int i=0;i<args;i++){ //print each arg with index,length, and number of alpha chars
        int length = strlen(argv[i]); //get current string length for ease
        totalLength+= length; //add to length sum
        printf("argument %d is \"%s\", ", i, argv[i]);
        printf("has length %d, ", length);
        printf("contains %d alphabetic characters\n", countAlphaChars(argv[i],length));
    }

    char joinedStrings[totalLength] = ""; //init string for combining args

    for(int i=0;i<args;i++){ //combine args into array
        strcat(joinedStrings,argv[i]);
    }
    
    printf("Total length %d: %s\n", totalLength, joinedStrings); //print final total
    return;
}

//count alpha chars and return value
int countAlphaChars(char str[], int length)
{
    int count = 0;
    for(int i = 0;i<length; i++){
        if(isalpha(str[i])){
            count++;
        }
    }
    return count;
}
