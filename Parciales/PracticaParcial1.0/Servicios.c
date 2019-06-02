#include "Servicios.h"

int validarFloat(int min, int max, char num[]);
int validarNombre(char nombre[]);
void formatearNombre(char vec[]);
void altaServicios(eServicio vecSer[], int tamSer);
void modificarServicio(eServicio vec[],  int tam);
void bajaServicio(eServicio vec[], int tam);
//*******************
//******************
void listarServicios( eServicio vecSer[], int tamSer){

    printf("\n  Servicios Precios");
        for(int i = 0; i < tamSer; i++){
        printf("\n %10s %.2f$\n", vecSer[i].descripcion,vecSer[i].precio);
    }
    printf("\n");
}
//*******************************************************************
void programaServicios(eServicio vecSer[], int tamSer){
system("cls");
int opcion;
do
    {

        printf("1-Alta servicio\n");
        printf("2-Modificar servicio\n");
        printf("3-Baja servicio\n");
        printf("4-Salir\n");
        printf("Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            altaServicios(vecSer,tamSer);
            break;
        case 2:
            modificarServicio(vecSer,tamSer);
            break;
        case 3:
            bajaServicio(vecSer,tamSer);
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
void altaServicios(eServicio vecSer[], int tamSer){

    int indice = buscarLibreServicio(vecSer,tamSer);

    if (indice == -1){
        printf("\nNo hay espacio para agregar servicios.");
    }else{

            pedirDatosServicio(vecSer,tamSer,indice);
            vecSer[indice].estado = OCUPADO;
            vecSer[indice].id = generarIdServicio();
            printf("\nServicio ingresado con exito: \n");
            mostrarServicio(vecSer[indice]);
        }
    }

//****************************************************************************************************************
int generarIdServicio()
{
    static int id= 20005;
    return id++;
}
//****************************************************************************************************************
void pedirDatosServicio(eServicio vecSer[], int tamSer, int indice){

char aux [20];
int validar = -1;

while(validar == -1){

    mostrarServicios(vecSer,tamSer);
    printf("\nIngrese un servicio: ");
    fflush(stdin);
    gets(aux);
    validar = validarNombre(aux);
    if(strlen(aux) == 0){
        validar = -1;
    }
    if( validar != -1){
        for ( int i = 0; i < tamSer ; i ++){

            if(strcmpi(vecSer[i].descripcion,aux) == 0 && vecSer[i].estado == OCUPADO){
                validar = -1;
                printf("\nEl servicio ingresado ya existe");
                break;
            }
        }
    }else{
    printf("\nEl programa solo acepta digitos alfabeticos para los nombres.");
    }
    if ( validar != -1){
        formatearNombre(aux);
        strcpy(vecSer[indice].descripcion,aux);
        strcpy(aux," ");

        printf("\nIngrese el valor del servicio: ");
        scanf("%s", aux);
        fflush(stdin);
        validar = validarFloat(0,99999999,aux);
        if (validar != -1){

            vecSer[indice].precio = atof(aux);

        }else {
        printf("\nIngrese digitos numericos para el precio. La operacion ha sido cancelada!");
        }
    }
}
}
//**************************************************************************************************************
int buscarLibreServicio(eServicio vec[], int tam){
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
void mostrarServicio(eServicio vecSer){

        printf("\n%10s    %.2f      %6d\n", vecSer.descripcion,vecSer.precio,vecSer.id);
}
//**************************************************************************************************************
void inicializarServicios(eServicio vec[] , int tam){

    for(int i = 0; i < tam ; i++){

        vec[i].estado = VACIO;
    }
}
//**************************************************************************************************************
void modificarServicio(eServicio vec[],  int tam){
    char aux[20];
    int validar = -1;
    int id;
    int contador = 0;
    int encontre = 0;
    while ( validar == -1){

        mostrarServicios(vec,tam);
        printf("\nIngrese el id del servicio que quiera modificar: ");
        fflush(stdin);
        scanf("%s", aux);

        for(int i = 0; i <tam; i++){
            if(vec[i].estado == OCUPADO){
                contador ++;
            }
        }

        validar = validarInt(0,(20000+contador),aux);
        if(validar == -1){
            printf("\nPor favor ingrese una opcion correcta.\n");
        }
    }
    id = atoi(aux);
    for(int i = 0; i < tam; i++){

        if(vec[i].id == id && vec[i].estado == OCUPADO){
            encontre = 1;
            validar = -1;
            strcpy(aux," ");
            printf("\nIngrese un precio para el servicio: ");
            scanf("%s",aux);
            validar = validarInt(0,999999,aux);

            if (validar != -1){
                vec[i].precio = atof(aux);
                break;
            }else{
                printf("\nEl precio ingresado es incorrecto!La operacion ha sido cancelada\n.");
                break;
            }
        }
    }
    if (encontre != 1){
        printf("\nNo existe un servicio dada de alta con ese codigo.");
    }
}
//******************************************************************************
void bajaServicio(eServicio vec[], int tam){
    int indice;
    char aux[20];
    int validar = -1;
    char seguir = 'n';
    mostrarServicios(vec,tam);
    printf("\nIngrese el nombre del servicio que desee dar de baja: ");
    scanf("%s", aux);
    fflush(stdin);

    for(int i = 0; i< tam ; i++){

        if(strcmpi(aux,vec[i].descripcion) == 0){
            validar = 1;
            indice = i;
        }
    }
    if( validar == 1){

        mostrarServicio(vec[indice]);
        printf("\nDesea ejecuar la baja? Ingrese 's' para confirmar: ");
        scanf("%c", &seguir);
        if(seguir == 's'|| seguir == 'S')
        {
            printf("\nLa baja se genero correctamente!\n");
            vec[indice].estado = VACIO;
        }else
        {
            printf("\nLa operacion ha sido cancelada!");
        }
    }else {
        printf("\nNo existe el servicio %s o no esta dado de alta.\n", aux);
    }
}
//**************************************************************************
//**************************************************************************
void hardCodearServicios(eServicio vec[], int tam){
    eServicio ficticios[] ={
    {20000,"Lavado",250,1},
    {20001,"Pulido",300,1},
    {20002,"Encerado",400,1},
    {20003,"Completo",600,1}
    };
    for(int i = 0; i < tam; i ++){

        vec[i] = ficticios[i];
    }
}
//******************************************************************************
void mostrarServicios(eServicio vec[], int tam){

    printf("\n Servicio:   Precio:       Id:");
    for(int i = 0; i < tam ; i ++){
        if(vec[i].estado == OCUPADO){
            mostrarServicio(vec[i]);
        }
    }
}
