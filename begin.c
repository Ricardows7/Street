#include <stdlib.h>
#include "begin.h"

hero* hero_create(){
	hero *new_hero = (hero*) malloc (sizeof(hero));		
	if (!new_hero){
		printf ("Erro durante a alocação de um novo herói!\n");
		return NULL;
	}
	
	new_hero->id = 0;
	new_hero->lenght = 0;
	new_hero->width = 0;
	new_hero->x = 0;
	new_hero->y = 0;
	new_hero->stun = 0;
	new_hero->hp = 100;
	new_hero->stamina = 100;
	new_hero->jump = 0;
	new_hero->control = joystick_create();
	//new_hero->moves = create_action();
	//new_hero->ultimate = create_special ();
	//new_hero->state = NULL;

	return new_hero;
	
}

hero* choose_hero (hero* element, int type, unsigned short x, unsigned short y, unsigned short max_x, unsigned short max_y, unsigned short ground){

	element->x = x;
	element->jump = 0;
	
	//element->moves->timers[0] = PUNCH_COOLDOWN;
	//element->moves->timers[1] = KICK_COOLDOWN;

	if (type == 49){	//type se refere ao codigo do teclado
		element->id = 1;
	        element->lenght = 20;
        	element->width = 20;

		//element->moves->range[0] = 3;
		//element->moves->range[1] = 4;
	}
	else if (type == 50){
		element->id = 2;
                element->lenght = 20;
                element->width = 20;

                //element->moves->range[0] = 3;
                //element->moves->range[1] = 4;
	}
	else if (type == 51){
		element->id = 3;
                element->lenght = 20;
                element->width = 20;

                //element->moves->range[0] = 3;
                //element->moves->range[1] = 4;
	}
	else{
		element->id = 4;
                element->lenght = 20;
                element->width = 20;

                //element->moves->range[0] = 3;
                //element->moves->range[1] = 4;
	}

	element->y = ground + element->lenght/2;

	if ((x - element->width/2 < 0) || (x + element->width/2 > max_x) || (y - element->lenght/2 < ground) || (y + element->lenght/2 > max_y)){
	       	free (element);
		printf ("Erro na posição inicial dos jogadores!\n");
		return NULL;
	}

	return element;
}

void hero_move(hero *element, char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y, unsigned short ground){							//Implementação da função "square_move" (-1)

	if (!trajectory){ if ((element->x - steps*STREET_STEP) - element->width/2 >= 0) element->x = element->x - steps*STREET_STEP;} 				//Verifica se a movimentação para a esquerda é desejada e possível; se sim, efetiva a mesma
	else if (trajectory == 1){ if ((element->x + steps*STREET_STEP) + element->width/2 <= max_x) element->x = element->x + steps*STREET_STEP;}	//Verifica se a movimentação para a direita é desejada e possível; se sim, efetiva a mesma
	else if (trajectory == 2){
	       	if ((element->y - steps) - element->lenght/2 >= ground) element->y = element->y - steps;
	}		//Verifica se a movimentação para cima é desejada e possível; se sim, efetiva a mesma
	else if (trajectory == 3){ if ((element->y + steps*STREET_STEP) + element->lenght/2 <= max_y) element->y = element->y + steps*STREET_STEP;}	//Verifica se a movimentação para baixo é desejada e possível; se sim, efetiva a mesma
}

unsigned char collision (hero *element_first, hero *element_second){
	int a, b, c, d;

	if ((element_first->y+element_first->lenght/2 >= element_second->y-element_second->lenght/2) && (element_second->y-element_second->lenght/2 >= element_first->y-element_first->lenght/2))
		a = 1;
	else
		a = 0;

	if ((element_second->y+element_second->lenght/2 >= element_first->y-element_first->lenght/2) && (element_first->y-element_first->lenght/2 >= element_second->y-element_second->lenght/2))
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

void hero_jump (hero *element, hero *aux, int max_x, int max_y, int ground){
	if (!element)
		return;
	
	if (element->y - element->lenght/2 != ground)	//Se o heroi nao esta no chao, nao pula
		return;

	if (element->control->down || element->control->defense)	//Se o heroi esta agachado ou defendendo, nao pula
		return;
	
	element->jump = JUMP_VEL;
	element->control->air = 1;
	hero_move (element, element->jump, 2, max_x, max_y, ground);
        if (collision (element, aux)){
        	element->jump = -element->jump;
        	hero_move (element, element->jump, 2, max_x, max_y, ground);
		element->control->air = 0;
		element->jump = 0;
	}
	return;
}	

void hero_destroy(hero *element){
	joystick_destroy (element->control);

	free (element);
	
	return;
}
