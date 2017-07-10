#ifndef PLAYER_HEADER_INCLUDED
#define PLAYER_HEADER_INCLUDED
#include "ID.hpp"

const int MAX_SIZE_PLAYER_NAME = 128;

struct Player
{
	char name[MAX_SIZE_PLAYER_NAME];
	unsigned short playerID;
};

void setName(Player&, char*);
void resizePlayerArr(Player*&, int, int&);
void createPlayer(Player&);
void loadPlayersToFile(Player*, int);
void loadPlayersFromFile(Player*&/*, int&*/);
unsigned short checkForPlayer(Player*, char*, int);
#endif //PLAYER_HEADER_INCLUDED