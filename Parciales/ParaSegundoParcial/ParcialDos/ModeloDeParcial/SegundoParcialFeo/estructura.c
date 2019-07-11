
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "estructura.h"
#include "LinkedList.h"

int d_setId(eDominio* this,int id)// devuelve 1 si todo ok o 0 si no esta todo ok
{
    int todoOk = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}
//*******************************************************************************************************************************
int d_getId(eDominio* this,int* id)//SIRVE PARA OBTENER EL ID O LEERLO. GEtId me carga el id por referencia
{
    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}
//*******************************************************************************************************************************
int d_setDominio(eDominio* this,char* dominio)
{
    int todoOk  = 0;

    if(this != NULL && dominio != NULL /*&& strlen(dominio) == 6*/ )// agregar al ir una funcion que valide nombre
    {
        //formatearNombre(dominio);
        strcpy(this->dominio,dominio);
        todoOk = 1;
    }
    return todoOk;
}
//*******************************************************************************************************************************
int d_getNombre(eDominio* this,char* dominio)
{
    int todoOk  = 0;
    if(this != NULL && dominio != NULL && this != NULL)
    {
        strcpy(dominio,this->dominio);
        todoOk = 1;
    }
    return todoOk;
}
//*******************************************************************************************************************************
int d_setAnio(eDominio* this,int anio)
{
    int todoOk  = 0;
    if(this != NULL && anio > 0 )// agregar al if una funcion que valide int
    {
        this->anio = anio;
        todoOk = 1;
    }
    return todoOk;
}
//*********
int d_getAnio(eDominio* this,int* anio)//SIRVE PARA OBTENER EL ID O LEERLO. GEtId me carga el id por referencia
{
    int todoOk = 0;
    if(this != NULL && anio != NULL)
    {
        *anio = this->anio;
        todoOk = 1;
    }
    return todoOk;

}
//*******************************************************************************************************************************
int d_setTipo(eDominio* this,char tipo)
{
    int todoOk  = 0;
    if(this != NULL && tipo != NULL /*&& strlen(tipo) >= 2 && validarNombre(tipo)*/)// agregar al ir una funcion que valide nombre
    {
        strcpy(this->tipo,tipo);
        todoOk = 1;
    }
    return todoOk;
}
//****************
int d_getTipo(eDominio* this,char* tipo)
{
    int todoOk  = 0;
    if(this != NULL && tipo != NULL )
    {
      //  strcpy(tipo,this->tipo);
      tipo = this->tipo;
        todoOk = 1;
    }
    return todoOk;
}
//*******************************************************************************************************************************
/*int e_getTipo(eDominio* this,char* tipo)
{
    int todoOk  = 0;
    if(this != NULL && horasTrabajadas != NULL && horasTrabajadas > 0)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}*/
//*******************************************************************************************************************************
eDominio* d_new()//uso this para seguir utilizando el mismo nombre pero tranquilamente podriautilizar cualwuier nombre
{
    eDominio* this = (eDominio*) malloc(sizeof(eDominio));
    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->dominio,"");
        this->anio = 0;
       // strcpy(this->tipo,"");
    }
    return this;
}
//*******************************************************************************************************************************
eDominio* d_newParametros(char* idStr,char* dominioStr,char* anioStr,char* tipoStr)//viene como punteros a char
{
    eDominio* this ;
    if (idStr != NULL && dominioStr != NULL && anioStr != NULL /*&& tipoStr != NULL*/)
    {
        this  = d_new();
        if( this != NULL)
        {

            if( !d_setId(this, atoi(idStr))||
                    !d_setDominio(this, dominioStr) ||
                    !d_setAnio(this, atoi(anioStr))/* ||
                !d_setTipo(this,tipoStr)*/)

            {

                free(this);
                this = NULL;
            }
        }
    }
    return this;
}
//******************
int d_list(LinkedList* lista)
{
    eDominio* elemento;
    int contador = 0;
    int tope= ll_len(lista);
    for( int i = 0; i < tope; i ++)
    {
        elemento=(eDominio*)ll_get(lista,i);
        if(elemento != NULL)
        {
            mostrarElemento(elemento);
            contador ++;
            if(contador == 200)
            {
                printf("\nEl registro de empleados es muy grande ser visualizado en su totalidad");
                printf("\n");
                system("pause");
                contador = 0;
            }
        }
    }
    return 1;
}
//******
void mostrarElemento(eDominio* elemento)
{
    int auxId;
    char auxDom[100];
    int auxAnio;
    char auxTipo[66];
    if (elemento != NULL)
    {
        d_getAnio(elemento,&auxAnio);
        d_getNombre(elemento,auxDom);
        //d_getTipo(elemento,auxTipo);
        d_getId(elemento,&auxId);
        printf("\n%10d%10s%10d",auxId,auxDom,auxAnio);
    }

}
int d_listConTipo(LinkedList* lista)
{
    eDominio* elemento;
    int contador = 0;
    int tope= ll_len(lista);
    for( int i = 0; i < tope; i ++)
    {
        elemento=(eDominio*)ll_get(lista,i);
        if(elemento != NULL)
        {
            mostrarElementoConTipo(elemento);
            contador ++;
            if(contador == 200)
            {
                printf("\nEl registro de empleados es muy grande ser visualizado en su totalidad");
                printf("\n");
                system("pause");
                contador = 0;
            }
        }
    }
    return 1;
}
//******
void mostrarElementoConTipo(eDominio* elemento)
{
    int auxId;
    char auxDom[100];
    int auxAnio;
    char auxTipo;
    if (elemento != NULL)
    {
        d_getAnio(elemento,&auxAnio);
        d_getNombre(elemento,auxDom);
        d_getTipo(elemento,auxTipo);
        d_getId(elemento,&auxId);
        printf("\n%10d%10s%10d%10s",auxId,auxDom,auxAnio,auxTipo);
    }
}
