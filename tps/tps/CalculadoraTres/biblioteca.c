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
