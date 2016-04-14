
#ifndef _COMPOSED_ITEMS_
#define _COMPOSED_ITEMS_

#include "entity.h"
#include "Items.h"
#include "Simple_items.h"
#include "dinamic_array.h"

class simple_item;
class Rooms;

class composed_item : public item
{
public:
	bool fillable;
public:

	composed_item(const char* nam, const char* des, bool drop, Rooms* room, bool fill) : item(nam, des, drop, room), fillable(fill)
	{
		type = ITEM;
	}



};

#endif