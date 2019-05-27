#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct{
int id;
char nombre[20];
char apellido[20];
float sueldo;
int estado;
}eEmpleado;


void mostrarEmpleados(eEmpleado* vec, int tam);
void mostrarEmpleado(eEmpleado* emp);
void imprimirEmpleados(eEmpleado* vec, int tam);
eEmpleado* newEmpleadoParam(int id, char* nombre, char* apellido, float sueldo);
void inicializarEmpleado(eEmpleado* vec, int tam);
eEmpleado* newEmpleado();
int buscarLibre(eEmpleado* vec, int tam);
void altaEmpleado( eEmpleado* vec, int tam);
void guardarEmpleadosBinarios(eEmpleado* vec, int tam);
void cargarEmpleados( eEmpleado* vec, int tam);


int main()
{
    char auxiliar = 0;
    eEmpleado* lista = (eEmpleado*) malloc (sizeof(eEmpleado)*TAM);
    if (lista ==  NULL)
    {
        printf("\nNo se consiguio memoria");
        system("Pause");
        exit(1);
    }
    inicializarEmpleado(lista,TAM);
    printf("\nEmpleados inicializados!");

    do{
        switch(menu())
        {
        case 1:
            cargarEmpleados(lista,TAM);
            system("pause");
            break;
        case 2:
            altaEmpleado(lista,TAM);
            system("pause");
            break;
        case 3:
            printf("\nOpcion 3\n");
            mostrarEmpleados(lista,TAM);
            system("pause");
            break;
        case 4:
            printf("\nOpcion 4\n");
            guardarEmpleadosBinarios(lista,TAM);
            system("pause");
            break;
        case 5:
            imprimirEmpleados(lista,TAM);
            system("pause");
            break;
        case 6:
            printf("\nOpcion 6\n");
            system("pause");
            exit(1);
            break;
        default:
            break;
        }
    }while( auxiliar != 6);

    free(lista);
    return 0;
}


void inicializarEmpleado(eEmpleado* vec, int tam){
    for(int i = 0 ; i < tam ; i++)
    {
        (vec+i) ->estado = 0;
    }
}
//**********************************************************************************************
//**********************************************************************************************
 eEmpleado* newEmpleado(){

 eEmpleado * emp = (eEmpleado*) malloc(sizeof(eEmpleado));//consigo memoria dinamica para un empleado
 if(emp != NULL)
 {
     emp->id = 0;
     strcpy(emp->nombre, "");
     strcpy(emp->apellido, "");
     emp->sueldo =0;// inicializo todos los campos para que no tengan basura
 }
 return emp;
 }
//**********************************************************************************************
eEmpleado* newEmpleadoParam(int id, char* nombre, char* apellido, float sueldo)
{
  eEmpleado * emp = (eEmpleado*) malloc(sizeof(eEmpleado));//consigo memoria dinamica para un empleado
 if(emp != NULL)
 {
     emp->id = id;
     strcpy(emp->nombre,nombre);
     strcpy(emp->apellido, apellido);
     emp->sueldo =sueldo;// inicializo todos los campos para que no tengan basura
    emp->estado = 1;
 }
 return emp;
}
//**********
int buscarLibre(eEmpleado* vec, int tam)
{
    int indice = -1;
    if (vec !=  NULL && tam > 0){
    for(int i = 0; i < tam; i ++)
    {
        if( (vec+i)->estado == 0 )
        {
            indice = i;
            break;
        }
    }
    }
    return indice;
}
//**********
void mostrarEmpleados(eEmpleado* vec, int tam)
{
     if (vec !=  NULL && tam > 0){
    for(int i = 0; i < tam; i ++)
    {
        if( (vec+i)->estado == 1 )
        {
            mostrarEmpleado(vec+i);
        }
    }
    }
}
//********
void mostrarEmpleado(eEmpleado* emp)
{
    if ( emp != NULL)
    {
        printf("\n %d %s %s %2.f\n",emp->id,emp->nombre,emp->apellido,emp->sueldo);
    }
}
//************
int menu()
{
    int opcion;
    system("cls");

    printf("\nMenu de opciones");
    printf("\n1_  Cargar empleados");
    printf("\n2_  Alta empleados");
    printf("\n3_  Listar empleados");
    printf("\n4_  Guardar empleados archivo");
    printf("\n5_  Imprimir empleados");
    printf("\n6_  Salir");

    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
//***********
void altaEmpleado( eEmpleado* vec, int tam)
{
    int indice;
    int auxInt;
    char auxCad[20];
    char auxCadDos[20];
    float auxFloat;
    indice = buscarLibre(vec,tam);

    if( indice == -1)
    {
        printf("\nNo hay lugar!");
    }else
    {
        printf("\nIngrese id: ");
        scanf("%d", &auxInt);

        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(auxCad);

        printf("\nIngrese apellido: ");
        fflush(stdin);
        gets(auxCadDos);

        printf("\nIngrese sueldo: ");
        scanf("%f", &auxFloat);

        eEmpleado* nuevoEmpleado = newEmpleadoParam(auxInt, auxCad, auxCadDos,auxFloat);
        if( nuevoEmpleado != NULL)
        {
            *(vec + indice) = *nuevoEmpleado;
        }
    free(nuevoEmpleado);
    }
}
//********
void imprimirEmpleados(eEmpleado* vec, int tam)
{
      if (vec !=  NULL && tam > 0){

            //tenemos que abrir un archivo
            FILE* f;
      f = fopen("./ListaEmpleados.txt", "w");
      if(f != NULL)
      {
          fprintf(f,"Id nombre apellido sueldo\n");
        for(int i = 0; i < tam; i ++)
        {
            if( (vec+i)->estado == 1 )
            {
                fprintf(f,"\n %d %s %s %2.f\n",(vec+i)->id,(vec+i)->nombre,(vec+i)->apellido,(vec+i)->sueldo);
            }
        }
      }
      fclose(f);
    }
}
//*****
void guardarEmpleadosBinarios(eEmpleado* vec, int tam)
{
      if (vec !=  NULL && tam > 0){

            //tenemos que abrir un archivo
            FILE* f;
      f = fopen("./empleados.bin", "wb");
      if(f != NULL)
      {
        for(int i = 0; i < tam; i ++)
        {
            if( (vec+i)->estado == 1 )
            {
                fwrite((vec+i),sizeof(eEmpleado), 1, f);// lo que leo, el tamaño de lo que estoy leyendo/quiero guardar, la cantidad de cosas que voy a guardar, y en donde lo voy a gardar
            }
        }
      }
      fclose(f);
    }
}
//*******************
void cargarEmpleados( eEmpleado* vec, int tam)
{
    int indice;
    FILE* f;
    int cant = 0;

    f= fopen("/.empleados.bin", "rb");
    printf("\nLogre abrir el archivo");

    while( !feof(f))
    {
        printf("\nEntro al while");
        indice = buscarLibre(vec,tam);
        printf("\nSali de buscar libre");
        cant = fread( (vec+indice), sizeof(eEmpleado), 1, f);
        if(cant < 1)
        {
            if(feof(f) )
            {
                break;
            }
        }
    }
    fclose(f);
}
