#include <iostream>
// rvalues are values. (often literals like 5, 'a', "Apple") [right side of copy assignment]
// lvalues evaluate to variables / functions [left side of copy assignment]

void references(int &myAge, int urAge)
{ // myAge is a reference
    std::cout << "My base age: " << myAge << std::endl;
    std::cout << "Your base age: " << urAge << std::endl;

    std::cout << "Wow a decade passed in the function..." << std::endl;
    myAge += 10;
    urAge += 10;
}

// reference - I am the object just by anothername (like a nickname!)
// pointer - I'm not the object, but I can contact them to get stuff done - I know where they live
void pointers(int *myAgePtr, int urAge)
{
    std::cout << "Pointing to my base age: " << *myAgePtr << std::endl;
    std::cout << "Just your age again: " << urAge << std::endl;

    std::cout << "A decade passed before, how about a century!" << std::endl;
    (*myAgePtr) += 10;
    urAge += 10;
}

void confusion(int &myAgeRef, int *myAgePtr, int myAge, const int constMyAge)
{
    auto someAge = myAgeRef;       // the reference is dropped
    auto &anotherMyAge = myAgeRef; // and now they point to the same thing again!
    // auto will not drop a pointer

    const int *somePtr = &constMyAge;               // points to a const addy, somePtr is not const
    const int *const unchangeSomePtr = &constMyAge; // points to a const addy, uncgangeSomePtr is also const

    auto example1 = somePtr;        // pointing to a const, not const itself
    auto *example2 = somePtr;       // same as above
    auto const example3 = somePtr;  // pointing to a const, is const itself
    const auto example4 = somePtr;  // same as above
    auto *const example5 = somePtr; // pointing to a const, is const itself
    const auto *example6 = somePtr; // pointing to a const, is not const itself
    // const auto const example7 = somePtr; // tries to double const the variable
}