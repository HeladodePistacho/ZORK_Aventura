#ifndef _PLAYER_H_
#define _PLAYER_H_

class Rooms;
#include "Creature.h"
#include "Items.h"
#include "Exits.h"
#include "Box.h"
#include "dinamic_array.h"

class Player : public creature
{
public:
	dynamic_array<item*> equiped;
public:

	Player(const char* nam, const char* des, Rooms* initial_room, unsigned int equip, unsigned int inv) : creature(nam, des, initial_room), equiped(equip), inventory(inv)
	{
		entity_type = PLAYER;
	}
	
	void movement(const dynamic_array<char*>&, const dynamic_array<Exit*>&, unsigned int);
	void looking(const dynamic_array<Exit*>&, const dynamic_array<item*>&, const box&)const;
	void looking_exits(const dynamic_array<char*>&, const dynamic_array<Exit*>&)const;
	void looking_items(const dynamic_array<char*>&, const dynamic_array<item*>&, const box&)const;
	void open_door(const dynamic_array<char*>&, const dynamic_array<Exit*>&)const;
	void close_door(const dynamic_array<char*>&, const dynamic_array<Exit*>&)const;
	void pick(const dynamic_array<char*>&, const dynamic_array<item*>&, const box&);
	void drop(const dynamic_array<char*>&, const dynamic_array<item*>&);
	void Get_inventory()const;
	void equip(const dynamic_array<char*>&);
	void unequip(const dynamic_array<char*>&);
	void put(const dynamic_array<char*>&, box&);
	void get(const dynamic_array<char*>&, box&);
	void combine(const dynamic_array<item*>&);
};

#endif