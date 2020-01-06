#include "Person.h"

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	return os <<"Gender: "<<person._gender<< "Name: " << person._name <<std::endl<< "Mass: " << person._mass << std::endl << "Height: " << person._height << std::endl <<std::endl;
}

Person::Person(float mass, float height, std::string name, std::string currentPlace, std::string currentPlanet, std::string currentSystem)
	:_mass(mass), _height(height), _name(name), _currentPlace(currentPlace), _currentPlanet(currentPlanet), _currentSystem(currentSystem)
{
	_gender = "unknown";
#if _DEBUG
	std::cout << "Konstrukcja obiektu typu Person" << std::endl;
#endif
};
Person::~Person()
{
#if _DEBUG
	std::cout << "Destrukcja obiektu typu Person"<<std::endl;
#endif
}


Person::Person(const Person& pers)
	:Person(pers._mass, pers._height, pers._name, pers._currentPlace, pers._currentPlanet, pers._currentSystem)
{};

void Person::CheckGender()
{
	std::cout << "Im unknooooooown"<<std::endl<<"I said it without my mark!";
}