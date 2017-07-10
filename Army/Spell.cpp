#include "Spell.h"
#include <iostream>

Spell::Spell() : spellDescr(nullptr), type(nullptr), power(0)
{
	/*...*/
}

Spell::Spell(const Spell & other)
{
	copy(other);
}

Spell & Spell::operator=(const Spell & other)
{
	if (this != &other)
	{
		delete[] spellDescr;
		delete[] type;
		copy(other);
	}
	return *this;
}

Spell::~Spell()
{
	delete[] spellDescr;
	delete[] type;
}

void Spell::setSpellDescr(char * descr)
{
	spellDescr = new char[strlen(descr) + 1];
	strcpy(spellDescr, descr);
}

void Spell::setType(char * t)
{
	type = new char[strlen(t) + 1];
	strcpy(type, t);
}

void Spell::setPower(int p)
{
	power = p;
}

int Spell::getPower() const
{
	return power;
}

void Spell::copy(const Spell & other)
{
	spellDescr = new char[strlen(other.spellDescr) + 1];
	strcpy(spellDescr, other.spellDescr);

	type = new char[strlen(other.type) + 1];
	strcpy(type, other.type);

	power = other.power;
}
