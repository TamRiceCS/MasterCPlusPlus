#include <vector>
#include <array>

void makeVector();
void vectorAccess();
void vectorPassing(std::vector<int> expensive, std::vector<int> &cheap, const std::vector<int> &cheapConst);
void makeArray();
void arrayAccess();
template <typename T, std::size_t N>
void arrayPassing(std::array<int, 5> &copy, std::array<T, N> anything, std::array<int, N> anySize)
{
    std::cout << "\nPassing via std::array<type, size> name, must be exact type size match!" << std::endl;
    std::cout << "Use a template to accept any type and size of array." << std::endl;
    std::cout << "Best practice is to return via a reference parameter." << std::endl;
    // Move semantics not allowed, copy will be made. :c
}
void makeCArray();
void CArrayAccess();
void CArrayPassing(int secretPtr[]);
void cString();
void multiDimensional();