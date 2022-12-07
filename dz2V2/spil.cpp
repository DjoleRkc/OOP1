#include "spil.h"

void Spil::operator+=(Slicica* s)
{
	Node* n = new Node;
	n->s = s;
	n->next = nullptr;
	if (!first) {
		first = n;
		last = n;
	}
	else {
		last->next = n;
		last = n;
	}
}

bool Spil::operator%(int number)
{
	Node* temp = first;
	while (temp) {
		if (temp->s->getNumber() == number) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

void Spil::setCurrent()
{
	current = first;
}

void Spil::moveCurrent()
{
	if(current) current = current->next;
}

bool Spil::isEnd()
{
	return current == nullptr;
}

Slicica* Spil::getCurrent()
{
	if (current) return current->s;
	else return nullptr;
}

Node* Spil::removeSlicica(int num)
{
	Node* n = first;
	Node* prev = nullptr;
	while (n) {
		if (n->s->getNumber() == num) {
			if (prev) prev->next = n->next;
			else first = n->next;
			if (n == last) last = prev;
			if (n == current) current = n->next;
			return n;
		}
		prev = n;
		n = n->next;
	}
	return nullptr;
}

Spil::~Spil()
{
	brisi();
}

void Spil::brisi()
{
	Node* n = first;
	while (n) {
		Node* temp = n;
		n = n->next;
		delete temp;
	}
}

ostream& operator<<(ostream& os, const Spil& sp)
{
	Node* temp = sp.first;
	while (temp) {
		os << *temp->s << endl;
		temp = temp->next;
	}
	return os;
}
