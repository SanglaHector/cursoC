#include "Almuerzo.h"

void  menuAlmuerzos(eEmpleado vec[], int tam, eSector vecSec[], int tamSec, eComida vecCom[], int tamMenu, eAlmuerzo vecAlm[], int tamAlm){
system("cls");
int opcion;
    do{

        printf("\n1.Almuerzos por empleados");
        printf("\n2.Almuerzos por sector");
        printf("\n3.Almuerzos por legajo");
        printf("\n4.Salir:  ");
        scanf("%d", &opcion);
        switch(opcion){
        case 1:
            mostrarAlmuerzos(vec,tam,vecSec, tamSec, vecAlm, tamAlm, vecCom,tamMenu);
            break;

        case 2:
            comidasPorSector(vec,tam,vecSec,tamSec,vecAlm,tamAlm,vecCom,tamMenu);
            break;

        case 3:
            comidasPorLegajo(vec,tam,vecSec,tamSec,vecAlm,tamAlm,vecCom,tamMenu);
            break;

        case 4:
            printf("\nSaliendon.\n");
            break;

        }
        system("pause");
        system("cls");
    }while(opcion != 4);
}
//*****************************************************************************************************************************
void mostrarAlmuerzos(eEmpleado vec[], int tam, eSector vecSec[], int tamSec, eAlmuerzo vecAlm[],int tamAlm, eComida vecCom[], int tamCom){

for(int i = 0; i < tamAlm; i++){

    mostrarAlmuerzo(vec,tam,vecSec, tamSec,vecAlm[i], vecCom,tamCom);
}}
//****************************************************************************************************************************
void mostrarAlmuerzo(eEmpleado vec[], int tam, eSector vecSec[], int tamSec, eAlmuerzo almuerzo, eComida vecCom[], int tamCom){

    char nombre[20];
    char apellido[20];
    char comida[20];
    for(int i = 0; i < tam ; i++){

        if(vec[i].estado == OCUPADO && vec[i].legajo == almuerzo.idEmpleado){
            strcpy(nombre, vec[i].nombre);
            strcpy(apellido, vec[i].apellido);
        }
    }

    for(int j = 0; j < tamCom ; j++){

        if( vecCom[j].id == almuerzo.idComida){
            strcpy(comida, vecCom[j].descripcion);
    }
    }
    printf("\nTiket: %d , Nombre: %s , Apellido: %s ,Fecha: %02d/%02d/%02d , Comida: %s\n",almuerzo.id, nombre, apellido, almuerzo.fecha.dia, almuerzo.fecha.mes, almuerzo.fecha.anio , comida);
    strcpy(nombre,"NOEXISTE");
    strcpy(apellido,"NOEXISTE");
}

//*********************************************************************************************************************
void comidasPorLegajo(eEmpleado vec[], int tam, eSector vecSec[],  int tamSec, eAlmuerzo vecAlm[],int tamAlm, eComida vecCom[], int tamCom){
int legajo;
printf("\nIngrese un legajo: ");
scanf("%d", &legajo);

for( int i = 0; i < tam ; i++){

    if(legajo == vec[i].legajo)
        for(int j = 0; j < tamAlm ; j++){

            if(vec[i].legajo == vecAlm[j].idEmpleado){
                mostrarAlmuerzo(vec,tam,vecSec,tamSec,vecAlm[j],vecCom,tamCom);
            }
        }
    }
}
void comidasPorSector(eEmpleado vec[], int tam, eSector vecSec[],  int tamSec, eAlmuerzo vecAlm[],int tamAlm, eComida vecCom[], int tamCom){

    int opcion;
    int legajoAux;
    printf("\n.Elija un sector\n");
    printf("\n1.Legal.\n");
    printf("\n2.RRHH.\n");
    printf("\n3.Economia.\n");
    printf("\n4.Obrero.\n");
    scanf("%d", &opcion);
    for(int i = 0; i < tam ; i++){

        if(vec[i].estado == OCUPADO && vec[i].sector == opcion ){

            legajoAux = vec[i].legajo;

            for(int j = 0; j < tamAlm; j++){
                    if(legajoAux == vecAlm[j].idEmpleado){

                        mostrarAlmuerzo(vec,tam,vecSec,tamSec,vecAlm[j],vecCom,tamCom);

                    }
            }
        }
    }

}
//**************************************************************************************************************
