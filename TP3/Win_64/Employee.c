#include "Employee.h"
#include <stdlib.h>
#include <string.h>


int employee_setId(Employee* this,int id)// devuelve 1 si todo ok o 0 si no esta todo ok
{
    int todoOk = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}




int employee_getId(Employee* this,int* id)//SIRVE PARA OBTENER EL ID O LEERLO. GEtId me carga el id por referencia
{
    int todoOk = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}
// horas trabajadas sean postivas, nombre sea distintto de null y tenga mas de 3 caracteres
int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk  = 0;
    if(this != NULL && nombre != NULL && strlen(nombre) > 3)
    {
        strcpy(this->nombre,nombre);
        todoOk = 1;
    }
    return todoOk;
}


int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk  = 0;
    if(this != NULL && nombre != NULL )
    {
        strcpy(nombre,this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk  = 0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas =  horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk  = 0;
    if(this != NULL && horasTrabajadas != NULL && horasTrabajadas > 0)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk  = 0;
    if(this != NULL &&  sueldo > 0)
    {
        this->sueldo =  sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk  = 0;
    if(this != NULL && sueldo != NULL && sueldo > 0)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}


Employee* employee_new()//uso this para seguir utilizando el mismo nombre pero tranquilamente podriautilizar cualwuier nombre
{
    Employee* this = (Employee*) malloc(sizeof(Employee));
    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre,"");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
        return this;
    }
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)//viene como punteros a char
//para poder levantarlo de los buffer
{
    Employee* this ;
        if ( idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
        {
            this = employee_new();
            if(this != NULL || employee_setId(this, atoi(idStr)) == 1 ||employee_setNombre(this,nombreStr) ||employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)) ||employee_setSueldo(this,atoi(sueldoStr)))
                            {
                                free(this);//creo que queda apuntando null
                                this = NULL;
                            }
        }
        return this;
}

void mostrarEmpleado(Employee* emp)
{
    printf("\n%d  %s  %d  %d  \n",emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
}
