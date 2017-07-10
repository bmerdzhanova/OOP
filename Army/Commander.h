#ifndef COMMANDER_HEADER_INCLUDED
#define COMMANDER_HEADER_INCLUDED
#include "Soldier.h"
#include "Mag.h"

class Commander :public Soldier
{
private:
	char* armyDescr;
	Mag* army;
	int cntArmy;
public:
	Commander();
	Commander(const Commander&);
	Commander& operator=(const Commander&);
	~Commander();

	void setArmyDescr(char*);
	void setArmy(Mag*, int);
private:
	void copy(const Commander&);
};

#endif //COMMANDER_HEADER_INCLUDED
