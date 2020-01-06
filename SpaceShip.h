#include <vector>
//#include "Person.h"
//#include "Woman.h"
#include "Man.h"



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
	//void SpaceShip::AddPerson(std::string gender,float mass, float height, std::string name);
public:
	SpaceShip(std::string name, std::string currentPlanet, std::string currentSystem);
	SpaceShip(const SpaceShip& ship);
	friend Planet;
	friend SolarSystem;
	friend std::ostream& operator<<(std::ostream& os, SpaceShip& ship);
	SpaceShip();
	~SpaceShip();
	//void Show();
	void AddMan(float mass, float height, std::string name);
	void AddWoman(float mass, float height, std::string name);
	void AddMan(Man person);
	void AddMan(Person person);
	void AddWoman(Woman person);
	void AddWoman(Person person);
};