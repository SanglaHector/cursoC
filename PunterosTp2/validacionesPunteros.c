#include "validacionesPunteros.h"

int validarInt(int num,int min,int max){
    int retorno = -1;
    if ( num >= min && num <= max ){

        retorno = 1;
    }

    return retorno;
}
//**************************************************************************************************************
int validarFloat(float num, float min, float max){
    int retorno = -1;
    if(num >= min && num <=max ){

        retorno = 1;
    }
    return retorno;
}
//**************************************************************************************************************
int validarNombre(char nombre[]){

int retorno =  -1;
int todoOk = 0;
    for(int i=0; i<strlen(nombre); i++)
    {
        if(isalpha(nombre[i]) == 0 ){

            todoOk = -1;
        }
    }

    if (todoOk == 0){
        retorno = 1;
    }

return retorno;
}
//**************************************************************************************************************

