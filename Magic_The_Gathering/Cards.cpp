#include "Cards.hpp"
#include <iostream>
#include <fstream>

void setCardName(Cards& cur, char cardName[])
{
	if (strlen(cardName) <= MAX_SIZE_CARD_NAME)
		strcpy(cur.cardName, cardName);
	else
		return;
}

void createCard(Cards& cur)
{
	char name[MAX_SIZE_CARD_NAME];
	char color[20];
	std::cin >> color;
	Color curColor;
	std::cin.ignore();
	std::cin.getline(name, MAX_SIZE_CARD_NAME);
	if ((strcmp(color, "Red")) == 0)
		curColor = Red;
	else if ((strcmp(color, "Black")) == 0)
		curColor = Black;
	else if ((strcmp(color, "Blue")) == 0)
		curColor = Blue;
	else if ((strcmp(color, "White")) == 0)
		curColor = White;
	else if ((strcmp(color, "Green")) == 0)
		curColor = Green;
	cur.cardColor = curColor;
	setCardName(cur, name);
	cur.cardID = getID();
	cur.cntOccur = 0;
	std::cout << ">Card " << name << "crated " << std::endl;
}


int checkForCard(Cards* cards, char* name, int cntCards)
{
	for (int i = 0; i < cntCards; i++)
	{
		if ((strcmp(cards[i].cardName, name)) == 0)
			return i;
	}
	return -1;
}

void loadCardsToFile(Cards* card, int cntCards)
{
	std::ofstream cardsFile;
	cardsFile.open("cards.dat", std::ios::out | std::ios::binary | std::ios::app);
	if (cardsFile.is_open())
	{
		for (int i = 0; i < cntCards; i++)
		{
			cardsFile.write((const char*)&card[i].cardID, sizeof(unsigned short));
			cardsFile.write((const char*)&card[i].cardColor, sizeof(card[i].cardColor));
			cardsFile.write((const char*)&card[i].cardName, sizeof(card[i].cardName));
			cardsFile.write((const char*)&card[i].cntOccur, sizeof(int));
		}
	}
	else
		std::cout << "Error!" << std::endl;
	cardsFile.close();
}

void loadCardsFromFile(Cards*& cards)
{
	std::ifstream cardsFile;
	int cnt = 0;
	cardsFile.open("cards.dat", std::ios::in | std::ios::binary);
	if (cardsFile.is_open())
	{
		while (!cardsFile.eof())
		{
			cardsFile.read((char*)&cards[cnt].cardID, sizeof(unsigned short));
			cardsFile.read((char*)&cards[cnt].cardColor, sizeof(cards[cnt].cardColor));
			cardsFile.read((char*)&cards[cnt].cardName, sizeof(cards[cnt].cardName));
			cardsFile.read((char*)&cards[cnt].cntOccur, sizeof(int));
			cnt++;
		}
	}
	cardsFile.close();
}