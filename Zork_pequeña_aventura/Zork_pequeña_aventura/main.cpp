#define _CRT_SECURE_NO_WARNINGS
#include "World.h"
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
	char action[20];
	char break_action[] = { ' ', 0 };
	char* first_word;
	char* second_word;
	bool finish;
	
	World map;
	map.CreateWorld(*map.player, map.rooms, map.exits);
	printf("You are %s\n Good luck\n", (map.rooms[2].room_name));

	do
	{
		do{
			printf("What's your next action?\n");
			gets(action);

			second_word = strtok(action, break_action);
			first_word = second_word;
			second_word = strtok(NULL, break_action);

		} while (first_word == NULL);

			map.action(first_word, second_word, map.player, map.rooms, map.exits);
			finish = map.finish_game(first_word);

			printf("\n\n");

	} while (finish == false);

	system("pause");
	return 0;

};