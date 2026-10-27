#include <iostream>
#include <vector>
#include <array>

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

void makeArray()
{
    std::cout << "Make an array, ih has a fixed size... std::array<type, size> name{}" << std::endl;
    std::cout << "\tIf a list is not given, members are zero-init..." << std::endl;
    std::cout << "\t";
    std::array<int, 5> name{};
    for (int elem : name)
    {
        std::cout << elem << " ";
    }

    std::cout << "\nAn array can be initialized to a list... std::array<type, size> name{elem1, ..., elemN}\n";
    std::array<const int, 5> name2 = {1, 2, 3, 4, 5};
    std::cout << "Arrays can be const AND their elements can be const as well!" << std::endl;
}

void makeCArray()
{
    std::cout << "A C-style array is initialized like so... type name[size]" << std::endl;
    std::cout << "A C-style array can be initialized to a list... type name = {elem1, ..., elemN}" << std::endl;
    int name[10]; // size can not be 0
    int name2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Get the size of an array with sizeof(arr)/sizeof(*arr)" << std::endl;
    std::cout << "\t" << sizeof(name) / sizeof(*name) << std::endl;
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

void CArrayAccess()
{
    int name[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    name[0] = -1;
    std::cout << "Only one way to access indexes, with operator[]" << std::endl;
    // name = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // this is illegal, assignment not allowed
}

void arrayAccess()
{
    std::cout << "\nThere are 3 main ways to access elements in an array:" << std::endl;
    std::cout << "\t1. operator[], not bounds checked" << std::endl;
    std::cout << "\t2. .at() member function, bounds checked at runtime" << std::endl;
    std::cout << "\t3. .get() member function, bounds checked at compiletime" << std::endl;
}

// okay to return by value, allows move semantics (deep copy)
void vectorPassing(std::vector<int> expensive, std::vector<int> &cheap, const std::vector<int> &cheapConst)
{
    std::cout << "\nBest practice is to pass by reference. Copies of vectors, like strings, are expensive.";
    std::cout << "\n";
}

void CArrayPassing(int secretPtr[])
{
    std::cout << "\nAll C-style arrays decay to just be a pointer when it is passed" << std::endl;
    std::cout << "Lots of draw backs. \n\tNo size info \n\tPointer arithmetic" << std::endl;
}

void cString()
{
    char whoAmI[] = {"Tamara\0"}; // null terminated
    // cstring header gives access to neat functions c:
    // careful cstring header functions won't work on decayed cstrings
}

void multiDimensional()
{
    int arr2D[2][2] = {{1, 1}, {2, 2}};
    int arr3D[3][2][1] = {{{1}, {2}}, {{1}, {2}}, {{1}, {2}}};

    // needs double curly braces for every subarray.
    std::array<int, 5> stdArray1D = {{1, 2, 3, 4, 5}};    // inner most layer can ommit double braces
    std::array<int, 5> otherStdArray1D = {1, 2, 3, 4, 5}; // this also works
    std::array<std::array<int, 5>, 2> stdArray2D = {{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}};
    // I wish I was kidding that this is the form of a 3d Array
    std::array<std::array<std::array<int, 1>, 2>, 3> stdArray3D = {{{{{1}, {2}}}, {{{3}, {4}}}, {{{5}, {6}}}}};

    std::vector<std::vector<int>> vector2D = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // Hmmm a certain 3D container looks easiest... hmmmm
    std::vector<std::vector<std::vector<int>>> vector3D = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}, {{9, 10}}};
}
