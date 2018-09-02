#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numeroUno;
    float numeroDos;
    float resta;

    printf("Ingrese el minuendo: \n");
    scanf("%f", &numeroUno);

    printf("Ingrese el sustraendo: \n");
    scanf("%f", &numeroDos);

    resta = numeroUno - numeroDos;

    system("CLS");

    if( resta < 0){
        printf("Resultado negativo");
    }
     else if ( resta > 0 ){
        printf("Resultado positivo");
    }
     else {
    printf("El resultado es 0");
    }

    return 0;
}
