#ifndef SINGLETON_HEADER_INCLUDED
#define SINGLETON_HEADER_INCLUDED

#define _4MB 4194304

class Singleton
{
private:
	char data[_4MB];
public:
	Singleton& operator=(const Singleton&) = delete;
	Singleton(const Singleton&) = delete;
private:
	Singleton() {};
public:
	static Singleton& getInstance()
	{
		static Singleton instance;
		return instance;
	}
};

#endif //SINGLETON_HEADER_INCLUDED