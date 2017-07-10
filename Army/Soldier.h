#ifndef SOLDIER_HEADER_INCLUDED
#define SOLDIER_HEADER_INCLUDED

class Soldier
{
private:
	char* name;
	int age;
	int level;
	int salary;
public:
	Soldier();
	Soldier(const Soldier&);
	Soldier& operator=(const Soldier&);
	~Soldier();

	void setName(char*);
	void setAge(int);
	void setLevel(int);
	void setSalary(int);
protected:
	void copy(const Soldier&);
};

#endif //SOLDIER_HEADER_INCLUDED