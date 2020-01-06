cmake_minimum_required(VERSION 3.10)


project(Kosmos)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)


add_executable(Kosmos main.cpp Man.h Man.cpp Woman.h Woman.cpp Person.h Person.cpp Planet.h Planet.cpp SolarSystem.h SolarSystem.cpp SpaceShip.h SpaceShip.cpp DEBUG.h)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

