#pragma once
#include <iostream>
#include <string>
using namespace std;
class Skup
{
	string str;
public:
	Skup(string s);
	Skup(const Skup&) = delete;
	Skup& operator=(const Skup&) = delete;
	bool operator()(char c) const;
	Skup& operator+=(char c);
	string getStr() const { return str; }
};


