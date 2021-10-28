#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void manejadorpadre(int senal){

    printf("Hola holita desde el padre con señal %d \n",senal);

}
void manejadorhijo(int senal){

    printf("Hola holita desde el hijo con señal %d \n",senal);

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
        
        signal(SIGUSR1, manejadorhijo);
        while(1){
            sleep(1);
            kill(pid_padre,SIGUSR1);
            pause();
            break;}
        
        
        break;

    default:
        sleep(1);
        signal(SIGUSR1, manejadorpadre);
        while(1){
            pause();
            sleep(1);
            kill(pid,SIGUSR1);
            break;
        }
        
        break;
    }

}