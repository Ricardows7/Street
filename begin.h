#ifndef __BEGIN__ 												
#define __BEGIN__																									
#include <stdbool.h>
#include <stdio.h>


#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

#include "joystick.h"

#define STREET_STEP 10
#define JUMP_VEL 25

typedef struct {
	int id;
	int length;
	int width;
	int x;
	int y;
	int stun;
	float hp;
	float stamina;
	bool air;
	int jump;
	bool trajectory;
	bool hitted;
	joystick *control_x;
	joystick *control_y;
	ALLEGRO_BITMAP *image;
} hero;																									
hero* hero_create();

void hero_move(hero *element, char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y, unsigned short ground);

hero *choose_hero (hero *element, int type, int x, int max_x, int max_y, int ground);

unsigned char collision (hero *element_first, hero *element_second);

void hero_movement (hero *p1, hero *p2, char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y, unsigned short ground);

void update_position (hero *p1, hero *p2, int max_x, int max_y, int ground, int gravity);

void position_x (hero *p1, hero *p2, int max_x, int max_y, int ground, int gravity);

void position_y (hero *p1, hero *p2, int max_x, int max_y, int ground, int gravity);

void hero_destroy(hero *element);										

void hero_jump (hero *element, hero *aux, int max_x, int max_y, int ground);

//void verify (bool test, const char *local);

#endif
