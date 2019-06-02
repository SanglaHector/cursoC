#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "punteros.h"
#define TAM 1000
#define OCUPADO 1
#define VACIO 0


int buscarLibre(eEmpleado* vec, int tam);
int buscarE(eEmpleado* vec, int tam , int clave);
void inicializarE(eEmpleado*, int tam );
void altaE(eEmpleado*, int );
void bajaE(eEmpleado* , int );
void modificarE(eEmpleado* vec, int tam);
void mostrarE(eEmpleado* e);
void mostrarEs(eEmpleado *vec, int tam);
void hardCodear(eEmpleado* vec, int tam);
int buscarLleno(eEmpleado* vec,  int tam);
void menuModificar(eEmpleado* , int,int);
void listarAlfabeticamente(eEmpleado* vec,int tam);
void totalizarSalarios(eEmpleado* vec,int tam);
void formatearNombre(eEmpleado* vec, int tam, int indice);
void menuInformes(eEmpleado* vec, int tam);
eEmpleado* new_EmpleadoParam(int leg, char* nombre, char sexo, float sueldo);

int main()
{
    eEmpleado empleados[TAM];
    eEmpleado* pEmpleado;
    pEmpleado = &empleados;
    inicializarE(pEmpleado,TAM);
    hardCodear(empleados,8);
    int opcion;
    int vacio;
do
    {

        system("cls");
        printf("1-Dar de Alta\n");
        printf("2-Modificar\n");
        printf("3-Dar de bajan\n");
        printf("4-Informar\n");
        printf("5-Salida\n");
        printf("Ingrese una opcion:  ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            altaE(pEmpleado,TAM);
            break;
        case 2:
            vacio = buscarLleno(empleados,TAM);
            if( vacio == OCUPADO){
                modificarE(empleados,TAM);
            }else {
            printf("\nDebe ingresar un usuario antes de ingresar a esta opcion.");
            }
            break;
        case 3:
            vacio = buscarLleno(empleados,TAM);
            if( vacio == OCUPADO){
                bajaE(empleados,TAM);
            }else {
            printf("\nDebe ingresar un usuario antes de ingresar a esta opcion.");
            }
            break;
        case 4:
            vacio = buscarLleno(empleados,TAM);
            if( vacio == OCUPADO){
                menuInformes(empleados, TAM);
            }else {
            printf("\nDebe ingresar un usuario antes de ingresar a esta opcion.");
            }
            break;
        case 5:
            printf("Hasta luego!\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }

        system("pause");
        system("cls");

    }
    while(opcion !=5);

    return 0;
}
