// Ova klasa je data kao moguća modifikacija od strane starijih studenata i nije urađena do kraja.
#include "svetsko.h"

Svetsko::Svetsko(string place)
{
	this->place = place;
}

void Svetsko::operator+=(Fudbaler f)
{
	Node* n = new Node;
	n->f = new Fudbaler(f.getName(), f.getNationalTeam(), f.getPosition());
	n->next = nullptr;
	if (last == nullptr) {
		last = n;
		first = n;
	}
	else {
		last->next = n;
		last = n;
	}
}

Svetsko::~Svetsko()
{
	Node* n = first;
	while (n != nullptr) {
		Node* temp = n;
		n = n->next;
		delete temp->f;
		delete temp;
	}
}
