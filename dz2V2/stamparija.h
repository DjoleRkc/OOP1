#ifndef _stamparija_h
#define _stamparija_h
#include <string>
#include <iostream>
#include <ostream>
#include "slicica.h"
using namespace std;

class Stamparija {
public:
	Stamparija(string* s, int n);
	Slicica* makeSlicica(int n);
	int getBrojSlicica() const { return brojSlicica; }
	Stamparija(const Stamparija& s) = delete;
	Stamparija& operator=(const Stamparija& s) = delete;
	~Stamparija();

private:
	string* names;
	int brojSlicica;
	void brisi();
};
#endif

