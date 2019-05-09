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
//*****************************************************
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
void altaE(eEmpleado [], int , eSector[], int);
/**
**/
void bajaE(eEmpleado [], int ,eSector[], int );
/**
**/
void modificarE(eEmpleado vec[], int tam, eSector[], int);
/**
**/
void mostrarE(eEmpleado e, eSector[], int);
/**
**/
void menuModificar(eEmpleado vec[], int indice, int tam,eSector vecSec[], int tamSec);
/**
**/
void mostrarEs(eEmpleado vec[], int tam, eSector[], int);
/**
**/
void hardCodear(eEmpleado vec[], int tam);
/**
**/
void pedirDatos(eEmpleado vec[], int tam, int indice);
/**
**/
void listarAlfabeticamente(eEmpleado vec[],int tam,eSector vecSec[],int tamSec);
/**
**/
void formatearNombre(eEmpleado vec[], int tam, int indice);
/**
**/
void empleadosPorLegajo(eEmpleado vec[], int tam, eSector vecSec[],int tamSec);
/**
**/
void empleadosAlfabeticamente(eEmpleado vec[], int tam, eSector vecSec[], int tamSec);
/**
**/
void empleadosPorSectorYLegajo(eEmpleado vec[], int tam, eSector vecSec[], int tamSec);
/**
**/
void empleadosMasculinoAlfa(eEmpleado vec[], int tam, eSector vecSec[], int tamSec);
/**
**/
void empleadosFemenimoPorlegajo(eEmpleado vec[], int tam, eSector vecSec[], int tamSec);

