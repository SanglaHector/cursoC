#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux = this->size;
    }


    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
//    Node* pNode = NULL;
//    if(this!=NULL)
//    {
//        if(nodeIndex>=0&&nodeIndex<ll_len(this))
//        {
//            pNode=(Node*)malloc(sizeof(Node));
//            for(int i=0; i<=nodeIndex; i++)
//            {
//                if(i==0)
//                {
//                    pNode=this->pFirstNode;
//                }
//                else
//                {
//                    pNode=pNode->pNextNode;
//                }
//            }
//        }
//    }
//
//    return pNode;
    Node* pNode = NULL;

    if(this !=NULL)
    {
        if(nodeIndex >= 0 && nodeIndex < ll_len(this))
        {
            //me paro en el primer elemento
            pNode = this->pFirstNode;

            //voy a buscar la & del primer nodo
            for(int i=0; i<nodeIndex; i++)
            {
                pNode = pNode->pNextNode;

            }
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
//    int returnAux = -1;
//    if(this != NULL)
//    {
//        Node* newNode=(Node*)malloc(sizeof(Node));
//        Node* previousNode=(Node*)malloc(sizeof(Node));
//        Node* nextNode=(Node*)malloc(sizeof(Node));
//        if(nodeIndex == 0)
//        {
//            if(ll_len(this) == 0)
//            {
//                newNode->pElement = pElement;
//                newNode->pNextNode = NULL;
//            }
//            else
//            {
//                nextNode = this->pFirstNode;
//                newNode->pElement = pElement;
//                newNode->pNextNode = nextNode;
//            }
//            this->pFirstNode = newNode;
//        }
//        else
//        {
//            previousNode = getNode(this, nodeIndex -1);
//            if(nodeIndex == ll_len(this))
//            {
//                newNode->pElement = pElement;
//                newNode->pNextNode = NULL;
//                previousNode->pNextNode = newNode;
//            }
//            else
//            {
//                nextNode = getNode(this, nodeIndex + 1);
//                newNode->pElement = pElement;
//                newNode->pNextNode = nextNode;
//                previousNode->pNextNode = newNode;
//            }
//        }
//
//        this->size++;
//        returnAux = 0;
//    }
//    return returnAux;
    int returnAux = -1;
    Node* pNewNode;
    Node* pAuxNode;

    if(this !=NULL)
    {
        pNewNode= (Node*)malloc(sizeof(Node));

        if(pNewNode !=NULL && nodeIndex>=0 && nodeIndex<= ll_len(this))
        {
            pNewNode->pElement=pElement;

            if(nodeIndex==0)
            {
                pNewNode->pNextNode=this->pFirstNode;
                this->pFirstNode=pNewNode;
                this->size++;
                returnAux = 0;
            }
            else
            {
                pAuxNode=getNode(this,nodeIndex-1);

                if(pAuxNode!=NULL)
                {
                    pNewNode->pNextNode=pAuxNode->pNextNode;
                    pAuxNode->pNextNode=pNewNode;
                    this->size++;
                    returnAux = 0;
                }
            }

        }

    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
//    int returnAux = -1;
//    if(this!=NULL)
//    {
//        returnAux=addNode(this,(ll_len(this)),pElement);
//    }
//
//    return returnAux;
    int returnAux = -1;

    int size = ll_len(this);

    if(this !=NULL)
    {
        addNode(this,size,pElement);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
//    void* returnAux = NULL;
//    if(this!=NULL)
//    {
//        if(index<ll_len(this))
//        {
//            Node* pNode=(Node*)malloc(sizeof(Node*));
//            pNode=(Node*)getNode(this,index);
//            if(pNode!=NULL)
//            {
//                returnAux=(Node*)malloc(sizeof(Node*));
//                returnAux=pNode->pElement;
//            }
//            free(pNode);
//        }
//    }
//    return returnAux;
    void* returnAux = NULL;
    Node* auxNode;

    if(this !=NULL && index>=0 && index<= ll_len(this))
    {
        auxNode = getNode(this,index);

        if(auxNode !=NULL)
        {
            returnAux = auxNode->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if((ll_len(this))>0)
        {
            if(index>=0&&index<(ll_len(this)))
            {
                Node* pNode=(Node*)malloc(sizeof(Node*));
                pNode=getNode(this,index);
                if(pNode!=NULL)
                {
                    pNode->pElement=pElement;
                    returnAux=0;
                }
            }
        }

    }

    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(ll_len(this)>0)
        {
            if(index>=0&&index<(ll_len(this)))
            {
                Node* pNode = (Node*)malloc(sizeof(Node));
                Node* previousNode = (Node*)malloc(sizeof(Node));
                Node* nextNode = (Node*)malloc(sizeof(Node));
                pNode=getNode(this,index);
                if(pNode==this->pFirstNode)
                {
                    this->size--;
                    pNode->pElement=NULL;
                }
                if(pNode!=this->pFirstNode)
                {
                    if(pNode->pNextNode!=NULL)
                    {
                        previousNode=getNode(this,index-1);
                        nextNode=getNode(this,index+1);
                        previousNode->pNextNode=nextNode;
                    }
                    else
                    {
                        previousNode=getNode(this,index-1);
                        previousNode->pNextNode=NULL;
                    }
                    this->size--;
                    pNode->pElement=NULL;
                }
                returnAux=0;
            }
        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        for(int i=ll_len(this); i>0; i--)
        {
            ll_remove(this,i-1);
        }
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux=-1;

    if(this != NULL)
    {
        Node* pNode=NULL;
        for(int i=0; i<ll_len(this); i++)
        {
            pNode=getNode(this,i);
            if(pNode->pElement==pElement)
            {
                returnAux=i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(this->pFirstNode==NULL)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(index >= 0 && index <= ll_len(this))
        {
            addNode(this,index,pElement);
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this!=NULL)
    {
        if(ll_len(this)>0)
        {
            if(index>=0&&index<(ll_len(this)))
            {
                Node* pNode = (Node*)malloc(sizeof(Node));
                Node* previousNode = (Node*)malloc(sizeof(Node));
                Node* nextNode = (Node*)malloc(sizeof(Node));
                pNode=getNode(this,index);
                if(pNode==this->pFirstNode)
                {
                    this->size--;
                    returnAux=pNode->pElement;
                }
                if(pNode!=this->pFirstNode)
                {
                    if(pNode->pNextNode!=NULL)
                    {
                        previousNode=getNode(this,index-1);
                        nextNode=getNode(this,index+1);
                        previousNode->pNextNode=nextNode;
                    }
                    else
                    {
                        previousNode=getNode(this,index-1);
                        previousNode->pNextNode=NULL;
                    }
                    this->size--;
                    returnAux=pNode->pElement;
                }
            }
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux=-1;
    if(this!=NULL)
    {
        Node* pNode=NULL;
        returnAux=0;
        for(int i=0; i<ll_len(this); i++)
        {
            pNode=getNode(this,i);
            if(pNode->pElement==pElement)
            {
                returnAux=1;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    if(this!=NULL&&this2!=NULL)
    {
        Node* pNode=NULL;
        returnAux=0;
        for(int i=0; i<ll_len(this2); i++)
        {
            pNode=getNode(this2,i);
            returnAux=ll_contains(this,pNode->pElement);
            if(returnAux==0)
            {
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
        if((from >= 0 && from < ll_len(this))&&(to > from && to <= ll_len(this)))
        {
            cloneArray=ll_newLinkedList();
            Node* pNode=(Node*)malloc(sizeof(Node*));
            for(int i=from; i<to; i++)
            {
                pNode=getNode(this,i);
                ll_add(cloneArray,pNode->pElement);
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
        cloneArray=ll_newLinkedList();
        cloneArray=ll_subList(this,0,ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* aux;
    if(this != NULL && pFunc != NULL && (order == 0  || order == 1))
    {
        if(this!=NULL)
        {
            for(int i=0; i< ll_len(this)-1; i++)
            {
                for(int j=i+1; j <ll_len(this) ; j++ )
                {
                    if(order)
                    {
                        if( pFunc( ll_get(this, i), ll_get(this, j)) >0)
                        {
                            aux = ll_get(this, i);
                            ll_set(this, i, ll_get(this, j));
                            ll_set(this, j, aux);
                        }
                    }
                    else
                    {
                        if( pFunc( ll_get(this, i), ll_get(this, j))  < 0)
                        {
                            aux = ll_get(this, i);
                            ll_set(this, i, ll_get(this, j));
                            ll_set(this, j, aux);
                        }
                    }
                }
            }
            returnAux=0;
        }
    }
    return returnAux;
}
//********************************************************************************
/** \brief aplica una funcion a todos los elementos de la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return LinkedList* de una lista nueva con los elementos afectados por la funcion
 */
LinkedList* ll_map(LinkedList* this,int *pFunc(void*))
{
//    LinkedList* nuevaLinked = ll_newLinkedList();
//    if ( this != NULL && pFunc != NULL)
//    {
//        Node* pNode = (Node*)malloc(sizeof(Node*));
//        pNode = this -> pFirstNode;
//        for(int i = 0; i < ll_len(this); i++)
//        {
//            if(pFunc(pNode->pElement) == 1)
//            {
//                ll_add(nuevaLinked,pNode->pElement);
//            }else
//            {
//                break;
//            }
//            pNode = pNode->pNextNode;
//        }
//    }
//    return nuevaLinked;
 void* pAux;

    if(this !=NULL && pFunc !=NULL)
    {
        //recorro la lista recibida
        for(int i=0; i<ll_len(this); i++)
        {
            //obtengo todos los elementos
            pAux = ll_get(this,i);

            if(pAux !=NULL)
            {
                //paso los elementos a la  funcion
                pFunc(pAux);
            }
        }
    }
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
//********************************************************************************************************************************
//***************************************************************************************************************************************************
/*void ll_startIter(LinkedList* this)
{
    Node* auxNode= NULL;

    if(this!= NULL)
    {
        auxNode = this -> pFirstNode;
        this -> pIterNode = auxNode;
    }

}

Node* ll_getNextNode(LinkedList* this)
{

    Node* pNode = NULL;

    if( this != NULL)
    {
        if(this -> pIterNode!=NULL)
        {
            pNode = this -> pIterNode;
            //printf("\nNodereturnGetNextNode: %p", pNode);
            this -> pIterNode = this -> pIterNode -> pNextNode;
            // printf("\nIterNodeThis: %p", this -> pIterNode);
        }

    }

    return pNode;
}
int ll_count(LinkedList* this,int (*pFunc)(void*))
{

    int contadorRet = -1;
    int sizeList;
    int i;
    void* pElementAux;
    Node* pNodeAux = NULL;


    if(this!=NULL && pFunc!=NULL)
    {
        sizeList = ll_len(this);


        if(sizeList>0 )
        {
            ll_startIter(this);
            contadorRet=0;
            for(i=0; i<sizeList; i++)
            {
                pNodeAux = ll_getNextNode(this);
                if(pNodeAux!=NULL)
                {
                    pElementAux = pNodeAux ->pElement;

                    contadorRet = contadorRet + pFunc(pElementAux);

                }
            }
        }
    }



    return contadorRet;


}*/
//**********AILU LINKED LIST**********************
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Empleado.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
 /*
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
 /*
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this !=NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
 /*
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;

    if(this !=NULL)
    {
        if(nodeIndex >= 0 && nodeIndex < ll_len(this))
        {
            //me paro en el primer elemento
            pNode = this->pFirstNode;

            //voy a buscar la & del primer nodo
            for(int i=0; i<nodeIndex; i++)
            {
                pNode = pNode->pNextNode;

            }
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
 /*
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
 /*
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNewNode;
    Node* pAuxNode;

    if(this !=NULL)
    {
        pNewNode= (Node*)malloc(sizeof(Node));

        if(pNewNode !=NULL && nodeIndex>=0 && nodeIndex<= ll_len(this))
        {
            pNewNode->pElement=pElement;

            if(nodeIndex==0)
            {
                pNewNode->pNextNode=this->pFirstNode;
                this->pFirstNode=pNewNode;
                this->size++;
                returnAux = 0;
            }
            else
            {
                pAuxNode=getNode(this,nodeIndex-1);

                if(pAuxNode!=NULL)
                {
                    pNewNode->pNextNode=pAuxNode->pNextNode;
                    pAuxNode->pNextNode=pNewNode;
                    this->size++;
                    returnAux = 0;
                }
            }

        }

    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
 /*
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
 /*
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    int size = ll_len(this);

    if(this !=NULL)
    {
        addNode(this,size,pElement);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 *//*
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode;

    if(this !=NULL && index>=0 && index<= ll_len(this))
    {
        auxNode = getNode(this,index);

        if(auxNode !=NULL)
        {
            returnAux = auxNode->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 *//*
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode;

    if(this !=NULL && index>=0 && index<= ll_len(this))
    {
        auxNode = getNode(this,index);

        if(auxNode !=NULL)
        {
            auxNode->pElement = pElement;
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 *//*
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pBorrar;
    Node* pAnterior;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        if(index == 0)
        {
            pBorrar = this->pFirstNode;
            this->pFirstNode = pBorrar->pNextNode;

        }
        else
        {
            pAnterior = getNode(this,index-1);
            pBorrar = getNode(this,index);

            pAnterior->pNextNode = pBorrar->pNextNode;
        }

        free(pBorrar);
        this->size--;
        returnAux = 0;

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 *//*
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this !=NULL)
    {
        for(int i=0; i<ll_len(this); i++)
        {
            ll_remove(this,i);
        }

        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 *//*
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this !=NULL)
    {
        ll_clear(this);
        free(this);

        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 *//*
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode;

    if(this !=NULL)
    {
        for(int i=0; i<ll_len(this); i++)
        {

            pNode = getNode(this,i);

            if(pNode!=NULL && pNode->pElement == pElement)
            {
                returnAux = i;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 *//*
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this !=NULL)
    {
        if(this->size == 0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 *//*
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this !=NULL && index >= 0 && index <= ll_len(this))
    {
        if(addNode(this,index,pElement)==0)
        {
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 *//*
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* pNode;

    if(this !=NULL && index >= 0 && index < ll_len(this))
    {
        pNode = ll_get(this,index);

        if(pNode !=NULL)
        {
            ll_remove(this,index);

            returnAux = pNode;
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*//*
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this !=NULL)
    {
        if(ll_indexOf(this,pElement)==-1)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*//*
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pAux;
    int cont = 0;

    if(this !=NULL && this2 !=NULL)
    {
        for(int i=0; i<ll_len(this2); i++)
        {

            pAux = ll_get(this2,i);

            if(ll_contains(this,pAux)==1)
            {
                cont++;
            }
        }

        if(cont == ll_len(this2))
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*//*
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    LinkedList* this2;
    void* pAux;

    if(this !=NULL && (from >=0 && from < ll_len(this)) && (to > from && to <= ll_len(this)))
    {
        this2 = ll_newLinkedList();

        if(this2 !=NULL)
        {
            for(int i=from; i<to; i++)
            {
                pAux = ll_get(this,i);

                ll_add(this2,pAux);
            }
        }
        else
        {
            this2 = NULL;
            free(this2);
        }

        if(this2->size == (to-from))
        {
            cloneArray = this2;
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*//*
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this !=NULL)
    {
        cloneArray = ll_subList(this,0,this->size);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 *//*
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{

    int returnAux = -1;

    void* pAux;
    Node* node1;
    Node* node2;
    int flag;

    if(this !=NULL && pFunc !=NULL && (order == 0 || order == 1) && this->size > 0)
    {
        do
        {
            flag = 0;

            node1 = this->pFirstNode;

            if(node1 !=NULL)
            {
                node2 = node1->pNextNode;

                for(int i=0; i<(ll_len(this)-1); i++)
                {
                    if((pFunc(node1->pElement,node2->pElement)== 1 && order == 1) || (pFunc(node1->pElement,node2->pElement)== -1 && order == 0))
                    {
                        pAux = node1->pElement;
                        node1->pElement = node2->pElement;
                        node2->pElement = pAux;
                        flag = 1;
                    }

                    if(node2->pNextNode !=NULL)
                    {
                        node1 = node2;
                    }
                    else
                    {
                        break;
                    }

                    node2 = node1->pNextNode;

                }
            }
        }
        while(flag == 1);

        returnAux = 0;

    }

    return returnAux;

}

/** \brief
 *
 * \param void*
 * \return LinkedList* ll_map(LinkedList* this, void*
 *
 *//*
LinkedList* ll_map(LinkedList* this, void* (*pFunc)(void*))
{
    LinkedList* returnAux = NULL;
    void* pAux;
    void* returnPFunc;

    if(this !=NULL && pFunc !=NULL)
    {
        returnAux = ll_newLinkedList();

        if(returnAux !=NULL)
        {
            //recorro la lista recibida
            for(int i=0; i<ll_len(this); i++)
            {
                //obtengo todos los elementos
                pAux = ll_get(this,i);

                if(pAux !=NULL)
                {
                    //paso los elementos a la  funcioN

                    if(returnPFunc !=NULL)
                    {
                        //lo que retorna se lo paso a la lista nueva con el ll_add
                        ll_add(returnAux,returnPFunc);
                    }
                }
            }
        }

    }

    return returnAux;
}

/** \brief
 *
 * \param this LinkedList*
 * \param (*pFunc void*
 * \return LinkedList*
 *
 *//*
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* returnAux = NULL;
    void* pAux;

    if(this !=NULL && pFunc !=NULL)
    {
        returnAux = ll_newLinkedList();

        if(returnAux !=NULL)
        {
            //recorro la lista recibida
            for(int i=0; i<ll_len(this); i++)
            {
                //obtengo todos los elementos
                pAux = ll_get(this,i);

                if(pAux !=NULL)
                {
                    if(pFunc(pAux))
                    {
                        //si entra por 1, lo cargo al array
                        ll_add(returnAux,pAux);
                    }
                }
            }
        }
    }
    return returnAux;
}

int ll_reduce(LinkedList* this, void* (*pFunc)(void*))
{
    int returnAux = -1;
    int i;
    int size = ll_len(this);
    void* pElemento;

    if (this!= NULL && pFunc != NULL)
    {
        for (i=0; i<size; i++)
        {
            pElemento = ll_get(this,i);

            if(pFunc(pElemento))
            {
                ll_remove(this,i);
                i--;
                size--;
            }
        }

        returnAux=0;
    }

    return returnAux;
}

void ll_map3(LinkedList* this, void (*pFunc)(void*))
{
    void* pAux;

    if(this !=NULL && pFunc !=NULL)
    {
        //recorro la lista recibida
        for(int i=0; i<ll_len(this); i++)
        {
            //obtengo todos los elementos
            pAux = ll_get(this,i);

            if(pAux !=NULL)
            {
                //paso los elementos a la  funcion
                pFunc(pAux);
            }
        }
    }
}

/*
LinkedList* ll_map2(LinkedList* this, void* (*pFunc)(void*))
{
    LinkedList* pp = ll_clone(this);

    void* pAux;

    if(this !=NULL && pFunc !=NULL)
    {
        //recorro la lista recibida
        for(int i=0; i<ll_len(this); i++)
        {
            //obtengo todos los elementos
            pAux = ll_get(this,i);

            if(pAux !=NULL)
            {
                //paso los elementos a la  funcion
                pFunc(pAux);
            }
        }
    }
}
*/
/*
LinkedList* ll_map1(LinkedList* this, void* (*pFunc)(void*))
{
    LinkedList* returnAux = NULL;
    //Employee* pAux;
    //Employee2* returnPFunc;
    eDominio pp;
    eDominio* pAux;

    if(this !=NULL && pFunc !=NULL)
    {
        returnAux = ll_newLinkedList();

        if(returnAux !=NULL)
        {
            //recorro la lista recibida
            for(int i=0; i<ll_len(this); i++)
            {
                //obtengo todos los elementos
                /*pAux = ll_get(this,i);
                returnPFunc = employee_new2();
                returnPFunc->id2 = pAux->id;
                strcpy(returnPFunc->nombre2,pAux->nombre);
                returnPFunc->horasTrabajadas2 = pAux->horasTrabajadas;
                returnPFunc->sueldo2 = pAux->sueldo;*/
     /*           pAux = ll_get(this,i);
                pp = *pAux;
                pAux = employee_new();
                *pAux = pp;

                if(pAux !=NULL)
                {
                    //paso los elementos a la  funcion
                    //pFunc(returnPFunc);
                    pFunc(pAux);
                    if(pAux !=NULL)
                    {
                        //lo que retorna se lo paso a la lista nueva con el ll_add
                        ll_add(returnAux,pAux);
                    }

                    /*if(returnPFunc !=NULL)
                    {
                        //lo que retorna se lo paso a la lista nueva con el ll_add
                        ll_add(returnAux,returnPFunc);
                    }*//*
                }
            }
        }

    }

    return returnAux;
}
*/
