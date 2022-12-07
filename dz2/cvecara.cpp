#include "cvecara.h"

Cvecara::Cvecara()
{
	this->profit = 1000;
}

void Cvecara::addBouquet(Buket* b)
{
	if (b->totalSelling() < (1.2 * b->totalBuying())) return;
	Node2* tmp = new Node2;
	tmp->buket = b;
	tmp->next = nullptr;
	Node2* current = first;
	while (current && current->next && current->next->buket->totalSelling() < tmp->buket->totalSelling()) {
		current = current->next;
	}
	if (!first) first = tmp;
	else {
		if (first == current) {
			tmp->next = first;
			first = tmp;
		}
		else {
			tmp->next = current->next;
			current->next = tmp;
		}
	}
	this->profit -= b->totalBuying();
}

void Cvecara::sellBouquet(int pos)
{
	int i = 0;
	Node2* current = this->first;
	Node2* tmp;
	if (pos == 0) {
		tmp = this->first;
		first = first->next;
		this->profit += tmp->buket->totalSelling();
		delete tmp;
		return;
	}
	while (current && i<pos-1) {
		current = current->next;
		i++;
	}
	tmp = current->next;
	current->next = current->next->next;
	this->profit += tmp->buket->totalSelling();
	delete tmp;
	
}

Cvecara::~Cvecara()
{
	brisi();
}

Cvecara::Cvecara(const Cvecara& cv)
{
	copy(cv);
}

Cvecara& Cvecara::operator=(const Cvecara& cv)
{
	if (this != &cv) {
		brisi();
		copy(cv);
	}
	return *this;
}

Cvecara::Cvecara(Cvecara&& cv)
{
	move(cv);
}

Cvecara& Cvecara::operator=(Cvecara&& cv)
{
	if (this != &cv) {
		brisi();
		move(cv);
	}
	return *this;
}

void Cvecara::copy(const Cvecara& cv)
{
	Node2* last = nullptr;
	Node2* current = cv.first;
	this->profit = cv.profit;
	while (current) {
		Node2* tmp = new Node2;
		tmp->buket = new Buket(*current->buket);
		tmp->next = nullptr;
		if (!first) first = tmp;
		else last->next = tmp;
		last = tmp;
		current = current->next;
	}
}

void Cvecara::move(Cvecara& cv)
{
	this->first = cv.first;
	this->profit = cv.profit;
	cv.first = nullptr;
}

void Cvecara::brisi()
{
	Node2* prev = first, * current = first;
	while (current) {
		delete prev;
		prev = current;
		current = current->next;
	}
}

ostream& operator<<(ostream& os, const Cvecara& c)
{
	os << "zarada=" << c.profit<<"RSD"<<endl;
	Node2* current = c.first;
	while (current) os << *(current->buket)<<endl, current=current->next;
	return os;
}
