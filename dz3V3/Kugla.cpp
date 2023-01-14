#include "Kugla.h"
#include<iostream>
using namespace std;
void Kugla::ispisi(ostream& os) const
{
	switch(this->v){
	case 0:
		os << ".";
		break;
	case 1:
		os << "o";
		break;
	case 2:
		os << "O";
		break;
	case 3:
		os << "()";
	}
}
