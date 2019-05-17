#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numero;
    float cuadrado;

    printf("Ingrese un numero: \n");
    scanf("%f", &numero);

    if ( numero <= 0 ){
        printf("ERROR el numero debe ser mayor que cero. \n");
        return 0;
    }

    cuadrado = numero * numero;
    printf("El cuadrado del numero es de: %f", cuadrado);
    return 0;
}
