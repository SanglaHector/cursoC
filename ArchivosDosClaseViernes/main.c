#include <stdio.h>
#include <stdlib.h>

typedef struct{
int id;
char nombre[20];
char apellido[20];
float sueldo;
int estado;
}eEmpleado;


void mostrarEmpleados(eEmpleado** vec, int tam);
void mostrarEmpleado(eEmpleado* emp);
void imprimirEmpleados(eEmpleado* vec, int tam);
eEmpleado* newEmpleadoParam(int id, char* nombre, char* apellido, float sueldo);
void inicializarEmpleado(eEmpleado* vec, int tam);
eEmpleado* newEmpleado();
int buscarLibre(eEmpleado** vec, int tam);
int altaEmpleado( eEmpleado** vec, int size);
void guardarEmpleadosBinarios(eEmpleado** vec, int tam);
void cargarEmpleados( eEmpleado** vec, int tam);

int main()
{
    int size = 0;
    char auxiliar = 0;
    eEmpleado** auxLista;
 //   eEmpleado* lista = (eEmpleado*) malloc (sizeof(eEmpleado)*TAM);//Esto cambia todo eEmpleado lista[10]; = estatico
    eEmpleado ** lista = (eEmpleado**) malloc((sizeof(eEmpleado*))); // Ahora tengo una lista que guarda
    //direcciones de memoria da direcciones de memoria
    //Casteo lo que me devuelve malloc para guardar lo mismo que estoy poniendo (eEmpleado** ants de malloc)
    //saco el tam porque pido lugar para un solo puntero
    if (lista ==  NULL)
    {
        printf("\nNo se consiguio memoria");
        system("Pause");
        exit(1);
    }

    do{
        switch(menu())
        {
        case 1:
            //cargarEmpleados(lista,TAM);
            system("pause");
            break;
        case 2:
            if(altaEmpleado(lista,size)== 1)
            {
                size = size +1;
                auxLista = (eEmpleado**) realloc(lista ,sizeof(eEmpleado*)* (size + 1));
                if( auxLista != NULL)
                {
                    lista = auxLista;
                    printf("\nAlta Exitosa!!");
                }
            }

            system("pause");
            break;
        case 3:
            printf("\nOpcion 3\n");
            mostrarEmpleados(lista,size);//la direccion de memoria de lista y adentro de agrandar lista
            //uso la direccion de memoria  de lista!
            system("pause");
            break;
        case 4:
            printf("\nOpcion 4\n");
      //      guardarEmpleadosBinarios(lista,size);
            system("pause");
            break;
        case 5:
       //     imprimirEmpleados(lista,size);
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


/*void inicializarEmpleado(eEmpleado* vec, int tam){
    for(int i = 0 ; i < tam ; i++)
    {
        (vec+i) ->estado = 0;
    }
}*/
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
/*int buscarLibre(eEmpleado** vec, int tam)
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
}*/
//**********
void mostrarEmpleados(eEmpleado** vec, int size)//
{
     if (vec !=  NULL && size > 0){
    for(int i = 0; i < size; i ++)
    {
        printf("\nEntre al for de mostrar empleado ymuestro estado: %d",(*(vec+i))->estado );
        if( (*(vec+i))->estado == 1 )//(*(vec+i)) El contenido  de la direccion de memoria que tiene ese campo "estado"
            //(vec +i) en el programa anterior es la contenido de uno, ahora tengo que hacer un salto mas
            //ya que no tengo la estructura tan cerca
        {
            mostrarEmpleado(*(vec+i));
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
int altaEmpleado( eEmpleado** vec, int size)// si pudo o no dar de alta el empleado
{
    int todoOk = 0;

    int auxInt;
    char auxCad[20];
    char auxCadDos[20];
    float auxFloat;

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

        eEmpleado* nuevoEmpleado = newEmpleadoParam(auxInt, auxCad, auxCadDos,auxFloat);//nos consigue un espacio en
        //memoria, con los parametros los carga y nos devuelve una direccion de memoria en donde esta
        if( nuevoEmpleado != NULL)
        {
            *(vec + size) = nuevoEmpleado;//vec + size el desplazamiento y va a valer lo que trajo newEmpleado
            todoOk = 1;// pudimos dar de alta
        }

        return todoOk;
}
//**********************************************
/*void imprimirEmpleados(eEmpleado** vec, int tam)
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
}*/
//*****
/*void guardarEmpleadosBinarios(eEmpleado** vec, int tam)
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
}*/
//*******************
/*void cargarEmpleados( eEmpleado** vec, int tam)
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
}*/
/*eEmpleado** agrandarLista(eEmpleado** vec, int size)
{

    eEmpleado** aux;
    aux = (eEmpleado**) realloc( *vec,sizeof(eEmpleado*)* (size+1));//conclucion= NO ESTA BIEN PROGRAMADO
    if( aux != NULL)
    {
        vec = aux;
        todoOk = 1;
    }
    return aux;
}*/
//****************************************
/*eEmpleado** agrandarLista(eEmpleado** vec, int size)
{
    return (eEmpleado**) realloc(*vec ,sizeof(eEmpleado*)* (size + 1));
}*/
