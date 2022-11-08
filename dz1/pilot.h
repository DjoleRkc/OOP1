#include <string>
#include <iostream>
#ifndef _dom1_h
#define _dom1_h
using namespace std;

class Pilot {
private:
	string ime;
	int brojSati;
	bool naLetu;
public:
	Pilot(string ime, int brojSati, bool naLetu=false) {
		this->ime = ime;
		this->brojSati = brojSati;
		this->naLetu = naLetu;
	};
	Pilot(const Pilot&) = delete;
	Pilot& operator = (const Pilot&) = delete;
	string dohvatiIme() const { return ime; }
	int  dohvatiBrSati() const { return brojSati; }
	bool dohvatiStatus() const { return naLetu; }
	void povecaj(int b) {
		this->brojSati += b;
	}
	void promeniStatus() {
		if (naLetu == false) naLetu = true;
		else naLetu = false;
	}
	void ispisiPilota() const {
		char status;
		if (naLetu) status = 'L';
		else status = 'N';
		cout << this->ime << "(" << brojSati << ")" << "-" << status << endl;
	}
};


#endif
