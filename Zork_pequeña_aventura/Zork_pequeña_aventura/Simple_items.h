#ifndef _SIMPLE_ITEMS_
#define _SIMPLE_ITEMS_

#include "entity.h"
class composed_item;
class Rooms;

class simple_item : public item
{
public:

	item* craftable_item1;
	item* craftable_item2;

public:

	simple_item(const char* nam, const char* des, bool drop, Rooms* room, item* craft_item, item* craft_item2) : item(nam, des, drop, room)
	{

		craftable_item1 = craft_item;
		craftable_item2 = craft_item2;

		type = ITEM;
	}



};

#endif