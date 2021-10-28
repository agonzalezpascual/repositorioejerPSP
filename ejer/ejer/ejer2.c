#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

main(){

    pid_t hijo, padre;
    int num =6;

    hijo = fork();

    if (hijo == -1){

        printf("ha habido un error");
        exit(-1);
    }

    if (hijo == 0){
        num = num-5;
        printf("Variable en proceso hijo: %d \n", num);

    }else{
    
        padre=wait(NULL);
        num = num +5;
        printf("Variable en proceso padre: %d \n", num);

    }
}