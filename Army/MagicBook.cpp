#include "MagicBook.h"

MagicBook::MagicBook() : book(nullptr), cntPages(1)
{
	/*...*/
}

MagicBook::MagicBook(const MagicBook &other)
{
	copy(other);
}

MagicBook & MagicBook::operator=(const MagicBook & other)
{
	if (this != &other)
	{
		delete[] book;
		copy(other);
	}
	return *this;
}

MagicBook::~MagicBook()
{
	delete[] book;
}

void MagicBook::addSpell(const Spell & newSpell)
{
	Spell* tmp = new Spell[cntPages];
	if (book)
	{
		for (int i = 0; i < cntPages - 1;i++)
			tmp[i] = book[i];
		delete[] book;
	}

	book = new Spell[cntPages + 1];
	for (int i = 0; i < cntPages - 1;i++)
		book[i] = tmp[i];
	delete[] tmp;

	book[cntPages - 1] = newSpell;
	++cntPages;
}

void MagicBook::useSpell(const int page)
{
	Spell* tmp = new Spell[cntPages];
	--cntPages;

	for (int i = 0; i < page; i++)
		tmp[i] = book[i];

	for (int i = page + 1, j = page; i < cntPages - 1, j < cntPages - 1; i++, j++)
		tmp[j] = book[i];
	
	delete[] book;

	book = new Spell[cntPages];
	for (int i = 0; i < cntPages - 1; i++)
		book[i] = tmp[i];
	delete[] tmp;
}

Spell& MagicBook::getSpell(int page)
{
	return book[page];
}

void MagicBook::copy(const MagicBook & other)
{
	book = new Spell[other.cntPages];
	book = other.book;

	cntPages = other.cntPages;
}
