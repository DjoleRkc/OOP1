#pragma once
#include <iostream>
using namespace std;
class Vreme
{
	int sat, min;
public:
	Vreme() = default;
	Vreme(int s, int m) { sat = s; min = m; }
	bool operator>(const Vreme& v) const;
	Vreme operator+(const Vreme& v) const;
	friend ostream& operator<<(ostream& os, const Vreme& v);
};

