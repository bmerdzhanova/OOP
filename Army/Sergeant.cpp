#include "Sergeant.h"
#include <iostream>

Sergeant::Sergeant() : squadDescr(nullptr), squad(nullptr), cntSoldiers(0)
{
	/*...*/
}

Sergeant::Sergeant(const Sergeant & other)
{
	Soldier::copy(other);
	copy(other);
}

Sergeant & Sergeant::operator=(const Sergeant & other)
{
	if (this != &other)
	{
		delete[] squadDescr;
		delete[] squad;
		Soldier::operator=(other);
		copy(other);
	}
	return *this;
}

Sergeant::~Sergeant()
{
	delete[] squadDescr;
	delete[] squad;
}

void Sergeant::setSquadDescr(char * dscr)
{
	squadDescr = new char[strlen(dscr) + 1];
	strcpy(squadDescr, dscr);
}

void Sergeant::setSquad(Soldier * newSquad, int cnt)
{
	squad = new Soldier[cnt];
	squad = newSquad;
	cntSoldiers = cnt;
}

void Sergeant::copy(const Sergeant & other)
{
	squadDescr = new char[strlen(other.squadDescr) + 1];
	strcpy(squadDescr, other.squadDescr);

	cntSoldiers = other.cntSoldiers;

	squad = new Soldier[cntSoldiers];
	squad = other.squad;
}
