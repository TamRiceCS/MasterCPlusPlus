#include <iostream>
#include "listContainer.h"
#include <vector>
#include <array>
#include "dynamic.h"

int main()
{
    std::cout << "\nWelcome to section 4, notes put into practice." << std::endl;

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

    SuperSimpleLL<int> exampleDynamic(10);
    exampleDynamic.insertStart(20);
    exampleDynamic.insertStart(30);
    exampleDynamic.insertStart(40);
    exampleDynamic.insertStart(50);
    exampleDynamic.insertEnd(-999);
    exampleDynamic.report();

    // Dynamic Array
    int size = 100; // let's pretend a user entered this, std arrays can't have non const sizes
    int *arr = new int[size];
    std::cout << "\nDynamic arrays are like decayed arrays, no pointer dereferencing needed: \n{";
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
        if (i == size - 1)
        {
            std::cout << arr[i];
            break;
        }
        if (i % 10 == 0 && i != 0)
        {
            std::cout << "\n";
        }
        std::cout << arr[i] << ",  ";
    }
    std::cout << "}" << std::endl;
    delete[] arr;

    std::cout
        << "\n";
    return 0;
}