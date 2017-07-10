#ifndef BUCKET_HEADER_INCLUDED
#define BUCKET_HEADER_INCLUDED
#include "Egg.h"

const int MAX_OWNER_NAME = 200;

class Bucket
{
private:
	char* ownerName;
	Egg* eggs;
	int size;
	int capacity;
public:
	Bucket();
	Bucket(const Bucket&);
	Bucket& operator=(const Bucket&);
	Egg& operator[](int);
	Egg& operator[](char*);
	Bucket& operator+=(const Bucket&);
	Bucket& operator*=(int);
	Bucket& operator/=(int);
	Bucket& operator%=(const Bucket&); 
	friend bool operator==(const Bucket&, const Bucket&); 
	friend bool operator<(const Bucket&, const Bucket&);
	bool operator!=(const Bucket&); 
	~Bucket();

	void resizeBucket(int);
	void shrinkBucket(int);
	void addEgg(Egg);
	void removeEgg(char*);
	void serializeBucket();
	void deserializeBucket(char*);
	void report();

	void setOwnerName(char*);
	void setEggs(Egg*, int);
	void setSize(int);
	void setCapacity(int);
	void setEgg(Egg&, char*, int);

	char* getOwnerName() const;
	int getSize() const;
	int getCapacity() const;
	Egg& getEggByIndex(int) const;
private:
	void copy(const Bucket&);
	int getIndex(char*) const;
};

const Bucket operator+(const Bucket&, const Bucket&);
char* operator+=(const Bucket&, char*);
const char* operator+(const Bucket&, const char*);
const Bucket operator*(const Bucket&, const int);
const Bucket operator/(const Bucket&, const int);
const Bucket operator%(const Bucket&, const Bucket&);
bool operator>(const Bucket&, const Bucket&);
bool operator<=(const Bucket&, const Bucket&);
bool operator>=(const Bucket&, const Bucket&); 

#endif //BUCKET_HEADER_INCLUDED