#include "stamparija.h"

Stamparija::Stamparija(string* s, int n)
{
	if (n <= 0) return;
	names = new string[n];
	for (int i = 0; i < n; i++)
	{
		names[i] = s[i];
	}
	brojSlicica = n;
}

Slicica* Stamparija::makeSlicica(int n)
{
	if (n >= brojSlicica && n<0) return nullptr;
	Slicica* s = new Slicica(n, names[n]);
	return s;
}

Stamparija::~Stamparija()
{
	brisi();
}

void Stamparija::brisi()
{
	for (int i = 0; i < brojSlicica; i++)
	{
		names[i].clear();
	}
	delete[] names;
}

