#ifndef _pogodak_h
#define _pogodak_h
#include "fudbaler.h"
#include <iostream>
#include <string>
using namespace std;

class Pogodak {
public:
	Pogodak(Fudbaler *f, int min);
	Fudbaler* getStrelac();
	friend ostream& operator<<(ostream& os, const Pogodak& p);
	Pogodak(const Pogodak& p);
	Pogodak& operator=(const Pogodak& p);
	Pogodak(Pogodak&& p);
	Pogodak& operator=(Pogodak&& p);
	~Pogodak();
	
private:
	Fudbaler* strelac;
	int minut;
	void copy(const Pogodak& p);
	void move(Pogodak& p);
	void brisi();
	
};



#endif



