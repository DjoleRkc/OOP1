#pragma once
#include <exception>
using namespace std;

class GNemaCurr :public exception {
public:
	GNemaCurr() :exception("Greska: Ne postoji tekuci element!") {};
};

class GLosaKomponenta: public exception {
public:
	GLosaKomponenta() :exception("Greska: Uneli ste nevalidnu vrednost za neku od komponenti!") {};
};
