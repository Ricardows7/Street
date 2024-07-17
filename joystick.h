#ifndef __JOYSTICK__
#define __JOYSTICK__

#include <stdlib.h>
#include <stdio.h>
#include <bool.h>

#define WALK_RIGHT 2
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
	bool state;
} joystick;

joystick* joystick_create();

void joystick_destroy (joystick *element);

void joystick_activate (joystick *element, int type, long move);

void joystick_deactivate (joystick *element, int type, long move);

#endif
