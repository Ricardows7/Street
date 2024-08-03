//Compilação: gcc AggressiveSquares.c Square.c -o AS $(pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_primitives-5 --libs --cflags) (!)

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

#include <stdio.h>
#include <time.h>

#include "begin.h"
#include "picture.h"

#define X_SCREEN 1280
#define Y_SCREEN 720

#define GRAVITY 1
#define GROUND 600

int main(){

	al_init();
	al_init_primitives_addon();
	al_install_keyboard();
	if (!al_init_font_addon()){
		printf ("ERRO NA FONTE!\n");
		return 0;
	}
	if (!al_init_ttf_addon()){
		printf ("ERRO NO TTF!\n");
		return 0;
	}
	al_init_image_addon();

	srand(time(NULL));

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
		
	ALLEGRO_EVENT event;

	ALLEGRO_BITMAP* bits[4];
	bits[0] = al_load_bitmap ("rafaelo.png");
	bits[1] = al_load_bitmap ("donatello_2.png");
	bits[2] = al_load_bitmap ("Michelangelo.png");
	bits[3] = al_load_bitmap ("sodaleonard.png");

	ALLEGRO_BITMAP* maps = al_load_bitmap ("mapa.png");
	if (!maps)
		return -1;

	int dimension [4];

	ALLEGRO_BITMAP* intro = al_load_bitmap ("intro.png");
	if (!intro)
		return -1;

	al_start_timer(timer);	

	int where_to_go = 1;
	bool hero_chosen = false;
	int option_chosen = 0, p1_chosen = 0, p2_chosen = 0, map_chosen = 0, paused = 0, score_1 = 0, score_2 = 0, ended = 0, bot = 0;

	while(1){
		if (where_to_go == 1){
			bot = 0;
			option_chosen = 0;
			while (1){
				al_wait_for_event (queue, &event);
				if (event.type == ALLEGRO_EVENT_TIMER){
					al_clear_to_color (al_map_rgb(0,0,0));
					menu (intro, option_chosen, X_SCREEN, Y_SCREEN);
					al_flip_display();
				}
				else if (event.type == 10){
					if (event.keyboard.keycode == 84)
						option_chosen = (2 + option_chosen) % 3;
					else if (event.keyboard.keycode == 85)
						option_chosen = (1 + option_chosen) % 3;
					else if (event.keyboard.keycode == 67){
						if (option_chosen == 2){
							where_to_go = 4;
							break;
						}
						if (!option_chosen)
							bot = 1;
						where_to_go = 2;
						break;
					}
				}
				else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                                        where_to_go = 4;
                                        break;
				}
			}
		}
		if (where_to_go == 2){
			hero_chosen = false;
			choose_hero (player_1, p1_chosen, X_SCREEN/3, X_SCREEN, Y_SCREEN, GROUND);
                  	choose_hero (player_2, p2_chosen, X_SCREEN/3, X_SCREEN, Y_SCREEN, GROUND);
			while (1){
				al_wait_for_event(queue, &event);
				if (event.type == ALLEGRO_EVENT_TIMER){
					al_clear_to_color (al_map_rgb (0,0,0));

					character_menu (disp, maps, bits, p1_chosen, p2_chosen, map_chosen, hero_chosen, X_SCREEN, Y_SCREEN);

					al_flip_display();
				}
				else if (event.type == 10){
					if (event.keyboard.keycode == 83 && !hero_chosen)
						p2_chosen = (p2_chosen + 1) % 4;
					else if (event.keyboard.keycode == 82 && !hero_chosen)
						p2_chosen = (3 + p2_chosen) % 4;
					else if (event.keyboard.keycode == 4){
						if (!hero_chosen)
							p1_chosen = (p1_chosen + 1) % 4;
						else
							map_chosen = (map_chosen + 1) % 2;
					}
					else if (event.keyboard.keycode == 1){
						if (!hero_chosen)
							p1_chosen = (3 + p1_chosen) % 4;
						else
							map_chosen = (1 + map_chosen) % 2;
					}
					else if (event.keyboard.keycode == 67){
						if (!hero_chosen)
							hero_chosen = true;
						else{
							where_to_go = 3;
							choose_hero (player_1, p1_chosen, X_SCREEN/3, X_SCREEN, Y_SCREEN, GROUND);
                				        choose_hero (player_2, p2_chosen, X_SCREEN * 2/3, X_SCREEN, Y_SCREEN, GROUND);
							if (map_chosen == 0){
								dimension[0] = 745;
								dimension[1] = 295;
								dimension[2] = 714;
								dimension[3] = 170;
							}
							else{
								dimension[0] = 338;
                                                                dimension[1] = 55;
                                                                dimension[2] = 714;
                                                                dimension[3] = 155;
							}
							break;
						}
					}	
				}
				else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
					where_to_go = 4;
					break;
				}
			}	
		}
		if (where_to_go == 3){
			paused = 0;
			ended = 0;
			score_1 = 0;
			score_2 = 0;
			while(1){
				al_wait_for_event(queue, &event);	
				if (event.type == ALLEGRO_EVENT_TIMER){
					al_clear_to_color (al_map_rgb(0, 0, 0));
					al_draw_scaled_bitmap (maps, dimension[0], dimension[1], dimension[2], dimension[3], 0, 0, X_SCREEN, Y_SCREEN, 0);

					bars (disp, X_SCREEN, Y_SCREEN, score_1, score_2, player_1, player_2);

					if (bot)
						robot (player_2, player_1);

					al_draw_filled_rectangle (player_1->x-player_1->width/2, player_1->y-player_1->length/2, player_1->x+player_1->width/2,player_1->y+player_1->length/2, al_map_rgb(255,0,0));
					al_draw_filled_rectangle (player_2->x-player_2->width/2, player_2->y-player_2->length/2, player_2->x+player_2->width/2,player_2->y+player_2->length/2, al_map_rgb(0,0,255));

					update_position (player_1, player_2, X_SCREEN, Y_SCREEN, GROUND, GRAVITY);
                                	update_position (player_2, player_1, X_SCREEN, Y_SCREEN, GROUND, GRAVITY);
				
					print_hero (player_1, player_1->trajectory, GROUND);
					print_hero (player_2, player_2->trajectory, GROUND);

					if (paused){
						if (!stopped (disp, queue, event, X_SCREEN, Y_SCREEN, &paused, &where_to_go))
							break;
					}

					end (player_1, player_2, &score_1, &score_2, X_SCREEN, Y_SCREEN, GROUND, &ended);

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
					else if (event.keyboard.keycode == 3){
						joystick_activate (player_1->control_x, event.type, SPECIAL);
						joystick_deactivate (player_1->control_x, event.type, SPECIAL);
					}
					else if (event.type == 10 && event.keyboard.keycode == 67){
                                                if (ended){
                                                        where_to_go = 1;
                                                        break;
                                                }
                                                paused = 1;
                                        }
					//PLAYER 2 DAQUI PRA BAIXO
					if (!bot){
						if (event.keyboard.keycode == 82){
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
                                        		joystick_activate (player_2->control_x, event.type, DEFENSE_DOWN);
                                        		joystick_deactivate (player_2->control_x, event.type, DEFENSE_DOWN);
                                		}
						else if (event.keyboard.keycode == 74){
                                        		joystick_activate (player_2->control_x, event.type, SPECIAL);
                                        		joystick_deactivate (player_2->control_x, event.type, SPECIAL);
                                		}
					}
					printf ("%d\n", event.keyboard.keycode);

				}
				else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
					where_to_go = 4;
					break;
				}
			}
		}
		else
			break;
	}

	al_destroy_font(font);
	al_destroy_display(disp);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
	for (int i = 0; i < 4; i++)
		al_destroy_bitmap (bits[i]);
	printf ("Ta dando free!\n"); 
  
	hero_destroy (player_1);
	hero_destroy (player_2);

	return 0;
}
