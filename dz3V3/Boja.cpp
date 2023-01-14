#include "Boja.h"
#include "greske.h"

Boja::Boja(int c, int z, int p)
{
	if ((c < 0 || c>255) || (z < 0 || z>255) || (p < 0 || p>255)) throw GLosaKomponenta();
	crvena = c;
	zelena = z;
	plava = p;

}

Boja& Boja::operator+(const Boja& b) const
{
	int nc = (this->crvena + b.crvena) / 2, nz = (this->zelena + b.zelena) / 2, np = (this->plava + b.plava) / 2;
	Boja nova(nc, nz, np);
	return nova;
}
