#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 1;
    int y = 2;
    int z[10];
    int *ip;  /* ip es un apuntador a int*/

    printf("ip: %d" ,ip);
    printf("\nip vale 101, un valor basura");

    /*////////////////////////////*/
    ip = &x;
    printf("\nip = &x : %d" ,ip);
    printf("\nip vale  de x");
    /* /
    /*///////////////////////////*/
    /* como  ip fue definido como un puntero, le asigno valores que puedan ser punteros, no le puedo asignar un valor como
    por ejemlplo "2", ya  que 2 no existe como direccion de memoria */

    ip = 2;
    printf("\nip = 2  :");
    printf("\n %d", ip);

    //como digo que ip me traiga lo que hay en &x

	ip = &x;

	printf("la direccion de memoria de 'x' es: %p \n", &x);
	printf("y su contenido es : %d \n", *ip);

    return 0;
}
