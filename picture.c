#include "picture.h"

void printa_walk_right (hero *p, ALLEGRO_BITMAP* image, bool rev){
	int a = 45;
        int b = 82;
	int sw, dx;
	int val;

	switch (p->id){
		case 4:	//LEO
			if (p->control_x->timer < 5){
				dx = p->x - p->width/2 - 45;
	                        sw = p->width + 65;
        	                if (rev){
                	                sw = -sw;
                        	        dx = dx - sw + 30;
                       		 }
				al_draw_scaled_bitmap (image, 0, 215, 66, 104, dx, p->y - p->length/2 - b, sw, p->length + 90, 0);
				printf ("TO NA 1!\n");

			}
			else if (p->control_x->timer < 10){
				dx = p->x - p->width/2 - 45;
        	                sw = p->width + 65;
	                        if (rev){
                        	        sw = -sw;
                	                dx = dx - sw + 25;
                	        }
				al_draw_scaled_bitmap (image, 64, 215, 63, 104, dx, p->y - p->length/2 - b, sw, p->length + 90, 0);
				printf ("TO NA 2!\n");
			}
			else if (p->control_x->timer < 15){
				dx = p->x - p->width/2 - 45;
	                        sw = p->width + 65;
        	                if (rev){
                	                sw = -sw;
                        	        dx = dx - sw + 30;
                       		 }
				al_draw_scaled_bitmap (image, 122, 215, 63, 104, dx, p->y - p->length/2 - b, sw, p->length + 90, 0);
				printf ("TO NA 3!\n");
			}
			
			else if (p->control_x->timer < 20){
				dx = p->x - p->width/2 - 20;
	                        sw = p->width + 65;
        	                if (rev){
                	                sw = -sw;
                        	        dx = dx - sw - 25;
                       	 	}
				al_draw_scaled_bitmap (image, 183, 215, 66, 104, dx, p->y - p->length/2 - b, sw, p->length + 90, 0);
				printf ("TO NA 4!\n");
			}
			else{
				dx = p->x - p->width/2 - 15;
        	                sw = p->width + 65;
	                        if (rev){
                        	        sw = -sw;
                	                dx = dx - sw - 30;
                	        }
				al_draw_scaled_bitmap (image, 245, 217, 66, 104, dx, p->y - p->length/2 - 84, sw, p->length + 90, 0);
				printf ("TO NA 5!\n");
			}

			break;
		case 2:	//DONATELLO
			a = 0;
			b = 52;
			dx = p->x - p->width/2 - 10;                                
			sw = p->width + 30;
                   	if (rev){
                     		sw = -sw;
                   		dx = dx - sw - 10;
                 	}
			if (p->control_x->timer < 5)
                                al_draw_scaled_bitmap (image, 7, 242, 46, 83, dx, p->y - p->length/2 - b, sw, p->length + b, 0);
                        else if (p->control_x->timer < 10)
                                al_draw_scaled_bitmap (image, 56, 242, 46, 83, dx, p->y - p->length/2 - b, sw, p->length + b, 0);
                        else if (p->control_x->timer < 15)
                                al_draw_scaled_bitmap (image, 110, 242, 46, 83, dx, p->y - p->length/2 - b, sw, p->length + b, 0);
			else if (p->control_x->timer < 20)
				al_draw_scaled_bitmap (image, 160, 242, 46, 83, dx, p->y - p->length/2 - b, sw, p->length + b, 0);
			else if (p->control_x->timer < 25)
				al_draw_scaled_bitmap (image, 207, 242, 46, 83, dx, p->y - p->length/2 - b, sw, p->length + b, 0);
			else
				al_draw_scaled_bitmap (image, 261, 242, 46, 83, dx, p->y - p->length/2 - b, sw, p->length + b, 0);
                        break;
		case 3:	//MICHELANGELO
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

		case 1:	//RAFAELO
			dx = p->x - p->width/2 - 10;
                        sw = p->width + 30;
			printf ("O VALOR E: %d\n", p->control_x->timer);
                        if (rev){
                                sw = -sw;
                                dx = dx - sw - 10;
                        }
			if (p->control_x->timer < 5){
                                al_draw_scaled_bitmap (image, 191, 160, 52, 84, dx, p->y - p->length/2 - 20, sw, p->length + 35, 0);
                                printf ("TO NA 1!\n");
                        }
                        else if (p->control_x->timer < 10){
                                al_draw_scaled_bitmap (image, 246, 160, 52, 84, dx, p->y - p->length/2 - 25, sw, p->length + 30, 0);
                                printf ("TO NA 2!\n");
                        }
                        else if (p->control_x->timer < 15){
                                al_draw_scaled_bitmap (image, 302, 160, 52, 84, dx, p->y - p->length/2 - 25, sw, p->length + 30, 0);
                                printf ("TO NA 3!\n");
                        }
                        else if (p->control_x->timer < 20){
                                al_draw_scaled_bitmap (image, 358, 160, 52, 84, dx, p->y - p->length/2 - 25, sw, p->length + 30, 0);

                                printf ("TO NA 4!\n");
                        }
                        else{
                                al_draw_scaled_bitmap (image, 410, 160, 52, 84, dx, p->y - p->length/2 - 30, sw, p->length + 35, 0);
                                printf ("TO NA 5!\n");

                        }

                        break;

	}
	return;
}

void printa_walk_left (hero *p, ALLEGRO_BITMAP* image, bool rev){
	int safe = p->control_x->timer;
	
	printf ("maoe!\n");
	if (p->control_x->timer < 5)
		p->control_x->timer = 23;
	else if (p->control_x->timer < 10)
		p->control_x->timer = 18;
	else if (p->control_x->timer < 15)
		safe = safe * 1;
	else if (p->control_x->timer < 20)
		p->control_x->timer = 7;
	else
		p->control_x->timer = 3;

	printf ("ate aqui blz!\n");
	printa_walk_right (p, image, rev);

	p->control_x->timer = safe;

	return;
}

void printa_down (hero *p, ALLEGRO_BITMAP* image, bool rev){
	int sw, dx;

	switch (p->id){
		case 1:	//RAFA 
			dx = p->x - p->width/2 - 10;
                        sw = p->width + 40;
                        if (rev){
                                sw = -sw;
                                dx = dx - sw - 10;
                        }
			al_draw_scaled_bitmap (image, 255, 250, 52, 84, dx, p->y - p->length/2 - 35, sw, p->length + 60, 0);
			break;
		case 2://DON
		     	dx = p->x - p->width/2 - 10;
                        sw = p->width + 40;
                        if (rev){
                                sw = -sw;
                                dx = dx - sw - 10;
                        }
			al_draw_scaled_bitmap (image, 57, 363, 48, 66, dx, p->y - p->length/2 - 30, sw, p->length + 33, 0);
			break;
		case 3://MIKE
			dx = p->x - p->width/2 - 10;
			sw = p->width + 40;
		     	if (rev){
				sw = -sw;
				dx = dx - sw - 10;
			}
			al_draw_scaled_bitmap (image, 247, 273, 54, 59, dx, p->y - p->length/2 - 5, sw, p->length + 12, 0);
			break;
		case 4:	//leo
			dx = p->x - p->width/2 - 10;
                        sw = p->width + 40;
                        if (rev){
                                sw = -sw;
                                dx = dx - sw - 20;
                        }
                        al_draw_scaled_bitmap (image, 66, 340, 67, 85, dx, p->y - p->length/2 - 45, sw, p->length + 65, 0);
                        break;
	}
	return;
}

void printa_jump (hero *p, ALLEGRO_BITMAP* image, bool rev, int ground){
	int sw, sh, dx, dy;

	switch (p->id){
		case 3:	//MIKE
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
			dx = p->x - p->width/2 - 20;
                        sw = p->width + 30;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (rev){
                                sw = -sw;
                                dx = dx - sw + 10;
                        }
                        if (p->control_y->timer < 10)
                                al_draw_scaled_bitmap (image, 129, 247, 53, 79, dx, dy - 10, sw, sh + 15, 0);
                        else if (!(p->y+p->length/2 >= ground))
                                al_draw_scaled_bitmap (image, 183, 247, 69, 79, dx, dy - 20, sw, sh + 25, 0);
                        else
                                printa_down (p, image, rev);
			break;
		case 4:	//LEO
			dx = p->x - p->width/2 - 20;
                        sw = p->width + 45;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (rev){
                                sw = -sw;
                                dx = dx - sw - 10;
                        }
                        if (p->control_y->timer < 10)
                                al_draw_scaled_bitmap (image, 126, 434, 61, 85, dx, dy - 10, sw, sh + 15, 0);
                        else if (!(p->y+p->length/2 >= ground))
                                al_draw_scaled_bitmap (image, 124, 546, 80, 85, dx, dy - 30, sw, sh + 45, 0);
                       	else
                                printa_down (p, image, rev);
			break;
		case 2: //dona
			dx = p->x - p->width/2 - 60;
                        sw = p->width + 80;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (rev){
                                sw = -sw;
                                dx = dx - sw + 40;
                        }
                        if (p->control_y->timer < 10)
                                al_draw_scaled_bitmap (image, 166, 343, 64, 70, dx, dy - 10, sw, sh + 15, 0);
                        else if (!(p->y+p->length/2 >= ground))
                                al_draw_scaled_bitmap (image, 230, 340, 76, 70, dx, dy - 20, sw, sh + 25, 0);
                        else
                                printa_down (p, image, rev);
                        break;
	}
	return;
}

void printa_up_defense (hero *p, ALLEGRO_BITMAP* image, bool rev){
	int sw, sh, dx, dy;

	switch (p->id){
		case 3:	//mike
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
		case 4: //leo
			dx = p->x - p->width/2 - 33;
                        sw = p->width + 70;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (rev){
                                sw = -sw;
                                dx = dx - sw - 10;
                        }
                        al_draw_scaled_bitmap (image, 0, 862, 80, 97, dx, dy - 40, sw, sh + 55, 0);
                        break;
		case 2: //dona
			dx = p->x - p->width/2 - 30;
                        sw = p->width + 50;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (rev){
                                sw = -sw;
                                dx = dx - sw + 10;
                        }
                        al_draw_scaled_bitmap (image, 0, 434, 68, 77, dx, dy - 10, sw, sh + 25, 0);
                        break;
		case 1:	//rafa
			dx = p->x - p->width/2 - 30;
                        sw = p->width + 70;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (rev){
                                sw = -sw;
                                dx = dx - sw + 10;
                        }
                        al_draw_scaled_bitmap (image, 190, 349, 69, 79, dx, dy - 10, sw, sh + 25, 0);
                        break;
	}
	return;	
}

void printa_down_defense (hero *p, ALLEGRO_BITMAP* image, bool rev){
	int sw, sh, dx, dy;

        switch (p->id){
                case 3:	//mike
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
		case 4:	//leo
			dx = p->x - p->width/2 - 20;
                        sw = p->width + 50;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (!rev){
                                sw = -sw;
                                dx = dx - sw - 10;
                        }
                        al_draw_scaled_bitmap (image, 75, 764, 64, 97, dx, dy - 30, sw, sh + 65, 0);
                        break;
		case 2:	//dona
			dx = p->x - p->width/2 - 50;
                        sw = p->width + 60;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (rev){
                                sw = -sw;
                                dx = dx - sw + 35;
                        }
                        al_draw_scaled_bitmap (image, 71, 431, 65, 77, dx, dy - 40, sw, sh + 65, 0);
                        break;
		case 1:	//rafa
			dx = p->x - p->width/2 - 50;
                        sw = p->width + 100;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (rev){
                                sw = -sw;
                                dx = dx - sw + 5;
                        }
                        al_draw_scaled_bitmap (image, 69, 1320, 69, 85, dx, dy - 50, sw, sh + 65, 0);
        }
        return;
}

void printa_stand_punch (hero *p, ALLEGRO_BITMAP* image, bool rev){
	int dx, sw, dy, sh;

	switch (p->id){
		case 1:	//rafa
			dx = p->x - p->width/2 - 80;
                        sw = p->width + 100;
                        dy = p->y - p->length/2;
                        sh = p->length;
			if (p->control_x->timer < 10 || p->control_x->timer > 20){
				if (rev){
                                	sw = -sw;
                                	dx = dx - sw + 55;
                        	}
                        	al_draw_scaled_bitmap (image, 0, 1415, 85, 72, dx, dy - 10, sw, sh + 20, 0);
			}
			else{
				sw += 50;
				dx += 20;
				if (rev){
                	                sw = -sw;
        	                        dx = dx - sw + 5;
	                        }
				al_draw_scaled_bitmap (image, 85, 1421, 117, 66, dx, dy - 20, sw, sh + 30, 0);
			}
			break;
		case 2:	//dona
			dx = p->x - p->width/2 - 80;
                        sw = p->width + 100;
                        dy = p->y - p->length/2;
                        sh = p->length;
			if (p->control_x->timer < 10 || p->control_x->timer > 20){
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw + 55;
                                }
                                al_draw_scaled_bitmap (image, 135, 433, 73, 67, dx, dy - 30, sw, sh + 40, 0);
                        }
                        else{
                                sw += 50;
                                dx += 70;
                                if (rev){
                                        sw = -sw;
                                       	dx = dx - sw - 120;
                                }
                                al_draw_scaled_bitmap (image, 278, 430, 121, 67, dx, dy - 20, sw, sh + 30, 0);
                        }
                        break;
		case 3:	//mike
			dx = p->x - p->width/2 - 60;
                        sw = p->width + 100;
                        dy = p->y - p->length/2;
                        sh = p->length;
                      	if (p->control_x->timer < 10 || p->control_x->timer > 20){
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw + 20;
                                }
                                al_draw_scaled_bitmap (image, 245, 352, 70, 75, dx, dy - 25, sw, sh + 40, 0);
                        }
                        else{
                                sw -= 10;
                                dx += 70;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 105;
				} 
                                al_draw_scaled_bitmap (image, 407, 349, 107, 73, dx, dy - 45, sw, sh + 50, 0);
                        }
                        break;
		case 4: //leo
			dx = p->x - p->width/2 - 70;
                        sw = p->width + 100;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10 || p->control_x->timer > 20){
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw + 35;
                                }
                                al_draw_scaled_bitmap (image, 267, 976, 88, 77, dx, dy - 20, sw, sh + 40, 0);
                        }
                        else{
                                sw += 20;
                                dx += 70;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 105;
                                }
                                al_draw_scaled_bitmap (image, 363, 976, 143, 77, dx, dy - 45, sw, sh + 70, 0);
                        }
                        break;
	}

	return;
}

void printa_down_punch (hero *p, ALLEGRO_BITMAP* image, bool rev){
	int dx, sw, dy, sh;

        switch (p->id){
                case 1: //rafa
                        dx = p->x - p->width/2 - 10;
                        sw = p->width + 170;
                        dy = p->y - p->length/2;
                        sh = p->length;
                 	if (rev){
                        	sw = -sw;
              			dx = dx - sw - 150;
                 	}
                      	al_draw_scaled_bitmap (image, 344, 547, 97, 71, dx, dy - 25, sw, sh + 45, 0);
                        break;
		case 2:	//dona
			dx = p->x - p->width/2 - 20;
                        sw = p->width + 120;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (rev){
                              	sw = -sw;
                               	dx = dx - sw - 70;
                       	}	
                       	al_draw_scaled_bitmap (image, 261, 590, 69, 70, dx, dy - 35, sw, sh + 40, 0);
                        break;
		case 3:	//mike
			dx = p->x - p->width/2 + 20;
                        sw = p->width + 30;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (rev){
                                sw = -sw;
                                dx = dx - sw - 70;
                        }
                        al_draw_scaled_bitmap (image, 256, 550, 86, 61, dx, dy - 10, sw, sh + 20, 0);
                        break;
		case 4:	//leo
			dx = p->x - p->width/2 + 20;
                        sw = p->width + 80;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (rev){
                                sw = -sw;
                                dx = dx - sw - 90;
                        }
                        al_draw_scaled_bitmap (image, 79, 2364, 92, 77, dx, dy - 10, sw, sh + 50, 0);
                        break;
        }
        return;
}

void printa_up_punch (hero *p, ALLEGRO_BITMAP* image, bool rev){
	int dx, sw, dy, sh;

        switch (p->id){
                case 1: //rafa
                        dx = p->x - p->width/2 - 30;
                        sw = p->width + 100;
                        dy = p->y - p->length/2;
                        sh = p->length;
			if (p->control_x->timer < 10){
				 if (rev){
        	                        sw = -sw;
	                                dx = dx - sw - 50;
                	        }
                        	al_draw_scaled_bitmap (image, 214, 728, 69, 82, dx, dy - 45, sw, sh + 50, 0);
			}
			else{
				dx += 30;
				if (rev){
                         	     	sw = -sw;
                                	dx = dx - sw - 100;
                        	}
				al_draw_scaled_bitmap (image, 357, 732, 77, 82, dx, dy - 20, sw, sh + 30, 0);
			}
         		break;
		case 2:	//dona
			dx = p->x - p->width/2 - 20;
                        sw = p->width + 100;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10){
                                 if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 60;
                                }
                                al_draw_scaled_bitmap (image, 67, 1015, 69, 76, dx, dy - 45, sw, sh + 60, 0);
                        }
                        else{
                                dx += 10;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 80;
                                }
                               	al_draw_scaled_bitmap (image, 209, 1004, 60, 80, dx, dy + 20, sw, sh + 30, 0);
                        }
                        break;
		case 3: //MIKE
			dx = p->x - p->width/2 + 10;
                        sw = p->width;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10){
                                 if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 30;
                                }
                                al_draw_scaled_bitmap (image, 273, 776, 54, 76, dx, dy - 45, sw, sh + 50, 0);
                        }
                        else{
                                dx += 10;
				sw += 20;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 70;
                                }
                                al_draw_scaled_bitmap (image, 405, 784, 68, 75, dx, dy - 10, sw, sh + 70, 0);
                        }
                        break;
		case 4:	//leo
			dx = p->x - p->width/2 + 10;
                        sw = p->width;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10){
                                 if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 30;
                                }
                                al_draw_scaled_bitmap (image, 92, 1188, 71, 92, dx, dy - 45, sw, sh + 80, 0);
                        }
                        else{
                                dx += 10;
                                sw += 20;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 50;
                                }
                                al_draw_scaled_bitmap (image, 271, 1196, 71, 92, dx, dy + 10, sw, sh + 70, 0);
                        }
                        break;
        }
        return;

}

void printa_stand_kick (hero *p, ALLEGRO_BITMAP* image, bool rev){
	int dx, sw, dy, sh;

        switch (p->id){
                case 1: //rafa
                        dx = p->x - p->width/2 - 50;
                        sw = p->width + 70;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10 || p->control_x->timer > 20){
                                 if (rev){
                                        sw = -sw;
                                      	dx = dx - sw + 10;
                                }
                              	al_draw_scaled_bitmap (image, 5, 536, 50, 82, dx, dy - 10, sw, sh + 15, 0);
                        }
                        else{
				sw += 30;
                                dx += 40;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 90;
                                }
                                al_draw_scaled_bitmap (image, 146, 530, 75, 89, dx, dy - 25, sw, sh + 30, 0);
                        }
                        break;
		case 2:	//dona
			dx = p->x - p->width/2 - 50;
                        sw = p->width + 70;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10 || p->control_x->timer > 20){
                                 if (rev){
                                        sw = -sw;
                                        dx = dx - sw + 10;
                                }
                                al_draw_scaled_bitmap (image, 284, 525, 59, 68, dx, dy - 10, sw, sh + 20, 0);
                        }
                        else{
                                sw += 40;
                                dx += 40;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 90;
                                }
                                al_draw_scaled_bitmap (image, 346, 520, 87, 79, dx, dy - 25, sw, sh + 40, 0);
                        }
                        break;
		case 3: //mike
			dx = p->x - p->width/2 - 50;
                        sw = p->width + 70;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10 || p->control_x->timer > 20){
                                 if (rev){
                                        sw = -sw;
                                        dx = dx - sw + 10;
                                }
                                al_draw_scaled_bitmap (image, 82, 473, 55, 72, dx, dy - 10, sw, sh + 20, 0);
                        }
                        else{
                                sw += 40;
                                dx += 40;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 90;
                                }
                                al_draw_scaled_bitmap (image, 139, 461, 92, 82, dx, dy - 25, sw, sh + 40, 0);
                        }
                        break;
		case 4:	//leo
			dx = p->x - p->width/2 - 30;
                        sw = p->width + 50;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10 || p->control_x->timer > 20){
                                 if (rev){
                                        sw = -sw;
                                        dx = dx - sw + 10;
                                }
                                al_draw_scaled_bitmap (image, 4, 1822, 49, 84, dx, dy - 5, sw, sh + 20, 0);
                        }
                        else{
                                sw += 40;
                                dx += 80;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 180;
                                }
                                al_draw_scaled_bitmap (image, 69, 1814, 82, 90, dx, dy - 25, sw, sh + 40, 0);
                        }
                        break;
        }
        return;
}

void printa_down_kick (hero *p, ALLEGRO_BITMAP* image, bool rev){
	int dx, sw, dy, sh;

        switch (p->id){
                case 1: //rafa
                        dx = p->x - p->width/2 - 30;
                        sw = p->width + 70;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10 || p->control_x->timer > 20){
                                 if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 10;
                                }
                                al_draw_scaled_bitmap (image, 130, 649, 54, 71, dx, dy - 10, sw, sh + 20, 0);
                        }
                        else{
                                sw += 30;
                                dx += 15;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 70;
                                }
                                al_draw_scaled_bitmap (image, 184, 659, 84, 64, dx, dy - 10, sw, sh + 30, 0);
                        }
                        break;
		 case 2: //dona
                        dx = p->x - p->width/2 - 120;
                        sw = p->width + 170;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10 || p->control_x->timer > 20){
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw + 50;
                                }
                                al_draw_scaled_bitmap (image, 2, 689, 70, 64, dx, dy - 20, sw, sh + 30, 0);
                        }
                        else{
                                dx += 50;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 20;
                                }
                                al_draw_scaled_bitmap (image, 205, 662, 77, 90, dx, dy - 50, sw, sh + 60, 0);
                        }
                        break;
		case 3: //mike
                        dx = p->x - p->width/2 - 20;
                        sw = p->width + 30;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10 || p->control_x->timer > 20){
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw + 10;
                                }
                                al_draw_scaled_bitmap (image, 354, 629, 50, 69, dx, dy - 20, sw, sh + 30, 0);
                        }
                        else{
                                dx += 60;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 120;
                                }
                                al_draw_scaled_bitmap (image, 411, 637, 84, 61, dx, dy - 20, sw, sh + 30, 0);
                        }
                        break;
		case 4:	//leo
			dx = p->x - p->width/2 - 10;
                        sw = p->width + 30;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10 || p->control_x->timer > 20){
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 10;
                                }
                                al_draw_scaled_bitmap (image, 84, 2454, 51, 80, dx, dy - 20, sw, sh + 45, 0);
                        }
                        else{
                                dx += 60;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 120;
                                }
                                al_draw_scaled_bitmap (image, 159, 2458, 96, 77, dx, dy - 40, sw, sh + 80, 0);
                        }
                        break;
        }
        return;
}

void printa_up_kick (hero *p, ALLEGRO_BITMAP* image, bool rev){
	int dx, sw, dy, sh;

        switch (p->id){
                case 1: //rafa
                        dx = p->x - p->width/2 - 30;
                        sw = p->width + 70;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10){
                                 if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 10;
                                }
                                al_draw_scaled_bitmap (image, 373, 840, 65, 83, dx, dy - 30, sw, sh + 40, 0);
                        }
                        else{
                                sw += 30;
                                dx += 15;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 70;
                                }
                                al_draw_scaled_bitmap (image, 439, 827, 82, 97, dx, dy - 50, sw, sh + 120, 0);
                        }
                        break;
		case 2:	//dona
			dx = p->x - p->width/2 - 30;
                        sw = p->width + 70;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10){
                                 if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 10;
                                }
                                al_draw_scaled_bitmap (image, 155, 916, 70, 88, dx, dy - 40, sw, sh + 50, 0);
                        }
                        else{
                                sw += 30;
                                dx += 15;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 70;
                                }
                                al_draw_scaled_bitmap (image, 228, 925, 96, 76, dx, dy - 30, sw, sh + 50, 0);
                        }
                        break;
		case 3: //mike
			dx = p->x - p->width/2 - 30;
                        sw = p->width + 50;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10){
                                 if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 10;
                                }
                      		al_draw_scaled_bitmap (image, 53, 859, 67, 82, dx, dy - 45, sw, sh + 50, 0);
                        }
                        else{
                                sw += 30;
                                dx += 15;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 70;
                                }
                                al_draw_scaled_bitmap (image, 123, 854, 78, 88, dx, dy - 30, sw, sh + 70, 0);
                        }
                        break;
		case 4:	//leo
			dx = p->x - p->width/2 - 30;
                        sw = p->width + 50;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10){
                                 if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 10;
                                }
                                al_draw_scaled_bitmap (image, 71, 2937, 73, 73, dx, dy - 45, sw, sh + 40, 0);
                        }
                        else{
                                sw += 50;
                                dx += 15;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 70;
                                }
                                al_draw_scaled_bitmap (image, 155, 2937, 118, 84, dx, dy - 10, sw, sh + 70, 0);
                        }
                        break;
        }
        return;
}

void printa_special (hero *p, ALLEGRO_BITMAP *image, bool rev){
	int dx, sw, dy, sh;

	switch (p->id){
		case 1:
			dx = p->x - p->width/2 - 30;
                        sw = p->width + 50;
                        dy = p->y - p->length/2;
                        sh = p->length;
			printf ("aqui tambem!!!!!!\n");
                        if (p->control_x->timer < 5){
                                 if (rev){
                                        sw = -sw;
                                        dx = dx - sw + 10;
                                }
                                al_draw_scaled_bitmap (image, 72, 1322, 58, 85, dx, dy - 20, sw, sh + 40, 0);
                        }
                        else if (p->control_x->timer < 15){
                                sw += 150;
                               	dx -= 30;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 70;
                                }
                                al_draw_scaled_bitmap (image, 344, 1344, 130, 47, dx, dy + 40, sw, sh - 100, 0);
                        }
			else{
				sw += 150;
                                dx -= 30;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 70;
                                }
                                al_draw_scaled_bitmap (image, 210, 1344, 130, 47, dx, dy + 40, sw, sh - 100, 0);
                        }
                        break;
		case 2:
			dx = p->x - p->width/2 + 10;
                        sw = p->width;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10){
                                 if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 10;
                                }
                                al_draw_scaled_bitmap (image, 183, 1165, 42, 67, dx, dy + 10, sw, sh + 10, 0);
                        }
                        else if (p->control_x->timer % 10 < 2){
                                sw += 150;
                                dx -= 80;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 10;
                                }
                                al_draw_scaled_bitmap (image, 9, 1485, 102, 56, dx, dy + 5, sw, sh + 10, 0);
                        }
                        else if (p->control_x->timer % 10 < 4){
                           	sw += 80;
                                dx -= 50;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 20;
                                }
                                al_draw_scaled_bitmap (image, 113, 1488, 70, 51, dx, dy + 5, sw, sh + 10, 0);
                        }
			else if (p->control_x->timer % 10 < 6){
				sw += 10;
                                dx -= 10;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 10;
                                }
                                al_draw_scaled_bitmap (image, 188, 1487, 48, 51, dx, dy, sw, sh + 10, 0);
			}
			else if (p->control_x->timer % 10 < 8){
				sw += 80;
                                dx -= 55;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw + 10;
                                }
                                al_draw_scaled_bitmap (image, 235, 1487, 72, 54, dx, dy + 5, sw, sh + 10, 0);
                        }
			else{
				sw += 150;
                                dx -= 80;
                                if (rev){
                                        sw = -sw;
					dx = dx - sw - 10;
				}
                                al_draw_scaled_bitmap (image, 310, 1491, 100, 51, dx, dy + 5, sw, sh + 10, 0);
                        }
                        break;
		case 3:
			dx = p->x - p->width/2 + 10;
             		sw = p->width;
           		dy = p->y - p->length/2;
             		sh = p->length;
            		if (p->control_x->timer < 5){
          			if (rev){
                        	 	sw = -sw;
                         		dx = dx - sw - 10;
                		}
              			al_draw_scaled_bitmap (image, 2, 1129, 64, 74, dx, dy, sw, sh + 10, 0);
           		}
			else if (p->control_x->timer < 10){
				dx -= 20;
				sw += 30;
				if (rev){
                        	        sw = -sw;
                        	       	dx = dx - sw - 10;
                       		}
                        	al_draw_scaled_bitmap (image, 68, 1139, 82, 62, dx, dy, sw, sh + 10, 0);
                	}
			else if (p->control_x->timer < 15){
				dx += 20;
				if (rev){
                                	sw = -sw;
                                	dx = dx - sw - 50;
                        	}
                        	al_draw_scaled_bitmap (image, 159, 1127, 44, 85, dx, dy, sw, sh + 10, 0);
                	}
			else if (p->control_x->timer < 20){
				if (rev){
                                	sw = -sw;
                                	dx = dx - sw - 20;
                        	}
                        	al_draw_scaled_bitmap (image, 208, 1141, 49, 69, dx, dy + 25, sw, sh - 10, 0);
                	}
			else if (p->control_x->timer < 25){
				dx -= 30;
				sw += 40;
				if (rev){
                                	sw = -sw;
                                	dx = dx - sw;
                        	}
                        	al_draw_scaled_bitmap (image, 258, 1137, 84, 66, dx, dy, sw, sh + 10, 0);
                	}
			else{
				dx += 10;
				if (rev){
                                	sw = -sw;
                                	dx = dx - sw - 40;
                        	}
                        	al_draw_scaled_bitmap (image, 347, 1132, 59, 82, dx, dy - 20, sw, sh + 30, 0);
                	}
			break;
		case 4:
			dx = p->x - p->width/2 + 10;
            		sw = p->width + 30;
         		dy = p->y - p->length/2;
          		sh = p->length;
         		if (p->control_x->timer < 20){
              			if (rev){
                        		sw = -sw;
                           		dx = dx - sw - 50;
                 		}
              			al_draw_scaled_bitmap (image, 226, 2766, 82, 110, dx, dy - 95, sw, sh + 120, 0);
         		}
			else if (p->control_x->timer < 25){
				sw += 40;
				dx += 10;
				if (rev){
                                	sw = -sw;
                                	dx = dx - sw - 110;
                        	}
                        	al_draw_scaled_bitmap (image, 314, 2784, 100, 88, dx, dy - 40, sw, sh + 70, 0);
                	}
			else{
				sw += 250;
				if (rev){
                                	sw = -sw;
                                	dx = dx - sw - 300;
                        	}
                        	al_draw_scaled_bitmap (image, 418, 2782, 208, 88, dx, dy -60, sw, sh + 120, 0);
                	}
			break;
        }
	return;
}

void print_hero (hero *p, bool rev, int ground){
	//stun vem aqui???????????????
	//printf ("O VALOR STATE E : %d %ld\n", p->control_x->state, p->control_x->acumulation);	
	switch (p->control_x->state){
		case SPECIAL:
			printf ("veio aqui!\n");
			printa_special (p, p->image, rev);
			break;
		case PUNCH:
			if (!p->control_y->state)
				printa_stand_punch (p, p->image, rev);
			else if (p->control_y->state == JUMP)
				printa_up_punch (p, p->image, rev);
			else
				printa_down_punch (p, p->image, rev);
			break;
		case KICK:
			if (!p->control_y->state)
                                printa_stand_kick (p, p->image, rev);
                        else if (p->control_y->state == JUMP)
                                printa_up_kick (p, p->image, rev);
                        else
                                printa_down_kick (p, p->image, rev);
                        break;
		case DEFENSE_UP:
			printa_up_defense (p, p->image, rev);
			break;
		case DEFENSE_DOWN:
			printa_down_defense (p, p->image, rev);
			break;
		case WALK_RIGHT:
			if (p->control_y->state == JUMP){
				printa_jump (p, p->image, rev, ground);
				break;
			}
			printa_walk_right (p, p->image, rev);
			break;
		case WALK_LEFT:
			if (p->control_y->state == JUMP){
				printa_jump (p, p->image, rev, ground);
				break;
			}
			printa_walk_left (p, p->image, rev);
			break;
		case 0:
			if (!p->control_y->state)
				printa_special (p, p->image, rev);
			else if (p->control_y->state == JUMP)
				printa_jump (p, p->image, rev, ground);
			else
				printa_down (p, p->image, rev);
			break;
		}
	return;
}		

void character_menu(ALLEGRO_DISPLAY* display, ALLEGRO_BITMAP* maps, ALLEGRO_BITMAP *bits[], int selected_character1, int selected_character2, int selected_map, bool characters_chosen, int max_x, int max_y){

	if (selected_character1 < 0 || selected_character1 > 3)
		return;
	if (selected_character2 < 0 || selected_character2 > 3)
		return;

	ALLEGRO_FONT* font = al_create_builtin_font();
    	// Calcula as dimensões e posições dos quadrados de personagens
  	int square_size = max_x / 5;
    	int margin = (max_x - 4 * square_size) / 5;

    	int x_positions[4];
    	for (int i = 0; i < 4; i++){
        	x_positions[i] = margin + i * (square_size + margin);
    	}
    	int y_position = max_y / 4;

    	// Calcula as dimensões e posições dos retângulos de mapas
    	int rect_width = max_x / 3;
    	int rect_height = max_y / 8;
    	int map_margin = (max_x - 2 * rect_width) / 3;

    	int map_x_positions[2];
    	for (int i = 0; i < 2; i++){
        	map_x_positions[i] = map_margin + i * (rect_width + map_margin);
    	}
    	int map_y_position = max_y * 3 / 4;

    	// Desenha os quadrados dos personagens
    	for (int i = 0; i < 4; i++){
        	al_draw_rectangle(x_positions[i], y_position, x_positions[i] + square_size, y_position + square_size, al_map_rgb(255, 255, 255), 2);
    	}

	al_draw_scaled_bitmap (bits[0], 66, 0, 68, 65, x_positions[0], y_position - 5, square_size + 10, square_size, 0);
	al_draw_scaled_bitmap (bits[1], 86, 0, 58, 52, x_positions[1] + 3, y_position, square_size - 3, square_size - 3, 0);
	al_draw_scaled_bitmap (bits[2], 68, 13, 64, 64, x_positions[2], y_position + 3, square_size - 3, square_size - 5, 0);
	al_draw_scaled_bitmap (bits[3], 495, 202, 62, 67, x_positions[3] + 4, y_position - 20, square_size - 7, square_size + 15, 0);

    	// Desenha os retângulos dos mapas se os personagens foram escolhidos
    	if (characters_chosen){
        	for (int i = 0; i < 2; i++) {
            	al_draw_rectangle(map_x_positions[i], map_y_position, map_x_positions[i] + rect_width, map_y_position + rect_height, al_map_rgb(255, 255, 255), 2);
        	}
		al_draw_scaled_bitmap (maps, 745, 295, 714, 170, map_x_positions[0], map_y_position, rect_width, rect_height, 0);
		al_draw_scaled_bitmap (maps, 338, 55, 714, 155, map_x_positions[1], map_y_position, rect_width, rect_height, 0);

        	// Desenha a flechinha indicando o mapa selecionado
        	int map_arrow_x = map_x_positions[selected_map] + rect_width / 2;
        	int map_arrow_y = map_y_position - 20;
        	al_draw_filled_triangle(map_arrow_x, map_arrow_y, map_arrow_x - 10, map_arrow_y - 20, map_arrow_x + 10, map_arrow_y - 20, al_map_rgb(0, 255, 0));
		al_draw_text(font, al_map_rgb(255, 255, 255), max_x / 2, y_position - 50, ALLEGRO_ALIGN_CENTER, "Choose your map");
    	}
	else
		al_draw_text(font, al_map_rgb(255, 255, 255), max_x / 2, y_position - 50, ALLEGRO_ALIGN_CENTER, "Choose your players");

    	// Desenha a flechinha indicando o primeiro personagem selecionado
    	int arrow_x1 = x_positions[selected_character1] + square_size / 2;
    	int arrow_y1 = y_position - 20;
    	al_draw_filled_triangle(arrow_x1, arrow_y1, arrow_x1 - 10, arrow_y1 - 20, arrow_x1 + 10, arrow_y1 - 20, al_map_rgb(255, 0, 0));

    	// Desenha a flechinha indicando o segundo personagem selecionado
    	int arrow_x2 = x_positions[selected_character2] + square_size / 2;
    	int arrow_y2 = y_position - 20;
    	al_draw_filled_triangle(arrow_x2, arrow_y2, arrow_x2 - 10, arrow_y2 - 20, arrow_x2 + 10, arrow_y2 - 20, al_map_rgb(0, 0, 255));

    	// Destroi a fonte criada para evitar vazamento de memória
    	al_destroy_font(font);
}

void bars(ALLEGRO_DISPLAY *display, int max_x, int max_y, hero *p1, hero *p2) {
    	float bar_width = 350;   // largura da barra
    	float bar_height = 25;   // altura da barra
    	float padding = 7;      // espaço entre as barras e a borda da tela
		int square_side = 30;	//tamanho do quadrado de rounds
    // Molde esquerda superior
    	al_draw_filled_rectangle(padding, padding, (3*padding) + bar_width, (3*padding) + bar_height, al_map_rgb(0, 0, 0));
    // Barra de vida esquerda superior
    	al_draw_filled_rectangle(2 * padding, 2 * padding, ((2*padding) + bar_width), (2*padding) + bar_height, al_map_rgba_f(0.5, 0.5, 0.5, 0.5));
	al_draw_filled_rectangle(2 * padding, 2 * padding, (2*padding) + (bar_width * (p1->hp/100)), (2*padding) + bar_height, al_map_rgb(255, 0, 0));

    // Molde direita superior
    	al_draw_filled_rectangle(max_x - (3*padding) - bar_width, padding, max_x - padding, (3*padding) + bar_height, al_map_rgb(0, 0, 0));
    // Barra de vida direita superior
    	al_draw_filled_rectangle (max_x - (2*padding) - bar_width, 2*padding, (max_x - (2*padding)), (2*padding) + bar_height, al_map_rgba_f(0.5, 0.5, 0.5, 0.5));
    	al_draw_filled_rectangle (max_x - (2*padding) - (bar_width * (p2->hp/100)), 2*padding, (max_x - (2*padding)), (2*padding) + bar_height, al_map_rgb(255, 0, 0));

    // Molde esquerda superior (stamina)
    	al_draw_filled_rectangle(padding, (4*padding) + bar_height, (3*padding) + bar_width, (6*padding) + (bar_height*2), al_map_rgb(0, 0, 0));
    // Barra de stamina esquerda superior
    	al_draw_filled_rectangle(2*padding, (5*padding) + bar_height, ((2*padding) + bar_width), (5*padding) + (2*bar_height), al_map_rgba_f(0.5,0.5,0.5,0.5));
    	al_draw_filled_rectangle(2*padding, (5*padding) + bar_height, ((2*padding) + (bar_width * (p1->stamina/100))), (5*padding) + (2*bar_height), al_map_rgb(0, 0, 255));

    // Molde direita superior (stamina)
    	al_draw_filled_rectangle(max_x - (3*padding) - bar_width, (4*padding) + bar_height, max_x - padding, (6*padding) + (bar_height * 2), al_map_rgb(0, 0, 0));
    // Barra de stamina direita superior
    	al_draw_filled_rectangle(max_x - (2*padding) - bar_width, (5*padding) + bar_height, (max_x - 2*padding), (5*padding) + (2*bar_height), al_map_rgba_f(0.5,0.5,0.5,0.5));
    	al_draw_filled_rectangle(max_x - (2*padding) - (bar_width * (p2->stamina/100)), (5*padding) + bar_height, (max_x - 2*padding), (5*padding) + (2*bar_height), al_map_rgb(0,0,255));

	int min_y = 7*padding + 2*bar_height;
	int square_x = square_side + 2*padding;

	//1 molde
	al_draw_filled_rectangle (padding, min_y, 3*padding + square_side, min_y + 2*padding + square_side, al_map_rgb(0,0,0));
	al_draw_filled_rectangle (2*padding, min_y + padding, 2*padding + square_side, min_y + padding + square_side, al_map_rgb(0,255,0));

	al_draw_filled_rectangle (square_x + 2*padding, min_y, square_x + 4*padding + square_side, min_y + 2*padding + square_side, al_map_rgb(0,0,0));
        al_draw_filled_rectangle (square_x + 3*padding, min_y + padding, square_x + 3*padding + square_side, min_y + padding + square_side, al_map_rgb(0,255,0));

	//rounds hero 2
	al_draw_filled_rectangle (max_x - square_x - padding, min_y, max_x - padding, min_y + 2*padding + square_side, al_map_rgb(0,0,0));
	al_draw_filled_rectangle (max_x - square_x, min_y + padding, max_x - 2*padding, min_y + padding + square_side, al_map_rgb(0,255,0));

	al_draw_filled_rectangle (max_x - (2*square_x) - (2*padding), min_y, max_x - (2*padding) - square_x, min_y + 2*padding + square_side, al_map_rgb(0,0,0));
        al_draw_filled_rectangle (max_x - (2*square_x) - padding, min_y + padding, max_x - 3*padding - square_x, min_y + padding + square_side, al_map_rgb(0,255,0));
	
	printf ("AS STAMINAS SAO %f, %f!\n", p1->stamina, p2->stamina);
}
/*
void menu (ALLEGRO_BITMAP *intro, int selected_option, int max_x, int max_y){
	al_draw_scaled_bitmap ();

	int padding = 20; // Espaço entre as opções
	
    	int text_height = al_get_font_line_height(font);

    	// Coordenadas y para as opções
    	int y1 = display_height - 3 * (text_height + padding);
    	int y2 = display_height - 2 * (text_height + padding);
    	int y3 = display_height - 1 * (text_height + padding);

    	// Opção "1 Player"
    	al_draw_text(font, al_map_rgb(255, 255, 255), max_x / 2, y1, ALLEGRO_ALIGN_CENTER, "1 Player");

    	// Opção "2 Players"
    	al_draw_text(font, al_map_rgb(255, 255, 255), max_x / 2, y2, ALLEGRO_ALIGN_CENTER, "2 Players");

    	// Opção "Quit"
    	al_draw_text(font, al_map_rgb(255, 255, 255), max_x / 2, y3, ALLEGRO_ALIGN_CENTER, "Quit");

	if (selected_option == 1){
		arrow_x = x_position + square_size / 2;
        	arrow_y = y_position - 20;
	}
	else if (selected_option == 2){
	}
	else{
	}

        al_draw_filled_triangle(arrow_x1, arrow_y1, arrow_x1 - 10, arrow_y1 - 20, arrow_x1 + 10, arrow_y1 - 20, al_map_rgb(255, 0, 0));

	return;
}
	
void pause (hero *p1, hero *p2, ALLEGRO_DISPLAY *disp, int max_x, int max_y){	//da pra fazer???
	while (1){		//PRINTAR NA TELA NESSA FUNCAO???

		PRINTAR UMA TELA PRETA TRANSPARENTE AQUI!

		al_draw_text(font, al_map_rgb(255, 255, 255), max_x / 2, max_y / 2, ALLEGRO_ALIGN_CENTER, "PAUSED");
		al_draw_text(font, al_map_rgb(255, 255, 255), max_x / 2, (max_y / 2) + 50, ALLEGRO_ALIGN_CENTER, "Press ENTER to continue!");
}
void end (){
	if (p1->hp == 0)
		score2++;
	if (p2->hp == 0)
		score1++;

	if (score1 > score2){ !!!!!!!!!!!
		if (score == 2)
			print draw;
		else
			print player_1 wins
		SE PRESSIONAR ENTER VOLTA PRO MENU PRINCIPAL!
	}
	else if (score2 == 2){
	}
	else{	logica pra restartar!
		choose_hero ();
		choose_hero ();
		p1->control_x->state = 0;
		p1->control_y->state = 0;
	}

	return;
}
*/
