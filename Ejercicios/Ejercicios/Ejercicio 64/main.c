#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[20];
    int i;
    int auxiliar;
    int j;

    for ( i = 0 ; i < 20 ; i ++ )
    {
        printf("Ingres un valor para el vector: \n");
        scanf("%d" ,  &vector[i]);
        if( vector[i] == 0)
        {
            printf("Error , debe ingresar un unmero distinto de cero.Por favor ingrese otro numero. \n");
            scanf("%d",&vector[i]);
        }
    }

    for ( i = 0  ; i <  20 ; i ++)
   {
       printf("%d\n", vector[i]);
   }

   printf("ordenando\n");


    if ( vector[i] > 0)
    {
        for ( i = 0 ; i < 20 ; i++)
        {
            for ( j =  i+1 ; j < 20 ; )
            {
                if ( vector[j] > vector[i])
                {
                    auxiliar = vector[j];
                    vector[j] = vector[i];
                    vector[i] = auxiliar;
                }
            }
        }
    }
    else if ( vector [i] < 0)
    {
        for ( i = 0 ; i < 20 ;  i++ )
        {
            for ( j = i +1 ; j < 20 ;j ++)
            {
                if ( vector [j] < vector [i])
                {
                    auxiliar = vector[j];
                    vector[j] = vector[i];
                    vector[i] = auxiliar;
                }
            }
        }
    }

   for ( i = 0  ; i <  20 ; i ++)
   {
       printf("%d\n", vector[i]);
   }
    return 0;
}
