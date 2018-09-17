#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector [31];
    int i;
    int compras = 0 ;
    char respuesta;

    for ( i = 0 ;  i < 31 ;  i++)
    {

        int auxiliar = 0;
        printf("Ustes se encuentra en el dia: %d \n",  i+1);
        printf("Por favor ingrese el gasto al  dia correspondido:\n ");
        scanf("%d", &compras);

        do
        {

        printf("Desea agregar otro gasto? Ingrese s/n \n");
        fflush()
        scanf("%c",&respuesta);
        printf("Ingrese otro gasto: %d \n");
        scanf("%d" , &auxiliar);
        compras = compras + auxiliar;
        }
        while( respuesta == "s" || respuesta == "S");
        vector[i] =compras;
        printf("El gasto del dia %d es de %d \n",i +1, vector[i] );
    }
    return 0;
}


