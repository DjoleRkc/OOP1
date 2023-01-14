#pragma once
#include <string>
#include <iostream>
#include "Skup.h"
using namespace std;
class Rec
{
	string rec;
public:
	Rec() = default;
	Rec(string s);
	int operator+() const { return rec.length(); };
	int operator~() const;
	string getRec() const { return rec; }
	int operator()(int n) const;
	bool operator^(const Rec& r) const;
	friend  istream& operator>>(istream& is, Rec& r);
	friend  ostream& operator<<(ostream& os, const Rec& r);
};

