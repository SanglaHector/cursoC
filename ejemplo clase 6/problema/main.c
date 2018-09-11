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
// para que quede acomodado
// printf("%4d %20s %2d %4f \n","legajos","nombres"," nota","altura");
//      for(--------)
//          {printf("%4d %20s %2d %4f \n", legajos[i] , nombres[i] , nota[i] , altura[i]);
//
