#pragma once
#include "Person.h"

class Man : public Person
{
	Man(float mass, float height, std::string name, std::string currentPlace, std::string currentPlanet, std::string currentSystem);
public:
	//Man(const Man& pers);
	~Man();
	//friend std::ostream& operator<<(std::ostream& os, const Person& person);
	friend Planet;
	friend SolarSystem;
	friend SpaceShip;
	friend std::ostream& operator<<(std::ostream& os, const Man& person);
	virtual void CheckGender() override;
};