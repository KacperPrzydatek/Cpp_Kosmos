#include "Person.h"

class Man : public Person
{
	float _mass;
	float _height;
	std::string _name;
	std::string _currentPlace;
	std::string _currentPlanet;
	std::string _currentSystem;
	bool _ifMan;
	Man(float mass, float height, std::string name, std::string currentPlace, std::string currentPlanet, std::string currentSystem);
	//Person();
	//void Swap(Person& one, Person& two);
public:
	Man(const Man& pers);
	~Man();
	friend std::ostream& operator<<(std::ostream& os, const Person& person);
	friend Planet;
	friend SolarSystem;
	friend SpaceShip;
	//void Show();
};