#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
# define T 3
int main()
{
   /* produco:
        marca
        precio
        vencimiento
        dimenciones
        tipo
        codigo
        etc // plantear el modelo de negocio de un problema
        //Como hacemos para registrar esta informacion?
        //*/

        //Vectores paralelos: vectores que se corresponden entre si, en donde cada elemento de un vector tiene relacion
        //en donde el elemento cero del vector a se corresponde con el vector cero del vector b y del vector c
        //

        int legajos[10];
        char nombres[10][21];   //nombres[10] solo puedo guardar nombres de un solo tipo, o un  solo nombre. Tengo que definir una matriz!!
        int nota[10];
        float altura [10];
        int i;

        for ( i = 0 ; i < T ; i++)
        {//En el mismo for pido todos los datos
            printf("Ingrese legajo: ");
            scanf("%d",&legajos[i]);
            printf("Ingrese el nombre: ");
            fflush(stdin);//En el siguiente paso tengo que ser riguroso, si pongo gets(nombres) guardo todo la matriz, entonces tengo que aclarar en que fila
            gets(nombres[i]);
            printf("Ingrese la nota : ");
            scanf("%d",&nota[i]);
            printf("Ingrese altura: ");
            scanf("%f",&altura[i]);
        }
        //Muestro los datos, hago otro for para recorrer los arrays

        printf("Legajo Nombre  Nota  Altura\n");
        for(i=0;i< T;i++)
        {
            printf("%d  %s  %d  %f\n", legajos[i] , nombres[i],nota[i],altura[i]);
        }fflush("stdio");

    return 0;
}

void cargarAlumnos(int[],char [][21],int [], float[], int);//prototipo

void cargarAlumnos(int legajos[],char nombres [][21],int notas [], float altura[], int i)
{
   for ( i = 0 ; i < T ; i++)
   {
            printf("Ingrese legajo: ");
            scanf("%d",&legajos[i]);
            printf("Ingrese el nombre: ");
            fflush(stdin);
            printf("Ingrese la nota : ");
            scanf("%d",&nota[i]);
            printf("Ingrese altura: ");
            scanf("%f",&altura[i]);
            return 0;
}

void mostrarAlumnos()
{
         for(i=0;i< T;i++)
        {
            printf("%d  %s  %d  %f\n", legajos[i] , nombres[i],nota[i],altura[i]);
        }fflush("stdio");

    return 0;
} //Que pasa si quiero agregar otro dato? por ejemplo el mail?
// Tengo que cambiar el prototipo, la funcion y todo el trabajo de mantenimiento. Si tengo que una matriz con 500 variables se me vbuelve demaciado costoso y complicado.

//Hacer funciona para ordenar por orden,
//funcion que muestre los alumno aprobados(mayor a 6)
//muestre los alumnoque se llaman juan
//muestr los alumnos cuyo nombre comienza con P
//Todo esto en un menu de opciones.
//El alumno con mas nota(sabiendo que puede ser mas que uno)
//el mas mediocre legajo = 100 nota 0 5 pepe y mide 1.75
//ingresar un legajo y permitir la modificacion de la nota. si no lo ecuentra no existe
//transoformar la carga de datos en una carga aleatoria)
