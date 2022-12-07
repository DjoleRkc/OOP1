#ifndef _cvecara_h
#define _cvecara_h
#include <iostream>
#include "buket.h"
using namespace std;

struct Node2 {
	struct Node2* next;
	Buket* buket;
};

class Cvecara {
public:
	Cvecara();
	void addBouquet(Buket* b);
	void sellBouquet(int pos);
	friend ostream& operator<<(ostream& os, const Cvecara& c);
	Cvecara(const Cvecara& cv);
	Cvecara& operator=(const Cvecara& cv);
	Cvecara(Cvecara&& cv);
	Cvecara& operator=(Cvecara&& cv);
	~Cvecara();
private:
	int profit;
	void copy(const Cvecara& cv);
	void move(Cvecara& cv);
	void brisi();
	Node2* first = nullptr;

};

#endif

