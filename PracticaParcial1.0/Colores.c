#include "Colores.h"

int validarNombre(char nombre[]);
void formatearNombre(char vec[]);
void altaColores(eColor vecCol[], int tamCol);
void modificarColor(eColor vec[],  int tam);
void bajaColor(eColor vec[], int tam);


void programaColores(eColor vecCol[], int tamCol){
system("cls");
int opcion;
do
    {

        printf("1-Alta color\n");
        printf("2-Modificar color\n");
        printf("3-Baja color\n");
        printf("4-Salir\n");
        printf("Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            altaColores(vecCol,tamCol);
            break;
        case 2:
            modificarColor(vecCol,tamCol);
            break;
        case 3:
            bajaColor(vecCol,tamCol);
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
void altaColores(eColor vecCol[], int tamCol){

    int indice = buscarLibreCol(vecCol,tamCol);

    if (indice == -1){
        printf("\nNo hay espacio para agregar colores.");
    }else{

            pedirDatosCol(vecCol,tamCol,indice);
            vecCol[indice].estado = OCUPADO;
            vecCol[indice].id = generarIdCol();
            printf("\nColor ingresado con exito: \n");
            mostrarCol(vecCol[indice]);
        }
    }
//****************************************************************************************************************
int generarIdCol()
{
    static int id= 5005;
    return id++;
}
//****************************************************************************************************************
void pedirDatosCol(eColor vecCol[], int tamCol, int indice){

char aux [20];
int validar = -1;
int longitud;
while ( validar == -1){

    printf("\nIngrese un color: ");
    fflush(stdin);
    gets(aux);
    fflush(stdin);
    longitud = strlen(aux);
    validar = validarNombre(aux);
    if(longitud == 0){
        validar =  -1;
    }
    if( validar != -1){
        for ( int i = 0; i < tamCol ; i ++){

            if(strcmpi(vecCol[i].descripcion,aux) == 0 && vecCol[i].estado == OCUPADO){
                validar = -1;
                printf("\nEl color ingresado ya existe");
                break;
            }
        }
    }else{
    printf("\nEl programa solo acepta digitos alfabeticos para los nombres.");
    }
    if ( validar != -1){
        formatearNombre(aux);
        strcpy(vecCol[indice].descripcion,aux);
    }
}

}
//**************************************************************************************************************
int buscarLibreCol(eColor vec[], int tam){
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
void mostrarCol(eColor vecCol){

    if(vecCol.estado == OCUPADO){
        printf("%10s%10d\n", vecCol.descripcion,vecCol.id);
    }

}
//**************************************************************************************************************
void inicializarColores(eColor vec[] , int tam){

    for(int i = 0; i < tam ; i++){

        vec[i].estado = VACIO;
    }

}
//**************************************************************************************************************
void modificarColor(eColor vec[],  int tam){
    char aux[20];
    int validar = -1;
    int indice;
    mostrarColores(vec,tam);
    printf("\nIngrese el color que quiera modificar: ");
    fflush(stdin);
    scanf("%s", aux);
    for(int i = 0; i < tam ; i++){

        if(strcmpi(aux,vec[i].descripcion) ==  0){
            validar = 1;
            indice = i;
        }
    }
    if ( validar != -1 ){

        printf("\nIngrese el color por el cual reemplazar al '%s' : ", aux);
        strcpy(aux," ");
        fflush(stdin);
        scanf("%s", aux);

        for(int i = 0 ; i < tam ; i++){
            if(strcmpi(aux,vec[i].descripcion)== 0){
                    printf("\nEl color en posicion %d es %s", i, vec[i].descripcion);
                printf("\nEste color ya existe: \n");
                mostrarCol(vec[i]);
                validar =  -1;
            }
        }
    }if (validar != -1){
        formatearNombre(aux);
        strcpy(vec[indice].descripcion,aux);
        printf("\nSe ha modificado el color exitosamente!\n");
        mostrarCol(vec[indice]);
    }else{
        printf("\nLa operacion ha sido cancelada.\n");}
}
//******************************************************************************
void bajaColor(eColor vec[], int tam){
    int indice;
    char aux[20];
    int validar = -1;
    printf("\nIngrese el color que desee dar de baja: ");
    scanf("%s", aux);
    fflush(stdin);

    for(int i = 0; i< tam ; i++){

        if(strcmpi(aux,vec[i].descripcion) == 0){
            validar = 1;
            indice = i;
        }
    }
    if( validar == 1){
        //printf("\nEl color :");
        mostrarCol(vec[indice]);
        printf("\nLa baja se genero correctamente!\n");
        vec[indice].estado = VACIO;
    }else {
        printf("\nNo existe el color %s o no esta dado de alta.\n", aux);
    }
}
//**************************************************************************
void hardCodearColores(eColor vec[], int tam){
    eColor ficticios[] ={
        {5000,"Negro",1},
        {5001,"Blanco",1},
        {5002,"Gris",1},
        {5003,"Rojo"},
        {5004,"Azul",1}
    };
    for(int i = 0; i < tam; i ++){

        vec[i] = ficticios[i];
    }
}
//*************************************************************************
void mostrarColores(eColor vec[], int tam){

    printf("    Color:       Id:\n");
    for(int i = 0; i < tam ; i ++){
        if(vec[i].estado == OCUPADO){
            mostrarCol(vec[i]);
        }
    }
    printf("\n");
}
//************************************************************************
