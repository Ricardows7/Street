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
	element->change = true;

	return element;
}

void joystick_destroy (joystick *element){
	if (!element)
		return;

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

int choose_move_y (joystick *element, joystick *aux, int stun){
	if (stun > 0)
		return -1;

	if (element->acumulation % GET_DOWN == 0 && verify_action (aux->state))
		element->state = GET_DOWN;
	else if (element->acumulation % JUMP == 0 && verify_action (aux->state))
		element->state = JUMP;
	else
		element->state = 0;

	element->timer = 0;

	return 0;
}

int choose_move_x (joystick *element, joystick *aux, float stamina, int stun, int x_1, int x_2, bool *traj, bool *hitted){
	if (stun > 0)	//se o personagem estiver stunado, nao realiza movimentacao alguma
		return -1;

	*traj = (x_1 > x_2);	//Calcula a posicao do oponente
	*hitted = false;        //Reseta se acertou o oponente ou nao

	if (element->acumulation % SPECIAL == 0 && !aux->state && stamina >= SPECIAL_STAMINA)	//Condicoes para escolher o movimento (ter pressionado o botao, estar com eixo y livre, ter stamina o bastante)
		element->state = SPECIAL;
	else if (element->acumulation % KICK == 0 && stamina >= KICK_STAMINA)
		element->state = KICK;
	else if (element->acumulation % PUNCH == 0 && stamina >= PUNCH_STAMINA)
		element->state = PUNCH;
	else if ((element->acumulation % DEFENSE_UP == 0) && (!aux->state) && (stamina >= DEFENSE_STAMINA))
		element->state = DEFENSE_UP;
	else if ((element->acumulation % DEFENSE_DOWN == 0) && (!aux->state) && (stamina >= DEFENSE_STAMINA))
		element->state = DEFENSE_DOWN;
	else if (element->acumulation % WALK_LEFT == 0 && aux->state != GET_DOWN){
		element->state = WALK_LEFT;	//Nao reseta clock do movimento, pois pode ser enterrompido
		return 0;
	}
	else if (element->acumulation % WALK_RIGHT == 0 && aux->state != GET_DOWN){	//So move se nao estiver agachado
		element->state = WALK_RIGHT;
		return 0;
	}
	else{
		element->state = 0;	//Se nao fizer nada, estado 0!
		return 0;
	}

	element->timer = 0;

	return 0;
}

int verify_action (int value){	//Retorna 1 se nao estiver realizando acoes especiais!
	if ((value != SPECIAL) && (value != KICK) && (value != PUNCH) && (value != DEFENSE_DOWN) && (value != DEFENSE_UP))
			return 1;
	return 0;
}
