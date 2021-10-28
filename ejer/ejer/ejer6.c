#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

main(){

    char frase[]= "Hola padre";
    char buffer[11];
    int fd[2];
    pid_t  hijo;

    pipe(fd);
    hijo = fork();

    switch (hijo)
    {
    case -1:
        printf("Ha habido un problema");
        break;
    
    case 0:
        printf("Escribiendo desde el hijo\n");
        close(fd[0]);
        write(fd[1],frase,strlen(frase));
        break;

    default:
        wait(NULL);
        printf("Leyendo desde el padre: \n" );
        close(fd[1]);
        read(fd[0],buffer,strlen(frase));
        printf(buffer);
        
        break;
    }
}