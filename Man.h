#pragma once
#include "Person.h"

class Man : public Person
{
	/*float _mass;
	float _height;

	std::string _name;
	std::string _currentPlace;
	std::string _currentPlanet;
	std::string _currentSystem;*/
	std::string _gender;
	Man(float mass, float height, std::string name, std::string currentPlace, std::string currentPlanet, std::string currentSystem);
public:
	Man(const Man& pers);
	~Man();
	//friend std::ostream& operator<<(std::ostream& os, const Person& person);
	friend Planet;
	friend SolarSystem;
	friend SpaceShip;

	virtual void CheckGender() override;
};