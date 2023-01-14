#include "Strani.h"

void Strani::ispisi(ostream& os) const
{
	os << this->getOznaka()<<" " << this->zemljaPorekla<<" ";
	switch (this->t) {
	case 0:
		os << "TITLOVAN ";
		break;
	case 1:
		os << "SINHRONIZOVAN ";
	}
}
