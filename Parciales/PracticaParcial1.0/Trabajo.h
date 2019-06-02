#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "fecha.h"
#define OCUPADO 1
#define VACIO 0


typedef struct{
    int id;//tiket
    char patente[6];
    int idServicio;
    eFecha fecha;
    int estado;
}eTrabajo;


/**
**/
int generarIdTrabajos();
//********************************************
/**
**/
int buscarLibreTra(eTrabajo vec[], int tam);
//**********************************************
/**
**/
void inicializarTrabajos(eTrabajo vecTra[],int tamTra);
//***********************************************
/**
**/
void hardCodearTrabajos(eTrabajo vec[], int tam);
//*************************************************
/**
**/
int generarIdTra();
