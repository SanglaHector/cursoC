#include <stdio.h>
#include <stdlib.h>
/*De los alumnos de una escuela se registran su apellido, nombre y altura.Diseñar un programa que indique
el nombre del alumno mas alto y su altura
*/

int main()
{
    char nombre [4][20];
    char apellido[4][30];
    float altura[4];
    int i;
    int posicion;
    float alturaMayor;

    for ( i = 0 ;i < 5 ; i++ ){
        system("cls");
        printf("\nIngrese el nombre del alumno: ");
        fflush(stdin);
        gets(nombre[i]);

        printf("\nIngrese el apellido del alumno: ");
        fflush(stdin);
        gets(apellido[i]);

        printf("\nIngrese la altura del alumno: ");
        scanf("%f", &altura[i]);
    }
    for ( i = 0; i < 5; i++){
        if ( altura[i] > 0){
            if (altura[i] > altura[i-1]){
                alturaMayor = altura[i];
                posicion = i;
            }
        }
    }

    printf("\nEl alumno con mayor altura es:%s %s.\nCon una altura de: %2.f ", nombre[posicion], apellido[posicion], altura[posicion]);

    return 0;
}

