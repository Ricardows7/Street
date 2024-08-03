#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

#include <stdio.h>
#include <time.h>

#include "hero.h"
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

	ALLEGRO_BITMAP* bits[4];	//bitmap dos personagens
	bits[0] = al_load_bitmap ("rafaelo.png");
	bits[1] = al_load_bitmap ("donatello_2.png");
	bits[2] = al_load_bitmap ("Michelangelo.png");
	bits[3] = al_load_bitmap ("sodaleonard.png");

	for (int i = 0; i < 4; i++){
		if (!bits[i]){
			printf ("Erro no load dos herois!\n");
			return -1;
		}
	}

	ALLEGRO_BITMAP* maps = al_load_bitmap ("mapa.png");	//bitmap do mapa
	if (!maps)
		return -1;

	int dimension [4];

	ALLEGRO_BITMAP* intro = al_load_bitmap ("intro.png");
	if (!intro)
		return -1;

	al_start_timer(timer);	

	int where_to_go = 1;	//controla a tela escolhida
	bool hero_chosen = false;
	int option_chosen = 0, p1_chosen = 0, p2_chosen = 0, map_chosen = 0, paused = 0, score_1 = 0, score_2 = 0, ended = 0, bot = 0;	//variaveis para todos os lacos

	while(1){
		if (where_to_go == 1){	//Menu principal
			bot = 0;	//Aponta se vai ter bot ou nao
			option_chosen = 0;	//Opcao do menu principal
			while (1){
				al_wait_for_event (queue, &event);
				if (event.type == ALLEGRO_EVENT_TIMER){
					al_clear_to_color (al_map_rgb(0,0,0));
					menu (intro, option_chosen, X_SCREEN, Y_SCREEN);
					al_flip_display();
				}
				else if (event.type == 10){	//Controle da setinha
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
		if (where_to_go == 2){	//Selecao de personagem
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
				else if (event.type == 10){	//Controle das setinhas
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
					else if (event.keyboard.keycode == 67){	//Se ja escolheu o heroi e deu enter de novo, finaliza as escolhas e procede
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
		if (where_to_go == 3){	//Luta
			paused = 0;	//Reseta os aspectos da luta
			ended = 0;
			score_1 = 0;
			score_2 = 0;
			while(1){
				al_wait_for_event(queue, &event);	
				if (event.type == ALLEGRO_EVENT_TIMER){
					al_clear_to_color (al_map_rgb(0, 0, 0));
					al_draw_scaled_bitmap (maps, dimension[0], dimension[1], dimension[2], dimension[3], 0, 0, X_SCREEN, Y_SCREEN, 0);	//printa o mapa

					bars (disp, X_SCREEN, Y_SCREEN, score_1, score_2, player_1, player_2);	//Printa as barras de hp e stam, alem da pontuacao de rounds

					if (bot)
						robot (player_2, player_1);

					update_position (player_1, player_2, X_SCREEN, Y_SCREEN, GROUND, GRAVITY);	//Atualiza a mecanica do hero
                                	update_position (player_2, player_1, X_SCREEN, Y_SCREEN, GROUND, GRAVITY);
				
					print_hero (player_1, player_1->trajectory, GROUND);
					print_hero (player_2, player_2->trajectory, GROUND);

					if (paused){
						if (!stopped (disp, queue, event, X_SCREEN, Y_SCREEN, &paused, &where_to_go))
							break;
					}

					end (player_1, player_2, &score_1, &score_2, X_SCREEN, Y_SCREEN, GROUND, &ended);	//verifica smp se alguem venceu

					al_flip_display();
				}
				else if ((event.type == 10) || (event.type == 12)){	//Logica de armazenar o botao pressionado para os 2 personagens
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
					else if (event.type == 10 && event.keyboard.keycode == 67){	//Se apertou Enter depois que acabou, volta pro menu
                                                if (ended){
                                                        where_to_go = 1;
                                                        break;
                                                }
                                                paused = 1;
                                        }
					//PLAYER 2 DAQUI PRA BAIXO
					if (!bot){	//Player 2 so joga se nao tiver bot
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
	al_destroy_bitmap (maps);
	al_destroy_bitmap (intro);

	hero_destroy (player_1);
	hero_destroy (player_2);

	return 0;
}
