// Variable Manipulation
#include <iostream>
#include <string>

void varInit()
{
    // Every init given a value can use the keyword const
    int defaultInit; // This will output something random, not defined
    int copyInit = 1;
    int directInit(2);     // Don't like, too function like
    int directListInit{3}; // Don't like, curly brackets not a code block
    int chain1 = 1, chain2 = 2, chain3 = 3;

    std::cout << "\nThis function has initialized a bunch of variables. They are..." << std::endl;
    std::cout << "Default: " << defaultInit << ", Copy Initialize: " << copyInit;
    std::cout << ", Direct List Initialize: " << directListInit;
    std::cout << ", Chain values: " << chain1 << " " << chain2 << " " << chain3 << std::endl;

    // Do NOT name a variable a keyword: https://cppreference.com/cpp/keyword
}

void varMath()
{
    int num1 = 10;
    int num2 = 22;

    std::cout << "\nThis function demos math operations: " << std::endl;

    std::cout << "Add " << num1 << " and " << num2 << ": " << num1 + num2 << std::endl;
    std::cout << "Subtract " << num2 << " and " << num1 << ": " << num2 - num1 << std::endl;
    std::cout << "Multiply " << num1 << " and " << num2 << ": " << num1 * num2 << std::endl;
    std::cout << "Divide " << num2 << " and " << num1 << ": " << num2 / num1 << std::endl;
    // Notice that division of an int drops the decimal, more details on this later
    std::cout << "Division remainder of " << num2 << " and " << num1 << ": " << num2 % num1 << std::endl;

    // Above are some basic math operations on variables, there are more such as binary math.
    // Some not included are == (equality), << (insertion), and >> (extraction) - these are more relevant elsewhere

    // Unary operator is just the negative sign (-)
    // Binary operators act on two variables like the math operations above
    // Ternary operator is only seen in a conditional that will be shown later
    // Nullary operator is only throw this will explain w/ try-catch
}

// More will be seen later, this is just basic
void basicIO()
{
    std::string userInput = ""; // Strings will be covered later

    // Needs import of iostream
    std::cout << "\nThis will output right away, endl forces a flush of output queue." << std::endl;
    std::cout << "This will wait to output until output queue full or a flush event occurs." << std::endl;
    std::cout << "Another way to force output.\n"
              << std::flush; // Explicitly call to flush queue

    // std::cout << "Type anything for a string to hold: ";
    // std::cin >> userInput;

    // std::cout << "\nYou entered: " << userInput << std::endl;

    // Here are escape sequences https://en.cppreference.com/cpp/language/escape
    // Common ones I use are \n, \t, \', and \"
}

// Functions Explained, more on functions later too only basics here.
// Tells CPU to pause current function (like main) to run other stuff (emptyFunction)
// DO NOT DEFINE FUNCTIONS INSIDE OF FUNCTIONS
void emptyFunction() // Function header, type -> name -> (parameters)
{
    // Everything in curly braces is the function body
    std::cout << "\nThis is an empty function that doesn't do much of anything." << std::endl;
    return; // Optional, but useful for an immediate exit
}

int doubleNum(int num)
{
    std::cout << "Double the number " << num << ": " << num * 2 << std::endl;
    return num * 2; // Return type must match, defined type above. Can only return one obj.
    // When a type is defined, MUST return the type
}

int multiplyThree(int num1, int num2, int num3)
{
    std::cout << num1 << " * " << num2 << " * " << num3 << ": " << num1 * num2 * num3 << std::endl;
    return num1 * num2 * num3;
}

// All default values must be on the right
int defaultMultiply(int num1, int num2 = 2)
{
    std::cout << num1 << " * " << num2 << ": " << num1 * num2 << std::endl;
    return num1 * num2;
}

// Can accept an ignored param w/o a name, useful to not change prior calls
// Having a non-blank operator now means every param must have a value
void ignoreParam(int num1, int)
{
    std::cout << "I only care about " << num1 << std::endl;
}

// Don't worry about this much until later ptr section
void passBy(int value, int *reference)
{
    std::cout << "This is just a copy and won't change the original: " << value << std::endl;
    std::cout << "This will change the original it points to the memory: " << *reference << std::endl;
}