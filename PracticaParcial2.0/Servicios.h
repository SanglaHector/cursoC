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
    float precio;
    int estado;
}eServicio;
//******************
/**
**/
void listarServicios(eServicio vecSer[], int tamSer);
//*******************
/**
**/
void programaServicios(eServicio vecSer[], int tamSer);
//************************************************
/**
**/
void altaServicios(eServicio vecSer[], int tamSer);
//************************************************
/**
**/
int generarIdServicio();
//************************************************
/**
**/
int buscarLibreServicio(eServicio vec[], int tam);
//************************************************
/**
**/
void pedirDatosServicio(eServicio vecSer[], int tamSer, int indice);
//************************************************
/**
**/
void mostrarServicio(eServicio vecSer);
//************************************************
/**
**/
void inicializarServicios(eServicio vec[] , int tam);
//***********************************************
/**
**/
void modificarServicio(eServicio vec[],  int tam);
//************************************************
/**
**/
void bajaServicio(eServicio vec[], int tam);
//************************************************
/**
**/
void hardCodearServicios(eServicio vec[], int tam);
//************************************************
/**
**/
void mostrarServicios(eServicio vec[], int tam);
