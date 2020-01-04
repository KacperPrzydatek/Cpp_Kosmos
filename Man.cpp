#include "Man.h"

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	return os << "Name: " << person._name << std::endl << "Mass: " << person._mass << std::endl << "Height: " << person._height << std::endl << std::endl;
}

Man::Man(float mass, float height, std::string name, std::string currentPlace, std::string currentPlanet, std::string currentSystem)
	:_mass(mass), _height(height), _name(name), _currentPlace(currentPlace), _currentPlanet(currentPlanet), _currentSystem(currentSystem), _ifMan(1)
{
#if _DEBUG
	std::cout << "Konstrukcja obiektu typu Person<M>" << std::endl;
#endif
};
Man::~Man()
{
#if _DEBUG
	std::cout << "Destrukcja obiektu typu Person<M>" << std::endl;
#endif
}


Man::Man(const Man& pers)
	:Man(pers._mass, pers._height, pers._name, pers._currentPlace, pers._currentPlanet, pers._currentSystem)
{};