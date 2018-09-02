#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int numeroTres;
    int numeroCuatro;
    int numeroCinco;
    float promedio;

    printf("Ingrese el primer numero: ");
    scanf("%d",&numeroUno);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &numeroDos);

    printf("Ingrese el tercer numero :");
   scanf("%d" , &numeroTres);

    printf("Ingrese el cuarto numero: ");
    scanf("%d", &numeroCuatro);

    printf("Ingrese el quinto numero: ");
    scanf("%d", &numeroCinco);

    promedio = ( numeroUno + numeroDos + numeroTres + numeroCuatro + numeroCinco ) / 5 ;
    printf("El valor del promedio es de: %f" ,  promedio);

    return 0;
}
