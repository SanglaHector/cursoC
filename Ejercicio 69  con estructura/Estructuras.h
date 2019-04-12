#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50

typedef struct eRemedio{
    char nombre [30];
    int codigo ;
    int cantidad ;
    float precio ;

}eRemedio;
/**



 **/
void getString(char* imprimo,char* string);
//**************************************************************
/**



 **/
void getInt(char* imprimo, int* vec);
//**************************************************************
/**



 **/
void getFloat(char* imprimo, float* vec);
//**************************************************************
/**
le paso un numero y me trae un indice


**/
int buscarPorCodido(int codigo, int* codigos, int tam);
//*************************************************************
/**



**/
int buscarPorNombre(char nombre,char* nombres,int tam);
//*************************************************************
/**


**/
void imprimirDatos(char* nombres, int codigos,float precios,int cantidades );
//************************************************************
/**


**/
void borrarRegistro(char* nombres, int codigos,float precios,int cantidades);

