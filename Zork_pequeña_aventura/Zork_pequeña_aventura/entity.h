#ifndef MOTHERCLASS
#define MOTHERCLASS

#include "my_string.h"

typedef enum {PLAYER, ROOM, EXIT, ITEM};

class entity
{
public:
	my_string name;
	my_string description;

public:
	

	int type;
	entity(const char* new_name, const char* new_description) : name(new_name), description(new_description) {}
	
	

};

#endif