#ifndef _SPIDER_H_
#define _SPIDER_H_

#include "Creature.h"
#include "entity.h"
#include "Player.h"
#include "dinamic_array.h"

enum STATE {IDLE, ATTACK};

class Spider : public creature
{
public:

	STATE spider_state;
	Player* main_player;

public:

	Spider(const char* nam, const char* des, entity* initial_room, Player* plyr) : creature(nam, des, initial_room), main_player(plyr)
	{
		life = 20;
		damage = 3;
		list.PushBack(initial_room);
		spider_state = IDLE;
		entity_type = SPIDER;
	}
	
	void attack();
	bool is_dead() const;
	
	void Update()
	{
		if (spider_state == ATTACK)
			attack();

		if (is_dead())
		{
			printf("You defeated the Big Spider and saved your brother \n CONGRATS AND THANKYOU FOR PLAYING\n");
			getchar();
		}
	}

	bool Look_extra_info(INFO_TYPE STATE)
	{
		return is_dead();
	}

	void Change_extra_info(INFO_TYPE state)
	{
		if (spider_state == IDLE)
			spider_state = ATTACK;
		else spider_state = IDLE;
	}

};

#endif