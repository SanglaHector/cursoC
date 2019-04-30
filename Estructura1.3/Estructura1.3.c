#include "Estructura1.3.h"
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
/*int validarChar(char vec[], int tam){
    int validar = -1
    for(int i = 0; i < tam ;  i++){
        isalpha(vec[i])

    }
}*/
//**************************************************************************************************************
int validarInt(int num,int min,int max){
    int retorno = -1;
    if ( num >= min && num <= max ){

        retorno = 1;
    }

    return retorno;
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
//**************************************************************************************************************
void menuInformes(eEmpleado vec[], int tam , eSector vecSec[], int tamSec){

    int opcion;
    do{

        printf("\nIngrese un informe: ");
        printf("\n1.Empleados por sector. ");
        printf("\n2.Empleados que gana mas por sector. ");
        printf("\n3.Empleados mas viejos. ");
        printf("\n4.Sector con mas empleados.");
        printf("\n5.Salir\n ");
        scanf("%d", &opcion);
        switch(opcion){
        case 1:
            empleadosPorSector(vec,tam,vecSec, tamSec);
            break;

        case 2:
            empleadoMasGana(vec,tam,vecSec,tamSec);
            break;

        case 3:
            empleadoMasAntiguo(vec,tam,vecSec,tamSec);
            break;

        case 4:
            sectorConMasEmpleados(vec, tam, vecSec, tamSec);
            break;

        case 5:
            printf("\nSaliendo\n");
           // system("pause");
            break;

        }

    }while(opcion != 5);
}
//**************************************************************************************************************
void empleadosPorSector(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){
    int sector;
    printf("\nIngrese un sector");
    printf("\n1.Legal");
    printf("\n2.RRHH");
    printf("\n3.Economia");
    printf("\n4.Obrero\n");
    scanf("%d", &sector);

    for(int i = 0; i < tam; i ++){

        if( vec[i].estado == OCUPADO && vec[i].sector == sector){
            mostrarE(vec[i],vecSec,tamSec);
        }
    }
}
//**************************************************************************************************************
void empleadoMasGana(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){
    int max = 0;
    int sector;
    printf("\nIngrese un sector");
    printf("\n1.Legal");
    printf("\n2.RRHH");
    printf("\n3.Economia");
    printf("\n4.Obrero\n");
    scanf("%d", &sector);


    for(int i = 0; i < tam; i ++){

        if( vec[i].estado == OCUPADO && vec[i].sueldo >= max && vec[i].sector == sector){
            max = vec[i].sueldo;
        }
    }
    for(int i = 0; i < tam; i++){

        if(vec[i].estado == OCUPADO && vec[i].sueldo == max && vec[i].sector == sector){
            mostrarE(vec[i], vecSec,tamSec);
        }
    }
}
//**************************************************************************************************************
void empleadoMasAntiguo(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){
    eFecha min = {31,12,3000};
    int sector;
    printf("\nIngrese un sector");
    printf("\n1.Legal");
    printf("\n2.RRHH");
    printf("\n3.Economia");
    printf("\n4.Obrero\n");
    scanf("%d", &sector);


    for(int i = 0; i < tam; i ++){

        if( vec[i].estado == OCUPADO && vec[i].fechaIngreso.anio <=  min.anio && vec[i].sector == sector){
            min = vec[i].fechaIngreso;
            if(vec[i].fechaIngreso.mes <=  min.mes){
                min = vec[i].fechaIngreso;
                if(vec[i].fechaIngreso.dia <= min.dia){
                    min = vec[i].fechaIngreso;
                }
            }
        }
    }
    for(int i = 0; i < tam; i++){

        if(vec[i].estado == OCUPADO && vec[i].fechaIngreso.anio == min.anio && vec[i].fechaIngreso.mes == min.mes && vec[i].fechaIngreso.dia == min.dia && vec[i].sector == sector){
            mostrarE(vec[i], vecSec,tamSec);
        }
    }
}
//**************************************************************************************************************
void sectorConMasEmpleados(eEmpleado vec[], int tam, eSector vecSec[], int tamSec){

    int sectores[3];
    /*int legal;
    int RRHH;
    int economia;
    int obrero;*/
    int max = 0;

    for(int i = 0; i < tam; i ++){

        if (vec[i].sector == 1){
            sectores[0] ++;
        }
        if (vec[i].sector == 2 ){
            sectores[1] ++;
        }
        if (vec[i].sector == 3){
            sectores[2] ++;
        }
        if (vec[i].sector == 4){
            sectores[3] ++;
        }
    }
    for(int i = 0; i < tamSec ;i++ ){

        if(sectores[i] > max){
            max = sectores[i];
        }
    }
    for(int i = 0; i < tamSec; i++){

        if(sectores[0] == max){
            printf("\nLEGAL es el sector con mas empleados con un total del %d.\n",max);
        }
        if(sectores[1] == max){
            printf("\nRRHH es el sector con mas empleados con un total del %d.\n",max);
        }
        if(sectores[2] == max){
            printf("\nECONOMIA es el sector con mas empleados con un total del %d.\n",max);
        }
        if(sectores[3] == max){
            printf("\nOBRERO es el sector con mas empleados con un total del %d.\n",max);
        }

    }
}
//*****************************************************************************************************************************
//*Almuerzos por empleados. uno elige un sector y nos muestra todos los almuerzos de ese sector = nombre, apellido
//comida y fecha.anio/
//*****************************************************************************************************************************
void  menuAlmuerzos(eEmpleado vec[], int tam, eSector vecSec[], int tamSec, eComida vecCom[], int tamMenu, eAlmuerzo vecAlm[], int tamAlm){

int opcion;
    do{

        printf("\n1.Almuerzos por empleados");
        printf("\n2.Almuerzos por sector");
        printf("\n3.");
        printf("\n4.Salir");
        scanf("%d", &opcion);
        switch(opcion){
        case 1:
            mostrarAlmuerzos(vec,tam,vecSec, tamSec, vecAlm, tamAlm, vecCom,tamMenu);
            break;

        case 2:
            comidasPorSector(vec,tam,vecSec,tamSec,vecAlm,tamAlm,vecCom,tamMenu);
            break;

        case 3:
            break;

        case 4:
            printf("\nSaliendon.\n");
            system("pause");
            break;

        }
    }while(opcion =! 4);
}
//*****************************************************************************************************************************
void mostrarAlmuerzos(eEmpleado vec[], int tam, eSector vecSec[], int tamSec, eAlmuerzo vecAlm[],int tamAlm, eComida vecCom[], int tamCom){

for(int i = 0; i < tamAlm; i++){

    mostrarAlmuerzo(vec,tam,vecSec, tamSec,vecAlm[i], vecCom,tamCom);
}}
//****************************************************************************************************************************
void mostrarAlmuerzo(eEmpleado vec[], int tam, eSector vecSec[], int tamSec, eAlmuerzo almuerzo, eComida vecCom[], int tamCom){

    char nombre[20];
    char apellido[20];
    char comida[20];
    for(int i = 0; i < tam ; i++){

        if(vec[i].estado == OCUPADO && vec[i].legajo == almuerzo.idEmpleado){
            strcpy(nombre, vec[i].nombre);
            strcpy(apellido, vec[i].apellido);
        }
    }
    for(int j = 0; j < tamCom ; j++){

        if( vecCom[j].id == almuerzo.idComida){
            strcpy(comida, vecCom[j].descripcion);
    }
    }
    printf("\nNombre: %s , Apellido: %s ,Fecha: %02d/%02d/%02d , Comida: %s\n", nombre, apellido, almuerzo.fecha.dia, almuerzo.fecha.mes, almuerzo.fecha.anio , comida);
}
//*****************************************************************************************************************************
void comidasPorSector(eEmpleado vec[], int tam, eSector vecSec[],  int tamSec, eAlmuerzo vecAlm[],int tamAlm, eComida vecCom[], int tamCom){

    int opcion;
   /* int legajo;
    int idComida;
    char nombre[20];
    char apellido[20];
    char comida[20];*/
    //char sector[20];
    printf("\n.Elija un sector\n");
    printf("\n1.Legal.\n");
    printf("\n2.RRHH.\n");
    printf("\n3.Economia.\n");
    printf("\n4.Obrero.\n");
    scanf("%d", &opcion);
    for(int i = 0; i < tam ; i++){

        if(vec[i].estado == OCUPADO && vec[i].sector == opcion){

           /* legajo = vec[i].legajo;
        }
        for(int j = 0; j < tamAlm; j++){

            if(vecAlm[j].idEmpleado == legajo){
                idComida = vecAlm[j].idComida;
            }
            for(int k = 0; k < tamCom ;k++ ){
                if(idComida == vecCom[k].id){

                    strcpy(nombre,vec[i].nombre);
                    strcpy(apellido,vec[i].apellido);
                    strcpy(comida,vecCom[k].descripcion);
                    printf("\nNombre: %s ,Apellido: %s, Comida: %s ",nombre,apellido,comida);
                }
            }
        }
    }*/
    //a partir de aqui toque todo
            mostrarAlmuerzos(vec,tam,vecSec,tamSec,vecAlm,tamAlm,vecCom,tamCom);
}}
}
