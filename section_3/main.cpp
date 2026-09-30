#include <iostream>
#include "functions.h"

bool oppositeDay(bool fact = false); // declare default values in forward declaration, can't do both

int main()
{
    std::cout << "\nWelcome to section 3, notes put into practice." << std::endl;

    // Allowed to overload via type and number of parameters, not return type or default values
    std::cout << "\nFunction overloading:" << std::endl;
    std::cout << "Add 1 + 2: \t" << add(1, 2) << std::endl;
    std::cout << "Add 1 + 2 + 3: \t" << add(1, 2, 3) << std::endl;
    std::cout << "Add \"Apple\" + \"Sauce\": \t" << add("Apple", "Sauce") << std::endl;
    std::cout << "Add \'a\' + \'b\': \t" << add('a', 'b') << std::endl;
    std::cout << "\n";

    std::cout << "\nDefault Arguments:" << std::endl;
    echo();
    echo("Meow");
    repeat("Woof", 2);
    repeat("Woof");
    std::cout << "\tHere are the facts: " << oppositeDay() << " Wait no actually: ";
    std::cout << oppositeDay(true) << std::endl;
    std::cout << "\tDifferent ways to multiply:" << std::endl;
    std::cout << "\t\tone->" << multiply();
    // Will fill default parameters left to right
    std::cout << "\t one->" << multiply(3) << "\t two->" << multiply(2, 3);
    std::cout << "\t three->" << multiply(2, 3, 4) << std::endl;
    std::cout << "\n";

    report<char>('a');
    report<int>(1);
    report<double>(1.23); // try this with type float and watch it crash
    // type will be deduced
    report<>(true);
    report<>((double)1.23); // can also c-style cast and atatic-cast (no example included)

    report<int, bool>(1, false);
    report<int, int>(1, 2);
    yolo<'t'>();

    std::cout
        << "\n";

    return 0;
}

bool oppositeDay(bool fact)
{
    return !fact;
}