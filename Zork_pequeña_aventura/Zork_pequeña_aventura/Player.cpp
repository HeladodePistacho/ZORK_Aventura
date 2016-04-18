
#include "Player.h"

//This prints the room name and the description of where you are, and it's exits directions
void Player::looking(const dynamic_array<Exit*>& exits, const dynamic_array<item*>& items, const box& Box) const
{
	bool no_items = true;
	printf("%s\n", player_room->name);
	printf("%s\n", player_room->description);
	printf("There is an exit going:");
	for (unsigned int j = 0; j < exits.get_size(); j++)
	{
		if (exits[j]->origen == player_room)
		{
			printf(" %s,", exits[j]->name);
		}
	}

	printf("\nItems in the room: ");
	for (unsigned int i = 0; i < items.get_size(); i++)
	{
		if (items[i]->item_room == player_room && items[i]->dropped == true)
		{
			printf(" %s,", items[i]->name);
			no_items = false;
		}
	}
	if (Box.item_room == player_room) printf("%s\n", Box.name);
	else if (no_items) printf("none");

	printf("\n");

}

//This will give the description of the exit asked
void Player::looking_exits(const dynamic_array<char*>& divided_action, const dynamic_array<Exit*>& exits)const{
	bool no_exit = true;

	for (unsigned int j = 0; j < exits.get_size(); j++){

		if (divided_action.compare(exits[j]->name.c_str()) && exits[j]->origen == player_room)
		{
			printf("%s\n", exits[j]->description);
			no_exit = false;
		}
	}
	if (no_exit) printf("there isn't any exits in this direction\n");
}

//This will give the description of the item asked
void Player::looking_items(const dynamic_array<char*>& divided_action, const dynamic_array<item*>& items, const box& Box)const
{
	for (unsigned int i = 0; i < items.get_size(); i++)
	{
		if (items[i]->name == divided_action[1] && (items[i]->item_room == player_room || items[i]->picked == true))
		{
			printf("%s,", items[i]->description);
		}
	}

	if (Box.name == divided_action[1] && Box.item_room == player_room)
	{
		unsigned int stored = 0;

		printf("%s\n", Box.description);
		printf("Stored in box: \n");

		for (stored; stored < Box.storage.get_size(); stored++)
		{
			printf("\t*%s\n", Box.storage[stored]->name.c_str());

		}
		for (int i = 5; i > stored; i--) printf("\t*Empty\n");
	}
}



void Player::movement(const dynamic_array<char*>& divided_action, const dynamic_array<Exit*>& exits, unsigned int position)
{
	bool door_closed = true;
	bool recheable_room = false;

	for (unsigned int j = 0; j < exits.get_size(); j++){

		if (exits[j]->open == true && exits[j]->origen == player_room && exits[j]->name == divided_action[position])
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
void Player::open_door(const dynamic_array<char*>& divided_action, const dynamic_array<Exit*>& exits)const
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

void Player::close_door(const dynamic_array<char*>& divided_action, const dynamic_array<Exit*>& exits)const
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

void Player::pick(const dynamic_array<char*>& divided_action, const dynamic_array<item*>& items, const box& Box)
{

	if (inventory.get_size() == 3)
	{
		printf("Your inventory is full");
	}

	for (unsigned int i = 0; i < items.get_size(); i++)
	{
		if (items[i]->item_room == player_room && inventory.get_size() < 3 && items[i]->dropped == true && items[i]->name == divided_action.vector[1])
		{
			items[i]->dropped = false;
			items[i]->picked = true;
			inventory.push_back(items[i]);
			printf("You putted it into your inventory\n");
		}
	}

	if (Box.name == divided_action[1] && Box.item_room == player_room) printf("The Box is to heavy to get carryied\n");

}

void Player::drop(const dynamic_array<char*>&divided_action, const dynamic_array<item*>& items)
{

	item* poped = nullptr;

	for (unsigned int i = 0; i < items.get_size(); i++)
	{
		for (unsigned int j = 0; j < inventory.get_size(); j++)
		{
			if (items.vector[i] == inventory[j] && items.vector[i]->name == divided_action.vector[1])
			{
				inventory.move_element(i);
				items[i]->dropped = true;
				items[i]->picked = false;
				items[i]->item_room = player_room;
				inventory.pop_back(poped);
				printf("item dropped in the room: %s", player_room->name);
			}
		}

	}

	if (poped == nullptr)
	{
		printf("This item is not in your inventory\n");
	}

}

void Player::Get_inventory()const
{
	unsigned int nºItems = 0;
	printf("INVENTORY:\n");
	for (unsigned int i = 0; i < inventory.get_capacity(); i++)
	{
		for (nºItems; nºItems < inventory.get_size(); nºItems++)
		{
			printf("\t*%s\n", inventory[nºItems]->name.c_str());

		}
	}
	for (int i = 3; i > nºItems; i--)  printf("\t*Empty\n");

	printf("EQUIP\n");
	unsigned int nºEquiped = 0;

	for (unsigned int i = 0; i < equiped.get_capacity(); i++)
	{
		for (nºEquiped; nºEquiped < equiped.get_size(); nºEquiped++)
		{
			printf("\t*%s\n", equiped[nºEquiped]->name.c_str());
		}
	}
	for (int i = 2; i > nºEquiped; i--) printf("\t*Empty\n");


}

void Player::equip(const dynamic_array<char*>& divided_action)
{
	item* poped = nullptr;

	for (unsigned int i = 0; i < inventory.get_size(); i++)
	{
		if (inventory.vector[i]->name == divided_action.vector[1])
		{

			equiped.push_back(inventory[i]);

			for (unsigned int k = i; k < inventory.get_size(); k++)
			{
				inventory[k] = inventory[k + 1];
			}
			inventory.pop_back(poped);
			printf("Item Equiped\n");
		}
	}

	if (poped == nullptr)
	{
		printf("This item is not in your inventory\n");
	}

}

void Player::unequip(const dynamic_array<char*>& divided_action)
{
	item* poped = nullptr;

	if (inventory.get_size() == 3)
	{
		printf("Your inventory is full\n");
	}
	else{
		for (unsigned int i = 0; i < equiped.get_size(); i++)
		{
			if (equiped.vector[i]->name == divided_action[1])
			{
				inventory.push_back(equiped[i]);

				equiped.move_element(i);

				equiped.pop_back(poped);
				printf("Item Unequiped\n");
			}
		}
		if (poped == nullptr)
		{
			printf("This item is not equiped\n");
		}
	}
}

void Player::put(const dynamic_array<char*>& divided_action, box& Box)
{

	item* poped_item;

	if (Box.storage.get_size() < 5)
	{
		for (unsigned int i = 0; i < inventory.get_size(); i++)
		{
			if (inventory[i]->name == divided_action[1])
			{
				Box.storage.push_back(inventory[i]);
				inventory.move_element(i);
				inventory.pop_back(poped_item);
				printf("Item stored\n");
			}
		}

	}

	else printf("The box is full\n");
}

void Player::get(const dynamic_array<char*>& divided_action, box& Box)
{
	item* poped;

	if (inventory.get_size() < 3)
	{
		for (unsigned int i = 0; i < Box.storage.get_size(); i++)
		{
			if (Box.storage[i]->name == divided_action[1])
			{
				inventory.push_back(Box.storage[i]);
				printf("%s is now on your inventory\n", Box.storage[i]->name.c_str());
				Box.storage.move_element(i);
				Box.storage.pop_back(poped);
			}
		}
	}
	else printf("Your inventory is full\n");
}

void Player::combine(const dynamic_array<item*>& items)
{
	item* poped;

	if (equiped.get_size() == 2)
	{

		if (equiped.vector[0]->craftable_item1 == equiped.vector[1]->craftable_item1 || equiped.vector[0]->craftable_item1 == equiped.vector[1]->craftable_item2)
		{
			printf("You created the %s\n", equiped.vector[0]->craftable_item1->name.c_str());
			equiped.pop_back(poped);
			equiped.push_front(equiped.vector[0]->craftable_item1);
			equiped.pop_back(poped);
			equiped.vector[0]->picked = true;
		}

		else {
			if (equiped.vector[0]->craftable_item2 == equiped.vector[1]->craftable_item1 || equiped.vector[0]->craftable_item2 == equiped.vector[1]->craftable_item2)
			{
				printf("You created the %s\n", equiped.vector[0]->craftable_item2->name.c_str());
				equiped.pop_back(poped);
				equiped.push_front(equiped.vector[0]->craftable_item1);
				equiped.pop_back(poped);
				equiped.vector[0]->picked = true;
			}

		}
	}
	else printf("You will need one more item to combine\n");

}



