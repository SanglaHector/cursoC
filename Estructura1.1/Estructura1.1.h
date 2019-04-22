#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define TAM 7
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
void altaE(eEmpleado [], int );
/**
**/
void bajaE(eEmpleado [], int );
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
