#include "Compra.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "validaciones.h"
#ifndef LindedDos_H_INCLUDED
#define LinkedDos_H_INCLUDED
LinkedList* ll_reduce (LinkedList* this, int *pFunc(void*));
LinkedList* ll_filter(LinkedList* this, int *pFunc(void*));
LinkedList* ll_map(LinkedList* this,int *pFunc(void*));
#endif
