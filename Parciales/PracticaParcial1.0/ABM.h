#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "Colores.h"
#include "Servicios.h"
#include "validaciones.h"
#include "Marca.h"
#include "auto.h"
#include "Trabajo.h"
#define OCUPADO 1
#define VACIO 0
//*****************************
/**
**/
void altaE(eAuto vec[], int tam, eMarca marVec[], int marSec,eColor colVec[],int tamCol);
//*******************************
/**
**/
void pedirDatos(eAuto vec[], int tam, int indice, eMarca vecMar[], int tamMar, eColor vecCol[], int tamCol);
//************************************
/**
**/
void bajaE(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol);
//********************************
/**
**/
void mostrarE(eAuto e, eMarca vecMar[], int tamMar, eColor vecCol[], int tamCol);
/**
**/
void modificarE(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol);
//*****************************
/**
**/
void menuModificar(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol,int indice);
//*******************************
/**
**/
int buscarLleno(eAuto vec[],  int tam);
//********************************
//********************************************************************************************************
//********************************LISTADOS****************************************************************
//********************************************************************************************************
/**
**/
void listarMarcas(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol);
//********************************
/**
**/
void listarColores(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol);
//********************************
/**
**/
void listarAutos(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol);
//********************************
//******************************************************************************************************
//********************************TRABAJO***************************************************************
//******************************************************************************************************
/**
**/
void mostrarTrabajos(eTrabajo vecTra[], int tamTra, eServicio vecSer[], int tamSer);
//********************************
/**
**/
void mostrarTrabajo(eTrabajo vecTra, eServicio vecSer[], int tamSer);
//*********************************
/**
**/
void altaTrabajo(eAuto vec[], int tam,eServicio vecSer[], int tamSer,eTrabajo vecTra[], int tamTra);
//*********************************

