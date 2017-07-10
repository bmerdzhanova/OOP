#include "Decks.hpp"
#include "Player.hpp"
#include <iostream>
#include <fstream>

void createDeck(Decks& newDeck, Player* players, Cards* cards, int cntPlayers, int cntCards)
{
	char playerName[MAX_SIZE_PLAYER_NAME];
	Cards deckCards[DECK_SIZE];
	int index;
	unsigned short playerID;
	do
	{
		std::cin.ignore();
		std::cin.getline(playerName, MAX_SIZE_PLAYER_NAME);
		playerID = checkForPlayer(players, playerName, cntPlayers);
		if (playerID >= 0)
			newDeck.plID = playerID;
	} while (playerID < 0);

	for (int i = 0; i < DECK_SIZE; i++)
	{
		do
		{
			char cardName[MAX_SIZE_CARD_NAME];
			//std::cin.ignore();
			std::cin.getline(cardName, MAX_SIZE_CARD_NAME);
			index = checkForCard(cards, cardName, cntCards);
			if (index >= 0)
			{
				newDeck.cID[i] = cards[index].cardID;
				deckCards[i].cardColor = cards[index].cardColor;
				deckCards[i].cardID = cards[index].cardID;
				cards[index].cntOccur++;
				strcpy(deckCards[i].cardName, cards[index].cardName);
			}
		} while (index < 0);
		newDeck.cID[i] = cards[i].cardID;
		deckCards[i].cardColor = cards[i].cardColor;
		deckCards[i].cardID = cards[i].cardID;
		strcpy(deckCards[i].cardName, cards[i].cardName);
	}

	newDeck.deckColor = determineColor(deckCards);
}

Color& determineColor(Cards cards[])
{
	int color[COLORS] = { 0,0,0,0,0 };

	for (int i = 0; i < DECK_SIZE; i++)
	{
		color[cards[i].cardColor]++;
	}

	int max = 0;
	for (int i = 0; i < COLORS; i++)
		if (color[max] < color[i])
			max = i;
	Color cur = (Color)max;
	return cur;
}

void loadDecksToFile(Decks* decks, int cntDecks)
{
	std::ofstream decksFile;
	decksFile.open("decks.dat", std::ios::out | std::ios::binary | std::ios::app);
	if (decksFile.is_open())
	{
		for (int i = 0; i < cntDecks; i++)
		{
			decksFile.write((const char*)&decks[i].plID, sizeof(unsigned short));
			decksFile.write((const char*)&decks[i].deckColor, sizeof(decks[i].deckColor));
			for (int j = 0; j < DECK_SIZE; j++)
				decksFile.write((const char*)&decks[i].cID[j], sizeof(unsigned short));
		}
	}
	decksFile.close();
}

void loadDecksFromFile(Decks*& decks)
{
	std::ifstream decksFile;
	int cnt = 0;
	decksFile.open("decks.dat", std::ios::in | std::ios::binary);
	if (decksFile.is_open())
	{
		while (!decksFile.eof())
		{
			decksFile.read((char*)&decks[cnt].plID, sizeof(unsigned short));
			decksFile.read((char*)&decks[cnt].deckColor, sizeof(Color));
			for (int j = 0; j < DECK_SIZE; j++)
				decksFile.read((char*)&decks[cnt].cID[j], sizeof(unsigned short));
		}
	}
	decksFile.close();
}
