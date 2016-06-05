#include "Spider.h"

void Spider::attack()
{
	main_player->life -= damage;
	printf("Big Spider has attackeed you and dealed %i damage\n", damage);
}

bool Spider::is_dead() const
{
	return life <= 0;
}