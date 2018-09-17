#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
typedef struct
{
    int legajo;
    char nombre [50];
    float altura;
    int nota;
}eAlumno;

void cargarListaDeAlumnos(eAlumno [],  int);
void mostrarListaDeAlumnos(eAlumno[], int);
int main()
{
    eAlumno listaDeAlumnos[5];


   cargarListaDeAlumnos(listaDeAlumnos, 5);
   mostrarListaDeAlumnos(listaDeAlumnos,5);
    return 0;
}

/*
void ordenarPorNombre ( eAlumno listaDeAlumnos[], int tam)
{
    int i;
    for ( i = 0 ; i < tam ; i++)
    {

    }
}
*/
