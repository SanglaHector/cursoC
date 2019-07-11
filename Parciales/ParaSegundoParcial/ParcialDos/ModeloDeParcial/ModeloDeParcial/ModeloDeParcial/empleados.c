#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "empleados.h"
#include "LinkedList.h"

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
//*******************************************************************************************************************************
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
//*******************************************************************************************************************************
int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk  = 0;
    if(this != NULL && nombre != NULL && strlen(nombre) >= 2 && validarNombre(nombre))// agregar al ir una funcion que valide nombre
    {
        formatearNombre(nombre);
        strcpy(this->nombre,nombre);
        todoOk = 1;
    }
    return todoOk;
}
//*******************************************************************************************************************************
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
//*******************************************************************************************************************************
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk  = 0;
    if(this != NULL && horasTrabajadas > 0 )// agregar al if una funcion que valide int
    {
        this->horasTrabajadas =  horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}
//*******************************************************************************************************************************
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
//*******************************************************************************************************************************
int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk  = 0;
    if(this != NULL &&  sueldo > 0)// agregar al if una funcion que valide int
    {
        this->sueldo =  sueldo;
        todoOk = 1;
    }
    return todoOk;
}
//*******************************************************************************************************************************
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
//*******************************************************************************************************************************
Employee* employee_new()//uso this para seguir utilizando el mismo nombre pero tranquilamente podriautilizar cualwuier nombre
{
    Employee* this = (Employee*) malloc(sizeof(Employee));
    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre,"");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this;
}
//*******************************************************************************************************************************
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)//viene como punteros a char
{
    Employee* this ;
        if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL)
        {
            this  = employee_new();

            if( this != NULL){

            if( !employee_setId(this, atoi(idStr))||
                !employee_setNombre(this, nombreStr) ||
                !employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)))
                       {
                            free(this);
                            this = NULL;
                       }
            }
        }
        return this;
}
//*******************************************************************************************************************************
void mostrarEmpleado(Employee* empleado)
{
    int auxId;
    char auxEmpleado[100];
    int auxHoras;
    employee_getHorasTrabajadas(empleado,&auxHoras);
    employee_getNombre(empleado,auxEmpleado);
    employee_getId(empleado,&auxId);
    printf("\n%10d%10s%10d",auxId,auxEmpleado,auxHoras);
}
//*******************************************************************************************************************************
void mostrarEmpleados(LinkedList* lista)
{
    Node* nodo;
    Employee* empleado;
    if ( lista->pFirstNode !=NULL)
    {
        nodo = lista->pFirstNode;
        for(int i = 0 ; i < lista->size;i++)
        {
            empleado = nodo->pElement;
            mostrarEmpleado(empleado);
            nodo = nodo->pNextNode;
        }
    }else
    {
        printf("\nNo hay empleados cargados!");
    }
}
//**************************************************************************************************************
int porId(Employee* empleadoUno, Employee* empleadoDos)
{
    int retorno = -1;
    if(empleadoDos != NULL && empleadoUno != NULL)
    {
        if(empleadoUno->id > empleadoDos->id)
        {
            retorno = 1;
        }
    }
    return retorno;
}
//**************************************************************************************************************
int porNombre(Employee* empleadoUno, Employee* empleadoDos)
{
    if(strcmpi( empleadoUno->nombre , empleadoDos->nombre) > 0 )
        {
         return 1;
        }
        if(strcmpi( empleadoUno->nombre , empleadoDos->nombre) < 0 )
        {
         return -1;
        }
        return 0;
}
//**************************************************************************************************************
int porHorasTrabajadas(Employee* empleadoUno, Employee* empleadoDos)
{
        if(empleadoUno->horasTrabajadas > empleadoDos->horasTrabajadas)
        {
         return 1;
        }
        if(empleadoUno->horasTrabajadas < empleadoDos->horasTrabajadas)
        {
         return -1;
        }
        return 0;
}
//**************************************************************************************************************
int porSueldos(Employee* empleadoUno, Employee* empleadoDos)
{
    if(empleadoUno->sueldo > empleadoDos->sueldo)
        {
         return 1;
        }
        if(empleadoUno->sueldo < empleadoDos->sueldo)
        {
         return -1;
        }
        return 0;
}
//**************************************************************************************************************
int employee_add (LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    char bufferNombre[100];
    char bufferId[50];
    char bufferHorasTrabajadas[50];
    Employee* nuevoEmpleado;

    sprintf(bufferId,"%d",generadorId(pArrayListEmployee));

    printf("\nIngrese el nombre del empleado: ");
    fflush(stdin);
    scanf("%s",bufferNombre);
    fflush(stdin);

    printf("\nIngrese las horas trabajadas del empleado: ");
    fflush(stdin);
    scanf("%s",bufferHorasTrabajadas);
    fflush(stdin);

    if( isDigit(bufferHorasTrabajadas) )
    {
        nuevoEmpleado = employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas);
    }else
    {
        printf("\nPor favor solo ingrese digitos numericos en los campos sueldo y horas trabajadas.\n");
    }

    strcpy(bufferId,"");
    strcpy(bufferNombre,"");
    strcpy(bufferHorasTrabajadas,"");

    if(nuevoEmpleado != NULL)
    {
        ll_add(pArrayListEmployee, nuevoEmpleado);
        mostrarEmpleado(nuevoEmpleado);
        retorno = 1;
    }
    return retorno;
}
//**************************************************************************************************************
/*int employee_edit(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    char bufferId[50];
    char bufferNombre[50];
    char bufferHoras[50];
    char bufferSueldo[50];

    int id = 0;
    int retorno = 0;
    int tope = ll_len(pArrayListEmployee);
    printf("\nEliga un empleado por su id: ");
    printf("\n        Id    Nombre  H.Trabaj    Sueldo");
    for( int i = 0; i < tope; i ++)//// cambiar tengo que agregar el header al binario o sacarselo al data
    {
        auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
        mostrarEmpleado(auxEmployee);
    }
    printf("\nEliga un empleado por su id: ");
    scanf("%d", &id);

    if( id > 0 && id <= tope)
    {
        for( int i = 0; i < tope ; i ++)// rompe si le pongo cero
        {
            auxEmployee = ll_get(pArrayListEmployee,i);
            if(auxEmployee!= NULL &&  auxEmployee->id == id )
            {
                mostrarEmpleado(auxEmployee);
                printf("\nIngrese el nuevo nombre del empleado: ");
                fflush(stdin);
                scanf("%s",bufferNombre);

                printf("\nIngrese las nuevas horas trabajadas  del empleado: ");
                fflush(stdin);
                scanf("%s",bufferHoras);

                printf("\nIngrese el nuevo sueldo del empleado: ");
                fflush(stdin);
                scanf("%s",bufferSueldo);
                fflush(stdin);

                sprintf(bufferId, "%d", auxEmployee->id);

                auxEmployee = employee_newParametros(bufferId,bufferNombre,bufferHoras,bufferSueldo);
                if(auxEmployee != NULL)
                {
                    retorno = 1;
                    auxEmployee = ll_get(pArrayListEmployee,i);
                    if(auxEmployee != NULL)
                    {
                        auxEmployee ->id = atoi(bufferId);
                        strcpy(auxEmployee ->nombre, bufferNombre);
                        auxEmployee->horasTrabajadas = atoi(bufferHoras);
                        auxEmployee->sueldo = atoi(bufferSueldo);
                    }
                   // ll_remove(pArrayListEmployee,i);
                   // ll_push(pArrayListEmployee,i,auxEmployee);

                    break;
                }else
                {
                    printf("\nLa inserccion de nuevos datos no fue correcta.");
                    break;
                }
            }
        }
    }
    return retorno;
}*/
//**************************************************************************************************************
int employee_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int indice;
    int id;
    char seguir;
    Employee* auxEmployee;
    int tope = ll_len(pArrayListEmployee);
    printf("\n        Id    Nombre  H.Trabaj    Sueldo");
    for( int i = 0; i < tope; i ++)
    {
        auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
        mostrarEmpleado(auxEmployee);
    }
    printf("\nEliga un empleado por su id: ");
    scanf("%d", &id);
    if( id > 0 && id <= tope)
    {
        for( int i = 0; i < tope ; i ++)// aca depende de como lo ponga me cambia la forma binaria o texto
        {
            auxEmployee = ll_get(pArrayListEmployee,i);
            if(auxEmployee->id == id && auxEmployee != NULL)
            {
                mostrarEmpleado(auxEmployee);
                printf("\nEsta seguro que desea ejecutar la baja? Ingrese S/N");
                fflush(stdin);
                scanf("%c", &seguir);
                if(seguir == 's' || seguir == 'S')
                {
                    indice = ll_indexOf(pArrayListEmployee,auxEmployee);
                    if(indice >= 0)
                    {
                        ll_remove(pArrayListEmployee,indice);
                        retorno = 1;
                        break;
                    }else
                    {
                        retorno = 0;
                        break;
                    }
                }
            }
        }
    }


    return retorno;
}
//**************************************************************************************************************
int employee_list(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int contador = 0;
    int tope= ll_len(pArrayListEmployee);
    //printf("\n        Id    Nombre  H.Trabaj    Sueldo");
    for( int i = 0; i < tope; i ++)
    {
        auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
        //printf("  %d",i);
        mostrarEmpleado(auxEmployee);
        contador ++;
        if(contador == 200)
        {
            printf("\nEl registro de empleados es muy grande ser visualizado en su totalidad");
            printf("\n");
            system("pause");
            contador = 0;
        }
    }
    return 1;
}
//**************************************************************************************************************
int employee_sort(LinkedList* pArrayListEmployee)
{
    Employee* empleadoUno;
    Employee* empleadoDos;
    int opcion;
    do
    {
        printf("\n1.Ordenar ascendente por Id");
        printf("\n2.Ordenar descendente por Id");
        printf("\n3.Ordenar ascendente por nombre");
        printf("\n4.Ordenar descendente por nombre");
        printf("\n5.Ordenar ascendente por horas trabajadas");
        printf("\n6.Ordenar descendente por horas trabajadas");
        printf("\n7.Ordenar ascendente por sueldo");
        printf("\n8.Ordenar descendente por sueldo");
        printf("\n9.Salir");
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            ll_sort(pArrayListEmployee,porId,1);
            mostrarEmpleados(pArrayListEmployee);
            break;

        case 2:
            ll_sort(pArrayListEmployee,porId,0);
            mostrarEmpleados(pArrayListEmployee);
            break;

        case 3:
            ll_sort(pArrayListEmployee,porNombre,1);
            mostrarEmpleados(pArrayListEmployee);
            break;

        case 4:
            ll_sort(pArrayListEmployee,porNombre,0);
            mostrarEmpleados(pArrayListEmployee);
            break;

        case 5:
            ll_sort(pArrayListEmployee,porHorasTrabajadas,1);
            mostrarEmpleados(pArrayListEmployee);
            break;

        case 6:
            ll_sort(pArrayListEmployee,porHorasTrabajadas,0);
            mostrarEmpleados(pArrayListEmployee);
            break;

        case 7:
            ll_sort(pArrayListEmployee,porSueldos,1);
            mostrarEmpleados(pArrayListEmployee);
            break;

        case 8:
            ll_sort(pArrayListEmployee,porSueldos,0);
            mostrarEmpleados(pArrayListEmployee);
            break;

        case 9:
            break;

        default:
            break;
        }
    }while( opcion != 9);

    return 1;
}
//*************************************************************************************************************
int employee_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno=0;
    int i;
    Employee* p;
    if(path!=NULL&&pArrayListEmployee!=NULL)
        {
            pFile = fopen(path, "w");
            if(pFile!=NULL)
            {

                fprintf(pFile,"%s,%s,%s,%s\n","id","nombre","horasTrabajadas","sueldo");
                printf("\nlen: %d", ll_len(pArrayListEmployee));

                for( i=0;  i < ll_len(pArrayListEmployee) ; i++)
                {
                    p = (Employee*)ll_get(pArrayListEmployee, i);
                    fprintf(pFile,"%d,%s,%d,%.2f\n",p->id,p->nombre,p->horasTrabajadas,p->sueldo);
                }
            }else
            {
                printf("\nNo se pudo abrir el archivo de salida");
            }
        if(i==ll_len(pArrayListEmployee)){
            retorno=1;
        }
        }
    fclose(pFile);
    return retorno;
}
//**************************************************************************************************************
int employee_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    f = fopen(path, "wb");
    Employee* pEmpleado;
    int retorno = 0;
    int i;
    int idAux;
    //fwrite("Id Nombre HorasTrabajadas Sueldo",sizeof(Employee),1,f);// header
    if(path!=NULL && f!=NULL && pArrayListEmployee!=NULL ){
            for(i=0; i<ll_len(pArrayListEmployee) ;i++){
            pEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(pEmpleado,&idAux);
            if(pEmpleado != NULL)
            {
                fwrite(pEmpleado, sizeof(Employee), 1, f);
            }
        }
        if(i==ll_len(pArrayListEmployee)){
            retorno=1;
        }
    }
    fclose(f);
    return retorno;
}
//**************************************************************************************************************
/** \brief Genera automaticamente el id
*
*   \param pArrayListEmployee LinkedList*
*   \return int
*
*/
int generadorId(LinkedList* pArrayListEmployee)
{
    Employee* empAux;
    int size;
    int auxId;
    int maxID = 0;
    int i;
    if(pArrayListEmployee != NULL)
    {
        size = ll_len(pArrayListEmployee);
        for(i=0 ; i<size ; i++)
        {
            empAux = ll_get(pArrayListEmployee, i);// le tiro el array y el indice y me devuelve el elemento
            if(empAux != NULL)
            {
                employee_getId(empAux, &auxId);//le tiqe toro el elmento y donde quiero guardar el id y me lo guarda donde le dije
                if(auxId > maxID)
                {
                    maxID = auxId;
                }
            }
        }
    }
    maxID = maxID + 1;
    return maxID;
}
//**************************************************************************************************************
int calcularSuedos(Employee* empleado)
 {
     int retorno = 0;
     float primerasHorasValor = 180;
     float segundasHorasValor = 240;
     float tercerasHorasValor = 350;
     float horas = empleado->horasTrabajadas;
     float sueldoFinal;

     if(horas > 0 && horas <= 120)
     {
         sueldoFinal = horas * primerasHorasValor;
         empleado->sueldo = sueldoFinal;
         retorno = 1;
     }
     else if(horas > 0 && horas <= 160)
     {
         horas - 120;
         sueldoFinal = (horas * segundasHorasValor) + ( 120 * primerasHorasValor);
         empleado->sueldo = sueldoFinal;
         retorno = 1;
     }
     else if(horas > 0 && horas <= 240)
     {
        sueldoFinal =  120*primerasHorasValor + 40* segundasHorasValor + (horas - 160)*tercerasHorasValor;
        empleado->sueldo = sueldoFinal;
        retorno = 1;
     }
     return retorno;
 }

