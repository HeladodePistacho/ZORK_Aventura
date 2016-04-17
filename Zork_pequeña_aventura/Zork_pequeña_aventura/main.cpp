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
	int p;

	dynamic_array<int> proba;
	proba.push_back(2);
	proba.push_back(3);
	proba.push_back(4);
	proba.move_element();
	proba.pop_back(p);
	proba.push_back(1);

	printf("%i,%i,%i,%i", proba[0], proba[1], proba[2], proba[3]);

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