int sumar(int nUno, int nDos){
        int suma;
        suma = nUno + nDos;
        return suma;}


    int restar ( int nUno , int nDos){
    int resta;
     resta = nUno - nDos;
     return resta;}



     int multiplicar (int nUno , int nDos){
       int multiplicacion;
        multiplicacion = nUno *nDos;
        return multiplicacion;
     }

     int dividir( int nUno , int nDos){
       int division;
        division= nUno / nDos;
        return division;}

    int factorizar ( int nUno){
        int factorizacion;
        int i;
        int acumulador = 1;

        for ( i = nUno ; i >= 1 ; i --){
            acumulador = acumulador * i;
            }

        factorizacion = acumulador;
        return factorizacion;
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

