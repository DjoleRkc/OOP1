// Ova klasa je data kao moguća modifikacija od strane starijih studenata i nije urađena do kraja.
#ifndef _sudija_h
#define _sudija_h
#include "fudbaler.h"
#include "utakmica.h"
#include <iostream>
using namespace std;

enum Karton{ZUTI, CRVENI};

struct Node2 {
	Fudbaler* f;
	Node2* next;
	int brKartona;
	Karton k[2];
};

class Sudija {
public:
	Sudija(string name, int exp);
	string getName();
	int getExperience();
	void setUtakmica(Utakmica* ut);
	void giveKarton(Fudbaler f, Karton k);
	int operator[](Fudbaler f);
	Sudija& operator=(const Sudija& f) = delete;
	Sudija(const Sudija& f) = delete;
	~Sudija();

private:
	Utakmica* utakmica = nullptr;
	string name;
	int experience;
	Karton k;
	Node2* first = nullptr, * last = nullptr;
};



#endif

