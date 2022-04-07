#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct dirent *dir;

int main(int argc, char const *argv[])
{

    while (1)
    {
        int fd = open(argv[1], O_RDONLY);
        printf("No encuentro %d \n", argv[1]);
        if (fd != -1)
        {
            printf("Encontrado, salgamos\n");
            close(fd);
            return 123;
        }

        close(fd);
    }

    return 0;
}
