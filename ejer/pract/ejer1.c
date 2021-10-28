#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

main(){

    pid_t hijo, padre,nieto;

    hijo = fork();

    if (hijo == -1){

        printf("ha habido un error");
        exit(-1);
    }

    if (hijo == 0){
        nieto = fork();
        if(nieto==0){
            printf("Soy el proceso nieto, mi pid es %d , y el de mi padre %d \n", getpid(), getppid());
        }else{
            hijo=wait(NULL);
            printf("Soy el proceso hijo, mi pid es %d , y el de mi padre %d \n", getpid(), getppid());
        }
    }else{
        padre=wait(NULL);
        printf("Soy el proceso padre, mi pid es %d, mi hijo %d terminó", getpid(), hijo);
    }
}