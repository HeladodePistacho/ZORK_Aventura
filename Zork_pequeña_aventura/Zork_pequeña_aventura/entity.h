#ifndef MOTHERCLASS
#define MOTHERCLASS

#include "my_string.h"
#include "Lista_enlazada.h"

enum TYPE { PLAYER, ROOM, EXIT, ITEM, PASSIVE_NPC, SPIDER, BUG };
enum INFO_TYPE { ITEM_DROP, ITEM_PICK, ITEM_FILL, EXIT_SATE, CREATURE_STATE };


class entity
{
public:
	my_string name;
	my_string description;

public:
	
	TYPE entity_type;
	my_list<entity*> list;

	//STATS
	int life;
	int damage;

	entity(const char* new_name, const char* new_description) : name(new_name), description(new_description) {}
	
	virtual bool Look_extra_info(INFO_TYPE) const {return false;};
	virtual void Change_extra_info(INFO_TYPE){};

	virtual void Update(){};

};

#endif