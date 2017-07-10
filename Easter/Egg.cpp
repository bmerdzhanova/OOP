#include <iostream>
#include <fstream>
#include "Egg.h"


Egg::Egg()
{
	eggName = NULL;
	eggSize = 0;
}

Egg::Egg(const Egg& other)
{
	copy(other);
}

Egg & Egg::operator*=(int num)
{
	eggSize *= num;
	return *this;
}

const Egg operator*(const Egg& lhs, int num)
{
	return Egg(lhs) *= num;
}

Egg & Egg::operator/=(int num)
{
	eggSize /= num;
	return *this;
}

const Egg operator/(const Egg& lhs, int num)
{
	return Egg(lhs) /= num;
}
Egg& Egg::operator=(const Egg& other)
{
	if (this != &other)
	{
		delete[] eggName;
		copy(other);
	}
	return *this;
}

bool Egg::operator!=(const Egg& other)
{
	if ((strcmp(eggName, other.eggName)) != 0 || eggSize != other.eggSize)
		return true;
	return false;
}

bool operator==(const Egg& lhs, const Egg& rhs)
{
	int size1 = strlen(lhs.eggName), size2 = strlen(rhs.eggName);

	if (size1 != size2)
		return false;

	for (int i = 0; i < size1; i++)
		if (lhs.eggName[i] != rhs.eggName[i])
			return false;

	return true;
}

bool operator<(const Egg& lhs, const Egg& rhs)
{
	int size1 = strlen(lhs.eggName), size2 = strlen(rhs.eggName);

	if (size1 > size2)
		return false;
	else if (size1 < size2)
		return true;

	for (int i = 0; i < size1; i++)
		if (lhs.eggName[i] > rhs.eggName[i])
			return false;

	return true;
}

bool operator>(const Egg& lhs, const Egg& rhs)
{
	return !(lhs < rhs);
}

bool operator<=(const Egg& lhs, const Egg& rhs)
{
	return !(lhs > rhs);
}

bool operator>=(const Egg& lhs, const Egg& rhs)
{
	return !(lhs < rhs);
}

Egg::~Egg()
{
	delete[] eggName;
}

void Egg::setEggName(char* newName)
{
	eggName = new char[strlen(newName) + 1];
	strcpy(eggName, newName);
}

void Egg::setEggSize(int newSize)
{
	eggSize = newSize;
}

char* Egg::getEggName() const
{
	return eggName;
}

int Egg::getEggSize() const
{
	return eggSize;
}

void Egg::createEgg()
{
	char* newName = new char[MAX_NAME_SIZE];
	std::cin >> newName;
	setEggName(newName);
	std::cin >> eggSize;
}

void Egg::copy(const Egg& other)
{
	eggName = new char[strlen(other.eggName) + 1];
	strcpy(eggName, other.eggName);
	eggSize = other.eggSize;
}

void Egg::serializeEgg(std::ofstream& serFile)
{
	if (serFile.good())
	{
		int lenOfEggName = strlen(eggName) + 1;
		serFile.write((char*)&lenOfEggName, sizeof(int));
		serFile.write(eggName, lenOfEggName*sizeof(char));
		serFile.write((char*)&eggSize, sizeof(int));
	}
}

void Egg::deserializeEgg(std::ifstream& deserFile)
{
	int lenofEggName = 0;
	deserFile.read((char*)&lenofEggName, sizeof(int));
	eggName = new char[lenofEggName];
	deserFile.read(eggName, lenofEggName*sizeof(char));
	deserFile.read((char*)&eggSize, sizeof(int));
}