#ifndef MAG_HEADER_INCLUDED
#define MAG_HEADER_INCLUDED

#include "Soldier.h"
#include "Sergeant.h"
#include "MagicBook.h"
class Mag :public Soldier
{
private:
	char* battalionDescr;
	Sergeant* battalion;
	int battalionCnt;
	int power;
	MagicBook magicBook;
public:
	Mag();
	Mag(const Mag&);
	Mag& operator=(const Mag&);
	~Mag();

	void setBattalionDescr(char*);
	void setBattalion(Sergeant*, int);
	void setPower(int);
	void setMagicBook(const MagicBook&);

	void useSpell(int);
private:
	void copy(const Mag&);
};

#endif //MAG_HEADER_INCLUDED