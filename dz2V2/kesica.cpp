#include "kesica.h"

Kesica::Kesica(Slicica* s)
{
	slicice = s;
}

Slicica* Kesica::openKesica()
{
	Slicica* temp = slicice;
	slicice = nullptr;
	return temp;
}
