#include <iostream>
#include "SolarSystem.h"

/*
Zmien zapis i odczyt.
*/
//DEBUGOWANIE zawarte w DEBUG.h
/*
Program przeznaczony do tworzenia UKLADOW, PLANET, STATKOWKOSMICZNYCH, LUDZI. Wszystko dzieje sie w jednym UKLADZIE.
UKLADY nie maja sposobu na komunikacje miedzy soba. Calosc programu polega na przerzucaniu LUDZI pomiedzy PLANETAMI,
do czego potrzebne sa STATKI. Zeby przemiescic CZLOWIEKA STATEK musi wyladawac na planecie zaladowac/wyladowac CZLOWIEKA,
odleciec z PLANETY, wyladawac na PLANECIE i ponownie WYLADOWAC/ZALADOWAC CZLOWIEKA.
Dodatkowo posiadam obiekty klasy PHASELEMON, ktore jako jedyne moga znajdowac sie na kilku planetach jednoczesnie.
Stad wlasnie sa alokowane dynamicznie.
Calosc programu sterowana jest za pomoca metod UKLADU.
Na potrzeby testow c-tor upublicznilem czesc parametrow planety(takich jak konstruktory) finalnie powinny zostac one ponownie zprywatyzowane.
W ostatecznosci przy zaprzyjaznieniu wszystkich pozostalych KLAS ze soba, oraz z UKLADEM, calosc KLAS (wylaczajac UKLAD) moze zostac sprywatyzowana.
*/


void main()
{
	//PROGRAM TESTUJACY FUNKCJONALNOSC KODU
	
	SolarSystem S1("Sloneczny");
	S1.AddPlanet("Ziemia");
	S1.AddPlanet("Mars");
	S1.AddSpaceShipToPlanet(0, "ISS");
	S1.AddPersonToPlanet(0, 95, 160, "Sasha");
	S1.AddSpaceShipToSpace("ISSDS");
	S1.AddSpaceShipToSpace("QWISS");
	S1.AddCrewToShipOnPlanet(0, 0, 120, 210, "XYP");
	S1.AddCrewToShipOnPlanet(0, 0, 120, 210, "XYZ");
	S1.AddPersonToPlanet(0, 90, 180, "ABC");
	std::cout << std::endl << std::endl;
	S1.PlanetMoveCrewFromShip(0, 0, 1);
	S1.PlanetMovePersonToShip(0, 0, 0);
	S1.MoveShipToSpace(0, 0);
	std::cout << std::endl << std::endl;
	S1.ZapiszDoPliku("Plik.txt"); 
	//SolarSystem S1("asdwa");
	//S1.WczytajZPliku("Plik.txt");


	//TEST NAJWIEKSZEGO KONSTRUKTORA KOPIUJACEGO
	/*
	Planet P1(1500, "Testowa", "Solarna");
	P1.AddPerson(95, 160, "Nowiutka");
	P1.AddPerson(95, 160, "Nowiutkwa");
	P1.AddPerson(91, 120, "Nowiutkaasdw");
	P1.AddShip("putnik");
	P1.AddShip("Sputnik");
	P1.MoveToShip(0, 1);
	Planet P2(P1);
	P1.Show();
	std::cout << std::endl << std::endl;
	P2.Show();
	*/
	system("PAUSE");
}