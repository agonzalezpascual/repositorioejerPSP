#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

main(){

    pid_t hijo, hijo2,hijo3,espera1,espera2,espera3;

    hijo = fork();
    
    

    if (hijo == -1){

        printf("ha habido un error");
        exit(-1);
    }

    if (hijo == 0){
        
        printf("Soy el proceso hijo1, mi pid es %d , y el de mi padre %d \n", getpid(), getppid());
    
    }else{
        espera1 = wait(NULL);
        hijo2 = fork();
        
        if(hijo2==0){

            printf("Soy el proceso hijo2, mi pid es %d , y el de mi padre %d \n", getpid(), getppid());

        }else{
            espera2 = wait(NULL);
            hijo3 = fork();
            if(hijo3==0){
                printf("Soy el proceso hijo3, mi pid es %d , y el de mi padre %d \n", getpid(), getppid());
            }else{
            espera3 = wait(NULL);
            printf("Soy el proceso padre, mi pid es %d, mi hijo %d terminó", getpid(), hijo);
            }
        }
    }

}
