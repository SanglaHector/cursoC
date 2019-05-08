#include "Sector.h"
//**************************************************************************************************************
void menuInformes(eEmpleado vec[], int tam , eSector vecSec[], int tamSec){

    int opcion;
    do{

        printf("\nIngrese un informe: ");
        printf("\n1.Empleados por sector. ");
        printf("\n2.Empleados que gana mas por sector. ");
        printf("\n3.Empleados mas viejos. ");
        printf("\n4.Sector con mas empleados.");
        printf("\n5.Salir\n ");
        scanf("%d", &opcion);
        switch(opcion){
        case 1:
            empleadosPorSector(vec,tam,vecSec, tamSec);
            break;

        case 2:
            empleadoMasGana(vec,tam,vecSec,tamSec);
            break;

        case 3:
            empleadoMasAntiguo(vec,tam,vecSec,tamSec);
            break;

        case 4:
            sectorConMasEmpleados(vec, tam, vecSec, tamSec);
            break;

        case 5:
            printf("\nSaliendo\n");
           // system("pause");
            break;

        }

    }while(opcion != 5);
}
//*****************************************************************************************************************************

void empleadoMasGana(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){
    int max = 0;
    int sector;
    printf("\nIngrese un sector");
    printf("\n1.Legal");
    printf("\n2.RRHH");
    printf("\n3.Economia");
    printf("\n4.Obrero\n");
    scanf("%d", &sector);


    for(int i = 0; i < tam; i ++){

        if( vec[i].estado == OCUPADO && vec[i].sueldo >= max && vec[i].sector == sector){
            max = vec[i].sueldo;
        }
    }
    for(int i = 0; i < tam; i++){

        if(vec[i].estado == OCUPADO && vec[i].sueldo == max && vec[i].sector == sector){
            mostrarE(vec[i], vecSec,tamSec);
        }
    }
}
//**************************************************************************************************************
void empleadoMasAntiguo(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){
    eFecha min = {31,12,3000};
    int sector;
    printf("\nIngrese un sector");
    printf("\n1.Legal");
    printf("\n2.RRHH");
    printf("\n3.Economia");
    printf("\n4.Obrero\n");
    scanf("%d", &sector);


    for(int i = 0; i < tam; i ++){

        if( vec[i].estado == OCUPADO && vec[i].fechaIngreso.anio <=  min.anio && vec[i].sector == sector){
            min = vec[i].fechaIngreso;
            if(vec[i].fechaIngreso.mes <=  min.mes){
                min = vec[i].fechaIngreso;
                if(vec[i].fechaIngreso.dia <= min.dia){
                    min = vec[i].fechaIngreso;
                }
            }
        }
    }
    for(int i = 0; i < tam; i++){

        if(vec[i].estado == OCUPADO && vec[i].fechaIngreso.anio == min.anio && vec[i].fechaIngreso.mes == min.mes && vec[i].fechaIngreso.dia == min.dia && vec[i].sector == sector){
            mostrarE(vec[i], vecSec,tamSec);
        }
    }
}
//**************************************************************************************************************
void sectorConMasEmpleados(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){

    int sectores[3];
    /*int legal;
    int RRHH;
    int economia;
    int obrero;*/
    int max = 0;

    for(int i = 0; i < tam; i ++){

        if (vec[i].sector == 1){
            sectores[0] ++;
        }
        if (vec[i].sector == 2 ){
            sectores[1] ++;
        }
        if (vec[i].sector == 3){
            sectores[2] ++;
        }
        if (vec[i].sector == 4){
            sectores[3] ++;
        }
    }
    for(int i = 0; i < tamSec ;i++ ){

        if(sectores[i] > max){
            max = sectores[i];
        }
    }
    for(int i = 0; i < tamSec; i++){

        if(sectores[0] == max){
            printf("\nLEGAL es el sector con mas empleados con un total del %d.\n",max);
        }
        if(sectores[1] == max){
            printf("\nRRHH es el sector con mas empleados con un total del %d.\n",max);
        }
        if(sectores[2] == max){
            printf("\nECONOMIA es el sector con mas empleados con un total del %d.\n",max);
        }
        if(sectores[3] == max){
            printf("\nOBRERO es el sector con mas empleados con un total del %d.\n",max);
        }

    }
}
//**************************************************************************************************************
void empleadosPorSector(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){
    int sector;
    printf("\nIngrese un sector");
    printf("\n1.Legal");
    printf("\n2.RRHH");
    printf("\n3.Economia");
    printf("\n4.Obrero\n");
    scanf("%d", &sector);

    for(int i = 0; i < tam; i ++){

        if( vec[i].estado == OCUPADO && vec[i].sector == sector){
            mostrarE(vec[i],vecSec,tamSec);
        }
    }
}
