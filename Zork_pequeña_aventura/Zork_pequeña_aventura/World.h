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

	 
	dynamic_array <entity*> entities;
	Player* player;

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
		
		for (int i = entities.get_size() - 1; i > 0; i--)
		{
			delete entities[i];
		}
		entities.clean();

		
	}



	void CreateWorld();
	bool finish_game(const dynamic_array<char*>&);
	void action(const dynamic_array<char*>&);
};






#endif