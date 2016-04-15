#define _CRT_SECURE_NO_WARNINGS
#include "World.h"
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include "Items.h"
#include <stdio.h>



//This method creates the player, the rooms array and the exits array.
void World::CreateWorld()
{
	//ROOMS
	Rooms* CenterRoom = new Rooms("Center of the room", "A lightly place in the middle of the room, there's nothing interesting to do, but you can go everywhere from here");
	Rooms* Heater = new Rooms("In Front of the Heater", "A warm place under some book shelves, between the wardrobe and the desk");
	Rooms* UnderWardrobe = new Rooms("Under the wardrobe", "Your house, it is a wet but homely place");
	Rooms* FrontWardrobe = new Rooms("Front of the wardrobe", "A large and empty place in front of your home");
	Rooms* BehindDoor = new Rooms("Behind the Door", "A really dark place, you will need something to watch if there's something in front of you");
	Rooms* BookShelves = new Rooms("Book Shelves", "A high place with some adventure books and comics, high enough to reach the wardrobe top");
	Rooms* Desk = new Rooms("Desk", "A lightly place next to the window with a half-eated sandwich, a laptop and some jambled stuff");
	Rooms* UnderBed = new Rooms("Under the Bed", "This place is a mess, really dirty and full of dust, you can also see a tiny door");
	Rooms* Bed = new Rooms("Bed", "Really soft and comfortable place, the bedside table seems reacheable from here");
	Rooms* MouseCave = new Rooms("Mouse cave", "A place which stinks of cheese, there is a mouse trap here but seems that the animal is smarter than the humans");
	Rooms* BedsideTable = new Rooms("Bedside Table", "Near the bed, there is a plate with some snacks and another with the rests of those snacks");
	Rooms* AboveWardrobe = new Rooms("Above the Wardrobe", "A dusty and dark place, your brother is here waiting for you to fight the spider ans save him");
	Rooms* UnderDesk = new Rooms("Under the Desk", "A shadowy place, home of Rusty the old man, you can also reach some drawers from here");

	world_rooms.push_back(CenterRoom);
	world_rooms.push_back(Heater);
	world_rooms.push_back(UnderWardrobe);
	world_rooms.push_back(FrontWardrobe);
	world_rooms.push_back(BehindDoor);
	world_rooms.push_back(BookShelves);
	world_rooms.push_back(Desk);
	world_rooms.push_back(UnderBed);
	world_rooms.push_back(Bed);
	world_rooms.push_back(MouseCave);
	world_rooms.push_back(BedsideTable);
	world_rooms.push_back(AboveWardrobe);
	world_rooms.push_back(UnderDesk);

	//EXITS
	world_exits.push_back(new Exit("north", "You will go in front of the heater", CenterRoom, Heater, true));
	world_exits.push_back(new Exit("east", "You will go in front of the wardrobe", CenterRoom, FrontWardrobe, true));
	world_exits.push_back(new Exit("south", "You will go inside the darkness of under the bed", CenterRoom, UnderBed, true));
	world_exits.push_back(new Exit("west", "You will go the centre of the room", FrontWardrobe, CenterRoom, true));
	world_exits.push_back(new Exit("north", "That's the way to your home", FrontWardrobe, UnderWardrobe, true));
	world_exits.push_back(new Exit("south", "The path will get darker as you get closer the door", FrontWardrobe, BehindDoor, true));
	world_exits.push_back(new Exit("south", "This is the south exit of your home", UnderWardrobe, FrontWardrobe, true));
	world_exits.push_back(new Exit("west", "This is the west exit of your home, to the warm heater", UnderWardrobe, Heater, true));
	world_exits.push_back(new Exit("east", "This is the east way to your home", Heater, UnderWardrobe, true));
	world_exits.push_back(new Exit("south", "This path will get you into the centre of the room", Heater, CenterRoom, true));
	world_exits.push_back(new Exit("west", "A dark and wet path to under the desk", Heater, UnderDesk, true));
	world_exits.push_back(new Exit("east", "A dark and warm path to the heater", UnderDesk, Heater, true));
	world_exits.push_back(new Exit("up", "You could go this way if the drawers were open", UnderDesk, Desk, false));
	world_exits.push_back(new Exit("east", "A scary jump to reach the book shelves", Desk, BookShelves, true));
	world_exits.push_back(new Exit("down", "You can descend using the drawers as a stairs", Desk, UnderDesk, true));
	world_exits.push_back(new Exit("north", "This path is getting you to the centre of the room", UnderBed, CenterRoom, true));
	world_exits.push_back(new Exit("south", "This path is full of animal hair", UnderBed, MouseCave, false));
	world_exits.push_back(new Exit("up", "You can climb to the bed using the bed sheet", UnderBed, Bed, true));
	world_exits.push_back(new Exit("west", "it seems that you can reach the bedside table", Bed, BedsideTable, true));
	world_exits.push_back(new Exit("east", "This will return you to the bed", BedsideTable, Bed, true));
	world_exits.push_back(new Exit("north", "The path conects the stinky mouse cave with the under bed", MouseCave, UnderBed, true));
	world_exits.push_back(new Exit("north", "A path that is getting shinnier as you approach the wardrobe", BehindDoor, FrontWardrobe, true));
	world_exits.push_back(new Exit("east", "A scarier jump to the above wardrobe", BookShelves, AboveWardrobe, true));
	world_exits.push_back(new Exit("west", "A jump to the desk", BookShelves, Desk, true));
	world_exits.push_back(new Exit("west", "A jump from the dusty wardrobe to the bookshelves", AboveWardrobe, BookShelves, true));
	world_exits.push_back(new Exit("down", "You can descend using the same bed sheet that you used to get here", Bed, UnderBed, true));
	
	//PLAYER
	player = new Player(UnderWardrobe, 2, 3);

	//ITEMS

	item* BluePen = new item("Blue Pen", "A standar pen, maybe you can do something with it", true, Desk, nullptr, nullptr, false);
	item* PoweredHook = new item("Powered Hook", "This awesome improved hook will help you to reach the wardrobe roof", false, nullptr, nullptr, nullptr, false);
	item* NutsGunLoaded = new item("Sunflower seed gun loaded", "Fully reloaded and ready to shoot", false, nullptr, nullptr, nullptr, false);
	item* Catapult = new item("Catapult", "Perfect to reach the wardrobe roof, you should find a clear place to use it", false, nullptr, nullptr, nullptr, false);
	item* Backpack = new item("Backpack", "Perfect to carry more stuff", true, UnderWardrobe, nullptr, nullptr, true);
	item* FireNeedle = new item("Fire Needle", "Improved needle with a incandescent needle tip, it is a super awesome weapon", false, nullptr, nullptr, nullptr, false);
	item* NutsGun = new item("Sunflower seed gun", "This powerfull weapon is perfect to fight from distance, but you have no ammo", false, nullptr, NutsGunLoaded, nullptr, false);
	item* Hook = new item("Hook", "This hook will help you to reach higher positions", false, nullptr, PoweredHook, nullptr, false);
	item* BlueWire = new item("Blue pen wire", "A elastic wire that can be used to create new items", false, BluePen->item_room, NutsGun, PoweredHook, false);
	item* BlackPlastic = new item("Black pen plastic", "This plastic have been used as a blowgun", true, Desk, NutsGun, nullptr, false);
	item* Shoelace = new item("Shoelace", "This item is usefull to craft recheable items", true, UnderBed, Hook, Catapult, false);
	item* Needle = new item("Needle", "A sharp needle, that can be a nice weapon", true, BehindDoor, Hook, FireNeedle, false);
	item* MouseTrap = new item("Mouse trap", "Seems that the cheese have been eaten, but the mouse is still alive", true, MouseCave, Catapult, nullptr, false);
	item* Nuts = new item("Nuts", "A delicious snack for humans", true, BedsideTable, NutsGunLoaded, nullptr, false);
	item* MatchStick = new item("MatchStic", "A usefull matchstick that can provide light and heat", true, Desk, FireNeedle, nullptr, false);
	
	world_items.push_back(BluePen);
	world_items.push_back(PoweredHook);
	world_items.push_back(NutsGunLoaded);
	world_items.push_back(Catapult);
	world_items.push_back(Backpack);
	world_items.push_back(FireNeedle);
	world_items.push_back(NutsGun);
	world_items.push_back(Hook);
	world_items.push_back(BlueWire);
	world_items.push_back(BlackPlastic);
	world_items.push_back(Shoelace);
	world_items.push_back(Needle);
	world_items.push_back(MouseTrap);
	world_items.push_back(Nuts);
	world_items.push_back(MatchStick);
}

/*

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
	printf("%s\n", player_room->name);
	printf("%s\n", player_room->description);
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
		int equal = strcmp(second_word, (exits + j)->name);

		if ((exits + j)->origen == player_room && equal == 0){
			printf("%s\n", (exits + j)->description);
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
				printf("%s\n", player_room->name);
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

*/