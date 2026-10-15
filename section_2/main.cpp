#include <iostream>
#include <string>
#include "fundamental_types.h"
#include "conditionals.h"

// Be careful to not use non-const / non-constexp global vars, helps prevent unexpected behavior
// const / constexpr global variables are static by default
constexpr int running = 1; // Value is known at compilation, faster
constexpr int alwaysKnown();
int g_example; // Can init this here because extern use in header

auto genericFunc() // Function parameters can't be auto, can't be forward defined
{                  // All return type must be the same in the body
    return true;
}

auto trailingFunc() -> int
{ // trailing type, useful when the return type is nasty so name isn't obscured
    return true;
}

// Useful to prevent name collisions (like a lastname), must be global
// Namespaces can be unnamed (unanonymous), useful to make global variables static (unusuable outside file)
namespace FunctionSpace // Start w/ a capital letter
{
    const float g_gravity = 9.8; // Gravity does not change
    void repeatNTimes(std::string base, int times)
    {
        if (times == 0)
            return;
        for (int i = 0; i < times - 1; i++)
        {
            std::cout << base << " ";
        }
        std::cout << base << std::endl;
    }

    namespace childSpace // Nested namespaces are allowed
    {
        void giggle()
        {
            std::cout << "Hehe ";
        }
    }

}

int main()
{
    std::cout << "\nWelcome to section 2, notes put into practice." << std::endl;

    numericalTypes();
    fixedInts();
    fastleastInts();
    decimalTypes();
    bools();
    charStrings();

    std::cout << "\nThis variable will always be running, it is a const and can't change." << std::endl;
    std::cout << "This function generates has no variables / parameters that must be resolved at runtime.";
    std::cout << "\n";

    std::cout << "\n";
    howIf(110);
    howIf(25);
    howIf(38);
    howIf(43);
    howIf(0);
    howIf(-510);
    howIf(-65);
    howIf(-78);
    howIf(-3);

    std::cout << "\n";
    floatRounding(2.896, 2.89601);

    bitOperations(123);

    { // Unspecific code blocks are allowed
        // type exists here
        int type = 1;
        std::cout << "\nCode blocks don't need to be named via a function or keyword." << std::endl;
        {
            // also exists here
            std::cout << "You can nest 'em like anyother block, try to keep nested blocks > 3" << std::endl;
            int type = 3; // This local variable will shadow the outside variable
            std::cout << "The most local variable w/ the same name will shadow all others, be careful: ";
            std::cout << type << std::endl;
        }
        // type exists here too
    }

    // type does not exist here, out of scope

    std::cout << "\nUsing a namespace function: ";
    // Need to use resolution operator to define what scope to look in
    FunctionSpace::repeatNTimes("Hello", 3);
    FunctionSpace::childSpace::giggle();
    namespace newName = FunctionSpace; // You can give a namespace an alias
    newName::childSpace::giggle();
    std::cout << "\nGlobal Variables in a namespace help prevent name collisions, ";
    std::cout << "gravity is a great candidate for this: " << newName::g_gravity;

    g_example = 1234; // Give extern global var a value here, can't do it in global

    switchItUp(1);
    switchItUp(3);
    switchItUp(20);

    whileCounting(5);
    whileCounting(-3);

    whatFor(0);
    whatFor(5);

    breakContinue();

    halts();
    random();

    typeConversions();

    std::cout
        << "\n";

    return 0;
}

constexpr int alwaysKnown()
{
    int seed = 123456789;
    return seed;
}