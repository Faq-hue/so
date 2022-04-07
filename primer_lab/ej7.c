/*7. Escriba un programa que cree un hijo, capture las mismas señales 
del programa anterior, se las reenvie al hijo y reproduzca la 
funcionalidad previa, es decir que el hijo escriba un mensaje para 
la primer señal y termine para la segunda, al terminar el hijo también 
debe terminar el padre.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void sigManager(int);

int main(int argc, char const *argv[])
{
    
    int result,status;

    result = fork();

    wait(&status);

    if (result == 0)
    {
        printf("Son, pid: %d , ppid: %d\n",getpid(), getppid());
        
        while (1)
        {
            signal(SIGTSTP, sigManager);
            signal(SIGINT, sigManager);
        
        }
        

    }else
    {

        printf("Father, pid: %d , ppid: %d\n",getpid(), getppid());
        signal(SIGTSTP, sigManager);
        signal(SIGINT, sigManager);

    }
    

    return 0;
}

void sigManager(int sigNum){
    
    if (sigNum == 2)
    {
        printf("control + c\n");
        signal(SIGINT, SIG_IGN);
       
    }

    if (sigNum == 20)
    {
        signal(SIGTSTP, SIG_IGN);
        kill(getpid(),9);
    }

    fflush(stdout);

    return;
}