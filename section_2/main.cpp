#include <iostream>
#include "fundamental_types.h"
#include "conditionals.h"

// Do not return const types, prefer const macros
constexpr int running = 1; // value is known at compilation, faster
constexpr int alwaysKnown();

int main()
{
    std::cout << "\nWelcome to section 2, notes put into practice." << std::endl;

    numericalTypes();
    fixedInts();
    fastleastInts();
    decimalTypes();
    bools();
    charStrings();

    std::cout << "\nThis variable will always be running, it is a const and can't change." << std::endl;
    std::cout << "This function generates has no variables / parameters that must be resolved at runtime.";
    std::cout << "\n";

    std::cout << "\n";
    howIf(110);
    howIf(25);
    howIf(38);
    howIf(43);
    howIf(0);
    howIf(-510);
    howIf(-65);
    howIf(-78);
    howIf(-3);

    std::cout << "\n";
    floatRounding(2.896, 2.89601);

    std::cout
        << "\n";

    return 0;
}

constexpr int alwaysKnown()
{
    int seed = 123456789;
    return seed;
}