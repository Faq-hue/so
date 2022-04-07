/*3) Escriba un programa que lea el directorio raiz (/) y muestre su
contenido por pantalla. Use opendir(), readdir() y closedir().*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

struct dirent *dir;

int main(int argc, char const *argv[])
{
    
    DIR *smting = opendir("/");
   
    if(smting == NULL){
        printf("Error");
        exit(-1);
    }  

    while ((dir = readdir(smting)) != NULL)
    {
        printf("%s\n", dir->d_name );
    }
    
    closedir(smting);

    return 0;
}

