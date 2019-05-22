#include "Clientes.h"

//******************************************************************************
void programaClientes(eCliente vecCli[], int tamCli){
    system("cls");
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
            printf("   Nombre: Apellido:     Sexo:       Id:\n");
            mostrarCli(vecCli[indice]);
        }
    }
//****************************************************************************************************************
int generarIdCli()
{
    static int id= 1;
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
validar = -1;
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
validar = -1;
while ( validar == -1){

    printf("\nIngrese el sexo del cliente: ");
    fflush(stdin);
    scanf("%c", &aux.sexo);
    fflush(stdin);
    validar = validarSexo(aux.sexo);
    if (validar == -1){
        printf("\nPor favor solo ingrese los digitos M o F.");
    }
}
system("cls");
printf("\n\nSe dio de alta correctamente el sexo");
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
        printf("%10s%10s%10c      %04d\n", vecCli.nombre,vecCli.apellido,vecCli.sexo,vecCli.id);
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
    eCliente aux;
    int id;
    int validar = -1;
    int indice ;
    int opcion;
    mostrarClientes(vec,tam);
    while(validar == -1)
    {
        printf("\nIngrese el id del Cliente que quiera modificar: ");
        fflush(stdin);
        scanf("%s", aux.nombre);
        validar = validarInt(0,9999,aux.nombre);
        if ( validar == 1)
        {
            id = atoi(aux.nombre);
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
    if (validar == 1)
    {
        do
        {
            printf("\nIngrese la opcion que quiera modificar: ");
            printf("\n1. Nombre ");
            printf("\n2. Apellido ");
            printf("\n3. Sexo ");
            scanf("%d", &opcion);
            switch(opcion)
            {
            case 1:
                while ( validar == -1){
                     printf("\nIngrese el nobmre del cliente: ");
                     fflush(stdin);
                     gets(aux.nombre);
                     fflush(stdin);
                     validar = validarNombre(aux.nombre);
                     if (validar == -1){
                       printf("\nPor favor solo ingrese digitos afabeticos.");
                     }else
                     {
                         strcpy(vec[indice].nombre, aux.nombre);
                     }
                }
                break;
            case 2:
                while ( validar == -1){

                    printf("\nIngrese el apellido del cliente: ");
                    fflush(stdin);
                    gets(aux.apellido);
                    fflush(stdin);
                    validar = validarNombre(aux.apellido);
                    if (validar == -1){
                        printf("\nPor favor solo ingrese digitos afabeticos.");
                    }else
                    {
                        strcpy(vec[indice].apellido, aux.apellido);
                    }
                }
                break;
            case 3:
                while ( validar == -1){

                    printf("\nIngrese el sexo del cliente: ");
                    fflush(stdin);
                    scanf("%c", &aux.sexo);
                    fflush(stdin);
                    validar = validarSexo(aux.sexo);
                    if (validar == -1){
                        printf("\nPor favor solo ingrese los digitos M o F.");
                    }else
                    {
                        vec[indice].sexo = aux.sexo;
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
        printf("\nNo se ha encontrado un cliente de alta con el numero de id %d", id);
    }
}
//******************************************************************************
void bajaCliente(eCliente vec[], int tam){
    int indice;
    int id;
    int validar = -1;
    printf("\nIngrese el id del  Cliente que desee dar de baja: ");
    scanf("%d", &id);
    fflush(stdin);

    for(int i = 0; i< tam ; i++){

        if(id == vec[i].id){
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
        printf("\nNo existe el id: '%d' o no esta dado de alta.\n",id );
    }
}
//**************************************************************************
void hardCodearClientes(eCliente vec[], int tam){
    eCliente ficticios[] ={
        {1234,"Hector","Sangla",'m',1},
        {5678,"Maria","Espada",'f',1},
        {9012,"Alberto","Sanchez",'m',1},
        {3456,"Sabrina","Rodriguez",'f',1},
        {7890,"Hernan","Fernandez",'m',1}
    };
    for(int i = 0; i < tam; i ++){

        vec[i] = ficticios[i];
    }
}
//*************************************************************************
void mostrarClientes(eCliente vec[], int tam){

    printf("   Nombre: Apellido:     Sexo:       Id:\n");
    for(int i = 0; i < tam ; i ++){
        if(vec[i].estado == OCUPADO){
            mostrarCli(vec[i]);
        }
    }
    printf("\n");
}
//************************************************************************
