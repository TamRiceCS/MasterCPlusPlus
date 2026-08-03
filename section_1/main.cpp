// This file should be kept as clean as possible
#include <iostream>
#include "varmanip.h" // Copies forward declarations into this file, main.cpp
// Forward Declare variables when they are defined after where they are used or in another file

// One Definition Rule: different variables should not share a name within the same scope
// You can define types, templates, inline functions, and inline variables again as long as all indentical

// Do NOT use the 'using' directive, increases risk of name space collisions

// Entry point of the program

int global = 100; // Global scope, can be seen in whole file

int main()
{
    // :: is scope resolution, tells compiler were things are defined. std is the standard library
    std::cout << "\nWelcome to section 1, notes put into practice." << std::endl;

    varInit();
    varMath();
    basicIO();

    emptyFunction();
    doubleNum(25); // Uncaught return is a temp obj, nbd
    multiplyThree(10, 20, 30);
    defaultMultiply(21);
    ignoreParam(999, 2); // Legacy call with 2 params
    // Just because a variable returns a value does not mean it must be used / caught

    int value = 111; // Local Scope only seen in main
    int *reference = &value;

    passBy(value, reference);

    std::cout << "\n";
    return 0; // Represents normal exit
}

/*
This is an example...
Of a multi-line comment...
Enjoy!
*/