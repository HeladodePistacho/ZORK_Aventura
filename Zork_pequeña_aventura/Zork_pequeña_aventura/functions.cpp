#define _CRT_SECURE_NO_WARNINGS
#include "World.h"
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include <stdio.h>



//This method creates the player, the rooms array and the exits array.
void World::CreateWorld(dynamic_array<entity>& entities)
{

	entities.push_back(new Rooms("Center of the room", "A lightly place in the middle of the room, there's nothing interesting to do, but you can go everywhere from here"));
	
	


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

	exits[0] = { "You will go in front of the heater", (rooms + 0), (rooms + 1), "north", true };
	exits[1] = { "You will go in front of the wardrobe", (rooms + 0), (rooms + 3), "east", true };
	exits[2] = { "You will go inside the darkness of under the bed", (rooms + 0), (rooms + 8), "south", true };
	exits[3] = { "You will go the centre of the room", (rooms + 3), (rooms + 0), "west", true };
	exits[4] = { "That's the way to your home", (rooms + 3), (rooms + 2), "north", true };
	exits[5] = { "The path will get darker as you get closer the door", (rooms + 3), (rooms + 4), "south", true };
	exits[6] = { "This is the south exit of your home", (rooms + 2), (rooms + 3), "south", true };
	exits[7] = { "This is the west exit of your home, to the warm heater", (rooms + 2), (rooms + 1), "west", true };
	exits[8] = { "This is the east way to your home", (rooms + 1), (rooms + 2), "east", true };
	exits[9] = { "This path will get you into the centre of the room", (rooms + 1), (rooms + 0), "south", true };
	exits[10] = { "A dark and wet path to under the desk", (rooms + 1), (rooms + 6), "west", true };
	exits[11] = { "A dark and warm path to the heater", (rooms + 6), (rooms + 1), "east", true };
	exits[12] = { "You could go this way if the drawers were open", (rooms + 6), (rooms + 7), "up", false };
	exits[13] = { "A scary jump to reach the book shelves", (rooms + 7), (rooms + 5), "east", true };
	exits[14] = { "You can descend using the drawers as a stairs", (rooms + 7), (rooms + 6), "down", true };
	exits[15] = { "This path is getting you to the centre of the room", (rooms + 8), (rooms + 0), "north", true };
	exits[16] = { "This path is full of animal hair", (rooms + 8), (rooms + 10), "south", false };
	exits[17] = { "You can climb to the bed using the bed sheet", (rooms + 8), (rooms + 9), "up", true };
	exits[18] = { "it seems that you can reach the bedside table", (rooms + 9), (rooms + 11), "west", true };
	exits[19] = { "This will return you to the bed", (rooms + 11), (rooms + 9), "east", true };
	exits[20] = { "The path conects the stinky mouse cave with the under the bed", (rooms + 10), (rooms + 8), "north", true };
	exits[21] = { "A path that is getting shinnier as you approach the wardrobe", (rooms + 4), (rooms + 3), "north", true };
	exits[22] = { "A scarier jump to the above wardrobe", (rooms + 5), (rooms + 12), "east", true };
	exits[23] = { "A jump to the desk", (rooms + 5), (rooms + 7), "west", true };
	exits[24] = { "A jump from the dusty wardrobe to the bookshelves", (rooms + 12), (rooms + 5), "west", true };
	exits[25] = { "You can descend using the same bed sheet that you used to get here", (rooms + 9), (rooms + 8), "down", true };

}

//This function looks if first_word == quit, if it is returns 1, and that finish the game.
bool World::finish_game(const char first_word[]) 
{
	int equal_quit[2] = { strcmp(first_word, "quit"), strcmp(first_word, "Quit") };

	if (equal_quit[0] == 0 || equal_quit[1] == 0){
		return true;
	}
	else return false;
}

//This is the big function that have all the others, it compares the strings and do what is asked to do.
void World::action(const char first_word[], const char second_word[], Player* player, Rooms* actualroom, Exit* exits) 
{

	int equal_help[2] = { strcmp(first_word, "help"), strcmp(first_word, "Help") };  //This vector has a 0 if first_word == help, or first_word == Help
	int equal_look[2] = { strcmp(first_word, "look"), strcmp(first_word, "Look") };
	int equal_directions[12] = { strcmp(first_word, "north"), strcmp(first_word, "n"), strcmp(first_word, "south"), strcmp(first_word, "s"), strcmp(first_word, "west"), strcmp(first_word, "w"), strcmp(first_word, "east"), strcmp(first_word, "e"), strcmp(first_word, "up"), strcmp(first_word, "u"), strcmp(first_word, "down"), strcmp(first_word, "d") };
	int equal_go[2] = { strcmp(first_word, "go"), strcmp(first_word, "Go") };
	int equal_open_close[4] = { strcmp(first_word, "open"), strcmp(first_word, "Open"), strcmp(first_word, "close"), strcmp(first_word, "Close") };

	if (equal_help[0] == 0 || equal_help[1] == 0){
		printf("Welcome to Zork\nControls:\n-To exit type quit\n-To move you can use comand go.\nexample : go north, go south, go east, go west, go up, go down.\n\n");
		printf("-To look the room where you are use look and the direction.\n It will says how it is the room where you are and the\n exits that it have.\n");
		printf(" You can also look only an exit, looking the direction.\nexample : look room, look north, look east...\n\n-Somewhere there will be closed doors, use open to pass or\n");
		printf(" close to close the door you actually open.\nexample : open north, open south, open up, close south...\n\n");
		
	}


	if (equal_look[0] == 0 || equal_look[1] == 0){

		if (second_word != NULL){
			player->looking_exits(second_word, exits);
		}

		else player->looking(exits);
	}


	if (equal_go[0] == 0 || equal_go[1] == 0){
		player->movement(second_word, exits);
	}
	else{
		for (int i = 0; i < 12; i++){
			if (equal_directions[i] == 0){
				player->movement(first_word, exits);
			}
		}
	}

	if (equal_open_close[0] == 0 || equal_open_close[1] == 0 || equal_open_close[2] == 0 || equal_open_close[3] == 0)
	{
		if (second_word != NULL)
		{
			player->open_close_door(first_word, second_word, exits);
		}
		else printf("I need a direction using this comand\n");
	}
}

//This prints the room name and the description of where you are, and it's exits directions
void Player::looking(Exit* exits)
{
	printf("%s\n", player_room->room_name);
	printf("%s\n", player_room->room_description);
	printf("There is an exit going:");
	for (int j = 0; j < 26; j++){
		if ((exits + j)->origen == player_room){
			printf(" %s, ", (exits + j)->direction);
		}

	}
	printf("\n");

}

//This will give the description of the exit asked
void Player::looking_exits(const char second_word[], const Exit* exits){
	int counter = 0;	//if counter == 0 at the end of the loop there isn't a room in the direction said								
	for (int j = 0; j < 26; j++){
		int equal = strcmp(second_word, (exits + j)->direction);

		if ((exits + j)->origen == player_room && equal == 0){
			printf("%s\n", (exits + j)->exit_name);
			counter++;
		}
	}
	if (counter == 0){
		printf("there isn't any exits in this direction\n");
	}
}

//This looks if the path is open or closed. If it is open, then search for the exit with the direction you asked for 
//and changes the player_room for the destiny room of the exit and prints it name. If it is close don't let you pass
void Player::movement(const char first_word[],const Exit exits[]){

	bool door_closed = true;
	bool recheable_room = false;
	int equal_direction;
	
	
	for (int j = 0; j < 26; j++){

		equal_direction = strcmp(first_word, exits[j].direction);

		if (exits[j].open == true && exits[j].origen == player_room)
		{

			if (equal_direction == 0)
			{
				player_room = exits[j].destiny;
				printf("%s\n", player_room->room_name);
				recheable_room = true;
				break;
			}
			
		}
		else {
			if (exits[j].open == false && exits[j].origen == player_room)
			{
				if (equal_direction == 0) door_closed = false;
			}
		}
	}
	if (door_closed == false){
		printf("You can't go this way, the path is closed\n");
	}
	else if (recheable_room == false)
	{
		printf("You can't go this way\n");
	}
	
}

//This function lets the player open and close paths changing the boolen open from the exits
void Player::open_close_door(const char first_word[], const char second_word[], Exit* exits){

	int open = strcmp(first_word, "open");
	int close = strcmp(first_word, "close");
	int counter_open = 0;
	int counter_close = 0;


	if (open == 0){						//this part of the code search for an exit which is in the same room of the player and the same direction introduced
		for (int j = 0; j < 26; j++)	//If it is found the boolean changes to true(open) and if it is not it prints an error 
		{
			int equal_direction = strcmp(second_word, (exits + j)->direction);
			if ((exits + j)->origen == player_room && equal_direction == 0)
			{
				if ((exits + j)->open == true)
				{
					printf("This path is already open\n");
				}
				else 
				{
					(exits + j)->open = true;
					printf("The path is open\n");
				}
				counter_open++;
			}

		}
		if (counter_open == 0)
		{
			printf("There is nothing to open this way\n");
		}
	}

	if (close == 0){						//Does exactly the same than the open one but closing the boolean (false)
		for (int j = 0; j < 26; j++)
		{
			int equal_direction = strcmp(second_word, (exits + j)->direction);
			if ((exits + j)->origen == player_room && equal_direction == 0)
			{
				if ((exits + j)->open == false)
				{
					printf("This path is already closed\n");
				}
				else
				{
					(exits + j)->open = false;
					printf("The path is closed\n");
				}
				counter_close++;
			}

		}
		if (counter_close == 0)
		{
			printf("There is nothing to close this way\n");
		}
	}

}
