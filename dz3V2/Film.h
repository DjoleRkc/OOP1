#pragma once
#include "Vreme.h"
#include "lista.h"
#include <iostream>
using namespace std;
class Film
{
	string name;
	Vreme trajanje;
	Lista<int> ocene;
public:
	Film(string naziv, const Vreme& v): trajanje(v) { name = naziv;}
	void oceni(int ocena) { ocene += ocena; }
	Vreme getTrajanje() const { return trajanje; }
	string getName() const { return name; }
	double prosecnaOcena() const;
	virtual  char getOznaka() const = 0;
	friend ostream& operator<<(ostream& os, const Film& f);
	virtual void ispisi(ostream& os) const = 0;

};

