#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numeroUno;
    float numeroDos;
    float suma;

    printf("Ingrese el numero uno ");
    scanf("%f" , &numeroUno);

    printf("Ingrese el numero dos ");
    scanf("%f" , &numeroDos);

    suma = numeroUno + numeroDos ;

    printf("La suma de ambos numeros es de: %f", suma);

    return 0;
}
