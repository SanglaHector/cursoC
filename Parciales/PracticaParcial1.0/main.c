#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ABM.h"
#define TAM 1000
#define TAMMAR 10
#define TAMTRA 100
#define TAMCOL 100
#define TAMSER 10
#define TAMCLI 10
#define OCUPADO 1
#define VACIO 0

int main()
{
    int opcion;
    int vacio;
//******************************************************
    eAuto autos[TAM];
    eTrabajo trabajos[TAMTRA];
    eColor colores[TAMCOL];
    eMarca marcas[TAMMAR];
    eServicio servicios[TAMSER];
    eCliente clientes[TAMCLI];
    inicializarE(autos,TAM);
    inicializarTrabajos(trabajos,TAMTRA);
    inicializarColores(colores,TAMCOL);
    inicializarMarcas(marcas,TAMMAR);
    inicializarServicios(servicios,TAMSER);
    inicializarClientes(clientes,TAMCLI);
//************AREA DE PRUEBA ****************************
    hardCodearAutos(autos,7);
    hardCodearTrabajos(trabajos,7);
    hardCodearColores(colores,5);
    hardCodearMarcas(marcas,5);
    hardCodearServicios(servicios,4);
    hardCodearClientes(clientes,5);
//******************************************************
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
                altaE(autos,TAM,marcas,TAMMAR,colores,TAMCOL,clientes,TAMCLI);
            break;
        case 2:
            vacio = buscarLleno(autos,TAM);
            if( vacio == OCUPADO){
                modificarE(autos,TAM,marcas,TAMMAR,colores,TAMCOL,clientes,TAMCLI);
            }else {
            printf("\nDebe ingresar un usuario antes de ingresar a esta opcion.\n");
            }
            break;
        case 3:
                vacio = buscarLleno(autos,TAM);
            if( vacio == OCUPADO){
                bajaE(autos,TAM,marcas,TAMMAR,colores,TAMCOL,clientes,TAMCLI);
            }else {
            printf("\nDebe ingresar un usuario antes de ingresar a esta opcion.\n");
            }
            break;
        case 4:

            programaColores(colores,TAMCOL);
            break;
        case 5:
            programaMarcas(marcas,TAMMAR);
            break;
        case 6:
            programaServicios(servicios,TAMSER);
            break;
        case 7:
            programaTrabajos(trabajos,TAMTRA,autos,TAM,servicios,TAMSER);
            break;
        case 8:
            programaClientes(clientes,TAMCLI);
            break;
        case 9:
            listados(autos,TAM,colores,TAMCOL,marcas,TAMMAR,servicios,TAMSER,trabajos,TAMTRA,clientes,TAMCLI);
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
