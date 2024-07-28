#ifndef __IMAGE__
#define __IMAGE__

#include "begin.h"

void printa_stand (hero *p, ALLEGRO_BITMAP* image, bool rev);

void printa_down (hero *p, ALLEGRO_BITMAP *image, bool rev);

void printa_jump (hero *p, ALLEGRO_BITMAP *image, bool rev, int ground);

void printa_up_defense (hero *p, ALLEGRO_BITMAP *image, bool rev);

void printa_down_defense (hero *p, ALLEGRO_BITMAP *image, bool rev);

void printa_stand_punch (hero *p, ALLEGRO_BITMAP *image, bool rev);

void printa_down_punch (hero *p, ALLEGRO_BITMAP *image, bool rev);

void printa_up_punch (hero *p, ALLEGRO_BITMAP *image, bool rev);

void printa_stand_kick (hero *p, ALLEGRO_BITMAP *image, bool rev);

void printa_down_kick (hero *p, ALLEGRO_BITMAP *image, bool rev);

void printa_up_kick (hero *p, ALLEGRO_BITMAP *image, bool rev);

#endif
