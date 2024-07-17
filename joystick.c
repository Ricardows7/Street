#include "joystick.h"

joystick* joystick_create(){
	joystick *element;

	element = (joystick*) malloc (sizeof(joystick));
	if (!element){
		printf ("Erro ao alocar o joystick!\n");
		return NULL;
	}

	element->acumulation = 1;
	element->timer = 0;
	element->state = false;
	element->air = false;
	element->jump = 0;	//so e alterado na funcao de pular!

	return element;
}

void joystick_destroy (joystick *element){
	free (element);
	element = NULL;

	return;
}

void joystick_activate (joystick *element, int type, long move){
	if (type != 10)		//Se não estiver apertando o botão, não guarda a info
		return;
	
	if ((element->acumulation % move) == 0)		//Se já estiver com a info guardada, não guarda de novo
		return;

	element->acumulation *= move;

	return;
}


