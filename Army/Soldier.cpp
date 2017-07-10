#include "Soldier.h"
#include <iostream>

Soldier::Soldier() : name(nullptr), age(0), level(0), salary(0)
{
	/*...*/
}

Soldier::Soldier(const Soldier & other)
{
	copy(other);
}

Soldier & Soldier::operator=(const Soldier & other)
{
	if (this != &other)
	{
		delete[] name;
		copy(other);
	}
	return *this;
}

Soldier::~Soldier()
{
	delete[] name;
}

void Soldier::setName(char * soldierName)
{
	name = new char[strlen(soldierName) + 1];
	strcpy(name, soldierName);
}

void Soldier::setAge(int soldierAge)
{
	age = soldierAge;
}

void Soldier::setLevel(int soldierLvl)
{
	level = soldierLvl;
}

void Soldier::setSalary(int soldierSalary)
{
	salary = soldierSalary;
}

void Soldier::copy(const Soldier & other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	age = other.age;

	level = other.level;

	salary = other.salary;
}
