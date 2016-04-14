#ifndef _SIMPLE_ITEMS_
#define _SIMPLE_ITEMS_

#include "entity.h"
class composed_item;
class Rooms;

class simple_item : public item
{
public:

	item* origin_item;
	item* craftable_item;

public:

	simple_item(const char* nam, const char* des, bool drop, Rooms* room, item* org_item, item* craft_item) : item(nam, des, drop, room), origin_item(org_item), craftable_item(craft_item)

	{
		type = ITEM;
	}



};

#endif