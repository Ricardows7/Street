#include <stdlib.h>
#include "begin.h"

hero* hero_create(){
	hero *new_hero = (hero*) malloc (sizeof(hero));		
	if (!new_hero){
		printf ("Erro durante a alocação de um novo herói!\n");
		return NULL;
	}
	
	new_hero->id = 0;
	new_hero->length = 0;
	new_hero->width = 0;
	new_hero->x = 0;
	new_hero->y = 0;
	new_hero->stun = 0;
	new_hero->hp = 100;
	new_hero->stamina = 100;
	new_hero->air = false;
	new_hero->jump = 0;

	new_hero->control_x = joystick_create();
	new_hero->control_y = joystick_create();

	return new_hero;
}

hero* choose_hero (hero* element, int type, int x, int max_x, int max_y, int ground){

	element->x = x;

	if (type == 49){	//type se refere ao codigo do teclado
		element->id = 1;
	        element->length = 20;
        	element->width = 20;
	}
	else if (type == 50){
		element->id = 2;
                element->length = 20;
                element->width = 20;
	}
	else if (type == 51){
		element->id = 3;
                element->length = 20;
                element->width = 20;
	}
	else{
		element->id = 4;
                element->length = 20;
                element->width = 20;
	}

	element->y = ground - element->length/2;	//como y spawna acima do chao, nunca passara pra baixo da tela!

	if ((x - element->width/2 < 0) || (x + element->width/2 > max_x) || (element->y - element->length/2 < 0)){
	       	free (element);
		printf ("Erro na posição inicial dos jogadores!\n");
		return NULL;
	}

	return element;
}

void hero_move(hero *element, char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y, unsigned short ground){							//Implementação da função "square_move" (-1)

	if (!trajectory){ if ((element->x - steps*STREET_STEP) - element->width/2 >= 0) element->x = element->x - steps*STREET_STEP;} 				//Verifica se a movimentação para a esquerda é desejada e possível; se sim, efetiva a mesma
	else if (trajectory == 1){ if ((element->x + steps*STREET_STEP) + element->width/2 <= max_x) element->x = element->x + steps*STREET_STEP;}	//Verifica se a movimentação para a direita é desejada e possível; se sim, efetiva a mesma
	else if (trajectory == 2){	//Lógica do personagem no ar. Steps positivo = subindo, negativo = descendo
		if (steps < 0){
	       		if ((element->y - steps) + element->length/2 >= ground)		//Se descer pra baixo do chao, spawna no chao. Se nao, so desce normal		
				element->y = ground - element->length/2;
			else
				element->y = element->y - steps;
		}
		else{
			if ((element->y - steps) - element->length/2 >= 0)		//So sobe se couber na tela
				element->y = element->y - steps;
			else
				element->y = element->length/2;
		}
	
	}

}

unsigned char collision (hero *element_first, hero *element_second){
	int a, b, c, d;

	if ((element_first->y+element_first->length/2 >= element_second->y-element_second->length/2) && (element_second->y-element_second->length/2 >= element_first->y-element_first->length/2))
		a = 1;
	else
		a = 0;

	if ((element_second->y+element_second->length/2 >= element_first->y-element_first->length/2) && (element_first->y-element_first->length/2 >= element_second->y-element_second->length/2))
		b = 1;
	else
		b = 0;

	if ((element_first->x+element_first->width/2 >= element_second->x-element_second->width/2) && (element_second->x-element_second->width/2 >= element_first->x-element_first->width/2))
		c = 1;
	else
		c = 0;

	if ((element_second->x+element_second->width/2 >= element_first->x-element_first->width/2) && (element_first->x-element_first->width/2 >= element_second->x-element_second->width/2))
		d = 1;
	else
		d = 0;

	if ((a || b) && (c || d))
		return 1;
	else
		return 0;
}

void update_position (hero *p1, hero *p2, int max_x, int max_y, int ground, int gravity){
	if (!p1->control_y->state && p1->control_y->change)	//NA FUNCAO JUMP, SE O CLOCK FOR 0 CHAMAR HERO_JUMP!!!!!!!!!!
		choose_move_y (p1->control_y, p1->control_x, p1->stun);	//NOS ESTADOS Y, SE ESTIVER GOLPEANDO, NAO TERMINAR A FUNCAO ENQUANTO (PELO MENOS) O GOLPE NAO FOR CONCLUIDO!!!!
					//PENSAR NO QUE FAZER QUANDO ESTIVER GOLPEANDO E CAIR NO CHAO!!!(TESTAR SE CHEGAR NO CHAO EM Y) E ESTIVER GOLPEANDO CANCELA????
	if (verify_action (p1->control_x->state) && p1->control_x->change)	//coloco pra chamar caso so esteja andando?
		choose_move_x (p1->control_x, p1->control_y, p1->stamina, p1->stun);

	position_x (p1, p2, max_x, max_y, ground, gravity);
	position_y (p1, p2, max_x, max_y, ground, gravity);

	stamina_update (p1->control_x->state, false, &p1->stamina);     //VER A LOGICA DISSO DEPOIS!

        if (p1->stun > 0)
                p1->stun--;
	else if (p1->stun < 0)
		p1->stun = 0;

        return;
}

void position_x (hero *p1, hero *p2, int max_x, int max_y, int ground, int gravity){
			printf ("ANTES DO LACO %d\n", p1->control_x->state);
	switch (p1->control_x->state){
		case SPECIAL:
			p1->control_x->timer++;
			//CHAMAR FUNCAO SPECIAL
			//ADICIONAR NO CLOCK
			//AO FINAL, TIRAR ESSE STATE E RESETAR O CLOCK!!!!!!!!!!
			break;
		case KICK:		//NAO MUDO O ESTADO DO Y??????????
			p1->control_y->change = false;
                        p1->control_x->timer++;
                        if (p1->control_x->timer == 30 || p1->control_y->state == JUMP){
                                int minimo_x, maximo_x;
                                if (p1->x < p2->x){
                                        minimo_x = p1->x + p1->width/2 + 10;	//MUDAR OS VALORES AQUI!!!
                                        maximo_x = p1->x + p1->width/2 + 20;
                                }
                                else{
                                        minimo_x = p1->x - p1->width/2 - 20;
                                        maximo_x = p1->x - p1->width/2 - 10;
                                }
                                update_damage (KICK_DAMAGE, &p2->hp, &p2->stun, !(p2->control_x->state - DEFENSE_UP), !(p2->control_x->state - DEFENSE_DOWN), minimo_x, maximo_x, p1->y * (3/5), p1->y * (4/5), p2->x, p2->y, p2->length, p2->width);	//ATUALIZAR AS HITBOXES AQUI TAMBEM!!!
                                if (!(p1->control_y->state == JUMP))      //ATUALIZAR NO JUMP A STAMINA! COMO EU FACO ISSO???
                                        stamina_update (p1->control_x->state, true, &p1->stamina);
                        }
			else if (p1->control_x->timer > 60){
				p1->control_x->state = 0;
                                p1->control_x->timer = 0;
				p1->control_y->change = true;
                        }

			break;
		case PUNCH:	//SE ESTIVER NO CHAO MAS JUMP ESTIVER ATIVO, NAO FAZ NADA! NO FIM DA FUNCAO EM Y DESATIVA O GOLPE!!!
			p1->control_y->change = false;
			p1->control_x->timer++;
			if (p1->control_x->timer == 15 || p1->control_y->state == JUMP){
				int minimo_x, maximo_x;
				if (p1->x < p2->x){
					minimo_x = p1->x + p1->width/2 + 10;
					maximo_x = p1->x + p1->width/2 + 20;
				}
				else{
					minimo_x = p1->x - p1->width/2 - 20;
					maximo_x = p1->x - p1->width/2 - 10;
				}
				update_damage (PUNCH_DAMAGE, &p2->hp, &p2->stun, !(p2->control_x->state - DEFENSE_UP), !(p2->control_x->state - DEFENSE_DOWN), minimo_x, maximo_x, p1->y - (p1->length/4), p1->y, p2->x, p2->y, p2->length, p2->width);
				al_draw_filled_rectangle (minimo_x, p1->y - (p1->length/4), maximo_x, p1->y, al_map_rgba_f(0.5, 0.3, 0.0, 0.5)); //PRECISO FAZER ISSO FUNCIONAR!!!

				printf ("Desenhou o retangulo!\n");

				if (!(p1->control_y->state == JUMP))	//ATUALIZAR NO JUMP A STAMINA! COMO EU FACO ISSO???
					stamina_update (p1->control_x->state, true, &p1->stamina);
			}
			else if (p1->control_x->timer > 30){
				p1->control_x->state = 0;
				p1->control_x->timer = 0;
				p1->control_y->change = true;
			}
			break;
		case DEFENSE_UP:	//NAO DA PRA COMBINAR OS DOIS DEFENSES JUNTOS AQUI???
			p1->control_y->change = false;
			p1->control_x->timer++;
			if (p1->control_x->timer > 30)
				p1->control_x->timer = 0;
			stamina_update (p1->control_x->state, true, &p1->stamina);
			if ((p1->control_x->acumulation % DEFENSE_UP != 0) || (p1->stamina < DEFENSE_STAMINA)){
				p1->control_x->state = 0;
				p1->control_x->timer = 0;
				p1->control_y->change = true;
			}
			break;
		case DEFENSE_DOWN:
			printf ("VALORES SAO %ld ac %d st\n", p1->control_x->acumulation, p1->control_x->state);
			p1->control_y->change = false;	//Trava o eixo y enquanto esta defendendo
			p1->control_x->timer++;
			if (p1->control_x->timer > 30)
				p1->control_x->timer = 0;
			stamina_update (p1->control_x->state, true, &p1->stamina);
			if ((p1->control_x->acumulation % DEFENSE_DOWN != 0) || (p1->stamina < DEFENSE_STAMINA)){	//encerra o estado se soltar o botao ou acabar a stamina
				p1->control_x->state = 0;
				p1->control_x->timer = 0;
				p1->control_y->change = true;
			}		
			break;
		case WALK_LEFT:
			if (p1->control_y->state != GET_DOWN){
				hero_move(p1, 1, 0, max_x, max_y, ground);
				p1->control_x->timer++;
			}
			if (p1->control_x->timer > 30)
				p1->control_x->timer = 0;
			if (p1->control_x->acumulation % WALK_LEFT == 0){ 	//SE LARGAR O BOTAO DE EVENTO CONTINUO, CORRIGI AQUI O STATE
				p1->control_x->state = 0;
				p1->control_x->timer = 0;
			}
			break;
		case WALK_RIGHT:	//LEMBRAR DE MUDAR MOVIMENTO PRA INCLUIR COLISAO!!!
			if (p1->control_y->state != GET_DOWN){		//Se nao estiver agachado, move pra direita e acrescenta no timer
				hero_move(p1, 1, 1, max_x, max_y, ground);
				p1->control_x->timer++;
			}
			if (p1->control_x->timer > 30)		//se o timer estourou do limite de sprints, reseta
				p1->control_x->timer = 0;
			if (p1->control_x->acumulation % WALK_RIGHT != 0){	//Se largou o botão, nao anda mais
				p1->control_x->state = 0;
				p1->control_x->timer = 0;
			}
			printf ("TO NO WALK RIGHT!!!, %d state %ld acumulation %d value\n", p1->control_x->state, p1->control_x->acumulation, WALK_RIGHT);
			break;
		default:
			p1->control_x->timer++;
			if (p1->control_x->timer > 30)
				p1->control_x->timer = 0;
			break;
	}
}

void position_y (hero *p1, hero *p2, int max_x, int max_y, int ground, int gravity){
	switch (p1->control_y->state){
		case GET_DOWN:
			if (p1->control_y->timer == 0){	//Quando ativar, reduz a altura pela metade
				p1->y += p1->length/4;
				p1->length /= 2;
			}		
			if (p1->control_y->timer < 30)		//atualiza o clock pra frente
				p1->control_y->timer++;
			if (p1->control_y->acumulation % GET_DOWN != 0 && verify_action (p1->control_x->state)){	//condicao pra sair do estado agachado
				p1->control_y->timer++;		//FACO UM ESTADO PRA NAO APERTAR ENQUANTO LEVANTANDO???
				p1->control_x->change = false;	
				if (p1->control_y->timer >= 60){
					p1->control_y->timer = 0;
					p1->control_y->state = 0;
					p1->control_x->change = true;
					p1->length *= 2;
					p1->y -= p1->length/4;
				}
		       	}		
			break;
		case JUMP:
			if (p1->air){
				if (p1->y+p1->length/2 >= ground){	//LEMBRAR DE SETAR HERO_MOVE PRA SEMPRE ACABAR EXATAMENTE NO CHAO!!!
					p1->control_x->state = 0;
					p1->control_x->change = false;
					p1->control_y->timer++;
					if (p1->control_y->timer > 60){
						p1->air = false;
						p1->control_y->state = 0;
						p1->control_y->change = true;
						p1->control_y->timer = 0;
						p1->control_x->change = true;
						p1->control_x->timer = 0;
					}
					return;
				}
				if (!(p1->control_x->acumulation % WALK_RIGHT) && (p1->control_x->state != WALK_RIGHT))
					hero_move (p1, 1, 1, max_x, max_y, ground);
                                else if (!(p1->control_x->acumulation % WALK_LEFT) && (p1->control_x->state != WALK_LEFT))
                                        hero_move (p1, 1, 0, max_x, max_y, ground);
				
				p1->jump -= gravity;
				hero_move (p1, p1->jump, 2, max_x, max_y, ground);	//LOGICA DE GRAVIDADE
				printf ("MTA PAZ!\n");
			}
			else{
				p1->control_x->change = false;
				p1->control_x->state = 0;
				p1->control_y->timer++;	//ZERO O EIXO X DURANTE O PULO????
				if (p1->control_y->timer > 30){		//So taca o personagem no ar depois da animacao de pulo
					hero_jump (p1, p2, max_x, max_y, ground);
					p1->control_x->change = true;
					p1->control_x->timer = 0;
				}
			}
			break;
		default:
			p1->control_y->timer++;
			if (p1->control_y->timer > 30)
				p1->control_y->timer = 0;
			break;
	}
	return;
}

void hero_jump (hero *element, hero *aux, int max_x, int max_y, int ground){    //ARRUMAR URGENTE!
        if (!element)
                return;

        if (element->y + element->length/2 != ground)   //Se o heroi nao esta no chao, nao pula
                return;

        element->jump = JUMP_VEL;
        element->air = true;
        hero_move (element, element->jump, 2, max_x, max_y, ground);
        if (collision (element, aux)){
                element->jump = -element->jump;
                hero_move (element, element->jump, 2, max_x, max_y, ground);
        }
        return;
}

void hero_destroy(hero *element){
        joystick_destroy (element->control_x);
	joystick_destroy (element->control_y);

        free (element);
	element = NULL;

        return;
}

/*
	if (p1->control->left){
		hero_move (p1, 1, 0, max_x, max_y, ground);
		if (collision (p1, p2))
			hero_move (p1, -1, 0, max_x, max_y, ground);
	}
	if (p1->control->right){
		printf ("direitinha!\n");
		hero_move (p1, 1, 1, max_x, max_y, ground);
		if (collision (p1, p2))
			hero_move (p1, -1, 1, max_x, max_y, ground);
	}
	if (p1->control->air){	//PULAR!!!!!!!!!!!
		p1->jump -= gravity;
		hero_move (p1, p1->jump, 2, max_x, max_y, ground);
		if (collision (p1, p2)){
			p1->jump = -p1->jump;
			hero_move (p1, p1->jump, 2, max_x, max_y, ground);
		}
		if (p1->y - p1->lenght/2 <= ground){
			p1->jump = 0;
			p1->control->air = 0;
		}
	}

	return;
}
*/
/*
void punch (hero *player, hero *target){
	SE ESTIVER NA TERRA, ZERA todos os campos DO PLAYER->CONTROL

	if (player->moves->timer[0] < 0){
		player->moves->timer[0] = PUNCH_COOLDOWN;
		player->state[1].status = false;	???
		return;
	}
	if (player->state[1].status == 0)	??? ISSO VAI NO INICIO! SE NAO TIVER SETADO PRA SOCO, OU TIVER SETADO PRA OUTRO GOLPE
		return;

	player->moves->timer[0] -= 1;
	if (player->moves->timer[0] >= PUNCH_COOLDOWN * 4/5 || player->moves->timer[0] <= PUNCH_COOLDOWN / 5)
		printar sprite normal;
	else if (player->moves->timer[0] >= PUNCH_COOLDOWN * 3/5)
		ajusta a sprite a ser printada;
	else if (player->moves->timer[0] >= PUNCH_COOLDOWN * 2/5){
		ajusta a sprite a ser printada;
		clean_hit ();
	}
	else
		ajusta a sprite a ser printada;
	
	return;

}

void clean_hit (int x_origin, y_origin, x_ext, y_ext, hero *source, hero *target){ //funcao que verifica se a hitbox e alvo se interceptam

}

void printa_hero (hero *player, hero *aux){
	SE ESTIVER BATENDO DE ALGUM JEITO, RETORNA!!!!!!
	if (player->control->air){
		printa a sprite em relacao a aux (COM BASE NA ID DO HERO!)
	}
	if (estiver batendo)
		return;
	
	if (player->control->left)
		printa indo pra esquerda com base nas posicoes;
	else if (player->control->right)
		
*/
/*
void update_damage (hero *p1, hero *p2, int type){
	int a, b, c, d, e;

	if (type == 3){
		return;
	}

	if (type == 1)
		e = 0;
	else
		e = 1;

	a = p1->x + p1->moves->range[e];
	b = p2->x - p2->width/2;
	c = p2->x + p2->width/2;
	d = p1->x - p1->moves->range[e];

	if (((p1->x <= p2->x) && (a >= b)) || ((p1->x >= p2->x) && (c >= d))){//se p2 estiver na area de impacto em x
		a = ((p1->y + p1->lenght/2) * 3) / 5;
		b = p2->y + p2->lenght/2;
		c = p2->y - p2->lenght/2;
		d = ((p1->y + p1->lenght/2) * 4) / 5;
	
		if (type == 1){
			if (((p1->y <= p2->y) && (d >= c)) || ((p1->y >= p2->y) && (a <= b)))	//se for soco e estar na altura certa NO CHAO!
				p2->hp -= p1->moves->damage[0];
		}
		else{	//se for chute NO CHAO
			if (abs(p2->x - p1->x) <= c)	//se p2 estiver abaixo da reta de 45° do chute
			      p2->hp -= p1->moves->damage[1];	
		}

	else if ();
	
	if (p2 esta no alcance do tiro de p1){
	}

	return;f (((p1->x <= p2->x) && (a >= b)) || ((p1->x >= p2->x) && (c >= d))){//se p2 estiver na area de impacto em x
                a = ((p1->y + p1->lenght/2) * 3) / 5;
                b = p2->y + p2->lenght/2;
                c = p2->y - p2->lenght/2;
                d = ((p1->y + p1->lenght/2) * 4) / 5;

                if (type == 1){
                        if (((p1->y <= p2->y) && (d >= c)) || ((p1->y >= p2->y) && (a <= b)))   //se for soco e estar na altura certa NO CHAO!
                                p2->hp -= p1->moves->damage[0];
                }
                else{   //se for chute NO CHAO
                        if (abs(p2->x - p1->x) <= c)    //se p2 estiver abaixo da reta de 45° do chute
                              p2->hp -= p1->moves->damage[1];
                }

        else if ();

        if (p2 esta no alcance do tiro de p1){
        }

        return;
}
f (((p1->x <= p2->x) && (a >= b)) || ((p1->x >= p2->x) && (c >= d))){//se p2 estiver na area de impacto em x
                a = ((p1->y + p1->lenght/2) * 3) / 5;
                b = p2->y + p2->lenght/2;
                c = p2->y - p2->lenght/2;
                d = ((p1->y + p1->lenght/2) * 4) / 5;

                if (type == 1){
                        if (((p1->y <= p2->y) && (d >= c)) || ((p1->y >= p2->y) && (a <= b)))   //se for soco e estar na altura certa NO CHAO!
                                p2->hp -= p1->moves->damage[0];
                }
                else{   //se for chute NO CHAO
                        if (abs(p2->x - p1->x) <= c)    //se p2 estiver abaixo da reta de 45° do chute
                              p2->hp -= p1->moves->damage[1];
                }

        else if ();

        if (p2 esta no alcance do tiro de p1){
f (((p1->x <= p2->x) && (a >= b)) || ((p1->x >= p2->x) && (c >= d))){//se p2 estiver na area de impacto em x
                a = ((p1->y + p1->lenght/2) * 3) / 5;
                b = p2->y + p2->lenght/2;
                c = p2->y - p2->lenght/2;
                d = ((p1->y + p1->lenght/2) * 4) / 5;

                if (type == 1){
                        if (((p1->y <= p2->y) && (d >= c)) || ((p1->y >= p2->y) && (a <= b)))   //se for soco e estar na altura certa NO CHAO!
                                p2->hp -= p1->moves->damage[0];
                }
                else{   //se for chute NO CHAO
                        if (abs(p2-
*/
