#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int negativos = 0;
    int positivos = 0;
    int i;

    for ( i = 1 ; i <= 10 ; i++)
    {
        printf("Ingrese un numero:\n");
        scanf("%d", &numero);
        if ( numero > 0  )
        {
            positivos = numero + positivos;
        } else if ( numero < 0 )
        {
            negativos = numero + negativos;
        }
        while ( numero == 0)
        {
            printf("El numero cero no cuenta, por favor ingrese otro numero. \n");
            scanf("%d", &numero);
        }
        }
        printf("\n La suma de los positivos es de: %d",positivos);
        printf("\n El producto de los negativos es de: %d", negativos);

    return 0;
}
