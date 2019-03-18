#include <stdio.h>
#include <stdlib.h>
#define elementos 4
/*De los alumnos de una escuela se registran su apellido, nombre y altura.Diseñar un programa que indique
el nombre del alumno mas alto y su altura
*/
void ingresarDatos();
void buscarAltura();
void resultados();
char nombre [elementos][20];
char apellido[elementos][30];
float altura[elementos];
int posicion;
float alturaMayor;
int main()
{
    ingresarDatos(nombre, apellido, altura);
    buscarAltura(nombre, apellido, altura);
    resultados(nombre, apellido, altura);
    return 0;
}
void ingresarDatos(char nombre[elementos][20],char apellido[elementos][30],float altura[elementos]){
    int i;

    for ( i = 0 ;i < elementos ; i++ ){
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
}
void buscarAltura(char nombre[elementos][20],char apellido[elementos][30],float altura[elementos],int posicion){
    int i;
    for ( i = 0; i < 5; i++){
        if ( altura[i] > 0){
            if (altura[i] > altura[i-1]){
                alturaMayor = altura[i];
                posicion = i;
            }
        }
    }
}

void resultados(char nombre[elementos][20],char apellido[elementos][30],float altura[elementos],int posicion){
    printf("\nEl alumno con mayor altura es:%s %s.\nCon una altura de: %2.f ", nombre[posicion], apellido[posicion], altura[posicion]);
}
