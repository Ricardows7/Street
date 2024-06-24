#ifndef __BEGIN__ 												
#define __BEGIN__																									
#include <stdbool.h>
#include <stdio.h>

#include "joystick.h"

#define STREET_STEP 20																									
typedef struct {
	unsigned char lenght;
	unsigned char width;
	unsigned short x;
	unsigned short y;
	unsigned char defense;
	unsigned char hp;
	joystick *control;
	actions *moves;

} hero;																									
hero* hero_create(unsigned char lenght, unsigned char width, unsigned short x, unsigned short y, unsigned short max_x, unsigned short max_y);

void hero_move(hero *element, char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y);

unsigned char collision (hero *element_first, hero *element_second);

void update_position (hero *p1, hero *p2);

void update_health (hero *p1, hero *p2);

void hero_destroy(hero *element);										

void verify (bool test, const char *local);

#endif
