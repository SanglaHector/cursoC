#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "Compra.h"
#include "validaciones.h"


Compra* compra_new()
{
    Compra* this = (Compra*) malloc(sizeof(Compra));
    if(this != NULL)
    {
        strcpy(this->nombreCliente, "");
        this->idProducto = 0;
        this->precioUnitario = 0;
        this->unidades = 0;
        this->iva = 0;
        this->montoTotal = 0;
    }
    return this;
}
//*************************************************************
Compra* compra_newParametros(char* nombreStr,char* idStr,char* precioStr, char* unidadesStr,char* ivaStr)
{
    Compra* this ;
        if (idStr != NULL && nombreStr != NULL && precioStr != NULL && unidadesStr != NULL && ivaStr != NULL)
        {
            this  = compra_new();

            if( this != NULL){

            if( !compra_setId(this,atoi(idStr))||
                !compra_setNombre(this, nombreStr) ||
                !compra_setPrecio(this, atof(precioStr)) ||
                !compra_setUnidades(this, atoi(unidadesStr))||
                !compra_setIva(this,atof(ivaStr)))
                       {
                            free(this);
                            this = NULL;
                       }
            }
        }
        return this;
}
//*********************************************************************************************************
int compra_setNombre(Compra* this,char nombre[128])
{
    int retorno = 0;
    if(this != NULL && nombre != NULL && strlen(nombre) >= 2 && validarNombre(nombre))// agregar al ir una funcion que valide nombre
    {
        formatearNombre(nombre);
        strcpy(this->nombreCliente,nombre);
        retorno = 1;
    }
    return retorno;
}
//***************
int compra_setId(Compra* this,int idProducto)
{
    int retorno = 0;
    if(this != NULL && idProducto > 0)
    {
        this->idProducto = idProducto;
        retorno = 1;
    }
    return retorno;
}
//**************
int compra_setPrecio(Compra* this, float precio)
{
    int retorno = 0;
    if(this != NULL && precio > 0 )
    {
        this->precioUnitario =  precio;
        retorno = 1;
    }
    return retorno;
}
//****************
int compra_setUnidades(Compra* this, int unidades)
{
    int retorno = 0;
     if(this != NULL && unidades > 0 )
    {
        this->unidades =  unidades;
        retorno = 1;
    }
    return retorno;
}
//**************
int compra_setIva(Compra* this, float iva)
{
    int retorno = 0;
     if(this != NULL && iva > 0 )
    {
        this->iva =  iva;
        retorno = 1;
    }
    return retorno;
}
//*************
/*int compra_setMontonTotal(Compra* this, float monto)
{
    int retorno = 0;
     if(this != NULL && monto > 0 )
    {
        this->montoTotal =  monto;
        retorno = 1;
    }
    return retorno;
}*/
//*************
int compras_mostrar(LinkedList* pArrayList)
{
    int retorno = 0;
    if(pArrayList != NULL)
    {
        Compra* auxCompra;
        int contador = 0;
        int tope= ll_len(pArrayList);
        for( int i = 0; i < tope; i ++)
        {
            auxCompra=(Compra*)ll_get(pArrayList,i);
            mostrarCompra(auxCompra);
            contador ++;
            if(contador == 200)
            {
                printf("\nEl registro de compras es muy grande ser visualizado en su totalidad");
                printf("\n");
                system("pause");
                contador = 0;
            }
        }
    }
    retorno = 1;
    return retorno;
}

//********************************
void mostrarCompra(LinkedList* lista)
{
    int auxId;
    char auxNombreCliente[100];
    float auxPrecio;
    int auxUnidades;
    float auxIva;
    compra_getId(lista,&auxId);
    compra_getNombre(lista,auxNombreCliente);
    compra_getPrecio(lista,&auxPrecio);
    compra_getUnidades(lista,&auxUnidades);
    compra_getIva(lista,&auxIva);
    printf("\n%10d %10s %10f %10d %10f",auxId,auxNombreCliente,auxPrecio,auxUnidades,auxIva);
}
//********************************
int compra_getId(Compra* this,int* id)
{
    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->idProducto;
        todoOk = 1;
    }
    return todoOk;
}
//***************************
int compra_getNombre(Compra* this,char* nombre)
{
   int todoOk  = 0;
    if(this != NULL && nombre != NULL )
    {
        strcpy(nombre,this->nombreCliente);
        todoOk = 1;
    }
    return todoOk;
}
//**************************
int compra_getPrecio(Compra* this,float* precio)
{
    int todoOk = 0;
    if(this != NULL && precio != NULL)
    {
        *precio = this->precioUnitario;
        todoOk = 1;
    }
    return todoOk;
}
//******************************
int compra_getUnidades(Compra* this,int* unidades)
{
    int todoOk = 0;
    if(this != NULL && unidades != NULL)
    {
        *unidades = this->unidades;
        todoOk = 1;
    }
    return todoOk;
}
//************************************
int compra_getIva(Compra* this,float* iva)
{
    int todoOk = 0;
    if(this != NULL && iva != NULL)
    {
        *iva = this->iva;
        todoOk = 1;
    }
    return todoOk;
}
//*************************************
void com_calcularMonto(void* p)
{

}
