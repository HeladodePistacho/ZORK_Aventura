
#ifndef _ITEMS_
#define _ITEMS_

#include "entity.h"
class Rooms;

class item : public entity
{
public:
	item* craftable_item1;
	item* craftable_item2;
	Rooms* item_room;
	bool dropped;
	bool picked;

public:

	item(const char* nam, const char* des, bool drop, Rooms* room, item* craft_item, item* craft_item2) : entity(nam, des), dropped(drop), item_room(room)
	{

		craftable_item1 = craft_item;
		craftable_item2 = craft_item2;
		entity_type = ITEM;
		picked = false;
	}

	


};

#endif