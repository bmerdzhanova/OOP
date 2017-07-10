#include "Mag.h"
#include <iostream>

Mag::Mag(): battalionDescr(nullptr), battalion(nullptr), battalionCnt(0), power(0), magicBook()
{
	/*...*/
}

Mag::Mag(const Mag &other)
{
	Soldier::copy(other);
	copy(other);
}

Mag & Mag::operator=(const Mag & other)
{
	if (this != &other)
	{
		delete[] battalionDescr;
		delete[] battalion;
		Soldier::operator=(other);
		copy(other);
	}
	return *this;
}

Mag::~Mag()
{
	delete[] battalionDescr;
	delete[] battalion;
}

void Mag::setBattalionDescr(char * descr)
{
	battalionDescr = new char[strlen(descr) + 1];
	strcpy(battalionDescr, descr);
}

void Mag::setBattalion(Sergeant * b, int cnt)
{
	battalion = new Sergeant[cnt];
	battalion = b;
	battalionCnt = cnt;
}

void Mag::setPower(int p)
{
	power = p;
}

void Mag::setMagicBook(const MagicBook & book)
{
	magicBook = book;
}

void Mag::useSpell(int page)
{
	if (magicBook.getSpell(page).getPower() > power)
		return;
	magicBook.useSpell(page);
}

void Mag::copy(const Mag & other)
{
	battalionDescr = new char[strlen(other.battalionDescr) + 1];
	strcpy(battalionDescr, other.battalionDescr);

	battalion = new Sergeant[other.battalionCnt];
	for (int i = 0; i < other.battalionCnt; i++)
		battalion[i] = other.battalion[i];

	battalionCnt = other.battalionCnt;
	power = other.power;

	magicBook = other.magicBook;
}
