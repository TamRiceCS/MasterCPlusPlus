#include <iostream>
#include <string>
#include <cstdarg>

// All functions have a recursive version and an iterative version
void recursive(int start, int end)
{
    if (start == end)
    {
        std::cout << start << std::endl;
        return; // return is imporatant to prevent infinite loop
    }
    if (start % 25 == 0)
    {
        std::cout << "\n";
    }
    std::cout << start << " ";
    recursive(start + 1, end);
}

void iterative(int start, int end)
{
    for (; start < end; start++)
    {
        if (start % 25 == 0)
        {
            std::cout << "\n";
        }
        std::cout << start << " ";
    }
}

// Don't use these no type checking, no way to confirm count correct
void elipses(int count, ...)
{
    va_list elipseParams;
    va_start(elipseParams, count);
    while (count--)
    {
        std::cout << va_arg(elipseParams, int) << " ";
    }
    va_end(elipseParams);
}
