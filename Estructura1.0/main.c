#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define TAM 7
#define OCUPADO 1
#define VACIO 0

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{

    int legajo;
    float sueldo;
    char nombre[20];
    char apellido [20];
    char sexo;
    eFecha fechaIngreso;
    int estado;
    int sector;
}eEmpleado;

typedef struct{
    int id;
    char descripcion[20];
}eSector;

int buscarLibre(eEmpleado vec[], int tam);
int buscarE(eEmpleado vec[], int tam , int clave);
void inicializarE(eEmpleado [], int tam );
void altaE(eEmpleado [], int );
void bajaE(eEmpleado [], int );
void modificarE(eEmpleado vec[], int tam);
void mostrarE(eEmpleado e);
void mostrarEs(eEmpleado vec[], int tam);
void hardCodear(eEmpleado vec[], int tam);

int main()
{
    eEmpleado empleados[TAM];
    inicializarE(empleados,TAM);
    hardCodear(empleados,5);
    int opcion;
do
    {

        printf("1-Dar de Alta\n");
        printf("2-Mostrar Empleados\n");
        printf("3-Informes\n");
        printf("4-Modificar\n");
        printf("5-Dar de Baja\n");
        printf("6-Salir\n");
        printf("Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            altaE(empleados,TAM);
            break;
        case 2:
            mostrarEs(empleados,TAM);
            break;
        case 3:
            menuInformes();
            break;
        case 4:
            modificarE(empleados,TAM);
            break;
        case 5:
            bajaE(empleados,TAM);
            break;
        case 6:
            printf("Hasta luego!\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }

        system("pause");
        system("cls");

    }
    while(opcion !=6);

    return 0;
}
//**************************************************************************************************************
void inicializarE(eEmpleado vec[], int tam){

    for(int i = 0; i < tam ; i++){

        vec[i].estado = VACIO;
    }
}
//**************************************************************************************************************
void altaE(eEmpleado vec[], int tam){
    int legajo;
    int repetido;
    int indice = buscarLibre(vec,tam);
    float sueldoAux;
    eFecha fechaAux;
    char sexoAux;
    char nombreAux[20];
    char apellidoAux[20];


    if (indice == -1){
        printf("\nNo hay espacio para agregar empleados.");
    }else{
        printf("Ingrese el legajo: ");
        fflush(stdin);
        scanf("%d", &legajo);
        repetido = buscarE(vec,tam,legajo);
        if (repetido == -1){

            vec[indice].legajo = legajo;

            fflush(stdin);
            printf("\nIngrese nombre: ");
            scanf("%s", vec[indice].nombre);

            fflush(stdin);
            printf("\nIngrese apellido: ");
            scanf("%s", vec[indice].apellido);

            printf("\nIngrese sueldo: ");
            scanf("%f", &vec[indice].sueldo);

            fflush(stdin);
            printf("\nIngrese sexo: ");
            scanf("%c", &vec[indice].sexo);
            fflush(stdin);

            printf("\nIngrese anio de ingreso: ");
            scanf("%d", &vec[indice].fechaIngreso.anio);

            printf("\nIngrese mes de ingreso: ");
            scanf("%d", &vec[indice].fechaIngreso.mes);

            printf("\nIngrese dia de ingreso: ");
            scanf("%d", &vec[indice].fechaIngreso.dia);

            vec[indice].estado = OCUPADO;

            printf("\nDatos ingresados con exito!");
        }else{
            printf("\nEl legajo %d ya existe: ", legajo);
            mostrarE(vec[repetido]);
        }
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
void mostrarE(eEmpleado e){

   // printf("\nNOMBRE   APELLIDO    SEXO  SUELDO   FECHA DE INGRESO.\n");
    printf("Legajo: %d Nombre: %s Apellido: %s Sexo: %c Sueldo: %.2f Fecha: %02d/%02d/%02d \n",e.legajo,e.nombre,e.apellido,e.sexo,e.sueldo,e.fechaIngreso.dia,e.fechaIngreso.mes,e.fechaIngreso.anio);}
//**************************************************************************************************************
void bajaE(eEmpleado vec[], int tam){
    int legajo;
    int indice;
    char seguir = 'n';
    printf("\nIngrese el legajo que quiera eliminar: ");
    scanf("%d", &legajo);
    indice = buscarE(vec,tam,legajo);
    if (indice != -1 && vec[indice].estado == OCUPADO){
        mostrarE(vec[indice]);
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
void modificarE(eEmpleado vec[], int tam){
    int legajo;
    int indice;
    float sueldo;
    char seguir = 'n';
    printf("\nIngrese el legajo que quiera modificar: ");
    scanf("%d", &legajo);
    indice = buscarE(vec,tam,legajo);
    if (indice != -1 && vec[indice].estado == OCUPADO){
        mostrarE(vec[indice]);
        printf("\nIngrese el nuevo sueldo del empleado: ");
        scanf("%f", &sueldo);
        printf("\nEsta seguro que desea dar de baja este empleado? S/N: ");
        fflush(stdin);
        scanf("%c",&seguir);
        seguir = toupper(seguir);
        if( seguir == 'S'){

            vec[indice].sueldo = sueldo;
            printf("\nEl empleado se ha dado de baja con exito.");
        }else {
        printf("\nLa operacion ha sido cancelada.");}

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
    {6666,10550,"Maria","Espada",'f',{16,8,2011},1,4}
    };

    for(int i = 0; i < tam; i ++){

        vec[i] = ficticios[i];
    }
}
//**************************************************************************************************************
void mostrarEs(eEmpleado vec[], int tam){
    for(int i = 0 ; i < tam ; i ++){

        if (vec[i].estado == OCUPADO){
            mostrarE(vec[i]);
            }
    }
}
//**************************************************************************************************************
void menuInformes(){
    system(cls);

}
