#include "Employee.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "LinkedDos.h"
/** \brief aplica una funcion a todos los elementos de la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return LinkedList* de una lista nueva con los elementos afectados por la funcion
 */
LinkedList* ll_map(LinkedList* this,int *pFunc(void*))
{
    LinkedList* nuevaLinked = ll_newLinkedList();
    if ( this != NULL && pFunc != NULL)
    {
        Node* pNode = (Node*)malloc(sizeof(Node*));
        pNode = this -> pFirstNode;
        for(int i = 0; i < ll_len(this); i++)
        {
            if(pFunc(pNode->pElement) == 1)
            {
                ll_add(nuevaLinked,pNode->pElement);
            }else
            {
                break;
            }
            pNode = pNode->pNextNode;
        }
    }
    return nuevaLinked;
}

/** \brief aplica una funcion a todos los elementos de la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return LinkedList* de una lista nueva con los elementos afectados por la funcion
 */
LinkedList* ll_filter(LinkedList* this, int *pFunc(void*))
{
    LinkedList* cloneLinked = ll_newLinkedList();
    if ( this != NULL && pFunc != NULL)
    {
        Node* pNode = (Node*)malloc(sizeof(Node*));
        pNode = this -> pFirstNode;
        for(int i = 0; i < ll_len(this); i++)
        {
            if(pFunc(pNode->pElement) == 1)
            {
                ll_add(cloneLinked,pNode->pElement);
            }
            pNode = pNode->pNextNode;
        }
    }
    return cloneLinked;
}
//***************************************************************

LinkedList* ll_reduce (LinkedList* this, int *pFunc(void*))
{
    int retorno =-1;
    void* pElemento;
    int longitud = ll_len(this);

    if (this!= NULL && pFunc != NULL)
    {
        for ( int i=0; i<longitud; i++)
        {
            pElemento = ll_get(this,i);

            if(pFunc(pElemento)==1)
            {
                ll_remove(this,i);
                i--;
                longitud--;
            }
        }
        retorno=0;
    }
    return retorno;
}
//***************************************************************************************************************************************************
