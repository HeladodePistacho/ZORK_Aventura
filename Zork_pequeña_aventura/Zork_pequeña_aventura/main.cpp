#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
	char action[20];
	char break_action[] = { ' ', 0 };
	char* first_word;
	char* second_word;
	int finish;
	int previous_room = 2;


	World map;
	map.CreateWorld(*map.player, map.rooms, map.exits);


	do
	{

		printf("What do you want to do?\n");
		gets(action);

		second_word = strtok(action, break_action);
		first_word = second_word;
		second_word = strtok(NULL, break_action);
	}
}
