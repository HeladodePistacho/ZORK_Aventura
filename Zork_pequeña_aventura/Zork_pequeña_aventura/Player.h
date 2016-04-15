#ifndef PLAYER
#define PLAYER

#include "Rooms.h"
#include "Items.h"
#include "Exits.h"
#include "dinamic_array.h"

class Player
{
public:
	Rooms *player_room;
	dynamic_array<item*> inventory;
	dynamic_array<item*> equiped;
public:

	Player(Rooms* initial_room, unsigned int equip, unsigned int inv) : player_room(initial_room), equiped(equip), inventory(inv){}
	
	void movement(const char[], const Exit[]);
	void looking(Exit* exits);
	void looking_exits(const char second_word[], const Exit* exits);
	void open_close_door(const char first_word[], const char second_word[], Exit* exits);


};

#endif