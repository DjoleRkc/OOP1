#ifndef _fudbaler_h
#define _fudbaler_h
#include <iostream>
#include <string>
using namespace std;

enum Position { GK, DEF, MID, FWD };

class Fudbaler {
public:
	Fudbaler(string name, string nationalTeam, Position pos);
	string getName() const { return name; }
	string getNationalTeam() const { return nationalTeam; }
	Position getPosition() const;
	void changePos(Position changedPos);
	friend ostream& operator<<(ostream& os, const Fudbaler& f);
	Fudbaler& operator=(const Fudbaler& f)=delete;
	Fudbaler(const Fudbaler& f) = delete;
	friend class Svetsko;
	
private:
	
	string name, nationalTeam;
	Position pos;
	
};


#endif

