#include "punteros.h"
#include "validacionesPunteros.h"
//**************************************************************************************************************
void inicializarE(eEmpleado* vec, int tam){

    for(int i = 0; i < tam ; i++){

        (vec+i)->estado  = VACIO;
    }
}
//**************************************************************************************************************
void altaE(eEmpleado* vec, int tam){
    int legajo;
    int repetido;
    int intAux;
    int validar = -1;
    int todoOk = 0;
    float floatAux;
    char charAux[51];
    int indice = buscarLibre(vec,tam);

    if (indice == -1){
        printf("\nNo hay espacio para agregar empleados.");
    }else{
        printf("Ingrese el legajo: ");
        fflush(stdin);

        scanf("%d", &legajo);
        validar = validarInt(legajo,1,1000);
        if(validar == 1){
            validar = -1;
            repetido = buscarE(vec,tam,legajo);

            if (repetido == -1){

                (vec+indice)->id = legajo;

                fflush(stdin);
                printf("\nIngrese nombre: ");
                scanf("%s", charAux);

                validar = validarNombre(charAux);

                if(validar == 1){
                    strcpy((vec+indice)->nombre,charAux);
                }else{
                    printf("\nEl nombre solo acepta letras.");
                    todoOk = -1;
                }

                fflush(stdin);
                printf("\nIngrese apellido: ");
                scanf("%s", charAux);

                validar = validarNombre(charAux);
                if(validar == 1){
                    strcpy((vec+indice)->apellido, charAux);
                }else{
                    printf("\nEl apellido solo acepta letras.");
                    todoOk = -1;
                }

                fflush(stdin);
                printf("\nIngrese sueldo: ");
                scanf("%f", &floatAux);
                validar = validarFloat(floatAux,8000,100000);
                if(validar == 1){
                    (vec+indice)->sueldo = floatAux;
                }else{
                    printf("\El sueldo debe estar entre los 8mil y 100mil pesos");
                    todoOk = -1;
                }
                printf("\nIngrese sector: ");
                scanf("%d", &intAux);
                validar = validarInt(intAux,1,4);
                if(validar == 1){
                    (vec+indice)->sector = intAux;
                }else{
                printf("\nEl sector puede ser: 1,2,3 o 4.");
                todoOk = -1;
                }
                fflush(stdin);

                if(todoOk == 0){

                    (vec+indice)->estado = OCUPADO;
                    formatearNombre(vec,tam,indice);
                    printf("\nDatos ingresados con exito!");
                    mostrarE((vec+indice));
                }else{
                    printf("\nLa operacion ha sido cancelada\n");
                }

            }else{
                printf("\nEl legajo %d ya existe: ", legajo);
                mostrarE((vec+repetido));
            }
        }else{
            printf("\nEl numero de legajo debe estar entre 0 y 1000.");
        }
    }
}
//**************************************************************************************************************
int buscarLibre(eEmpleado* vec, int tam){
    int indice = -1;
    for(int i = 0; i < tam ;  i++){

        if((vec+i)->estado == VACIO){
            indice = i;
            break;
        }
    }
    return indice;
}
//**************************************************************************************************************
int buscarE(eEmpleado* vec, int tam , int clave){
    int indice = -1;
    for(int i = 0; i < tam ; i++){
        if((vec+i)->id == clave && (vec+i)->estado == OCUPADO){
            indice = i;
            break;
        }
    }
    return indice;
}
//**************************************************************************************************************
void mostrarE(eEmpleado* e){

   // printf("\nNOMBRE   APELLIDO    SEXO  SUELDO   FECHA DE INGRESO.\n");
    printf("Legajo: %d Nombre: %s Apellido: %s  Sueldo: %.2f Sector: %d \n",e->id,e->nombre,e->apellido,e->sueldo,e->sector);}
//**************************************************************************************************************
void bajaE(eEmpleado* vec, int tam){
    int legajo;
    int indice;
    char seguir = 'n';
    printf("\nIngrese el legajo que quiera eliminar: ");
    scanf("%d", &legajo);
    indice = buscarE(vec,tam,legajo);
    if (indice != -1 && (vec+indice)->estado == OCUPADO){
        mostrarE(vec+indice);
        printf("\nEsta seguro que desea dar de baja este empleado? S/N: ");
        fflush(stdin);
        scanf("%c",&seguir);
        seguir = toupper(seguir);
        if( seguir == 'S'){

            (vec+indice)->estado = VACIO;
            printf("\nEl empleado se ha dado de baja logica con exito.");
        }else {
        printf("\nLa operacion ha sido cancelada.");}

    }else {
        printf("\nEl legajo ingresado no se encuentra en el sistema.");
    }
}
//**************************************************************************************************************
void modificarE(eEmpleado* vec, int tam){
    int legajo;
    int indice;
    char seguir = 'n';
    printf("\nIngrese el legajo que quiera modificar: ");
    scanf("%d", &legajo);
    indice = buscarE(vec,tam,legajo);
    if (indice != -1 && (vec+indice)->estado == OCUPADO){

        mostrarE(vec+indice);
        printf("\nEste es el empleado que desea modificar? S/N: ");
        fflush(stdin);
        scanf("%c", &seguir);
        seguir = toupper(seguir);
        if(seguir == 'S'){

            menuModificar(vec, indice, tam);
        }else {
            printf("\nLa operacion ha sido canselada.");
              }
    }
    else {
        printf("\nEl legajo ingresado no se encuentra en el sistema.");
          }
}
//**************************************************************************************************************
void hardCodear(eEmpleado vec[], int tam){
    eEmpleado ficticios[] ={
    {0001,"Hector","Sangla",25000,3,1},
    {0002,"Alberto","Perez",15000,2,1},
    {0003,"Vanesa","Rodriguez",20000,2,1},
    {0004,"Marta","Galatti",35000,3,1},
    {0005,"Carlos","Sanchez",60000,4,1},
    {0006,"Maria","Espada",10550,4,1},
    {0007,"Leila","Casati",25000,3,1},
    {1000,"Osvaldo","Sangla",90000,4,1}
    };

    for(int i = 0; i < tam; i ++){

        vec[i] = ficticios[i];
    }
}
//**************************************************************************************************************
void mostrarEs(eEmpleado* vec, int tam){
    for(int i = 0 ; i < tam ; i ++){

        if ((vec+i)->estado == OCUPADO){
            mostrarE(vec+i);
            }
    }
}
//**************************************************************************************************************
void menuInformes(eEmpleado* vec, int tam){


    int opcion;
    do{
            system("cls");
        printf("\n1.Listar empleados ordenados alfabeticamente por apellido y sector .\n");
        printf("\n2.Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
        printf("\n3.Salir.\n");
        scanf("%d", &opcion);

        switch(opcion){
    case 1:
        listarAlfabeticamente(vec,tam);
        system("pause");
        break;

    case 2:
        totalizarSalarios(vec,tam);
        system("pause");
        break;

    case 3:
        break;

    default:
        printf("\nOpcion incorrecta.\n");
        break;

        }
    }while(opcion != 3);

}
//**************************************************************************************************************
int buscarLleno(eEmpleado* vec,  int tam){

int estado = -1;
for(int i = 0;i <tam ; i++){

    if ((vec+i)->estado == OCUPADO){
        estado = OCUPADO;
        break;
    }
}
return estado;
}
//***************************************************************************************************************
void menuModificar(eEmpleado* vec, int indice, int tam){

int opcion;
int validar =  -1;
int sectorAux;
float salarioAux;
char nombreAux[51];
char apellidoAux[51];

do{
        system("cls");
    printf("\nIngrese una opcion: ");
    printf("\n1.Modificar nombre .\n");
    printf("\n2.Modificar apellido .\n");
    printf("\n3.Modificar sueldo .\n");
    printf("\n4.Modificar sector .\n");
    printf("\n5.Salir .\n");
    scanf("%d", &opcion);

    switch(opcion){

    case 1:
        fflush(stdin);
        printf("\nIngrese nombre: ");
        scanf("%s", nombreAux);
        //***************
        validar = validarNombre(nombreAux);

            if(validar == 1){
                strcpy((vec+indice)->nombre,nombreAux);
                formatearNombre(vec,tam,indice);
        }else{
            printf("\nIngrese un nombre solo con caracteres alfabeticos.La operacion ha sido cancelada.\n");
        }
        mostrarE(vec+indice);
        system("pause");

        break;

    case 2:
        fflush(stdin);
        printf("\nIngrese apellido: ");
        scanf("%s", apellidoAux);
        validar = validarNombre(apellidoAux);

            if(validar == 1){
                strcpy((vec+indice)->apellido,apellidoAux);
                formatearNombre(vec,tam,indice);
        }else{
            printf("\nIngerese un apellido solo con caracteres alfabeticos.La operacion ha sido cancelada.\n");
        }
         mostrarE(vec+indice);
        system("pause");

        break;

    case 3:
        fflush(stdin);
        printf("\nIngrese sueldo: ");
        scanf("%f", &salarioAux);
        validar = validarFloat(salarioAux,8000,100000);
            (vec+indice)->sueldo = salarioAux;
            if(validar == 1){
        }else{
            printf("\nEl salario debe estar entre 8mil y 100mil pesos.La operacion ha sido cancelada.\n");
        }
         mostrarE(vec+indice);
        system("pause");

        break;

    case 4:
        printf("\nIngrese sector: ");
        scanf("%d", &sectorAux);
        validar = validarInt(sectorAux,1,4);
        if (validar == 1){
            (vec+indice)->sector = sectorAux;
        }else{
            printf("\nLos sectores son 1,2,3 o 4. La operacion ha sido cancelada.\n");
        }
         mostrarE(vec+indice);
        system("pause");

        break;

    case 5:
        break;

    default:
        printf("\nIngrese una opcion correcta. \n");
        break;

    }

}while(opcion != 5);
}
//***************************************************************************************************************************************************************
void listarAlfabeticamente(eEmpleado* vec,int tam){

    eEmpleado empleadoAux;
    for (int i = 0; i < tam-1; i++ ){
        for(int j = i+1; j <tam ; j++){

            if((vec+i)->estado == OCUPADO && (vec+j)->estado == OCUPADO && strcmp((vec+i)->apellido,(vec+j)->apellido) > 0 ){

                empleadoAux = *(vec+i);
                *(vec+i) = *(vec+j);
                *(vec+j) = empleadoAux;

            }
            if((vec+i)->estado == OCUPADO && (vec+j)->estado == OCUPADO && strcmp((vec+i)->apellido,(vec+j)->apellido) == 0 && (vec+i)->sector > (vec+j)->sector ){

                empleadoAux = *(vec+i);
                *(vec+i) = *(vec+j);
                *(vec+j) = empleadoAux;

            }
        }
    }
    for(int i= 0;i < tam;i ++){
            if((vec+i)->estado == OCUPADO){

                mostrarE(vec+i);
            }
    }
}
//******************************************************************************************************************************************
void totalizarSalarios(eEmpleado* vec,int tam){

float promedio = 0;
int cantidadEmpleados = 0;
float acumuladorSueldos = 0;
for(int i= 0; i < tam; i++){
    if((vec+i)->estado == OCUPADO){

        acumuladorSueldos = acumuladorSueldos + (vec+i)->sueldo;
        cantidadEmpleados ++;
    }
}
promedio = (acumuladorSueldos / cantidadEmpleados);
printf("\nLa cantidad de empleados activos es de: %d ",cantidadEmpleados );
printf("\nLa suma total de los sueldos es de: %.2f",acumuladorSueldos );
printf("\nEl promedio de sueldo es de: %.2f",promedio );
printf("\nEstos son los empleados que superan el promedio de sueldo: \n");
for (int i = 0; i < tam ; i++){
    if((vec+i)->estado == OCUPADO && (vec+i)->sueldo >= promedio){

        mostrarE(vec+i);
    }
}
}
//*******************************************************************************************************************************************
void formatearNombre(eEmpleado* vec, int tam, int indice){

    strlwr((vec+indice)->nombre);
    (vec+indice)->nombre[0]=toupper((vec+indice)->nombre[0]);

    strlwr((vec+indice)->apellido);
    (vec+indice)->apellido[0]=toupper((vec+indice)->apellido[0]);
}
//**************************************************************************************************************
eEmpleado* new_EmpleadoParam(int leg, char* nombre, char sexo, float sueldo){

    eEmpleado* nuevo;

    nuevo = (eEmpleado* ) malloc(sizeof(eEmpleado));

    if( nuevo != NULL){

        nuevo->id = leg;
        strcpy(nuevo->nombre , nombre);
      //  nuevo->sexo = sexo;
        nuevo->sueldo = sueldo;
    }


    return nuevo;


}
