#include <iostream>
#include <vector>

// Avoid vector<bool>, strange behavior because each element is a bitfield... a proxy object
// The proxy object will NOT allow direct access or manipulation...
// Messes w/ algs that work on every other type

void makeVector()
{
    std::cout << "Make an empty vector... vector<type> name" << std::endl;
    std::vector<int> name;
    std::cout << "Make an empty list initialized vector... vector<type> name{}" << std::endl;
    std::vector<int> name2 = {};
    std::cout << "Make a vector w/ 0 initialized slots of num size... vector<type>name(size)" << std::endl;
    std::vector<int> name3(10);
    std::cout << "Make a vector from a given list... vector<type>name = {elem1, ..., elemN}" << std::endl;
    std::vector<int> name4 = {1, 2, 3, 4};
    std::cout << "Vectors can be const, their elements cannot.." << std::endl;
    std::cout << "\tconst vector<type> name; // this is legal" << std::endl;
    std::cout << "\tvector<const type> name; // this is illegal" << std::endl;
}

void vectorAccess()
{
    std::vector<int> name = {1, 2, 3, 4};
    std::cout << "\nCan access elements in a vector with operator[], vectorName[index] - 0 indexed." << std::endl;

    for (int i = 0; i < name.size(); i++)
    {
        if (i == name.size() - 1)
        {
            std::cout << i << std::endl;
            continue;
        }
        std::cout << i << " " << std::endl;
    }

    std::cout << "operator[] is not bounds checked, oob can cause strange behavior" << std::endl;
    std::cout << name[9] << std::endl;

    std::cout << "\nThe .at() member function of vector is bounds checked." << std::endl;
    name.at(3);
    // name.at(9); // this will throw an error

    std::cout << "The native index type for a vector is size_t, it is unsigned." << std::endl;
    // for each loop, iters through vector w/ no knowledge of index
    for (const auto &element : name) // consider making element a reference if it is expensive, copies are made
    {
        std::cout << element << " ";
    }
}

// okay to return by value, allows move semantics (deep copy)
void vectorPassing(std::vector<int> expensive, std::vector<int> &cheap, const std::vector<int> &cheapConst)
{
    std::cout << "\nBest practice is to pass by reference. Copies of vectors, like strings, are expensive.";
    std::cout << "\n";
}