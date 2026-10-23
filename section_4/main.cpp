#include <iostream>
#include "listContainer.h"
#include <vector>
#include <array>

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
    makeArray();
    arrayAccess();

    std::array<int, (std::size_t)5> example;
    arrayPassing(example, example, example);

    makeCArray();
    CArrayAccess();

    int basic[3];
    CArrayPassing(basic);
    cString();
    multiDimensional();

    std::cout
        << "\n";
    return 0;
}