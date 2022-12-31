
#include <string>
#include <iostream>
#include <ostream>
#include "slicica.h"
#include "stamparija.h"
#include "spil.h"
using namespace std;

int Slicica::i = 1;
int main() {
	Stamparija st(new string[3]{ "Pera", "Mika", "Zika" }, 3);
	Slicica* s1 = st.makeSlicica(0);
	Slicica* s2 = st.makeSlicica(1);
	Slicica* s3 = st.makeSlicica(2);
	Spil sp;
	sp += s1;
	sp += s2;
	sp += s3;
	cout << sp << endl;
	sp.setCurrent();
	while (!sp.isEnd()) {
		cout << *sp.getCurrent()<< endl;
		sp.moveCurrent();
	}
	sp.removeSlicica(2);
	cout <<endl<< sp << endl;
	cout<< sp % 2<<endl;
	cout << sp % 1;
}
