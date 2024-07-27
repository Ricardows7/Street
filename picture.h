#ifndef __IMAGE__
#define __IMAGE__

#include "begin.h"

void printa_stand (hero *p, ALLEGRO_BITMAP* image, bool rev);

void printa_down (hero *p, ALLEGRO_BITMAP *image, bool rev);

void printa_jump (hero *p, ALLEGRO_BITMAP *image, bool rev, int ground);

void printa_up_defense (hero *p, ALLEGRO_BITMAP *image, bool rev);

void printa_down_defense (hero *p, ALLEGRO_BITMAP *image, bool rev);

void draw_air_punch();

void draw_air_kick();

void draw_air();

void draw_down();

void draw_down_punch();

void draw_down_kick();

#endif
