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
//*********************************************************************************************************************
/**
**/
void menuInformes(eEmpleado[], int , eSector[], int);
/**
**/
void empleadosPorSector(eEmpleado vec[], int tam, eSector vecSec[], int tamSec);
/**
**/
void empleadoMasGana(eEmpleado vec[], int tam, eSector vecSec[], int tamSec);
/**
**/
void empleadoMasAntiguo(eEmpleado vec[], int tam, eSector vecSec[], int tamSec);
/**
**/
void sectorConMasEmpleados(eEmpleado vec[], int tam, eSector vecSec[], int tamSec);
