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
	element->state = 0;

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

int choose_move_y (joystick *element, joystick *aux, unsigned short stun, unsigned short stamina){	//REVISAR AS CONDIÇÕES!!!
	if (stun > 0)
		return -1;

	if (element->acumulation % GET_DOWN == 0)	//if aux state e 0, 2 ou 3!!! DA PRA TRAVAR MOVIMENTO EM Y NESSAS FUNCOES! TALVEZ SO VERIFICAR PRA SOCO E CHUTE???
		element->state = GET_DOWN;
	else if (element->acumulation % JUMP == 0)
		element->state = JUMP;
	else
		element->state = 0;

	element->timer = 0;

	return 0;
}

int choose_move_x (joystick *element, joystick *aux,  unsigned short stun, unsigned short stamina){
	if (stun > 0)	//se o personagem estiver stunado, nao realiza movimentacao alguma
		return -1;	//ACHO QUE TENHO QUE TROCAR O STATE PRA 0 OU PRA UMA IMAGEM STUNADA!!!!!!

	if (element->acumulation % SPECIAL == 0 && !aux->state)//REVER ESSA LOGICA DO !AUX (TEM ACUMULATION EM Y TAMBEM!!!!!!
		element->state = SPECIAL;
	else if (element->acumulation % KICK == 0)
		element->state = KICK;
	else if (element->acumulation % PUNCH == 0)
		element->state = PUNCH;
	else if (element->acumulation % DEFENSE_UP == 0 && !aux->state)
		element->state = DEFENSE_UP;
	else if (element->acumulation % DEFENSE_DOWN == 0 && !aux->state)
		element->state = DEFENSE_DOWN;
	else if (element->acumulation % WALK_LEFT == 0)	//LEMBRAR DA POSSIBILIDADE DE SO RETORNAR O VALOR DO MOVIMENTO PRA OUTRA FUNCAO!!!!!!!!!!!!
		element->state = WALK_LEFT;
	else if (element->state % WALK_RIGHT == 0)
		element->state = WALK_RIGHT;
	else
		element->state = 0;	//SE NAO FIZER NADA, ESTADO 0!!!!!!!!
	
	element->timer = 0;

	return 0;
}

int verify_action (long value){
	if ((value != SPECIAL) && (value != KICK) && (value != PUNCH) && (value != DEFENSE_DOWN) && (value != DEFENSE_UP))
			return 1;
	return 0;
}
