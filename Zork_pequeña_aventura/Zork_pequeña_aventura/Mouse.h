#ifndef _MOUSE_H_
#define _MOUSE_H_

#include "Creature.h"
#include "entity.h"
#include "dinamic_array.h"
#include <Windows.h>

class Mouse : public creature
{
public:
	dynamic_array<entity*> inventory;
	entity* last_room_visited;
	dynamic_array<entity*> ent;

	
	bool return_room = false;
	
public:

	Mouse(const char* nam, const char* des, entity* initial_room, dynamic_array<entity*> entities_vector) : creature(nam, des, initial_room), ent(entities_vector)
	{
		last_room_visited = nullptr;
		entity_type = CREATURE;
	}

	void Move();
	void pick();
	void drop();

	void Update()
	{
		if (inventory.get_size() == 0)
			pick();

		Move();

		if (inventory.get_size() > 0)
			drop();
	}

};

#endif