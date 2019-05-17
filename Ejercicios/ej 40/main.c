#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dias [30];
    int Lluvia;
    int i;
    int contador = 0;
    int mayor = 0;
    int menor = 9999;
    int diaMayor;
    int diaMenor;
    int promedio = 0;
    int acumulador = 0;

    for (i=0 ; i<= 30 ; i++){
        printf("\nIngrese la cantidad de lluvia en mm que callo el dia %d : ", i+1);
        scanf("%d", &Lluvia);
        dias [i] = Lluvia;
        contador ++;

    }
    for (i=0 ; i<=30 ; i ++){

        if ( dias[i] > mayor ){
            diaMayor = i+1;
            mayor = dias[i];
        }
    }
    for ( i=0 ; i<=30 ; i++){

        if (dias[i]< menor){
            diaMenor = i+1;
            menor = dias[i];

        }
    }
    for ( i = 0; i <= 30 ; i ++){

        acumulador = dias[i] + acumulador;

        }

    promedio = acumulador / 31;
    printf("\nla mayor cantidad de lluvia en un dia fue de : %d mm", mayor);
    printf("\nLa menor cantidad de lluvia en un dia fue: %d mm", menor);
    printf("\nEL dia que mas llovio fue: %d", diaMayor);
    printf("\nEl dia que menos llovio fue: %d",diaMenor);
    printf("\n el promedio de lluvia caida fue de: %d",promedio);

    return 0;
}
