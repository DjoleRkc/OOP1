#pragma once
#include "Rec.h"
#include <string>
class Stih
{
public:
	struct Node {
		Rec r;
		Node* next;
		Node(Rec rec, Node* nxt = nullptr) : r(rec) { next = nxt; }
	};
	Stih() { first = last = nullptr; }
	Stih& operator+=(const Rec r);
	int operator+() const;
	int operator~() const;
	Rec& operator[](int index) const;
	void operator()(int index);
	void operator()(const Rec& r, int index);
	bool operator^(const Stih& s) const;
	friend istream& operator>>(istream& is, Stih& s);
	friend ostream& operator<<(ostream& os, const Stih& s);
	Stih(const Stih& s);
	Stih(Stih&& s);
	Stih& operator=(const Stih& s);
	Stih& operator=(Stih&& s);
	~Stih();
private:
	Node* first, * last;
	void copy(const Stih& s);
	void move(Stih& s);
	void brisi();
};

