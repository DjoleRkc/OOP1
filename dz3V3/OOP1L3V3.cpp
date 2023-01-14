// OOP1L3V3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lista.h"
#include "Boja.h"
#include "Kugla.h"
#include "Ukras.h"
using namespace std;



int main()
{
    try {
        Lista<Ukras*> l;
        Boja b(255, 200, 100);
        Boja b2(200, 100, 10);
        Boja b4(49, 26, 12);
        Boja b3 = b + b2;
        Kugla *k1 = new Kugla(b, 100, Kugla::MALA);
        Kugla *k2 = new Kugla (b2, 1000, Kugla::SREDNJA);
        Kugla *k3 = new Kugla(b3, 520, Kugla::VELIKA);
        Kugla *k4 = new Kugla(b4, 127, Kugla::NAJVECA);
        l >>= k1;
        l >>= k2;
        l <<= k3;
        l <<= k4;
        l.setCurrToFirst();
        while (l.currExists()) {
            cout << *l.getCurr() << endl;
            l.moveCurr();
        }
    }
    catch (exception e) { cout << e.what(); }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
