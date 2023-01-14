#pragma once
#include "Boja.h"
#include<iostream>
using namespace std;
class Ukras{
	Boja b;
	int masa;
public:
	Ukras(const Boja& boja, int m) : b(boja) { masa = m; }
	Boja getBoja() const { return b; }
	int getMasa() const { return masa; }
	virtual void ispisi(ostream& os) const = 0;
	friend ostream& operator<<(ostream& os, const Ukras& u);
};

