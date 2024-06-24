//Compilação: gcc AggressiveSquares.c Square.c -o AS $(pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_primitives-5 --libs --cflags) (!)

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>	
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

#include "begin.h"

#define X_SCREEN 320
#define Y_SCREEN 320

#define KEY_SEEN 1
#define KEY_RELEASED  2

int main(){

	al_init();
	al_init_primitives_addon();
	al_install_keyboard();
	
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	ALLEGRO_FONT* font = al_create_builtin_font();
	ALLEGRO_DISPLAY* disp = al_create_display(X_SCREEN, Y_SCREEN);

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(disp));
	al_register_event_source(queue, al_get_timer_event_source(timer));

	hero* player_1 = hero_create(20, 20, X_SCREEN/3, Y_SCREEN/2, X_SCREEN, Y_SCREEN);
	if (!player_1) return 1;
	
	hero* player_2 = hero_create(20, 20, X_SCREEN * 2/3, Y_SCREEN/2, X_SCREEN, Y_SCREEN);
	if (!player_2) return 2;
	
	al_init_image_addon();
	
	ALLEGRO_BITMAP* mysha = al_load_bitmap ("mysha.png");

	ALLEGRO_EVENT event;
	
	al_start_timer(timer);	
	
	while(1){
		al_wait_for_event(queue, &event);	

		if (event.type == 30){
			al_clear_to_color (al_map_rgb(0, 0, 0));
			al_draw_bitmap (mysha, 50, 100, 100);
			al_draw_filled_rectangle (100, 100, 340, 340, al_map_rgba_f (0,0,0.5,0.5));
      			al_draw_filled_rectangle (player_1->x-player_1->width/2, player_1->y-player_1->lenght/2, player_1->x+player_1->width/2, player_1->y+player_1->lenght/2, al_map_rgb(255, 0, 0));
			al_draw_filled_rectangle (player_2->x-player_2->width/2, player_2->y-player_2->lenght/2, player_2->x+player_2->width/2, player_2->y+player_2->lenght/2, al_map_rgb (255, 0, 0));

			al_flip_display();
		}
		else if ((event.type == 10) || (event.type == 12)){
			if (event.keyboard.keycode == 1)
				joystick_left (player_1->control);
			else if (event.keyboard.keycode == 4)
				joystick_right (player_1->control);
			else if (event.keyboard.keycode == 23)
				joystick_up (player_1->control);
			else if (event.keyboard.keycode == 19)
				joystick_down (player_1->control);
			else if (event.keyboard.keycode == 82)
				joystick_left (player_2->control);
			else if (event.keyboard.keycode == 83)
				joystick_right (player_2->control);
			else if (event.keyboard.keycode == 84)
				joystick_up (player_2->control);
			else if (event.keyboard.keycode == 85)
				joystick_down (player_2->control);
		}
		else if (event.type == 42)
			break;
	}

	al_destroy_font(font);
	al_destroy_display(disp);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
	al_destroy_bitmap (mysha);

	printf ("Ta dando free!\n"); 
  
	hero_destroy (player_1);
	hero_destroy (player_2);

	return 0;
}
