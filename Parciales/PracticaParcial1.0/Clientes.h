#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define OCUPADO 1
#define VACIO 0


typedef struct{

    int id;
    char nombre[20];
    char apellido[20];
    char sexo;
    int estado;
}eCliente;//Los campos nombre y apellido en realidad son clinte[50] para el parcial. sexo no esta tampoco
//*******************************************
/**
**/
void programaClientes(eCliente vecCli[], int tamCli);
//************************************************
/**
**/
void altaClientes(eCliente vecCli[], int tamCli);
//************************************************
/**
**/
int generarIdCli();
//************************************************
/**
**/
int buscarLibreCli(eCliente vec[], int tam);
//************************************************
/**
**/
void pedirDatosCli(eCliente vecCli[], int tamCli, int indice);
//************************************************
/**
**/
void mostrarCli(eCliente vecCli);
//************************************************
/**
**/
void inicializarClientes(eCliente vec[] , int tam);
//***********************************************
/**
**/
void modificarCliente(eCliente vec[], int TAM);
//************************************************
/**
**/
void bajaCliente(eCliente vec[], int tam);
//************************************************
/**
**/
void hardCodearClientes(eCliente vec[], int tam);
//***********************************************
/**
**/
void mostrarClientes(eCliente vec[], int tam);
//***********************************************

