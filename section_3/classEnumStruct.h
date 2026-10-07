#include <string>
#pragma once
// If the enums were not defined in namespaces, there woild be collisions from similar names

namespace SailorMoon
{

    enum SailorScouts
    {
        Mercury = 1,
        Venus = 4,
        Mars = 2,
        Jupiter = 3,
        Saturn = 7,
        Uranus = 8,
        Neptune = 6,
        Pluto = 5,
        Moon = 0,
        TuxedoMask = 9,
        Earth = 9,
    };
}

/*
enum class SailorScout {
...
};
// would also prevent collisions: must be in a namespace or in an enum class
*/

namespace SolarSystem
{
    // secretly 0 indexed
    enum Planets
    {
        Mercury,
        Venus,
        Earth,
        Mars,
        Jupiter,
        Saturn,
        Uranus,
        Neptune,
    };
}

// structs can basically do anything a class can do, but they are the preferred choice for aggregates.
struct Basic
{
    std::string FName = "Tamara";
    std::string LName = "Rice";
    int age = 25;

    void haveBDay()
    {
        std::cout << "Happy Birthday, " << FName << "is now " << ++age << std::endl;
    }
    void introduce()
    {
        std::cout << "Hello, I am " << FName << " " << LName << " pleasure to meet you" << std::endl;
    }
};

void enumPrefs(SolarSystem::Planets favPlanet, SailorMoon::SailorScouts favScout);

template <typename Data>
struct QuadData
{
    Data piece1;
    Data piece2;
    Data piece3;
    Data piece4;

    void output()
    {
        std::cout << "The data provided is: " << piece1 << " " << piece2;
        std::cout << " " << piece3 << " " << piece4 << std::endl;
    }
};

class SomeProj
{
public:
    static int seen;           // does not belong to class is global, just in its domain
    void aboutProject() const; // can't edit data members
    friend void lastEditChange(std::string update);
    friend void updateLink(std::string update);
    SomeProj() = default;                // explicitly get an empty constructor
    SomeProj(float pVer) : version{pVer} // can quickly define member data here, no this ptr
    {
    }
    SomeProj(int version, std::string pName, std::string author, std::string create, std::string link = "None")
    {
        this->version = version; // use this keyword to unshadow
        projName = pName;
        this->author = author;
        lastEditDate = create;
        associatedNotes = link;
    }

private: // implicitly private if public is not declared
    float version = 0.0;
    std::string projName = "Relearn C++ deeply";
    std::string author = "Tamara Rice";
    std::string lastEditDate = "10/6/26";
    std::string associatedNotes = "Google Docs Link";
};
