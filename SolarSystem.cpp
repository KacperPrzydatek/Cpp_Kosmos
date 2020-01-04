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

void SolarSystem::AddCrewToShipInSpace(int indexShip, float mass, float height, std::string name)
{
	_spaceShipList[indexShip].AddPerson(mass, height, name);
}

void SolarSystem::AddPersonToPlanet(int indexPlanet, float mass, float height, std::string name)
{
	_planetList[indexPlanet].AddPerson(mass, height, name);
}

void SolarSystem::AddCrewToShipOnPlanet(int indexPlanet, int indexShip, float mass, float height, std::string name)
{
	_planetList[indexPlanet]._SpacePort[indexShip].AddPerson(mass, height, name);
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

void SolarSystem::ZapiszDoPliku(char* plikTxt)
{
	std::cout << "ZAPIS DO PLIKU" << std::endl;
	std::ofstream save(plikTxt);
	if (!save.is_open())
	{
		std::cout << "Plik do zapisu nie zostal otwarty";
		exit(0);
	}
	save<< _name <<std::endl;
	for (auto& planets: _planetList)
	{
		save << planets._name << std::endl;
		for (auto& ships : planets._SpacePort)
		{
			save << ships._name << std::endl;
			for (auto& crew : ships._Crew)
			{
				save << crew._name << std::endl;
				save << crew._height << std::endl;
				save << crew._mass << std::endl;
			}
			save << "___"<<std::endl;
		}
		if (planets._SpacePort.size() == 0) save << "___" << std::endl;
		save << "PopulacjaPlanety:" << std::endl;;
		for (auto& populity : planets._Populity)
		{
			save << populity._name << std::endl;
			save << populity._height << std::endl;
			save << populity._mass << std::endl;
		}
			save<<"///"<<std::endl;
	}
	save << "OkretyKosmiczneWPrzestrzeni" << std::endl;
	for (auto& ships : _spaceShipList)
	{
		save << ships._name<<std::endl;
		for (auto& crew : ships._Crew)
		{
			save << crew._name << std::endl;
			save << crew._height << std::endl;
			save << crew._mass << std::endl;
		}
		save << "---"<<std::endl;
	}
	save << "KoniecZapisu";
	save.close();
}

void SolarSystem::WczytajZPliku(char* plikTxt, int maxDlLini)
{
	std::cout << "WCZYTYWANIE Z PLIKU"<<std::endl;
	std::ifstream load(plikTxt);
	load >> _name;
	std::string tmp;
	int counter = 0;
	int cnt2 = 0;
	int ct3 = 0;
	int cn4 = 0;
	int c5 = 0;
	int acounter = 0;
	int acnt2 = 0;
	//SpaceShip tmpShip("0", "0", "0");
	while (1)
	{
		load >> tmp;
		if (tmp == "OkretyKosmiczneWPrzestrzeni") break;
		_planetList.push_back(Planet(tmp, _name));
		while (1)
		{
			load >> tmp;
			if (tmp == "___") break;
			/*tmpShip._name = tmp;
			tmpShip._currentPlanet = _planetList[counter]._name;
			tmpShip._currentSystem = _name;*/
			_planetList[counter]._SpacePort.push_back(SpaceShip(tmp, _planetList[counter]._name, _name));
			while (1)
			{
				load >> tmp;
				if (tmp == "___") break;
				_planetList[counter]._SpacePort[cnt2]._Crew.push_back(Person(0, 0, tmp, _planetList[counter]._SpacePort[cnt2]._name, _planetList[counter]._name, _name));
				load >> _planetList[counter]._SpacePort[cnt2]._Crew[ct3]._height;
				load >> _planetList[counter]._SpacePort[cnt2]._Crew[ct3]._mass;
				++ct3;
				
			}
			++cnt2;
		}
		load >> tmp;
		//////O TU O SIE ZATRZYMALEM

		while(1)
		{
			load >> tmp;
			
			if (tmp == "///")
				break;
			_planetList[counter]._Populity.push_back(Person(0, 0, tmp, "OutOF", _planetList[counter]._name, _name));
			load >> _planetList[counter]._Populity[cn4]._height;
			load >> _planetList[counter]._Populity[cn4]._mass;
			++cn4;
		}
		++counter;
		
	}
	while (1)
	{
		load >> tmp;
		if (tmp == "KoniecZapisu") break;
		_spaceShipList.push_back(SpaceShip(tmp, "Space", _name));
		while (1)
		{
			load >> tmp;
			if (tmp == "---") break;
			_spaceShipList[acounter].AddPerson(0, 0, tmp);
			load >> _spaceShipList[acounter]._Crew[acnt2]._height;
			load >> _spaceShipList[acounter]._Crew[acnt2]._mass;
			++acnt2;
		}
		++acounter;
	}
	load.close();
}