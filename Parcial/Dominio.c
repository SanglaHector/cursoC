#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Dominio.h"
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
    int* pId;
   // printf("\nid: %d",this->id);//el id que le paso esta mal
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        /*printf("\nthis->ID %d",this->id);
        printf("\nid %d", (*id));*/
        todoOk = 1;
    }
    return todoOk;
}
//****************
int d_setIdProblema(eDominio* this,int id)// devuelve 1 si todo ok o 0 si no esta todo ok // esta bien
{
    int todoOk = 0;
    if(this != NULL && id > 0)
    {
        this->idProblema = id;

        /*printf("\nthis->IDproblema %d",this->idProblema);
        printf("\nid %d", id);*/  //bien
        todoOk = 1;
    }

    return todoOk;
}
//*************************
int d_getIdProblema(eDominio* this,int* id)//SIRVE PARA OBTENER EL ID O LEERLO. GEtId me carga el id por referencia

{
    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->idProblema;
        todoOk = 1;
    }
    return todoOk;
}
//*******************************************************************************************************************************
int d_setFecha(eDominio* this,char* fecha)
{
    int todoOk  = 0;

    if(this != NULL && fecha != NULL /*&& strlen(dominio) == 6*/ )// agregar al ir una funcion que valide nombre
    {
        //formatearNombre(dominio);
        strcpy(this->fecha,fecha);
        todoOk = 1;
    }
    return todoOk;
}
//*******************************************************************************************************************************
int d_getFecha(eDominio* this,char* fecha)

{
    int todoOk  = 0;
    if(this != NULL && fecha != NULL && this != NULL)
    {
        strcpy(fecha,this->fecha);
        todoOk = 1;
    }
    return todoOk;
}
//**********************************
int d_getProblema(eDominio* this,char* problema)

{
    int todoOk  = 0;
    if(this != NULL && problema != NULL && this != NULL)
    {
        strcpy(problema,this->problemaSolucionado);
        todoOk = 1;
    }
    return todoOk;
}
//*******************************************************************************************************************************
int d_setCliente(eDominio* this,int cliente)
{
    int todoOk  = 0;
    if(this != NULL && cliente > 0 )// agregar al if una funcion que valide int
    {
        this->numeroCliente = cliente;
        todoOk = 1;
    }
    return todoOk;
}
//*********
int d_getCliente(eDominio* this,int* cliente)//SIRVE PARA OBTENER EL ID O LEERLO. GEtId me carga el id por referencia
{
    int todoOk = 0;
    if(this != NULL && cliente != NULL)
    {
        *cliente = this->numeroCliente;
        todoOk = 1;
    }
    return todoOk;

}
//*******************************************************************************************************************************
int d_setProblema(eDominio* this,char* problema)
{
    int todoOk  = 0;
    if(this != NULL && problema != NULL && strlen(problema) >= 2 )// agregar al ir una funcion que valide nombre
    {
        strcpy(this->problemaSolucionado,problema);
        todoOk = 1;
    }
    return todoOk;
}
//****************
/*int d_getTipo(eDominio* this,char* tipo)
{
    int todoOk  = 0;
    if(this != NULL && tipo != NULL )
    {
      tipo = this->tipo;
      //printf("\nEl tipo del elemento dentro del getter es %c", this->tipo);//funciona
        todoOk = 1;
    }
    return todoOk;
}*/
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
        strcpy(this->fecha,"");
        this->numeroCliente = 0;
        this->idProblema = 0;
        strcpy(this->problemaSolucionado,"");
    }
    return this;
}
//*******************************************************************************************************************************
eDominio* d_newParametros(char* idStr,char* fechaStr,char* clienteStr,char* idProblema,char* problemaStr)//viene como punteros a char
{
    eDominio* this ;
    if (idStr != NULL && fechaStr != NULL && clienteStr != NULL && problemaStr != NULL && idProblema != NULL)
    {
        this  = d_new();
        if( this != NULL)
        {
            if( !d_setId(this, atoi(idStr))||
                    !d_setFecha(this, fechaStr) ||
                    !d_setCliente(this, atoi(clienteStr)) ||
                !d_setProblema(this,problemaStr) ||
                !d_setIdProblema(this,atoi(idProblema)) )

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
    char auxFecha[10];
    int auxCliente;
    int idProblema;
    char auxProblema[2];
    if (elemento != NULL)
    {
        d_getId(elemento,&auxId);

        d_getFecha(elemento,auxFecha);
        d_getCliente(elemento,&auxCliente);
        d_getIdProblema(elemento,&idProblema);
        d_getProblema(elemento,auxProblema);
        printf("\n%10d %10s%10d%10d%10s",elemento->id,auxFecha,auxCliente,elemento->idProblema,auxProblema);
       //printf("\n%d",auxId);
//       printf("\n%d",auxCliente);
//       printf("\n%d",idProblema);
//       printf("\n%s",auxFecha);
//       printf("\n%s",auxProblema);
    }

}
//******
/*void mostrarElementoConTipo(eDominio* elemento)
{
    int auxId;
    char auxDom[100];
    int auxAnio;
    char auxTipo;
    if (elemento != NULL)
    {
        d_getAnio(elemento,&auxAnio);
        d_getNombre(elemento,auxDom);
        d_getTipo(elemento,&auxTipo);
        d_getId(elemento,&auxId);
        printf("\n%10d%10s%10d%10c",auxId,auxDom,auxAnio,elemento->tipo);
    }
}*/

int d_listConDescripcion(LinkedList* lista)
{
    eDominio* elemento;
    int contador = 0;
    int tope= ll_len(lista);
    for( int i = 0; i < tope; i ++)
    {
        elemento=(eDominio*)ll_get(lista,i);
        if(elemento != NULL)
        {
            mostrarElementoConDescripcion(elemento);
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

void mostrarElementoConDescripcion(eDominio* elemento)
{
    int auxId;
    char auxFecha[10];
    int auxCliente;
    int idProblema;
    char auxProblema[2];
    char descripcion[100];
    if (elemento != NULL)
    {
        d_getId(elemento,&auxId);

        d_getFecha(elemento,auxFecha);
        d_getCliente(elemento,&auxCliente);
        //d_getIdProblema(elemento,&idProblema);
        idProblema = elemento->idProblema;
        d_getProblema(elemento,auxProblema);

        if(idProblema == 1)
        {
            strcpy(descripcion,"No enciende PC");
        }else if(idProblema == 2)

        {
            strcpy(descripcion,"No funciona mouse");
        }else if(idProblema == 3)

        {
            strcpy(descripcion,"No funciona teclado");
        }else if(idProblema == 4)

        {
            strcpy(descripcion,"No hay internet");
        }else if(idProblema == 5)

        {
            strcpy(descripcion,"No funciona telefono");
        }else
        {
            strcpy(descripcion,"Id no valido");
        }

        printf("\n%10d %10s%10d%20s%20s",elemento->id,auxFecha,auxCliente,descripcion,auxProblema);

    }

}
