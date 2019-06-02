#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define OCUPADO 1
#define VACIO 0



typedef struct{

    int id;
    char patente[6];
    int idMarca;
    int idColor;
    int modelo;
    int idCliente;
    int estado;
}eAuto;

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
//*********************
/**
**/
int buscarE(eAuto vec[], int tam , int clave);

//********************************
/**
**/
void hardCodearAutos(eAuto vec[], int tam);
//**********************************

