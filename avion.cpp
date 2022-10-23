#include "avion.h"

void Avion::setKapetan(Pilot& kapetan)
{
	if (kapetan.getNaLetu() || kapetan.getSate() < 100) return;
	kapetan.setNaLetu();
	this->kapetan = &kapetan;
}

void Avion::setKopilot(Pilot& kopilot)
{
	if (kopilot.getNaLetu()) return;
	kopilot.setNaLetu();
	this->kopilot = &kopilot;
}

ostream& operator<<(ostream& os, const Avion& a)
{
	os << "AVION: " << a.naziv << "-" << a.brPutnika;
	return os;
}
