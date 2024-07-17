#ifndef __JOYSTICK__
#define __JOYSTICK__

#include <stdlib.h>
#include <stdio.h>
#include <bool.h>

typedef struct joystick{
	long acumulation;
	int timer;
	bool state;
	bool air;
} joystick;

joystick* joystick_create();

void joystick_destroy (joystick *element);

void joystick_activate (joystick *element);

void joystick_deactivate (joystick *element);

#endif
