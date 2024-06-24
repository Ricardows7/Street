#ifndef __DAMAGE__
#define __DAMAGE__

typedef struct{
	int action[2];
	int timers[2];
	int range;
}actions;

typedef struct special{
	int timer;
	int x;
	int y;
	int trajectory;
	int damage;
	int velocity;
	special *next;
}special;

special* create_special();

special* special_move(special *element);

special* special_destroy(special *element);

#endif
