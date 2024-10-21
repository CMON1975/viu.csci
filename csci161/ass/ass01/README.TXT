************************************************************************************************

   File: Pex1.cpp
   Author: Christopher Nilssen (Jack)
   Date: January 11, 2017
   Updated: January 13, 2017

   Purpose: This program helps a fast food chain store (such as a McDonald's store) 
   maintain its customer orders. A single customer order record contains three items: 
   a burger, a side dish and a drink. Each customer order is assigned (by your program) 
   a three-digit order number that is between 100 and 999 (inclusive). 

   Notes: This program uses a doubly linked list to maintain the list of the records, with a
   single "dummy" head node.

   How to compile: from Linux prompt, g++ Pex1.cpp -o Pex1x -Wall

   How to run: from Linux prompt ./Pex1x will display a short welcome message and menu of 
   options. All options are case-inclusive. 
      "O" to make a new order, which prompts the user to enter a type of burger, a sidedish, 
         and a drink, then provides an order number, starting with 100. The user will recieve 
         a warning if the maximum order number (999) has been reached.
      "S" to serve an existing order, removing it from memory. The user will recieve a warning
         if there are no orders in memory.
      "V" to view existing orders, from oldest to latest. The user will recieve a warning if
         there are no orders in memory.
      "H" to re-display the option menu.
      "T" to terminate the program, providing there are no unserved orders. The user will
         recieve a warning if there are orders in memory.

   Completed parts: all assigned parts completed.

   Updates: Jan 13 - Renamed variables to make more sense.

   Known bugs: none.

   Marker's attention: the spec titled the program "Welcome to Library Reservation System",
      I assumed this was actually a "Food Order System" and titled it as such.

************************************************************************************************
