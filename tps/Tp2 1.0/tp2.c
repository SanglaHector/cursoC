#include "tp2.h"
#include "validaciones.h"
//**************************************************************************************************************
void inicializarE(eEmpleado vec[], int tam){

    for(int i = 0; i < tam ; i++){

        vec[i].estado = VACIO;
    }
}
//**************************************************************************************************************
void altaE(eEmpleado vec[], int tam){
    int legajo;
    int repetido;
    int indice = buscarLibre(vec,tam);

    if (indice == -1){
        printf("\nNo hay espacio para agregar empleados.");
    }else{
        printf("Ingrese el legajo: ");
        fflush(stdin);
        scanf("%d", &legajo);
        repetido = buscarE(vec,tam,legajo);
        if (repetido == -1){

            vec[indice].id = legajo;

            fflush(stdin);
            printf("\nIngrese nombre: ");
            scanf("%s", vec[indice].nombre);

            fflush(stdin);
            printf("\nIngrese apellido: ");
            scanf("%s", vec[indice].apellido);

            printf("\nIngrese sueldo: ");
            scanf("%f", &vec[indice].sueldo);

            printf("\nIngrese sector: ");
            scanf("%d", &vec[indice].sector);

            fflush(stdin);

            vec[indice].estado = OCUPADO;

            printf("\nDatos ingresados con exito!");
        }else{
            printf("\nEl legajo %d ya existe: ", legajo);
            mostrarE(vec[repetido]);
        }
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
        if(vec[i].id == clave && vec[i].estado == OCUPADO){
            indice = i;
            break;
        }
    }
    return indice;
}
//**************************************************************************************************************
void mostrarE(eEmpleado e){

   // printf("\nNOMBRE   APELLIDO    SEXO  SUELDO   FECHA DE INGRESO.\n");
    printf("Legajo: %d Nombre: %s Apellido: %s  Sueldo: %.2f Sector: %d \n",e.id,e.nombre,e.apellido,e.sueldo,e.sector);}
//**************************************************************************************************************
void bajaE(eEmpleado vec[], int tam){
    int legajo;
    int indice;
    char seguir = 'n';
    printf("\nIngrese el legajo que quiera eliminar: ");
    scanf("%d", &legajo);
    indice = buscarE(vec,tam,legajo);
    if (indice != -1 && vec[indice].estado == OCUPADO){
        mostrarE(vec[indice]);
        printf("\nEsta seguro que desea dar de baja este empleado? S/N: ");
        fflush(stdin);
        scanf("%c",&seguir);
        seguir = toupper(seguir);
        if( seguir == 'S'){

            vec[indice].estado = VACIO;
            printf("\nEl empleado se ha dado de baja logica con exito.");
        }else {
        printf("\nLa operacion ha sido cancelada.");}

    }else {
        printf("\nEl legajo ingresado no se encuentra en el sistema.");
    }
}
//**************************************************************************************************************
void modificarE(eEmpleado vec[], int tam){
    int legajo;
    int indice;
    char seguir = 'n';
    printf("\nIngrese el legajo que quiera modificar: ");
    scanf("%d", &legajo);
    indice = buscarE(vec,tam,legajo);
    if (indice != -1 && vec[indice].estado == OCUPADO){

        mostrarE(vec[indice]);
        printf("\nEste es el empleado que desea modificar? S/N: ");
        fflush(stdin);
        scanf("%c", &seguir);
        seguir = toupper(seguir);
        if(seguir == 'S'){

            menuModificar(vec, indice);
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
    {1234,"Hector","Sangla",25000,3,1},
    {2222,"Alberto","Perez",15000,2,1},
    {3333,"Vanesa","Rodriguez",20000,2,1},
    {4444,"Marta","Galatti",35000,3,1},
    {5555,"Carlos","Sanchez",60000,4,1},
    {6666,"Maria","Espada",10550,4,1},
    {7777,"Leila","Casati",25000,3,1},
    {8888,"Osvaldo","Sangla",90000,4,1}
    };

    for(int i = 0; i < tam; i ++){

        vec[i] = ficticios[i];
    }
}
//**************************************************************************************************************
void mostrarEs(eEmpleado vec[], int tam){
    for(int i = 0 ; i < tam ; i ++){

        if (vec[i].estado == OCUPADO){
            mostrarE(vec[i]);
            }
    }
}
//**************************************************************************************************************
void menuInformes(eEmpleado vec[], int tam){
    system("cls");

    int opcion;
    do{
        printf("\n1.Listar empleados ordenados alfabeticamente por apellido y sector .\n");
        printf("\n2.Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
        printf("\n3.Salir.\n");
        scanf("%d", &opcion);

        switch(opcion){
    case 1:
        listarAlfabeticamente(vec,tam);
        break;

    case 2:
        totalizarSalarios(vec,tam);
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
int buscarLleno(eEmpleado vec[],  int tam){

int estado = -1;
for(int i = 0;i <tam ; i++){

    if (vec[i].estado == OCUPADO){
        estado = OCUPADO;
        break;
    }
}
return estado;
}
//***************************************************************************************************************
void menuModificar(eEmpleado vec[], int indice){

int opcion;
char seguir = 'N';
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
        printf("\n Usted ingreso: %s .Es correcto? S/N",nombreAux);
        fflush(stdin);
        scanf("%c", &seguir);
        seguir = toupper(seguir);

        if(seguir == 'S'){

            strcpy(vec[indice].nombre,nombreAux);
        }else{
            printf("\nLa operacion ha sido cancelada.\n");
        }
        mostrarE(vec[indice]);
        system("pause");

        break;

    case 2:
        fflush(stdin);
        printf("\nIngrese apellido: ");
        scanf("%s", apellidoAux);
        printf("\n Usted ingreso: %s .Es correcto? S/N",apellidoAux);
        fflush(stdin);
        scanf("%c", &seguir);
        seguir = toupper(seguir);

        if(seguir == 'S'){

            strcpy(vec[indice].apellido,apellidoAux);
        }else{
            printf("\nLa operacion ha sido cancelada.\n");
        }
         mostrarE(vec[indice]);
        system("pause");

        break;

    case 3:
        fflush(stdin);
        printf("\nIngrese sueldo: ");
        scanf("%f", &salarioAux);
        printf("\n Usted ingreso: %f .Es correcto? S/N",salarioAux);
        fflush(stdin);
        scanf("%c", &seguir);
        seguir = toupper(seguir);

        if(seguir == 'S'){

            vec[indice].sueldo = salarioAux;
        }else{
            printf("\nLa operacion ha sido cancelada.\n");
        }
         mostrarE(vec[indice]);
        system("pause");

        break;

    case 4:
        printf("\nIngrese sector: ");
        scanf("%d", &sectorAux);
        printf("\n Usted ingreso: %d .Es correcto? S/N",sectorAux);
        fflush(stdin);
        scanf("%c", &seguir);
        seguir = toupper(seguir);

        if(seguir == 'S'){

            vec[indice].sector = sectorAux;
        }else{
            printf("\nLa operacion ha sido cancelada.\n");
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
