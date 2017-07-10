#include <iostream>
#include <fstream>
#include "Bucket.h"

Bucket::Bucket()
{
	ownerName = NULL;
	eggs = NULL;
	size = 0;
	capacity = 0;
}

Bucket::Bucket(const Bucket& other)
{
	copy(other);
}

Bucket& Bucket::operator=(const Bucket& other)
{
	if (this != &other)
	{
		delete[] ownerName;
		delete[] eggs;
		copy(other);
	}
	return *this;
}

Egg& Bucket::operator[](int index)
{
	if (index > size)
	{
		std::cout << "Index out of range!";
	}
	return eggs[index];
}

Egg& Bucket::operator[](char* name)
{
	Egg egg;
	for (int i = 0; i < size; i++)
		if ((strcmp(eggs[i].getEggName(), name)) == 0)
			return eggs[i];
	return egg;
}

Bucket & Bucket::operator+=(const Bucket & rhs)
{
	int newSize = size + rhs.size;
	int newCap = newSize * 2;

	Egg* tmp = new Egg[size];

	for (int i = 0; i < size; i++)
		tmp[i] = eggs[i];

	delete[] eggs;

	eggs = new Egg[newCap];

	for (int i = 0; i < size; i++)
		eggs[i] = tmp[i];
	for (int i = size, j = 0; i < newSize, j < rhs.size; i++, j++)
		eggs[i] = rhs.eggs[j];

	size = newSize;
	capacity = newCap;

	return*this;
}

char* operator+=(const Bucket& lhs, char * str)
{
	int strSize = 0;
	for (int i = 0; i < lhs.getSize(); i++)
		strSize += strlen(lhs.getEggByIndex(i).getEggName());

	str = new char[strSize + 1];
	strcpy(str, lhs.getEggByIndex(0).getEggName());

	for (int i = 1; i < lhs.getSize(); i++)
		strcat(str, lhs.getEggByIndex(i).getEggName());
	return str;
}

const char* operator+(const Bucket& lhs, char* str)
{
	return Bucket(lhs) += str;
}

const Bucket operator+(const Bucket& lhs, const Bucket& rhs)
{
	return Bucket(lhs) += rhs;
}

Bucket& Bucket::operator*=(int num)
{
	for (int i = 0; i < size; i++)
	{
		eggs[i] *= num;
	}

	return *this;
}

const Bucket operator*(const Bucket& rhs, const int num)
{
	return Bucket(rhs) *= num;
}

Bucket& Bucket::operator/=(int num)
{
	for (int i = 0; i < size; i++)
	{
		eggs[i] /= num;
	}

	return *this;
}

Bucket & Bucket::operator%=(const Bucket & rhs)
{
	Egg* intersection = new Egg[size > rhs.size ? size : rhs.size];
	int cntEggs = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < rhs.size;j++)
			if (strcmp(eggs[i].getEggName(), rhs.eggs[j].getEggName()) == 0 && eggs[i].getEggSize() == rhs.eggs[j].getEggSize())
			{
				intersection[cntEggs] = eggs[i];
				cntEggs++;
			}
	}
	delete[] eggs;
	eggs = new Egg[cntEggs];
	for (int i = 0; i < cntEggs; i++)
		eggs[i] = intersection[i];

	size = cntEggs;
	capacity = size * 2;

	return *this;
}

const Bucket operator%(const Bucket& lhs, const Bucket& rhs)
{
	return Bucket(lhs) %= rhs;
}

const Bucket operator/(const Bucket& lhs, const int num)
{
	return Bucket(lhs) /= num;
}

bool operator==(const Bucket& lhs, const Bucket& rhs)
{
	if (lhs.size != rhs.size)
		return false;

	for (int i = 0; i < lhs.size; i++)
		if (lhs.eggs[i] != rhs.eggs[i])
			return false;
	return true;
}

bool operator<(const Bucket& lhs, const Bucket& rhs)
{
	if (lhs.size > rhs.size)
		return false;
	else if (lhs.size < rhs.size)
		return true;

	for (int i = 0; i < lhs.size; i++)
		if (lhs.eggs[i]>rhs.eggs[i])
			return false;

	return true;
}

bool operator>(const Bucket& lhs, const Bucket& rhs)
{
	return !(lhs < rhs);
}

bool operator<=(const Bucket& lhs, const Bucket& rhs)
{
	return !(lhs > rhs) || (lhs == rhs);
}

bool operator>=(const Bucket& lhs, const Bucket& rhs)
{
	return !(lhs < rhs) || (lhs == rhs);
}

bool Bucket::operator!=(const Bucket& other)
{
	if (size != other.size)
		return true;

	int cnt = 0;
	for (int i = 0; i < size; i++)
		if (eggs[i] != other.eggs[i])
			cnt++;
	if (cnt == 0)
		return false;
	return true;
}

Bucket::~Bucket()
{
	delete[] ownerName;
	delete[] eggs;
}

void Bucket::resizeBucket(int newCapacity)
{
	if (!eggs || newCapacity == 1)
		eggs = new Egg[newCapacity];
	else
	{
		Egg* tmp = new Egg[size];
		for (int i = 0; i < size; i++)
			tmp[i] = eggs[i];
		delete[] eggs;

		eggs = new Egg[newCapacity];
		for (int i = 0; i < size; i++)
			eggs[i] = tmp[i];
		delete[] tmp;
	}
}

void Bucket::shrinkBucket(int shrinkWith)
{
	Egg* tmp = new Egg[size];
	for (int i = 0; i < size; i++)
		tmp[i] = eggs[i];
	delete[] eggs;

	capacity -= shrinkWith;
	eggs = new Egg[capacity];
	for (int i = 0; i < size; i++)
		eggs[i] = tmp[i];
	delete[] tmp;
}

void Bucket::addEgg(Egg newEgg)
{
	if (size == capacity)
	{
		if (size == 0)
			capacity = 1;
		else
			capacity = size * 2;
		resizeBucket(capacity);
	}
	size++;
	eggs[size - 1] = newEgg;
}

void Bucket::removeEgg(char* description)
{
	int index = getIndex(description);
	if (index >= 0)
	{
		for (int i = index; i < size-1; i++)
			eggs[i] = eggs[i + 1];
		size--;
		if (capacity > size * 2)
		{
			shrinkBucket(capacity - size * 2);
		}
	}
	else
		std::cout << "Wrong description!" << std::endl;
}

void Bucket::setOwnerName(char* name)
{
	if (ownerName)
		delete[] ownerName;
	ownerName = new char[strlen(name) + 1];
	strcpy(ownerName, name);
}

void Bucket::setEggs(Egg* other, int cntEggs)
{
	if (eggs)
		delete[] eggs;
	eggs = new Egg[cntEggs];
	for (int i = 0; i < cntEggs; i++)
		eggs[i] = other[i];
}

void Bucket::setSize(int newSize)
{
	size = newSize;
}

void Bucket::setCapacity(int newCap)
{
	capacity = newCap;
}

void Bucket::setEgg(Egg& cur, char* eggName, int eggSize)
{
	cur.setEggName(eggName);
	cur.setEggSize(eggSize);
}

int Bucket::getIndex(char* dsc) const
{
	for (int i = 0; i < size; i++)
		if ((strcmp(eggs[i].getEggName(), dsc)) == 0)
			return i;

	return -1;
}

char* Bucket::getOwnerName() const
{
	return ownerName;
}

int Bucket::getSize() const
{
	return size;
}

int Bucket::getCapacity() const
{
	return capacity;
}

void Bucket::copy(const Bucket& other)
{
	ownerName = new char[strlen(other.ownerName) + 1];
	strcpy(ownerName, other.ownerName);
	eggs = new Egg[other.capacity];
	for (int i = 0; i < other.size; i++)
		eggs[i] = other.eggs[i];
	size = other.size;
	capacity = other.capacity;
}

Egg& Bucket::getEggByIndex(int index) const
{
	return eggs[index];
}

void Bucket::serializeBucket()
{
	std::ofstream serFile;
	char* fileName = new char[MAX_NAME_SIZE];
	strcpy(fileName, ownerName);
	strcat(fileName, ".dat");
	
	serFile.open(fileName, std::ios::out | std::ios::binary | std::ios::app);
	if (serFile.is_open())
	{
		int lenOfBucketName = strlen(ownerName) + 1;
		serFile.write((char*)&lenOfBucketName, sizeof(int));
		serFile.write(ownerName, lenOfBucketName*sizeof(char));
		serFile.write((char*)&size, sizeof(int));
		serFile.write((char*)&capacity, sizeof(int));
		for (int i = 0; i < size; i++)
			eggs[i].serializeEgg(serFile);
	}
	serFile.close();
}

void Bucket::deserializeBucket(char* bucketName)
{
	std::ifstream deserFile;
	int lenofBucketName = 0;
	char* fileName = new char[MAX_NAME_SIZE];
	strcpy(fileName, bucketName);
	strcat(fileName, ".dat");

	deserFile.open(fileName, std::ios::in | std::ios::binary);
	if (deserFile.is_open())
	{
		deserFile.read((char*)&lenofBucketName, sizeof(int));
		ownerName = new char[lenofBucketName];
		deserFile.read(ownerName, lenofBucketName*sizeof(char));
		deserFile.read((char*)&size, sizeof(int));
		deserFile.read((char*)&capacity, sizeof(int));
		eggs = new Egg[capacity];
		for (int i = 0; i < size; i++)
			eggs[i].deserializeEgg(deserFile);
	}
	deserFile.close();
}


void Bucket::report()
{
	char report[MAX_OWNER_NAME];
	strcpy(report, "report_");
	strcat(report, ownerName);
	strcat(report, ".txt");
	std::ofstream reportFile;
	reportFile.open(report, std::ios::out);

	reportFile << "This is a report file for: " << ownerName;
	reportFile << std::endl << "This bucket has: " << size << " eggs";
	reportFile << std::endl;

	for (int i = 0; i < size; i++)
	{
		reportFile << "Name: " << eggs[i].getEggName()<< " Size: "
			<< eggs[i].getEggSize() << std::endl;
	}
	reportFile.close();
}