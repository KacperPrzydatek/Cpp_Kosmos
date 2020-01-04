#include <iostream>
#include <string>
#include "DEBUG.h"

class Planet;
class SpaceShip;
class SolarSystem;
class Person
{
	float _mass;
	float _height;
	std::string _name;
	std::string _currentPlace;
	std::string _currentPlanet;
	std::string _currentSystem;	
	Person(float mass, float height, std::string name, std::string currentPlace, std::string currentPlanet, std::string currentSystem);
	//Person();
	//void Swap(Person& one, Person& two);
public:
	Person(const Person& pers);
	~Person();
	friend std::ostream& operator<<(std::ostream& os, const Person& person);
	friend Planet;
	friend SolarSystem;
	friend SpaceShip;
	//void Show();
};