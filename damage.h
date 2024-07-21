#ifndef __DAMAGE__
#define __DAMAGE__

#define PUNCH_DAMAGE 3
#define KICK_DAMAGE 5

#define SPECIAL_STAMINA 20
#define KICK_STAMINA 5
#define PUNCH_STAMINA 3
#define DEFENSE_UP_STAMINA 0.5
#define DEFENSE_DOWN_STAMINA 0.5
#define STAMINA_RECOVERY 0.3

int check_hit (int min_x, int max_x, int min_y, int max_y, int x, int y, int lenght, int width);

void update_damage (int dam, int *hp, int *stun, bool up, bool down, int min_x, int max_x, int min_y,
int max_y, int x, int y, int lenght, int width);

void stamina_update (int state, bool drop);

#endif
