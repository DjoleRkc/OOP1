#ifndef _flota_h
#define _flota_h
#include "avion.h"

class Flota {
public:
	Flota(const char* naziv): naziv(string(naziv)) {}
	Flota(const string& naziv): naziv(naziv) {}
	Flota(const Flota&);
	Flota(Flota&&);
	~Flota();


	friend ostream& operator<< (ostream&, const Flota&);
	Flota& operator= (Flota f);

	Flota& dodaj(const Avion&);
	int getUkupanBrojAviona() const { return brojAviona; }
	int getUkupanBrojPutnika() const { return brojPutnika; }
	Avion& getNajveci() const { return *najveci; }

	friend void swap(Flota& f1, Flota f2);

private:
	string naziv;
	struct Node {
		Avion* info;
		struct Node* sl;
		Node(Avion& a): info(&a), sl(nullptr) {}
	};
	Node* head = nullptr, * tail = nullptr;
	int brojAviona = 0, brojPutnika = 0, maksBrojPutnika = 0;
	Avion* najveci = nullptr;

};


#endif