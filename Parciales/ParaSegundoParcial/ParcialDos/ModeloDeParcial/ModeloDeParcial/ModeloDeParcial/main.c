/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350
    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca ArrayList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.
    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
**/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "empleados.h"
int calcularSuedos(Employee* empleado);
int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();

    //cargo archivo texto


    FILE* f;

    if((f = fopen("data.csv","r")) != NULL)
    {
        if(parser_EmployeeFromText(f,listaEmpleados) != 0)
        {
            printf("\nLectura correcta!! \n");

            employee_list(listaEmpleados);

            // ya tengo todo cargado
           listaEmpleados =  ll_map(listaEmpleados,calcularSuedos);// el map tiene un error
           if(listaEmpleados != NULL)
           {
               if( employee_saveAsText("data2.csv",listaEmpleados) == 1)
               {
                   printf("\nDatos guardados correctamente!");

               }else
               {
                   printf("\nError en guardado de archivo");
               }
           }
        }else
        {
            printf("\nLa lectura del archivo no fue correcta.\n");
        }

    }else
    {
        printf("\nEl archivo no se pudo abrir correctamente.\n");
    }
return 0;
}
