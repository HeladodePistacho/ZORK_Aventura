#ifndef PLAYER
#define PLAYER

#include "Rooms.h"
#include "Items.h"
#include "Exits.h"
#include "Box.h"
#include "dinamic_array.h"

class Player
{
public:
	Rooms *player_room;
	dynamic_array<item*> inventory;
	dynamic_array<item*> equiped;
public:

	Player(Rooms* initial_room, unsigned int equip, unsigned int inv) : player_room(initial_room), equiped(equip), inventory(inv){}
	
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
};

#endif