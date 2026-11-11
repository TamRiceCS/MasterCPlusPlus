#include <iostream>
#include <vector>
#include <functional>
#include "functions.h"
#include "overloading.h"

using compareShrt = bool (*)(int, int);

// Lambdas!
// or just use auto, or a regular function pointer
std::function quartic{[](int a)
                      { return a * a * a * a; }};

int main(int argc, char *argv[]) // can also use int argc, char** argv
{

    std::cout << "\nWelcome to section 5, notes put into practice." << std::endl;

    std::cout << "\nArguments given by command line: " << std::endl;
    while (argc--)
    {
        std::cout << argv[argc] << " ";
    }

    std::cout << "\nNotice that command line arguments are stored in reverse order. " << std::endl;
    std::cout << "Notice that the executable is listed AND the given -o alias is not used." << std::endl;

    // template example of a function ptr, don't make funcPtrs on void
    bool (*comparePtr)(int, int) = &compare<int>;
    bool (*const comparePtrConst)(int, int) = &compare<int>; // make a funcptr const
    compareShrt simplePtr = &compare<int>;                   // use an alias to hide nasty type
    auto deduceType = &compare<double>;

    std::cout << "Is " << 5 << " greater than " << 10 << "?" << std::endl;
    // implicit then explicit
    std::cout << "\t" << comparePtr(5, 10) << " can also call " << (*comparePtr)(5, 10) << std::endl;

    std::vector<int> ones = {1, 1, 1, 1, 1, 1};
    std::vector<int> counting = {1, 2, 3, 4, 5};

    bool (*equalPtr)(int, int) = &equal<int>;
    std::cout << "\nAre we all equal in ones: " << allEqual(ones, equalPtr) << std::endl;
    std::cout << "Are we all equal in counting: " << allEqual(counting, equalPtr) << std::endl;

    std::cout << "\nRecursive 0-100: " << std::endl;
    recursive(0, 100);
    std::cout << "\nIterative 0-100: " << std::endl;
    iterative(0, 100);

    std::cout << "\n";
    elipses(5, 1, 2, 3, 4, 5);

    integerPower(counting, [](int a)
                 { return a * a * a; });
    integerPower(counting, quartic);

    std::cout << "\n";
    lambdaInHere(20);
    lambdaInHere(30);

    Fraction myFraction(1, 2, true);
    std::cout << "\nLet's overload a bunch of operators in a class!" << std::endl;
    std::cout << "We'll be using this simple fraction... " << myFraction << std::endl;

    Fraction myInputFraction(3, 4);
    std::cout << "Enter an integer numerator and denominator seperated by a newline:" << std::endl;
    // std::cin >> myInputFraction;
    std::cout << "Fraction recieved is: " << myInputFraction << std::endl;

    Fraction addEm = myFraction + myInputFraction;
    std::cout << "Overloaded adding two fractions: " << addEm << std::endl;

    if (myInputFraction == myFraction)
    {
        std::cout << "The demo fraction and user fraction ARE equal." << std::endl;
    }
    else
    {
        std::cout << "The demo fraction and user fraction ARE NOT equal." << std::endl;
    }

    ++addEm;
    std::cout << "++Fraction overloaded: " << addEm++ << std::endl;
    std::cout << "Fraction++ overloaded:" << addEm << std::endl;

    std::cout << "Now has a defined way to convert to double: " << addEm + (double)1.24 << std::endl;

    return 0;
}