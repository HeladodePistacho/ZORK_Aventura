#ifndef MOTHERCLASS
#define MOTHERCLASS

#include "my_string.h"
#include "Lista_enlazada.h"

enum TYPE { PLAYER, ROOM, EXIT, ITEM };

class entity
{
public:
	my_string name;
	my_string description;

public:
	
	TYPE entity_type;
	my_list<entity*> list;
	entity(const char* new_name, const char* new_description) : name(new_name), description(new_description) {}
	
	virtual void Update();

};

#endif