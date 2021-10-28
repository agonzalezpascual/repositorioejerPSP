#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(){

int fp, bytesleidos;
char buffer[5];
fp = open("FIFO2", 0);
printf("Leyendo\n");
bytesleidos =read(fp,buffer,1);
while (bytesleidos !=0)
{   
    printf(buffer[0]);
    bytesleidos =read(fp,buffer,1);
}
close(fp);

}