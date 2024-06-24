#include <stdlib.h>
#include <stdio.h>

int main (void){
    FILE *mouse = fopen ("/dev/input/mouse0", "rb");
    char b;

    if (!mouse)
        return 1;

    while (1){
        b = fgetc (mouse);
        printf ("%d\n", b);
    }
    
    fclose(mouse); 
}




