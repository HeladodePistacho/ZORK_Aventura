#include "Mouse.h"


void Mouse::Move()
{
	int number_exits = 0;

	for (int i = 0; i < ent.get_size(); i++)
	{
		if (ent[i]->entity_type == EXIT && ent[i]->list.first_node->data == creature_room)
		{
			if (ent[i]->list.first_node->next->data != last_room_visited)
			{
				last_room_visited = creature_room;
				creature_room = ent[i]->list.first_node->next->data;
			}
			else
			{
				for (int j = 0; j < ent.get_size(); j++)
				{
					if (ent[j]->entity_type == EXIT && ent[j]->list.first_node->data == creature_room)
					{
						number_exits++;
					}
						
				}
				if (number_exits == 1)
				{
					last_room_visited = creature_room;
					creature_room = ent[i]->list.first_node->next->data;
				}
			}
		}
	}
}

void Mouse::pick()
{
	entity temp = *creature_room;
	if (temp.list.first_node != nullptr)
	{
		inventory.push_back(temp.list.first_node->data);
		creature_room->list.Erase(temp.list.first_node);
	}
}

void Mouse::drop()
{
	entity* poped = nullptr;

	inventory[0]->Change_extra_info(ITEM_DROP);
	creature_room->list.PushBack(inventory[0]);
	inventory.pop_back(poped);

}

