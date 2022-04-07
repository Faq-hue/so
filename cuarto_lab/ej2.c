#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 1024

int main(int argc, char const *argv[])
{
    int fd = open("ceros.txt", O_RDONLY);

    if (fd == -1)
    {
        printf("No encuentro %s \n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char buff[MAX];

    while (1)
    {
        int n = read(fd, buff, MAX);

        for (int i = 0; i < n; i++)
        {

            if (buff[i] == '1')
            {
                printf("Encontre un 1, voy a salir\n");
                exit(EXIT_SUCCESS);
            }
        }

        printf(".\n");
    }

    close(fd);

    return 0;
}
