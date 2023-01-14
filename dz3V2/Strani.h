#pragma once
#include "Film.h"
class Strani : public Film
{
public:
	enum Tip { TITLOVAN, SINHRONIZOVAN };
private:
	string zemljaPorekla;
	Tip t;
public:
	Strani(string name, Vreme trajanje, string zemlja, Tip tip) : Film(name, trajanje) { zemljaPorekla = zemlja; t = tip;}
	char getOznaka() const override { return 'S'; }
	void ispisi(ostream& os) const override;
};

