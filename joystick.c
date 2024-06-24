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
	element->up = 0;
	element->down = 0;

	return element;
}

void joystick_destroy (joystick *element){
	free (element);
	element = NULL;

	return;
}

void joystick_right (joystick *element){ element->right = element->right ^ 1;}

void joystick_left (joystick *element){ element->left = element->left ^ 1;}

void joystick_up (joystick *element){ element->up = element->up ^ 1;}

void joystick_down (joystick *element){ element->down = element->down ^ 1;}

