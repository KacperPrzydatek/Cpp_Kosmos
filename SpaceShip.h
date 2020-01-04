#include <vector>
#include "Person.h"


class Planet;
class SolarSystem;
class SpaceShip
{
	std::string _name;
	std::vector<Person> _Crew;
	std::string _currentPlanet;
	std::string _currentSystem;
	void ShowWithoutCrew();
	void ShowCrew();
	//SpaceShip(std::string name, std::string currentPlanet, std::string currentSystem);
public:
	SpaceShip(std::string name, std::string currentPlanet, std::string currentSystem);
	SpaceShip(const SpaceShip& ship);
	friend Planet;
	friend SolarSystem;
	friend std::ostream& operator<<(std::ostream& os, SpaceShip& ship);
	SpaceShip();
	~SpaceShip();
	//void Show();
	void AddPerson(float mass, float height, std::string name);
	void AddPerson(Person person);
};