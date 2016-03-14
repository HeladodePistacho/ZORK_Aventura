#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <stdio.h>
#include <string.h>

void World::CreateWorld(Player& player, Rooms rooms[13], Exit exits[25])
{
	rooms[0] = { "Center of the room", "A lightly place in the middle of the room, there's nothing interesting to do, but you can go everywhere from here" };
	rooms[1] = { "In Front of the Heater", "A warm place under some book shelves, between the wardrobe and the desk" };
	rooms[2] = { "Under the wardrobe", "Your house, it is a wet but homely place" };
	rooms[3] = { "Front of the wardrobe", "A large and empty place in front of your home" };
	rooms[4] = { "Behind the Door", "A really dark place, you will need something to watch if there's something in front of you" };
	rooms[5] = { "Book Shelves", "A high place with some adventure books and comics, high enough to reach the wardrobe top" };
	rooms[6] = { "Under the Desk", "A shadowy place, home of Rusty the old man, you can also reach some drawers from here" };
	rooms[7] = { "Desk", "A lightly place next to the window with a half-eated sandwich, a laptop and some jambled stuff" };
	rooms[8] = { "Under the Bed", "This place is a mess, really dirty and full of dust, you can also see a tiny door" };
	rooms[9] = { "Bed", "Really soft and comfortable place, the bedside table seems reacheable from here" };
	rooms[10] = { "Mouse cave", "A place which stinks of cheese, there is a mouse trap here but seems that the animal is smarter than the humans" };
	rooms[11] = { "Bedside Table", "Near the bed, there is a plate with some snacks and another with the rests of those snacks" };
	rooms[12] = { "Above the Wardrobe", "A dusty and dark place, your brother is here waiting for you to fight the spider ans save him" };

	player.player_room = (rooms + 2);

	exits[0] = { "From the center of the room to the front of the heater", (rooms + 0), (rooms + 1), "north", true };
	exits[1] = { "From the center of the room to the front of the wardrobe", (rooms + 0), (rooms + 3), "east", true };
	exits[2] = { "From the center of the room to under the bed", (rooms + 0), (rooms + 8), "south", true };
	exits[3] = { "From the front of the wardrobe to the center of the room", (rooms + 3), (rooms + 0), "west", true };
	exits[4] = { "From the front of the wardrobe to under the wardrobe", (rooms + 3), (rooms + 2), "nort", true };
	exits[5] = { "From the front of the wardrobe to behind the door", (rooms + 3), (rooms + 4), "south", true };
	exits[6] = { "From under the wardrobe to in front of it", (rooms + 2), (rooms + 3), "south", true };
	exits[7] = { "From under the wardrobe to in front of the heater", (rooms + 2), (rooms + 1), "west", true };
	exits[8] = { "From in front of the heater to under the wardrobe", (rooms + 1), (rooms + 2), "east", true };
	exits[9] = { "From in front of the heater to the center of the room", (rooms + 1), (rooms + 0), "south", true };
	exits[10] = { "From in front of the heater to under the desk", (rooms + 1), (rooms + 6), "west", true };
	exits[11] = { "From under the desk to the front of the heater", (rooms + 6), (rooms + 1), "east", true };
	exits[12] = { "From under the desk to the desk", (rooms + 6), (rooms + 7), "up", false };
	exits[13] = { "From the desk to the book shelves", (rooms + 7), (rooms + 5), "east", true };
	exits[14] = { "From the desk to under the desk", (rooms + 7), (rooms + 6), "down", true };
	exits[15] = { "From under the bed to the center of the room", (rooms + 8), (rooms + 0), "north", true };
	exits[16] = { "From under the bed to the mouse cave", (rooms + 8), (rooms + 10), "south", false };
	exits[17] = { "From under the bed to the bed", (rooms + 8), (rooms + 9), "up", true };
	exits[18] = { "From the bed to the bedside table", (rooms + 9), (rooms + 11), "west", true };
	exits[19] = { "From the bedside table to the bed", (rooms + 9), (rooms + 8), "east", true };
	exits[20] = { "From the mouse cave to under the bed", (rooms + 10), (rooms + 8), "north", true };
	exits[21] = { "From behind the door to the front of the wardrobe", (rooms + 4), (rooms + 3), "north", true };
	exits[22] = { "From the books shelves to above the wardrobe", (rooms + 5), (rooms + 12), "east", true };
	exits[23] = { "From the books shelves to the desk", (rooms + 5), (rooms + 7), "west", true };
	exits[24] = { "From the above the wardrobe to the bookshelves", (rooms + 7), (rooms + 5), "west", true };
}

int finish_game(char first_word[]){
	int equal_quit[2] = { strcmp(first_word, "quit"), strcmp(first_word, "Quit") };

	if (equal_quit[0] == 0 || equal_quit[1] == 0){
		return 1;
	}
	else return 0;
}

void ToDo(int *previous_room, char first_word[], char second_word[], Player* player, Rooms* actualroom, Exit* exits)
{
	int equal_help[2] = { strcmp(first_word, "help"), strcmp(first_word, "Help") };  //This vector has a 0 if first_word == help, or first_word == Help
	int equal_look[2] = { strcmp(first_word, "look"), strcmp(first_word, "Look") };

	if (equal_help[0] == 0 || equal_help[1] == 0){
		printf("Welcome to Zork\nControls:\n-To exit type quit\n-To move you can use comand go.\nexample : go north, go south, go east, go west, go up, go down.\n\n");
		printf("-To look the room where you are use look and the direction.\n It will says how it is the room where you are and the\n exits that it have.\n");
		printf(" You can also look only an exit, looking the direction.\nexample : look room, look north, look east...\n\n-Somewhere there will be closed doors, use open to pass or\n");
		printf(" close to close the door you actually open.\nexample : open north, open south, open up, close south...\n\n");
		getchar();
	}


	if (equal_look[0] == 0 || equal_look[1] == 0){

		if (second_word != NULL){
			looking_exits(second_word, player, exits);
		}

		else looking(*player, exits);
	}

}

void looking(Player& player, Exit* exits)
{
	printf("%s\n", player.player_room->room_name);
	printf("%s\n", player.player_room->room_description);
	printf("There is an exit going:");
	for (int j = 0; j < 25; j++){
		if ((exits + j)->origen == player.player_room){
			printf(" %s, ", (exits + j)->direction);
		}
		
	}
	printf("\n");

}

void looking_exits(char second_word[], Player* player, Exit* exits){
	int counter = 0;	//if counter == 0 at the end of the loop there isn't a room in the direction said								
	for (int j = 0; j < 25; j++){
		int equal = strcmp(second_word, (exits + j)->direction);

		if ((exits + j)->origen == player->player_room && equal == 0){
			printf("%s\n", (exits + j)->exit_name);
			counter++;
		}
	}
	if (counter == 0){
		printf("there isn't any exits in this direction\n");
	}
}