
#include <iostream>
#include "flota.h"

int main()
{
	Pilot p1("Marko", 200);
	Pilot p2("Ana", 180);
	Pilot p6("Miha", 150);
	Pilot p7("Srdjan", 120);
	Pilot p8("Mateja", 110);
	Pilot p3("Vuk", 90);
	Pilot p4("Milica", 75);
	Pilot p5("Sinisa", 50);
	Avion a1("Avion1", 120);
	Avion a2("Avion2", 150);
	Avion a3("Aviona3", 180);
	Avion a4("Avion4", 200);
	Avion a5("Avion5", 220);
	a1.setKapetan(p1);
	a2.setKapetan(p2);
	a1.setKopilot(p6);
	a2.setKopilot(p7);
	a3.setKapetan(p8);
	a3.setKopilot(p5);
	Flota f1("Flota1");
	f1.dodaj(a1).dodaj(a3).dodaj(a2);
	Flota f2("Flota2");
	f2.dodaj(a3).dodaj(a2);

	cout << f1 << endl;

	cout << f1.getNajveci();
}

