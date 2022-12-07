#ifndef _album_h
#define _album_h
#include "slicica.h"
#include "stamparija.h"
#include <iostream>
using namespace std;

class Album {
public:
	Album(Stamparija* st);
	void operator+=(Slicica s);

private:
	int numOfPlaces;
	Slicica* places;

};

#endif

