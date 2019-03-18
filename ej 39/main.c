#include <stdio.h>
#include <stdlib.h>
// Diseña un programa que lea 4 numeros e imprima el mayor
int main()
{
    int numeroUno;
    int numeroDos;
    int numeroTres;
    int numeroCuatro;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numeroUno);
    printf("\n Ingrese el segundo numero: ");
    scanf("%d", &numeroDos);
    printf("\n Ingrese el tercer numero: ");
    scanf("%d", &numeroTres);
    printf("\n Ingrese el cuarto numero: ");
    scanf("%d", &numeroCuatro);

    if ( numeroUno >= numeroDos && numeroUno >= numeroTres && numeroUno >= numeroCuatro )
        {
            printf("\n El numero mas alto es el primero que ingreso: %d",numeroUno);}

    if ( numeroDos >= numeroUno && numeroDos >= numeroTres && numeroDos >= numeroCuatro )
        {
            printf("\n El numero mas alto es el segundo que ingreso: %d",numeroDos);}

    if ( numeroTres >= numeroDos && numeroTres >= numeroUno && numeroTres >= numeroCuatro )
        {
            printf("\n El numero mas alto es el tercero que ingreso: %d",numeroTres);}

    if ( numeroCuatro >= numeroDos && numeroCuatro >= numeroTres && numeroCuatro >= numeroUno )
        {
            printf("\n El numero mas alto es el cuarto que ingreso: %d",numeroCuatro);}

    return 0;
}
