#include "damage.h"

actions* create_action(){

	actions *move_set = (actions*) malloc (sizeof(actions));
	if (!move_set){
		printf ("Erro durante alocacao de vetor de movimentos!\n");
		return NULL;
	}

	move_set->timers[0] = 0;
	move_set->timers[1] = 0;
	move_set->range[0] = 0;
	move_set->range[1] = 0;

	return move_set;
}

bullet* create_bullet (int x, int y, int dam, int vel, bool track){
	bullet *aux = (bullet*) malloc (sizeof (bullet));
	if (!aux){
		printf ("Erro na alocação do projétil!\n");
		return NULL;
	}

	aux->x = x;
	aux->y = y;
	aux->trajectory = track;
	aux->damage = dam;
	aux->velocity = vel;

	return aux;
}

special* create_special(){
	special *aux = (special*) malloc (sizeof(special));
	if (!aux){
		printf ("Erro na alocação do especial!\n");
		return;
	}
	aux->projectile = NULL;
	if (id == 1){
		aux->timer = 10;
		aux->damage = 10;
	}
	else if (id == 2){
		aux->timer = 10;
		aux->damage = 10;
	}
	else if (id == 3){
		aux->timer = 10;
		aux->damage = 10;
	}
	else{
		aux->timer = 10;
		aux->damage = 10;
	}

	return aux;
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
