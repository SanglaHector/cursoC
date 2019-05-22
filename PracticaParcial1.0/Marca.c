#include "Marca.h"

int validarNombre(char nombre[]);
void formatearNombre(char vec[]);
void altaMarca(eMarca vecMar[], int tamMar);
void modificarMarca(eMarca vec[],  int tam);
void bajaMarca(eMarca vec[], int tam);

void programaMarcas(eMarca vecMar[], int tamMar){
system("cls");
int opcion;
do
    {

        printf("1-Alta marca\n");
        printf("2-Modificar marca\n");
        printf("3-Baja marca\n");
        printf("4-Salir\n");
        printf("Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            altaMarcas(vecMar,tamMar);
            break;
        case 2:
            modificarMarca(vecMar,tamMar);
            break;
        case 3:
            bajaMarca(vecMar,tamMar);
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
void altaMarcas(eMarca vecMar[], int tamMar){

    int indice = buscarLibreCol(vecMar,tamMar);

    if (indice == -1){
        printf("\nNo hay espacio para agregar marcas.");
    }else{

            pedirDatosCol(vecMar,tamMar,indice);
            vecMar[indice].estado = OCUPADO;
            vecMar[indice].id = generarIdCol();
            printf("\nMarca ingresado con exito: \n");
            mostrarCol(vecMar[indice]);
        }
    }

//****************************************************************************************************************
int generarIdMarca()
{
    static int id= 1005;
    return id++;
}
//****************************************************************************************************************
void pedirDatosMarca(eMarca vecMar[], int tamMar, int indice){

char aux [20];
int validar = -1;
int longitud;
while ( validar == -1){

    printf("\nIngrese un marca: ");
    fflush(stdin);
    gets(aux);
    longitud = strlen(aux);
    validar = validarNombre(aux);
    if(longitud == 0){
        validar = -1;
    }
    if( validar != -1){
        for ( int i = 0; i < tamMar ; i ++){

            if(strcmpi(vecMar[i].descripcion,aux) == 0){
                validar = -1;
                printf("\nLa marca ingresado ya existe");
                break;
            }
        }
    }else{
    printf("\nEl programa solo acepta digitos alfabeticos para los nombres.");
    }
    if ( validar != -1){
        formatearNombre(aux);
        strcpy(vecMar[indice].descripcion,aux);
    }
}
}
//**************************************************************************************************************
int buscarLibreMarca(eMarca vec[], int tam){
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
void mostrarMarca(eMarca vecMar){

    if(vecMar.estado == OCUPADO){
        printf("\n%10s%10d\n", vecMar.descripcion,vecMar.id);
    }
}
//**************************************************************************************************************
void inicializarMarcas(eMarca vec[] , int tam){

    for(int i = 0; i < tam ; i++){

        vec[i].estado = VACIO;
    }
}
//**************************************************************************************************************
void modificarMarca(eMarca vec[],  int tam){
    char aux[20];
    int validar = -1;
    int indice;
    mostrarMarcas(vec,tam);
    printf("\nIngrese la marca que quiera modificar: ");
    fflush(stdin);
    scanf("%s", aux);
    for(int i = 0; i < tam ; i++){

        if(strcmpi(aux,vec[i].descripcion) ==  0){
            validar = 1;
            indice = i;
        }
    }
    if ( validar != -1 ){

        printf("\nIngrese la marca por el cual reemplazar al '%s' : ", aux);
        strcpy(aux," ");
        fflush(stdin);
        scanf("%s", aux);

        for(int i = 0 ; i < tam ; i++){
            if(strcmpi(aux,vec[i].descripcion)== 0){
                    printf("\nLa marca en posicion %d es %s", i, vec[i].descripcion);
                printf("\nEsta marca ya existe: \n");
                mostrarCol(vec[i]);
                validar =  -1;
            }
        }
    }if (validar != -1){
        formatearNombre(aux);
        strcpy(vec[indice].descripcion,aux);
        printf("\nSe ha modificado la marca exitosamente!\n");
        mostrarCol(vec[indice]);
    }else{
        printf("\nLa operacion ha sido cancelada.\n");}
}
//******************************************************************************
void bajaMarca(eMarca vec[], int tam){
    int indice;
    char aux[20];
    int validar = -1;
    printf("\nIngrese la marca que desee dar de baja: ");
    scanf("%s", aux);
    fflush(stdin);

    for(int i = 0; i< tam ; i++){

        if(strcmpi(aux,vec[i].descripcion) == 0){
            validar = 1;
            indice = i;
        }
    }
    if( validar == 1){
        //printf("\nEl marca :");
        mostrarCol(vec[indice]);
        printf("\nLa baja se genero correctamente!\n");
        vec[indice].estado = VACIO;
    }else {
        printf("\nNo existe la marca %s o no esta dado de alta.\n", aux);
    }
}
//**************************************************************************
void hardCodearMarcas(eMarca vec[], int tam){
    eMarca ficticios[] ={
    {1000,"Renault",1},
    {1001,"Fiat",1},
    {1002,"Ford",1},
    {1003,"Chevrolet",1},
    {1004,"Peugeot",1}
    };
    for(int i = 0; i < tam; i ++){

        vec[i] = ficticios[i];
    }
}
//***************************************************************************
void mostrarMarcas(eMarca vec[], int tam){

    printf("    Marca:       Id:\n");
    for(int i = 0; i < tam ; i ++){
        if(vec[i].estado == OCUPADO){
            mostrarMarca(vec[i]);
        }
    }
    printf("\n");
}
//**************************************************************************
