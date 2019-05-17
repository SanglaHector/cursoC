#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define TAM 7
#define TAMSEC 4
#define OCUPADO 1
#define VACIO 0

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{

    int legajo;
    float sueldo;
    char nombre[20];
    char apellido [20];
    char sexo;
    eFecha fechaIngreso;
    int estado;
    int sector;
}eEmpleado;

typedef struct{
    int id;
    char descripcion[20];
}eSector;

int buscarLibre(eEmpleado vec[], int tam);
int buscarE(eEmpleado vec[], int tam);
void inicializarE(eEmpleado [], int tam);
void altaE(eEmpleado [], int,eSector [], int);
void bajaE(eEmpleado [], int);
void modificarE(eEmpleado vec[], int tam);
void mostrarE(eEmpleado e, eSector sectores);
void mostrarEs(eEmpleado vec[], int tam,eSector sectores);
void hardCodear(eEmpleado vec[], int tam);

int main()
{
    eEmpleado empleados[TAM];
    eSector   sectores[TAMSEC] = {   {1,"Sistemas"},
                                {2,"RRHH"},
                                {3,"Legales"},
                                {4,"Contable"}};

    inicializarE(empleados,TAM);
    hardCodear(empleados,5);
    int opcion;
do
    {

        printf("1-Dar de Alta\n");
        printf("2-Mostrar Empleados\n");
        printf("3-Informes\n");
        printf("4-Modificar\n");
        printf("5-Dar de Baja\n");
        printf("6-Salir\n");
        printf("Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            altaE(empleados,TAM,sectores,TAMSEC);

            break;
        case 2:
            mostrarEs(empleados,TAM,sectores,TAMSEC);
            break;
        case 3:
        //    menuInformes();
            break;
        case 4:
            modificarE(empleados,TAM);
            break;
        case 5:
            bajaE(empleados,TAM);
            break;
        case 6:
            printf("Hasta luego!\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }

        system("pause");
        system("cls");

    }
    while(opcion !=6);

    return 0;
}

