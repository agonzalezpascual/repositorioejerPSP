#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){

int fp;
char saludo[] = "Hola";
fp = open("FIFO2", 1);

printf("Escribiendo\n");
write(fp,saludo,strlen(saludo));
close(fp);

}