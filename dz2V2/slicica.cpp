#include "slicica.h"

Slicica::Slicica(int number, string name)
{
	this->number = number;
	this->name = name;
	id = i++;
}

int Slicica::getNumber()
{
	return number;
}

string Slicica::getName()
{
	return name;
}

int Slicica::getID()
{
	return id;
}

ostream& operator<<(ostream& os, const Slicica& s)
{
	os << "Slicica "<< s.number << " - " << s.name << "("<<s.id<<")"<<endl;
	return os;
}
