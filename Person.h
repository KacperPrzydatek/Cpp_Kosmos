#pragma once
#include <iostream>
#include <string>
#include "DEBUG.h"


class Planet;
class SpaceShip;
class SolarSystem;
class Person
{
protected:
	float _mass;
	float _height;
	std::string _gender;
	std::string _name;
	std::string _currentPlace;
	std::string _currentPlanet;
	std::string _currentSystem;	
public:

	friend std::ostream& operator<<(std::ostream& os, const Person& person);
	friend Planet;
	friend SolarSystem;
	friend SpaceShip;
	
	virtual void CheckGender()=0;
};
