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
    /*do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;

        }
    }while(option != 10);
    return 0;*/


    Employee* emp1 = employee_newParametros("1234","Juan","234","25000");
    Employee* emp2 = employee_newParametros("2222","Julia","100","15000");
    Employee* emp3 = employee_newParametros("1111","Juana","340","35000");

    printf("\nCantidad de elementos: %d\n",ll_len(listaEmpleados) );
    if(ll_add(listaEmpleados,emp1)== 0)
    {
        printf("\nSe ha agregado el empleado a la lista!\n");
    }
    printf("\nCantidad de elementos: %d\n",ll_len(listaEmpleados) );
}
