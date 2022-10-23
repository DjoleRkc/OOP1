#ifndef _avion_h
#define _avion_h
#include "pilot.h"

class Avion {
public:
	Avion(const char* naziv, int brPutnika): naziv(string(naziv)), brPutnika(brPutnika) {}
	Avion(const string& naziv, int brPutnika) : naziv(naziv), brPutnika(brPutnika) {}
	Avion(const Avion&) = delete;

	Avion& operator = (const Avion&) = delete;

	void setKapetan(Pilot& kapetan);
	void setKopilot(Pilot& kopilot);
	
	const string& getNaziv() const { return naziv; }
	Pilot* getKapetan() const { return kapetan; }
	Pilot* getKopilot() const { return kopilot; }
	int getBrPutnika() const { return brPutnika; }

	friend ostream& operator<< (ostream&, const Avion&);


private:
	string naziv;
	Pilot* kapetan = nullptr, * kopilot = nullptr;
	int brPutnika;


};


#endif