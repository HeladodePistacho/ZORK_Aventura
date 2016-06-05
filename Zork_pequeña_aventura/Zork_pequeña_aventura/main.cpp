#define _CRT_SECURE_NO_WARNINGS
#include "Clock.h"
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
	int action_time = 2500;
	unsigned int actual_character = 0;

	int clock_time = 0;

	int Minutes = 4;
	int Decimes = 5;
	int Seconds = 9;

	int dead_time = 0;

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
				if (map.entities[i]->entity_type == SPIDER && map.player->creature_room == map.entities[i]->list.first_node->data)
				{
					map.entities[i]->Change_extra_info(CREATURE_STATE);
					if (map.entities[i]->Look_extra_info(CREATURE_STATE))
						finish = true;

				}
				
				map.entities[i]->Update();	
			}
			actual_time = current_time;
		}


		map.player->Update();
		if (map.player->is_dead()) finish = true;

		if (current_time >= clock_time + 1000)
		{
			Clock(&Minutes, &Decimes, &Seconds);
			clock_time = current_time;
		}

		if (current_time >= dead_time + 5000)
		{
			printf(" Brother's dead in: %i:%i%i\n", Minutes , Decimes  , Seconds + 1);
			dead_time = current_time;
		}

		if (Minutes <= 0 && Decimes <= 0 && Seconds <= 0)
			finish = true;



	} while (finish == false);

	return 0;

};