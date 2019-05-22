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
}eColor;
//*
/**
**/
void programaColores(eColor vecCol[], int tamCol);
//************************************************
/**
**/
void altaColores(eColor vecCol[], int tamCol);
//************************************************
/**
**/
int generarIdCol();
//************************************************
/**
**/
int buscarLibreCol(eColor vec[], int tam);
//************************************************
/**
**/
void pedirDatosCol(eColor vecCol[], int tamCol, int indice);
//************************************************
/**
**/
void mostrarCol(eColor vecCol);
//************************************************
/**
**/
void inicializarColores(eColor vec[] , int tam);
//***********************************************
/**
**/
void modificarColor(eColor vec[], int TAM);
//************************************************
/**
**/
void bajaColor(eColor vec[], int tam);
//************************************************
/**
**/
void hardCodearColores(eColor vec[], int tam);
//***********************************************
/**
**/
void mostrarColores(eColor vec[], int tam);
//***********************************************
