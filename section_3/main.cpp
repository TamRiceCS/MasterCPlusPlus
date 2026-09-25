#include <iostream>
#include "functions.h"

int main()
{
    std::cout << "\nWelcome to section 3, notes put into practice." << std::endl;

    // Allowed to overload via type and number of parameters
    std::cout << "\nFunction overloading:" << std::endl;
    std::cout << "Add 1 + 2: \t" << add(1, 2) << std::endl;
    std::cout << "Add 1 + 2 + 3: \t" << add(1, 2, 3) << std::endl;
    std::cout << "Add \"Apple\" + \"Sauce\": \t" << add("Apple", "Sauce") << std::endl;
    std::cout << "Add \'a\' + \'b\': \t" << add('a', 'b') << std::endl;
    std::cout << "\n";

    std::cout << "\nDefault Arguments:" << std::endl;
    std::cout << "Default function example: ";
    echo();
    echo("Meow");
    repeat("Woof", 2);
    repeat("Woof");
    std::cout << "\n";

    return 0;
}