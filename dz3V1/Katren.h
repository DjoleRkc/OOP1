#pragma once
#include "Strofa.h"
class Katren :public Strofa
{
public:
	Katren() : Strofa(4) {};
	bool operator*() const override;
	char getOznaka() const override { return 'K'; }
};

