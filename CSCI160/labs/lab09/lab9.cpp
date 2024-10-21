/* Christopher Nilssen (Jack)
   lab8.cpp
   This program stores information about different types of parts stored in a warehouse. 
   Each part will have an id number, a description, and a price.
*/

#include <cstdio>

// maximum length for a part description
const int MaxLen = 256;

// Part definition:
//    each part is defined by three components:
//    a unique integer id, a price, and a text description
struct Part {
   long id;
   float price;
   char description[MaxLen];

};

// get the user to provide the id, description, and price for the part
void partEntry(Part &p);

// display the part id, price, and description, using the following layout:
// Part ID:     3865132
// Price:       $19.99
// Description: This part is a completely useless overpriced gizmo.
void partDisplay(Part p);

int main()
{
   Part p;
   partEntry(p);
   printf("The part information is as follows:\n");
   partDisplay(p);
}

// get the user to provide the id, description, and price for the part
void partEntry(Part &p)
{
   printf("Please enter the part id as an integer (e.g. 315679)\n");
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

