#ifndef __BEGIN__ 												
#define __BEGIN__																									
#include <stdbool.h>
#include <stdio.h>

#include "joystick.h"
#include "damage.h"

#define STREET_STEP 20
#define JUMP_VEL 50

typedef struct {
	unsigned short id;
	unsigned char lenght;
	unsigned char width;
	unsigned short x;
	unsigned short y;
	unsigned short stun;
	unsigned short hp;
	unsigned short stamina;
	joystick *control;
} hero;																									
hero* hero_create();

void hero_move(hero *element, char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y, unsigned short ground);

hero *choose_hero (hero *element, int type, unsigned short x, unsigned short y, unsigned short max_x, unsigned short max_y, unsigned short ground);

unsigned char collision (hero *element_first, hero *element_second);

void update_position (hero *p1, hero *p2, int max_x, int max_y, int ground, int gravity);

void update_health (hero *p1, hero *p2);

void hero_destroy(hero *element);										

void hero_jump (hero *element, hero *aux, int max_x, int max_y, int ground);

void verify (bool test, const char *local);

#endif
