#include "damage.h"

int check_hit (int min_x, int max_x, int min_y, int max_y, int x, int y, int lenght, int width){
	float sq_left = x - (width/2);
	float sq_right = x + (width/2);
	float sq_top = y - (height/2);
	float sq_bottom = y + (height/2);

	return !(max_x < sq_left || min_x > sq_right || max_y < sq_top || min_y > sq_bottom);
}

void update_damage (int dam, int *hp, int *stun, bool up, bool down, int min_x, int max_x, int min_y, int max_y, int x, int y, int lenght, int width){
	bool hit_up, hit_down;

	hit_up = check_hit (min_x, max_x, min_y, max_y, x, );
	hit_down = check_hit (min_x, max_x, min_y, max_y, x, );

	if (hit_up || hit_down){
		*stun += STUN_TIME;
		*hp -= dam;
	}

	if (hit_up && up)
		*hp += dam * 0.8;
	else if (hit_down && down)
		hp* += dam *0.8;
	
	if (*hp < 0)
		*hp = 0;

	return;
}

void stamina_update (int state, bool drop){      //PASSAR ESSA FUNCAO PARA O DAMAGE.C!!!!!!!!!!!
        if (!(state % SPECIAL)){
                if (drop)
                        p1->stamina -= SPECIAL_STAMINA;
        }
        else if (!(state % KICK)){
                if (drop)
                        p1->stamina -= KICK_STAMINA;
        }
        else if (!(state % PUNCH)){
                if (drop)
                        p1->stamina -= PUNCH_STAMINA;
        }
        else if (!(state % DEFENSE_UP)){
                p1->stamina -= DEFENSE_UP_STAMINA;
        }
        else if (!(state % DEFENSE_DOWN)){
                p1->stamina -= DEFENSE_DOWN_STAMINA;
        }
        else
                stamina += STAMINA_RECOVERY;
	
	if (stamina > 100)
		stamina = 100;
	else if (stamina < 0)
		stamina = 0;

        return;
}

/*	
void update_damage (hero *p1, hero *p2, int type){
        int a, b, c, d, e;

        if (type == 3){
		if (p1->id == 1){
			VERIFICAR SE P2 ESTA NO CHAO!
		}
		else if (p1->id == 2){
			DAR DANO EM AREA!
		}
		else if (p1->id == 3){
			TELEPORTA PRA TRAS
		}
		else{
			raduken!
		}
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
                        if (abs(p2->x - p1->x) <= c)    //se p2 estiver abaixo da reta de 45° do chute
                              p2->hp -= p1->moves->damage[1];
                }
 else if ();

        if (p2 esta no alcance do tiro de p1){
        }

        return;

}
*/
