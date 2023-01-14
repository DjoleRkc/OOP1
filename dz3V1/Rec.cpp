#include "Rec.h"

Rec::Rec(string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if ((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z')) rec += s[i];
	}
}

int Rec::operator~() const
{
	int brSlogova = 0;
	Skup samoglasnici("aeiouAEIOU");
	Skup sonanti("lnrLNR");
	for (int i = 0; i < rec.length(); i++)
	{
		if (samoglasnici(rec[i])) brSlogova++;
		else if (sonanti(rec[i])) {
			if (rec[i] == 'l' or rec[i] == 'L' or rec[i] == 'n' or rec[i] == 'N') {
				if (rec[i == rec.length() - 1 ? i : i + 1] != 'j' and (rec[i == rec.length() - 1 ? i : i + 1] != 'J') and !samoglasnici(rec[i == 0 ? i : i - 1]) and !samoglasnici(rec[i == rec.length() - 1 ? i : i + 1])) brSlogova++;
			}
			else {
				if (!samoglasnici(rec[i == 0 ? i : i - 1]) and !samoglasnici(rec[i == rec.length() - 1 ? i : i + 1])) brSlogova++;
			}
		}
	}
	return brSlogova;
}

int Rec::operator()(int n) const
{
	int brSlogova = 0;
	Skup samoglasnici("aeiouAEIOU");
	Skup sonanti("lnrLNR");
	if (n >= 0) {
		for (int i = 0; i < rec.length(); i++)
		{
			if (samoglasnici(rec[i])) brSlogova++;
			else if (sonanti(rec[i])) {
				if (rec[i] == 'l' or rec[i] == 'L' or rec[i] == 'n' or rec[i] == 'N') {
					if (rec[i == rec.length() - 1 ? i : i + 1] != 'j' and (rec[i == rec.length() - 1 ? i : i + 1] != 'J') and !samoglasnici(rec[i == 0 ? i : i - 1]) and !samoglasnici(rec[i == rec.length() - 1 ? i : i + 1])) brSlogova++;
				}
				else {
					if (!samoglasnici(rec[i == 0 ? i : i - 1]) and !samoglasnici(rec[i == rec.length() - 1 ? i : i + 1])) brSlogova++;
				}
			}
			if (brSlogova-1 == n)return i;
		}
	}
	else {
		for (int i = rec.length()-1; i >=0 ; i--)
		{
			if (samoglasnici(rec[i])) brSlogova++;
			else if (sonanti(rec[i])) {
				if (rec[i] == 'l' or rec[i] == 'L' or rec[i] == 'n' or rec[i] == 'N') {
					if (rec[i == rec.length() - 1 ? i : i + 1] != 'j' and (rec[i == rec.length() - 1 ? i : i + 1] != 'J') and !samoglasnici(rec[i == 0 ? i : i - 1]) and !samoglasnici(rec[i == rec.length() - 1 ? i : i + 1])) brSlogova++;
				}
				else {
					if (!samoglasnici(rec[i == 0 ? i : i - 1]) and !samoglasnici(rec[i == rec.length() - 1 ? i : i + 1])) brSlogova++;
				}
			}
			if (brSlogova == -n)return i;
		}
	}
	return -1;
}

bool Rec::operator^(const Rec &r) const
{
	int pocetak = 0, pocetak2=0;
	if ((*this)(-2) == -1 or r(-2) == -1) {
		pocetak = ((*this)(-1));
		pocetak2 = (r(-1));
	}
	else {
		pocetak = ((*this)(-2));
		pocetak2 = (r(-2));
	} 

	string sub1 = (*this).rec.substr(pocetak);
	string sub2 = r.rec.substr(pocetak2);
	return sub1 == sub2;

}

istream& operator>>(istream& is, Rec& r)
{
	string newWord;
	is >> newWord;
	r = Rec(newWord);
	return is;
}

ostream& operator<<(ostream& os, const Rec& r)
{
	return os << r.getRec();
}
