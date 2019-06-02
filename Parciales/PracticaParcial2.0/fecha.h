#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define OCUPADO 1
#define VACIO 0

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

/**
**/
int validarFecha(int dia, int mes, int anio);
//*******************************************
/**
**/
int ordenPorFecha(eFecha fechaUno, eFecha fechaDos);
//*******************************************
