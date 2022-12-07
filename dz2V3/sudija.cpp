// Ova klasa je data kao moguća modifikacija od strane starijih studenata i nije urađena do kraja.
#include "sudija.h"

Sudija::Sudija(string name, int exp)
{
	this->name = name;
	this->experience = exp;
}

string Sudija::getName()
{
	return name;
}

int Sudija::getExperience()
{
	return experience;
}

void Sudija::setUtakmica(Utakmica* ut)
{
	if (!utakmica || !utakmica->getProgress()) {
		utakmica = ut;
		Node2* current = first;
		while (current)
		{
			Node2* temp = current;
			current = current->next;
			delete temp;
		}
		first = last = nullptr;
	}
		
}

void Sudija::giveKarton(Fudbaler f, Karton k)
{
	if (utakmica && utakmica->getProgress())
	{
		Node2* current = first;
		while (current)
		{
			if (current->f == &f)
			{
				current->k[current->brKartona] = k;
				current->brKartona++;
				return;
			}
			current = current->next;
		}
		if (!first)
		{
			first = new Node2;
			first->f = &f;
			first->k[0] = k;
			first->brKartona = 1;
			first->next = nullptr;
			last = first;
		}
		else
		{
			last->next = new Node2;
			last = last->next;
			last->f = &f;
			last->k[0] = k;
			last->brKartona = 1;
			last->next = nullptr;
		}
	}
}

int Sudija::operator[](Fudbaler f)
{
	Node2* current = first;
	while (current)
	{
		if (current->f == &f)
			return current->brKartona;
		current = current->next;
	}
	return 0;
}

Sudija::~Sudija()
{
	Node2* current = first;
	while (current)
	{
		Node2* temp = current;
		current = current->next;
		delete temp;
	}
}
