#include "pogodak.h"

Pogodak::Pogodak(Fudbaler* f, int min)
{
	strelac = f;
	minut = min;
}

Fudbaler* Pogodak::getStrelac()
{
	return strelac;
}

Pogodak::Pogodak(const Pogodak& p)
{
	copy(p);
}

Pogodak& Pogodak::operator=(const Pogodak& p)
{
	if (this != &p)
	{
		delete strelac;
		copy(p);
	}
	return *this;
}

Pogodak::Pogodak(Pogodak&& p)
{
	move(p);
}

Pogodak& Pogodak::operator=(Pogodak&& p)
{
	if (this != &p)
	{
		delete strelac;
		move(p);
	}
	return *this;
}

Pogodak::~Pogodak()
{
	brisi();
}

void Pogodak::copy(const Pogodak& p)
{
	strelac = new Fudbaler(p.strelac->getName(), p.strelac->getNationalTeam(), p.strelac->getPosition());
	minut = p.minut;
}

void Pogodak::move(Pogodak& p)
{
	strelac = p.strelac;
	minut = p.minut;
	p.strelac = nullptr;
}

void Pogodak::brisi()
{
	delete strelac;
}


ostream& operator<<(ostream& os, const Pogodak& p)
{
	return os << "[" << p.minut<<"'] - "<<*p.strelac << endl;
}
