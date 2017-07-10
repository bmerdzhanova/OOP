#ifndef CARDS_HEADER_INCLUDED
#define CARDS_HEADER_INCLUDED
#include "ID.hpp"

const int MAX_SIZE_CARD_NAME = 64;
const int COLORS = 5;

enum Color
{
	Red,
	Black,
	Blue,
	White,
	Green
};

struct Cards
{
	char cardName[MAX_SIZE_CARD_NAME];
	Color cardColor;
	unsigned short cardID;
	int cntOccur;
};

void setCardName(Cards&, char[]);
void createCard(Cards&);
int checkForCard(Cards*, char*, int);
void loadCardsToFile(Cards*, int);
void loadCardsFromFile(Cards*&);

#endif //CARDS_HEADER_INCLUDED