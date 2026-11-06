#include <vector>

template <typename T>
bool compare(T item1, T item2)
{
    return item1 > item2;
}

template <typename T>
bool equal(T item1, T item2)
{
    return item1 == item2;
}

template <typename T>
bool allEqual(std::vector<T> list, bool (*comparePtr)(T, T))
{
    for (int i = 0; i < list.size() - 2; i++)
    {
        if (!comparePtr(list[i], list[i + 1]))
        {
            return false;
        }
    }
    return true;
}

template <typename T>
// Many ways to pass a lambda
void integerPower(std::vector<T> list, auto operation)
{
    std::cout << "Feed me Lambdas: " << std::endl;
    for (auto elem : list)
    {
        std::cout << operation(elem) << " ";
    }
}

void lambdaInHere(int start)
{
    std::cout
        << "\nGiven value before lambda: " << start << std::endl;
    // start is not the original object but a copy in the lambda
    // mutable keyword allows capture clause to be changed, otherwise it is const
    std::function go{[start]() mutable
                     {
                         while (start < 100)
                         {
                             if (start % 25 == 0)
                             {
                                 std::cout << "\n";
                             }
                             std::cout << start++ << " ";
                         }
                         std::cout << "\tStart is " << start << " so we're done!" << std::endl;
                     }};

    go();

    std::cout
        << "Given value after lambda: " << start << std::endl;
}

void recursive(int start, int end);
void iterative(int start, int end);
void elipses(int count, ...);