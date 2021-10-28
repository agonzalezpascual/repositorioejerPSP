#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

main(){

    pid_t hijo;
    int fd[2],fd1[2],bytesleidos,bytesleidos2;
    char buffer[80];

    pipe(fd);
    pipe(fd1);

    hijo = fork();

    if(hijo==0){
        //Lee Hijo
        close(fd1[1]);
        read(fd1[0], buffer,sizeof(buffer));
        printf("%s",buffer);
        printf("\n");
        //Escribe Hijo
        close(fd[0]);
        write(fd[1],"Hola Padre",11);

    }else{
        //Escribe padre
        close(fd1[0]);
        write(fd1[1],"Hola Hijo",10);
        //Lee padre
        wait(NULL);
        close(fd[1]);
        read(fd[0], buffer,sizeof(buffer));
        printf("%s",buffer);
        printf("\n");

    }

}