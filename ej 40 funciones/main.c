#include <stdio.h>
#include <stdlib.h>
void ingresarDatos();
void evaludarDias();
void sacarPromedio();
int main()
{
    int dias [30];
    int Lluvia;
    int i;
    int contador;
    int mayor ;
    int menor ;
    int diaMayor ;
    int diaMenor ;
    int promedio ;
    int acumulador ;

    ingresarDatos(i,contador,dias);
    printf("\n%d", mayor);
    printf("\n%d",menor);
    printf("\n%d",diaMayor);
    printf("\n%d",diaMenor);

    evaludarDias(i, dias, mayor, diaMayor, menor, diaMenor);
    sacarPromedio(i,dias,acumulador);
    promedio = acumulador / 30;
    printf("\nla mayor cantidad de lluvia en un dia fue de : %d mm", mayor);
    printf("\nLa menor cantidad de lluvia en un dia fue: %d mm", menor);
    printf("\nEL dia que mas llovio fue: %d", diaMayor);
    printf("\nEl dia que menos llovio fue: %d",diaMenor);
    printf("\n el promedio de lluvia caida fue de: %d",promedio);

    return 0;
}
void ingresarDatos (int i,int contador, int dias[]){
    for (i=0 ; i<= 30 ; i++){
        printf("\nIngrese la cantidad de lluvia en mm que callo el dia %d : ", i+1);
        scanf("%d", &dias[i]);
    }
}
void evaludarDias(int j, int dia[], int ma, int diaMa, int me, int diaMe){
     ma = 0;
     me = 999;
     diaMa = 0;
     diaMe = 0;
    for (j=0 ; j<30 ; j ++){

        if ( dia[j] > ma ){
            diaMa = j+1;
            ma = dia[j];
            }
    }
    for ( j=0 ; j<30 ; j++){
        if (dia[j]< me){
            diaMe = j+1;
            me = dia[j];
            }
    }
}
void sacarPromedio(int i, int dias[], int acumulador){
    acumulador = 0;
       for ( i = 0; i < 30 ; i ++){
        acumulador = dias[i] + acumulador;
    }
}
