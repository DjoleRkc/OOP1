// Ova klasa je data kao moguća modifikacija od strane starijih studenata i nije urađena do kraja.
#ifndef _kesica_h
#define _kesica_h
#include "slicica.h"
#include <iostream>
using namespace std;

class Kesica {
public:
	Kesica(Slicica* s);
	Slicica* openKesica();
	Kesica(const Kesica&) = delete;
	Kesica& operator=(const Kesica& k) = delete;
	Kesica& operator=(Kesica&& k) = delete;
	


private:
	Slicica* slicice;



};

#endif

