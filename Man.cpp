#include "Man.h"


Man::Man(float mass, float height, std::string name, std::string currentPlace, std::string currentPlanet, std::string currentSystem)
	:Person::Person(mass,height,name, currentPlace, currentPlanet, currentSystem)
{
	_gender = "man";
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

/*
Man::Man(const Man& pers)
	:Man(pers.Person::_mass, pers._height, pers._name, pers._currentPlace, pers._currentPlanet, pers._currentSystem)
{
};*/

void Man::ChangeNumberOfHands(int newNumber)
{
	_numberOfHands = newNumber;
}

void Man::CheckGender()
{
	std::cout << "Im Maaaan" << std::endl << "I said it without my mark!";
}