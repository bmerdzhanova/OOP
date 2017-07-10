#include "ID.hpp"
#include <fstream>

void initialize(char* fileName)
{
	std::ifstream in;
	in.open(fileName);
	if (!in.is_open())
		ID = 0;
	else
		in >> ID;
	in.close();
}

void saveChanges(char* fileName)
{
	std::ofstream out(fileName);
	out << ID;
	out.close();
}

unsigned short getID()
{
	return ID++;
}