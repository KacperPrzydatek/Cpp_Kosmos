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

void SpaceShip::AddMan(float mass, float height, std::string name)
{
	std::shared_ptr<Person> tmp;
	tmp.reset(new Man(mass, height, name, "OutOf", _name, _currentSystem));
	_Crew.push_back(tmp);
	/*Man tmp(mass, height, name, _name, _currentPlanet, _currentSystem);
	_Crew.push_back(std::make_shared<Person>(tmp));
	_Crew.back()->CheckGender();*/
}


void SpaceShip::AddWoman(float mass, float height, std::string name)
{
	std::shared_ptr<Person> tmp;
	tmp.reset(new Woman(mass, height, name, "OutOf", _name, _currentSystem));
	_Crew.push_back(tmp);
	/*
	Woman tmp(mass, height, name, _name, _currentPlanet, _currentSystem);
	//Woman* tmsp = &tmp;
	_Crew.push_back(std::make_shared<Woman>(tmp));*/
}

void SpaceShip::AddMan(std::shared_ptr<Person> person)
{
	AddMan(person->_mass, person->_height, person->_name);
}

void SpaceShip::AddWoman(std::shared_ptr<Person> person)
{
	AddWoman(person->_mass, person->_height, person->_name);
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
		std::cout << *it;
	}
}


SpaceShip::SpaceShip(const SpaceShip& ship)
	:SpaceShip(ship._name, ship._currentPlanet, ship._currentSystem)
{
	for (auto& it : ship._Crew)
	{
		if (it->_gender=="woman")
		AddWoman(it->_mass, it->_height, it->_name);
		else if (it->_gender=="man")
		AddMan(it->_mass, it->_height, it->_name);
		else std::cout << "SpaceShip copy C-tor doesnt work. Crew constaint non-binary person";
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