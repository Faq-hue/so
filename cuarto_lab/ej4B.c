#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 1024

int main(int argc, char const *argv[])
{
    int fd = open("comunicador.txt", O_RDONLY);

    if (fd == -1)
    {
        printf("No encuentro comunicador.txt \n");
        exit(EXIT_FAILURE);
    }

    char buff[MAX], buff2[MAX];

    int n = read(fd, buff, MAX);

    printf("%s", buff);

    while (1)
    {
        int n = read(fd, buff2, MAX);

        for (int i = 0; i < n; i++)
        {
            if (buff[i] != buff2[i])
            {
                printf("%s", buff2);

                exit(EXIT_SUCCESS);
            }
            
        }
        
    }

    close(fd);

    return 0;
}
