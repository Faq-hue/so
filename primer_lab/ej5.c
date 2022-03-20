/*5. Escriba un programa similar al anterior, pero modificado de modo 
que el hijo quede en espera indefinida, luego desde una terminal envíe 
una señal (por medio del comando kill para que termine y observe el 
comportamiento del status de salida.
Investigue las señales posibles por medio de man 7 signal .
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char const *argv[])
{
    int result,status;

    result = fork();

    wait(&status);

    if (result ==0)
    {
        printf("Son, pid: %d , ppid: %d\n",getpid(), getppid());
        printf("Running");
        
        while (1)
        {
            /* code */
        }
        

    }else
    {
        if (WIFSIGNALED(status))
        {
            printf("Killed by signal\n");
        }

        printf("Father, pid: %d , ppid: %d\n",getpid(), getppid());

    }
    
    return 0;
}
