#include "Woman.h"


Woman::Woman(float mass, float height, std::string name, std::string currentPlace, std::string currentPlanet, std::string currentSystem)
	:Person::Person(mass, height, name, currentPlace, currentPlanet, currentSystem)
{
	_gender = "woman";
#if _DEBUG
	std::cout << "Konstrukcja obiektu typu Person<M>" << std::endl;
#endif
};
Woman::~Woman()
{
#if _DEBUG
	std::cout << "Destrukcja obiektu typu Person<M>" << std::endl;
#endif
}


Woman::Woman(const Woman& pers)
	:Woman(pers._mass, pers._height, pers._name, pers._currentPlace, pers._currentPlanet, pers._currentSystem)
{};

void Woman::CheckGender()
{
	std::cout << "Im Womaaaaaan" << std::endl << "I said it without my mark!";
}