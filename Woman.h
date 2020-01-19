#pragma once
#include "Person.h"

class Woman : public Person
{
	Woman(float mass, float height, std::string name, std::string currentPlace, std::string currentPlanet, std::string currentSystem);
public:
	//Woman(const Woman& pers);
	~Woman();
	//friend std::ostream& operator<<(std::ostream& os, const Woman& person);
	friend Planet;
	friend SolarSystem;
	friend SpaceShip;
	friend std::ostream& operator<<(std::ostream& os, const Woman& person);

	virtual void CheckGender() override;
};