#include "Person.h"

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	return os << "Name: " << person._name <<std::endl<< "Mass: " << person._mass << std::endl << "Height: " << person._height << std::endl <<std::endl;
}

Person::Person(float mass, float height, std::string name, std::string currentPlace, std::string currentPlanet, std::string currentSystem)
	:_mass(mass), _height(height), _name(name), _currentPlace(currentPlace), _currentPlanet(currentPlanet), _currentSystem(currentSystem)
{
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

/*
Person::Person()
	:_mass(100), _height(200), _name("Bezimienny"), _currentPlanet("Czarna Dziura")
{};

void Person::Swap(Person& one, Person& two)
{
	std::swap(one._mass, two._mass);
	std::swap(one._height, two._height);
	std::swap(one._name, two._name);
	std::swap(one._currentPlace, two._currentPlace);
	std::swap(one._currentPlanet, two._currentPlanet);
}

void Person::Show()
{
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Current Ship: " << _currentPlace << std::endl;
	std::cout << "Current Planet: " << _currentPlanet << std::endl;
	std::cout << "Current System: " << _currentSystem << std::endl;
	std::cout << "Mass: " << _mass << std::endl;
	std::cout << "Height: " << _height << std::endl;
}
*/