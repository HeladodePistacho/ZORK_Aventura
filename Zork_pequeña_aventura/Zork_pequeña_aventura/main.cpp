#define _CRT_SECURE_NO_WARNINGS
#include "World.h"
#include <Windows.h>
#include <conio.h>
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include "Items.h"
#include <stdio.h>
#include "my_string.h"
#include <stdlib.h>

#define ACTION_LONG 50


int main()
{
	dynamic_array<char*> divided_action;
	my_string main_action;
	World map;
	char action[ACTION_LONG];
	bool finish = false;

	unsigned int actual_character = 0;


	do
	{
		if (_kbhit())
		{
			if (actual_character < (ACTION_LONG - 2))
			{
				action[actual_character] = _getch();
				action[actual_character + 1] = '\0';
				
				actual_character++;
			}

			if (action[actual_character - 1] == '\r')
			{
				action[actual_character] = '\0';
				printf("%s", action);//va imprimint l'estat de command
				actual_character = 0;
				main_action.tokenize(" \r", action, divided_action);
				map.action(divided_action);
				finish = map.finish_game(divided_action);
				divided_action.clean();
				printf("\n\n");
			}
		

		}
		
		

	} while (finish == false);

	return 0;

};