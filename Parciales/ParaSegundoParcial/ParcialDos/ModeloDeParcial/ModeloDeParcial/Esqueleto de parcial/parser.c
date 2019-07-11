#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* empleado;
    char id[50];
    char nombre[50];
    char horas[50];
    char sueldo[50];
    int registro;
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
    while(!feof(pFile))
    {
        registro = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
        if(registro == 4)
        {
            empleado = employee_newParametros(id,nombre,horas,sueldo);
            ll_add(pArrayListEmployee,empleado);
            retorno ++;
        }else
        {
            retorno = 0;
            break;
        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int retorno=1;
    int cant;

   /* do{
        auxEmployee= employee_new();
        if(auxEmployee!=NULL){
            cant = fread(auxEmployee, sizeof(Employee), 1, pFile);

            if(cant<1)
            {
                if(!feof(pFile))
                    retorno=0;
                break;
            }
            if(ll_add(pArrayListEmployee, auxEmployee) == 0)
            {
                retorno=1;
            }
        }
    }while(!feof(pFile));*/
    while(!feof(pFile))
    {
        auxEmployee= employee_new();
        if(auxEmployee!=NULL){
            cant = fread(auxEmployee, sizeof(Employee), 1, pFile);

            if(cant<1)
            {
                if(!feof(pFile))
                    retorno=0;
                break;
            }
            if(ll_add(pArrayListEmployee, auxEmployee) == 0)
            {

                retorno=1;
            }
        }
    }
    fclose(pFile);
    return retorno;
}
