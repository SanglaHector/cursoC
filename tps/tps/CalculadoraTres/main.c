#include <stdio.h>
#include <stdlib.h>
    int sumar(int nUno,int nDos);
    int restar( int nUno ,  int nDos);
    int multiplicar(int nUno , int nDos);
    int dividir(int nUno ,  int nDos);
    int factorizar(int nUno);

int main()
{
    int numeroUno;
    int numeroDos;
    int suma;
    int resta;
    int multiplicacion;
    int division;
    int factorizacionUno;
    int factorizacionDos;

    int opcion;

    do
    {
        printf("1.Ingrese el primer operando.\n");
        printf("2:Ingrese el segundo operando.\n");
        printf("3.Calcular todas las operaciones.\n");
        printf("4.Informar resultados.\n");
        printf("5.Salir.\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){

    case 1:
        printf("Digite el primer numero. \n");
        scanf("%d", &numeroUno);

        system("cls");
        break;

    case 2:

        printf("Digite el segundo numero. \n");
        scanf("%d", &numeroDos);

        system("cls");
        break;

    case 3:

        suma = sumar(numeroUno, numeroDos);

        resta = restar ( numeroUno ,numeroDos );

        multiplicacion = multiplicar (numeroUno , numeroDos);

        division = dividir ( numeroUno , numeroDos);

        factorizacionUno =   factorizar( numeroUno);

        factorizacionDos = factorizar (numeroDos);
        break;

    case 4:
        printf("\n El resultado de la suma es de: %d", suma);
        printf("\n El resultado de la resta es de: %d", resta);
        printf("\n El resultado de la multiplicacion es  de: %d", multiplicacion);
        printf("\n El resultado de la division es de:  %d",division);
        printf("\n El resultado de la factorial del primer numero es de: %d", factorizacionUno);
        printf("\nEl resultado de la factorial del segundo numero es de :%d", factorizacionDos);



    case 5:
        exit("n");
        break;
        }
    system("pause");
    system("cls");

    }
        while ( opcion !=5);


    return 0;

    }

