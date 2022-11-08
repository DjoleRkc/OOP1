#include "flota.h"

void Flota::dodajAvion(Avion& a)
{
	Node* novi = new Node;
	novi->avion = &a;
	novi->sled = nullptr;
	if (!prvi) prvi = novi;
	else posl->sled = novi;
	posl = novi;

}

int Flota::brojAviona() const
{
	int brojac = 0;
	Node* curr = this->prvi;
	while (curr != nullptr) {
		brojac++;
		curr = curr->sled;
	}
	return brojac;
}

int Flota::maxBrPutnika() const
{
	int brPutnika = 0;
	Node* curr = this->prvi;
	while (curr != nullptr) {
		brPutnika += curr->avion->dohvatiMaxBrPutnika();
		curr = curr->sled;
	}
	return brPutnika;
}

Avion* Flota::najveciAvion() const
{
	int max = 0;
	Avion* najveci=nullptr;
	Node* curr = this->prvi;
	while (curr != nullptr) {
		if (curr->avion->dohvatiMaxBrPutnika() > max) {
			max = curr->avion->dohvatiMaxBrPutnika(); najveci = curr->avion;
		}
		curr = curr->sled;
	}
	return najveci;
}

void Flota::ispisiFlotu() const
{
	cout << this->nazivFlote << endl;
	Node* curr = this->prvi;
	while (curr != nullptr) {
		curr->avion->ispisiAvion();
		curr = curr->sled;
	}
}

Flota::~Flota()
{
	Node* prev = prvi;
	for (Node* i = prvi; i; prev = i, i = i->sled) {
		delete prev;
	}
}

Flota::Flota(Flota&& f)
{
	nazivFlote = f.nazivFlote;
	prvi = f.prvi;
	posl = f.posl;
	f.nazivFlote = "";
	f.prvi = nullptr;
	f.posl = nullptr;
}

Flota::Flota(const Flota& f)
{
	nazivFlote = f.nazivFlote;
	for (Node* i = f.prvi, *prev = f.prvi; i; prev = i, i = i->sled) {
		Node* novi = new Node;
		novi->avion = i->avion;
		novi->sled = nullptr;
		if (prvi == nullptr) prvi = novi;
		else posl->sled = novi;
		posl = novi;
	}
}
