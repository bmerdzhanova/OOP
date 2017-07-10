#include "Player.hpp"
#include <iostream>
#include <fstream>


void setName(Player& cur, char playerName[])
{
	if (strlen(playerName) <= MAX_SIZE_PLAYER_NAME)
		strcpy(cur.name, playerName);
	else
		return;
}

void createPlayer(Player& cur)
{
	char playerName[MAX_SIZE_PLAYER_NAME];
	std::cin.ignore();
	std::cin.getline(playerName, MAX_SIZE_PLAYER_NAME);
	setName(cur, playerName);
	cur.playerID = getID();	
}

void loadPlayersToFile(Player* players, int cntPlayers)
{
	std::ofstream playerFile;
	playerFile.open("players.dat", std::ios::out | std::ios::binary | std::ios::app);
	if (playerFile.is_open())
	{
		for (int i = 0; i < cntPlayers; i++)
		{
			playerFile.write((const char*)&players[i].playerID, sizeof(unsigned short));
			playerFile.write((const char*)&players[i].name, sizeof(players[i].name));
		}
	}
	else
		std::cout << "Error!" << std::endl;
	playerFile.close();
}

void loadPlayersFromFile(Player*& players)
{
	std::ifstream playerFile;
	int cur = 0;
	playerFile.open("players.dat", std::ios::in | std::ios::binary);
	if (playerFile.is_open())
	{
		while (!playerFile.eof())
		{
			playerFile.read((char*)&players[cur].playerID, sizeof(unsigned short));
			playerFile.read((char*)&players[cur].name, sizeof(players[cur].name));
			cur++;
		}
	}
	playerFile.close();
}

unsigned short checkForPlayer(Player* players,char* name, int cntPlayers)
{
	for (int i = 0; i < cntPlayers; i++)
	{
		if ((strcmp(players[i].name, name) == 0))
			return players[i].playerID;
	}
	return -1;
}
