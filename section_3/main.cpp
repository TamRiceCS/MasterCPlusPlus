#include <iostream>
#include "functions.h"
#include "pointersNref.h"
#include "classEnumStruct.h"

bool oppositeDay(bool fact = false); // declare default values in forward declaration, can't do both

int main()
{
    std::cout << "\nWelcome to section 3, notes put into practice." << std::endl;

    // Allowed to overload via type and number of parameters, not return type or default values
    std::cout << "\nFunction overloading:" << std::endl;
    std::cout << "Add 1 + 2: \t" << add(1, 2) << std::endl;
    std::cout << "Add 1 + 2 + 3: \t" << add(1, 2, 3) << std::endl;
    std::cout << "Add \"Apple\" + \"Sauce\": \t" << add("Apple", "Sauce") << std::endl;
    std::cout << "Add \'a\' + \'b\': \t" << add('a', 'b') << std::endl;
    std::cout << "\n";

    std::cout << "\nDefault Arguments:" << std::endl;
    echo();
    echo("Meow");
    repeat("Woof", 2);
    repeat("Woof");
    std::cout << "\tHere are the facts: " << oppositeDay() << " Wait no actually: ";
    std::cout << oppositeDay(true) << std::endl;
    std::cout << "\tDifferent ways to multiply:" << std::endl;
    std::cout << "\t\tone->" << multiply();
    // Will fill default parameters left to right
    std::cout << "\t one->" << multiply(3) << "\t two->" << multiply(2, 3);
    std::cout << "\t three->" << multiply(2, 3, 4) << std::endl;
    std::cout << "\n";

    report<char>('a');
    report<int>(1);
    report<double>(1.23); // try this with type float and watch it crash
    // type will be deduced
    report<>(true);
    report<>((double)1.23); // can also c-style cast and atatic-cast (no example included)

    report<int, bool>(1, false);
    report<int, int>(1, 2);
    std::cout << "non-type template parameter function: ";
    yolo<'t'>();
    std::cout << "constexpr func: " << divide(20, 5) << std::endl;

    std::cout
        << "\n";

    int tam = 25;
    int you = 30;
    int &dopple = tam; // now the same object as tam
    const int days = 115;
    const int &sameDays = days;
    int *tamPtr = &tam; // points to the tam object
    const int *unchangeTam = tamPtr;

    references(tam, you);
    std::cout << "After the function decade I am: " << tam << " and you are: " << you << std::endl;
    dopple -= 10;
    std::cout << "Let's use a doppleganger to deage me: " << tam << std::endl;

    std::cout << "\n";
    pointers(tamPtr, you);
    std::cout << "After the function century I am: " << tam << " (" << *tamPtr << ") and you are: ";
    std::cout << you << std::endl;
    (*tamPtr) -= 10;
    std::cout << "Let's use the ptr to deage me again: " << tam << std::endl;

    std::cout << "\n";
    SolarSystem::Planets favPlanet = SolarSystem::Planets::Earth;
    SailorMoon::SailorScouts favScout = SailorMoon::SailorScouts::Mercury;
    enumPrefs(favPlanet, favScout);
    Basic person = Basic{};
    person.haveBDay();
    person.introduce();
    Basic fren{"Adam", "Beigel", 26};
    fren.haveBDay();
    fren.introduce();
    Basic *refFren = &fren;
    refFren->LName = "B";
    refFren->introduce();
    QuadData<int> nums{1, 2, 3, 4};
    QuadData<char> letters{'a', 'b', 'c', 'd'};
    QuadData<int> yikes{};
    nums.output();
    yikes.output();

    std::cout
        << "\n";

    return 0;
}

bool oppositeDay(bool fact)
{
    return !fact;
}