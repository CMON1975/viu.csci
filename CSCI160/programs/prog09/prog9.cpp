/* Christopher Nilssen (Jack)
   prog9.cpp
   This program asks the user to specify how many parts they wish to process, they can pick    
   any integer value in the range 1 to 20.

   It then gathers the information about each of the 20 parts.

   Once information has been gathered for all the parts, it will go through the parts and 
   display the information about each one.

   I have not included error checking.
*/

#include <cstdio>

// maximum length for a part description
const int MaxLen = 256;
// maximum number of part entries
const int MaxParts = 20;

// Part definition:
//    each part is defined by three components:
//    a unique integer id, a price, and a text description
struct Part {
   long id;
   float price;
   char description[MaxLen];
};

// get the value from user for number of parts, with limit of MaxParts
int getPartArrayLength();

// get the user to provide the id, description, and price for the part
void partEntry(Part &p, int index);

// display the part id, price, and description, using the following layout:
// Part ID:     3865132
// Price:       $19.99
// Description: This part is a completely useless overpriced gizmo.
void partDisplay(Part p);

int main()
{
   int partsLength = getPartArrayLength();
   // initialize parts array
   Part parts[partsLength];

   // iterate through and fill parts array
   for(int i = 0; i<partsLength; i++){
      partEntry(parts[i], i);
   }

   printf("\nThe part information is as follows:\n");
   // iterate through and display parts array
   for(int i = 0; i<partsLength; i++){
      partDisplay(parts[i]);
   }
}

// get the value from user for number of parts, with limit of MaxParts
int getPartArrayLength()
{
   int length = 0; //actual value read for return
   int valsRead = 0; //read error check
   bool isValid = false; //valid value error check
   do {
      printf("How many parts would you like to process (1..%i)? ", MaxParts);
      valsRead = scanf("%i", &length); //scan
      if (valsRead < 1) { //check
         printf("That was not a number, please try again\n");
         scanf("%*s"); //clear
      } else if (length<1) {
         printf("That was less than 1, please try again\n");
      } else if (length>MaxParts) {
         printf("That was greater than %i, please try again\n", MaxParts);
      } else {
         isValid = true;
      }
   } while (!isValid); //repeat until valid entry

   // return value
   return length;
}

// get the user to provide the id, description, and price for the part
void partEntry(Part &p, int index)
{
   printf("For part %i, please enter the part id as an integer (e.g. 315679)\n", index+1);
   scanf("%ld", &p.id);
   scanf("%*c");
   //error in spec, it's going to be either MaxLen-1 allowed, or rewritten to allow MaxLen
   printf("Please enter the part description, up to %i characters\n", MaxLen-1);
   fgets(p.description, MaxLen, stdin);
   printf("Please enter the price as a number\n$");
   scanf("%f", &p.price);
   return;
}

// display the part id, price, and description, using the following layout:
// Part ID:     3865132
// Price:       $19.99
// Description: This part is a completely useless overpriced gizmo.
void partDisplay(Part p)
{
   printf("Part ID:     %ld\n", p.id);
   printf("Price:       $%g\n", p.price);
   printf("Description: %s\n", p.description);
   return;
}

