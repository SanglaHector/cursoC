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

/**
**/
int buscarLibre(eEmpleado vec[], int tam);
/**
**/
int buscarE(eEmpleado vec[], int tam , int clave);
/**
**/
void inicializarE(eEmpleado [], int tam );
/**
**/
void altaE(eEmpleado [], int);
/**
**/
void bajaE(eEmpleado [], int);
/**
**/
void modificarE(eEmpleado vec[], int tam);
/**
**/
void mostrarE(eEmpleado e);
/**
**/
void mostrarEs(eEmpleado vec[], int tam);
/**
**/
void hardCodear(eEmpleado vec[], int tam);
/**
**/
int validarInt(int num,int min,int max);
/**
**/
int buscarLleno(eEmpleado vec[],  int tam);
/**
**/
void menuModificar(eEmpleado vec[],int);
/**
**/
void menuInformes(eEmpleado vec[], int tam);
/**
**/
void listarAlfabeticamente(eEmpleado vec[],int tam);
/**
**/
void totalizarSalarios(eEmpleado vec[],int tam);
/**
**/
