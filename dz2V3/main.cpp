
#include "fudbaler.h"
#include "pogodak.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Fudbaler* f1 = new Fudbaler("Ronaldo", "Portugal", MID);
	Fudbaler* f2 = new Fudbaler("Messi", "Argentina", FWD);
	Pogodak* p1 = new Pogodak(f1, 10);
	Pogodak* p2 = new Pogodak(f2, 20);
	cout << *p1 << *p2;
	
}
