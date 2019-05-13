#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "Trabajo.h"
#include "Colores.h"
#include "Servicios.h"
#include "validaciones.h"
#include "Marca.h"
#define OCUPADO 1
#define VACIO 0


typedef struct{

    int id;
    char patente[6];
    int idMarca;
    int idColor;
    int modelo;
    int estado;
}eAuto;



//***************************************************************
/**
**/
void altaE(eAuto vec[], int tam, eMarca marVec[], int marSec,eColor colVec[],int tamCol);
//********************************************************************
/**
**/
int buscarLibre(eAuto vec[], int tam);
//*****************
/**
**/
int generarIdAuto();
//**************
/**
**/
void inicializarE(eAuto vec[], int tam);
//*******************************
/**
**/
void pedirDatos(eAuto vec[], int tam, int indice, eMarca vecMar[], int tamMar, eColor vecCol[], int tamCol);
//********************************
/**
**/
//*********************************
void mostrarE(eAuto e, eMarca vecMar[], int tamMar, eColor vecCol[], int tamCol);
//************************************
/**
**/
void bajaE(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol);
//*********************
/**
**/
int buscarE(eAuto vec[], int tam , int clave);
//*******************************************
/**
**/
void modificarE(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol);
//***********************************************************************************************
/**
**/
void menuModificar(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol,int indice);
/**
**/
int buscarLleno(eAuto vec[],  int tam);
//********************************
/**
**/
void listarAutos(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol);
//***************
/**
**/
void altaTrabajo(eAuto vec[], int tam,eServicio vecSer[], int tamSer,eTrabajo vecTra[], int tamTra);
//**************************************
/**
**/
void mostrarTrabajos(eTrabajo vecTra[], int tamTra, eServicio vecSer[], int tamSer);
//***************************************
/**
**/
void mostrarTrabajo(eTrabajo vecTra, eServicio vecSer[], int tamSer);
//*********************************************************************
/**
**/
void hardCodearAutos(eAuto vec[], int tam);
