#makefile trab STREET_FIGHT Prog2

FLAGS= $(pkg-config allegro-5 allegro_main-5 allegro_font-5 allegro_primitives-5 allegro_image-5 --libs --cflags) 
Executavel=Street

all: $(Executavel)

$(Executavel): AggressiveSquares.o begin.o
	gcc AggressiveSquares.o begin.o -o $(Executavel) $(FLAGS)

AggressiveSquares.o: AggressiveSquares.c
	gcc -c AggressiveSquares.c $(FLAGS)

begin.o: begin.c begin.h
	gcc -c begin.c $(FLAGS)

joystick.o: joystick.c joystick.h
	gcc -c joystick.o $(FLAGS)

#damage.o: damage.c damage.h
#	gcc -c damage.o $(FLAGS)

clean:
	rm -f *.o *.gch

purge:
	rm -f *.o *.gch $(Executavel)
