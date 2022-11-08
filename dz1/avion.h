#ifndef _avion_h
#define _avion_h
#include <iostream>
#include "pilot.h"
using namespace std;

class Avion {
private:
	string naziv;
	Pilot* kapetan =nullptr;
	Pilot* kopilot=nullptr;
	int maxKap;
public:
	Avion(string naziv, int maxBrPutnika) {
		this->naziv = naziv;
		this->maxKap = maxBrPutnika;
	}
	Avion(const Avion&) = delete;
	Avion& operator = (const Avion&) = delete;
	string dohvatiNazivAviona() const { return naziv; }
	Pilot* dohvatiPilota() const { return kapetan; }
	Pilot* dohvatiKopilota() const { return kopilot; }
	int dohvatiMaxBrPutnika() const { return maxKap; };
	void postaviKapetana(Pilot& p) {
		if (p.dohvatiBrSati() >= 100 && p.dohvatiStatus() == false) {
			this->kapetan = &p;
			p.promeniStatus();
		}
		else exit(0);
	}
	void postaviKopilota(Pilot& p) {
		if (&p != this->kapetan && p.dohvatiStatus()==false) {
			this->kopilot = &p;
			p.promeniStatus();
		}
		else exit(0);
	}
	void ispisiAvion() {
		cout << "AVION:" << this->naziv << "-" << this->maxKap << endl;
	}
};
#endif
