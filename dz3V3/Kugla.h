#pragma once
#include "Ukras.h"
#include<iostream>
using namespace std;
class Kugla : public Ukras
{
public:
	enum Velicina{ MALA, SREDNJA, VELIKA, NAJVECA };
	void ispisi(ostream& os) const override;
private:
	Velicina v;
public:
	Kugla(const Boja& b, int masa, Velicina vel): Ukras(b, masa) { v = vel; }
};

