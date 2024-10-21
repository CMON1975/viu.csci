#include <iostream>
#include "flag.h"
using namespace std;

int main()
{
    Flag starFlag(5, 3, '*');
    Flag *flagPtr = new Flag();

    cout << "info of star flag:\n"
         << "width: " << starFlag.GetWidth() << " "
         << "height: " << starFlag.GetHeight() << endl;

    starFlag.Display();

    if (starFlag.BigFlag()) {
        cout << "star flag is a big flag.\n";
    } else {
        cout << "star flag is a small flag.\n";
    }

    cout << "info of a dynamically created flag:\n"
         << "width: " << flagPtr->GetWidth() << " "
         << "height: " << flagPtr->GetHeight() << endl;

    flagPtr->Display();

    flagPtr->Resize(7, 5);
    flagPtr->Display();

    if (flagPtr->BigFlag()) {
        cout << "the dynamically created flag is a big flag.\n";
    } else {
        cout << "the dynamically created flag is a small flag.\n";
    }

    delete flagPtr;

    return 0;
}
