#include "Commander.h"
#include <iostream>

Commander::Commander(): armyDescr(nullptr), army(nullptr), cntArmy(0)
{
	/*...*/
}

Commander::Commander(const Commander & other)
{
	Soldier::copy(other);
	copy(other);
}

Commander & Commander::operator=(const Commander & other)
{
	if (this != &other)
	{
		delete[] armyDescr;
		delete[] army;
		Soldier::operator=(other);
		copy(other);
	}
	return *this;
}

Commander::~Commander()
{
	delete[] armyDescr;
	delete[] army;
}

void Commander::setArmyDescr(char * descr)
{
	armyDescr = new char[strlen(descr) + 1];
	strcpy(armyDescr, descr);
}

void Commander::setArmy(Mag * a, int cnt)
{
	army = new Mag[cnt];
	army = a;
	cntArmy = cnt;
}

void Commander::copy(const Commander & other)
{
	armyDescr = new char[strlen(other.armyDescr) + 1];
	strcpy(armyDescr, other.armyDescr);

	army = new Mag[other.cntArmy];
	army = other.army;

	cntArmy = other.cntArmy;
}
