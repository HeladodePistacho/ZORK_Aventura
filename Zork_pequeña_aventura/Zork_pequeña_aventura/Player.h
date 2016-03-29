#ifndef PLAYER
#define PLAYER

#include "Rooms.h"
#include "Exits.h"

class Player
{
public:
	Rooms *player_room;
	void movement(const char[], const Exit[]);
};

#endif