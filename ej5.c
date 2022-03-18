#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
    
    int pid;
    int status;

    pid = fork();

    if (pid == 0)
    {
        printf("Hijo\n");
        
    }

    return 0;
}
