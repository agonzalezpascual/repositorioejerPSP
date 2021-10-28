#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void manejador(int senal){

    printf("Hola holita desde %d \n",senal);

}

main(){

    pid_t pid;

    pid = fork();
    switch (pid)
    {
    case -1:
        printf("Ha habido un error \n");
        break;
    
    case 0:
        
        signal(SIGUSR1, manejador);
        while(1){}
        break;

    default:
        sleep(1);
        kill(pid,SIGUSR1);
        sleep(1);
        kill(pid,SIGUSR1);
        sleep(1);
        
        break;
    }

}