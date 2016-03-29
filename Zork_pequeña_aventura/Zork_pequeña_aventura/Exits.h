

#ifndef EXITS
#define EXITS

#include"Rooms.h"

class Exit
{
public:
	char exit_name[100];
	Rooms* origen;
	Rooms* destiny;
	char direction[6];
	bool open;
};

#endif