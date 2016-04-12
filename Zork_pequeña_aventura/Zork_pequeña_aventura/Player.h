#ifndef PLAYER
#define PLAYER

#include "Rooms.h"
#include "Exits.h"

class Player
{
public:
	Rooms *player_room;
	void movement(const char[], const Exit[]);
	void looking(Exit* exits);
	void looking_exits(const char second_word[], const Exit* exits);
	void open_close_door(const char first_word[], const char second_word[], Exit* exits);


};

#endif