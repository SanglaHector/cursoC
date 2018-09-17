#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int numeroTres;

    printf("Ingrese el primer numero: \n");
    scanf("%d",&numeroUno);
    printf("Ingrese el segundo numero: \n");
    scanf("%d",&numeroDos);
    printf("Ingrese el tercer numero: \n");
    scanf("%d",&numeroTres);


   desendente( numeroUno, numeroDos, numeroTres);
    return 0;
}

void desendente ( int a, int b , int c)
{

    if (a >= b && a >= c )
    {
        if (b >= c )
        {
         printf("%d , %d , %d .", a , b , c );
        } else if ( c >= b)
        {
         printf("%d , %d , %d .", a , c , b );
        }
    } else if ( b >= a && b >= c )
    {
        if( a >= c )
        {
            printf("%d , %d , %d .", b , a , c );
        }else if ( c >= a)
        {
            printf("%d , %d , %d .", b , c , a );
        }
    }else if ( c  >= a && c >= b )
    {
        if ( a >= b )
        {
            printf("%d , %d , %d .", c , a , b );
        }else if ( b >= a )
        {
            printf("%d , %d , %d .", c , b , a );
        }
    }
    return 0;
}
