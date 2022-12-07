#ifndef _spil_h
#define _spil_h
#include <string>
#include <iostream>
#include <ostream>
#include "stamparija.h"
using namespace std;

struct Node {
	Slicica* s;
	Node* next;
};

class Spil {
public:
	Spil()=default;
	void operator+=(Slicica* s);
	bool operator%(int number);
	void setCurrent();
	void moveCurrent();
	bool isEnd();
	Slicica* getCurrent();
	Node* removeSlicica(int num);
	Spil(const Spil& s) = delete;
	Spil& operator=(const Spil& s) = delete;
	friend ostream& operator<<(ostream& os, const Spil& sp);
	friend class Tapkaros;
	~Spil();
	
private:
	Node* first = nullptr;
	Node* last = nullptr;
	Node* current = nullptr;
	void brisi();
	
};



#endif

