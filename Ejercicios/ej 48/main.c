#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ej48.c"
#include "ej48.h"
#define elementos 100
/*
Escribe un programa que calcule el salario semanal de cada trabajador de una empresa dada la tarifa horaria
y el numero de horas trabajadas ademas del nombre(dependiendo el dia, los trabajadores ganan mas o menos). Se debe preguntar al usuario cuando dejar de ingresar datos.
Ademas al final tambien informar la cantidad de salarios calculados y cual es el salario de cada uno de los
empelados. */

int main()
{
    int opcion;
    struct eEmpleados empleados[elementos];
    int i = 0;
    int empleadosRegistrados = 1;
    char seguir;
    int legajo;
    do{
        system("cls");
        opcion = menu(opcion);
    switch(opcion){
        case 1:
            for ( i = 0; i <= empleadosRegistrados; i++)
                {
                    ingresarEmpleado(empleados[i].nombre, empleados[i].apellido, empleados[i].salario);
                    empleados[i].legajo = empleadosRegistrados;
                    printf("\nIngrese el sueldo por hora del empleado: ");
                    scanf("%d",  &empleados[i].salario);
                    imprimirDatosIngresados(empleados[i].nombre, empleados[i].apellido, empleados[i].salario, empleados[i].legajo);

                    printf("\n\nSi desea agregar otro empleado precion 'S', para salir al menu precione otra tecla: ");
                    fflush(stdin);
                    scanf("%c",  &seguir);
                    if(seguir == 'S' || seguir == 's')
                        {
                            empleadosRegistrados ++;
                        }
                    else
                        {
                            break;
                        }
                }
            break;
        case 2:
            printf("\nIngrese el numero de legajo del empleado el cual quiere modificar sus datos: ");
            scanf("%d", &legajo);
            modificarDatos(empleados[legajo].legajo,empleados[legajo].nombre, empleados[legajo].apellido, empleados[legajo].salario,legajo);
            printf("\nLos datos se han modificado de la siquiente manera: ");
            imprimirDatosIngresados(empleados[legajo].nombre, empleados[legajo].apellido, empleados[legajo].salario, empleados[legajo].legajo);
            break;
        case 3:
 //           eliminarEmpleado();
            break;
        case 4:
//            calcularHoras();
            break;

        }
    }while (opcion != 5);
    return 0;
}
