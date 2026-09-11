#include <iostream>
#include <random>

void howIf(int round)
{
    int negativeFlag = 1;

    std::string fact = (round < 0) ? "negative" : "positive / zero";

    std::cout << "Rounding the ones place of " << fact << ": " << round;

    if (round < 0)
    {
        round *= -1; // make positive to see how must be rounded
        negativeFlag = -1;
    }

    if (round % 10 == 0)
    {
        std::cout << "\t" << round * negativeFlag << " does not need to be rounded" << std::endl;
    }
    else if ((round % 10) - 5 >= 0) // Must have an if before, unlimited else if
    {
        std::cout << "\t" << (round + (10 - (round % 10))) * negativeFlag << " round away from 0." << std::endl;
    }
    else
    { // Must have an if / else if before
        std::cout << "\t" << (round - (round % 10)) * negativeFlag << " round toward 0." << std::endl;
    }

    // All conditional operators >, <, >=, <=, and ==
    // Logical Operators !(not), &&(and), ||(or)
}

void switchItUp(int button)
{
    std::cout << "\nExample of fall through: " << std::endl;
    switch (button)
    {
    case 1:
        std::cout << "Boop ";

    case 2:
        std::cout << "Beep ";
    case 3:
        std::cout << "Bop ";
    case 4:
        std::cout << "Meep ";
    case 5:
        std::cout << "Moop ";
    case 6:
        std::cout << "Mop ";
    default:
    {
        std::cout << "I'm a robot..." << std::endl;
        break;
    }
    }

    std::cout << "Example w/o fall through" << std::endl;
    switch (button)
    {
    case 1:
    {
        std::cout << "One has a bun" << std::endl;
        break;
    }
    case 2:
    {
        std::cout << "Two says who?" << std::endl;
        break;
    }
    case 3:
    {
        std::cout << "Three climbed a tree" << std::endl;
        break;
    }
    case 4:
    {
        std::cout << "Four thinks you're a bore" << std::endl;
        break;
    }
    }
}

void whileCounting(int number)
{
    int countDown = number;
    std::cout << "\nCount down to 0..." << std::endl;

    std::cout << "\tdo-while: ";
    do
    {
        std::cout << countDown-- << " ";
    } while (countDown > 0);

    std::cout << "\n\twhile: ";
    countDown = number;
    while (countDown > 0)
    {
        std::cout << countDown-- << " ";
    }

    std::cout << "\n";
}

void whatFor(int number)
{
    std::cout << "\nCount down up to 10..." << std::endl;

    for (int i = number; i <= 10; i++)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    // technically no part if the for loop is mandatory
    for (int i = number;;)
    {
        std::cout << i << " ";
        i++;
        if (i > 10)
        {
            break;
        }
    }

    for (;;)
    {
        std::cout << "\nYup even this is legal" << std::endl;
        return;
    }
}

void breakContinue()
{
    while (true)
    {
        std::cout << "\nThis can be an infinite loop" << std::endl;
        break; // exits the current loop, in this case a while
    }

    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            continue; // skip all code and move on to the next iteration
        }
        std::cout << i << " ";
    }
    std::cout << "\n";
}

void haltHelper()
{
    std::cout << "Doing some clean-up" << std::endl;
}

void halts()
{
    // Calling halts are bad practice, error handle instead.

    std::cout << "This will output" << std::endl;

    // Exit will call built-in clean-up functions
    // std::exit(EXIT_SUCCESS);
    // std::exit(EXIT_FAILURE);
    // atexit(haltHelper); // will exit normally but now also call clean-up at end
    // std::abort(); // Call when issue w/ continuing code, can not be ignoredd
    // std::terminate(); // An exception is not handled, this will complain no exception is present

    std::cout << "Nothing will output" << std::endl;
}

void random() // Can be interesting to investigate more w/ advanced statistics
{
    std::mt19937 mt{std::random_device{}()};  // get a random seed from OS random device
    std::uniform_int_distribution die6{1, 6}; // uses a stat distribution where every # has an equal chance
    std::cout << "\nRandomness" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << "\nNo range random: " << mt() << " ";
        std::cout << "Random w/ range: " << die6(mt) << " ";
        std::cout << "Random w/ range via %: " << mt() % 6;
    }
}