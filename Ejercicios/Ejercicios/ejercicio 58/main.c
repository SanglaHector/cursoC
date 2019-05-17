#include <stdio.h>
#include <stdlib.h>
#define rango 5
int main()
{

    int vector [rango];
    int i;


    for( i=0 ; i < rango ; i++)
    {
        printf("Ingrese el valor del indice \n");
        scanf("%d",  &vector [i]);
    }
    for ( i  = 0 ; i < rango ; i++)
    {
        printf("%d\n", vector[i]);
    }

    return 0;
}
