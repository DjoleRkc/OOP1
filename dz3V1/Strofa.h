#pragma once
#include "Stih.h"
class Strofa
{
protected:
	int kap, brElem = 0;
	Stih* nizStihova;
public:
	Strofa(const Strofa& s);
	Strofa(Strofa&& s);
	Strofa(int kapacitet) { nizStihova = new Stih[kapacitet]; kap = kapacitet; }
	int getKap() const { return kap; }
	Strofa& operator+=(const Stih& s);
	void operator-(){ if (brElem)brElem--; }
	int operator+() const { return brElem; }
	Stih& operator[](int ind) const { return this->nizStihova[ind]; }
	void operator()(int i, int j) { swap(this->nizStihova[i], this->nizStihova[j]); }
	virtual  bool operator*() const = 0;
	virtual char getOznaka() const = 0;
	friend ostream& operator<<(ostream& os, Strofa& s);
	Strofa& operator=(const Strofa& s);
	Strofa& operator=(Strofa&& s);
	~Strofa() { brisi(); }

private:
	void copy(const Strofa& s);
	void move(Strofa& s);
	void brisi();


};

