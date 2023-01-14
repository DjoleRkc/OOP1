#include "Skup.h"

Skup::Skup(string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if ((*this)(s[i])) continue;
		this->str += s[i];
	}
}

bool Skup::operator()(char c) const
{
	for (size_t i = 0; i < this->str.length(); i++)
	{
		if (c == this->str[i]) return true;
	}
	return false;
}

Skup& Skup::operator+=(char c)
{
	if ((*this)(c)) return *this;
	this->str += c;
	return *this;
}
