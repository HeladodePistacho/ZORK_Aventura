#define _CRT_SECURE_NO_WARNINGS
#include "World.h"
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include "Mouse.h"
#include "Creature.h"
#include "Items.h"
#include <stdio.h>



//This method creates the player, the rooms array and the exits array.
void World::CreateWorld()
{
	

	//ITEMS	
	item* PoweredHook = new item("PoweredHook", "This awesome improved hook will help you to reach the wardrobe roof", false, false, nullptr, nullptr);
	item* NutsGunLoaded = new item("NutsGunLoaded", "Fully reloaded and ready to shoot", false, false, nullptr, nullptr);
	item* Catapult = new item("Catapult", "Perfect to reach the wardrobe roof, you should find a clear place to use it", false, false, nullptr, nullptr);
	item* FireNeedle = new item("FireNeedle", "Improved needle with a incandescent needle tip, it is a super awesome weapon", false, false,  nullptr, nullptr);
	item* NutsGun = new item("NutsGun", "This powerfull weapon is perfect to fight from distance, but you have no ammo", false, false, NutsGunLoaded, nullptr);
	item* Hook = new item("Hook", "This hook will help you to reach higher positions", false, false,  PoweredHook, nullptr);
	item* BlueWire = new item("PenWire", "A elastic wire that can be used to create new items", true, false,  NutsGun, PoweredHook);
	item* BlackPlastic = new item("BlackPlastic", "This plastic have been used as a blowgun", true, false,  NutsGun, nullptr);
	item* Shoelace = new item("Shoelace", "This item is usefull to craft recheable items", true, false,  Hook, Catapult);
	item* Needle = new item("Needle", "A sharp needle, that can be a nice weapon", true, false,  Hook, FireNeedle);
	item* MouseTrap = new item("MouseTrap", "Seems that the cheese have been eaten, but the mouse is still alive", true, false,  Catapult, nullptr);
	item* Nuts = new item("Nuts", "A delicious snack for humans", true, false,  NutsGunLoaded, nullptr);
	item* Matchstick = new item("Matchstick", "A usefull matchstick that can provide light and heat", true, false,  FireNeedle, nullptr);
	item* Box = new item("Box", "This box can store items", true, true,  nullptr, nullptr);
	
	entities.push_back(PoweredHook);
	entities.push_back(NutsGunLoaded);
	entities.push_back(Catapult);
	entities.push_back(FireNeedle);
	entities.push_back(NutsGun);
	entities.push_back(Hook);
	entities.push_back(BlueWire);
	entities.push_back(BlackPlastic);
	entities.push_back(Shoelace);
	entities.push_back(Needle);
	entities.push_back(MouseTrap);
	entities.push_back(Nuts);
	entities.push_back(Matchstick);
	entities.push_back(Box);

	//ROOMS
	Rooms* CenterRoom = new Rooms("Center of the room", "A lightly place in the middle of the room, there's nothing interesting to do, but you can go everywhere from here", nullptr, nullptr, nullptr);
	Rooms* Heater = new Rooms("In Front of the Heater", "A warm place under some book shelves, between the wardrobe and the desk", nullptr, nullptr, nullptr);
	Rooms* UnderWardrobe = new Rooms("Under the wardrobe", "Your house, it is a wet but homely place", nullptr, nullptr, nullptr);
	Rooms* FrontWardrobe = new Rooms("Front of the wardrobe", "A large and empty place in front of your home", nullptr, nullptr, nullptr);
	Rooms* BehindDoor = new Rooms("Behind the Door", "A really dark place, you will need something to watch if there's something in front of you", Needle, nullptr, nullptr);
	Rooms* BookShelves = new Rooms("Book Shelves", "A high place with some adventure books and comics, high enough to reach the wardrobe top", Box, nullptr, nullptr);
	Rooms* Desk = new Rooms("Desk", "A lightly place next to the window with a half-eated sandwich, a laptop and some jambled stuff", BlackPlastic, BlueWire, Matchstick);
	Rooms* UnderBed = new Rooms("Under the Bed", "This place is a mess, really dirty and full of dust, you can also see a tiny door", Shoelace, nullptr, nullptr);
	Rooms* Bed = new Rooms("Bed", "Really soft and comfortable place, the bedside table seems reacheable from here", nullptr, nullptr, nullptr);
	Rooms* MouseCave = new Rooms("Mouse cave", "A place which stinks of cheese, there is a mouse trap here but seems that the animal is smarter than the humans", MouseTrap, nullptr, nullptr);
	Rooms* BedsideTable = new Rooms("Bedside Table", "Near the bed, there is a plate with some snacks and another with the rests of those snacks", Nuts, nullptr, nullptr);
	Rooms* AboveWardrobe = new Rooms("Above the Wardrobe", "A dusty and dark place, your brother is here waiting for you to fight the spider ans save him", nullptr, nullptr, nullptr);
	Rooms* UnderDesk = new Rooms("Under the Desk", "A shadowy place, home of Rusty the old man, you can also reach some drawers from here", nullptr, nullptr, nullptr);

	entities.push_back(CenterRoom);
	entities.push_back(Heater);
	entities.push_back(UnderWardrobe);
	entities.push_back(FrontWardrobe);
	entities.push_back(BehindDoor);
	entities.push_back(BookShelves);
	entities.push_back(Desk);
	entities.push_back(UnderBed);
	entities.push_back(Bed);
	entities.push_back(MouseCave);
	entities.push_back(BedsideTable);
	entities.push_back(AboveWardrobe);
	entities.push_back(UnderDesk);

	
	//EXITS
	entities.push_back(new Exit("north", "You will go in front of the heater", CenterRoom, Heater, true));
	entities.push_back(new Exit("east", "You will go in front of the wardrobe", CenterRoom, FrontWardrobe, true));
	entities.push_back(new Exit("south", "You will go inside the darkness of under the bed", CenterRoom, UnderBed, true));
	entities.push_back(new Exit("west", "You will go the centre of the room", FrontWardrobe, CenterRoom, true));
	entities.push_back(new Exit("north", "That's the way to your home", FrontWardrobe, UnderWardrobe, true));
	entities.push_back(new Exit("south", "The path will get darker as you get closer the door", FrontWardrobe, BehindDoor, true));
	entities.push_back(new Exit("south", "This is the south exit of your home", UnderWardrobe, FrontWardrobe, true));
	entities.push_back(new Exit("west", "This is the west exit of your home, to the warm heater", UnderWardrobe, Heater, true));
	entities.push_back(new Exit("east", "This is the east way to your home", Heater, UnderWardrobe, true));
	entities.push_back(new Exit("south", "This path will get you into the centre of the room", Heater, CenterRoom, true));
	entities.push_back(new Exit("west", "A dark and wet path to under the desk", Heater, UnderDesk, true));
	entities.push_back(new Exit("east", "A dark and warm path to the heater", UnderDesk, Heater, true));
	entities.push_back(new Exit("up", "You could go this way if the drawers were open", UnderDesk, Desk, false));
	entities.push_back(new Exit("east", "A scary jump to reach the book shelves", Desk, BookShelves, true));
	entities.push_back(new Exit("down", "You can descend using the drawers as a stairs", Desk, UnderDesk, true));
	entities.push_back(new Exit("north", "This path is getting you to the centre of the room", UnderBed, CenterRoom, true));
	entities.push_back(new Exit("south", "This path is full of animal hair", UnderBed, MouseCave, false));
	entities.push_back(new Exit("up", "You can climb to the bed using the bed sheet", UnderBed, Bed, true));
	entities.push_back(new Exit("west", "it seems that you can reach the bedside table", Bed, BedsideTable, true));
	entities.push_back(new Exit("east", "This will return you to the bed", BedsideTable, Bed, true));
	entities.push_back(new Exit("north", "The path conects the stinky mouse cave with the under bed", MouseCave, UnderBed, true));
	entities.push_back(new Exit("north", "A path that is getting shinnier as you approach the wardrobe", BehindDoor, FrontWardrobe, true));
	entities.push_back(new Exit("east", "A scarier jump to the above wardrobe", BookShelves, AboveWardrobe, true));
	entities.push_back(new Exit("west", "A jump to the desk", BookShelves, Desk, true));
	entities.push_back(new Exit("west", "A jump from the dusty wardrobe to the bookshelves", AboveWardrobe, BookShelves, true));
	entities.push_back(new Exit("down", "You can descend using the same bed sheet that you used to get here", Bed, UnderBed, true));

	//PLAYER
	player = new Player("", "", Desk, 2);


	entities.push_back(new Mouse("Mouse", "", MouseCave, entities));

	my_string dir("north south west east up down n s w e");
	dir.tokenize(" ", directions);
	
	my_string com("exit help look go open close pick drop inventory inv i equip unequip put into get from combine");
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
	
		printf("Welcome to Zork\nControls:\n");
		printf("\n*[exit] to close the game\n");
		printf("*[go] + [north, south, west, east, up, down] or [north, south, west, east, up, down] to move\n");
		printf("*[look] to see general information of the room where you are\n");
		printf("*[look] + [north, south, west, east, up, down] to see a description of the room's exits\n");
		printf("*[look] + <item> to see a description of the room's items and, if it is the box, also his content\n");
		printf("*[open] + [north, south, west, east, up, down] to open a closed exit\n");
		printf("*[close] + [north, south, west, east, up, down] to close a opened exit\n");
		printf("*[pick] + <item> to take a item from the room to the inventory\n");
		printf("*[drop] + <item> to let a item in the room from the inventory\n");
		printf("*[inventory, inv, i] to watch the inventory and the equiped items\n");
		printf("*[equip] + <item> to move items from the inventory to your hands\n");
		printf("*[unequip] + <item> to move the items from your hands to the inventory\n");
		printf("*[put] + <item> + [into] + [Box] to move a item from your inventory into the box\n");
		printf("*[get] + <item> + [from] + [Box] to move an item from the box to your inventory\n");
		printf("*[combine] to create a new item with the ones that are equiped\n");
		printf("\n To run the Zork propierly write the names of the items exactly how they are when you use comand look, for example\n");
	}

	//LOOK
	if (divided_action.compare(comands, 2))
	{
		if (divided_action.get_size() == 1) player->looking(entities);
		else
		{
			if (divided_action.compare(directions)) player->looking_exits(divided_action, entities);
			else player->looking_items(divided_action, entities);
		}		
	}

	//MOVEMENT
	if (divided_action.compare(comands, 3) && divided_action.compare(directions))
		player->movement(divided_action, entities, 1);

	else 
	{ 
		if (divided_action.compare(directions) && divided_action.get_size() == 1) 
		player->movement(divided_action, entities, 0); 
	}
	
	//OPEN
	if (divided_action.compare(comands, 4))
	{
		if (divided_action.compare(directions))
		{
			player->open_door(divided_action, entities);
		}
		else printf("I need a direction using this comand\n");
	}

	//CLOSE
	if (divided_action.compare(comands, 5))
	{
		if (divided_action.compare(directions))
		{
			player->close_door(divided_action, entities);
		}
		else printf("I need a direction using this comand\n");
	}
	
	//PICK
	if (divided_action.compare(comands, 6))
	{
		player->pick(divided_action, entities);
	}
	
	//DROP
	if (divided_action.compare(comands, 7))
	{
		player->drop(divided_action, entities);
	}

	//WATCH INVENTORY
	if (divided_action.compare(comands, 8) || divided_action.compare(comands, 9) || divided_action.compare(comands, 10))
	{
		player->Get_inventory();
	}

	//EQUP
	if (divided_action.compare(comands, 11))
	{
		player->equip(divided_action);
	}

	//UNEQUIP
	if (divided_action.compare(comands, 12))
	{
		player->unequip(divided_action);
	}

	//PUT INTO
	if (divided_action.compare(comands, 13) && divided_action.compare(comands, 14))
	{
		player->put(divided_action, entities);
	}

	//GET
	if (divided_action.compare(comands, 15) && divided_action.compare(comands, 16))
	{
		player->get(divided_action, entities);
	}

	//COMBINE
	if (divided_action.compare(comands, 17))
	{
		player->combine(entities);
	}
}


