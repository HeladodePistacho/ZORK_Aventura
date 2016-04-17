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
	player = new Player(Desk, 2, 3);

	//ITEMS

	item* BluePen = new item("BluePen", "A standar pen, maybe you can do something with it", true, Desk, nullptr, nullptr, false);
	item* PoweredHook = new item("PoweredHook", "This awesome improved hook will help you to reach the wardrobe roof", false, nullptr, nullptr, nullptr, false);
	item* NutsGunLoaded = new item("NutsGunLoaded", "Fully reloaded and ready to shoot", false, nullptr, nullptr, nullptr, false);
	item* Catapult = new item("Catapult", "Perfect to reach the wardrobe roof, you should find a clear place to use it", false, nullptr, nullptr, nullptr, false);
	item* Backpack = new item("Backpack", "Perfect to carry more stuff", true, UnderWardrobe, nullptr, nullptr, true);
	item* FireNeedle = new item("FireNeedle", "Improved needle with a incandescent needle tip, it is a super awesome weapon", false, nullptr, nullptr, nullptr, false);
	item* NutsGun = new item("NutsGun", "This powerfull weapon is perfect to fight from distance, but you have no ammo", false, nullptr, NutsGunLoaded, nullptr, false);
	item* Hook = new item("Hook", "This hook will help you to reach higher positions", false, nullptr, PoweredHook, nullptr, false);
	item* BlueWire = new item("PenWire", "A elastic wire that can be used to create new items", false, BluePen->item_room, NutsGun, PoweredHook, false);
	item* BlackPlastic = new item("BlackPlastic", "This plastic have been used as a blowgun", true, Desk, NutsGun, nullptr, false);
	item* Shoelace = new item("Shoelace", "This item is usefull to craft recheable items", true, UnderBed, Hook, Catapult, false);
	item* Needle = new item("Needle", "A sharp needle, that can be a nice weapon", true, BehindDoor, Hook, FireNeedle, false);
	item* MouseTrap = new item("MouseTrap", "Seems that the cheese have been eaten, but the mouse is still alive", true, MouseCave, Catapult, nullptr, false);
	item* Nuts = new item("Nuts", "A delicious snack for humans", true, BedsideTable, NutsGunLoaded, nullptr, false);
	item* MatchStick = new item("MatchStick", "A usefull matchstick that can provide light and heat", true, Desk, FireNeedle, nullptr, false);
	
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

	my_string dir("north south west east up down");
	dir.tokenize(" ", directions);
	
	my_string com("exit help look go open close");
	com.tokenize(" ", comands);
	
}



//This function looks if first_word == quit, if it is returns 1, and that finish the game.
bool World::finish_game( const dynamic_array<char*>& divided_action)
{
	
	return divided_action.compare(comands, 0);
}


//This is the big function that have all the others, it compares the strings and do what is asked to do.
void World::action(const dynamic_array<char*>& divided_action)
{

	//HELP
	if (divided_action.compare(comands, 1) == true)
	{
		printf("Welcome to Zork\nControls:\n-To exit type quit\n-To move you can use comand go.\nexample : go north, go south, go east, go west, go up, go down.\n\n");
		printf("-To look the room where you are use look and the direction.\n It will says how it is the room where you are and the\n exits that it have.\n");
		printf(" You can also look only an exit, looking the direction.\nexample : look room, look north, look east...\n\n-Somewhere there will be closed doors, use open to pass or\n");
		printf(" close to close the door you actually open.\nexample : open north, open south, open up, close south...\n\n");
	}

	//LOOK
	if (divided_action.compare(comands, 2))
	{
		if (divided_action.get_size() == 1) player->looking(world_exits, world_items);
		else
		{
			if (divided_action.compare(directions)) player->looking_exits(divided_action, world_exits);
			else player->looking_items(divided_action, world_items);
		}		
	}

	//MOVEMENT
	if (divided_action.compare(comands, 3) && divided_action.compare(directions))
		player->movement(divided_action, world_exits, 1);

	else 
	{ 
		if (divided_action.compare(directions) && divided_action.get_size() == 1) 
		player->movement(divided_action, world_exits, 0); 
	}
	
	//OPEN
	if (divided_action.compare(comands, 4))
	{
		if (divided_action.compare(directions))
		{
			player->open_door(divided_action, world_exits);
		}
		else printf("I need a direction using this comand\n");
	}

	//CLOSE
	if (divided_action.compare(comands, 5))
	{
		if (divided_action.compare(directions))
		{
			player->close_door(divided_action, world_exits);
		}
		else printf("I need a direction using this comand\n");
	}
	
}


//This prints the room name and the description of where you are, and it's exits directions
void Player::looking(const dynamic_array<Exit*>& exits, const dynamic_array<item*>& items)
{
	bool no_items = true;
	printf("%s\n", player_room->name);
	printf("%s\n", player_room->description);
	printf("There is an exit going:");
	for (int j = 0; j < exits.get_size(); j++)
	{
		if (exits[j]->origen == player_room)
		{
			printf(" %s,", exits[j]->name);
		}
	}

	printf("\nItems in the room: ");
	for (int i = 0; i < items.get_size(); i++)
	{
		if (items[i]->item_room == player_room && items[i]->dropped == true) 
		{
			printf(" %s,", items[i]->name);
			no_items = false;
		}
	}

	if (no_items) printf("none");
	printf("\n");

}

//This will give the description of the exit asked
void Player::looking_exits(const dynamic_array<char*>& divided_action, const dynamic_array<Exit*>& exits){
	bool no_exit = true;

	for (int j = 0; j < exits.get_size(); j++){

		if (divided_action.compare(exits[j]->name.c_str()) && exits[j]->origen == player_room)
		{
			printf("%s\n", exits[j]->description);
			no_exit = false;
		}
	}
	if (no_exit) printf("there isn't any exits in this direction\n");	
}

//This will give the description of the item asked
void Player::looking_items(const dynamic_array<char*>& divided_action, const dynamic_array<item*>& items)
{
	for (int i = 0; i < items.get_size(); i++)
	{
		if (divided_action.compare(items[i]->name.c_str()) && items[i]->item_room == player_room)
		{
			printf("%s,", items[i]->description);
		}
	}
}


//This looks if the path is open or closed. If it is open, then search for the exit with the direction you asked for 
//and changes the player_room for the destiny room of the exit and prints it name. If it is close don't let you pass
void Player::movement(const dynamic_array<char*>& divided_action, const dynamic_array<Exit*>& exits, unsigned int position)
{
	bool door_closed = true;
	bool recheable_room = false;

	for (int j = 0; j < exits.get_size(); j++){

		if (exits[j]->open == true && exits[j]->origen == player_room && exits[j]->name == divided_action.vector[position])
		{
		
			player_room = exits[j]->destiny;
			printf("%s\n", player_room->name);
			recheable_room = true;
			break;
				
			
		}
		else {
			if (exits[j]->open == false && exits[j]->origen == player_room)
			{
				door_closed = false;
			}
		}
	}
	if (door_closed == false) printf("You can't go this way, the path is closed\n");
		
	
	else if (recheable_room == false)
	{
		printf("You can't go this way\n");
	}
	
}


//This function lets the player open and close paths changing the boolen open from the exits
void Player::open_door(const dynamic_array<char*>& divided_action, const dynamic_array<Exit*>& exits)
{
		int counter_open = 0;						
		for (unsigned int j = 0; j < exits.get_size(); j++)
		{
			
			if (exits[j]->origen == player_room && exits[j]->name == divided_action.vector[1])
			{
				if (exits[j]->open == true)
				{
					printf("This path is already open\n");
				}
				else 
				{
					exits[j]->open = true;
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
void Player::close_door(const dynamic_array<char*>& divided_action, const dynamic_array<Exit*>& exits)
{			
		int counter_close = 0;
		for (unsigned int j = 0; j < exits.get_size(); j++)
		{

			if (exits[j]->origen == player_room && exits[j]->name == divided_action.vector[1])
			{
				if (exits[j]->open == false)
				{
					printf("This path is already closed\n");
				}
				else
				{
					exits[j]->open = false;
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



