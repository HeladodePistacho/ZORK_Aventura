#ifndef CLASSANDFUNCTIONS
#define CLASSANDUNCTIONS

#include "Exits.h"
#include "Rooms.h"
#include "Player.h"



class World
{
public:
	Player* player;
	Rooms* rooms;
	Exit* exits;

public:

	World(){
		player = new Player;
		rooms = new Rooms[13];
		exits = new Exit[26];
	}
	~World(){
		delete player;
		delete[]rooms;
		delete[]exits;
	}
	void CreateWorld(Player&, Rooms[], Exit[]);
	bool finish_game(const char first_word[]);
	void action(const char first_word[], const char second_word[], Player* player, Rooms* actualroom, Exit* exits);
};






#endif