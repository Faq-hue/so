#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    int pid;
    int ppid;
    int result;    

    result = fork();
    pid = getpid();
    ppid= getpid();

    printf("RES: %d - PID: %d - PID: %d\n", result,pid,ppid);

    return 0;
}
