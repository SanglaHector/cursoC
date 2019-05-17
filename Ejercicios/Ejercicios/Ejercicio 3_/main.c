#include <stdio.h>
#include <stdlib.h>

   int main()
{
    float numeroUno;
    float numeroDos;
    float producto;
    float cuadrado;

    printf("Igrese el primer numero que sea distinto de cero \n");
    scanf("%f", &numeroUno);

    printf("Ingrese el segundo numero distinto de cero.\n");
    scanf("%f" , &numeroDos);

    if( numeroUno == 0){
        printf("Por favor ingrese un numero distinto a cero \n");
        scanf("%f", &numeroUno);
    }
    if ( numeroDos == 0){
        printf("Por favor ingrese un numero distinto de cero. \n");
        scanf("%f",&numeroDos);
    }

    producto = numeroUno * numeroDos;
    cuadrado = numeroUno * numeroUno;

    system("CLS");
    printf("El resultado de la multiplicacion es de: %f" , producto, "\n");



    printf("\n El resultado delcuadrado del  numero uno es de: %f" , cuadrado , "\n");

    return 0;
}

