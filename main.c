#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    int pid;
    int ppid;

    pid= getpid();
    ppid=getpid();
    printf("PID: %d - PPID: %d\n" , pid,ppid);
    sleep(100);

    return 0;
}

