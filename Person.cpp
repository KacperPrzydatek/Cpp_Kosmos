#include "Person.h"

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	return os << "Gender: " << person._gender << std::endl << "Name: " << person._name << std::endl << "Mass: " << person._mass << std::endl << "Height: " << person._height << std::endl << std::endl;
}