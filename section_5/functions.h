
#include <string>

void echo(std::string base, int times);

template <typename T>
bool compare(T item1, T item2)
{
    return item1 > item2;
}