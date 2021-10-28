#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <errno.h>



main(){

    pid_t padre, hijo, nieto, espera1, espera2, espera3;
    int fd1[2];
    int fd2[2];
    char buffer[80];

    pipe(fd1);
    pipe(fd2);

    hijo = fork();

    if(hijo==0){

        nieto = fork();
        if (nieto==0)
        {
            //Nieto recibe del hijo
            close(fd2[1]);
            read(fd2[0], buffer, 25);
            printf("%s",buffer);
            printf("\n");

            //NIeto envía al hijo
            printf("soy el nieto y le estoy mandando un mensaje a mi padre\n");
            close(fd1[0]);
            write(fd1[1], "Hola papa desde el nieto", 25);
            printf("soy el nieto y estoy recibiendo un mensaje a mi padre\n");

            

            
        }else{
            //HIjo recibe del padre
            printf("Soy el hijo y estoy recibiendo un mensaje del padre\n");
            close(fd1[1]);
            read(fd1[0], buffer, 25);
            printf("%s",buffer);
            printf("\n");
            //Hijo envía a nieto
            printf("Soy el hijo y estoy enviando un mensaje al nieto\n");
            close(fd2[0]);
            write(fd2[1], "Hola nieto desde el hijo", 25);
            espera1 = wait(NULL);
            

            //Hijo recibe de  nieto
            printf("Soy el hijo y estoy recibiendo un mensaje del nieto\n");
            close(fd1[1]);
            read(fd1[0], buffer, 25);
            printf("%s",buffer);
            printf("\n");
            //Hijo envía al padre
            printf("Soy el hijo y estoy enviando un mensaje al padre\n");
            close(fd2[0]);
            write(fd2[1], "Hola padre desde el hijo", 25);
            
        }
        

    }else{
        //Abuelo envía al hijo
        printf("Soy el padre y estoy enviando un mensaje al hijo\n");
        close(fd1[0]);
        write(fd1[1], "Hola hijo desde el padre", 25);
        espera2=wait(NULL);

        //Abuelo recibe del hijo
        printf("Soy el padre y estoy recibiendo un mensaje del hijo\n");
        close(fd2[1]);
        read(fd2[0], buffer, 25);
        printf("%s",buffer);
        printf("\n");
            
    }

}