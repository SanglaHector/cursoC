#include <stdio.h>
#include <stdlib.h>

int main()
{
    float base;
    float altura;
    float area;

    printf("Ingrese la altura del triangulo: ");
    scanf("%f", &altura);

    printf("Ingrese la base del triangulo: ");
    scanf("%f", &base);

    area = ( base * altura) / 2 ;
    printf("El area de su triangulo es de %f", area);
    return 0;
}
