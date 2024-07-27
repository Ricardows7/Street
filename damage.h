#ifndef __DAMAGE__
#define __DAMAGE__

#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "joystick.h"

#define PUNCH_DAMAGE 3
#define KICK_DAMAGE 5

#define STUN_TIME 15

#define SPECIAL_STAMINA 20
#define KICK_STAMINA 7
#define PUNCH_STAMINA 5
#define DEFENSE_STAMINA 0.5
#define STAMINA_RECOVERY 0.3

int check_hit (int min_x, int max_x, int min_y, int max_y, int x, int y, int lenght, int width);

void check_hit_box (int *min_x, int *max_x, int *min_y, int *max_y, int move, int id, int x, int y, int length, int width, int state_y, bool right);

void update_damage (int dam, float *hp, int *stun, bool up, bool down, int min_x, int max_x, int min_y,
int max_y, int x, int y, int lenght, int width);

void stamina_update (int state, bool drop, float *stamina);

#endif
