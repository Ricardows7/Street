#ifndef __IMAGE__
#define __IMAGE__

#include "begin.h"

void printa_walk_right (hero *p, ALLEGRO_BITMAP* image, bool rev);

void printa_walk_left (hero *p, ALLEGRO_BITMAP* image, bool rev);

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

void printa_special (hero *p, ALLEGRO_BITMAP *image, bool rev);

void print_hero (hero *p, bool rev, int ground);

void character_menu (ALLEGRO_DISPLAY* display, ALLEGRO_BITMAP* maps, ALLEGRO_BITMAP* bits[] ,int selected_character1, int selected_character2, int selected_map, bool character_chosen, int max_x, int max_y);

void bars (ALLEGRO_DISPLAY *display, int max_x, int max_y, hero *p1, hero *p2);

#endif
