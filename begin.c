#include <stdlib.h>
#include "begin.h"

hero* hero_create(unsigned char lenght, unsigned char width, unsigned short x, unsigned short y, unsigned short max_x, unsigned short max_y){
	if ((x - width/2 < 0) || (x + width/2 > max_x) || (y - lenght/2 < 0) || (y + lenght/2 > max_y)) return NULL;
	hero *new_hero = (hero*) malloc (sizeof(hero));		
	if (!new_hero){
		printf ("Erro durante a alocação de um novo herói!\n");
		return NULL;
	}
	
	new_hero->lenght = lenght;
	new_hero->width = width;
	new_hero->x = x;
	new_hero->y = y;
	new_hero->control = joystick_create();
	
	return new_hero;
	
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

void update_health (hero *p1, hero *p2){
	if ((p1->x + p1->moves->range >= p2->x - p2->width) || (p2->x + p2->width >= p1->x - p1->moves->range)){//se p2 estiver na area de impacto 
		if (p1->moves->action[0]){	//se for soco e esta na area do soco
			if (//determinar a altura do soco)
				p2->hp--;//tiro dano personalizado ou padrao???????????
		}
		else if (p1->moves->action[1]){
		}

	else if ();
	
	if (p2 esta no alcance do tiro de p1){
	}

	return;
}

void hero_destroy(hero *element){
	joystick_destroy (element->control);
	free (element);
	
	return;
}
