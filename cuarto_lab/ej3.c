#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 1024

int main(int argc, char const *argv[])
{
    int fd = open("ceros.txt", O_WRONLY | O_CREAT | 0644);

    if (fd == -1)
    {
        printf("No encuentro %s \n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char buff[MAX];

    char one = 1;

    wait(100);

    printf("Voy a escribir 1 en el archivo\n");

    write(fd, one, 1);

    close(fd);

    return 0;
}
