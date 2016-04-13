#ifndef ROOMS
#define ROOMS

#include "entity.h"
#include "my_string.h"

class my_string;

class Rooms : protected entity
{
public:

	Rooms(const char* nam, const char* des) : entity(name.c_str, description.c_str) {}
	

};

#endif