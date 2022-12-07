#ifndef _cvet_h
#define _cvet_h
#include <string.h>
#include <iostream>
using namespace std;

class Cvet {
public:
	Cvet(string name, int buyingPrice, int sellingPrice);
	string getName() const { return this->name; }
	int getBuying() const { return this->buyingPrice; }
	int getSelling() const { return this->seliingPrice; }
	int profit();
	friend  bool operator==(const Cvet& c1, const Cvet& c2);
	friend bool operator!=(const Cvet& c1, const Cvet& c2);
	friend ostream &operator<<(ostream& os, const Cvet& c1);
private:
	string name;
	int buyingPrice, seliingPrice;


};



#endif

