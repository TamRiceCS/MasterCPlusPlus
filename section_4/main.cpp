#include <iostream>
#include "listContainer.h"
#include <vector>

int main()
{
    std::cout << "\nWelcome to section 3, notes put into practice." << std::endl;

    std::cout << "\n";
    makeVector();
    vectorAccess();
    std::vector<int> dummy;
    vectorPassing(dummy, dummy, dummy);

    std::cout
        << "\n";
    return 0;
}