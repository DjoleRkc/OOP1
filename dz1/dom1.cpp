#include "pilot.h"
#include <iostream>
#include "avion.h"
#include "flota.h"
using namespace std;

int main() {
	Flota* f = new Flota("Air Serbia");
	Pilot* p = new Pilot("Mirko", 20);
	Pilot* p2 = new Pilot("Darko", 200);
	Pilot* p3 = new Pilot("Lana", 11);
	Pilot* p4 = new Pilot("Ana", 348);
	Pilot* p5 = new Pilot("Marko", 24);
	Pilot* p6 = new Pilot("Janko", 100);
	Pilot* p7 = new Pilot("Ogi", 12);
	Pilot* p8 = new Pilot("Anastasija", 1099);
	Avion* a = new Avion("Airbus A320", 180);
	Avion* a2 = new Avion("Boeing 777", 388);
	Avion *a3 = new Avion("Embraer 195", 132);
	Avion* a4 = new Avion("Airbus A380", 853);
	a->postaviKapetana(*p2);
	a->postaviKopilota(*p);
	a2->postaviKapetana(*p4);
	a2->postaviKopilota(*p3);
	a3->postaviKapetana(*p6);
	a3->postaviKopilota(*p5);
	a4->postaviKapetana(*p8);
	a4->postaviKopilota(*p7);
	f->dodajAvion(*a);
	f->dodajAvion(*a2);
	f->dodajAvion(*a3);
	f->dodajAvion(*a4);
	f->ispisiFlotu();
	cout << endl;
	f->najveciAvion()->ispisiAvion();
}