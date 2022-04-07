#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 1024

int main(int argc, char const *argv[])
{
    int fd = open("comunicador.txt", O_RDWR | O_CREAT, 0644);

    if (fd == -1)
    {
        printf("No pude crear el archivo ni abrirlo\n");
        exit(EXIT_FAILURE);
    }

    char message[MAX] = {'h', 'o', 'l', 'a'};

    write(fd,message,MAX);

    sleep(10);
    
    char message2[MAX] = {'c', 'h', 'a', 'u'};

    write(fd, message2, MAX);

    close(fd);

    return 0;
}
