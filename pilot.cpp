#include "pilot.h"
#include <iostream>
void Pilot::setSat(int brSati)
{
	if (brSati > this->brSati) this->brSati = brSati;
}

ostream& operator<< (ostream& os, const Pilot& p)
{
	os << p.ime << "(" << p.brSati << ")-" << (p.naLetu) ? "L" : "N";
	return os;
}
