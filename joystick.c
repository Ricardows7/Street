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

	return element;
}

void joystick_destroy (joystick *element){
	free (element);
	element = NULL;

	return;
}

void joystick_activate (joystick *element, int type, long move){	//funcao para guardar a ativação de ume estado
	if (type != 10)		//Se não estiver apertando o botão, não guarda a info
		return;
	
	if ((element->acumulation % move) == 0)		//Se já estiver com a info guardada, não guarda de novo
		return;

	element->acumulation *= move;

	return;
}

void joystick_deactivate (joystick *element, int type, long move){	//funcao para esquecer a ativacao de um estado
	if (type != 12)		//Se não estiver soltando o botão, não deleta a info
		return;

	if ((element->acumulation % move) == 0)		//Se tiver a info guardada, libera ela
		element->acumulation /= move;

	return;
}

void choose_move_x (joystick *element, bool air, unsigned short stun, unsigned short stamina){
	
