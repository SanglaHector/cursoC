#include <stdio.h>
#include <stdlib.h>
float sumar(float nUno,float nDos);
float restar( float nUno ,  float nDos);
float multiplicar(float nUno , float nDos);
float dividir(float nUno ,  float nDos);

int main()
{

    float numeroUno;
    float numeroDos;
    float suma;
    float resta;
    float multiplicacion;
    float division;

    int opcion;
    do
    {
    printf("1.Sumar\n");
    printf("2:Restar\n");
    printf("3.Multiplicacion\n");
    printf("4.Division\n");
    printf("5.Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    switch(opcion){
        case 1:
            printf("Digite el primer numero \n");
            scanf("%f",&numeroUno);

            printf("Digite el segundo numero \n");
            scanf("%f",&numeroDos);

            suma =  sumar(numeroUno,numeroDos);
            printf("\n La suma es de: %f \n", suma);
        break;


        case 2:
            printf("Digite el minuendo. \n");
            scanf("%f",&numeroUno);

            printf("Digite el sustraendo.\n");
            scanf("%f",&numeroDos);

            resta = restar(numeroUno , numeroDos);
            printf("\n La resta es de: %f\n" , resta);
        break;


        case 3:
            printf("Digite el primer numero.\n");
            scanf("%f",&numeroUno);

            printf("Digite el segundo numero. \n");
            scanf("%f",&numeroDos);

            multiplicacion = multiplicar(numeroUno , numeroDos);
            printf("\n La multiplicacion es de: %f\n" , multiplicacion);
        break;


        case 4:
            printf("Digite el dividendo. \n");
            scanf("%f",&numeroUno);

            printf("Digite el divisor. \n");
            scanf("%f",&numeroDos);

            division= dividir(numeroUno , numeroDos);
            printf("\n La division es de: %f \n",division);
        break;

        case 5:
            exit("n");

        default:
            printf("Por favor ingrese un numero correct. \n");

    }
system("pause");
system("cls");
    }
    while (opcion != 5)
        ;
    return 0;
    }

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



