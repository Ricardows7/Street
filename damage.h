#ifndef __DAMAGE__
#define __DAMAGE__

#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "joystick.h"

#define PUNCH_DAMAGE 5
#define KICK_DAMAGE 7

#define LEO_SPECIAL 30
#define RAFA_SPECIAL 0.4
#define DONA_SPECIAL 0.6

#define STUN_TIME 1

#define SPECIAL_STAMINA 50
#define KICK_STAMINA 7
#define PUNCH_STAMINA 5
#define DEFENSE_STAMINA 0.5
#define STAMINA_RECOVERY 0.05

#define KICK_AIR_STAMINA 20
#define PUNCH_AIR_STAMINA 15

int check_hit (int min_x, int max_x, int min_y, int max_y, int x, int y, int lenght, int width);

int check_hit_box (int *min_x, int *max_x, int *min_y, int *max_y, int move, int id, int x, int y, int length, int width, int state_y, bool right, int clock, int state_x, float *stamina);

void update_damage (float dam, float *hp, int *stun, bool up, bool down, int min_x, int max_x, int min_y,
int max_y, int x, int y, int lenght, int width, int store, bool *hitted);

void stamina_update (int state, bool drop, float *stamina, bool air);

#endif
