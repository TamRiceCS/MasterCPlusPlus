// This file should be kept as clean as possible
// #include is a preprocessor directive, the preprocessor 'renders' code before compilation
// You can also make macros for the preprocessor to handle

#include <iostream>   // input + output
#include <stdio.h>    // needed for __function__
#include "varmanip.h" // Copies forward declarations into this file, main.cpp
// Forward Declare variables when they are defined after where they are used or in another file
// "" hints at user defined, <> hints at a downloaded file, library, etc.
// If an included files have their own defines, they will be inherited here as well, DON'T RELY ON THIS

#define version 1.1 // First run through, section 1
// #undef version // undefine version macro
#define tautology() while (true)
#define parent() std::cout << __func__ << std::endl;
// define has global scope, even if they are placed in a function

// One Definition Rule: different variables should not share a name within the same scope
// You can define types, templates, inline functions, and inline variables again as long as all indentical

// Do NOT use the 'using' directive, increases risk of name space collisions

// Entry point of the program

int global = 100; // Global scope, can be seen in whole file

int main()
{
    // :: is scope resolution, tells compiler were things are defined. std is the standard library
    std::cout << "\nWelcome to section 1, notes put into practice." << std::endl;

#ifdef version // Protects code, if version is not defined, it will be skipped
    std::cout << "Currently running version " << version << std::endl;
#endif

#ifndef version // Protects code, if version is not defined, this will run
    std::cout << "Version is not defined..." << std::endl;
#endif

    parent(); // Reports what function is running

    int testTautology = 0;

    tautology() // Preprocessor will replace this w/ while(true)
    {
        std::cout << "Thank you for running the program..." << std::endl;
        testTautology++;
        if (testTautology > 0)
        {
            break;
        }
    }

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