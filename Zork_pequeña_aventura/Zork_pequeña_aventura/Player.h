#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Creature.h"
#include "entity.h"
#include "Clock.h"
#include "dinamic_array.h"

class Player : public creature
{
public:
	dynamic_array<entity*> inventory;
	dynamic_array<entity*> equiped;
public:

	Player(const char* nam, const char* des, entity* initial_room, unsigned int equip) : creature(nam, des, initial_room), equiped(equip)
	{
		life = 10;
		damage = 2;

		entity_type = PLAYER;
	}



	void Update()
	{
		if (equiped[0] != nullptr)
		{
			damage = equiped[0]->damage;
		}
		else damage = 2;

		if (is_dead())
		{
			printf("You have died in a painfull way, and, for sure, your brother too\n more luck the next time\n");
			getchar();
		}
	}
	
	void movement(const dynamic_array<char*>&, const dynamic_array<entity*>&, unsigned int);
	void looking(const dynamic_array<entity*>&)const;
	void looking_exits(const dynamic_array<char*>&, const dynamic_array<entity*>&)const;
	void looking_items(const dynamic_array<char*>&, const dynamic_array<entity*>&)const;
	void open_door(const dynamic_array<char*>&, const dynamic_array<entity*>&)const;
	void close_door(const dynamic_array<char*>&, const dynamic_array<entity*>&)const;
	void pick(const dynamic_array<char*>&, const dynamic_array<entity*>&);
	void drop(const dynamic_array<char*>&, const dynamic_array<entity*>&);
	void Get_inventory()const;
	void equip(const dynamic_array<char*>&);
	void unequip(const dynamic_array<char*>&);
	void put(const dynamic_array<char*>&, const dynamic_array<entity*>&);
	void get(const dynamic_array<char*>&, const dynamic_array<entity*>&);
	void combine(const dynamic_array<entity*>&);
	void attack(const dynamic_array<entity*>&, const dynamic_array<char*>&)const;
	bool is_dead() const;


	
};

#endif