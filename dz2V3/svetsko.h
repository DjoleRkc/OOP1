// Ova klasa je data kao moguća modifikacija od strane starijih studenata i nije urađena do kraja.
#ifndef _svetsko_h
#define _svetsko_h
#include <iostream>
#include "fudbaler.h"
#include <string>
using namespace std;

struct Node {
	Fudbaler *f;
	Node* next;
};

class Svetsko {
public:
	Svetsko(string place);
	void operator+=(Fudbaler f);
	Svetsko& operator=(const Svetsko& f) = delete;
	Svetsko(const Svetsko& f) = delete;
	~Svetsko();

private:
	string place; 
	Node* last = nullptr, * first = nullptr;
};
#endif // !_svetsko_h

