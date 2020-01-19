#include "Planet.h"

Planet::Planet(std::string name, std::string currentSystem)
	: _name(name), _currentSystem(currentSystem)
{
#if _DEBUG
	std::cout << "Konstrukcja obiektu typu Planet" << std::endl;
#endif
};

Planet::Planet(const Planet& planet)
	:_name(planet._name), _currentSystem(planet._currentSystem)
{
#if _DEBUG
	std::cout << "Konstrukcja kopiujaca obiektu typu Planet" << std::endl;
#endif
	int tmp = 0;
	for (auto& it : planet._Populity)
	{
		
		if (it->_gender == "woman")
			AddWoman(it->_mass, it->_height, it->_name);
		else if (it->_gender == "man")
			AddMan(it->_mass, it->_height, it->_name);
	}
	for (auto& it : planet._SpacePort)
	{
		AddShip(it._name);
		for (auto& i : it._Crew)
		{
			if (i->_gender == "woman")
				_SpacePort[tmp].AddWoman(i->_mass, i->_height, i->_name);
			else if (i->_gender == "man")
				_SpacePort[tmp].AddMan(i->_mass, i->_height, i->_name);
		}
		++tmp;
	}
}

Planet::~Planet()
{
#if _DEBUG
	std::cout << "Destrukcja obiektu typu Planet" << std::endl;
#endif
}

std::ostream& operator<<(std::ostream& os, Planet& planet)
{
	std::cout << "Planet: " << planet._name << std::endl;
	std::cout << "Space Ships: " << planet._SpacePort.size() << std::endl;
	int shipindex = 0;
	for (auto& i : planet._SpacePort)
	{
		std::cout << "ShipIndex: " << shipindex << std::endl;
		std::cout << i;
		++shipindex;
	}
	std::cout<<std::endl << "Populity: " << planet._Populity.size() << std::endl;
	for (auto& i : planet._Populity)
	{
		std::cout << i;
	}
	return os;
}

void Planet::ShowWithoutShipsAndPopulation()
{
	std::cout << "Planet: " << _name << std::endl;
	std::cout << "Current System: " << _currentSystem << std::endl;
	std::cout << "Space Ships: " << _SpacePort.size() << std::endl;
	std::cout << "Population: " << _Populity.size() << std::endl;
}

void Planet::ShowShipsWithoutCrew()
{
	if(_SpacePort.size()!=0)
	{
		std::cout << "Planet: " << _name << std::endl;
		int shipindex = 0;
		for (auto& it : _SpacePort)
		{
			std::cout << "ShipIndex: " << shipindex << std::endl;
			it.ShowWithoutCrew();
			++shipindex;
			std::cout << std::endl;
		}
	}
}

void Planet::ShowPopulation()
{
	for (auto& it : _Populity)
	{
		std::cout << _name<<std::endl;
		std::cout << " " << std::endl;
		std::cout << *it;
	}
}

void Planet::AddMan(float mass, float height, std::string name)
{
	//Man tmp(mass, height, name, "OutOf", _name, _currentSystem);
	std::shared_ptr<Person> tmp;
	tmp.reset(new Man(mass, height, name, "OutOf", _name, _currentSystem));
	_Populity.push_back(tmp);
}
void Planet::AddWoman(float mass, float height, std::string name)
{
	std::shared_ptr<Person> tmp;
	tmp.reset(new Woman(mass, height, name, "OutOf", _name, _currentSystem));
	_Populity.push_back(tmp);
	//Woman tmp(mass, height, name, "OutOf", _name, _currentSystem);
	//_Populity.push_back(std::make_shared<Person>(tmp));
}

void Planet::AddShip(std::string name)
{
	SpaceShip tmp(name, _name, _currentSystem);
	_SpacePort.push_back(tmp);
}

void Planet::Show()
{
	std::cout << "Planet: " << _name << std::endl;
	std::cout << "Current System: " << _currentSystem << std::endl;
	std::cout << "Space Ships: " << _SpacePort.size() << std::endl;
	for (auto& it : _SpacePort)
	{
		std::cout << it;
	}
	std::cout << "Population: " << _Populity.size() << std::endl;
	for (auto& i : _Populity)
	{
		std::cout << i;
	}
}

void Planet::MoveToShip(int shipIndex, int personIndex)
{
	if (_SpacePort.size() > shipIndex)
	{
		if (_Populity[personIndex]->_gender == "woman")
			_SpacePort[_SpacePort.size() - 1].AddWoman(_Populity[personIndex]);
		else if (_Populity[personIndex]->_gender == "man")
		_SpacePort[_SpacePort.size()-1].AddMan(_Populity[personIndex]);
		else
			_SpacePort[_SpacePort.size() - 1].AddMan((_Populity[personIndex]));

		_Populity.erase(_Populity.begin()+personIndex);
	}
}

void Planet::MoveFromShip(int shipIndex, int crewIndex)
{
	if (_SpacePort.size() > shipIndex)
	{
		_Populity.push_back(_SpacePort[shipIndex]._Crew[crewIndex]);
		_Populity[_Populity.size() - 1]->_currentPlace = "OutOf";
		_SpacePort[shipIndex]._Crew.erase(_SpacePort[shipIndex]._Crew.begin() + crewIndex);
	}
}

/*
Planet::Planet()
	:Planet(1, "PlanetaZero", "OutsideSystem")
{};


void Planet::ShowShips()
{
	std::cout << "Planet: " << _name << std::endl;
	int shipindex = 0;
	for (auto& it : _SpacePort)
	{
		std::cout << "ShipIndex: " << shipindex << std::endl;
		std::cout << it;
		++shipindex;
	}
}*/