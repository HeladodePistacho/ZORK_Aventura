#define _CRT_SECURE_NO_WARNINGS
#include "World.h"
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include "Items.h"
#include <stdio.h>
#include "my_string.h"
#include <stdlib.h>



int main()
{
	dynamic_array<char*> divided_action;
	my_string main_action;
	World map;
	char action[50];
	bool finish;

	do
	{
		printf("What's your next action?\n");
		gets(action);
		main_action.tokenize(" ", action, divided_action);

		map.action(divided_action);
		finish = map.finish_game(divided_action);
		divided_action.clean();
		printf("\n\n");

	} while (finish == false);

	return 0;

};