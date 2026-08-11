#include <iostream>
#include <cstdint>

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

    std::cout << "Here are the sizes of decimal variables..." << std::endl;
    std::cout << "\t* floats: " << sizeof(decimal4bytes) * 8 << std::endl;
    std::cout << "\t* doubles: " << sizeof(decimal8bytes) * 8 << std::endl;
    std::cout << "\t* long doubles: " << sizeof(decimalAnybytes) * 8 << std::endl;
}