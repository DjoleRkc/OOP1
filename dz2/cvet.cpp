#include "cvet.h"

Cvet::Cvet(string name, int buyingPrice, int sellingPrice)
{
	this->name = name;
	this->buyingPrice = buyingPrice;
	this->seliingPrice = sellingPrice;
}

int Cvet::profit()
{
	return this->seliingPrice - this->buyingPrice;
}

bool operator==(const Cvet& c1, const Cvet& c2)
{
	if (c1.getName() == c2.getName()) return true;
	return false;
}

bool operator!=(const Cvet& c1, const Cvet& c2)
{
	if (c1.getName() != c2.getName()) return true;
	return false;
}

ostream &operator<<(ostream& os, const Cvet& c1)
{
	return os << c1.getName();
}
