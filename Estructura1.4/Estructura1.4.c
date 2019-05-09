#include "Estructura1.4.h"
//**************************************************************************************************************
void inicializarE(eEmpleado vec[], int tam){

    for(int i = 0; i < tam ; i++){

        vec[i].estado = VACIO;
    }
}
//**************************************************************************************************************
void altaE(eEmpleado vec[], int tam, eSector secVec[], int tamSec){
    int legajo;
    int repetido;
    int validar;
    char aux[20];
    int indice = buscarLibre(vec,tam);

    if (indice == -1){
        printf("\nNo hay espacio para agregar empleados.");
    }else{
            printf("\nIngrese el legajo: ");
            fflush(stdin);
            scanf("%s", aux);
            validar = validarInt(1,1000,aux);
            if (validar != -1){
                legajo = atoi(aux);
            }
            repetido = buscarE(vec,tam,legajo);
            }
        if (repetido == -1){
            vec[indice].legajo = legajo;
            pedirDatos(vec,tam,indice);
            printf("\nEmpleado ingresado con exito: \n");
            mostrarE(vec[indice],secVec,tamSec);

        }else{
            printf("\nEl legajo %d ya existe: ", legajo);
            mostrarE(vec[repetido], secVec, tamSec);
        }
    }
//**************************************************************************************************************
int buscarLibre(eEmpleado vec[], int tam){
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
int buscarE(eEmpleado vec[], int tam , int clave){
    int indice = -1;
    for(int i = 0; i < tam ; i++){
        if(vec[i].legajo == clave && vec[i].estado == OCUPADO){
            indice = i;
            break;
        }
    }
    return indice;
}
//**************************************************************************************************************
void mostrarE(eEmpleado e, eSector vecSec[], int tamSec){

char sector[20];
   // printf("\Legajo nNOMBRE   APELLIDO    SEXO  SUELDO   FECHA DE INGRESO.\n");
   for(int i = 0; i < tamSec; i++){

    if ( vecSec[i].id == e.sector){

        strcpy(sector,vecSec[i].descripcion);
    }
   }
    printf("\nLegajo: %d Nombre: %s Apellido: %s Sexo: %c Sueldo: %.2f Fecha: %02d/%02d/%02d Sector: %s\n\n\n",e.legajo,e.nombre,e.apellido,e.sexo,e.sueldo,e.fechaIngreso.dia,e.fechaIngreso.mes,e.fechaIngreso.anio,sector);}
//**************************************************************************************************************
void bajaE(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){
    int legajo;
    int indice;
    char seguir = 'n';
    printf("\nIngrese el legajo que quiera eliminar: ");
    scanf("%d", &legajo);
    indice = buscarE(vec,tam,legajo);
    if (indice != -1 && vec[indice].estado == OCUPADO){
        mostrarE(vec[indice], vecSec,tamSec);
        printf("\nEsta seguro que desea dar de baja este empleado? S/N: ");
        fflush(stdin);
        scanf("%c",&seguir);
        seguir = toupper(seguir);
        if( seguir == 'S'){

            vec[indice].estado = VACIO;
            printf("\nEl empleado se ha dado de baja con exito.");
        }else {
        printf("\nLa operacion ha sido cancelada.");}

    }else {
        printf("\nEl legajo ingresado no se encuentra en el sistema.");
    }
}
//**************************************************************************************************************
void modificarE(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){
    int legajo;
    int indice;
    int opcion;
    int sector;
    float sueldo;
    char seguir = 'n';
    printf("\nIngrese el legajo que quiera modificar: ");
    scanf("%d", &legajo);
    indice = buscarE(vec,tam,legajo);
    if (indice != -1 && vec[indice].estado == OCUPADO){
        mostrarE(vec[indice],vecSec, tamSec);
        printf("\nDesea modificar este empleado?Ingrese S/N: ");
        fflush(stdin);
        scanf("%c" , &seguir);
        fflush(stdin);
        if(seguir == 's' || seguir == 'S'){

            menuModificar(vec,indice,tam,vecSec,tamSec);
        }else{
            printf("\nLa operacion ha sido cancelada");
        }

    }else {
        printf("\nEl legajo ingresado no se encuentra en el sistema.");
    }
}
//**************************************************************************************************************
void hardCodear(eEmpleado vec[], int tam){
    eEmpleado ficticios[] ={
    {1234,25000,"Hector","Sangla",'m',{20,10,2018},1,1},
    {2222,15000,"Alberto","Perez",'m',{5,6,2006},1,2},
    {3333,20000,"Vanesa","Rodriguez",'f',{9,11,2010},1,2},
    {4444,35000,"Marta","Galatti",'f',{23,4,1998},1,3},
    {5555,60000,"Carlos","Sanchez",'m',{10,7,2014},1,4},
    {6666,10550,"Maria","Espada",'f',{16,8,2011},1,4},
    {2222,30000,"Leila","Casati",'f',{9,5,2019},1,1}
    };

    for(int i = 0; i < tam; i ++){

        vec[i] = ficticios[i];
    }
}
//**************************************************************************************************************
void mostrarEs(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){
    for(int i = 0 ; i < tam ; i ++){

        if (vec[i].estado == OCUPADO){
            mostrarE(vec[i],vecSec,tamSec);
            }
    }
}
//**************************************************************************************************************
void pedirDatos(eEmpleado vec[], int tam, int indice){
    int validar = -1;
    char aux[50];
    char auxSexo;
//*********************VALIDO NOMBRE*****************************************
        while( validar == -1){
            fflush(stdin);
            printf("\nIngrese nombre: ");
            scanf("%s", aux);
            validar = validarNombre(aux);
            if( validar == -1){
                printf("\nEl nombre solo acepta caracteres alfabeticos");
            }
        }
        strcpy(vec[indice].nombre,aux);
        formatearNombre(vec,tam,indice);
        strcpy(aux," ");
//********************VALIDO APELLIDO****************************************
        validar =-1;
        while ( validar == -1){
            fflush(stdin);
            printf("\nIngrese apellido: ");
            scanf("%s", aux);
            validar = validarNombre(aux);
            if( validar == -1){
                printf("\nEl apellido solo acepta caracteres alfabeticos");
            }
        }
        strcpy(vec[indice].apellido,aux);
        formatearNombre(vec,tam,indice);
        strcpy(aux," ");
//*******************VALIDO SUELDO*********************************************
        validar =-1;
    while( validar == -1){
            fflush(stdin);
            printf("\nIngrese sueldo: ");
            scanf("%s", aux);
            validar = validarFloat(8000,100000,aux);
            if( validar == -1){
                printf("\nEl sueldo debe estar entre %d$ y  %d$", 8000,100000);
            }
    }
     vec[indice].sueldo = atof(aux);
     strcpy(aux," ");

//******************VALIDO SEXO***********************************************
    validar =-1;
    while ( validar == -1){

            fflush(stdin);
            printf("\nIngrese sexo: ");
            scanf("%c", &auxSexo);
            validar = isalpha(auxSexo);
            if (validar !=0){
                auxSexo= toupper(auxSexo);
                if(auxSexo != 'F' && auxSexo != 'M'){
                    printf("\nPor favor solo ingrese F/M");
                    validar = -1;
                }else {
                    validar = 1;
                }
            }else {
                validar = -1;
            }
    }
    fflush(stdin);
    vec[indice].sexo = auxSexo;
//******************VALIDO FECHA**********************************************
    validar = -1;
    while( validar == -1){
            printf("\nIngrese anio de ingreso: ");
            scanf("%s", aux);
            validar = validarInt(1900,2100,aux);
            if( validar == -1){

             printf("\nEl año de ingreso debe estar entre 1900 y 2100.");
            }
            }
            vec[indice].fechaIngreso.anio=atoi(aux);
            strcpy(aux," ");
            validar = -1;
//***************mes********************************************************
    while( validar == -1){
            printf("\nIngrese mes de ingreso: ");
            scanf("%s", aux);
            validar = validarInt(1,12,aux);
            if( validar == -1){

             printf("\nEl mes de ingreso es incorrecto.");
            }
    }
    vec[indice].fechaIngreso.mes=atoi(aux);
    strcpy(aux," ");
//************************dia**********************************************
            validar = -1;
     while( validar == -1){
            printf("\nIngrese dia de ingreso: ");
            scanf("%s", aux);
            validar = validarInt(1,31,aux);
            if( validar == -1){
             printf("\nEl dia de ingreso es incorrecto.");
            }
     }
     vec[indice].fechaIngreso.dia = atoi(aux);
     strcpy(aux," ");
//************************SECTOR**********************************************
    validar = -1;
    while(validar == -1){
            printf("\nIngrese un sector");
            printf("\n1.Legal");
            printf("\n2.RRHH");
            printf("\n3.Economia");
            printf("\n4.Obrero\n :");
            scanf("%s", aux);
            validar = validarInt(1,4,aux);
            if(validar == -1){
                printf("\nPor favor ingrese una opcion correcta.");
            }
    }
    vec[indice].sector = atoi(aux);
    strcpy(aux," ");
//**********************TERIMINE VALIDACION*****************************
            vec[indice].estado = OCUPADO;
            printf("\nDatos ingresados con exito!\n");
}
//*****************************************************************************************************************************
void menuModificar(eEmpleado vec[], int indice, int tam,eSector vecSec[], int tamSec){

int opcion;
int validar =  -1;
char aux[51];
char auxSexo;

do{
        system("cls");
    printf("\nIngrese una opcion: ");
    printf("\n1.Modificar nombre .\n");
    printf("\n2.Modificar apellido .\n");
    printf("\n3.Modificar sueldo .\n");
    printf("\n4.Modificar sector .\n");
    printf("\n5.Salir .\n");
    scanf("%d", &opcion);

    switch(opcion){

    case 1:
          while( validar == -1){
            fflush(stdin);
            printf("\nIngrese nombre: ");
            scanf("%s", aux);
            validar = validarNombre(aux);
            if( validar == -1){
                printf("\nEl nombre solo acepta caracteres alfabeticos");
            }
        }
        strcpy(vec[indice].nombre,aux);
        formatearNombre(vec,tam,indice);
        strcpy(aux," ");

        break;

    case 2:
         validar =-1;
        while ( validar == -1){
            fflush(stdin);
            printf("\nIngrese apellido: ");
            scanf("%s", aux);
            validar = validarNombre(aux);
            if( validar == -1){
                printf("\nEl apellido solo acepta caracteres alfabeticos");
            }
        }
        strcpy(vec[indice].apellido,aux);
        formatearNombre(vec,tam,indice);
        strcpy(aux," ");

        break;

    case 3:
         validar =-1;
        while( validar == -1){
            fflush(stdin);
            printf("\nIngrese sueldo: ");
            scanf("%s", aux);
            validar = validarFloat(8000,100000,aux);
            if( validar == -1){
                printf("\nEl sueldo debe estar entre %d$ y  %d$", 8000,100000);
            }
        }
        vec[indice].sueldo = atof(aux);
        strcpy(aux," ");


        break;

    case 4:
        validar = -1;
        while(validar == -1){
            printf("\nIngrese un sector");
            printf("\n1.Legal");
            printf("\n2.RRHH");
            printf("\n3.Economia");
            printf("\n4.Obrero\n :");
            scanf("%s", aux);
            validar = validarInt(1,4,aux);
            if(validar == -1){
                printf("\nPor favor ingrese una opcion correcta.");
            }
        }
        vec[indice].sector = atoi(aux);
        strcpy(aux," ");
        break;

    case 5:
        break;

    default:
        printf("\nIngrese una opcion correcta. \n");
        break;

    }

}while(opcion != 5);
}
//***************************************************************************************************************************************************************
void listarAlfabeticamente(eEmpleado vec[],int tam,eSector vecSec[],int tamSec){

    eEmpleado empleadoAux;
    for (int i = 0; i < tam-1; i++ ){
        for(int j = i+1; j <tam ; j++){

            if(vec[i].estado == OCUPADO && vec[j].estado == OCUPADO && strcmp(vec[i].apellido,vec[j].apellido) > 0 ){

                empleadoAux = vec[i];
                vec[i] = vec[j];
                vec[j] = empleadoAux;

            }
            if(vec[i].estado == OCUPADO && vec[j].estado == OCUPADO && strcmp(vec[i].apellido,vec[j].apellido) == 0 && vec[i].sector > vec[j].sector ){

                empleadoAux = vec[i];
                vec[i] = vec[j];
                vec[j] = empleadoAux;

            }
        }
    }
    for(int i= 0;i < tam;i ++){
            if(vec[i].estado == OCUPADO){

                mostrarE(vec[i],vecSec,tamSec);
            }
    }
}
//******************************************************************************************************************************************
void totalizarSalarios(eEmpleado vec[],int tam,eSector vecSec[],int tamSec){

float promedio = 0;
int cantidadEmpleados = 0;
float acumuladorSueldos = 0;
for(int i= 0; i < tam; i++){
    if(vec[i].estado == OCUPADO){

        acumuladorSueldos = acumuladorSueldos + vec[i].sueldo;
        cantidadEmpleados ++;
    }
}
promedio = (acumuladorSueldos / cantidadEmpleados);
printf("\nLa cantidad de empleados activos es de: %d ",cantidadEmpleados );
printf("\nLa suma total de los sueldos es de: %.2f",acumuladorSueldos );
printf("\nEl promedio de sueldo es de: %.2f",promedio );
printf("\nEstos son los empleados que superan el promedio de sueldo: \n");
for (int i = 0; i < tam ; i++){
    if(vec[i].estado == OCUPADO && vec[i].sueldo >= promedio){

        mostrarE(vec[i],vecSec,tamSec);
    }
}
}
//*******************************************************************************************************************************************
void formatearNombre(eEmpleado vec[], int tam, int indice){

    strlwr(vec[indice].nombre);
    vec[indice].nombre[0]=toupper(vec[indice].nombre[0]);

    strlwr(vec[indice].apellido);
    vec[indice].apellido[0]=toupper(vec[indice].apellido[0]);
}
//************************************************MOSTRAR EMPLEADOS****************************************************************************
void menuMostrarE(eEmpleado vec[], int tam, eSector vecSec[],int tamSec){

    int opcion;
    do{
        system("pause");
        system("cls");
        printf("\nIngrese una opcion: ");
        printf("\n1.Mostrar todos empleados .");
        printf("\n2.Mostrar empleados ordenados por sector.");
        printf("\n3.Mostrar empleados ordenados por legajo.");
        printf("\n4.Mostrar empleados por orden alfabetico.");
        printf("\n5.Mostrar empleados por sector alfabeticamente.");
        printf("\n6.Mostrar empleados por sector y en orden de legajo.");
        printf("\n7.Mostrar empleados de sexo masculino ordenados alfabeticamente.");
        printf("\n8.Mostrar empleados de sexo femenimo ordenados por legajo.");
        printf("\n9.Mostrar empleados ordenados por sector, legajo y sexo.");
        printf("\n10.Salir .\n");
       scanf("%d", &opcion);

       switch(opcion){

        case 1:
            mostrarEs(vec,tam,vecSec,tamSec);
            break;
        case 2:
            empleadosPorSector(vec,tam,vecSec,tamSec);
            break;
        case 3:
            empleadosPorLegajo(vec,tam,vecSec,tamSec);
            break;
        case 4:
            empleadosAlfabeticamente(vec,tam,vecSec,tamSec);
            break;
        case 5:
            empleadosPorSectorYAlfa(vec,tam,vecSec,tamSec);
            break;
        case 6:
            empleadosPorSectorYLegajo(vec,tam,vecSec,tamSec);
            break;
        case 7:
            empleadosMasculinoAlfa(vec,tam,vecSec,tamSec);
            break;
        case 8:
            empleadosFemenimoPorlegajo(vec,tam,vecSec,tamSec);
            break;
        case 9:
            printf("\nNo tiene sentido hacer eso.");
            break;
        case 10:
            printf("\nSaliendo...\n");
            break;
        default:
            printf("\nIngrese una opcion correcta. ");
            break;
       }

    }while(opcion != 10);
}
//***********************************************************************************************************************
void empleadosPorLegajo(eEmpleado vec[], int tam, eSector vecSec[],int tamSec){

    eEmpleado aux;
    for(int i= 0; i < tam - 1 ; i++){
        for(int j = 1; j <tam ; j++){

            if(vec[i].legajo > vec[j].legajo){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
    mostrarEs(vec,tam,vecSec,tamSec);
}
//**********************************************************************************************************************
void empleadosAlfabeticamente(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){
    eEmpleado aux;
    for(int i= 0; i < tam - 1 ; i++){
        for(int j = 1; j <tam ; j++){

            if(strcmp(vec[i].apellido,vec[j].apellido) < 0){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
    mostrarEs(vec,tam,vecSec,tamSec);
}
//**********************************************************************************************************************
void empleadosPorSectorYAlfa (eEmpleado vec[], int tam, eSector vecSec[], int tamSec){
    eEmpleado aux;
        for(int i= 0; i < tam - 1 ; i++){
            for(int j = 1; j <tam ; j++){

            if(vec[i].sector > vec[j].sector){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
    for(int i = 0; i< tam-1 ; i++ ){
        for(int j = 1; j< tam; j++){
            if(vec[i].sector == vec[j].sector){
                if(strcmp(vec[i].apellido,vec[j].apellido) < 0){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
                }
            }
        }
    }
    mostrarEs(vec,tam,vecSec,tamSec);
}
//****************************************************************************************
void empleadosPorSectorYLegajo(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){

    eEmpleado aux;
        for(int i= 0; i < tam - 1 ; i++){
            for(int j = 1; j <tam ; j++){

            if(vec[i].sector > vec[j].sector){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
    for(int i = 0; i< tam-1 ; i++ ){
        for(int j = 1; j< tam; j++){
            if(vec[i].sector == vec[j].sector){
                if(vec[i].legajo < vec[j].legajo){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
                }
            }
        }
    }
    mostrarEs(vec,tam,vecSec,tamSec);
}
//******************************************************************************************************
void empleadosMasculinoAlfa(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){

    eEmpleado aux;

    for(int i = 0; i< tam-1 ; i++ ){
        for(int j = 1; j< tam; j++){
                if(strcmp(vec[i].apellido,vec[j].apellido) < 0){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
                }
        }
    }
    for(int i = 0; i<tam ; i++){
        if( vec[i].sexo == 'm'){
            mostrarE(vec[i],vecSec,tamSec);
        }
    }
}
//*******************************************************************************************************
void empleadosFemenimoPorlegajo(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){
     eEmpleado aux;
    for(int i= 0; i < tam - 1 ; i++){
        for(int j = 1; j <tam ; j++){

            if(vec[i].legajo > vec[j].legajo){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
    for(int i = 0; i<tam ; i++){
        if( vec[i].sexo == 'f'){
            mostrarE(vec[i],vecSec,tamSec);
        }
    }
}
//*****************************************************************************************************
