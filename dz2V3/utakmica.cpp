// Ova klasa je data kao moguća modifikacija od strane starijih studenata i nije urađena do kraja.
#include "utakmica.h"

Utakmica::Utakmica(string r1, string r2, int kolo, Sudija* s)
{
	this->r1 = r1;
	this->r2 = r2;
	this->kolo = kolo;
	this->s = s;
}

bool Utakmica::getProgress() const
{
    return inProgress;
}
