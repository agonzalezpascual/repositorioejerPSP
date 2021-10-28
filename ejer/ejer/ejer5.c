#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void main(void){

    int desf[2];
    char buffer[30];
    pid_t hijo;

    pipe(desf);
    hijo = fork();
    switch (hijo)
    {
    case -1:
        printf("Ha habido un problema");
        break;
    
    case 0:
        
        close(desf[1]);
        printf("Leyendo desde el hijo\n");
        read(desf[0], buffer, strlen("Hola holita"));
        printf(buffer);
        break; 

    default:
        close(desf[0]);
        printf("Escribiendo desde el padre:\n");
        write(desf[1], "Hola holita", strlen("Hola holita"));
        wait(NULL);
        break;
    }
}