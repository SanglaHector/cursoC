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
    {9998,"PLE670",20001,{5,6,2006},1},
    {9997,"PNA663",20002,{9,11,2010},1},
    {9996,"LLE456",20003,{23,4,1998},1},
    {9995,"LKD637",20000,{10,7,2014},1},
    {9994,"MIZ486",20001,{16,8,2011},1},
    {9993,"FYX454",20002,{9,5,2019},1}
    };

    for(int i = 0; i < tam; i ++){

        vec[i] = ficticios[i];
    }
}

