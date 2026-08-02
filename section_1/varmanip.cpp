// Variable Manipulation
#include <iostream>

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
}