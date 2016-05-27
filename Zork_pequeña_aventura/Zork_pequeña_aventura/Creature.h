#ifndef _CREATURE_
#define _CREATURE_

#include "entity.h"
class Rooms;

class creature : public entity
{
public:
	Rooms* creature_room;
	creature(const char* nam, const char* des, Rooms* initial_room) : entity(nam, des), creature_room(initial_room){}
};


#endif