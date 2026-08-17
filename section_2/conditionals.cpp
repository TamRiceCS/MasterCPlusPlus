#include <iostream>

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
