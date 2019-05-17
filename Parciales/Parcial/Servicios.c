#include "Servicios.h"


//*******************
void listarServicios( eServicio vecSer[], int tamSer){
    printf("\n  Servicios Precios");
        for(int i = 0; i < tamSer; i++){

        printf("\n %10s %.2f$\n", vecSer[i].descripcion,vecSer[i].precio);
    }
    printf("\n");
}
//*************************************************************************
