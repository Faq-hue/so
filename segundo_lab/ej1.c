/*1) Compile el ejemplo que crea 5 hilos, guarde en ht.c
Compile utilizando:

    $ gcc -Wall -pthread -o ht ht.c
    
    Notas:
a) pthread_create crea el hilo, el primer argumento almacena el ID del Hilo,
el tercero indica cual es la función que ejecuta el hilo, el cuarto es el
[unico] argumento que podemos pasar al hilo.

b) Todos los hilos deben invocar pthread_exit al terminar.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS     5

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   int t;
   
   for( t = 0; t < NUM_THREADS; t++ ) {
      printf("In main: creating thread %ld\n", t);
      rc = pthread_create( &threads[t], NULL, PrintHello, (void *)t);
      if ( rc ) {
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }

   /* Last thing that main() should do */
   pthread_exit(NULL);
}