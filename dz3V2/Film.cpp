#include "Film.h"
#include "lista.h"
double Film::prosecnaOcena() const
{
	if (!this->ocene.getNumOfElems()) return 0;
	int zbir = 0;
	for (int i = 0; i < this->ocene.getNumOfElems(); i++) zbir += this->ocene[i];
	return (double)zbir / this->ocene.getNumOfElems();
}

ostream& operator<<(ostream& os, const Film& f)
{
	f.ispisi(os);
	os << f.getName()<<" "<<f.getTrajanje()<<" "<<f.prosecnaOcena();
	return os;
}
