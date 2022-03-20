/*6. Escriba un programa que capture las señales “Ctrl-C” (Interrumpir) 
y “Ctrl-Z” (Suspender), en el primer caso el programa debe escribir un mensaje en pantalla, en el segundo debe terminar.

Utilice el siguiente procedimiento: defina una función que retorne 
void para manejar la señal y asigne una señal a esta función por medio 
de la llamada signal()

void sigmanager(int sig_num) {
	 Reasignar la señal
	signal(SIGNAL, sigmanager):
	...
	fflush(stdout);
	}
	...
	signal(SIGNAL, sigmanager);
    }
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void sigManager(int);

int main(int argc, char const *argv[])
{
    
    while (1)
    {
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