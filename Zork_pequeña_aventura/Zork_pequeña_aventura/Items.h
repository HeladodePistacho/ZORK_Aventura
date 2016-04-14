
#ifndef _ITEMS_
#define _ITEMS_

#include "entity.h"
class Rooms;

class item : public entity
{
public:
	Rooms* item_room;
	bool dropped;
public:

	item(const char* nam, const char* des, bool drop, Rooms* room) : entity(nam, des), dropped(drop), item_room(room)
	{
		type = ITEM;
	}



};

#endif