/*1) Cliente-Servidor con archivos. Exploraremos la posibilidad de "comunicar" 
dos procesos mediante archivos externos. Escriba un programa que "cree" dos
archivos, a-inout y b-inout. Luego deberá crear dos hijos, cada hijo deberá 
abrir los archivos PERO de modo que el primer hijo abra "a" para lectura y 
"b" para escritura, en cambio el segundo abrira "a" para escritura y "b"
para lectura. Una vez realizado esto el primer hijo debera obtener la hora
del sistema (usando ctime()), escribira esta informacion en "b", cuando esto
ocurra, el segundo proceso hijo obtendra a su vez la hora y la leerra de 
"b", y la mostrara por pantalla. Al finalizar ambos procesos hijos
el padre deberá reportar el estado de terminacion.*/


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
