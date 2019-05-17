#include "Estructura1.1.h"
//**************************************************************************************************************
void inicializarE(eEmpleado vec[], int tam){

    for(int i = 0; i < tam ; i++){

        vec[i].estado = VACIO;
    }
}
//**************************************************************************************************************
void altaE(eEmpleado vec[], int tam,eSector sectores[]){
    int legajo;
    int repetido;
    int validar = -1;
    int indice = buscarLibre(vec,tam);

    if (indice == -1){
        printf("\nNo hay espacio para agregar empleados.");
    }else{
        while (validar != 1){
            printf("\nIngrese el legajo: ");
            fflush(stdin);
            scanf("%d", &legajo);

            validar =  validarInt(legajo,0001,9999);
            if( validar == -1){
             printf("\nEl legajo debe estar entre 0001 y 9999.");
            }
            repetido = buscarE(vec,tam,legajo);}
        if (repetido == -1){
            vec[indice].legajo = legajo;
            pedirDatos(vec,tam,indice);

            printf("\nIngrese el sector: ");
            printf("\n1.Sistemas");
            printf("\n2.RRHH");
            printf("\n3.Legales");
            printf("\n4.Contable\n");
            scanf("%d", &vec[indice].sector);


        }else{
            printf("\nEl legajo %d ya existe: ", legajo);
            mostrarE(vec[repetido],sectores);
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
        if(vec[i].legajo == clave && vec[i].estado == OCUPADO){
            indice = i;
            break;
        }
    }
    return indice;
}
//**************************************************************************************************************
void mostrarE(eEmpleado e, eSector sectores[]){


    printf("Legajo: %d Nombre: %s Apellido: %s Sexo: %c Sueldo: %.2f Fecha: %02d/%02d/%02d Sector: %s \n",e.legajo,e.nombre,e.apellido,e.sexo,e.sueldo,e.fechaIngreso.dia,e.fechaIngreso.mes,e.fechaIngreso.anio,sectores[e.sector].descripcion);}
//**************************************************************************************************************
void bajaE(eEmpleado vec[], int tam,eSector sectores[]){
    int legajo;
    int indice;
    char seguir = 'n';
    printf("\nIngrese el legajo que quiera eliminar: ");
    scanf("%d", &legajo);
    indice = buscarE(vec,tam,legajo);
    if (indice != -1 && vec[indice].estado == OCUPADO){
        mostrarE(vec[indice],sectores);
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
void modificarE(eEmpleado vec[], int tam){
    int legajo;
    int indice;
    float sueldo;
    char seguir = 'n';
    printf("\nIngrese el legajo que quiera modificar: ");
    scanf("%d", &legajo);
    indice = buscarE(vec,tam,legajo);
    if (indice != -1 && vec[indice].estado == OCUPADO){
        mostrarE(vec[indice],sectores);
        printf("\nIngrese el nuevo sueldo del empleado: ");
        scanf("%f", &sueldo);
        printf("\nEsta seguro que desea dar de baja este empleado? S/N: ");
        fflush(stdin);
        scanf("%c",&seguir);
        seguir = toupper(seguir);
        if( seguir == 'S'){

            vec[indice].sueldo = sueldo;
            printf("\nEl empleado se ha dado de baja con exito.");
        }else {
        printf("\nLa operacion ha sido cancelada.");}

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
void mostrarEs(eEmpleado vec[], int tam, eSector sectores){
    for(int i = 0 ; i < tam ; i ++){

        if (vec[i].estado == OCUPADO){
            mostrarE(vec[i], sectores);
            }
    }
}
//**************************************************************************************************************
void altaId(eSector vec[], int tam, int indice){
    int alta = -1;
    for(int i = 0; i < tam ; i ++){

        if ( i == indice){

            printf("\nIngrese un numero correspondiente al sector: ");
            printf("\n1.Legal");
            printf("\n2.Economico");
            printf("\n3.Obrero");
            printf("\n4.Sistemas");
            scanf("%d", &vec[i].id);
            do{
                alta = aniadirDescripcion(vec,tam,indice,vec[i].id);
            }while(alta != -1);
        }
    }
}
//**************************************************************************************************************
int aniadirDescripcion(eSector vec[], int tam, int indice,int opcion){
    int alta = -1;
    char legal ="Legal";
    char economico ="Economico";
    char obrero ="Obrero";
    char sistemas ="Sistemas";
    for(int i = 0; i < tam ; i ++){

        if ( i == indice){

                switch(opcion){

                 case 1:
                    strcpy(vec[i].descripcion,legal);
                    alta = 1;
                    break;
                 case 2:
                    strcpy(vec[i].descripcion,economico);
                    alta = 1;
                    break;
                 case 3:
                    strcpy(vec[i].descripcion,obrero);
                    alta = 1;
                    break;
                 case 4:
                    strcpy(vec[i].descripcion,sistemas);
                    alta = 1;
                    break;
                 default:
                    printf("\nIngreso una opcion incorrecta para el tipo de sector.\nPor favor intente de nuevo");
            }
        }
    }
    return alta;
}
//**************************************************************************************************************
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
    int legajo;
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
//void asignarSector(eEmpleado vec[],eSector sector[],tam)
