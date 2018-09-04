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
    int factorizacion;

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

        prinf("Digite el segundo numero. \n");
        scanf("%d", &numeroDos);

        system("cls");
        break;

    case 3:

        int sumar(int nUno,int nDos);
        int suma = sumar(numeroUno, numeroDos);

        int restar( int nUno ,  int nDos);
        resta = restar ( int nUno , int nDos);

        int multiplicar(int nUno , int nDos);
        multiplicacion = multiplicar (numeroUno , numeroDos);

        int dividir(int nUno ,  int nDos);
        division = dividir ( numeroUno , numeroDos);

        int factorizar(int nUno);
        factorizacion = factorizar ( numeroUno);

        int factorizar (int nUno);
        factorizacion = factorizar (numeroDos);

        break;

    case 4:





    case 5:
        exit("n");
        break;

    system("pause");
    system("cls");


        while ( opcion !=5);
        }

    return 0;

    }

