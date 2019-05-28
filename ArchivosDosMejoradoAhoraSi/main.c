#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cant;
    /*char auxCad4[30];
    char auxCad3[30];
    char auxCad2[30];
    char auxCad1[30];*/

    char buffer[4][30];
    float auxFloat;
    FILE* f = fopen("./archivoNumeros.txt", "r");


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
        printf("%d %s %s %.2f \n", atoi(buffer[0]),buffer[1],buffer[2],atof(buffer[3]));// tengo que decir al programa para que el programa reconosca las comas

    }
    fclose(f);

    return 0;
}
