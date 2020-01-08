#include "Planet.h"
#include <fstream>

class SolarSystem
{
	std::deque<Planet> _planetList;
	std::deque<SpaceShip> _spaceShipList;
	std::string _name;
	//Funkcje na uzytek ShowSystem()
	void ShowPopulation();
	void ShowShips();
	void ShowShipsinSpace(); //Uzywana w ShowShips()
	void ShowPlanets();
	
	//
public:
	SolarSystem(std::string name);
	~SolarSystem();
	
	void ShowSystem();
	//Funkcje dodawania obiektow do Systemu
	void AddPlanet(std::string name);
	void CopyPlanet(int indexPlanet);
	void AddSpaceShipToSpace(std::string name);
	void CopySpaceShip(int indexShip);
	void AddSpaceShipToPlanet(int indexPlanet, std::string name);
	void AddManToShipInSpace(int indexShip, float mass, float height, std::string name);
	void AddWomanToShipInSpace(int indexShip, float mass, float height, std::string name);
	void AddManCrewToShipOnPlanet(int indexPlanet, int indexShip, float mass, float height, std::string name);
	void AddWomanCrewToShipOnPlanet(int indexPlanet, int indexShip, float mass, float height, std::string name);
	void AddManToPlanet(int indexPlanet, float mass, float height, std::string name);
	void AddWomanToPlanet(int indexPlanet, float mass, float height, std::string name);
	//Funkcje przenoszenia: osob statek<->planeta && statkow: planeta<->space
	void PlanetMovePersonToShip(int planetIndex, int shipIndex, int personIndex);
	void PlanetMoveCrewFromShip(int planetIndex, int shipIndex, int crewIndex);
	void MoveShipToPlanet(int planetIndex, int shipIndex);
	void MoveShipToSpace(int planetIndex, int shipIndex);
	//Funkcje plikow
/*	void ZapiszDoPliku(char* plikTxt);
	void WczytajZPliku(char* plikTxt, int maxDlLinii = 50);*/
	
};