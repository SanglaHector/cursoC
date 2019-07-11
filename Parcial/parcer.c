#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Dominio.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_FromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    eDominio* elemento;
    char id[50];
    char fecha[60];
    char numero[50];
    char idProblema[50];
    char problema[50];
    int registro;
    while(!feof(pFile))
    {
        registro = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,fecha,numero,idProblema,problema);
        if(registro  == 5 )
        {
            elemento = d_newParametros(id,fecha,numero,idProblema,problema);
            //printf("\n%s,%s,%s,%s,%s",id,fecha,numero,idProblema,problema);//bien
            if( elemento != NULL)
            {
                ll_add(pArrayListEmployee,elemento);
                retorno ++;
            }

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
/*int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int retorno=1;
    int cant;

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
*/

