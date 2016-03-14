#ifndef CLASSANDFUNCTIONS
#define CLASSANDUNCTIONS

class Player
{
public:
	Rooms* player_room;
};

class Rooms
{
public:
	char room_name[25];
	char room_description[150];
};

class Exit
{
public:
	char exit_name[100];
	Rooms* origen;
	Rooms* destiny;
	char direction[6];
	bool open;
};

class World
{
public:
	Player* player;
	Rooms* rooms;
	Exit* exits;

public:

	World(){
		player = new Player;
		rooms = new Rooms[13];
		exits = new Exit[25];
	}
	~World(){
		delete player;
		delete[]rooms;
		delete[]exits;
	}
	void CreateWorld(Player&, Rooms[], Exit[]);
};

#endif