#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define OCUPADO 1
#define VACIO 0

typedef struct{

    int id;
    char nombre[20];
    char apellido [20];
    float sueldo;
    int sector;
    int estado;
}eEmpleado;
//***************************************************
/**
* \param vec[] eEmpleado
* \param tam int
* \return int
**/
int buscarLibre(eEmpleado vec[], int tam);
//****************************************************
/**
* \param vec[] eEmpleado
* \param tam int
* \param clave int
* \return int
**/
int buscarE(eEmpleado vec[], int tam , int clave);
//****************************************************
/**
* \param vec[] eEmpleado
* \param tam int
* \return void
**/
void inicializarE(eEmpleado [], int tam );
//****************************************************
/**
* \param vec[] eEmpleado
* \param tam int
* \return void
**/
void altaE(eEmpleado [], int);
//****************************************************
/**
* \param vec[] eEmpleado
* \param tam int
* \return void
**/
void bajaE(eEmpleado [], int);
//****************************************************
/**
* \param vec[] eEmpleado
* \param tam int
* \return void
**/
void modificarE(eEmpleado vec[], int tam);
//****************************************************
/**
* \param e eEmpleado
* \return void
**/
void mostrarE(eEmpleado e);
//***************************************************
/**
* \param vec[] eEmpleado
* \param tam int
* \return void
**/
void mostrarEs(eEmpleado vec[], int tam);
//***************************************************
/**
* \param vec[] eEmpleado
* \param tam int
* \return void
**/
void hardCodear(eEmpleado vec[], int tam);
//***************************************************
/**
* \param vec[] eEmpleado
* \param tam int
* \return int
**/
int buscarLleno(eEmpleado vec[],  int tam);
//**************************************************
/**
* \param vec[] eEmpleado
* \param int
* \param int
* \return void
**/
void menuModificar(eEmpleado vec[],int,int);
//**************************************************
/**
* \param vec[] eEmpleado
* \param tam int
* \return void
**/
void menuInformes(eEmpleado vec[], int tam);
//***************************************************
/**
* \param vec[] eEmpleado
* \param tam int
* \return void
**/
void listarAlfabeticamente(eEmpleado vec[],int tam);
//***************************************************
/**
* \param vec[] eEmpleado
* \param int tam
* \return void
**/
void totalizarSalarios(eEmpleado vec[],int tam);
//**************************************************
/**
* \param vec[] eEmpleado
* \param tam int
* \param indice int
* \return void
**/
void formatearNombre(eEmpleado vec[], int tam, int indice);
