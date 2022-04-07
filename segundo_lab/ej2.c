/*2) Use 5 hilos para computar los 5 primeros términos de la serie de Fibonacci

0 1 1 2 3 5 8 13 ...
a_n = a_n-1 + a_n-2

Use una expresión no recursiva para la función de la serie.
Declare un arreglo común donde cada hilo debe almacenar elresultado.
Imprima el arreglo al finalizar

Piense de que modo 'sicronizar' al hilo principal, recuerde que las variables
globales son comunes.*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int fibb = 0, ant = 1;

void *cFibonacci(void *threadid){

    long tid;
    tid = (long)threadid;
    
    int x = fibb;

    if(fibb == 0 || fibb == 1){
        
        fibb = fibb+1;

    }else
    {
        
        fibb = fibb + ant;
        
    }

    
    ant = x;

    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    
    int j = 10, rc;
    pthread_t threads[j];

    //printf("Hello World! It's me, thread #%ld!\n", tid);
    
    for (int i = 0; i < j; i++)
    {
        printf("%d, ", fibb);
        
        rc = pthread_create( &threads[j], NULL, cFibonacci, (void *)j);

      if ( rc ) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
      
    }
    
    pthread_exit(NULL);
}
