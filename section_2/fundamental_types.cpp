#include <iostream>

void numericalTypes()
{

    std::cout << "\nBasic Integer types: their size and range..." << std::endl;
    // Can slap int in front of short, long, and long long, don't
    short int wrorngShort = 1;
    short rightShort = 22;
    int basicInt = 333;
    long int wrongLong = 4444;
    long rightLong = 55555;
    long long int wrongLongLong = 666666;
    long long rightLongLong = 7777777;

    std::cout << "* Shorts have " << sizeof(rightShort) << " bytes " << std::endl;
    std::cout << "\tAnd ranges... [" << SHRT_MIN << "," << SHRT_MAX << "]" << std::endl;

    std::cout << "* Ints have " << sizeof(basicInt) << " bytes " << std::endl;
    std::cout << "\tAnd ranges... [" << INT_MIN << "," << INT_MAX << "]" << std::endl;

    std::cout << "* Longs have " << sizeof(rightLong) << " bytes " << std::endl;
    std::cout << "\tAnd ranges... [" << LONG_MIN << "," << LONG_MAX << "]" << std::endl;

    std::cout << "* Long Longs have " << sizeof(rightLongLong) << " bytes " << std::endl;
    std::cout << "\tAnd ranges... [" << LONG_LONG_MIN << "," << LONG_LONG_MAX << "]" << std::endl;

    std::cout << "\nNotice the pattern? The range is -(2^(bytes*8) to (2^(bytes*8) - 1)" << std::endl;

    // Ints can take the keyword unsigned, DON'T USE IT - EASY TO OVERFLOW -1 will do it

    unsigned int redundantExample = 123; // This is the same range as before redundant.
    signed int easyOverflow = 456;       // Can only handle positive values (0 to 2xINT_MAX)
}