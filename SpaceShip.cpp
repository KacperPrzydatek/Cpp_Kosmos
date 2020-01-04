#include "SpaceShip.h"


std::ostream& operator<<(std::ostream& os, SpaceShip& ship)
{
	std::cout << "Space Ship: " << ship._name << std::endl;
	std::cout << "Crew: " << ship._Crew.size() << std::endl;
	for (auto& i : ship._Crew)
	{
		std::cout << i;
	}
	return os;
}


SpaceShip::SpaceShip(std::string name, std::string currentPlanet, std::string currentSystem)
	:_name(name), _currentPlanet(currentPlanet), _currentSystem(currentSystem)
{
#if _DEBUG
	std::cout << "Konstrukcja obiektu typu SpaceShip" << std::endl;
#endif
}
SpaceShip::SpaceShip()
	:SpaceShip("StatekZero", "PlanetaZero", "OutsideSystem")
{};

SpaceShip::~SpaceShip()
{
#if _DEBUG
	std::cout << "Destrukcja obiektu typu SpaceShip" << std::endl;
#endif
}

void SpaceShip::AddPerson(float mass, float height, std::string name)
{
	Person tmp(mass, height, name, _name, _currentPlanet, _currentSystem);
	_Crew.push_back(tmp);
}

void SpaceShip::AddPerson(Person person)
{
	AddPerson(person._mass, person._height, person._name);
}

void SpaceShip::ShowWithoutCrew()
{
	std::cout << "Space Ship: " << _name << std::endl;
	std::cout << "Current System: " << _currentSystem << std::endl;
	std::cout << "Current Planet: " << _currentPlanet << std::endl;
	std::cout << "Crew: " << _Crew.size() << std::endl;
}

void SpaceShip::ShowCrew()
{
	for (auto& it : _Crew)
	{
		std::cout << _currentPlanet<<std::endl;
		std::cout << _name<<std::endl;
		std::cout << it;
	}
}

SpaceShip::SpaceShip(const SpaceShip& ship)
	:SpaceShip(ship._name, ship._currentPlanet, ship._currentSystem)
{
	for (auto& it : ship._Crew)
	{
		AddPerson(it._mass, it._height, it._name);
	}
}


/*
void SpaceShip::Show()
{
	std::cout << "Space Ship: " << _name << std::endl;
	std::cout << "Current System: " << _currentSystem<< std::endl;
	std::cout << "Current Planet: " << _currentPlanet << std::endl;
	std::cout << "Crew: " << _Crew.size() << std::endl;
	for (auto& i : _Crew)
	{
		std::cout << i;
	}
}*/