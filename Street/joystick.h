#ifndef __JOYSTICK__
#define __JOYSTICK__

#include <stdlib.h>

typedef struct joystick{
	unsigned char right;
	unsigned char left;
	unsigned char down;
	unsigned char defense;
	unsigned char air;	//Será alterado somente na função de pulo!
} joystick;

joystick* joystick_create();

void joystick_destroy (joystick *element);

void joystick_right (joystick *element, int type);

void joystick_left (joystick *element, int type);

void joystick_down (joystick *element, int type);

void joystick_defense (joystick *element, int type);

#endif
