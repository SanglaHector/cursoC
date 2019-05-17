#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int auxiliar;

    printf("Ingrese el primer numero: \n");
    scanf("%d",&numeroUno);

    printf("Ingrese el segundo numero: \n");
    scanf("%d",&numeroDos);

    auxiliar = numeroUno;
    numeroUno = numeroDos;
    numeroDos= auxiliar;

    printf("Intercambiando numeros...\n");
    printf("El primer numero ahora es:%d y el segundo es:%d", numeroUno , numeroDos);
    return 0;
}
