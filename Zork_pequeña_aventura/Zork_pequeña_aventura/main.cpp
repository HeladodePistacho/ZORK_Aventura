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

	
	int actual_time = 0;
	int action_time = 1000;

	unsigned int actual_character = 0;


	do
	{
		int current_time = GetTickCount();

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
		
		//update
		if (current_time >= actual_time + action_time)
		{
			for (int i = 0; i < map.entities.get_size(); i++)
			{
				map.entities[i]->Update();
			}
			actual_time = current_time;
		}
		//test

		

		

	} while (finish == false);

	return 0;

};