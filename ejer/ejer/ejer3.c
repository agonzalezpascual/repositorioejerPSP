#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>

main(){

int fd, bytesleidos;
char saludo[] = "Hola holita\n";
char buffer[10];

fd = open("texto.txt", 1);

write(fd, saludo, strlen(saludo));
close(fd);

fd = open("texto.txt", 0);

bytesleidos = read(fd,buffer,1);
while (bytesleidos != 0)
{
    printf("%1c",buffer[0]);
    bytesleidos = read(fd,buffer,1);
}
close(fd);

}