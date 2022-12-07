#ifndef _utakmica_h
#define _utakmica_h
#include "sudija.h"
#include "fudbaler.h"
#include <iostream>
using namespace std;

struct Node3 {

};

class Utakmica {
public:
	Utakmica(string r1, string r2, int kolo, Sudija* s);
	bool getProgress() const;
	string getR1() const { return r1; }
	string getR2() const { return r2; }
	int getKolo() const { return kolo; }
	Sudija* getSudija() const { return s; }


private:
	bool inProgress = false;
	string r1, r2;
	int kolo;
	Sudija* s;

};
#endif // !_utakmica_h

