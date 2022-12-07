#ifndef _tapkaros_h
#define _tapkaros_h
#include <string>
#include <iostream>
#include <ostream>
#include "album.h"
#include "spil.h"
using namespace std;

class Tapkaros {
public:
	Tapkaros(string ime, Spil* s);
	
private:
	string ime;
	int id;
	static int i;
	Spil* spil;
	Stamparija* stamparija;
};


#endif

