#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
/* Diseñar un programa que permita calcular el promedio de un alumno sabiendo que se ingresa por alumno la nota de
6 materias y su nombre. No se sabe la cantidad de alumnos. Se pide una lista impresa que diga
NOMBRE DEL ALUMNO:                     PROMEDIO:
*/

void ingresarDatos();
void calcularPromedio();
void mostrarFichero();
int elementos = 0;
char alumnos[100][20];
int matematica[100];
int lengua[100];
int fisica[100];
int quimica[100];
int educacionF[100];
int arte[100];
int promedio[100];
char seguir = 's';

int main()
{

   /* ingresarDatos(alumnos, materiaUno, materiaDos, materiaTres, materiaCuatro, materiaCinco, materiaSeis, promedio, elementos);
    calcularPromedio(alumnos, materiaUno, materiaDos, materiaTres,materiaCuatro,materiaCinco, materiaSeis,promedio,elementos);
    mostrarFichero(alumnos, materiaUno, materiaDos, materiaTres,materiaCuatro,materiaCinco, materiaSeis,promedio,elementos);

    */
     char seguir = 's';
    int i;
    elementos = 0;
    for (i = 0; i <= elementos ; i++){
        system("cls");
        fflush(stdin);
        printf("\nIngrese el nombre del alumno: ");
        gets(alumnos[i]);

        printf("\n Ingrese la nota de Matematica: ");
        scanf("%d", &matematica[i]);
        printf("\n Ingrese la nota de Lengua: ");
        scanf("%d", &lengua[i]);
        printf("\n Ingrese la nota de Fisica: ");
        scanf("%d", &fisica[i]);
        printf("\n Ingrese la nota de Quimica: ");
        scanf("%d", &quimica[i]);
        printf("\n Ingrese la nota de Eduacacion Fisica: ");
        scanf("%d", &educacionF[i]);
        printf("\n Ingrese la nota de Arte: ");
        scanf("%d", &arte[i]);

        system("cls");

        printf("\nSi desea agregar otro alumno Conteste S/s para si o cualquier otra letra para no: ");
        fflush(stdin);
        scanf("%c", &seguir);
        if ( seguir == 'S' || seguir == 's'){
            elementos ++;
            printf("%d", elementos);
        }
    }
    for( i = 0 ; i <= elementos; i ++){
        promedio[i] = ( matematica[i] + lengua[i] + fisica[i] + quimica[i] + educacionF[i] + arte[i] ) / 6 ;
    }

    system("cls");
    printf("\n\tNombre\t\t\tPromedio ");
    for(i=0; i<=elementos; i++){
        printf("\n\t%s\t\t%d",alumnos[i],promedio[i]);
    }
    return 0;
}
/* ////////////////////////////////////////////////////////////////////////////////////////////////////////// */
void ingresarDatos(char alumnos[100][20], int matematica[100],int lengua[100],int fisica[100],int quimica[100],int educacionF[100],int arte[100], int promedio[100],int elementos){
    char seguir = 's';
    int i;
    elementos = 0;
    for (i = 0; i <= elementos ; i++){
        system("cls");
        fflush(stdin);
        printf("\nIngrese el nombre del alumno: ");
        gets(alumnos[i]);

        printf("\n Ingrese la nota de Matematica: ");
        scanf("%d", &matematica[i]);
        printf("\n Ingrese la nota de Lengua: ");
        scanf("%d", &lengua[i]);
        printf("\n Ingrese la nota de Fisica: ");
        scanf("%d", &fisica[i]);
        printf("\n Ingrese la nota de Quimica: ");
        scanf("%d", &quimica[i]);
        printf("\n Ingrese la nota de Eduacacion Fisica: ");
        scanf("%d", &educacionF[i]);
        printf("\n Ingrese la nota de Arte: ");
        scanf("%d", &arte[i]);

        system("cls");

        printf("\nSi desea agregar otro alumno Conteste S/s para si o cualquier otra letra para no: ");
        fflush(stdin);
        scanf("%c", &seguir);
        if ( seguir == 'S' || seguir == 's'){
            elementos ++;
            printf("%d", elementos);
        }
    }
}
/* ********************************************************************** */

void calcularPromedio(char alumnos[100][20], int matematica[100],int lengua[100],int fisica[100],int quimica[100],int educacionF[100],int arte[100], int promedio[100],int elementos){
    int i;
    for( i = 0 ; i < elementos; i ++){
        promedio[i] = ( matematica[i] + lengua[i] + fisica[i] + quimica[i] + educacionF[i] + arte[i] ) / 6 ;
    }
}
/* ************************************************************************ */
void mostrarFichero(char alumnos[100][20], int matematica[100],int lengua[100],int fisica[100],int quimica[100],int educacionF[100],int arte[100], int promedio[100],int elementos){
    int i;
    system("cls");
    printf("\n\tNombre\t\t\tPromedio ");
    for(i=0; i<elementos; i++){
        printf("\n\t%s\t\t%d",alumnos[i],promedio[i]);
    }
}
