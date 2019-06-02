#include <stdio.h>
#include <stdlib.h>
//*******************************
typedef struct{
int anio;
int mes;
int dia;

}eFecha;

typedef struct{
int legajo;
char nombre[20];
float sueldo;
char sexo;
eFecha fecha;
}eEmpleado;

//******************************
int main()
{
    /*int x = 5;
    int* p = &x;

    modificarNumero(p);

    printf("%d", *p);*/ //Primera parte


    /*int vec[] = { 2,5,6,7,8};
    int variable = 10;
    funcionUno(vec,5);
    funcionDos(vec,5);
    funcionTres(vec,5);
    funcionCuatro(vec,5);*/ //segunda parte



 /*   char cadena[20]= "Esto es una cadena";
    char* p;
    p = cadena; // o
    //p = &cadena[0];
    //quiero recorrer de caracter a caracter

    while( *p != '\0'){//Lo hago sin usar un for
        printf("%c", *p);
        p++;//aritmetica de puntero
    }*/



    eEmpleado emp1 = {1234,"Juan",34000,'m',{2018,10,12}};

    eEmpleado lista[] = {
    {1234,"Juan",34000,'m',{2018,10,12}},
    {1111,"Ana",40000,'f',{2018,12,1}},
    {1432,"Mario",24000,'m',{2000,11,3}},

    };

    eEmpleado* pEmp;

    printf("\n%d", sizeof(emp1)); //la cuenta nos da 29 bytes pero el print nos dice 32.Luego de agregar fecha me tira 44
    //                           lo mas probable es que fraccione en potencias de 2
    pEmp = &emp1;

    printf("\n%s", emp1.nombre);
    printf("\n%s", pEmp -> nombre);

    printf("\n%02d/%02d/%02d\n\n",pEmp ->fecha.dia,pEmp -> fecha.mes,pEmp ->fecha.anio);// -> para acceder

    //quiero pisar el nombre
    printf("\ingrese nombre: ");
    scanf("%s", pEmp ->nombre);

    printf("%s", pEmp -> nombre);

    printf("\nIngrese nuevo sueldo:");
    scanf("%f", &pEmp ->sueldo);//pEmp ->sueldo es para referirme a la variable sueldo que esta dentro de la estructura
    //                          el & modifica a la variable sueldo por mas que esta escrita detras del puntero
    //

    printf("%.2f", pEmp -> sueldo);

    mostrarEmpleados(lista,3);
    return 0;
}


//     &X SIGNIFICA LA UBICACION DE: X
//     X* SIGNIFICA HACIA A DONDE APUNTA: X
//     PRINTF CUANDO USO LA MASCARA %P VOY A IMPRIMIR UN PUNTERO. PRINTF("%P" , &P); YA QUE &P ES LA UBICACION = DIRECCION
//     PRINTF CUANDO USO LA MASCARA %D (EN CASO DE INT) VOY A IMPRIMIR UN VALOR. PRINTF("%D", *P); YA QUE *P APUNTA A UNA VARIABLE CON VALOR INT
//********************************
/*void  modificarNumero(int * a){
*a = 25;
}
//********************************
void funcionUno( int x[], int tam){
printf("\nfuncionUno");
for(int i  = 0; i < tam; i++){

    printf("\n%d", x[i]);
}
}
//*****************************
void funcionDos(int x[], int tam){
    printf("\nfuncionDos");
for(int i = 0; i < tam; i++){

    printf("\n%d", *(x+i));
}
}
//****************************
void funcionTres(int* x, int tam){
printf("\nfuncionTres");
for(int i  = 0; i < tam; i++){

    printf("\n%d", x[i]);
}
}
//****************************
void funcionCuatro(int* x, int tam){
printf("\nfuncionCuatro");
for(int i = 0; i < tam; i++){

    printf("\n%d", *(x+i));
}
}*/ //Segunda parte

void mostrarEmpleados(eEmpleado* vec, int tam){

for(int i = 0; i < tam ; i++){

    printf("\nLegajo: %d ", (*(vec->legajo)+i));
    printf("\nNombre: %s ", *(vec+i)->nombre);
    printf("\nSueldo: %f ", vec->sueldo);
    printf("\nSexo: %c ",vec->sexo);
    printf("\nFecha: %02d/%02d/%02d \n\n",vec->fecha.dia,vec->fecha.mes,vec->fecha.anio);
}

}
