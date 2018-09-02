#include <stdio.h>
#include <stdlib.h>

int main()
{
    float radio;
    float area;
    float perimetro;

    printf("Ingrese el radio del circulo: \n");
    scanf("%f",&radio);

    area = 3.14 * ( radio * radio);
    perimetro = 3.14 * 2 * radio ;

    printf("El area de su circulo es de: %f", area );
    printf("\n");
    printf("El perimetro de su circulo es de %f", perimetro , "\n");
    return 0;
}
