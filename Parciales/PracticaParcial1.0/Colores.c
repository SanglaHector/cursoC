#include "Colores.h"
void programaColores(eColor vecCol[], int tamCol){
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

            break;
        case 3:

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

int id;
    int indice = buscarLibreCol(vecCol,tamCol);

    if (indice == -1){
        printf("\nNo hay espacio para agregar empleados.");
    }else{

            pedirDatosCol(vecCol,tamCol,indice);
            vecCol[indice].estado = OCUPADO;
            vecCol[indice].id = generarIdCol();
            printf("\nEmpleado ingresado con exito: \n");
            mostrarCol(vecCol[indice],tamCol);
        }
    }

//****************************************************************************************************************
int generarIdCol()
{
    static int id= 5005;
printf("\nen generar id: %d", id);
    return id++;
}
//****************************************************************************************************************
void pedirDatosCol(eColor vecCol[], int tamCol, int indice){

char aux [20];
int validar;
printf("\nIngrese un color: ");
fflush(stdin);
gets(aux);
validar = validarNombre(aux);
if( validar != -1){
    for ( int i = 0; i < tamCol ; i ++){

        if(strcmpi(vecCol[i].descripcion,aux) == 0){
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
void mostrarCol(eColor vecCol, int tamCol){
    printf("\n entro a mostrar col, indice: %d",vecCol.id);// aca ya llega mal el id
    if(vecCol.estado == OCUPADO){
        printf("\nColor: %s Id: %d", vecCol.descripcion,vecCol.id);
    }
}
//**************************************************************************************************************
void inicializarColores(eColor vec[] , int tam){

    for(int i = 0; i < tam ; i++){

        vec[i].estado = VACIO;
    }
}
//**************************************************************************************************************
