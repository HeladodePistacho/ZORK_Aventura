

#ifndef EXITS
#define EXITS
class entity;
#include"Rooms.h"

class Exit : public entity
{
public:
	Rooms* origen;
	Rooms* destiny;
	bool open;

public:

	Exit(const char* direction, const char* description, Rooms* orig, Rooms* dest, bool op) : entity(direction, description), origen(orig), destiny(dest), open(op)
	{
		type = EXIT;	
	}
	
};

#endif