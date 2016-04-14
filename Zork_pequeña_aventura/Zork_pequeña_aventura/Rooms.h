#ifndef ROOMS
#define ROOMS

#include "entity.h"
#include "my_string.h"

class my_string;

class Rooms : public entity
{
public:

	Rooms(const char* nam, const char* des) : entity(nam, des) 
	{
		type = ROOM;
	}
	

};

#endif