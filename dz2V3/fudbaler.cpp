#include "fudbaler.h"

Fudbaler::Fudbaler(string name, string nationalTeam, Position pos)
{
	this->name = name;
	this->nationalTeam = nationalTeam;
	this->pos = pos;
}


Position Fudbaler::getPosition() const
{
	return pos;
}

void Fudbaler::changePos(Position changedPos)
{
	if (changedPos > 3) return;
	pos = changedPos;
}

ostream& operator<<(ostream& os, const Fudbaler& f)
{
	os << f.name<<"(";
	switch (f.pos)
	{
	case 0:
		os << "GK";
		break;
	case 1:
		os << "DEF";
		break;
	case 2:
		os << "MID";
		break;
	case 3:
		os << "FWD";
		break;
	}
	os << ") : ";
	os<< f.nationalTeam << endl;
	return os;
}
