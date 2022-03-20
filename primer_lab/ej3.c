/*3. Escriba un programa similar al anterior, de modo que cada proceso 
obtenga su propio numero de proceso y el de su padre; a continuación 
imprima el resultado. Estudie y utilice las llamadas getpid() y getppid().
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    int result = fork();

    if (result != 0)
    {
        printf("Father, pid: %d , ppid: %d\n",getpid(), getppid());
    }else
    {
        printf("Son, pid: %d , ppid: %d\n",getpid(), getppid());
    }
    

    return 0;
}
