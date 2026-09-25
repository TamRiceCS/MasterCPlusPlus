#include <iostream>
#include <string>

// function overloading
int add(int a, int b)
{
    return a + b;
}
int add(int a, int b, int c)
{
    return a + b + c;
}
std::string add(std::string a, std::string b)
{
    a += b;
    return a;
}
std::string add(char a, char b)
{
    std::string returnable = "";
    returnable += a;
    returnable += b;
    return returnable;
}
float add(float a, float b) = delete;

void echo(std::string phrase = "echo")
{
    std::cout << phrase << std::endl;
}

void repeat(std::string phrase, int number = 1)
{
    for (int i = 0; i < number - 1; i++)
    {
        std::cout << phrase << " ";
    }
    if (number != 0)
    {
        std::cout << phrase << std::endl;
    }
}
