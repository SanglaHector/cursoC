#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int  menu(int numero){

    system("color 3e");
    printf("*****\tBienbvenido al programa de actualizacion de empleados.\t*****");
    printf("\n");
    printf("\n*****\tIngrese una de las siquientes opciones: \t\t*****");
    printf("\n");
    printf("\n*****\t1. Ingrese un nuevo empleado.\t\t\t\t*****");
    printf("\n");
    printf("\n*****\t2. Modifique los datos de uno de los empleados.\t\t*****");
    printf("\n");
    printf("\n*****\t3. Elimine uno de los empleados.\t\t\t*****");
    printf("\n");
    printf("\n*****\t4. Calcular horas trabajadas.   \t\t\t*****");
    printf("\n");
    printf("\n*****\t5.Salir.\t\t\t\t\t\t*****");
    printf("\n");

    fflush(stdin);
    scanf("%d", &numero);
    getchar();
    while ( numero != 1 && numero != 2 && numero != 3 && numero != 4 && numero != 5){
            system("cls");
            system("color 4f");
            printf("\nOpcion incorrecta,por favor ingrese una opcion valida\n: ");
            fflush(stdin);
            scanf("%d", &numero);
    }

    system("color 3e");
    return numero;
 }
 /*/******************************************************************************** */

 void ingresarEmpleado(char nombre[30], char apellido[30], int salario)
 {
     system("cls");
     printf("\nIngrese el nombre del empleado: ");
     fflush(stdin);
     gets(nombre);
     printf("\nIngrese el Apellido del empleado: ");
     fflush(stdin);
     gets(apellido);
 }
 /* ////////////////////////////////////////////////////////////////////////////////////// */
 void imprimirDatosIngresados(char nombre[30], char apellido[30], int salario,  int legajo)
 {
     system("cls");
     printf("\n NOMBRE \t\t APELLIDO \t\t SUELDO/HORA \t LEGAJO ");
     printf("\n %s \t\t %s \t\t %d \t %d ", nombre , apellido, salario, legajo);
 }
 /* ////////////////////////////////////////////////////////////////////////////////////// */
 void modificarDatos(int legajo , char nombre[30],  char apellido[30], int salario,  int legajoInterno){
    char seguir;
    system("cls");
    printf("\nIngrese N para modificar el nombre, A para modificar el apellido o S para modificar el salario: ");
    fflush(stdin);
    scanf("%c", &seguir);
    toupper(seguir);

    switch(seguir){
        case 'N':
            fflush(stdin);
            printf("\nIngrese el nombre del empleado: ");
            gets(nombre);
            printf("\nNombre: %s",  nombre);
            break;

        case 'n':
            fflush(stdin);
            printf("\nIngrese el nombre del empleado: ");
            gets(nombre);
            printf("\nEl programa esta cortando aca.");
            printf("\nNombre: %s",  nombre);
            break;

        case 'A':
            printf("\nIngrese el apellido del empleado: ");
            fflush(stdin);
            gets(apellido);
            break;

        case 'a':
            printf("\nIngrese el apellido del empleado: ");
            fflush(stdin);
            gets(apellido);
            break;
        case 'S':

            printf("\nIngrese el salario por hora de el empleado: ");
            scanf("%d", &salario);
            break;

        case 's':
            printf("\nIngrese el salario por hora de el empleado: ");
            scanf("%d", &salario);
            break;

        default:
            printf("\nUsted ingreso una opcion invalida.");
    }
 }
