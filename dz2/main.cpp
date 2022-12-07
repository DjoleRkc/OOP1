#include "cvet.h"
#include"buket.h"
#include "cvecara.h"
#include <iostream>
#include <ostream>
using namespace std;

int main() {
	Cvet* c1 = new Cvet("Ruza", 20, 23000);
	Cvet* c2 = new Cvet("Karanfil", 20, 28);
	Cvet* c3 = new Cvet("Koka", 21, 134);
	Cvet* c4 = new Cvet("Suncokret", 11, 222);
	Cvet* c5 = new Cvet("Bela Koka", 21, 100);
	Cvet* c6 = new Cvet("Beli Suncokret", 11, 200);
	Buket* b1 = new Buket;
	Buket* b2 = new Buket;
	Buket* b3 = new Buket;
	b1->addFlower(c1);
	b1->addFlower(c2);
	b2->addFlower(c3);
	b2->addFlower(c4);
	b3->addFlower(c5);
	b3->addFlower(c6);
	Cvecara* cv = new Cvecara();
	cv->addBouquet(b1);
	cv->addBouquet(b2);
	cv->addBouquet(b3);
	cout << *cv<<endl;
	cv->sellBouquet(2);
	cout << *cv<<endl;

}