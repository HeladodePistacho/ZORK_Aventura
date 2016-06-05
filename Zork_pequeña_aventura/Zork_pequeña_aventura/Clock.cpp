#include "Clock.h"

void Clock(int* min, int* dec, int* sec)
{
	

	if (*sec < 0)
	{
		*sec = 9;
		*dec -= 1;
	}

	if (*dec < 0)
	{
		*dec = 5;
		*min -= 1;
	}
	*sec -= 1;

}