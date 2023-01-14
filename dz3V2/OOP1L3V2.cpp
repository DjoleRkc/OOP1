// OOP1L3V2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "lista.h"
#include "Vreme.h"
#include "Film.h"
#include "Domaci.h"
#include "Strani.h"
using namespace std;


int main()
{
    try {
        Lista<Vreme> l;
        Lista<Film*>lf;
        Vreme v1(5, 9);
        Vreme v2(6, 52);
        Vreme v3 = v1 + v2;
        l += v1;
        l += v2;
        l += v3;
        Domaci *d = new Domaci("Klopka", v1);
        Strani *s = new Strani("Terminator", v2, "Novi Zeland", Strani::SINHRONIZOVAN);
        lf += d;
        lf += s;
        (*s).oceni(7);
        (*s).oceni(9);
        for (int i = 0; i < lf.getNumOfElems(); i++) cout << *lf[i] << endl;
        
        /*cout << *s;*/
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
