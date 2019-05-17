#include "auto.h"
#define OCUPADO 1
#define VACIO 0
//*******************************************************************************
void altaE(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor colVec[],int tamCol){
    int id;
    int indice = buscarLibre(vec,tam);

    if (indice == -1){
        printf("\nNo hay espacio para agregar empleados.");
    }else{
            id = generarIdAuto();

            pedirDatos(vec,tam,id,vecMar,tamMar,colVec,tamCol);
            vec[id].id = id;
            printf("\nEmpleado ingresado con exito: \n");
            mostrarE(vec[id],vecMar,tamMar,colVec,tamCol);
        }
    }
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
//***************************************
void pedirDatos(eAuto vec[], int tam, int indice, eMarca vecMar[], int tamMAr, eColor vecCol[], int tamCol){
    int validar = -1;
    char aux[50];
    char patenteNum[6];
    char patenteCar[3];
    char patente[6];
    int contador=0;
//*********************VALIDO patente*****************************************
        validar = -1;
        while (validar == -1){
                contador = 0;
            fflush(stdin);
            printf("\nLa patente debe estar compuesta por 3 digitos numericos al principio y 3 al final:");
            printf("\nIngrese los 3 digitos numericos: ");
            scanf("%s", aux);
            validar = validarInt(0,999,aux);
            for(int i = 0; i < strlen(aux); i++){
                if( isdigit(aux[i]) != 0){
                   contador ++;
                   }else{
                    break;
                   }
            }
            if (contador != 3){
                validar = -1;
            }
            contador = 0;
            if( validar == -1){
                printf("\nPor favor solo ingrese los 3 primeros digitos: ");
            }
        }
        strcpy(patenteNum,aux);
        strcpy(aux," ");

        validar = -1;
        while (validar == -1){
                contador = 0;
            fflush(stdin);
            printf("\nIngrese los 3 digitos alfabeticos: ");
            scanf("%s", aux);
            validar = validarNombre(aux);
            for(int i = 0; i < strlen(aux); i++){
                if( isalpha(aux[i]) != 0){
                   contador ++;
                   }else{
                    break;
                   }
            }
             if (contador != 3){
                validar = -1;
            }
            if( validar == -1){
                printf("\nPor favor solo ingrese las 3 letras de la patente: ");
            }
        }
        strcpy(vec[indice].patente,patenteNum);
        strcpy(patenteCar,aux);
        strcpy(aux," ");
        validarPatente(patenteCar,vec[indice].patente,patente);// aca esta el problema
        strcpy(vec[indice].patente,patente);
//********************VALIDO modelo****************************************
        validar =-1;
        while ( validar == -1){
            fflush(stdin);
            printf("\nIngrese anio de modelo: ");
            scanf("%s", aux);
            validar = validarInt(1900,2020,aux);
            if( validar == -1){
                printf("\nEl año debe estar entre 1900 y 2020");
            }
        }
        vec[indice].modelo = atoi(aux);
        strcpy(aux," ");

//************************marca**********************************************
    validar = -1;
    while(validar == -1){
            printf("\nIngrese un codigo de marca");
            printf("\n1000.Renault");
            printf("\n1001.Fiat");
            printf("\n1002.Ford");
            printf("\n1003.Chevrolet :");
            printf("\n1004.Peugeot :");
            scanf("%s", aux);
            validar = validarInt(1000,1004,aux);
            if(validar == -1){
                printf("\nPor favor ingrese una opcion correcta.");
            }
    }
    vec[indice].idMarca = atoi(aux);
    strcpy(aux," ");
//************************COLOR**********************************************
    validar = -1;
    while(validar == -1){
            printf("\nIngrese un codigo de color");
            printf("\n5000.Negro");
            printf("\n5001.Blanco");
            printf("\n5002.Gris");
            printf("\n5003.Rojo :");
            printf("\n5004.Azul\n :");
            scanf("%s", aux);
            validar = validarInt(5000,5004,aux);
            if(validar == -1){
                printf("\nPor favor ingrese una opcion correcta.");
            }
    }
    vec[indice].idColor = atoi(aux);
    strcpy(aux," ");
//**********************TERIMINE VALIDACION*****************************
            vec[indice].estado = OCUPADO;
            printf("\nDatos ingresados con exito!\n");
}
void mostrarE(eAuto e, eMarca vecMar[], int tamMar, eColor vecCol[], int tamCol){

char marca[20];
char color[20];
   for(int i = 0; i < tamMar; i++){

    if ( vecMar[i].id == e.idMarca){

        strcpy(marca,vecMar[i].descripcion);
    }}

     for(int i = 0; i < tamCol; i++){

    if ( vecCol[i].id == e.idColor){

        strcpy(color,vecCol[i].descripcion);
    }
   }
   if(e.estado == OCUPADO ){

        printf("\nPatente : %s , Marca: %s , Color: %s , Modelo: %d . ",e.patente,marca,color,e.modelo);
   }
}
//***************************************************************************
void bajaE(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol){
    int id;
    char patente[6];
    int indice;
    char seguir = 'n';
    printf("\nIngrese la patente del auto que quiera eliminar: ");
    scanf("%s", patente);
    for(int i = 0; i < tam ; i++){

        if(strcmpi(patente,vec[i].patente) == 0 && vec[i].estado == OCUPADO){
           id = vec[i].id;
           }
    }

    indice = buscarE(vec,tam,id);
    if (indice != -1 && vec[indice].estado == OCUPADO){
        mostrarE(vec[indice],vecMar,tamMar,vecCol,tamCol);
        printf("\nEsta seguro que desea dar de baja este auto? S/N: ");
        fflush(stdin);
        scanf("%c",&seguir);
        seguir = toupper(seguir);
        if( seguir == 'S'){

            vec[indice].estado = VACIO;
            printf("\nEl auto se ha dado de baja con exito.");
        }else {
        printf("\nLa operacion ha sido cancelada.");}

    }else {
        printf("\nLa patente ingresado no se encuentra en el sistema o ya esta dada de baja.");
    }
}
//************************************************************************************
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
void modificarE(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol){
    int id;
    int indice;
    char patente[6];
    char seguir = 'n';
    printf("\nIngrese la patente del auto que quiera modificar: ");
    scanf("%s", patente);
    for(int i = 0; i < tam ; i++){

        if(strcmpi(patente,vec[i].patente) == 0 && vec[i].estado == OCUPADO){
           id = vec[i].id;
           }
    }
    indice = buscarE(vec,tam,id);
    if (indice != -1 && vec[indice].estado == OCUPADO){
        mostrarE(vec[indice],vecMar,tamMar,vecCol,tamCol);
        printf("\nDesea modificar este auto?Ingrese S/N: ");
        fflush(stdin);
        scanf("%c" , &seguir);
        fflush(stdin);
        if(seguir == 's' || seguir == 'S'){

            menuModificar(vec,tam,vecMar,tamMar,vecCol,tamCol,indice);
            mostrarE(vec[indice],vecMar,tamMar,vecCol,tamCol);
        }else{
            printf("\nLa operacion ha sido cancelada");
        }

    }else {
        printf("\nLa patente ingresada no se encuentra en el sistema ono esta dada de alta.");
    }
}
//**********************************************************************
void menuModificar(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol,int indice){

int opcion;
int validar =  -1;
char aux[51];

do{
        system("cls");
    printf("\nIngrese una opcion: ");
    printf("\n1.Modificar Color .\n");
    printf("\n2.Modificar Modelo .\n");
    printf("\n3.Salir .\n");
    scanf("%d", &opcion);

    switch(opcion){
//*******************************************************
    case 1:
           validar = -1;
    while(validar == -1){
            printf("\nIngrese un codigo de color");
            printf("\n5000.Negro");
            printf("\n5001.Blanco");
            printf("\n5002.Gris");
            printf("\n5003.Rojo :");
            printf("\n5004.Azuñ\n :");
            scanf("%s", aux);
            validar = validarInt(5000,5004,aux);
            if(validar == -1){
                printf("\nPor favor ingrese una opcion correcta.");
            }
    }
    vec[indice].idColor = atoi(aux);
    strcpy(aux," ");
        break;
//********************************************************
    case 2:
        validar =-1;
        while ( validar == -1){
            fflush(stdin);
            printf("\nIngrese anio de modelo: ");
            scanf("%s", aux);
            validar = validarInt(1900,2020,aux);
            if( validar == -1){
                printf("\nEl año debe estar entre 1900 y 2020");
            }
        }
        vec[indice].modelo = atoi(aux);
        strcpy(aux," ");


        break;
//*******************************************************
    default:
        printf("\nIngrese una opcion correcta. \n");
        break;

    }
}while(opcion != 3);
}
//********************************************************************
int buscarLleno(eAuto vec[],  int tam){

int estado = -1;
for(int i = 0;i <tam ; i++){

    if (vec[i].estado == OCUPADO){
        estado = OCUPADO;
        break;
    }
}
return estado;
}
//**********************************************************************
void listarAutos(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol){

eAuto aux;
for(int i = 0; i < tam-1; i++){
    for(int j = 0; j < tam ; j++){

        if(vec[i].idMarca > vec[j].idMarca ){
            aux = vec[i];
            vec[i] = vec[j];
            vec[j] = aux;

        }
    }
}
for(int i = 0; i < tam-1; i++){
    for(int j = 0; j < tam ; j++){
        if(vec[i].idMarca == vec[j].idMarca){

            if(strcmp(vec[i].patente,vec[j].patente) < 0 ){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
        }
        }
    }
}
for(int i = 0; i < tam ;i ++){
        if(vec[i].estado == OCUPADO){

            mostrarE(vec[i],vecMar,tamMar,vecCol,tamCol);
        }
}
printf("\n");

}
//**********************************************************************************

void altaTrabajo(eAuto vec[], int tam,eServicio vecSer[], int tamSer,eTrabajo vecTra[], int tamTra){
    int validar = -1;
    char aux[50];
    char patenteNum[6];
    char patenteCar[3];
    char patente[6];
    int contador=0;
    int indice = generarIdTrabajos();
    vecTra[indice].id = indice;
//*********************************************************************************************************
//**********************************VALIDO PATENTE*********************************************************
//*********************************************************************************************************
    validar = -1;
        while (validar == -1){
                while(validar == -1){

                system("pause");
                system("cls");
                contador = 0;
            fflush(stdin);
            printf("\nLa patente debe estar compuesta por 3 digitos numericos al principio y 3 al final:");
            printf("\nIngrese los 3 digitos numericos: ");
            scanf("%s", aux);
            validar = validarInt(0,999,aux);
            for(int i = 0; i < strlen(aux); i++){
                if( isdigit(aux[i]) != 0){
                   contador ++;
                   }else{
                    break;
                   }
            }
            if (contador != 3){
                validar = -1;
            }
            contador = 0;
            if( validar == -1){
                printf("\nPor favor solo ingrese los 3 primeros digitos: ");
            }

        strcpy(patenteNum,aux);
        strcpy(aux," ");

                }
        validar = -1;
        while (validar == -1){
                contador = 0;
            fflush(stdin);
            printf("\nIngrese los 3 digitos alfabeticos: ");
            scanf("%s", aux);
            validar = validarNombre(aux);
            for(int i = 0; i < strlen(aux); i++){
                if( isalpha(aux[i]) != 0){
                   contador ++;
                   }else{
                    break;
                   }
            }
             if (contador != 3){
                validar = -1;
            }
            if( validar == -1){
                printf("\nPor favor solo ingrese las 3 letras de la patente: ");
            }
        }
        strcpy(vecTra[indice].patente,patenteNum);
        strcpy(patenteCar,aux);
        strcpy(aux," ");
        validarPatente(patenteCar,vecTra[indice].patente,patente);// aca esta el problema
//*********************Valido si esxiste patente*************
        for(int i = 0; i < tam; i++){
            if(strcmp(vec[i].patente,patente) == 0 && vec[i].estado == OCUPADO){
                strcpy(vecTra[indice].patente,patente);
                validar = 0;
                break;
            }
        }
        if(validar != 0){
            printf("\nLa patente ingresada no esta registrada: (%s) en el sistema o no esta dada de alta.",patente);
            validar = -1;
        }
        }
//****************************************************************************************************
//*************************************Fin validar patente********************************************
//****************************************************************************************************
//*************************************SERVICIO******************************************************
    validar = -1;
    while(validar == -1){
            printf("\nIngrese un codigo de servicio");
            printf("\n20000.Lavado : $250");
            printf("\n20001.Pulido: $300");
            printf("\n20002.Encerado : $400");
            printf("\n20003.Completo : $600\n");
            scanf("%s", aux);
            validar = validarInt(20000,20003,aux);
            if(validar == -1){
                printf("\nPor favor ingrese una opcion correcta.");
            }
    }
    vecTra[indice].idServicio = atoi(aux);
    strcpy(aux," ");
//**************************FECHA*****************************************
//**************************VALIDO FECHA**********************************************
    validar = -1;
    while( validar == -1){
            printf("\nIngrese anio de ingreso: ");
            scanf("%s", aux);
            validar = validarInt(1900,2100,aux);
            if( validar == -1){

             printf("\nEl año de ingreso debe estar entre 1900 y 2100.");
            }
            }
            vecTra[indice].fecha.anio=atoi(aux);
            strcpy(aux," ");
            validar = -1;
//***************MES********************************************************
    while( validar == -1){
            printf("\nIngrese mes de ingreso: ");
            scanf("%s", aux);
            validar = validarInt(1,12,aux);
            if( validar == -1){

             printf("\nEl mes de ingreso es incorrecto.");
            }
    }
    vecTra[indice].fecha.mes=atoi(aux);
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
     vecTra[indice].fecha.dia = atoi(aux);
     strcpy(aux," ");
     vecTra[indice].estado == OCUPADO;
     printf("\nServicio ingresado con exito!: ");
     mostrarTrabajo(vecTra[indice],vecSer,tamSer);
}


//*********************************************
void mostrarTrabajos(eTrabajo vecTra[], int tamTra, eServicio vecSer[], int tamSer){

    for(int i = 0; i<tamTra; i++){

        if(vecTra[i].estado == OCUPADO){
            mostrarTrabajo(vecTra[i],vecSer,tamSer);
        }
    }
}
//**********************************************************************************
void mostrarTrabajo(eTrabajo vecTra, eServicio vecSer[], int tamSer){
    char servicio[20];
    float precio;
    for(int i = 0; i< tamSer; i ++){
        if(vecSer[i].id == vecTra.idServicio){
            strcpy(servicio,vecSer[i].descripcion);
            precio = vecSer[i].precio;
        }
    }
    printf("\nServicio: %s ",servicio);
    printf("Precio: %.2f ",precio);
    printf("Patente: %s ",vecTra.patente);
    printf("Fecha: %02d/%02d/%02d .",vecTra.fecha.dia,vecTra.fecha.mes,vecTra.fecha.anio);
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
//****************************************************
