#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "auto.h"
#define TAM 1000
#define TAMMAR 5
#define TAMTRA 1000
#define TAMCOL 5
#define TAMSER 4
#define OCUPADO 1
#define VACIO 0

void inicializarE(eAuto vec[], int tam);
void inicializarTrabajos(eTrabajo vecTra[],int tamTra);
void hardCodearAutos(eAuto vec[], int tam);
void hardCodearTrabajos(eTrabajo vec[], int tam);
int buscarLleno(eAuto vec[],  int tam);
void altaE(eAuto vec[], int tam, eMarca marVec[], int marSec,eColor colVec[],int tamCol);
void mostrarE(eAuto e, eMarca vecMar[], int tamMar, eColor vecCol[], int tamCol);
void bajaE(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol);
void listarAutos(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol);
void listarMarcas( eMarca vecMar[], int tamMar);
void listarColores( eColor vecCol[],  int tamCol);
void listarServicios(eServicio vecSer[], int tamSer);
void altaTrabajo(eAuto vec[], int tam,eServicio vecSer[], int tamSer,eTrabajo vecTra[], int tamTra);
void mostrarTrabajos(eTrabajo vecTra[], int tamTra, eServicio vecSer[], int tamSer);

int main()
{
    int opcion;
    int vacio;
        //***********************************
    eMarca marcas[] ={
        {1000,"Renault"},{1001,"Fiat"},{1002,"Ford"},{1003,"Chevrolet"},{1004,"Peugeot"}
        };
        //************************************
    eColor colores[] ={
        {5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}
    };
        //***********************************
    eServicio servicios[] = {{20000,"Lavado",250},{20001,"Pulido",300},{20002,"Encerado",400},{20003,"Completo",600}
    };
        //**********************************
    eAuto autos[TAM];
    eTrabajo trabajos[TAMTRA];
    inicializarE(autos,TAM);
    inicializarTrabajos(trabajos,TAMTRA);
  //  hardCodearAutos(autos,7);
  //  hardCodearTrabajos(trabajos,7);
do
    {

        printf("1-Alta auto\n");
        printf("2-Modificar auto\n");
        printf("3-Baja auto\n");
        printf("4-Listar autos\n");
        printf("5-Listar marcas\n");
        printf("6.Listar colores\n");
        printf("7.Listar servicios\n");
        printf("8.Alta trabajo\n");
        printf("9.Listar trabajo\n");
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
             vacio = buscarLleno(autos,TAM);
            if( vacio == OCUPADO){
                listarAutos(autos,TAM,marcas,TAMMAR,colores,TAMCOL);
            }else {
            printf("\nDebe ingresar un usuario antes de ingresar a esta opcion.\n");
            }
            break;
        case 5:
            vacio = buscarLleno(autos,TAM);
            if( vacio == OCUPADO){
                listarMarcas(marcas,TAMMAR);
            }else {
            printf("\nDebe ingresar un usuario antes de ingresar a esta opcion.\n");
            }
            break;
        case 6:
            vacio = buscarLleno(autos,TAM);
            if( vacio == OCUPADO){
                listarColores(colores,TAMCOL);
            }else {
            printf("\nDebe ingresar un usuario antes de ingresar a esta opcion.\n");
            }
            break;
        case 7:
             vacio = buscarLleno(autos,TAM);
            if( vacio == OCUPADO){
                listarServicios(servicios,TAMSER);
            }else {
            printf("\nDebe ingresar un usuario antes de ingresar a esta opcion.\n");
            }
            break;
        case 8:
            vacio = buscarLleno(autos,TAM);
            if( vacio == OCUPADO){
                altaTrabajo(autos,TAM,servicios,TAMSER,trabajos,TAMTRA);
            }else {
            printf("\nDebe ingresar un usuario antes de ingresar a esta opcion.\n");
            }
            break;
        case 9:
            vacio = buscarLleno(autos,TAM);
            if( vacio == OCUPADO){
                mostrarTrabajos(trabajos,TAMTRA,servicios,TAMSER);
            }else {
            printf("\nDebe ingresar un usuario antes de ingresar a esta opcion.\n");
            }
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
