#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[30];
    char apellido[30];
    float sueldo;
}eEmpleado;

int main()
{
    eEmpleado* lista = (eEmpleado*) malloc(sizeof(eEmpleado));
    eEmpleado* auxEmpleado;
    FILE* f = fopen("./archivoNumeros.txt", "r");

    int cont = 0;
    int cant;
    char buffer[4][30];


    if ( f == NULL)
    {
        printf("\No se pudo abrir el archivo");
        exit(1);
    }


    fscanf(f,"%[^,],%[^,],%[^,],%[^\n],",buffer[0],buffer[1],buffer[2], buffer[3]);//Con esto no hago nada, solo leo el ancabezado
    printf("%s %s %s %.s \n", buffer[0],buffer[1],buffer[2],buffer[3]);//muestro el encabezado del archivo de entrada

    while(!feof(f))
    {
        cant = fscanf(f,"%[^,],%[^,],%[^,],%[^\n],",buffer[0],buffer[1],buffer[2], buffer[3]);



        if(cant < 4)
        {
            if (feof(f))
            {
                break;
            }
            else
            {
                printf("\nProbelmas para leer el archivo\n");
                break;
            }
        }
        (lista + cont )->id = atoi(buffer[0]);
        strcpy((lista+cont)->nombre,buffer[1]);
        strcpy((lista+cont)->apellido,buffer[2]);
        (lista + cont )->sueldo = atof(buffer[3]);
        cont ++;

        auxEmpleado = (eEmpleado*) realloc(lista,sizeof(eEmpleado)*(cont+1));//siempre de lo que tengo 1 mas

        if (auxEmpleado != NULL)
        {
            lista = auxEmpleado;
        }
        //printf("%d %s %s %.2f \n", atoi(buffer[0]),buffer[1],buffer[2],atof(buffer[3]));// tengo que decir al programa para que el programa reconosca las comas

    }
    fclose(f);

    for(int i = 0;)

    return 0;
}
