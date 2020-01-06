#include <iostream>
#include <string>
#include <deque>
#include <memory>
#include "SpaceShip.h"
class SolarSystem;
class Planet
{
	std::string _name;
	std::deque<Person> _Populity;
	std::deque<SpaceShip> _SpacePort;
	std::string _currentSystem;
	void ShowWithoutShipsAndPopulation();
	void ShowPopulation();
	void ShowShipsWithoutCrew();
	//Planet(float radius, std::string name, std::string currentSystem);
public:
	Planet(std::string name, std::string currentSystem);
	Planet(const Planet& planet);
	~Planet();
	friend SolarSystem;
	friend std::ostream& operator<<(std::ostream& os, Planet& planet);
	void Show();
	void MoveToShip(int shipIndex, int personIndex);
	void MoveFromShip(int shipIndex, int crewIndex);
	void AddMan(float mass, float height, std::string name);
	void AddWoman(float mass, float height, std::string name);
	void AddShip(std::string name);
	//void ShowShips();

};