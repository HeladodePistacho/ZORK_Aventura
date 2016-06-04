#ifndef EXITS
#define EXITS

#include "entity.h"

class Exit : public entity
{
public:
	
	bool open;

public:

	Exit(const char* direction, const char* description, entity* orig, entity* dest, bool op) : entity(direction, description), open(op)
	{
		entity_type = EXIT;	
		list.PushBack(orig);
		list.PushBack(dest);
	}
	
	bool Look_extra_info(INFO_TYPE opened_exit) const
	{	
		if (opened_exit == EXIT_SATE)
			return open;
	}

	void Change_extra_info(INFO_TYPE exit_info)
	{
		if (exit_info == EXIT_SATE)
		{
			if (open)
				open = false;
			else open = true;
		}
	}
};

#endif