#ifndef MOTHERCLASS
#define MOTHERCLASS

#include "my_string.h"
#include "Lista_enlazada.h"

enum TYPE { PLAYER, ROOM, EXIT, ITEM };
enum INFO_TYPE { ITEM_DROP, ITEM_PICK, ITEM_FILL, EXIT_SATE };


class entity
{
public:
	my_string name;
	my_string description;

public:
	
	TYPE entity_type;
	my_list<entity*> list;
	entity(const char* new_name, const char* new_description) : name(new_name), description(new_description) {}
	
	virtual bool Look_extra_info(INFO_TYPE) const {return false;};
	virtual void Change_extra_info(INFO_TYPE){};

	virtual void Update(){};

};

#endif