#ifndef __JOYSTICK__
#define __JOYSTICK__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "damage.h"

#define WALK_RIGHT 29
#define WALK_LEFT 3
#define JUMP 5
#define GET_DOWN 7
#define DEFENSE_UP 11
#define DEFENSE_DOWN 13
#define PUNCH 17
#define KICK 19
#define SPECIAL 23

typedef struct joystick{
	long acumulation;
	int timer;
	int state;
	bool change;
} joystick;

joystick* joystick_create();

void joystick_destroy (joystick *element);

void joystick_activate (joystick *element, int type, long move);

void joystick_deactivate (joystick *element, int type, long move);

int choose_move_y (joystick *element, joystick *aux, int stun);

int choose_move_x (joystick *element, joystick *aux, float stamina, int stun);

int verify_action (int value);

#endif
