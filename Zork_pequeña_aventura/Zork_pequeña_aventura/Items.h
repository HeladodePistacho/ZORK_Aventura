
#ifndef _ITEMS_
#define _ITEMS_

#include "entity.h"
class Rooms;

class item : public entity
{
public:
	
	bool picked;
	bool dropped;
	bool fillable;

public:

	item(const char* nam, const char* des, bool drop, bool fill, entity* craft_item, entity* craft_item2, int dmg) : entity(nam, des), dropped(drop), fillable(fill)
	{
		entity_type = ITEM;
		damage = dmg;

		picked = false;

		if (craft_item != nullptr)
			list.PushBack(craft_item);

		if (craft_item2 != nullptr)
			list.PushBack(craft_item2);

	}

	bool Look_extra_info(INFO_TYPE item_info) const
	{
		if (item_info == ITEM_DROP)
			return dropped;

		if (item_info == ITEM_FILL)
			return fillable;

		if (item_info == ITEM_PICK)
			return picked;
	}

	void Change_extra_info(INFO_TYPE item_info)
	{
		if (item_info == ITEM_DROP)
		{
			if (dropped)
				dropped = false;
			else dropped = true;
		}

		if (item_info == ITEM_FILL)
		{
			if (fillable)
				fillable = false;
			else fillable = true;
		}

		if (item_info == ITEM_PICK)
		{
			if (picked)
				picked = false;
			else picked = true;
		}
	}


};

#endif