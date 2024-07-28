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
                                        dx = dx - sw - 60;
                                }
                                al_draw_scaled_bitmap (image, 273, 776, 54, 76, dx, dy - 45, sw, sh + 50, 0);
                        }
                        else{
                                dx += 10;
				sw += 20;
                                if (rev){
                                        sw = -sw;
                                        dx = dx - sw - 100;
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
                        if (p->control_x->timer < -1 || p->control_x->timer > 200){
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
                        if (p->control_x->timer < 10){
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
                        if (p->control_x->timer < 10){
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
                                        dx = dx - sw - 20;
                                }
                                al_draw_scaled_bitmap (image, 411, 637, 84, 61, dx, dy - 20, sw, sh + 30, 0);
                        }
                        break;
		case 4:	//leo
			dx = p->x - p->width/2 - 10;
                        sw = p->width + 30;
                        dy = p->y - p->length/2;
                        sh = p->length;
                        if (p->control_x->timer < 10){
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

void print_hero (hero *p, bool rev, int ground){
	//stun vem aqui???????????????
	printf ("O VALOR STATE E : %d %ld\n", p->control_x->state, p->control_x->acumulation);	
	switch (p->control_x->state){
		case SPECIAL:
			//A FAZER!!!
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
				//printa_stand A FAZER!!!!!
				break;
			else if (p->control_y->state == JUMP)
				printa_jump (p, p->image, rev, ground);
			else
				printa_down (p, p->image, rev);
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
