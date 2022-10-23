#include "flota.h"

Flota::Flota(const Flota& f)
{
    naziv = f.naziv;
    brojAviona = f.brojAviona;
    brojPutnika = f.brojPutnika;
    maksBrojPutnika = f.maksBrojPutnika;
    najveci = f.najveci;
    if (f.head == nullptr) return;
    Node* tmp = f.head;
    while (tmp)
    {
        auto novi = new Node(*(tmp->info));
        if (head == nullptr) head = novi;
        else tail->sl = novi;
        tail = novi;
    }
}

Flota::Flota(Flota&& f)
{
    naziv = f.naziv;
    brojAviona = f.brojAviona;
    brojPutnika = f.brojPutnika;
    maksBrojPutnika = f.maksBrojPutnika;
    najveci = f.najveci;
    head = f.head;
    tail = f.tail;
    f.naziv = "";
    f.brojAviona = 0;
    f.brojPutnika = 0;
    f.maksBrojPutnika = 0;
    f.najveci = nullptr;
    f.head = nullptr;
    f.tail = nullptr;
}

Flota::~Flota()
{
    Node* tmp = head;
    while (tmp)
    {
        auto next = tmp->sl;
        delete tmp;
        tmp = next;
    }
}

Flota& Flota::operator=(Flota f)
{
    swap(*this, f);
    return *this;
}

Flota& Flota::dodaj(const Avion& avion)
{
    Node* novi = new Node(const_cast<Avion&>(avion));
    if (head == nullptr) head = novi;
    else tail->sl = novi;
    tail = novi;
    brojPutnika += avion.getBrPutnika();
    brojAviona++;
    if (avion.getBrPutnika() > maksBrojPutnika)
    {
        maksBrojPutnika = avion.getBrPutnika();
        najveci = &(const_cast<Avion&>(avion));
    }

    return *this;
}

ostream& operator<<(ostream& os, const Flota& f) 
{
    os << f.naziv << endl;
    Flota::Node* tmp = f.head;
    while (tmp)
    {
        os << *(tmp->info) << endl;
        tmp = tmp->sl;
    }
    return os;
}

void swap(Flota& f1, Flota f2)
{
    using std::swap;
    swap(f1.brojAviona, f2.brojAviona);
    swap(f1.brojPutnika, f2.brojPutnika);
    swap(f1.najveci, f2.najveci);
    swap(f1.maksBrojPutnika, f2.maksBrojPutnika);
    swap(f1.naziv, f2.naziv);
    swap(f1.head, f2.head);
    swap(f1.tail, f2.tail);
}
