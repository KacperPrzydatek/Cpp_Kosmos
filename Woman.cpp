#include "Woman.h"


Woman::Woman(float mass, float height, std::string name, std::string currentPlace, std::string currentPlanet, std::string currentSystem)
{
	_mass = mass;
	_height = height;
	_name = name;
	_currentPlace = currentPlace;
	_currentPlanet = currentPlanet;
	_currentSystem = currentSystem;
	_gender = "woman";
#if _DEBUG
	std::cout << "Konstrukcja obiektu typu Person<M>" << std::endl;
#endif
};
Woman::~Woman()
{
#if _DEBUG
	std::cout << "Destrukcja obiektu typu Person<M>" << std::endl;
#endif
}

std::ostream& operator<<(std::ostream& os, const Woman& person)
{
	return os << "Gender: " << person._gender << std::endl << "Name: " << person._name << std::endl << "Mass: " << person._mass << std::endl << "Height: " << person._height << std::endl << std::endl;
}

/*
Woman::Woman(const Woman& pers)
	:Woman(pers._mass, pers._height, pers._name, pers._currentPlace, pers._currentPlanet, pers._currentSystem)
{};
*/
void Woman::CheckGender()
{
	std::cout << "Im Womaaaaaan" << std::endl << "I said it without my mark!";
}