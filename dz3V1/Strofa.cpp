#include "Strofa.h"

Strofa& Strofa::operator+=(const Stih& s)
{
	Stih kopija = s;
	if (!brElem and (brElem + 1 <= kap)) this->nizStihova[this->brElem++] = kopija;
	else if (brElem and (s.operator~() == this->nizStihova[brElem-1].operator~()) and (brElem + 1 <= kap)) this->nizStihova[this->brElem++] = kopija;
	return *this;
}

Strofa::Strofa(const Strofa& s) 
{
	copy(s);
}

Strofa& Strofa::operator=(const Strofa& s)
{
	if (this != &s) {
		brisi();
		copy(s);
	}
	return *this;
}

Strofa& Strofa::operator=(Strofa&& s) 
{
	if (this != &s) {
		brisi();
		move(s);
	}
	return *this;
}

Strofa::Strofa(Strofa&& s) 
{
	move(s);
}

ostream& operator<<(ostream& os, Strofa& s)
{
	for (size_t i = 0; i < s.brElem; i++)
	{
		os << s.nizStihova[i]<<endl;
	}
	return os;
}


void Strofa::copy(const Strofa& s)
{
	Stih* tmp = new Stih[s.kap];
	for (size_t i = 0; i < s.brElem; i++)
	{
		tmp[i] = s.nizStihova[i];
	}
	this->nizStihova = tmp;
	this->brElem = s.brElem;
	this->kap = s.kap;
}

void Strofa::move(Strofa& s)
{
	this->nizStihova = s.nizStihova;
	this->kap = s.kap;
	this->brElem = s.brElem;
	s.nizStihova = nullptr;
}

void Strofa::brisi()
{
	delete[] nizStihova;
	brElem = 0;
	kap = 0;
}
