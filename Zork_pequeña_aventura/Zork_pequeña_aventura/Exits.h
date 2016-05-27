

#ifndef EXITS
#define EXITS
class entity;
#include"Rooms.h"

class Exit : public entity
{
public:
	entity* origen;
	entity* destiny;
	bool open;

public:

	Exit(const char* direction, const char* description, entity* orig, entity* dest, bool op) : entity(direction, description), origen(orig), destiny(dest), open(op)
	{
		entity_type = EXIT;	
	}
	
};

#endif