#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void manejador1(int senal){

    printf("Hola holita desde el padre con señal %d \n",senal);

}
void manejador2(int senal){

    printf("Qué tal con señal %d \n",senal);

}
void manejador3(int senal){

    printf("Cómo vas con señal %d \n",senal);

}
main(){

    pid_t pid, pid_padre;
    pid_padre = getpid();
    pid = fork();
    switch (pid)
    {
    case -1:
        printf("Ha habido un error \n");
        break;
    
    case 0:
        sleep(1);
        kill(pid_padre,SIGUSR1);
        sleep(1);
        kill(pid_padre,SIGUSR1);
        sleep(1);
        kill(pid_padre,SIGUSR2);
        sleep(1);
        kill(pid_padre,SIGKILL);
        
        break;

    default:
        sleep(1);
        signal(SIGUSR1, manejador1);
        signal(SIGUSR2, manejador2);
        signal(SIGKILL, manejador3);
        while (1){}
        
        break;
    }

}