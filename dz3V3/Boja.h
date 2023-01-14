#pragma once
#include "greske.h"
#include <iostream>
class Boja
{
	int crvena, zelena, plava;
public:
	Boja(int c, int z, int p);
	bool operator==(const Boja& b) const { return crvena == b.crvena and zelena == b.zelena and plava == b.plava; }
	Boja& operator+(const Boja& b) const;
};

