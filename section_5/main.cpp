#include <iostream>
#include "functions.h"

int main()
{
    std::cout << "\nWelcome to section 5, notes put into practice." << std::endl;

    // template example of a function ptr, don't make funcPtrs on void
    bool (*comparePtr)(int, int) = &compare<int>;
    bool (*const comparePtrConst)(int, int) = &compare<int>; // make a funcptr const

    std::cout << "Is " << 5 << " greater than " << 10 << "?" << std::endl;
    // implicit then explicit
    std::cout << "\t" << comparePtr(5, 10) << " can also call " << (*comparePtr)(5, 10) << std::endl;

    return 0;
}