#ifndef CLASSANDFUNCTIONS
#define CLASSANDUNCTIONS

#include "Exits.h"
#include "Rooms.h"
#include "Player.h"
#include "dinamic_array.h"

class entity;

class World
{
public:
	Player* player;
	dynamic_array <Rooms*> world_rooms;
	dynamic_array <Exit*> world_exits;
	dynamic_array <item*> world_items;

public:

	World()
	{
		
	}
	~World()
	{
		delete player;	
	}
	void CreateWorld();
	bool finish_game(const char first_word[]);
	void action(const char first_word[], const char second_word[], Player* player, Rooms* actualroom, Exit* exits);
};






#endif