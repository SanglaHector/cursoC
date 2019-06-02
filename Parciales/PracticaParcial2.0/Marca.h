#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define OCUPADO 1
#define VACIO 0

typedef struct{
    int id;
    char descripcion[20];
    int estado;
}eMarca;

/**
**/
void programaMarcas(eMarca vecMar[], int tamMar);
//************************************************
/**
**/
void altaMarcas(eMarca vecMar[], int tamMar);
//************************************************
/**
**/
int generarIdMarca();
//************************************************
/**
**/
int buscarLibreMacar(eMarca vec[], int tam);
//************************************************
/**
**/
void pedirDatosMarca(eMarca vecMar[], int tamMar, int indice);
//************************************************
/**
**/
void mostrarMarca(eMarca vecMar);
//************************************************
/**
**/
void inicializarMarcas(eMarca vec[] , int tam);
//***********************************************
/**
**/
void modificarMarca(eMarca vec[],  int tam);
//************************************************
/**
**/
void bajaMarca(eMarca vec[], int tam);
//************************************************
/**
**/
void hardCodearMarcas(eMarca vec[], int tam);
//***********************************************
/**
**/
void mostrarMarcas(eMarca vec[], int tam);
//***********************************************
