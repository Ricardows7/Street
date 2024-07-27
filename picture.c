#include "picture.h"

void printa_stand (hero *p, ALLEGRO_BITMAP* image, bool rev){
	int a = 45;
        int b = 82;
	int sw, dx;
	//printf ("O VALOR DE ID E: %d\n", p->id);
	switch (p->id){
		case 10:	//LEO
			if (p->control_x->timer < 5){
				al_draw_scaled_bitmap (image, 0, 215, 66, 104, p->x - p->width/2 - 45, p->y - p->length/2 - b, p->width + 68, p->length + 90, 0);
				printf ("TO NA 1!\n");

			}
			else if (p->control_x->timer < 10){
				al_draw_scaled_bitmap (image, 66, 215, 63, 104, p->x - p->width/2 - 25, p->y - p->length/2 - b, p->width + 65, p->length + 90, 0);
				printf ("TO NA 2!\n");
			}
			else if (p->control_x->timer < 15){
				al_draw_scaled_bitmap (image, 122, 215, 63, 104, p->x - p->width/2 - 35, p->y - p->length/2 - b, p->width + 65, p->length + 90, 0);
				printf ("TO NA 3!\n");
			}
			
			else if (p->control_x->timer < 20){
				al_draw_scaled_bitmap (image, 183, 215, 66, 104, p->x - p->width/2 - 23, p->y - p->length/2 - b, p->width + 68, p->length + 90, 0);
				printf ("TO NA 4!\n");
			}
			else{
				al_draw_scaled_bitmap (image, 245, 217, 66, 104, p->x - p->width/2 - 20, p->y - p->length/2 - 84, p->width + 68, p->length + 90, 0);
				printf ("TO NA 5!\n");
			}

			break;
		case 9:	//DONATELLO
			a = 0;
			b = 52;
			if (p->control_x->timer < 5){
                                al_draw_scaled_bitmap (image, 7, 242, 46, 83, p->x - p->width/2 - a, p->y - p->length/2 - b, p->width + 20, p->length + b, 0);
                                printf ("TO NA 1!\n");
                        }
                        else if (p->control_x->timer < 10){
                                al_draw_scaled_bitmap (image, 56, 242, 46, 83, p->x - p->width/2 - a, p->y - p->length/2 - b, p->width + 20, p->length + b, 0);
                                printf ("TO NA 2!\n");
                        }
                        else if (p->control_x->timer < 15){
                                al_draw_scaled_bitmap (image, 110, 242, 46, 83, p->x - p->width/2 - a, p->y - p->length/2 - b, p->width + 20, p->length + b, 0);
                                printf ("TO NA 3!\n");
                        }
			else if (p->control_x->timer < 20)
				al_draw_scaled_bitmap (image, 160, 242, 46, 83, p->x - p->width/2 - a, p->y - p->length/2 - b, p->width + 20, p->length + b, 0);
			else if (p->control_x->timer < 25)
				al_draw_scaled_bitmap (image, 207, 242, 46, 83, p->x - p->width/2 - a, p->y - p->length/2 - b, p->width + 20, p->length + b, 0);
			else
				al_draw_scaled_bitmap (image, 261, 242, 46, 83, p->x - p->width/2 - a, p->y - p->length/2 - b, p->width + 20, p->length + b, 0);

                        break;
		case 1:	//MICHELANGELO
			dx = p->x - p->width/2 - 10;
			sw = p->width + 30;
			if (rev){
				sw = -sw;
				dx = dx - sw - 10;
			}
                        if (p->control_x->timer < 5){
                                al_draw_scaled_bitmap (image, 179, 166, 56, 81, dx, p->y - p->length/2 - 12, sw, p->length + 22, 0);
                                printf ("TO NA 1!\n");
                        }
                        else if (p->control_x->timer < 10){
                                al_draw_scaled_bitmap (image, 237, 166, 56, 81, dx, p->y - p->length/2 - 12, sw, p->length + 22, 0);
                                printf ("TO NA 2!\n");
                        }
                        else if (p->control_x->timer < 15){
                                al_draw_scaled_bitmap (image, 296, 166, 56, 81, dx, p->y - p->length/2 - 12, sw, p->length + 22, 0);
                                printf ("TO NA 3!\n");
                        }
                        else if (p->control_x->timer < 20)
                                al_draw_scaled_bitmap (image, 353, 166, 56, 81, dx, p->y - p->length/2 - 12, sw, p->length + 22, 0);
                        else
                                al_draw_scaled_bitmap (image, 407, 166, 56, 81, dx, p->y - p->length/2 - 15, sw, p->length + 22, 0);

                        break;

		case 7:	//RAFAELO
			if (p->control_x->timer < 5){
                                al_draw_scaled_bitmap (image, 191, 160, 52, 84, p->x - p->width/2, p->y - p->length/2 - 20, p->width + 20, p->length + 35, 0);
                                printf ("TO NA 1!\n");
                        }
                        else if (p->control_x->timer < 10){
                                al_draw_scaled_bitmap (image, 246, 160, 52, 84, p->x - p->width/2, p->y - p->length/2 - 25, p->width + 20, p->length + 30, 0);
                                printf ("TO NA 2!\n");
                        }
                        else if (p->control_x->timer < 15){
                                al_draw_scaled_bitmap (image, 302, 160, 52, 84, p->x - p->width/2, p->y - p->length/2 - 25, p->width + 20, p->length + 30, 0);
                                printf ("TO NA 3!\n");
                        }
                        else if (p->control_x->timer < 20){
                                al_draw_scaled_bitmap (image, 358, 160, 52, 84, p->x - p->width/2, p->y - p->length/2 - 25, p->width + 20, p->length + 30, 0);

                                printf ("TO NA 4!\n");
                        }
                        else{
                                al_draw_scaled_bitmap (image, 410, 160, 52, 84, p->x - p->width/2, p->y - p->length/2 - 30, p->width + 20, p->length + 35, 0);
                                printf ("TO NA 5!\n");

                        }

                        break;

	}
	return;
}

void printa_down (hero *p, ALLEGRO_BITMAP* image, bool rev){
	int sw, dx;

	switch (p->id){
		case 5:	//RAFA 
			al_draw_scaled_bitmap (image, 255, 250, 52, 84, p->x - p->width/2, p->y - p->length/2 - 30, p->width + 40, p->length + 50, 0);
			break;
		case 6://DON
			al_draw_scaled_bitmap (image, 57, 363, 48, 66, p->x - p->width/2, p->y - p->length/2 - 30, p->width + 40, p->length + 33, 0);
			break;
		case 1://MIKE
			dx = p->x - p->width/2 - 10;
			sw = p->width + 40;
		     	if (rev){
				sw = -sw;
				dx = dx - sw - 10;
			}
			al_draw_scaled_bitmap (image, 247, 273, 54, 59, dx, p->y - p->length/2 - 5, sw, p->length + 12, 0);
			break;
	}
	return;
}

void printa_jump (hero *p, ALLEGRO_BITMAP* image, bool rev, int ground){
	int sw, sh, dx, dy;

	switch (p->id){
		case 10:	//MIKE
			dx = p->x - p->width/2 - 10;
			sw = p->width + 10;
			dy = p->y - p->length/2;
			sh = p->length;
			if (rev){
				sw = -sw;
				dx = dx - sw + 10;
			}
			if (p->control_y->timer < 10)
				al_draw_scaled_bitmap (image, 63, 261, 55, 75, dx, dy - 10, sw, sh + 15, 0);
			else if (!(p->y+p->length/2 >= ground))
				al_draw_scaled_bitmap (image, 117, 261, 67, 75, dx, dy, sw, sh + 15, 0);
			else 
				printa_down (p, image, rev);
			break;
		case 1:		//RAFAELO
			dx = p->x - p->width/2 - 10;
                        sw = p->width + 10;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (rev){
                                sw = -sw;
                                dx = dx - sw + 10;
                        }
                        if (p->control_y->timer < 10)
                                al_draw_scaled_bitmap (image, 63, 261, 55, 75, dx, dy - 10, sw, sh + 15, 0);
                        else if (!(p->y+p->length/2 >= ground))
                                al_draw_scaled_bitmap (image, 117, 261, 67, 75, dx, dy, sw, sh + 15, 0);
                        else
                                printa_down (p, image, rev);

	}
	return;
}

void printa_up_defense (hero *p, ALLEGRO_BITMAP* image, bool rev){
	int sw, sh, dx, dy;

	switch (p->id){
		case 1:
			dx = p->x - p->width/2 - 5;
                        sw = p->width + 20;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (rev){
                                sw = -sw;
                                dx = dx - sw - 10;
             		}
			al_draw_scaled_bitmap (image, 4, 1048, 62, 76, dx, dy - 10, sw, sh + 15, 0);
			break;
	}
	return;	
}

void printa_down_defense (hero *p, ALLEGRO_BITMAP* image, bool rev){
	int sw, sh, dx, dy;

        switch (p->id){
                case 1:
                        dx = p->x - p->width/2 - 20;
                        sw = p->width + 20;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (!rev){
                                sw = -sw;
                                dx = dx - sw + 20;
                        }
                        al_draw_scaled_bitmap (image, 211, 90, 48, 75, dx, dy - 10, sw, sh + 15, 0);
                        break;
        }
        return;
}

/*

	switch (p->control_x->state){
		case SPECIAL:
			//printa special;
			break;
		case PUNCH:
			if (!p->control_y->state){
				if (p->control_x->timer < 10)

				else if (p->control_x->timer < 20)

				else
			}
			else if (p->control_y->state == JUMP){
			}
			else{
			}
			break;
		case KICK:
			break;
		case DEFENSE_UP:
			break;
		case DEFENSE_DOWN;
			break;
		case WALK_RIGHT:
			break;
		case WALK_LEFT:
			break;
		default:
			break;
	}

	return;
}

void printa_heroi (heroi *p){
	switch (p->id){
		case 1: 
			
printa_hero_1 (p);
			break;
		case 2: 
			printa_hero_2 (p);
			break;
		case 3:
			printa_hero_3 (p);
			break;
		case 4:
			printa_hero_4 (p);
			break;
	}

	return;
}
*/			
