#include "ABM.h"
//********************************************************************************************************
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

//*******************PIDO DATOS************************************************************************
void pedirDatos(eAuto vec[], int tam, int indice, eMarca vecMar[], int tamMAr, eColor vecCol[], int tamCol){
    int validar = -1;
    char aux[50];
    int auxInt = 0;
    char patenteNum[6];
    char patenteCar[3];
    char patente[6];
    int contador=0;
//*********************VALIDO PATENTE******************************************************************
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
//********************VALIDO MODELO**************************************************************
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

//************************MARCA********************************************************************
    validar = -1;
    auxInt = 0;
    while(validar == -1){
            printf("\nIngrese un codigo de marca");
            mostrarMarcas(vecMar,tamMAr);
            scanf("%d", &auxInt);
            for(int i = 0; i < tamMAr; i++)
            {
                if(vecMar[i].id == auxInt && vecMar[i].estado == OCUPADO)
                {
                    validar = 1;
                    break;
                }
            }
            if(validar == -1){
                printf("\nPor favor ingrese una opcion correcta.");
            }
    }
    vec[indice].idMarca = auxInt;
//************************COLOR***********************************************************************
    validar = -1;
    auxInt = 0;
    while(validar == -1){
            printf("\nIngrese un codigo de color");
            mostrarColores(vecCol,tamCol);
            fflush(stdin);
            scanf("%d", &auxInt);
            fflush(stdin);
            validar = -1;
            for(int i = 0; i < tamCol; i++)
            {
                if(vecCol[i].estado == OCUPADO && vecCol[i].id == auxInt)
                {
                    validar = 1;
                    break;
                }
            }
            if(validar == -1){
                printf("\nPor favor ingrese una opcion correcta.");
            }
    }
    vec[indice].idColor = auxInt;
    auxInt = 0;
//**********************TERIMINE VALIDACION***********************************************************
            vec[indice].estado = OCUPADO;
            printf("\nDatos ingresados con exito!\n");
}
//****************************************************************************************************
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
//********************************************************************************************
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
//****************************************************************************************************
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
//****************************************************************************************************
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
//****************************************************************************************************
    default:
        printf("\nIngrese una opcion correcta. \n");
        break;

    }
}while(opcion != 3);
}
//****************************************************************************************************
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
//*****************************************************************************************************
void listarMarcas(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol){

    for(int i = 0; i < tamMar; i++){

        printf("\n%s\n",vecMar[i].descripcion);
    }
printf("\n");
}
//******************************************************************************************************
void listarColores(eAuto vec[], int tam, eMarca vecMar[], int tamMar,eColor vecCol[],  int tamCol){

        for(int i = 0; i < tamCol; i++){

        printf("\n%s\n",vecCol[i].descripcion);
    }
    printf("\n");
}
//*******************************************************************************************************
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
//*****************************************************************************************************
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
//********************************************************************************************************
void altaTrabajo(eAuto vec[], int tam,eServicio vecSer[], int tamSer,eTrabajo vecTra[], int tamTra){
    int indice = buscarLibreTra(vecTra,tamTra);

    if (indice == -1){
        printf("\nNo hay espacio para agregar Trabajos.");
    }else{

            pedirDatosTra(vecTra,tamTra,vec,tam,vecSer,tamSer,indice);
            vecTra[indice].estado = OCUPADO;
            vecTra[indice].id = generarIdTra();
            printf("\nTrabajo ingresado con exito: \n");
            printf("\n  Patente:    Id:   Fecha:      Servicio:    Precio:\n");
            mostrarTrabajo(vecTra[indice],vecSer,tamSer);
        }
}
//****************************************************************************************************************
void pedirDatosTra(eTrabajo vecTra[], int tamTra, eAuto vecAuto[], int tamAuto, eServicio vecSer[], int tamSer,int indice){

eTrabajo auxTra;
eAuto    auxAuto;
int validar = -1;
int indiceAux;
while ( validar == -1){

    printf("\nIngrese la patente del auto a cual quiere asignarle el trabajo: ");
    fflush(stdin);
    gets(auxAuto.patente);
    fflush(stdin);
    for(int i = 0 ; i < tamAuto; i++)
    {
        if(strcmpi(vecAuto[i].patente,auxAuto.patente) == 0 && vecAuto[i].estado == OCUPADO)
        {
            validar = 1;
            indiceAux = i;
            break;
        }
    }
    if (validar == -1){
        printf("\nLa patente ingresada no se encuentra dada de alta en el sistema\n.");
    }
}
strcpy(vecTra[indice].patente,vecAuto[indiceAux].patente);
validar = -1;
while ( validar == -1){

    printf("\nIngrese el servicio: ");
    fflush(stdin);
    mostrarServicios(vecSer,tamSer);
    scanf("%d", &indiceAux);

    for(int i = 0 ; i < tamSer; i++)
    {
        if(vecSer[i].id == indiceAux && vecSer[i].estado == OCUPADO)
        {
            validar = 1;
            indiceAux = i;
            break;
        }
    }
    if ( validar == 1)
    {
        vecTra[indice].idServicio = vecSer[indiceAux].id;
    }
}
validar = -1;
    while( validar == -1){
            printf("\nIngrese anio de ingreso: ");
            scanf("%d", &auxTra.fecha.anio);

            printf("\nIngrese mes de ingreso: ");
            scanf("%d", &auxTra.fecha.mes);

            printf("\nIngrese dia de ingreso: ");
            scanf("%d", &auxTra.fecha.dia);

            validar = validarFecha(auxTra.fecha.dia,auxTra.fecha.mes,auxTra.fecha.anio);
            if( validar == -1){
             printf("\nLa fecha de ingreso no existe.");
            }else if(validar == -2)
            {
                printf("\nEl año debe estar dentro del rango de 1900 y 2020");
            }
            else
            {
                vecTra[indice].fecha.anio = auxTra.fecha.anio;
                vecTra[indice].fecha.mes = auxTra.fecha.mes;
                vecTra[indice].fecha.dia = auxTra.fecha.dia;
            }
     }
}
//**********************************************************************************
int generarIdTrabajos()
{
    static int id = 0;

    return id++;
}
//**********************************************************************************
void mostrarTrabajos(eTrabajo vecTra[], int tamTra, eServicio vecSer[], int tamSer){
            printf("\n  Patente:    Id:   Fecha:      Servicio:    Precio:\n");
    for(int i = 0; i<tamTra; i++){

        if(vecTra[i].estado == OCUPADO){
            mostrarTrabajo(vecTra[i],vecSer,tamSer);
        }
    }
}
//********************************************************************************
void mostrarTrabajo(eTrabajo vecTra, eServicio vecSer[], int tamSer){
    char servicio[20];
    float precio;
    for(int i = 0; i< tamSer; i ++){
        if(vecSer[i].id == vecTra.idServicio){
            strcpy(servicio,vecSer[i].descripcion);
            precio = vecSer[i].precio;
        }
    }
    printf("\n%10s ",vecTra.patente);
    printf("  %04d ", vecTra.id);
    printf("  %02d/%02d/%02d",vecTra.fecha.dia,vecTra.fecha.mes,vecTra.fecha.anio);
    printf("  %10s ",servicio);
    printf("  %.2f \n",precio);

}
//****************************************************************************************
void programaTrabajos(eTrabajo vecTra[], int tamTra, eAuto vecAuto[], int tamAuto, eServicio vecSer[], int tamSer){
    system("cls");
int opcion;
do
    {

        printf("1-Alta Trabajo\n");
        printf("2-Modificar Trabajo\n");
        printf("3-Baja Trabajo\n");
        printf("4-Salir\n");
        printf("Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            altaTrabajo(vecAuto,tamAuto,vecSer,tamSer,vecTra,tamTra);
            break;
        case 2:
            modificarTrabajo(vecTra,tamTra,vecSer,tamSer,vecAuto,tamAuto);
            break;
        case 3:
            bajaTrabajo(vecTra,tamTra,vecSer,tamSer);
            break;
        case 4:
            printf("Hasta luego!\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }

        system("pause");
        system("cls");

    }
    while(opcion !=4);

}
//**************************************************************************************************************
void modificarTrabajo(eTrabajo vec[],  int tam, eServicio vecSer[], int tamSer, eAuto vecAuto[], int tamAuto){
    eTrabajo aux;
    int id;
    int validar = -1;
    int indice ;
    int opcion;
    mostrarTrabajos(vec,tam,vecSer, tamSer);
    while(validar == -1)
    {
        printf("\nIngrese el id del Trabajo que quiera modificar: ");
        fflush(stdin);
        scanf("%s", aux.patente);
        validar = validarInt(0,9999,aux.patente);//uso este
        if ( validar == 1)
        {
            id = atoi(aux.patente);
        }
        else
        {
            printf("\nIngrese un valor correcto: ");
        }
    }
    for(int i = 0; i < tam ; i++)
        {
            if(id == vec[i].id && vec[i].estado == OCUPADO)
            {
                validar = 1;
                indice = i;
            }
        }
        strcpy(aux.patente," ");
    if (validar == 1)
    {
        do
        {
            printf("\nIngrese la opcion que quiera modificar: ");
            printf("\n1. Patente ");
            printf("\n2. Servicio ");
            printf("\n3. Fecha ");
            scanf("%d", &opcion);
            switch(opcion)
            {
            case 1:
                validar = -1;
                while ( validar == -1){
                     printf("\nIngrese la patente del auto a la cual se le designo el Trabajo: ");
                     fflush(stdin);
                     gets(aux.patente);
                     fflush(stdin);
                     validar = -1;
                     for(int i = 0; i < tamAuto; i ++)
                     {
                         if(strcmpi(aux.patente,vecAuto[i].patente) == 0)
                         {
                            validar = 1;
                            break;
                         }
                     }
                     if (validar == -1){
                       printf("\nLa patente ingresada no se encuetra dada de alta en el sistema.");
                     }else
                     {
                         strcpy(vec[indice].patente, aux.patente);
                     }
                }
                break;
            case 2:
                validar =-1;
                while ( validar == -1){

                    mostrarServicios(vecSer,tamSer);
                    printf("\nIngrese el id del  servicio del Trabajo: ");
                    fflush(stdin);
                    scanf("%d", &aux.idServicio);
                    fflush(stdin);
                    validar = -1;
                    for(int i = 0; i < tamSer; i++)
                    {
                        if(aux.idServicio == vecSer[i].id)
                        {
                            validar = 1;
                        }
                    }
                    if (validar == -1){
                        printf("\nPor favor ingrese un id corecto.");
                    }else
                    {
                        vec[indice].idServicio = aux.idServicio;
                    }
                }
                break;
            case 3:
                validar =-1;
                while ( validar == -1){

                    printf("\nIngrese la nueva fecha: ");
                    printf("\nIngrese el dia: ");
                    fflush(stdin);
                    scanf("%d",&aux.fecha.dia);
                    fflush(stdin);
                    printf("\nIngrese el mes: ");
                    scanf("%d",&aux.fecha.mes);
                    fflush(stdin);
                    printf("\nIngrese el anio: ");
                    scanf("%d",&aux.fecha.anio);

                    validar = validarFecha(aux.fecha.dia,aux.fecha.mes,aux.fecha.anio);

                    if (validar == -1){
                        printf("\nPor favor ingrese una fecha correcta.");
                    }else
                    {
                        vec[indice].fecha.dia = aux.fecha.dia;
                        vec[indice].fecha.mes = aux.fecha.mes;
                        vec[indice].fecha.anio = aux.fecha.anio;
                    }
                }
                break;
            default:
                printf("\nOpcion incorrecta");
                validar = -1;
                break;
            }
        }while(validar == -1);
    }
    else
    {
        printf("\nNo se ha encontrado un Trabajo de alta con el numero de id %d", id);
    }
}
//******************************************************************************
void bajaTrabajo(eTrabajo vec[], int tam, eServicio vecSer[], int tamSer){
    int indice;
    int id;
    int validar = -1;
    printf("  Patente: Servicio:       Id:  Fecha:\n");
    mostrarTrabajos(vec,tam,vecSer,tamSer);
    printf("\nIngrese el id del  Trabajo que desee dar de baja: ");
    scanf("%d", &id);
    fflush(stdin);

    for(int i = 0; i< tam ; i++){

        if(id == vec[i].id){
            validar = 1;
            indice = i;
        }
    }
    if( validar == 1){
        //printf("\nEl Trabajo :");
        mostrarTrabajo(vec[indice],vecSer,tamSer);
        printf("\nLa baja se genero correctamente!\n");
        vec[indice].estado = VACIO;
    }else {
        printf("\nEl id ingresado no esta dado de alta en el sistema.\n");
    }
}
//************************************************************************

