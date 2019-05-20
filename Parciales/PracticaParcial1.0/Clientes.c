#include "Clientes.h"

//******************************************************************************
void programaClientes(eCliente vecCli[], int tamCli){
int opcion;
do
    {

        printf("1-Alta Cliente\n");
        printf("2-Modificar Cliente\n");
        printf("3-Baja Cliente\n");
        printf("4-Salir\n");
        printf("Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            altaClientes(vecCli,tamCli);
            break;
        case 2:
            modificarCliente(vecCli,tamCli);
            break;
        case 3:
            bajaCliente(vecCli,tamCli);
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
//**************************************************************************************************************
void altaClientes(eCliente vecCli[], int tamCli){

    int indice = buscarLibreCli(vecCli,tamCli);

    if (indice == -1){
        printf("\nNo hay espacio para agregar Clientes.");
    }else{

            pedirDatosCli(vecCli,tamCli,indice);
            vecCli[indice].estado = OCUPADO;
            vecCli[indice].id = generarIdCli();
            printf("\nCliente ingresado con exito: \n");
            mostrarCli(vecCli[indice]);
        }
    }
//****************************************************************************************************************
int generarIdCli()
{
    static int id= 0;
    return id++;
}
//****************************************************************************************************************
void pedirDatosCli(eCliente vecCli[], int tamCli, int indice){

eCliente aux;
int validar = -1;
int longitud;
while ( validar == -1){

    printf("\nIngrese el nobmre del cliente: ");
    fflush(stdin);
    gets(aux.nombre);
    fflush(stdin);
    validar = validarNombre(aux.nombre);
    if (validar == -1){
        printf("\nPor favor solo ingrese digitos afabeticos.");
    }
}
while ( validar == -1){

    printf("\nIngrese el apellido del cliente: ");
    fflush(stdin);
    gets(aux.apellido);
    fflush(stdin);
    validar = validarNombre(aux.apellido);
    if (validar == -1){
        printf("\nPor favor solo ingrese digitos afabeticos.");
    }
}
while ( validar == -1){

    printf("\nIngrese el sexo del cliente: ");
    fflush(stdin);
    scanf("%c", aux.sexo);
    fflush(stdin);
    validar = validarSexo(aux.sexo);
    if (validar == -1){
        printf("\nPor favor solo ingrese los digitos M o F.");
    }
}

for ( int i = 0; i < tamCli ; i++){

    if(strcmpi(aux.nombre,vecCli[i].nombre) == 0 && strcmpi(aux.apellido,vecCli[i].apellido) == 0 && vecCli[i].estado == OCUPADO){
        printf("\nEste cliente ya se encuentra registrado en la base de memoria");
        validar = -1;
        break;
        }
    }


    if ( validar != -1){
        formatearNombre(aux.nombre);
        formatearNombre(aux.apellido);
        strcpy(vecCli[indice].nombre,aux.nombre);
        strcpy(vecCli[indice].apellido,aux.apellido);
        vecCli[indice].sexo = aux.sexo;

    }else {
        printf("\nLa operacion ha sido cancelada.\n");
    }
}
//**************************************************************************************************************
int buscarLibreCli(eCliente vec[], int tam){
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
void mostrarCli(eCliente vecCli){

    if(vecCli.estado == OCUPADO){
        printf("%10s%10d\n", vecCli.descripcion,vecCli.id);
    }

}
//**************************************************************************************************************
void inicializarClientes(eCliente vec[] , int tam){

    for(int i = 0; i < tam ; i++){

        vec[i].estado = VACIO;
    }

}
//**************************************************************************************************************
void modificarCliente(eCliente vec[],  int tam){
    char aux[20];
    int validar = -1;
    int indice;
    mostrarClientes(vec,tam);
    printf("\nIngrese el Cliente que quiera modificar: ");
    fflush(stdin);
    scanf("%s", aux);
    for(int i = 0; i < tam ; i++){

        if(strcmpi(aux,vec[i].descripcion) ==  0){
            validar = 1;
            indice = i;
        }
    }
    if ( validar != -1 ){

        printf("\nIngrese el Cliente por el cual reemplazar al '%s' : ", aux);
        strcpy(aux," ");
        fflush(stdin);
        scanf("%s", aux);

        for(int i = 0 ; i < tam ; i++){
            if(strcmpi(aux,vec[i].descripcion)== 0){
                    printf("\nEl Cliente en posicion %d es %s", i, vec[i].descripcion);
                printf("\nEste Cliente ya existe: \n");
                mostrarCli(vec[i]);
                validar =  -1;
            }
        }
    }if (validar != -1){
        formatearNombre(aux);
        strcpy(vec[indice].descripcion,aux);
        printf("\nSe ha modificado el Cliente exitosamente!\n");
        mostrarCli(vec[indice]);
    }else{
        printf("\nLa operacion ha sido cancelada.\n");}
}
//******************************************************************************
void bajaCliente(eCliente vec[], int tam){
    int indice;
    char aux[20];
    int validar = -1;
    printf("\nIngrese el Cliente que desee dar de baja: ");
    scanf("%s", aux);
    fflush(stdin);

    for(int i = 0; i< tam ; i++){

        if(strcmpi(aux,vec[i].descripcion) == 0){
            validar = 1;
            indice = i;
        }
    }
    if( validar == 1){
        //printf("\nEl Cliente :");
        mostrarCli(vec[indice]);
        printf("\nLa baja se genero correctamente!\n");
        vec[indice].estado = VACIO;
    }else {
        printf("\nNo existe el Cliente %s o no esta dado de alta.\n", aux);
    }
}
//**************************************************************************
void hardCodearClientes(eCliente vec[], int tam){
    eCliente ficticios[] ={
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
void mostrarClientes(eCliente vec[], int tam){

    printf("    Cliente:       Id:\n");
    for(int i = 0; i < tam ; i ++){
        if(vec[i].estado == OCUPADO){
            mostrarCli(vec[i]);
        }
    }
    printf("\n");
}
//************************************************************************
