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
	new_hero->moves = create_action();
	new_hero->special = create_special (hero* element);

	return new_hero;
	
}

hero* choose_hero (hero* element, int type, unsigned short x, unsigned short y, unsigned short max_x, unsigned short max_y){

	element->x = x;
	element->y = y;

	if (type == 49){	//type se refere ao codigo do teclado
		element->id = 1;
	        element->lenght = 20;
        	element->width = 20;

		element->moves->timers[0] = 3;
		element->moves->range[0] = 3;
		element->moves->damage[0] = 3;

		element->moves->timers[1] = 3;
		element->moves->range[1] = 4;
		element->moves->damage[1] = 4;
	}
	else if (type == 50){
		element->id = 2;
                element->lenght = 20;
                element->width = 20;

                element->moves->timers[0] = 3;
                element->moves->range[0] = 3;
                element->moves->damage[0] = 3;

                element->moves->timers[1] = 3;
                element->moves->range[1] = 4;
                element->moves->damage[1] = 4;
	}
	else if (type == 51){
		element->id = 3;
                element->lenght = 20;
                element->width = 20;

                element->moves->timers[0] = 3;
                element->moves->range[0] = 3;
                element->moves->damage[0] = 3;

                element->moves->timers[1] = 3;
                element->moves->range[1] = 4;
                element->moves->damage[1] = 4;
	}
	else{
		element->id = 4;
                element->lenght = 20;
                element->width = 20;

                element->moves->timers[0] = 3;
                element->moves->range[0] = 3;
                element->moves->damage[0] = 3;

                element->moves->timers[1] = 3;
                element->moves->range[1] = 4;
                element->moves->damage[1] = 4;
	}

	if ((x - element->width/2 < 0) || (x + element->width/2 > max_x) || (y - element->lenght/2 < 0) || (y + element->lenght/2 > max_y)) return NULL;

	return element;
}

void hero_move(hero *element, char steps, unsigned char trajectory, unsigned short max_x, unsigned short max_y){							//Implementação da função "square_move" (-1)

	if (!trajectory){ if ((element->x - steps*STREET_STEP) - element->width/2 >= 0) element->x = element->x - steps*STREET_STEP;} 				//Verifica se a movimentação para a esquerda é desejada e possível; se sim, efetiva a mesma
	else if (trajectory == 1){ if ((element->x + steps*STREET_STEP) + element->width/2 <= max_x) element->x = element->x + steps*STREET_STEP;}	//Verifica se a movimentação para a direita é desejada e possível; se sim, efetiva a mesma
	else if (trajectory == 2){ if ((element->y - steps*STREET_STEP) - element->lenght/2 >= 0) element->y = element->y - steps*STREET_STEP;}		//Verifica se a movimentação para cima é desejada e possível; se sim, efetiva a mesma
	else if (trajectory == 3){ if ((element->y + steps*STREET_STEP) + element->lenght/2 <= max_y) element->y = element->y + steps*STREET_STEP;}	//Verifica se a movimentação para baixo é desejada e possível; se sim, efetiva a mesma
}

unsigned char collision (hero *element_first, hero *element_second){
	int a, b, c, d;

	if ((element_first->y+element_first->lenght/2 >= element_second->y-element_second->lenght/2) && (element_second->y-element_second_lenght/2 >= element_first->y-element_first->lenght/2))
		a = 1;
	else
		a = 0;

	if ((element_second->y+element_second->lenght/2 >= element_first->y-element-first->lenght/2) && (element_first->y-element_first->lenght/2 >= element_second->y-element_second->lenght/2))
		b = 1;
	else
		b = 0;

	if ((element_first->x+element_first->width/2 >= element_second->x-element_second->width/2) && (element_second->x-element_second->width/2 >= element_first->x-element_first->width/2))
		c = 1;
	else
		c = 0;

	if ((element_second->x+element_second->width/2 >= element_first->x-element_first->width/2) && (element_first->x-element_first->width/2 >= element_second->x-element_second->width/2));
		d = 1;
	else
		d = 0;

	if ((a || b) && (c || d))
		return 1;
	else
		return 0;
}

void update_position (hero *p1, hero *p2){
	if (p1->control->left){
		hero_move (p1, 1, 0, X_SCREEN, Y_SCREEN);
		if (collision (p1, p2))
			hero_move (p1, -1, 0, X_SCREEN, Y_SCREEN);
	}
	if (p1->control->right){
		hero_move (p1, 1, 1, X_SCREEN, Y_SCREEN);
		if (collision (p1, p2))
			hero_move (p1, -1, 1, X_SCREEN, Y_SCREEN);
	}
	if (p1->control->up){
		hero_move (p1, 1, 2, X_SCREEN, Y_SCREEN);
		if (collision (p1, p2))
			hero_move (p1, -1, 2, X_SCREEN, Y_SCREEN);
	}
	if (p1->control->down){
		hero_move (p1, 1, 3, X_SCREEN, Y_SCREEN);
		if (collision (p1, p2))
			hero_move (p1, -1, 3, X_SCREEN, Y_SCREEN);
	}
	if (p2->control->left){	
		hero_move (p2, 1, 0, X_SCREEN, Y_SCREEN);
		if (collision (p1, p2))
			hero_move (p2, -1, 0, X_SCREEN, Y_SCREEN);
	}
	if (p2->control->right){
		hero_move (p2, 1, 1, X_SCREEN, Y_SCREEN);
		if (collision (p1, p2))
			hero_move (p2, -1, 1, X_SCREEN, Y_SCREEN);
	}
	if (p2->control->up){
		hero_move (p2, 1, 2, X_SCREEN, Y_SCREEN);
		if (collision (p1, p2))
			hero_move (p2, -1, 2, X_SCREEN, Y_SCREEN);
	}
	if (p2->control->down){
		hero_move (p2, 1, 3, X_SCREEN, Y_SCREEN);
		if (collision (p1, p2))
			hero_move (p2, -1, 3, X_SCREEN, Y_SCREEN);
	}

	return;
}

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

void hero_destroy(hero *element){
	joystick_destroy (element->control);
	free (element);
	
	return;}
