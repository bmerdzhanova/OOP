#ifndef MAGICBOOK_HEADER_INCLUDED
#define MAGICBOOK_HEADER_INCLUDED
#include "Spell.h"

class MagicBook
{
private:
	Spell* book;
	int cntPages;
public:
	MagicBook();
	MagicBook(const MagicBook&);
	MagicBook& operator=(const MagicBook&);
	~MagicBook();

	void addSpell(const Spell&);
	void useSpell(const int);

	Spell& getSpell(int);
private:
	void copy(const MagicBook&);
};

#endif //MAGICBOOK_HEADER_INCLUDED