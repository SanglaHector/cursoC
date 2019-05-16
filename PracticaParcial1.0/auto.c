#include "auto.h"
//**************************************************************************************************************
int buscarLibre(eAuto vec[], int tam){
    int indice = -1;
    for(int i = 0; i < tam ;  i++){

        if(vec[i].estado == VACIO){
            indice = i;
            break;
        }
    }
    return indice;
}
//**************************************************************************************************************
int generarIdAuto()
{
    static int id= 1;

    return id++;
}
//***************************************
void inicializarE(eAuto vec[] , int tam){

    for(int i = 0; i < tam ; i++){

        vec[i].estado = VACIO;
    }
}

int buscarE(eAuto vec[], int tam , int clave){
    int indice = -1;
    for(int i = 0; i < tam ; i++){
        if(vec[i].id == clave && vec[i].estado == OCUPADO){
            indice = i;
            break;
        }
    }
    return indice;
}

//******************************************************
void hardCodearAutos(eAuto vec[], int tam){
    eAuto ficticios[] ={
    {999,"ASD123",1000,5000,1989,1},
    {998,"ABC789",1001,5001,2000,1},
    {997,"HRU547",1002,5002,2010,1},
    {996,"ABC123",1001,5003,2015,1},
    {995,"ASD456",1000,5004,2020,1},
    {994,"HRU963",1002,5000,2019,1},
    {993,"ASD124",1000,5001,2006,1}
    };

    for(int i = 0; i < tam; i ++){

        vec[i] = ficticios[i];
    }
}
//******************************************************
