#define _CRT_SECURE_NO_WARNINGS
#include "World.h"
#include "Exits.h"
#include "Player.h"
#include "Rooms.h"
#include "Box.h"
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

	//BOX
	Box = new box("Box", "This box can store items", Desk);

	//ITEMS

	
	item* PoweredHook = new item("PoweredHook", "This awesome improved hook will help you to reach the wardrobe roof", false, nullptr, nullptr, nullptr);
	item* NutsGunLoaded = new item("NutsGunLoaded", "Fully reloaded and ready to shoot", false, nullptr, nullptr, nullptr);
	item* Catapult = new item("Catapult", "Perfect to reach the wardrobe roof, you should find a clear place to use it", false, nullptr, nullptr, nullptr);
	item* FireNeedle = new item("FireNeedle", "Improved needle with a incandescent needle tip, it is a super awesome weapon", false, nullptr, nullptr, nullptr);
	item* NutsGun = new item("NutsGun", "This powerfull weapon is perfect to fight from distance, but you have no ammo", false, nullptr, NutsGunLoaded, nullptr);
	item* Hook = new item("Hook", "This hook will help you to reach higher positions", false, nullptr, PoweredHook, nullptr);
	item* BlueWire = new item("PenWire", "A elastic wire that can be used to create new items", true, Desk, NutsGun, PoweredHook);
	item* BlackPlastic = new item("BlackPlastic", "This plastic have been used as a blowgun", true, Desk, NutsGun, nullptr);
	item* Shoelace = new item("Shoelace", "This item is usefull to craft recheable items", true, UnderBed, Hook, Catapult);
	item* Needle = new item("Needle", "A sharp needle, that can be a nice weapon", true, BehindDoor, Hook, FireNeedle);
	item* MouseTrap = new item("MouseTrap", "Seems that the cheese have been eaten, but the mouse is still alive", true, MouseCave, Catapult, nullptr);
	item* Nuts = new item("Nuts", "A delicious snack for humans", true, BedsideTable, NutsGunLoaded, nullptr);
	item* MatchStick = new item("Matchstick", "A usefull matchstick that can provide light and heat", true, Desk, FireNeedle, nullptr);
	
	
	world_items.push_back(PoweredHook);
	world_items.push_back(NutsGunLoaded);
	world_items.push_back(Catapult);
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
		if (divided_action.get_size() == 1) player->looking(world_exits, world_items, *Box);
		else
		{
			if (divided_action.compare(directions)) player->looking_exits(divided_action, world_exits);
			else player->looking_items(divided_action, world_items, *Box);
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
	
	//PICK
	if (divided_action.compare(comands, 6))
	{
		player->pick(divided_action, world_items, *Box);
	}
	
	//DROP
	if (divided_action.compare(comands, 7))
	{
		player->drop(divided_action, world_items);
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
		player->put(divided_action, *Box);
	}

	//GET
	if (divided_action.compare(comands, 15) && divided_action.compare(comands, 16))
	{
		player->get(divided_action, *Box);
	}

	//COMBINE
	if (divided_action.compare(comands, 17))
	{
		player->combine(world_items);
	}
}


