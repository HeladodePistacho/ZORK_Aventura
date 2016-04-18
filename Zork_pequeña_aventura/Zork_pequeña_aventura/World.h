#ifndef CLASSANDFUNCTIONS
#define CLASSANDUNCTIONS

#include "Exits.h"
#include "Rooms.h"
#include "Player.h"
#include "dinamic_array.h"
#include "Box.h"

class entity;

class World
{
public:
	box* Box;
	Player* player;
	dynamic_array <Rooms*> world_rooms;
	dynamic_array <Exit*> world_exits;
	dynamic_array <item*> world_items;
	dynamic_array <char*> comands;
	dynamic_array <char*> directions;

public:

	World()
	{
		CreateWorld();
	}
	~World()
	{
		delete player;
		delete Box;
		for (int i = world_items.get_size() - 1; i > 0; i--)
		{
			delete world_items[i];
		}
		world_items.clean();

		for (int i = world_rooms.get_size() - 1; i > 0; i--)
		{
			delete world_rooms[i];
		}

		world_rooms.clean();

		for (int i = world_exits.get_size() - 1; i > 0; i--)
		{
			delete world_exits[i];
		}
		world_exits.clean();
	}



	void CreateWorld();
	bool finish_game(const dynamic_array<char*>&);
	void action(const dynamic_array<char*>&);
};






#endif