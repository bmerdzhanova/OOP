#ifndef EGGS_HEADER_INCLUDED
#define EGGS_HEADER_INCLUDED

const int MAX_NAME_SIZE = 200;

class Egg
{
private:
	char* eggName;
	int eggSize;
public:
	Egg();
	Egg(const Egg&);
	Egg& operator=(const Egg&);
	Egg& operator*=(int);
	Egg& operator/=(int);
	bool operator!=(const Egg&);
	friend bool operator==(const Egg&, const Egg&);
	friend bool operator<(const Egg&, const Egg&); 

	
	~Egg();

	void setEggName(char*);
	void setEggSize(int);
	char* getEggName() const;
	int getEggSize() const;

	void createEgg();
	void serializeEgg(std::ofstream&);
	void deserializeEgg(std::ifstream&);
private:
	void copy(const Egg&);
};

const Egg operator*(const Egg&, int);
const Egg operator/(const Egg&, int);
bool operator>(const Egg&, const Egg&);
bool operator<=(const Egg&, const Egg&);
bool operator>=(const Egg&, const Egg&);
#endif //EGGS_HEADER_INCLUDED