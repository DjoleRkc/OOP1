#include "Stih.h"
#include "Rec.h"
#include <exception>
using namespace std;
class GVanOpsega : public exception {
public:
    GVanOpsega() :exception("Indeks je van opsega!") {}
};

Stih& Stih::operator+=(const Rec r)
{
    Node* tmp = new Node(r);
    if (!first)first = tmp;
    else last->next = tmp;
    last = tmp;
    return *this;
}

int Stih::operator+() const
{
    int brReci = 0;
    for (Node* curr = first; curr; curr = curr->next) brReci++;
    return brReci;
}

int Stih::operator~() const
{
    int brSlog = 0;
    for (Node* curr = first; curr; curr = curr->next) {
        brSlog += curr->r.operator~();
    }
    return brSlog;
}

Rec& Stih::operator[](int index) const
{
    Node* curr = first;
    if (index >= 0 and index < +(*this)) {
        for (size_t i = 0; i < index; i++) curr = curr->next;
    }
    else throw GVanOpsega();
    return curr->r;
}

void Stih::operator()(int index)
{
    Node* curr = first;
    Node* prev = nullptr;
    if (index >= 0) {
        for (size_t i = 0; i < index; i++) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == last)last = prev;
        if (!prev) first = curr->next;
        else prev->next = curr->next;
        delete curr;
    }
    else throw GVanOpsega();
}

void Stih::operator()(const Rec& r, int index)
{
    Node* prev = nullptr, *curr=first;
    for (size_t i = 0; i < index; i++) {
        prev = curr;
        curr = curr->next;
    }
    Node* tmp = new Node(r,curr);
    if (!prev) first = tmp;
    else prev->next = tmp;
}

bool Stih::operator^(const Stih &s) const
{
    int br1 = +(*this), br2= +s;
    Rec r1 = (*this)[br1-1], r2 = s[br2-1];
    return (r1 ^ r2);


}

Stih::Stih(const Stih& s)
{
    copy(s);
}

Stih::Stih(Stih&& s)
{
    move(s);
}

Stih& Stih::operator=(const Stih& s)
{
    if (this != &s) {
        brisi();
        copy(s);
    }
    return *this;
}

Stih& Stih::operator=(Stih&& s)
{
    if (this != &s) {
        brisi();
        move(s);
    }
    return *this;
}

void Stih::copy(const Stih& s)
{
    first = last = nullptr;
    for (Stih::Node* curr = s.first; curr; curr = curr->next) {
        Node* tmp = new Node(curr->r);
        if (!first)first = tmp;
        else last->next = tmp;
        last = tmp;
    }
}

void Stih::move(Stih& s)
{
    this->first = s.first;
    this->last = s.last;
    s.first = s.last = nullptr;
}

void Stih::brisi()
{
    for (Stih::Node* curr = first; curr;) {
        Node* old = curr;
        curr = curr->next;
        delete old;
    }
    first = last = nullptr;
}

Stih::~Stih()
{
    brisi();
}

istream& operator>>(istream& is, Stih& s)
{
    string st;
    string sub="n";
    
    getline(is,st);
    while(true){
        sub = st.substr(0, st.find(' '));
        Rec pom(sub);
        s += pom;
        if (st.find(' ') == std::string::npos) break;
        st = st.substr(st.find(' ') + 1);
    }
    return is;
}

ostream& operator<<(ostream& os, const Stih& s)
{
    for (Stih::Node* curr = s.first; curr; curr = curr->next) os << curr->r << " ";
    return os;
}
