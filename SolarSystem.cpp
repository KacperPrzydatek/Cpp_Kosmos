#include "SolarSystem.h"
SolarSystem::SolarSystem(std::string name)
	:_name(name)
{
#if _DEBUG
	std::cout << "Konstrukcja obiektu typu SolarSystem" << std::endl;
#endif
}

SolarSystem::~SolarSystem()
{
#if _DEBUG
	std::cout << "Destrukcja obiektu typu SolarSystem" << std::endl;
#endif
}

void SolarSystem::ShowShipsinSpace()
{
	int shipindex = 0;
	if (_spaceShipList.size() != 0)
	{
		for (auto& it : _spaceShipList)
		{
			std::cout << "shipIndex: " << shipindex << std::endl;
			it.ShowWithoutCrew();
			std::cout << std::endl;
			++shipindex;
		}
	}
}

void SolarSystem::AddPlanet(std::string name)
{
	Planet tmp(name, _name);
	_planetList.push_back(tmp);
}

void SolarSystem::CopyPlanet(int indexPlanet)
{
	Planet tmp(_planetList[indexPlanet]);
	_planetList.push_back(tmp);
}

void SolarSystem::AddSpaceShipToSpace(std::string name)
{
	SpaceShip tmp(name, "Space", _name);
	_spaceShipList.push_back(tmp);
}

void SolarSystem::CopySpaceShip(int indexShip)
{
	SpaceShip tmp(_spaceShipList[indexShip]);
	_spaceShipList.push_back(tmp);
}

void SolarSystem::ShowPlanets()
{
	int index = 0;
	for (auto& it : _planetList)
	{
		std::cout << "Index: " << index << std::endl;
		it.ShowWithoutShipsAndPopulation();
		std::cout << std::endl;
		++index;
	}
}

void SolarSystem::ShowShips()
{
	for (auto& it : _planetList)
	{
		it.ShowShipsWithoutCrew();
	}
	std::cout << "In space: " << std::endl;
	ShowShipsinSpace();
}

void SolarSystem::ShowPopulation()
{
	for (auto& it : _planetList)
	{
		it.ShowPopulation();
	}
	for (auto& it : _planetList)
	{
		for (auto& i : it._SpacePort)
			i.ShowCrew();
	}
	for (auto& it : _spaceShipList)
	{
			it.ShowCrew();
	}
}


void SolarSystem::ShowSystem()
{
	std::cout << "System " << _name << ":" << std::endl;
	std::cout << "Planets: " << _planetList.size()<< std::endl;
	ShowPlanets();
	std::cout << std::endl << std::endl << "                            SPACE SHIPS" << std::endl << std::endl;	
	ShowShips();
	std::cout <<  "			POPULATION" << std::endl<<std::endl;
	ShowPopulation();
}


void SolarSystem::AddSpaceShipToPlanet(int indexPlanet, std::string name)
{
	_planetList[indexPlanet].AddShip(name);
}

void SolarSystem::AddManToShipInSpace(int indexShip, float mass, float height, std::string name)
{
	_spaceShipList[indexShip].AddMan(mass, height, name);
}
void SolarSystem::AddWomanToShipInSpace(int indexShip, float mass, float height, std::string name)
{
	_spaceShipList[indexShip].AddWoman(mass, height, name);
}

void SolarSystem::AddManToPlanet(int indexPlanet, float mass, float height, std::string name)
{
	_planetList[indexPlanet].AddMan(mass, height, name);
}
void SolarSystem::AddWomanToPlanet(int indexPlanet, float mass, float height, std::string name)
{
	_planetList[indexPlanet].AddWoman(mass, height, name);
}

void SolarSystem::AddManCrewToShipOnPlanet(int indexPlanet, int indexShip, float mass, float height, std::string name)
{
	_planetList[indexPlanet]._SpacePort[indexShip].AddMan(mass, height, name);
}
void SolarSystem::AddWomanCrewToShipOnPlanet(int indexPlanet, int indexShip, float mass, float height, std::string name)
{
	_planetList[indexPlanet]._SpacePort[indexShip].AddWoman(mass, height, name);
}

void SolarSystem::PlanetMovePersonToShip(int planetIndex, int shipIndex, int personIndex)
{
	_planetList[planetIndex].MoveToShip(shipIndex, personIndex);
}

void SolarSystem::PlanetMoveCrewFromShip(int planetIndex, int shipIndex, int crewIndex)
{
	_planetList[planetIndex].MoveFromShip(shipIndex, crewIndex);
}

void SolarSystem::MoveShipToPlanet(int planetIndex, int shipIndex)
{
	_planetList[planetIndex]._SpacePort.push_back(_spaceShipList[shipIndex]);
	_planetList[planetIndex]._SpacePort[_planetList[planetIndex]._SpacePort.size() - 1]._currentPlanet = _planetList[planetIndex]._name;
	_spaceShipList.erase(_spaceShipList.begin() + shipIndex);
}

void SolarSystem::MoveShipToSpace(int planetIndex, int shipIndex)
{
	_spaceShipList.push_back(_planetList[planetIndex]._SpacePort[shipIndex]);
	_spaceShipList[_spaceShipList.size() - 1]._currentPlanet = "Space";
	_planetList[planetIndex]._SpacePort.erase(_planetList[planetIndex]._SpacePort.begin() + shipIndex);
}