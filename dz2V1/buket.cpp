#include "buket.h"
#include <cmath>


void Buket::addFlower(Cvet* c)
{
	Node* tmp = new Node;
	tmp->cvet = c;
	tmp->next = nullptr;
	if (!first) first = tmp;
	else {
		last->next = tmp;
	}
	last = tmp;
}

int Buket::totalBuying() const
{
	int buying = 0;
	Node* current = this->first;
	while (current) {
		buying += current->cvet->getBuying();
		current = current->next;
	}
	return buying;
}

int Buket::totalSelling() const
{
	int selling = 0;
	Node* current = this->first;
	while (current) {
		selling += current->cvet->getSelling();
		current = current->next;
	}
	return selling;
}

int Buket::profit() const
{
	return this->totalSelling() - this->totalBuying();
}

Buket::~Buket()
{
	brisi();
}

Buket::Buket(const Buket& b)
{
	copy(b);
}

Buket& Buket::operator=(const Buket& b)
{
	if (this != &b) {
		brisi();
		copy(b);
	}
	return *this;
}

Buket::Buket(Buket&& b)
{
	move(b);
}

Buket& Buket::operator=(Buket&& b)
{
	if (this != &b) {
		brisi();
		move(b);
	}
	return *this;
}

void Buket::brisi()
{
	Node* prev = first, * current = first;
	while (current) {
		delete prev;
		prev = current;
		current = current->next;
	}
}

void Buket::copy(const Buket& b)
{
	Node* current = b.first;
	this->first = nullptr;
	this->last = nullptr;
	while (current) {
		Node* tmp = new Node;
		tmp->cvet = new Cvet(current->cvet->getName(), current->cvet->getBuying(), current->cvet->getSelling());
		tmp->next = nullptr;
		if (!first) first = tmp;
		else last->next = tmp;
		last = tmp;
		current = current->next;
	}
}

void Buket::move(Buket& b)
{
	this->first = b.first;
	this->last = b.last;
	b.first = b.last = nullptr;
}

bool operator>(const Buket& b1, const Buket& b2)
{
	return (b1.profit() > b2.profit());
}

ostream& operator<<(ostream& os, const Buket& b)
{
	Node* current = b.first;
	os << "(";
	while (current) {
		os << current->cvet->getName();
		if (current->next) os << ",";
		current = current->next;
	}
	os << ")";
	return os << b.totalSelling() << "RSD";
}
