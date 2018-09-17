 float sumar(float nUno, float nDos){
        float suma;
        suma = nUno + nDos;
        return suma;}


    float restar ( float nUno , float nDos){
    float resta;
     resta = nUno - nDos;
     return resta;}



     float multiplicar (float nUno , float nDos){
       float multiplicacion;
        multiplicacion = nUno *nDos;
        return multiplicacion;
     }

     float dividir( float nUno , float nDos){
        float division;
        division= nUno / nDos;
        return division;}

    float factorizar ( float nUno){
        float factorizacion;
        float i;
        float acumulador = 1;

        for ( i = nUno ; i >= 1 ; i --){
            acumulador = acumulador * i;
            }
        if ( nUno == 0)
        {
            factorizacion = 1;
        }else
        {
             factorizacion = acumulador;
        }

        return factorizacion;
        }

 float ingresar ()
 {
     float valor;
     printf("Ingrese el valor del operando: \n");
     scanf("%f", &valor);
     system("cls");
     return valor;
 }


