#include <iostream>
#include <string>

void echo(std::string base, int times)
{
    for (int i = 0; i < times.size(); i++)
    {
        if (i == times - 1)
        {
            std::cout << base << std::endl;
        }
        std::cout << base << " ";
    }
}