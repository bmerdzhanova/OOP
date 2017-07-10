#ifndef DECKS_HEADER_INCLUDED
#define DECKS_HEADER_INCLUDED
#include "Cards.hpp"
#include "Player.hpp"

const int DECK_SIZE = 60;

struct Decks
{
	unsigned short plID;
	Color deckColor;
	unsigned short cID[DECK_SIZE];
};

void createDeck(Decks& newDeck, Player* players, Cards* cards, int cntPlayers, int cntCards);
Color& determineColor(Cards cards[]);
void loadDecksToFile(Decks*, int);
void loadDecksFromFile(Decks*&);
#endif //DECKS_HEADER_INCLUDED