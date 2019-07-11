#include "LinkedList.h"
#ifndef __EMPLEADOS
#define __EMPLEADOS

typedef struct
{
    int id;
    char dominio[7];
    int anio;
    char tipo;
}eDominio;
#endif

eDominio* d_new();
eDominio* d_newParametros(char* idStr,char* dominioStr,char* anioStr,char* tipoStr);

int d_setId(eDominio* this,int id);
int d_getId(eDominio* this,int* id);
int d_setDominio(eDominio* this,char* nombre);
int d_getNombre(eDominio* this,char* nombre);
int d_setAnio(eDominio* this,int anio);
int d_getAnio(eDominio* this,int* anio);
int d_setTipo(eDominio* this,char tipo);
int d_getTipo(eDominio* this,char* tipo);

int d_list(LinkedList* lista);
int d_listConTipo(LinkedList* lista);
void mostrarElemento(eDominio* elemento);
