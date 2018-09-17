#include <stdio.h>
#include <stdlib.h>

int main()
{
    char respuesta;
    int peso;
    int personas = 1;
    int i;
    int contadorPeso = 0;
    int contadorPesoMayor = 0;

    for(i=0; i <= peronas ; i++)
    {
        peso = ingresoPeso();
        if( peso <= 80)
            contadorPeso ++;
    }else
    contadorPesoMayor ++;


    return 0;
}
int ingresoPeso ()
{
    int peso;
    printf("Ingrese el peso del empleado: \n");
    scanf("%d",&peso);
    return peso;
}
