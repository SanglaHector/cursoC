#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char nombre [20];
    char apellido [20];
    char nombreCompleto [41];

    char buffer[1024]; /* auxiliar, guarda algo */
    printf("Ingrese nombre ");
    fflush(stdin);
    gets(nombre);
    while(strlen(buffer) > 19)/* Esta condicion significa que se me esta desbordando el vector */
    {
        printf("Reingrese nombre: ");
        fflush(stdin);/*limpio la basura que guardo anteriormente */
        gets(buffer);
    }

    strcpy(nombre ,  buffer);/*copio lo del buffer en mi vector nombre, una vez que ya se(mediante el while) que no se desborda*/

     printf("Ingrese apellido ");
    fflush(stdin);
    gets(apellido);
    while(strlen(buffer) > 19)/* Esta condicion significa que se me esta desbordando el vector */
    {
        printf("Reingrese apellido: ");
        fflush(stdin);/*limpio la basura que guardo anteriormente */
        gets(buffer);
    }
    strcpy(apellido , buffer);


    strcpy(nombreCompleto , apellido);
    strcat(nombreCompleto , ", ");
    strcat(nombreCompleto , nombre);

    strlwr(nombreCompleto);
    nombreCompleto[ 0 ] = toupper(nombreCompleto);/*Es 0 porque se que la primer letra es la que tiene que ser mayuscula*/
    /*El for para vereficar donde hay mayusculas*/

    int i;
    for( i=0 ; i < strlen(nombreCompleto) ; i++) /*el strlen es para que vayacontando uno por uno los caracteres*/
    {
        /*Busco espacios*/
        if(nombreCompleto[i] == " ")
        {
            /*Si es espacio, que pasa?*/
            nombreCompleto[i+1] = toupper((nombreCompleto[i+1]));/*Luego de el espacio tengo una letra, entonces le asigno su equivalente en mayuscula*/

        }
    }
    puts(nombreCompleto);/* nombreCompleto tiene basura*/
    /*Entonces tengo que hacer lo siguiente char nombreCompleto [""]; inicializo en cero*/

    /*Voy a tener que hacer un for para qe me muestre los primeros caracteres de nombre y apellido en minuscula.
    /* Tengo que agregar la biblioteca de arriba*/


    return 0;
}
