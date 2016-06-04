
#include "Player.h"

//This prints the room name and the description of where you are, and it's exits directions
void Player::looking(const dynamic_array<entity*>& entities) const
{
	bool no_items = true;
	printf("%s\n", creature_room->name);
	printf("%s\n", creature_room->description);
	printf("There is an exit going:");
	for (unsigned int j = 0; j < entities.get_size(); j++)
	{
		if (entities[j]->entity_type == EXIT && entities[j]->list.first_node->data == creature_room)
		{
			printf(" %s,", entities[j]->name);
		}	
	}

	printf("\nItems in the room: ");
	for (unsigned int i = 0; i < entities.get_size(); i++)
	{
		
		if (entities[i] == creature_room)
		{

			entity temp = *entities[i];

			while (temp.list.first_node != nullptr)
			{
				printf(" %s,", temp.list.first_node->data->name.c_str());
				no_items = false;
				temp.list.first_node = temp.list.first_node->next;
			}
		}
	}

	if (no_items) printf("none");

	printf("\n");

}

//This will give the description of the exit asked
void Player::looking_exits(const dynamic_array<char*>& divided_action, const dynamic_array<entity*>& entities)const
{
	bool no_exit = true;

	for (unsigned int j = 0; j < entities.get_size(); j++){

		if (divided_action.compare(entities[j]->name.c_str()) && entities[j]->entity_type == EXIT && entities[j]->list.first_node->data == creature_room)
		{
			printf("%s\n", entities[j]->description);
			no_exit = false;
		}
	}
	if (no_exit) printf("there isn't any exits in this direction\n");
}

//This will give the description of the item asked
void Player::looking_items(const dynamic_array<char*>& divided_action, const dynamic_array<entity*>& entities)const
{
	//LOOKS ITEMS INTO ROOM
	int stored = 0;
	entity temp = *creature_room;
	while (temp.list.first_node != nullptr)
	{
		if (temp.list.first_node->data->name == divided_action[1])
		{
			printf("%s\n", temp.list.first_node->data->description);

			if (temp.list.first_node->data->Look_extra_info(ITEM_FILL))
			{
				entity temp_box = *temp.list.first_node->data;
				printf("Stored in box: \n");

				while (temp_box.list.first_node != nullptr)
				{

					printf("\t%s\n", temp_box.list.first_node->data->name.c_str());
					temp_box.list.first_node = temp_box.list.first_node->next;
					stored++;

				}
				for (int k = stored; k <= 2; k++) printf("\t*Empty\n");
			}	
		}
		temp.list.first_node = temp.list.first_node->next;
	}

	//LOOKS ITEMS INTO INVENTORY
	for (int i = 0; i < inventory.get_size(); i++)
	{
		if (inventory[i] != nullptr)
		{
			if (inventory[i]->name == divided_action[1])
				printf("%s", inventory[i]->description);
		}
	}
		
}

void Player::movement(const dynamic_array<char*>& divided_action, const dynamic_array<entity*>& entities, unsigned int position)
{
	bool door_closed = true;
	bool recheable_room = false;

	for (unsigned int j = 0; j < entities.get_size(); j++){

		if (entities[j]->entity_type == EXIT && entities[j]->Look_extra_info(EXIT_SATE) == true && entities[j]->list.first_node->data == creature_room && entities[j]->name == divided_action[position])
		{
			creature_room = entities[j]->list.first_node->next->data;
			printf("%s\n", creature_room->name);
			recheable_room = true;
			break;
		}
		else {
			if (entities[j]->Look_extra_info(EXIT_SATE) == false && entities[j]->entity_type == EXIT && entities[j]->list.first_node->data == creature_room)
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
void Player::open_door(const dynamic_array<char*>& divided_action, const dynamic_array<entity*>& entities)const
{
	int counter_open = 0;
	for (unsigned int j = 0; j < entities.get_size(); j++)
	{

		if (entities[j]->entity_type == EXIT && entities[j]->name == divided_action.vector[1] && entities[j]->list.first_node->data == creature_room)
		{
			if (entities[j]->Look_extra_info(EXIT_SATE))
			{
				printf("This path is already open\n");
			}
			else
			{
				entities[j]->Change_extra_info(EXIT_SATE);
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

void Player::close_door(const dynamic_array<char*>& divided_action, const dynamic_array<entity*>& entities)const
{
	int counter_close = 0;
	for (unsigned int j = 0; j < entities.get_size(); j++)
	{

		if (entities[j]->name == divided_action.vector[1] && entities[j]->entity_type == EXIT && entities[j]->list.first_node->data == creature_room)
		{
			if (entities[j]->Look_extra_info(EXIT_SATE) == false)
			{
				printf("This path is already closed\n");
			}
			else
			{
				entities[j]->Change_extra_info(EXIT_SATE);
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

void Player::pick(const dynamic_array<char*>& divided_action, const dynamic_array<entity*>& entities)
{

	if (inventory.get_size() == 3)
	{
		printf("Your inventory is full");
	}

	else
	{
		entity temp = *creature_room;

		while (temp.list.first_node != nullptr)
		{
			if (temp.list.first_node->data->name == divided_action.vector[1])
			{
				
				inventory.push_back(temp.list.first_node->data);
				creature_room->list.Erase(temp.list.first_node);
				printf("You putted it into your inventory\n");
				break;
			}
			temp.list.first_node = temp.list.first_node->next;
		}

	}

}

void Player::drop(const dynamic_array<char*>&divided_action, const dynamic_array<entity*>& entities)
{
	entity* poped = nullptr;

	for (unsigned int j = 0; j < inventory.get_size(); j++)
	{
		if (inventory[j]->name == divided_action.vector[1])
		{
			inventory[j]->Change_extra_info(ITEM_DROP);
			creature_room->list.PushBack(inventory[j]);
			inventory.move_element(j);
			inventory.pop_back(poped);
			printf("item dropped in the room: %s", creature_room->name);
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
	entity* poped = nullptr;

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
	entity* poped = nullptr;

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

void Player::put(const dynamic_array<char*>& divided_action, const dynamic_array<entity*>& entities)
{
	entity* poped_item;
	bool full_box = false;
	my_list<entity*> temp = creature_room->list;

	while (creature_room->list.first_node != nullptr)
	{
		if (creature_room->list.first_node->data->Look_extra_info(ITEM_FILL))
		{
			if (creature_room->list.first_node->data->list.size() > 2)
			{
				full_box = true;
				break;
			}
			else
			{	
				for (int i = 0; i < inventory.get_size(); i++)
				{
					if (inventory[i]->name == divided_action[1])
					{
						creature_room->list.first_node->data->list.PushBack(inventory[i]);
						inventory.move_element(i);
						inventory.pop_back(poped_item);
						printf("Item stored\n");
					}
				}
			}

		}

		creature_room->list.first_node = creature_room->list.first_node->next;
	}

	creature_room->list.first_node = temp.first_node;
	if (full_box) printf("The box is full\n");
}

void Player::get(const dynamic_array<char*>& divided_action, const dynamic_array<entity*>& entities)
{
	entity* poped;
	bool empty_box = true;
	bool is_here_box = false;

	my_list<entity*> temp = creature_room->list;

	if (inventory.get_size() > 2)
	{

		while (creature_room->list.first_node != nullptr)
		{
			if (creature_room->list.first_node->data->Look_extra_info(ITEM_FILL))
			{
				entity* box_temp = creature_room->list.first_node->data;

				while (creature_room->list.first_node->data->list.first_node != nullptr)
				{
					if (creature_room->list.first_node->data->list.first_node->data->name == divided_action[1])
					{
						inventory.push_back(creature_room->list.first_node->data->list.first_node->data);
						printf("%s is now on your inventory\n", creature_room->list.first_node->data->list.first_node->data->name.c_str());
						creature_room->list.first_node->data->list.Erase(creature_room->list.first_node->data->list.first_node);
						empty_box = false;
						break;
					}
					creature_room->list.first_node->data->list.first_node = creature_room->list.first_node->data->list.first_node->next;
				}
				creature_room->list.first_node->data->list = box_temp->list;
				is_here_box = true;
			}
			creature_room->list.first_node = creature_room->list.first_node->next;
		}

		creature_room->list.first_node = temp.first_node;
		

	}
	else
	{
		if (empty_box)
			printf("The box is empty\n");

		else if (is_here_box)
			printf("The box is not in your room\n");

		else printf("Your inventory is full\n");
	}	
}

void Player::combine(const dynamic_array<entity*>& entities)
{
	entity* poped = nullptr;

	if (equiped.get_size() == 2)
	{

		if (equiped.vector[0]->list.first_node->data == equiped.vector[1]->list.first_node->data || equiped.vector[0]->list.first_node == equiped.vector[1]->list.first_node->next)
		{
			printf("You created the %s\n", equiped.vector[0]->list.first_node->data->name.c_str());
			equiped.pop_back(poped);
			equiped.push_front(equiped.vector[0]->list.first_node->data);
			equiped.pop_back(poped);
			equiped.vector[0]->Change_extra_info(ITEM_PICK);
		}

		else {
			if (equiped.vector[0]->list.first_node->next == equiped.vector[1]->list.first_node || equiped.vector[0]->list.first_node->next == equiped.vector[1]->list.first_node->next)
			{
				printf("You created the %s\n", equiped.vector[0]->list.first_node->next->next->data->name.c_str());
				equiped.pop_back(poped);
				equiped.push_front(equiped.vector[0]->list.first_node->data);
				equiped.pop_back(poped);
				equiped.vector[0]->Change_extra_info(ITEM_PICK);
			}

		}
	}
	else printf("You will need one more item to combine\n");

	if (poped == nullptr)
	{
		printf("You cant' combine this items\n");
	}

}



