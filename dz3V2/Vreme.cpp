#include "Vreme.h"
#include <iomanip>
using namespace std;
bool Vreme::operator>(const Vreme& v) const
{
    if (this->sat > v.sat) return true;
    else if (this->sat == v.sat) {
        if (this->min > v.min) return true;
        return false;
    }
    return false;
}

Vreme Vreme::operator+(const Vreme& v) const
{
    int satPom = this->sat + v.sat;
    int minPom = 0;
    if ((this->min + v.min) >= 60) {
        satPom++; 
        minPom = this->min + v.min - 60;
    }
    else minPom = this->min + v.min;

    Vreme v2(satPom, minPom);
    return v2;
}

ostream& operator<<(ostream& os, const Vreme& v)
{
    os << setw(2) << setfill('0');
    os << v.sat << ":";
    os << setw(2) << setfill('0');
    return os << v.min;
}
