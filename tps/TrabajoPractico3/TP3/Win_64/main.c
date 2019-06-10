#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

            system("cls");
            printf("\n1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
            printf("\n2.Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
            printf("\n3.Alta de empleado");
            printf("\n4.Modificar datos de empleado");
            printf("\n5.Baja de empleado");
            printf("\n6.Listar empleados");
            printf("\n7.Ordenar empleados");
            printf("\n8.Guardar los datos de los empleados en el archivo data.csv (modo texto).");
            printf("\n9.Guardar los datos de los empleados en el archivo data.csv (modo binario).");
            printf("\n10.Salir");
            printf("\nIngrese una opcion: ");
            scanf("%d", &option);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("",listaEmpleados);
                break;
            case 3:

                if(controller_addEmployee(listaEmpleados))
                {
                    printf("\nAlta dada correctamente!!");
                }else
                {
                    printf("\nEl alta fallo");
                }
                break;
            case 4:
                if(controller_editEmployee(listaEmpleados))
                {
                    printf("\nModificacion correcta!!");
                }
                else
                {
                    printf("\nError en la modificacion");
                }
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                controller_saveAsText("",listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("",listaEmpleados);
                break;
            case 10:
                printf("\nSaliendo...");
                break;
            default:
                printf("\nIngrese una opcion correcta");
        }
        printf("\n");
        system("pause");
        printf("\n");
    }while(option != 10);
    return 0;
}
