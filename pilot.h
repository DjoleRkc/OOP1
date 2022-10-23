#ifndef _pilot_h
#define _pilot_h

#include <string>
#include <iostream>
using namespace std;

class Pilot {
public:
	Pilot(const string& ime, int brSati, bool naLetu = false) : ime(ime), brSati(brSati), naLetu(naLetu) {}
	Pilot(const char* ime, int brSati, bool naLetu = false) : ime(string(ime)), brSati(brSati), naLetu(naLetu) {}
	Pilot(const Pilot&&) = delete;
	
	Pilot& operator = (const Pilot&) = delete;

	void setSat(int brSati);
	void setNaLetu() { this->naLetu = !this->naLetu; }
	


	const string& getIme() const { return ime; }
	int getSate() const { return brSati; }
	bool getNaLetu() const { return naLetu; }

	friend ostream& operator<<(ostream&, const Pilot&);

private:
	string ime;
	int brSati;
	bool naLetu;
};


#endif