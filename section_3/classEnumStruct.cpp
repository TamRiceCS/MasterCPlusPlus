#include <iostream>
#include "ClassEnumStruct.h"

constexpr std::string_view returnPlanet(SolarSystem::Planets planet)
{
    switch (planet)
    {
    case SolarSystem::Planets::Mercury:
        return "Mercury";
    case SolarSystem::Planets::Venus:
        return "Venus";
    case SolarSystem::Planets::Earth:
        return "Earth";
    case SolarSystem::Planets::Mars:
        return "Mars";
    case SolarSystem::Planets::Jupiter:
        return "Jupiter";
    case SolarSystem::Planets::Saturn:
        return "Saturn";
    case SolarSystem::Planets::Uranus:
        return "Uranus";
    case SolarSystem::Planets::Neptune:
        return "Neptune";
    default:
        return "???";
    }
}
constexpr std::string_view returnScout(SailorMoon::SailorScouts planet)
{
    switch (planet)
    {
    case SailorMoon::SailorScouts::Mercury:
        return "Sailor Mercury";
    case SailorMoon::SailorScouts::Venus:
        return "Sailor Venus";
    case SailorMoon::SailorScouts::TuxedoMask:
        return "Tuxedo Mask";
    case SailorMoon::SailorScouts::Mars:
        return "Sailor Mars";
    case SailorMoon::SailorScouts::Jupiter:
        return "Sailor Jupiter";
    case SailorMoon::SailorScouts::Saturn:
        return "Sailor Saturn";
    case SailorMoon::SailorScouts::Uranus:
        return "Sailor Uranus";
    case SailorMoon::SailorScouts::Neptune:
        return "Sailor Neptune";
    default:
        return "???";
    }
}

std::ostream &operator<<(std::ostream &out, SolarSystem::Planets base)
{
    out << returnPlanet(base);
    return out;
}
std::ostream &operator<<(std::ostream &out, SailorMoon::SailorScouts base)
{
    out << returnScout(base);
    return out;
}
void enumPrefs(SolarSystem::Planets favPlanet, SailorMoon::SailorScouts favScout)
{
    std::cout << "Given Fav Planet: " << favPlanet << " and Fav Sailor Scout. " << favScout << std::endl;
}

void SomeProj::aboutProject() const // cant edit
{
    std::cout << "\n"
              << projName << " by " << author << std::endl;
    std::cout << "Last Edited On: " << lastEditDate << std::endl;
    std::cout << "Based off of notes from learncpp.com: " << associatedNotes << std::endl;
}