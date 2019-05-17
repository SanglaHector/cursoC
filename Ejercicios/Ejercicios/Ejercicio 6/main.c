#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numero;
    float positivo = 0;
    float negativo = 0;
    float cero = 0;
    float i;

    for( i = 0 ; i < 10 ; i++){

        printf("Ingrese un numero: \n");
        scanf("%f" , &numero);

        if ( numero < 0){
            negativo ++;
        }
        else if( numero > 0){
            positivo ++;
        }else{
            cero ++;
        }
    }

    printf("La cantidad de numeros mayores a cero es de: %f", positivo);
    printf("\nLa cantidad de numeros menores a cero es de: %f" ,  negativo);


    return 0;
}
