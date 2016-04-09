#ifndef CLASSANDFUNCTIONS
#define CLASSANDUNCTIONS

#include "Exits.h"
#include "Rooms.h"
#include "Player.h"



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
		exits = new Exit[26];
	}
	~World(){
		delete player;
		delete[]rooms;
		delete[]exits;
	}
	void CreateWorld(Player&, Rooms[], Exit[]);
	bool finish_game(const char first_word[]);
};

bool finish_game(char[]);

void looking(Player&, Exit*);

void looking_exits(char[], Player*, Exit*);



void open_close_door(char[], char[], Player*, Exit*);

void change_directions(const char*[]);

void ToDo(char[], char[], Player*, Rooms*, Exit*);

#endif