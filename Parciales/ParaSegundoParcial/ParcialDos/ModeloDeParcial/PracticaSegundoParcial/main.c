/**
1) Realizar un programa que lea un archivo (cuyo nombre se pasa como parámetro por
línea de comandos), con los datos de los dominios del registro automotor, guardándolos
en un linkedList de entidades eDominio.
2) Listar todos los vehiculos ordenados por dominio Datos:
Utilizar getters, setters y constructores, según corresponda.
 eDominio
o id
o dominio
o anio
o tipo
 data.csv
 auto.csv
 moto.csv
NOTAS:
Nota 0: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las
reglas de estilo de la cátedra.
Nota 1: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Nota 2: Se deberán utilizar las bibliotecas linkedList y dominio (desarrollando las funciones setter y getter
necesarias).
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "parser.h"
#include "Dominio.h"
int ordenarPorDominio(void* elemento1, void* elemento2);
int setearTipo(eDominio* elemento1);
int evaluarTipo(eDominio* elemento,char tipo);
int main()
{

    LinkedList* lista;
    lista = ll_newLinkedList();
    char path[100];

    FILE* f;
    FILE* pfMotos;
    FILE* pfAUTOS;

    eDominio* pElemento;

      int opcion = 0;
    do{
        printf("\n1.Cargar Datos");
        printf("\n2.Ordenar datos y mostrar");
        printf("\n3.Implementar tipo");
        printf("\n4.Salir\n");
        printf("\n5.Salir\n");
        scanf("%d", &opcion);


        switch(opcion)
        {
            case 1:
                printf("\nIngrese el nombre del archivo que quiera cargar.");
                scanf("%s", path);

                if((f = fopen(path,"r")) != NULL)
                {
                    if(parser_FromText(f,lista) != 0)
                    {
                        printf("\nLectura correcta!! \n");
                        d_list(lista);

                    }else
                    {
                        printf("\nError en parceo");
                    }
                }else
                {
                    printf("\nError al abrir al archivo");
                }
                break;
            case 2:
                if(ll_len(lista) > 0)
                {
                    ll_sort(lista,ordenarPorDominio,1);
                    d_list(lista);
                }
                break;
            case 3:
                if(ll_len(lista) > 0)
                {
                    ll_map(lista,setearTipo);
                    d_listConTipo(lista);
                }
                break;
            case 4:

                pfMotos = fopen("Motos.csv","w");
                pfAUTOS = fopen("Autos.csv","w");
                if(pfMotos != NULL && pfAUTOS != NULL )
                {
                    LinkedList* listaMotos = ll_newLinkedList();
                    LinkedList* listaAutos = ll_newLinkedList();
                    listaMotos = ll_filterPAraDominio(lista,evaluarTipo,'M');
                    listaAutos = ll_filterPAraDominio(lista,evaluarTipo,'A');
                    printf("\nLongitus de lista Motos: %d",ll_len(listaMotos));
                    if(listaMotos != NULL)
                    {
                        fprintf(pfMotos,"%s,%s,%s,%s\n","id","Domino","anio","tipo");

                        for(int i = 0; i < ll_len(listaMotos); i++)
                        {
                            pElemento = (eDominio*)ll_get(listaMotos, i);
                            fprintf(pfMotos,"%d,%s,%d,%c\n",pElemento->id,pElemento->dominio,pElemento->anio,pElemento->tipo);
                        }
                        fclose(pfMotos);
                    }

                    if(listaAutos != NULL)
                    {
                        fprintf(pfAUTOS,"%s,%s,%s,%s\n","id","Dominio","Anio","tipo");

                        for(int i = 0; i < ll_len(listaAutos); i++)
                        {
                            pElemento = (eDominio*)ll_get((listaAutos),i);
                            fprintf(pfAUTOS,"%d,%s,%d%,%c\n",pElemento->id, pElemento->dominio,pElemento->anio,pElemento->tipo);
                        }
                        fclose(pfAUTOS);
                    }

                }
                break;

        }
    }while(opcion != 5);
}
//*********************************************************************
int ordenarPorDominio(void* elemento1, void* elemento2)
{
    int retorno = 0;
    if(elemento1 != NULL && elemento1 != NULL)
    {

        char dominioUno[7];
        char dominioDos[7];
        d_getNombre(elemento1,dominioUno);
        d_getNombre(elemento2,dominioDos);

        if(stricmp( dominioUno , dominioDos) > 0 )
            {

             retorno = 1;
            }
           else  if(stricmp( dominioUno , dominioDos) < 0 )
            {
             retorno = -1;
            }else
            {
                retorno = 0;
            }

    }
        return retorno;
}
//**************************************************
int setearTipo(eDominio* elemento1)
{
    int retorno = 0;
//    char tipoA[1] = "A";
//    char tipoM[1] = "M";
    if(elemento1 != NULL )
    {
        char dominioUno[7];
        d_getNombre(elemento1,dominioUno);

        if(isdigit(dominioUno[0]) == 0)
        {
            elemento1->tipo = 'A';
        }else
        {
        //    printf("\nentro x moto");
            elemento1->tipo = 'M';
        }
        retorno = 1;
     //   mostrarElementoConTipo(elemento1);
    }

   // printf("\nel elemento es de tipo: %c",elemento1->tipo);hasta aca lo hace bien
    return retorno;
}
//*************************************************
int evaluarTipo(eDominio* elemento,char tipo)
{
    int retorno = 0;
    if( elemento != NULL && tipo != NULL)
    {
        if(elemento->tipo == tipo)
        {
            retorno = 1;
        }
    }

    return retorno;
}
