// pex1.cpp

#include "CommandHandler.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    CommandHandler handler;
    string command;

    while (true)
    {
        // menu
        cout << "\nAvailable commands:\n";
        cout << "1. submit\n";
        cout << "2. execute\n";
        cout << "3. lottery\n";
        cout << "4. quit\n";
        cout << "Enter your choice: ";
        cin >> command;

        if (command == "submit" || command == "1")
        {
            handler.submit();
        }
        else if (command == "execute" || command == "2")
        {
            handler.execute();
        }
        else if (command == "lottery" || command == "3")
        {
            handler.lottery();
        }
        else if (command == "quit" || command == "4")
        {
            handler.quit();
        }
        else
        {
            cout << "Invalid command. Please try again.\n";
        }
    }

    return 0;
}
