
#ifndef _ITEMS_
#define _ITEMS_

#include "entity.h"
class Rooms;

class item : public entity
{
public:
	entity* craftable_item1;
	entity* craftable_item2;
	entity* item_room;
	bool dropped;
	bool picked;

public:

	item(const char* nam, const char* des, bool drop, entity* room, entity* craft_item, entity* craft_item2, TYPE type) : entity(nam, des), dropped(drop), item_room(room)
	{

		craftable_item1 = craft_item;
		craftable_item2 = craft_item2;
		entity_type = type;
		picked = false;
	}

	


};

#endif