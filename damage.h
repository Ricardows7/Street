#ifndef __DAMAGE__
#define __DAMAGE__

#define PUNCH_DAMAGE 3
#define PUNCH_COOLDOWN 3 * 30
#define KICK_DAMAGE 5
#define KICK_COOLDOWN 5 * 30

#define BDAMAGE 5
#define BVELOCITY 5
#define BCOOLDOWN 10

typedef struct{
	int timers[2];
	int range[2];
}actions;

typedef struct special{
	int timer;
	int damage;
}special;

actions* create_action();

bullet* create_bullet (int x, int y, int dam, int vel, bool track);

special* create_special();

special* special_move(special *element);

special* special_destroy(special *element);

#endif
