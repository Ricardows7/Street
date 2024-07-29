#include "damage.h"

int check_hit (int min_x, int max_x, int min_y, int max_y, int x, int y, int length, int width){
	float sq_left = x - (width/2);
	float sq_right = x + (width/2);
	float sq_top = y - (length/2);
	float sq_bottom = y + (length/2);

	return !(max_x < sq_left || min_x > sq_right || max_y < sq_top || min_y > sq_bottom);
}

int stand_punch (int *min_x, int *max_x, int *min_y, int *max_y, int id, int clock, int state_x, float *stamina, bool right){
	switch (id){
		case 1:
			if ((clock <= 20) && (clock >= 10)){
                                *min_x = 40;
                                *max_x = 85;
                                *min_y = -50;
                                *max_y = -35;
                                if (right){
                                        *min_x -= 40;
                                        *max_x -= 35;
                                }
                                if (clock == 20)
                                        stamina_update (state_x, true, stamina, false);
                                return 1;
                        }
			break;
		case 2:
			if ((clock <= 20) && (clock >= 10)){
                                *min_x = 0;
                                *max_x = 130;
                                *min_y = -125;
                                *max_y = -10;
                                if (right){
                                        *min_x -= 20;
                                        *max_x -= 5;
                                }
                                if (clock == 20)
                                        stamina_update (state_x, true, stamina, false);
                                return 1;
                        }
                        break;
		case 3:
			if ((clock <= 20) && (clock >= 10)){
                                *min_x = 50;
                                *max_x = 100;
                                *min_y = -150;
                                *max_y = -80;
                                if (right){
                                        *min_x -= 20;
                                        *max_x -= 5;
                                }
                                if (clock == 20)
                                        stamina_update (state_x, true, stamina, false);
                                return 1;
                        }
                        break;
		case 4:
			if ((clock <= 20) && (clock >= 10)){
				*min_x = 40;
                        	*max_x = 110;
                        	*min_y = -45;
                        	*max_y = -25;
				if (right){
					*min_x -= 20;
                                	*max_x -= 15;
				}
				if (clock == 20)
					stamina_update (state_x, true, stamina, false);
				return 1;
			}
                        break;
	}

	return 0;
}

int down_punch (int *min_x, int *max_x, int *min_y, int *max_y, int id, int clock, int state_x, float *stamina, bool right){
        switch (id){
                case 1:
                        *min_x = 80;
                        *max_x = 148;
                        *min_y = -35;
                        *max_y = -12;
                        if (right)
                                *min_x -= 20;
                        if (!clock)
                                stamina_update (state_x, true, stamina, false);
                        return 1;
                        break;
                case 2:
                        *min_x = 20;
                       	*max_x = 90;
                        *min_y = -30;
                        *max_y = -10;
                        if (right){
                                *min_x -= 10;
                                *max_x -= 10;
                        }
                        if (!clock)
                                stamina_update (state_x, true, stamina, false);
                        return 1;
                        break;
                case 3:
                      	*min_x = 20;
                        *max_x = 50;
                        *min_y = -40;
                        *max_y = -10;
                        if (right)
                                *min_x -= 30;
                        if (!clock)
                                stamina_update (state_x, true, stamina, false);
                        return 1;
                        break;
                case 4:
                        *min_x = 20;
                        *max_x = 85;
                        *min_y = 40;
                        *max_y = 60;
			if (right){
				*min_x -= 30;
				*max_x -= 30;
			}
			if (!clock)
				stamina_update (state_x, true, stamina, false);
			return 1;
                        break;
        }

        return 0;
}

int up_punch (int *min_x, int *max_x, int *min_y, int *max_y, int id, int clock, int state_x, float *stamina, bool right){
        switch (id){
                case 1:
			if (clock < 10)
				return 0;
                        *min_x = 40;
                      	*max_x = 90;
                  	*min_y = 40;
                	*max_y = 80;
                 	if (right)
                         	*min_x -= 20;
                        if (!clock)
                                stamina_update (state_x, true, stamina, true);
                        return 1;
                        break;
                case 2:
                       	if (clock < 10){
                                *min_x = 10;
                                *max_x = 40;
                                *min_y = -80;
                                *max_y = 80;
                        }
                        else{
                                *min_x = 10;
                                *max_x = 70;
                                *min_y = 100;
                                *max_y = 170;
                                if (right)
                                        *min_x -= 20;
                        }
                        if (!clock)
                                stamina_update (state_x, true, stamina, true);
                        return 1;
                        break;
                case 3:
                        if (clock < 10){
                                *min_x = 10;
                                *max_x = 40;
                                *min_y = -80;
                                *max_y = 80;
                        }
                        else{
                                *min_x = -5;
                                *max_x = 30;
                                *min_y = 100;
                                *max_y = 170;
                                if (right){
                                        *min_x -= 20;
                                        *max_x -= 0;
                                }
                        }
                        if (!clock)
                                stamina_update (state_x, true, stamina, true);
                        return 1;
                        break;
                case 4:
			if (clock < 10){
                        	*min_x = 10;
                        	*max_x = 80;
                        	*min_y = -80;
                        	*max_y = 80;
			}
			else{
				*min_x = -5;
                                *max_x = 30;
                                *min_y = 100;
                                *max_y = 170;
				if (right){
					*min_x -= 20;
					*max_x -= 20;
				}
			}
			if (!clock)
				stamina_update (state_x, true, stamina, true);
			return 1;
                        break;
        }

        return 0;
}

int stand_kick (int *min_x, int *max_x, int *min_y, int *max_y, int id, int clock, int state_x, float *stamina, bool right){
        switch (id){
                case 1:
                        if ((clock >= 10) && (clock <= 20)){
                                *min_x = 30;
                                *max_x = 85;
                                *min_y = -130;
                                *max_y = -80;
                                if (right){
                                        *max_x += 10;
					*min_x += 20;
				}
                                if (clock == 10)
                                        stamina_update (state_x, true, stamina, false);
                                return 1;
                        }
                        break;
                case 2:
                        if ((clock >= 10) && (clock <= 20)){
                                *min_x = 10;
                                *max_x = 95;
                                *min_y = -100;
                                *max_y = -60;
                                if (right)
                                        *max_x -= 0;
                                if (clock == 10)
                                        stamina_update (state_x, true, stamina, false);
                                return 1;
                        }
                        break;
                case 3:
                        if ((clock >= 10) && (clock <= 20)){
                                *min_x = 10;
                                *max_x = 95;
                                *min_y = -105;
                                *max_y = -70;
                                if (right)
                                        *max_x -= 0;
                                if (clock == 10)
                                        stamina_update (state_x, true, stamina, false);
                                return 1;
                        }
                        break;
                case 4:
			if ((clock >= 10) && (clock <= 20)){
                        	*min_x = 10;
                        	*max_x = 130;
                        	*min_y = -30;
                        	*max_y = 0;
				if (right)
					*max_x -= 10;
				if (clock == 10)
					stamina_update (state_x, true, stamina, false);
				return 1;
			}
                        break;
        }

        return 0;
}

int down_kick (int *min_x, int *max_x, int *min_y, int *max_y, int id, int clock, int state_x, float *stamina, bool right){
        switch (id){
                case 1:
                        if ((clock >= 10) && (clock <= 20)){
                                *min_x = 15;
                                *max_x = 80;
                                *min_y = 30;
                                *max_y = 60;
                                if (right)
                                        *max_x += 0;
                                if (clock == 10)
                                        stamina_update (state_x, true, stamina, false);
                                return 1;
                        }
                        break;
                case 2:
                        if ((clock >= 10) && (clock <= 20)){
                                *min_x = 30;
                                *max_x = 90;
                                *min_y = -110;
                                *max_y = -70;
                                if (right)
                                        *max_x -= 10;
                                if (clock == 10)
                                        stamina_update (state_x, true, stamina, false);
                                return 1;
                        }
                        break;
                case 3:
                        if ((clock >= 10) && (clock <= 20)){
                                *min_x = 5;
                                *max_x = 63;
                                *min_y = 30;
                                *max_y = 60;
                                if (right)
                                        *max_x += 7;
                                if (clock == 10)
                                        stamina_update (state_x, true, stamina, false);
                                return 1;
                        }
                        break;
                case 4:
			if ((clock >= 10) && (clock <= 20)){
                        	*min_x = 10;
                        	*max_x = 60;
                        	*min_y = 30;
                        	*max_y = 60;
				if (right)
					*max_x -= 10;
				if (clock == 10)
					stamina_update (state_x, true, stamina, false);
				return 1;
			}
                        break;
        }

        return 0;
}

int up_kick (int *min_x, int *max_x, int *min_y, int *max_y, int id, int clock, int state_x, float *stamina, bool right){
        switch (id){
                case 1:
                        if (clock < 10)
                                return 0;
                        *min_x = 10;
                        *max_x = 70;
                        *min_y = 90;
                        *max_y = 160;
                        if (right)
                                *max_x += 0;
                        if (clock == 10)
                                stamina_update (state_x, true, stamina, true);
                        return 1;
                        break;
                case 2:
                      	if (clock < 10)
				return 0;
			*min_x = 30;
                     	*max_x = 80;
                  	*min_y = 60;
                 	*max_y = 110;
                        if (!clock)
                                stamina_update (state_x, true, stamina, true);
                        return 1;
                        break;
                case 3:
			if (clock < 10)
				return 0;
                        *min_x = 10;
                        *max_x = 50;
                        *min_y = 50;
                        *max_y = 140;
			if (right)
				*max_x += 20;
			if (clock == 10)
				stamina_update (state_x, true, stamina, true);
			return 1;
                        break;
                case 4:
                        if (clock < 10){ 
                                *min_x = 10;
                                *max_x = 80;
                                *min_y = -80;
                                *max_y = 80;
                        }
                        else{
                                *min_x = -40;
                                *max_x = 30;
                                *min_y = 100;
                                *max_y = 180;
                                if (right){
                                        *min_x -= 20;
                                        *max_x -= 20;
                                }
                        }
                        if (!clock)
                                stamina_update (state_x, true, stamina, true);
                        return 1;
                        break;
        }

        return 0;
}

int special_select (int *min_x, int *max_x, int *min_y, int *max_y, int id, int clock, int state_x, float *stamina, bool right){
        switch (id){
                case 1:
                        if (clock < 5)
				return 0;
			*min_x = 70;
                  	*max_x = 135;
                     	*min_y = -15;
                 	*max_y = 5;
			if (right)
				*max_x -= 10;
			return 1;
                        break;
                case 2:
                        if (clock < 10)
				return 0;
			if (clock % 10 < 2){
				*min_x = 10;
	                        *max_x = 75;
        	                *min_y = -80;
                	        *max_y = -20;
			}
			else if (clock % 10 < 4){
				*min_x = 0;
                                *max_x = 30;
                                *min_y = -90;
                                *max_y = -20;
				if (right)
					*max_x += 15;
			}
			else if (clock % 10 < 6)
				return 0;
			else if (clock % 10 < 8){
				*min_x = 0;
                                *max_x = 30;
                                *min_y = -90;
                                *max_y = -20;
                        }
			else{ 
				*min_x = 10;
                                *max_x = 75;
                                *min_y = -85;
                                *max_y = -20;
			}
			return 1;
                        break;
                case 3:
                        return 0;
                        break;
                case 4:
			if (clock < 20)
				return 0;
			else if (clock < 25){
                        	*min_x = 0;
                        	*max_x = 60;
                        	*min_y = 20;
                        	*max_y = 280;
			}
			else{
				*min_x = 100;
                                *max_x = 300;
                                *min_y = -100;
                                *max_y = 70;
			}
			if (clock == 20)
				stamina_update (state_x, true, stamina, false);
			return 1;
                        break;
        }

        return 0;
}

int check_hit_box (int *min_x, int *max_x, int *min_y, int *max_y, int move, int id, int x, int y, int length, int width, int state_y, bool right, int clock, int state_x, float *stamina){
	int minimo_x, maximo_x, minimo_y, maximo_y;
	int store = 0;

	switch(move){
		case KICK:
			if (!state_y)
				store = stand_kick (&minimo_x, &maximo_x, &minimo_y, &maximo_y, id, clock, state_x, stamina, right);	
			else if (state_y == JUMP)
				store = up_kick (&minimo_x, &maximo_x, &minimo_y, &maximo_y, id, clock, state_x, stamina, right);
			else
				store = down_kick (&minimo_x, &maximo_x, &minimo_y, &maximo_y, id, clock, state_x, stamina, right);
			break;
		case PUNCH:
			if (!state_y)
				store = stand_punch (&minimo_x, &maximo_x, &minimo_y, &maximo_y, id, clock, state_x, stamina, right);
			else if (state_y == JUMP)
				store = up_punch (&minimo_x, &maximo_x, &minimo_y, &maximo_y, id, clock, state_x, stamina, right);
			else
				store = down_punch (&minimo_x, &maximo_x, &minimo_y, &maximo_y, id, clock, state_x, stamina, right);
			break;
		case SPECIAL:
			printf ("GANGUE ESTEVE AQUI!\n");
			store = special_select (&minimo_x, &maximo_x, &minimo_y, &maximo_y, id, clock, state_x, stamina, right);
			break;
	}

	if (!store)
		return store;
	//printf ("%d %d %d %d\n", *min_x, *max_x, *min_y, *max_y);
	*min_y = y + minimo_y;
	*max_y = y + maximo_y;

	if (!right){
		*min_x = x + width/2 + minimo_x;
		*max_x = x + width/2 + maximo_x;
	}
	else{
		*min_x = x - width/2 - maximo_x;
		*max_x = x - width/2 - minimo_x;
	}

	return 1;
}

void update_damage (int dam, float *hp, int *stun, bool up, bool down, int min_x, int max_x, int min_y, int max_y, int x, int y, int length, int width, int store, bool *hitted){
	bool hit_up, hit_down;

	if (!store || *hitted)	//se nao estiver no momento de dar hit, retorna
		return;

	hit_up = check_hit (min_x, max_x, min_y, max_y, x, y+(length/4), length/2, width);	//verifica se houve hit na porção superior e/ou inferior da box do player2
	hit_down = check_hit (min_x, max_x, min_y, max_y, x, y-(length/4), length/2, width);

	if (hit_up || hit_down){	//Se houve hit, stunna e tira vida
		*stun += STUN_TIME;
		*hp -= dam;
		*hitted = true;
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

void stamina_update (int state, bool drop, float *stamina, bool air){
        if (state == SPECIAL){	//Se estiver realizando acao, e drop estiver ativo, perde stamina no momento de impacto. Ao longo do golpe, nao recupera stamina!
                if (drop)
                        *stamina -= SPECIAL_STAMINA;
        }
        else if (state == KICK){
                if (drop && air)
                        *stamina -= KICK_STAMINA;
		else if (drop)
			*stamina -= KICK_STAMINA;
        }
        else if (state == PUNCH){
                if (drop && air)
                        *stamina -= PUNCH_STAMINA;
		else if (drop)
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
