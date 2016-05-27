#ifndef _BOX_H_
#define _BOX_H_

#include "entity.h"
#include "dinamic_array.h"

class Rooms;
class item;

class box : public entity
{
public:
	dynamic_array<item*> storage;
	Rooms* item_room;
public:

	box(const char* nam, const char* des, Rooms* room) : entity(nam, des) , item_room(room)
	{
		entity_type = ITEM;
	}
	


};

#endif