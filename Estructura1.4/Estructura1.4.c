#include "Estructura1.4.h"
//**************************************************************************************************************
void inicializarE(eEmpleado vec[], int tam){

    for(int i = 0; i < tam ; i++){

        vec[i].estado = VACIO;
    }
}
//**************************************************************************************************************
void altaE(eEmpleado vec[], int tam, eSector secVec[], int tamsec){
    int legajo;
    int repetido;
    int indice = buscarLibre(vec,tam);

    if (indice == -1){
        printf("\nNo hay espacio para agregar empleados.");
    }else{
            printf("\nIngrese el legajo: ");
            fflush(stdin);
            scanf("%d", &legajo);

            repetido = buscarE(vec,tam,legajo);}
        if (repetido == -1){
            vec[indice].legajo = legajo;
            pedirDatos(vec,tam,indice);
            printf("\nIngrese un sector");
            printf("\n1.Legal");
            printf("\n2.RRHH");
            printf("\n3.Economia");
            printf("\n4.Obrero");
            scanf("%d", &vec[indice].sector);

        }else{
            printf("\nEl legajo %d ya existe: ", legajo);
            mostrarE(vec[repetido], secVec, tamsec);
        }
    }
//**************************************************************************************************************
int buscarLibre(eEmpleado vec[], int tam){
    int indice = -1;
    for(int i = 0; i < tam ;  i++){

        if(vec[i].estado == VACIO){
            indice = i;
            break;
        }
    }
    return indice;
}
//**************************************************************************************************************
int buscarE(eEmpleado vec[], int tam , int clave){
    int indice = -1;
    for(int i = 0; i < tam ; i++){
        if(vec[i].legajo == clave && vec[i].estado == OCUPADO){
            indice = i;
            break;
        }
    }
    return indice;
}
//**************************************************************************************************************
void mostrarE(eEmpleado e, eSector vecSec[], int tamSec){

char sector[20];
   // printf("\nNOMBRE   APELLIDO    SEXO  SUELDO   FECHA DE INGRESO.\n");
   for(int i = 0; i < tamSec; i++){

    if ( vecSec[i].id == e.sector){

        strcpy(sector,vecSec[i].descripcion);
    }
   }
    printf("\nLegajo: %d Nombre: %s Apellido: %s Sexo: %c Sueldo: %.2f Fecha: %02d/%02d/%02d Sector: %s\n\n\n",e.legajo,e.nombre,e.apellido,e.sexo,e.sueldo,e.fechaIngreso.dia,e.fechaIngreso.mes,e.fechaIngreso.anio,sector);}
//**************************************************************************************************************
void bajaE(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){
    int legajo;
    int indice;
    char seguir = 'n';
    printf("\nIngrese el legajo que quiera eliminar: ");
    scanf("%d", &legajo);
    indice = buscarE(vec,tam,legajo);
    if (indice != -1 && vec[indice].estado == OCUPADO){
        mostrarE(vec[indice], vecSec,tamSec);
        printf("\nEsta seguro que desea dar de baja este empleado? S/N: ");
        fflush(stdin);
        scanf("%c",&seguir);
        seguir = toupper(seguir);
        if( seguir == 'S'){

            vec[indice].estado = VACIO;
            printf("\nEl empleado se ha dado de baja con exito.");
        }else {
        printf("\nLa operacion ha sido cancelada.");}

    }else {
        printf("\nEl legajo ingresado no se encuentra en el sistema.");
    }
}
//**************************************************************************************************************
void modificarE(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){
    int legajo;
    int indice;
    int opcion;
    int sector;
    float sueldo;
    char seguir = 'n';
    printf("\nIngrese el legajo que quiera modificar: ");
    scanf("%d", &legajo);
    indice = buscarE(vec,tam,legajo);
    if (indice != -1 && vec[indice].estado == OCUPADO){
        mostrarE(vec[indice],vecSec, tamSec);
        printf("\nIngrese la opcion a modifica: \n");
        printf("1.Sueldo \n");
        printf("2.Sector \n");
        scanf("%d", &opcion);
        if (opcion == 1){

            printf("\nIngrese el nuevo sueldo del empleado: ");
            scanf("%f", &sueldo);
            printf("\nEsta seguro que desea modificar este empleado? S/N: ");
            fflush(stdin);
            scanf("%c",&seguir);
            seguir = toupper(seguir);
            if( seguir == 'S'){

                vec[indice].sueldo = sueldo;
                printf("\nEl empleado se ha modificado con exito.");
            }else {
                printf("\nLa operacion ha sido cancelada.");}
        }if (opcion == 2){

            printf("\nIngrese un sector");
            printf("\n1.Legal");
            printf("\n2.RRHH");
            printf("\n3.Economia");
            printf("\n4.Obrero");
            scanf("%d", &sector);

            printf("\nEsta seguro que desea modificar este empleado? S/N: ");
            fflush(stdin);
            scanf("%c",&seguir);
            seguir = toupper(seguir);
            if( seguir == 'S'){

                vec[indice].sector = sector;
                printf("\nEl empleado se ha modificado con exito.");
            }else {
                printf("\nLa operacion ha sido cancelada.");}
        }

    }else {
        printf("\nEl legajo ingresado no se encuentra en el sistema.");
    }
}
//**************************************************************************************************************
void hardCodear(eEmpleado vec[], int tam){
    eEmpleado ficticios[] ={
    {1234,25000,"Hector","Sangla",'m',{20,10,2018},1,1},
    {2222,15000,"Alberto","Perez",'m',{5,6,2006},1,2},
    {3333,20000,"Vanesa","Rodriguez",'f',{9,11,2010},1,2},
    {4444,35000,"Marta","Galatti",'f',{23,4,1998},1,3},
    {5555,60000,"Carlos","Sanchez",'m',{10,7,2014},1,4},
    {6666,10550,"Maria","Espada",'f',{16,8,2011},1,4}
    };

    for(int i = 0; i < tam; i ++){

        vec[i] = ficticios[i];
    }
}
//**************************************************************************************************************
void mostrarEs(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){
    for(int i = 0 ; i < tam ; i ++){

        if (vec[i].estado == OCUPADO){
            mostrarE(vec[i],vecSec,tamSec);
            }
    }
}
//**************************************************************************************************************
void pedirDatos(eEmpleado vec[], int tam, int indice){
    int validar = -1;

            fflush(stdin);
            printf("\nIngrese nombre: ");
            scanf("%s", vec[indice].nombre);

            fflush(stdin);
            printf("\nIngrese apellido: ");
            scanf("%s", vec[indice].apellido);

            printf("\nIngrese sueldo: ");
            scanf("%f", &vec[indice].sueldo);

            fflush(stdin);
            printf("\nIngrese sexo: ");
            scanf("%c", &vec[indice].sexo);
            fflush(stdin);

    while( validar == -1){
            printf("\nIngrese anio de ingreso: ");
            scanf("%d", &vec[indice].fechaIngreso.anio);
            validar = validarInt(vec[indice].fechaIngreso.anio,1900,2100);
            if( validar == -1){

             printf("\nEl año de ingreso debe estar entre 1900 y 2100.");
            }
            }
            validar = -1;
    while( validar == -1){
            printf("\nIngrese mes de ingreso: ");
            scanf("%d", &vec[indice].fechaIngreso.mes);
            validar = validarInt(vec[indice].fechaIngreso.mes,1,12);
            if( validar == -1){

             printf("\nEl mes de ingreso es incorrecto.");
            }
    }
            validar = -1;
     while( validar == -1){
            printf("\nIngrese dia de ingreso: ");
            scanf("%d", &vec[indice].fechaIngreso.dia);
            validar = validarInt(vec[indice].fechaIngreso.dia,1,31);

            if( validar == -1){
             printf("\nEl dia de ingreso es incorrecto.");
            }
     }
            vec[indice].estado = OCUPADO;
            printf("\nDatos ingresados con exito!\n");
}
//*****************************************************************************************************************************
//***************************************************************************************************************
void menuModificar(eEmpleado vec[], int indice, int tam){

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
                strcpy(vec[indice].nombre,nombreAux);
                formatearNombre(vec,tam,indice);
        }else{
            printf("\nIngrese un nombre solo con caracteres alfabeticos.La operacion ha sido cancelada.\n");
        }
        mostrarE(vec[indice]);
        system("pause");

        break;

    case 2:
        fflush(stdin);
        printf("\nIngrese apellido: ");
        scanf("%s", apellidoAux);
        validar = validarNombre(apellidoAux);

            if(validar == 1){
                strcpy(vec[indice].apellido,apellidoAux);
                formatearNombre(vec,tam,indice);
        }else{
            printf("\nIngerese un apellido solo con caracteres alfabeticos.La operacion ha sido cancelada.\n");
        }
         mostrarE(vec[indice]);
        system("pause");

        break;

    case 3:
        fflush(stdin);
        printf("\nIngrese sueldo: ");
        scanf("%f", &salarioAux);
        validar = validarFloat(salarioAux,8000,100000);
            vec[indice].sueldo = salarioAux;
            if(validar == 1){
        }else{
            printf("\nEl salario debe estar entre 8mil y 100mil pesos.La operacion ha sido cancelada.\n");
        }
         mostrarE(vec[indice]);
        system("pause");

        break;

    case 4:
        printf("\nIngrese sector: ");
        scanf("%d", &sectorAux);
        validar = validarInt(sectorAux,1,4);
        if (validar == 1){
            vec[indice].sector = sectorAux;
        }else{
            printf("\nLos sectores son 1,2,3 o 4. La operacion ha sido cancelada.\n");
        }
         mostrarE(vec[indice]);
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
void listarAlfabeticamente(eEmpleado vec[],int tam){

    eEmpleado empleadoAux;
    for (int i = 0; i < tam-1; i++ ){
        for(int j = i+1; j <tam ; j++){

            if(vec[i].estado == OCUPADO && vec[j].estado == OCUPADO && strcmp(vec[i].apellido,vec[j].apellido) > 0 ){

                empleadoAux = vec[i];
                vec[i] = vec[j];
                vec[j] = empleadoAux;

            }
            if(vec[i].estado == OCUPADO && vec[j].estado == OCUPADO && strcmp(vec[i].apellido,vec[j].apellido) == 0 && vec[i].sector > vec[j].sector ){

                empleadoAux = vec[i];
                vec[i] = vec[j];
                vec[j] = empleadoAux;

            }
        }
    }
    for(int i= 0;i < tam;i ++){
            if(vec[i].estado == OCUPADO){

                mostrarE(vec[i]);
            }
    }
}
//******************************************************************************************************************************************
void totalizarSalarios(eEmpleado vec[],int tam){

float promedio = 0;
int cantidadEmpleados = 0;
float acumuladorSueldos = 0;
for(int i= 0; i < tam; i++){
    if(vec[i].estado == OCUPADO){

        acumuladorSueldos = acumuladorSueldos + vec[i].sueldo;
        cantidadEmpleados ++;
    }
}
promedio = (acumuladorSueldos / cantidadEmpleados);
printf("\nLa cantidad de empleados activos es de: %d ",cantidadEmpleados );
printf("\nLa suma total de los sueldos es de: %.2f",acumuladorSueldos );
printf("\nEl promedio de sueldo es de: %.2f",promedio );
printf("\nEstos son los empleados que superan el promedio de sueldo: \n");
for (int i = 0; i < tam ; i++){
    if(vec[i].estado == OCUPADO && vec[i].sueldo >= promedio){

        mostrarE(vec[i]);
    }
}
}
//*******************************************************************************************************************************************
void formatearNombre(eEmpleado vec[], int tam, int indice){

    strlwr(vec[indice].nombre);
    vec[indice].nombre[0]=toupper(vec[indice].nombre[0]);

    strlwr(vec[indice].apellido);
    vec[indice].apellido[0]=toupper(vec[indice].apellido[0]);
}
