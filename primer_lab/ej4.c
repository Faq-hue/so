/*4. Escriba un programa en el cual creamos un proceso y configuramos 
al proceso “padre” para que espere, por medio de la llamada wait() , 
a que termine su hijo antes de proseguir, luego de lo cual debe 
reportar el status de salida del proceso hijo. 
Use la llamada wait() . Se la debe invocar como

...
wait(&STATUS);
...

Use el status de salida, analícelo por medio de las funciones macro 
definidas en la página de manual de la llamada wait() .
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int result;
    int status;

    result = fork();

    wait(&status);

    if (result !=0)
    {
        printf("Father, pid: %d , ppid: %d\n",getpid(), getppid());
        printf("Status: %d\n", WEXITSTATUS(status));
    }else
    {
        printf("Son, pid: %d , ppid: %d\n",getpid(), getppid());
    }
    
    return 0;
}

