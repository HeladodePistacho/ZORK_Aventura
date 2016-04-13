#ifndef MOTHERCLASS
#define MOTHERCLASS

#include "my_string.h"

class entity
{
protected:
	my_string name;
	my_string description;

public:
	
	entity(const char* new_name, const char* new_description) : name(new_name), description(new_description) {}
	
	dynamic_array<entity*> my_entities;

};

#endif