#ifndef _CREATURE_
#define _CREATURE_

#include "entity.h"

class creature : public entity
{
public:
	entity* creature_room;
	creature(const char* nam, const char* des, entity* initial_room) : entity(nam, des), creature_room(initial_room){}

	
};


#endif