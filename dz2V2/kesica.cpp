// Ova klasa je data kao moguća modifikacija od strane starijih studenata i nije urađena do kraja.
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
