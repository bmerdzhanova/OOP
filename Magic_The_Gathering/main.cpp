#include <iostream>
#include <fstream>
#include "ID.hpp"
#include "Player.hpp"
#include "Cards.hpp"
#include "Decks.hpp"

const char* colors[COLORS] = { "Red", "Black", "Blue", "White", "Green" };

template <class T>
void resizeArr(T*& arr, int newSize, int& oldSize)
{
	if (!arr)
	{
		arr = new T[newSize];
		oldSize = newSize;
	}
	else
	{
		T* tmp = new T[oldSize];
		for (int i = 0; i < oldSize; i++)
			tmp[i] = arr[i];
		delete[] arr;
		arr = new T[newSize];
		for (int i = 0; i < oldSize; i++)
			arr[i] = tmp[i];
		delete[] tmp;
		oldSize = newSize;
	}
}

int determineSizeOfArr(char*fileName)
{
	std::ifstream file;
	int cnt = 0;
	file.open(fileName, std::ios::in | std::ios::binary);
	if (file.is_open())
	{
		file.seekg(0, std::ios::end);
		cnt = file.tellg();
		if ((strcmp(fileName, "players.dat")) == 0)
			cnt /= sizeof(Player);
		else if ((strcmp(fileName, "cards.dat")) == 0)
			cnt /= sizeof(Cards);
		else if ((strcmp(fileName, "decks.dat")) == 0)
			cnt /= sizeof(Decks);
		else
			std::cerr << "There is no such file!" << std::endl;
	}
	file.close();
	if (cnt == 0)
		return 1;
	return cnt;
}

void loadFiles(Player*& players, Cards*& cards, Decks*& decks)
{
	loadPlayersFromFile(players);
	loadCardsFromFile(cards);
	loadDecksFromFile(decks);
}

Cards getMostUsedCard(Cards* cards, int cntCards)
{
	int max = 0;
	for (int i = 1; i < cntCards; i++)
	{
		if (cards[max].cntOccur < cards[i].cntOccur)
			max = i;
	}
	return cards[max];
}

void generateReport(Decks* decks, Player* players, Cards* cards)
{
	std::ofstream reportFile;
	reportFile.open("report.txt", std::ios::out);
	if (reportFile.is_open())
	{
		for (int i = 0; i < COLORS; i++)
		{
			reportFile << colors[i];

		}
	}
	reportFile.close();
}


void mainLoop()
{
	Player* players = nullptr;
	int cntPlayers = 0;
	Cards* cards = nullptr;
	int cntCards = 0;
	Decks* decks = nullptr;
	int cntDecks = 0;
	char command[7];
	while (std::cin>>command)
	{
		if ((strcmp(command, "cp")) == 0)
		{
			resizeArr<Player>(players, cntPlayers + 1, cntPlayers);
			createPlayer(players[cntPlayers-1]);
		}
		else if ((strcmp(command, "cc")) == 0)
		{
			resizeArr<Cards>(cards, cntCards + 1, cntCards);
			createCard(cards[cntCards-1]);
		}
		else if ((strcmp(command, "cd")) == 0)
		{
			resizeArr<Decks>(decks, cntDecks + 1, cntDecks);
			createDeck(decks[cntDecks-1], players, cards, cntPlayers, cntCards);
		}
		else if ((strcmp(command, "report")) == 0)
		{
			generateReport(decks, players, cards);
		}
		else if ((strcmp(command, "quit")) == 0)
		{
			loadPlayersToFile(players, cntPlayers);
			loadCardsToFile(cards, cntCards);
			loadDecksToFile(decks, cntDecks);
			break;
		}
		else
		{
			std::cerr << "Wrong command! Please try again: ";
		}
	}
}


int main()
{
	mainLoop();
	return 0;
}