#ifndef ROOMS
#define ROOMS

#include "entity.h"
#include "my_string.h"

class my_string;

class Rooms : public entity
{
public:

	Rooms(const char* nam, const char* des, entity* item_1, entity* item_2, entity* item_3 ) : entity(nam, des)
	{
		entity_type = ROOM;

		if (item_1 != nullptr)
			list.PushBack(item_1);

		if (item_2 != nullptr)
			list.PushBack(item_2);

		if (item_3 != nullptr)
			list.PushBack(item_3);
	}
	

};

#endif