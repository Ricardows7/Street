#include <stdlib.h>
#include "hero.h"

hero* hero_create(){	//inicializacao do heroi
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
	new_hero->trajectory = false;
	new_hero->hitted = false;

	new_hero->control_x = joystick_create();
	new_hero->control_y = joystick_create();

	new_hero->image = NULL;

	return new_hero;
}

void reset_hero (hero *p){	//reseta para novo round
	p->stun = 0;
	p->hp = 100;
	p->stamina = 100;
	p->air = false;
	p->jump = 0;
	p->trajectory = false;
	p->hitted = false;
	
	p->control_x->acumulation = 1;
	p->control_x->state = 0;
	p->control_x->timer = 0;
	p->control_x->change = true;

	p->control_y->acumulation = 1;
        p->control_y->state = 0;
        p->control_y->timer = 0;
        p->control_y->change = true;

	return;
}

hero* choose_hero (hero* element, int type, int x, int max_x, int max_y, int ground){	//define os aspectos e bitmaps

	reset_hero (element);

	element->x = x;

	element->length = 220;
      	element->width = 141;

	element->id = type + 1;

	if (element->id == 1)
	        element->image = al_load_bitmap ("rafaelo.png");
	else if (element->id == 2)
                element->image = al_load_bitmap ("donatello_2.png");
	else if (element->id == 3)
                element->image = al_load_bitmap ("Michelangelo.png");
	else
                element->image = al_load_bitmap ("sodaleonard.png");

	if (!element->image){
		printf ("Erro no load das imagens!\n");
		return NULL;
	}

	element->y = ground - element->length/2;	//como y spawna acima do chao, nunca passara pra baixo da tela!

	if ((x - element->width/2 < 0) || (x + element->width/2 > max_x) || (element->y - element->length/2 < 0)){
	       	free (element);
		printf ("Erro na posição inicial dos jogadores!\n");
		return NULL;
	}

	return element;
}

int aleat (){
	return (rand() % 100) + 1;
}

void robot (hero *element, hero *target){	//funcao do bot
	int value = aleat();
	element->control_x->acumulation = 1;

	if (element->x < target->x){
		if ((element->x + element->width/2 + 50) < (target->x - target->width/2)){
			joystick_activate (element->control_x, 10, WALK_RIGHT);
			return;
		}
	}
	else{
		if ((element->x - element->width/2 - 50) > (target->x + target->width/2)){
			joystick_activate (element->control_x, 10, WALK_LEFT);
			return;
		}
	}

	if (value < 11)
		joystick_activate (element->control_x, 10, SPECIAL);
	else if (value < 51)
		joystick_activate (element->control_x, 10, KICK);
	else
		joystick_activate (element->control_x, 10, PUNCH);
	
	return;
}
	
void hero_move(hero *element, char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y, unsigned short ground){
	if (!trajectory){ if ((element->x - steps*STREET_STEP) - element->width/2 >= 0) element->x = element->x - steps*STREET_STEP;} 	
	else if (trajectory == 1){ if ((element->x + steps*STREET_STEP) + element->width/2 <= max_x) element->x = element->x + steps*STREET_STEP;}
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

void hero_movement (hero *p1, hero *p2, char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y, unsigned short ground){
	hero_move (p1, steps, trajectory, max_x, max_y, ground);	//movimenta e analisa a colisao
	if (collision (p1, p2)){
		hero_move (p1, -steps, trajectory, max_x, max_y, ground);
		if (p1->air && trajectory == 2)		//so inverte pulo se for chamado da movimentacao vertical!
			p1->jump = -p1->jump;
	}
	return;
}

void update_position (hero *p1, hero *p2, int max_x, int max_y, int ground, int gravity){
	if (!p1->control_y->state && p1->control_y->change)	//Se estiver livre em y e puder chamar, escolhe algo em y
		choose_move_y (p1->control_y, p1->control_x, p1->stun);	

	if (verify_action (p1->control_x->state) && p1->control_x->change)	//Se nao estiver realizando movimento especial e puder chamar, escolhe em x
		choose_move_x (p1->control_x, p1->control_y, p1->stamina, p1->stun, p1->x, p2->x, &p1->trajectory, &p1->hitted);

	if (!p1->hp){	//Se estiver morto, conta um clock e atualiza em y (caso morra no ar ou agachado)
		p1->control_y->acumulation = 1;
		if (p1->control_x->timer < 10)
			p1->control_x->timer++;
		position_y (p1,p2,max_x,max_y,ground,gravity);
		return;
	}

	position_x (p1, p2, max_x, max_y, ground, gravity);	//Atualiza a situacao nos eixos
	position_y (p1, p2, max_x, max_y, ground, gravity);

	stamina_update (p1->control_x->state, false, &p1->stamina, false);	//Recupera stamina se for possivel

        if (p1->stun > 0)	//Atualiza o stun
                p1->stun--;
	else if (p1->stun < 0)
		p1->stun = 0;

        return;
}

void position_x (hero *p1, hero *p2, int max_x, int max_y, int ground, int gravity){
	int minimo_x, maximo_x, minimo_y, maximo_y, store;
	float damage;

	switch (p1->control_x->state){
		case SPECIAL:
			p1->control_x->timer++;
			p1->control_y->change = false;
			switch (p1->id){
				case 1:
					p1->hitted = false;	//Pode acertar multiplas vezes
					if (!p1->trajectory)	//Rafaelo e obrigado a se movimentar no sentido inicial do oponente
						hero_movement (p1, p2, 2, 1, max_x, max_y, ground);
					else
						hero_movement (p1, p2, 2, 0, max_x, max_y, ground);
					damage = RAFA_SPECIAL;
					break;
				case 2:
					p1->hitted = false;	
					if (p1->control_x->acumulation % WALK_RIGHT == 0)	//Donatello pode se movimentar durante special
						hero_movement (p1, p2, 1, 1, max_x, max_y, ground);
					else if (p1->control_x->acumulation % WALK_LEFT == 0)
						hero_movement (p1, p2, 1, 0, max_x, max_y, ground);
					damage = DONA_SPECIAL;
					break;
				case 3:
					if (!p1->trajectory)	//Michelangelo move no sentido contrario do oponente
                                                hero_movement (p1, p2, 2, 0, max_x, max_y, ground);
                                        else
                                                hero_movement (p1, p2, 2, 1, max_x, max_y, ground);
					if (p1->control_x->timer > 30){
						p1->control_x->state = 0;
						p1->control_x->timer = 0;
						p1->control_y->change = true;
						stamina_update (p1->control_x->state, true, &p1->stamina, false);
					}
                                        break;
				case 4:
					if (p1->control_x->timer > 30){
               					p1->control_x->state = 0;
                                                p1->control_x->timer = 0;
                                                p1->control_y->change = true;
						stamina_update (p1->control_x->state, true, &p1->stamina, false);
                                        }
					damage = LEO_SPECIAL;
					break;
			}
			store = check_hit_box (&minimo_x, &maximo_x, &minimo_y, &maximo_y, SPECIAL, p1->id, p1->x, p1->y, p1->length, p1->width, p1->control_y->state, p1->trajectory, p1->control_x->timer, p1->control_x->state, &p1->stamina);
			update_damage(damage, &p2->hp, &p2->stun, !(p2->control_x->state - DEFENSE_UP), !(p2->control_x->state - DEFENSE_DOWN), minimo_x, maximo_x, minimo_y, maximo_y, p2->x, p2->y, p2->length, p2->width, store, &p1->hitted, &p2->control_x->timer);
			if (p1->control_x->timer > 60){	//Dura ate 60 ciclos
				stamina_update (p1->control_x->state, true, &p1->stamina, false);          
				p1->control_x->state = 0;
				p1->control_x->timer = 0;
				p1->control_y->change = true;
			}
			break;
		case KICK:
			p1->control_y->change = false;
                        p1->control_x->timer++;
			store = check_hit_box (&minimo_x, &maximo_x, &minimo_y, &maximo_y, KICK, p1->id, p1->x, p1->y, p1->length, p1->width, p1->control_y->state, p1->trajectory, p1->control_x->timer, p1->control_x->state, &p1->stamina);
                     	update_damage (KICK_DAMAGE, &p2->hp, &p2->stun, !(p2->control_x->state - DEFENSE_UP), !(p2->control_x->state - DEFENSE_DOWN), minimo_x, maximo_x, minimo_y, maximo_y, p2->x, p2->y, p2->length, p2->width, store, &p1->hitted, &p2->control_x->timer);
			if (p1->control_x->timer > 20 && !p1->air){	//So termina o golpe se nao estiver no ar! Se estiver no ar, funcao jump termina
				p1->control_x->state = 0;
                                p1->control_x->timer = 0;
				p1->control_y->change = true;
                        }

			break;
		case PUNCH:
			p1->control_y->change = false;
			p1->control_x->timer++;
			store = check_hit_box (&minimo_x, &maximo_x, &minimo_y, &maximo_y, PUNCH, p1->id, p1->x, p1->y, p1->length, p1->width, p1->control_y->state, p1->trajectory, p1->control_x->timer, p1->control_x->state, &p1->stamina);
			update_damage (PUNCH_DAMAGE, &p2->hp, &p2->stun, !(p2->control_x->state - DEFENSE_UP), !(p2->control_x->state - DEFENSE_DOWN), minimo_x, maximo_x, minimo_y, maximo_y, p2->x, p2->y, p2->length, p2->width, store, &p1->hitted, &p2->control_x->timer);

			if (p1->control_x->timer > 20 && !p1->air){
				p1->control_x->state = 0;
				p1->control_x->timer = 0;
				p1->control_y->change = true;
			}
			break;
		case DEFENSE_UP:
			p1->control_y->change = false;
			p1->control_x->timer++;
			if (p1->control_x->timer > 30)
				p1->control_x->timer = 0;
			stamina_update (p1->control_x->state, true, &p1->stamina, false);
			if ((p1->control_x->acumulation % DEFENSE_UP != 0) || (p1->stamina < DEFENSE_STAMINA)){	//Se largar o botao de defesa ou acabar a stamina necessaria
				p1->control_x->state = 0;
				p1->control_x->timer = 0;
				p1->control_y->change = true;
			}
			break;
		case DEFENSE_DOWN:
			p1->control_y->change = false;	//Trava o eixo y enquanto esta defendendo
			p1->control_x->timer++;
			if (p1->control_x->timer > 30)
				p1->control_x->timer = 0;
			stamina_update (p1->control_x->state, true, &p1->stamina, false);
			if ((p1->control_x->acumulation % DEFENSE_DOWN != 0) || (p1->stamina < DEFENSE_STAMINA)){
				p1->control_x->state = 0;
				p1->control_x->timer = 0;
				p1->control_y->change = true;
			}		
			break;
		case WALK_LEFT:
			if (p1->control_y->state != GET_DOWN){
				hero_movement(p1, p2, 1, 0, max_x, max_y, ground);
				p1->control_x->timer++;
			}
			if (p1->control_x->timer > 30)
				p1->control_x->timer = 0;
			if (p1->control_x->acumulation % WALK_LEFT != 0 || p1->stun > 0){ 	//Se largar o botao de evento continuo, corrigi aqui o state
				p1->control_x->state = 0;
				p1->control_x->timer = 0;
			}
			break;
		case WALK_RIGHT:
			if (p1->control_y->state != GET_DOWN){		//Se nao estiver agachado, move pra direita e acrescenta no timer
				hero_movement(p1, p2, 1, 1, max_x, max_y, ground);
				p1->control_x->timer++;
			}
			if (p1->control_x->timer > 30)		//se o timer estourou do limite de sprints, reseta
				p1->control_x->timer = 0;
			if (p1->control_x->acumulation % WALK_RIGHT != 0 || p1->stun > 0){	//Se largou o botão, nao anda mais
				p1->control_x->state = 0;
				p1->control_x->timer = 0;
			}
			break;
		case 0:
			p1->control_x->timer++;
			if (p1->control_x->timer > 30){
				p1->control_x->timer = 0;
			}
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
			if (p1->control_y->timer < 30)
				p1->control_y->timer++;

			if ((p1->control_y->acumulation % GET_DOWN != 0 && verify_action (p1->control_x->state)) || p1->stun > 0){	//condicao pra sair do estado agachado
				p1->control_y->timer++;		
				p1->control_x->change = false;	
				if (p1->control_y->timer >= 0){
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
				if (p1->y+p1->length/2 >= ground){	//Logica de aterrisagem
					p1->control_x->state = 0;
					p1->control_x->change = false;
					p1->control_y->timer++;
					if (p1->control_y->timer > 20){
						p1->air = false;
						p1->control_y->state = 0;
						p1->control_y->change = true;
						p1->control_y->timer = 0;
						p1->control_x->change = true;
						p1->control_x->timer = 0;
					}
					return;
				}
				if (!(p1->control_x->acumulation % WALK_RIGHT) && (p1->control_x->state != WALK_RIGHT))	//Possibilidade de se movimentar no ar no eixo x, mesmo durante um golpe
					hero_movement (p1, p2, 1, 1, max_x, max_y, ground);
                                else if (!(p1->control_x->acumulation % WALK_LEFT) && (p1->control_x->state != WALK_LEFT))
                                        hero_movement (p1, p2, 1, 0, max_x, max_y, ground);
				
				p1->jump -= gravity;
				hero_movement (p1, p2, p1->jump, 2, max_x, max_y, ground);
				if (p1->control_y->timer < 15)
					p1->control_y->timer++;
			}
			else{	//Logica de decolagem
				p1->control_x->change = false;	
				p1->control_x->state = 0;
				p1->control_y->timer++;
				if (p1->control_y->timer > 10){		//So taca o personagem no ar depois da animacao de pulo
					hero_jump (p1, p2, max_x, max_y, ground);
					p1->control_x->change = true;
					p1->control_x->timer = 0;
				}
			}
			break;
		case 0:
			p1->control_y->timer++;
			if (p1->control_y->timer > 30)
				p1->control_y->timer = 0;
			break;
	}
	return;
}

void hero_jump (hero *element, hero *aux, int max_x, int max_y, int ground){  
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

	al_destroy_bitmap (element->image);

        free (element);
	element = NULL;

        return;
}
