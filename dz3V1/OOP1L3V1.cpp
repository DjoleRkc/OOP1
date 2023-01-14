// OOP1L3V1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Skup.h"
#include "Rec.h"
#include "Stih.h"
#include "Strofa.h"
#include "Katren.h"
using namespace std;

int main()
{
    try {
        Katren *k = new Katren();
        Katren k2();
        Rec r("Pera");
        Rec r2("igra");
        Rec r3("fudbal");
        Rec r4("Marko");
        Rec r5("igra");
        Rec r6("basket");
        Rec r7("Lana");
        Rec r8("igra");
        Rec r9("Kolo");
        Stih s, s2, s3, s4, s5;
        s += r;
        s += r2;
        s += r3;
        s2 += r4;
        s2 += r5;
        s2 += r6;
        s4 += r7;
        s4 += r8;
        //cin >> s5;
        (*k) += s;
        (*k) += s2;
        //(*k) += s3;
        (*k) += s4;
        cout << *k;
    }
    catch (exception e) { cout << e.what(); }
    

    //cin >> r;
    
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
