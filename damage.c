#include "damage.h"

int check_hit (int min_x, int max_x, int min_y, int max_y, int x, int y, int length, int width){
	float sq_left = x - (width/2);
	float sq_right = x + (width/2);
	float sq_top = y - (length/2);
	float sq_bottom = y + (length/2);

	return !(max_x < sq_left || min_x > sq_right || max_y < sq_top || min_y > sq_bottom);
}

void stand_punch (int *min_x, int *max_x, int *min_y, int *max_y, int id){
	switch (id){
		case 1:
			*min_x = 10;
			*max_x = 20;
			*min_y = -20;
			*max_y = 0;
			break;
		case 2:
			*min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
		case 3:
			*min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
		default:
			*min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
	}

	return;
}

void down_punch (int *min_x, int *max_x, int *min_y, int *max_y, int id){
        switch (id){
                case 1:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                case 2:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                case 3:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                default:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
        }

        return;
}

void up_punch (int *min_x, int *max_x, int *min_y, int *max_y, int id){
        switch (id){
                case 1:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                case 2:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                case 3:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                default:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
        }

        return;
}

void stand_kick (int *min_x, int *max_x, int *min_y, int *max_y, int id){
        switch (id){
                case 1:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                case 2:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                case 3:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                default:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
        }

        return;
}

void down_kick (int *min_x, int *max_x, int *min_y, int *max_y, int id){
        switch (id){
                case 1:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                case 2:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                case 3:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                default:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
        }

        return;
}

void up_kick (int *min_x, int *max_x, int *min_y, int *max_y, int id){
        switch (id){
                case 1:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                case 2:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                case 3:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                default:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
        }

        return;
}

void special_select (int *min_x, int *max_x, int *min_y, int *max_y, int id){
        switch (id){
                case 1:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                case 2:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                case 3:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
                default:
                        *min_x = 10;
                        *max_x = 20;
                        *min_y = -20;
                        *max_y = 0;
                        break;
        }

        return;
}

void check_hit_box (int *min_x, int *max_x, int *min_y, int *max_y, int move, int id, int x, int y, int length, int width, int state_y, bool rigth){
	int minimo_x, maximo_x, minimo_y, maximo_y;

	switch(move){
		case KICK:
			if (!state_y)
				stand_kick (&minimo_x, &maximo_x, &minimo_y, &maximo_y, id);	
			else if (state_y == JUMP)
				up_kick (&minimo_x, &maximo_x, &minimo_y, &maximo_y, id);
			else
				down_kick (&minimo_x, &maximo_x, &minimo_y, &maximo_y, id);
			break;
		case PUNCH:
			if (!state_y)
				stand_punch (&minimo_x, &maximo_x, &minimo_y, &maximo_y, id);
			else if (state_y == JUMP)
				up_punch (&minimo_x, &maximo_x, &minimo_y, &maximo_y, id);
			else
				down_punch (&minimo_x, &maximo_x, &minimo_y, &maximo_y, id);
			break;
		default:
			special_select (&minimo_x, &maximo_x, &minimo_y, &maximo_y, id);
			break;
	}

	*min_y = y + minimo_y;
	*max_y = y + maximo_y;

	if (rigth){
		*min_x = x + width/2 + minimo_x;
		*max_x = x + width/2 + maximo_x;
	}
	else{
		*min_x = x - width/2 - maximo_x;
		*max_x = x - width/2 - minimo_x;
	}

	return;
}

void update_damage (int dam, float *hp, int *stun, bool up, bool down, int min_x, int max_x, int min_y, int max_y, int x, int y, int length, int width){
	bool hit_up, hit_down;

	hit_up = check_hit (min_x, max_x, min_y, max_y, x, y+(length/4), length/2, width);	//verifica se houve hit na porção superior e/ou inferior da box do player2
	hit_down = check_hit (min_x, max_x, min_y, max_y, x, y-(length/4), length/2, width);

	if (hit_up || hit_down){	//Se houve hit, stunna e tira vida
		*stun += STUN_TIME;
		*hp -= dam;
	}

	if (hit_up && up)	//Se o hit pegou em alguma regiao sendo defendida, recupera a vida, dando o efeito de dano reduzido
		*hp += dam * 0.8;
	else if (hit_down && down)
		*hp += dam *0.8;
	
	if (*hp < 0)
		*hp = 0;

	al_draw_filled_rectangle (min_x, min_y, max_x, max_y, al_map_rgba_f(0.5, 0.3, 0.0, 0.5));

	return;
}

void stamina_update (int state, bool drop, float *stamina){
        if (state == SPECIAL){	//Se estiver realizando acao, e drop estiver ativo, perde stamina no momento de impacto. Ao longo do golpe, nao recupera stamina!
                if (drop)
                        *stamina -= SPECIAL_STAMINA;
        }
        else if (state == KICK){
                if (drop)
                        *stamina -= KICK_STAMINA;
        }
        else if (state == PUNCH){
                if (drop)
                        *stamina -= PUNCH_STAMINA;
        }
        else if ((state == DEFENSE_UP) || (state == DEFENSE_DOWN))
                *stamina -= DEFENSE_STAMINA;
        else
                *stamina += STAMINA_RECOVERY;	//So recupera stamina se nao estiver realizando acao especial!
	
	if (*stamina > 100)	//Corrigi os valores da stamina para dentro dos parametros
		*stamina = 100;
	else if (*stamina < 0)
		*stamina = 0;

        return;
}
