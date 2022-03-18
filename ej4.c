#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int pid;
    int status;

    pid = fork();

    wait(&status);

    if (pid !=0)
    {
        printf("Father\n");
        printf("PID: %d\n",pid);
    }else
    {
        printf("Son\n");
        printf("PID: %d\n",pid);
    }

    printf("Estatus %d\n", status);
    

    return 0;
}

