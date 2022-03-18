#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    int pid;
    
    pid = fork();

    if (pid !=0)
    {
        printf("Father\n");
    }else
    {
        printf("Son\n");
    }
    
    

    return 0;
}
