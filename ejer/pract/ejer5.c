#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <signal.h>

void manejahijo(){
    int pid = getpid();
    printf("Señal mandada desde el padre al hijo con pid: %d\n",pid);

}

void manejapadre(){
    int pid = getpid();
    printf("Señal mandada desde el hijo al padre con pid: %d\n",pid);
}

main(){


    pid_t hijo;
    int pidpadre, pidhijo;

    pidpadre = getpid();
    hijo=fork();

    if(hijo==0){
        signal(SIGUSR1,manejapadre);
        while(1){kill(pidpadre,SIGUSR1);
        pause();}
    }else{
        signal(SIGUSR1,manejahijo);
        while(1){
            sleep(1);
            kill(pidhijo,SIGUSR1);
        }
    }
}