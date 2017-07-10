#ifndef SERGEANT_HEADER_INCLUDED
#define SERGEANT_HEADER_INCLUDED
#include "Soldier.h"

class Sergeant :public Soldier
{
private:
	char* squadDescr;
	Soldier* squad;
	int cntSoldiers;
public:
	Sergeant();
	Sergeant(const Sergeant&);
	Sergeant& operator=(const Sergeant&);
	~Sergeant();

	void setSquadDescr(char*);
	void setSquad(Soldier*, int);
private:
	void copy(const Sergeant&);
};

#endif //SERGEANT_HEADER_INCLUDED