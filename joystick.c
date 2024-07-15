#include "joystick.h"

joystick* joystick_create(){
	joystick *element;

	element = (joystick*) malloc (sizeof(joystick));
	if (!element){
		printf ("Erro ao alocar o joystick!\n");
		return NULL;
	}

	element->right = 0;
	element->left = 0;
	element->defense = 0;
	element->down = 0;
	element->air = 0;	//so e alterado na funcao de pular!

	return element;
}

void joystick_destroy (joystick *element){

	free (element);
	element = NULL;

	return;
}

void joystick_right (joystick *element, int type){
	if (!element->right && (type == 10)){	
		if (!element->defense && !element->down){
			element->right = 1;
			return;
		}
		else
			return;
	}
	else if (element->right && (type == 12)){
		element->right = 0;
		return;
	}
	return;
}

void joystick_left (joystick *element, int type){
	if (!element->left && (type == 10)){	
		if (!element->defense && !element->down){
			element->left = 1;
			return;
		}
		else
			return;
	}
	else if (element->left && (type == 12)){
		element->left = 0;
		return;
	}
	return;
}

void joystick_defense (joystick *element, int type){	//FAZER DEFESA PRA CIMA E PRA BAIXO!!!
	if (!element->defense && (type == 10)){
		if (element->air || element->down)
			return;
		element->left = 0;
		element->right = 0;
		element->defense = element->defense ^ 1;
	}
	else if (element->defense && (type == 12))
		element->defense = 0;
	
	return;
}

void joystick_down (joystick *element, int type){
	if (!element->down && (type == 10)){
		if (element->defense ||element->air)
			return;
		element->right = 0;
		element->left = 0;
		element->down = element->down ^ 1;
	}
	else if (element->down && (type == 12))
		element->down = 0;
	
	return;
}
