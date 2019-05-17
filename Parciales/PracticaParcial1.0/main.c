#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ABM.h"
#define TAM 1000
#define TAMMAR 5
#define TAMTRA 1000
#define TAMCOL 5
#define TAMSER 4
#define OCUPADO 1
#define VACIO 0

int main()
{
    int opcion;
    int vacio;
        //***********************************
    eMarca marcas[] ={
        {1000,"Renault",1},{1001,"Fiat",1},{1002,"Ford",1},{1003,"Chevrolet",1},{1004,"Peugeot",1}
        };
        //************************************
    eColor colores[] ={
        {5000,"Negro",1},{5001,"Blanco",1},{5002,"Gris",1},{5003,"Rojo"},{5004,"Azul",1}
    };
        //***********************************
    eServicio servicios[] = {{20000,"Lavado",250,1},{20001,"Pulido",300,1},{20002,"Encerado",400},1,{20003,"Completo",600,1}
    };
        //**********************************
    eAuto autos[TAM];
    eTrabajo trabajos[TAMTRA];
    inicializarE(autos,TAM);
    inicializarTrabajos(trabajos,TAMTRA);
    inicializarColores(colores,TAMCOL);
    hardCodearAutos(autos,7);
    hardCodearTrabajos(trabajos,7);
do
    {

        printf("1-Alta auto\n");
        printf("2-Modificar auto\n");
        printf("3-Baja auto\n");
        printf("4-Programa colores\n");
        printf("5-Programa marcas\n");
        printf("6.Programa servicios\n");
        printf("7.Programa trabajos\n");
        printf("8.Programa clientes\n");
        printf("9.Listados\n");
        printf("10-Salir\n");
        printf("Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
                altaE(autos,TAM,marcas,TAMMAR,colores,TAMCOL);
            break;
        case 2:
            vacio = buscarLleno(autos,TAM);
            if( vacio == OCUPADO){
                modificarE(autos,TAM,marcas,TAMMAR,colores,TAMCOL);
            }else {
            printf("\nDebe ingresar un usuario antes de ingresar a esta opcion.\n");
            }
            break;
        case 3:
                vacio = buscarLleno(autos,TAM);
            if( vacio == OCUPADO){
                bajaE(autos,TAM,marcas,TAMMAR,colores,TAMCOL);
            }else {
            printf("\nDebe ingresar un usuario antes de ingresar a esta opcion.\n");
            }
            break;
        case 4:

            programaColores(colores,TAMCOL);
            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:

            break;
        case 10:
            printf("Hasta luego!\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }

        system("pause");
        system("cls");

    }
    while(opcion !=10);

    return 0;
}
