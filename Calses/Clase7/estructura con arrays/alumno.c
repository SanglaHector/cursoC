#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>

void cargarListaDeAlumnos(eAlumno listaDeAlumnos [], int tam)
{
    int i;
    for(i = 0 ; i< tam ; i ++)
    {
        printf("Ingrese el legajo: \n");
        scanf("%d", &listaDeAlumnos[i].legajo);

        printf("Ingrese el nombre: \n");
        scanf("%s", listaDeAlumnos[i].nombre);

        printf("Ingrese la altura: \n");
        scanf("%f", &listaDeAlumnos[i].altura);

        printf("Ingrese la nota: \n");
        scanf("%d", &listaDeAlumnos[i].nota);


    }
     return 0;
}

void mostrarListaDeAlumnos(eAlumno listaDeAlumnos[], int tam)
{
    int i;
    for( i = 0 ; i < tam ; i++)
    {
            printf("%d----%s----%f----%d \n", listaDeAlumnos[i].legajo,listaDeAlumnos[i].nombre,listaDeAlumnos[i].altura,listaDeAlumnos[i].nota);
    }

    return 0;
}
