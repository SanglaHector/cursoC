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

