# Makefile para o jogo STREET_FIGHT Prog2

# Usar pkg-config para obter os flags corretos de compilação e linkagem para o Allegro
#INCLUDE_PATH=/usr/include/allegro5
#LIB_PATH=/usr/lib
FLAGS=$(shell pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_primitives-5 allegro_image-5 allegro_ttf-5 allegro_dialog-5 allegro_keyboard-5 --libs --cflags)
Executavel=Street

all: $(Executavel)

$(Executavel): AggressiveSquares.o begin.o joystick.o
	gcc AggressiveSquares.o begin.o joystick.o -o $(Executavel) $(FLAGS)

AggressiveSquares.o: AggressiveSquares.c
	gcc -c AggressiveSquares.c -I$(INCLUDE_PATH) $(FLAGS)

begin.o: begin.c begin.h
	gcc -c begin.c -I$(INCLUDE_PATH) $(FLAGS)

joystick.o: joystick.c joystick.h
	gcc -c joystick.c -I$(INCLUDE_PATH) $(FLAGS)

clean:
	rm -f *.o *.gch

purge:
	rm -f *.o *.gch $(Executavel)

