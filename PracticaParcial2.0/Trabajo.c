#include "Trabajo.h"


int buscarLibreTra(eTrabajo vec[], int tam){
    int indice = -1;
    for(int i = 0; i < tam ;  i++){

        if(vec[i].estado == VACIO){
            indice = i;
            break;
        }
    }
    return indice;
}

//******************************************************
void inicializarTrabajos(eTrabajo vecTra[],int tamTra){

    for(int i = 0; i < tamTra ; i++){

        vecTra[i].estado = VACIO;
    }
}
//*******************************************************
void hardCodearTrabajos(eTrabajo vec[], int tam){

    eTrabajo ficticios[] ={
    {9999,"KRL569",20000,{20,10,2018},1},
    {9998,"ASD123",20001,{5,6,2006},1},
    {9997,"ABC789",20002,{9,11,2010},1},
    {9996,"ASD123",20003,{23,4,1998},1},
    {9995,"ABC789",20000,{10,7,2014},1},
    {9994,"ASD124",20001,{9,11,2010},1},
    {9993,"HRU963",20002,{9,5,2019},1}
    };

    for(int i = 0; i < tam; i ++){

        vec[i] = ficticios[i];
    }
}
//******************************************************************************

int generarIdTra()
{
    static int id= 1;
    return id++;
}
