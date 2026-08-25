#include <iostream>
#include <iomanip>
#include <cstdint>
#include <string>

// All of the functions in this file are extern by default, can be seen and used upon being imported

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

void fixedInts()
{
    // size of 8 ints commonly acts as a char
    std::int8_t signint8 = 1;
    std::uint8_t unsignint8 = 22;
    std::int16_t signint16 = 333;
    std::uint16_t unsignint16 = 4444;
    std::int32_t signint32 = 55555;
    std::uint32_t unsignint32 = 666666;
    std::int64_t signint64 = 7777777;
    std::uint64_t unsignint64 = 88888888;

    std::cout << "\nFixed size ints via cstdint..." << std::endl;
    std::cout << "Here are the guaranteed sizes you can have: " << std::endl;
    std::cout << "\t* " << sizeof(signint8) * 8 << std::endl;
    std::cout << "\t* " << sizeof(signint16) * 8 << std::endl;
    std::cout << "\t* " << sizeof(signint32) * 8 << std::endl;
    std::cout << "\t* " << sizeof(signint64) * 8 << std::endl;
}

void fastleastInts()
{
    // Fastest type w/ a min of x bits
    int_fast8_t fast8 = 1;
    uint_fast8_t ufast8 = 22;
    int_fast16_t fast16 = 333;
    uint_fast16_t ufast16 = 4444;
    int_fast32_t fast32 = 55555;
    uint_fast32_t ufast32 = 666666;
    int_fast64_t fast64 = 7777777;
    uint_fast64_t ufast64 = 88888888;
    // Smallest type w/ a min of x bits
    int_least8_t least8 = 1;
    uint_least8_t uleast8 = 22;
    int_least16_t least16 = 333;
    uint_least16_t uleast16 = 4444;
    int_least32_t least32 = 55555;
    uint_least32_t uleast32 = 666666;
    int_least64_t least64 = 7777777;
    uint_least64_t uleast64 = 88888888;

    std::cout << "\nTest this on a 64bit system and a 32bit system!" << std::endl;
    std::cout << "When you give a fast int a small number..." << std::endl;
    std::cout << "\t *" << sizeof(fast8) * 8 << std::endl;
    std::cout << "\t *" << sizeof(fast16) * 8 << std::endl;
    std::cout << "\t *" << sizeof(fast32) * 8 << std::endl;
    std::cout << "\t *" << sizeof(fast64) * 8 << std::endl;

    std::cout << "\nWhen you give a fast int a small number..." << std::endl;
    std::cout << "\t *" << sizeof(least8) * 8 << std::endl;
    std::cout << "\t *" << sizeof(least16) * 8 << std::endl;
    std::cout << "\t *" << sizeof(least32) * 8 << std::endl;
    std::cout << "\t *" << sizeof(least64) * 8 << std::endl;
}

void decimalTypes()
{
    float decimal4bytes = 1.23;
    double decimal8bytes = 4.56;
    long double decimalAnybytes = 7.89; // Don't use long no set size (8, 12, or 16)
    float zeroDecimal = 1.000;

    std::cout << "\nHere are the sizes of decimal variables..." << std::endl;
    std::cout << "\t* floats: " << sizeof(decimal4bytes) * 8 << std::endl;
    std::cout << "\t* doubles: " << sizeof(decimal8bytes) * 8 << std::endl;
    std::cout << "\t* long doubles: " << sizeof(decimalAnybytes) * 8 << std::endl;

    auto old_flags = std::cout.flags();    // save pre-precision settings
    auto old_prec = std::cout.precision(); // needed to reset flags

    // 0 decimal component won't be printed unless precision is set...
    std::cout << "\nThe number of the day is: " << zeroDecimal << std::endl;
    // Need iomanip to work, need to set fixed for setprecision to work
    std::cout << "Print the hidden decimal: " << std::fixed << std::setprecision(3) << zeroDecimal << std::endl;
    std::cout.flags(old_flags);
    std::cout.precision(old_prec);
    std::cout << "Same as it ever was... " << zeroDecimal << std::endl;
}

void floatRounding(float a, float b)
{
    std::cout << "Absolute Rounding: " << std::endl;
    std::cout << "\tLet's say that we will only allow a .001 difference between 2 values for equality...";
    std::cout << "\n";

    if (abs(a - b) < .001)
    {
        std::cout << "With absolute comparison, they are equal..." << std::endl;
    }
    else
    {
        std::cout << "Absolutely, they are not equal..." << std::endl;
    }

    std::cout << "\nRelative Rounding: " << std::endl;
    std::cout << "\tLet's normalize the difference to be relative, then see if they are equal..." << std::endl;
    std::cout << "\tWe'll do this via a really small epsilon of 0.00001..." << std::endl;
    int difference = abs(a - b);
    int larger = (a > b) ? a : b;

    if (abs(a - b) <= larger * 0.00001)
    {
        std::cout << "With relative comparison, they are equal..." << std::endl;
    }
    else
    {
        std::cout << "Relatively, they are not equal." << std::endl;
    }

    std::cout << "\nJust direct comparison: " << std::endl;

    if (a == b)
    {
        std::cout << "With direct comparison, they are equal..." << std::endl;
    }
    else
    {
        std::cout << "Directly, they are not equal..." << std::endl;
    }
}

void bools()
{
    std::cout << "\nBooleans can only take..." << std::endl;
    std::cout << "\t* true / false keywords" << std::endl;
    std::cout << "\t* 0 / 1" << std::endl;
}

void charStrings()
{
    char firstInitial = 'T';
    char lastInitial = 82; // chars are number indexed in ascii table, not preferred
    // escape sequences https://en.cppreference.com/cpp/language/escape
    std::cout << "\nChars can be given a letter or a number in ascii range: " << firstInitial;
    std::cout << " " << lastInitial << std::endl;

    // strings, can be a char array that ends in \0 (null char) or use string (must import)
    std::string firstName = "Tamara";
    char lastName[5] = "Rice"; // implied null terminated, MAKE SURE IT'S NOT LOST
    // char arrays are also called C-style strings

    std::cout << "My first name is: " << firstName << std::endl;
    std::cout << "My last name is: " << lastName << std::endl;

    int index = 0;

    while (lastName[index] != '\0')
    {
        std::cout << lastName[index++] << " ";
    }
    std::cout << "\n";

    std::cout << "\nString manipulation shorthands (common ones): " << std::endl;
    std::cout << "\tA float: " << 1.23456f << std::endl;

    // Do NOT pass strings by value, pass by reference - string copies are expensive
    // For the same reason, try not to return strings as well.

    std::string_view nameLook = firstName; // basically a name pointer, but can only read not write
    std::cout << nameLook << std::endl;
    firstName = "Mara";
    std::cout << "string view is not updated and will react strangely... " << nameLook << std::endl;
    nameLook = firstName; // fixes weird read
    // Do not return string views!
}

void typeConversion()
{
    // static-cast
    int num = static_cast<int>('a');
    char letter = 'a';
    // c-style
    int example = (int)letter;
}

void bitOperations(int given)
{
    int shift = given;
    std::cout << "\nGiven Value is: " << given << std::endl;
    shift = (given << 1);
    std::cout << "Shift left by 1: " << shift << std::endl;
    shift = (given >> 1);
    std::cout << "Shift right by 1: " << shift << std::endl;
    shift = (given << 1);

    // vice versa will not reverse affects of shift...
    shift = given;
    std::cout << "\nGiven Value is: " << given << std::endl;
    shift = (given >> 1);
    std::cout << "Shift right by 1: " << shift << std::endl;
    shift = (given << 1);
    std::cout << "Shift left by 1: " << shift << std::endl;

    std::cout << "Bitwise not: " << (~given) << std::endl;
    std::cout << "Bitwise and (&), " << given << " & " << shift << ": " << (given & shift) << std::endl;
    std::cout << "Bitwise or (|), " << given << " | " << shift << ": " << (given | shift) << std::endl;
    std::cout << "Bitwise xOR (^), " << given << " ^ " << shift << ": " << (given ^ shift) << std::endl;
}
