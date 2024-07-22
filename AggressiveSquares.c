//Compilação: gcc AggressiveSquares.c Square.c -o AS $(pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_primitives-5 --libs --cflags) (!)

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

#include <stdio.h>

#include "begin.h"

#define X_SCREEN 1080
#define Y_SCREEN 1080

#define GRAVITY 1
#define GROUND 500

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

	int where_to_go = 2;

	choose_hero (player_1, 49, X_SCREEN/3, X_SCREEN, Y_SCREEN, GROUND);		//RETIRAR O INICIO EM Y, DEPENDE DA ALTURA DO HEROI!!!!!!!!!!	
	choose_hero (player_2, 49, X_SCREEN * 2/3, X_SCREEN, Y_SCREEN, GROUND);

	while(1){
	/*	AQUI SERÁ O MENU DE ESCOLHA!
		if (where_to_go == 1){
			while (1){
				al_wait_for_event(queue, &event);
				printf ("Selecione o Player 1!\n");
				if (49 <= event.keyboard.keycode && event.keyboard.keycode <= 52)
					player1 = choose_hero (player1, event.keyboard.keycode, 
			}	
		}
	*/
		if (where_to_go == 2){
			al_wait_for_event(queue, &event);
			//printf ("vai entrar no update!\n");	
			update_position (player_1, player_2, X_SCREEN, Y_SCREEN, GROUND, GRAVITY);
			update_position (player_2, player_1, X_SCREEN, Y_SCREEN, GROUND, GRAVITY);

			if (event.type == 30){
				al_clear_to_color (al_map_rgb(0, 0, 0));
				//al_draw_bitmap (mysha, 50, 100, 100;
				al_draw_filled_rectangle (0, Y_SCREEN/50, 300 * (player_1->hp/100), 0, al_map_rgba_f (0.5,0,0,0.5));
				al_draw_filled_rectangle (0, (Y_SCREEN/25) + 10, 300 * (player_1->stamina/100), (Y_SCREEN/50) + 10, al_map_rgba_f (0,0,0.5,0.5));

				al_draw_filled_rectangle (X_SCREEN - (300 * (player_2->hp/100)), Y_SCREEN/50, X_SCREEN, 0, al_map_rgba_f (0.5,0,0,0.5));
				al_draw_filled_rectangle (X_SCREEN - (300 * (player_2->stamina/100)), (Y_SCREEN/25) + 10, X_SCREEN, (Y_SCREEN/50) + 10, al_map_rgba_f (0,0,0.5,0.5));
				al_draw_filled_rectangle(0, Y_SCREEN, X_SCREEN, GROUND, al_map_rgb(0, 255, 0));
      				al_draw_filled_rectangle (player_1->x-player_1->width/2, player_1->y-player_1->length/2, player_1->x+player_1->width/2, player_1->y+player_1->length/2, al_map_rgb(255, 0, 0));
				al_draw_filled_rectangle (player_2->x-player_2->width/2, player_2->y-player_2->length/2, player_2->x+player_2->width/2, player_2->y+player_2->length/2, al_map_rgb (0, 0, 255));

				al_flip_display();
			}

			else if ((event.type == 10) || (event.type == 12)){ 
				if (event.keyboard.keycode == 1){
					joystick_activate (player_1->control_x, event.type, WALK_LEFT);
					joystick_deactivate (player_1->control_x, event.type, WALK_LEFT);
				}
				else if (event.keyboard.keycode == 4){
					joystick_activate (player_1->control_x, event.type, WALK_RIGHT);
					joystick_deactivate (player_1->control_x, event.type, WALK_RIGHT);
				}
				else if (event.keyboard.keycode == 23){
					joystick_activate (player_1->control_y, event.type, JUMP);
					joystick_deactivate (player_1->control_y, event.type, JUMP);
				}
				else if (event.keyboard.keycode == 19){		//COLOCAR AQUI COM BASE NA VERIFICACAO DE EVENT.TYPE O REDIMENSIONAMENTO
					joystick_activate (player_1->control_y, event.type, GET_DOWN);
					joystick_deactivate (player_1->control_y, event.type, GET_DOWN);
				}	
				else if (event.keyboard.keycode == 6){	//ARRUMAR AQUI!
					joystick_activate (player_1->control_x, event.type, PUNCH);
					joystick_deactivate (player_1->control_x, event.type, PUNCH);
				}
				else if (event.keyboard.keycode == 7){
                                        joystick_activate (player_1->control_x, event.type, KICK);
                                        joystick_deactivate (player_1->control_x, event.type, KICK);
                                }
				else if (event.keyboard.keycode == 8){
                                        joystick_activate (player_1->control_x, event.type, DEFENSE_UP);
                                        joystick_deactivate (player_1->control_x, event.type, DEFENSE_UP);
                                }
				else if (event.keyboard.keycode == 10){
                                        joystick_activate (player_1->control_x, event.type, DEFENSE_DOWN);
                                        joystick_deactivate (player_1->control_x, event.type, DEFENSE_DOWN);
                                }
				//PLAYER 2 DAQUI PRA BAIXO
				else if (event.keyboard.keycode == 82){
                                        joystick_activate (player_2->control_x, event.type, WALK_LEFT);
                                        joystick_deactivate (player_2->control_x, event.type, WALK_LEFT);
                                }
                                else if (event.keyboard.keycode == 83){
                                        joystick_activate (player_2->control_x, event.type, WALK_RIGHT);
                                        joystick_deactivate (player_2->control_x, event.type, WALK_RIGHT);
                                }
                                else if (event.keyboard.keycode == 84){
                                        joystick_activate (player_2->control_y, event.type, JUMP);
                                        joystick_deactivate (player_2->control_y, event.type, JUMP);
                                }
                                else if (event.keyboard.keycode == 85){         //COLOCAR AQUI COM BASE NA VERIFICACAO DE EVENT.TYPE O REDIMENSIONAMENTO
                                        joystick_activate (player_2->control_y, event.type, GET_DOWN);
                                        joystick_deactivate (player_2->control_y, event.type, GET_DOWN);
                                }
                                else if (event.keyboard.keycode == 73){  //ARRUMAR AQUI!
                                        joystick_activate (player_2->control_x, event.type, PUNCH);
                                        joystick_deactivate (player_2->control_x, event.type, PUNCH);
                                }
                                else if (event.keyboard.keycode == 68){
                                        joystick_activate (player_2->control_x, event.type, KICK);
                                        joystick_deactivate (player_2->control_x, event.type, KICK);
                                }
                                else if (event.keyboard.keycode == 72){
                                        joystick_activate (player_2->control_x, event.type, DEFENSE_UP);
                                        joystick_deactivate (player_2->control_x, event.type, DEFENSE_UP);
                                }
                                else if (event.keyboard.keycode == 13){
                                        joystick_activate (player_1->control_x, event.type, DEFENSE_DOWN);
                                        joystick_deactivate (player_1->control_x, event.type, DEFENSE_DOWN);
                                }
				printf ("%d\n", event.keyboard.keycode);

			}
			else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
				where_to_go = 3;
				break;
			}
		}
		else
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
