#ifndef _buket_h
#define _buket_h
#include "cvet.h"
#include <iostream>
#include <ostream>
using namespace std;

struct Node {
	struct Node* next;
	Cvet* cvet;
};

class Buket {
public:
	Buket() = default;
	void addFlower(Cvet* c);
	int totalBuying() const;
	int totalSelling() const;
	int profit() const;
	friend bool operator>(const Buket& b1, const Buket& b2);
	friend ostream& operator<<(ostream& os, const Buket& b);
	Buket(const Buket& b);
	Buket& operator=(const Buket& b);
	Buket(Buket&& b);
	~Buket();
	Buket& operator=(Buket&& b);
	
private:
	Node* first = nullptr, * last = nullptr;
	void brisi();
	void copy(const Buket& b);
	void move(Buket& b);
};


#endif

