#ifndef _flota_h
#define _flota_h
#include <iostream>
#include "avion.h"
#include "pilot.h"
using namespace std;

struct Node {
	Node* sled;
	Avion* avion;
};

class Flota {
private:
	Node* prvi=nullptr, * posl=nullptr;

	string nazivFlote;
public:
	Flota(string imeFlote) {
		this->nazivFlote = imeFlote;
	}
	void dodajAvion(Avion& a);
	int brojAviona() const;
	int maxBrPutnika() const;
	Avion* najveciAvion() const;
	void ispisiFlotu() const;
	~Flota();
	Flota(const Flota& f);
	Flota(Flota&& f);

};

#endif
