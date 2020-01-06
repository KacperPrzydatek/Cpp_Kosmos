#include "Person.h"

class Woman : public Person
{
	float _mass;
	float _height;
	std::string _gender;
	std::string _name;
	std::string _currentPlace;
	std::string _currentPlanet;
	std::string _currentSystem;
	Woman(float mass, float height, std::string name, std::string currentPlace, std::string currentPlanet, std::string currentSystem);
public:
	Woman(const Woman& pers);
	~Woman();
	//friend std::ostream& operator<<(std::ostream& os, const Woman& person);
	friend Planet;
	friend SolarSystem;
	friend SpaceShip;

	void CheckGender();
};