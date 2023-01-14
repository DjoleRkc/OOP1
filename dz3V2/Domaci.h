#pragma once
#include "Film.h"
class Domaci : public Film
{
public:
	Domaci(string name, Vreme trajanje) : Film(name, trajanje) {}
	char getOznaka() const override { return 'D'; }
	void ispisi(ostream& os) const override { os << this->getOznaka()<<" "; }
};

