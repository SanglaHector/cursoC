#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define TAM 1000
#define TAMSEC 4
#define TAMMENU 7
#define TAMALM 20
#define OCUPADO 1
#define VACIO 0

typedef struct{
    int anio;
    int mes;
    int dia;
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

typedef struct{
    int id;
    char descripcion[20];

}eComida;

typedef struct{
    int id;
    int idEmpleado;
    int idComida;
    eFecha fecha;
    char descripcion [];
}eAlmuerzo;

int buscarLibre(eEmpleado vec[], int tam);
int buscarE(eEmpleado vec[], int tam , int clave);
void inicializarE(eEmpleado [], int tam );
void altaE(eEmpleado [], int , eSector[] , int );
void bajaE(eEmpleado [], int, eSector[], int );
void modificarE(eEmpleado vec[], int tam, eSector[], int);
void mostrarE(eEmpleado e, eSector [], int);
void mostrarEs(eEmpleado vec[], int tam, eSector[], int);
void hardCodear(eEmpleado vec[], int tam);
void pedirDatos(eEmpleado[], int , int);
void menuInformes(eEmpleado[], int , eSector[], int);
void  menuAlmuerzos(eEmpleado[], int, eSector[], int, eComida[], int, eAlmuerzo[],int);

int main()
{
    eEmpleado empleados[TAM];
    inicializarE(empleados,TAM);
    eSector sectores[] ={
        {1,"Legal"},{2,"RRHH"},{3,"Economia"},{4,"Obrero"}
        };
        //29/05
    eComida menu[] = {{1,"Milanesas"},{2,"Fideos"},{3,"Pizza"},{4,"Hamburgesa"},{5,"Ensalada"},{6,"Pollo"}, {7,"Tarta"}
    };

     eAlmuerzo listaAlmuerzos[20]=
    {
        {100, 1234, 1, {10,12,2019}},
        {101, 2222, 2, {11,12,2019}},
        {102, 3333, 3, {12,12,2019}},
        {103, 6578, 1, {12,12,2019}},
        {104, 4444, 2, {12,12,2019}},
        {105, 9040, 2, {13,12,2019}},
        {106, 1234, 4, {14,12,2019}},
        {107, 7439, 1, {14,12,2019}},
        {108, 5555, 5, {14,12,2019}},
        {109, 9040, 5, {15,12,2019}},
        {110, 7439, 3, {15,12,2019}},
        {111, 6578, 5, {16,12,2019}},
        {112, 2211, 7, {17,12,2019}},
        {113, 1111, 3, {17,12,2019}},
        {114, 7654, 2, {17,12,2019}},
        {115, 2224, 1, {18,12,2019}},
        {116, 7654, 2, {19,12,2019}},
        {117, 1111, 3, {19,12,2019}},
        {118, 2224, 6, {20,12,2019}},
        {119, 2222, 2, {21,12,2019}}
    };

    hardCodear(empleados,7);
    int opcion;
do
    {

        printf("1-Dar de Alta\n");
        printf("2-Mostrar Empleados\n");
        printf("3-Informes\n");
        printf("4-Modificar\n");
        printf("5-Dar de Baja\n");
        printf("6.Ingresar al programa de almuerzos\n");
        printf("7-Salir\n");
        printf("Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            altaE(empleados,TAM,sectores, TAMSEC);
            break;
        case 2:
            menuMostrarE(empleados,TAM,sectores, TAMSEC);
            break;
        case 3:
            menuInformes(empleados, TAM, sectores, TAMSEC);
            break;
        case 4:
            modificarE(empleados,TAM,sectores, TAMSEC);
            break;
        case 5:
            bajaE(empleados,TAM,sectores,TAMSEC);
            break;
        case 6:
            menuAlmuerzos(empleados, TAM, sectores, TAMSEC, menu, TAMMENU,listaAlmuerzos,TAMALM );
            break;
        case 7:
            printf("Hasta luego!\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }

        system("pause");
        system("cls");

    }
    while(opcion !=7);

    return 0;
}
