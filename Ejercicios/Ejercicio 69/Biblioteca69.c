#include "Biblioteca69.h"
void getString(char* imprimo ,char* string){

    puts(imprimo);
    fflush(stdin);
    scanf("%s",string);
    fflush(stdin);

}
//*************************************************************//
void getInt(char* imprimo, int* vec){

    puts(imprimo);
    fflush(stdin);
    scanf("%d",vec);
    fflush(stdin);

}
//*************************************************************//
void getFloat(char* imprimo, float* vec){

    puts(imprimo);
    fflush(stdin);
    scanf("%f",vec);
    fflush(stdin);

}
//*************************************************************//
int buscarPorCodido(int codigo,  int* codigos,  int tam){

int indice = -1;
            for( int i = 0; i < tam ; i ++){

                if(codigos[i] == codigo){
                    indice = i;
                }
                }
        if (indice != -1){

            return indice;
        }else {

        return -1;
              }
}
//*************************************************************//
int buscarPorNombre(char nombre,  char* nombres,int tam){

int indice = -1;

    for (int i = 0; i < tam ; i++){

        if (strcmp(nombres[i], nombre) == 0){
            indice = i;
        }}
    if (indice != -1){
        return indice;
    }else {
    return -1;
          }

}
//*************************************************************//
void imprimirDatos(char* nombres, int codigos,float precios,int cantidades ){

    printf("\nSus datos obtenidos son: ");
    printf("\nNOMBRE\t\tCODIGO\t\tPRECIO\t\tCANTIDAD");
    printf("\n%s\t%d\t\t%f\t%d\n", nombres, codigos, precios, cantidades);

}
//*************************************************************//
void borrarRegistro(char* nombres, int codigos,float precios,int cantidades){

    strcpy(nombres,"");
    codigos = 0;
    precios = 0;
    cantidades = 0;
    printf("%d codigo: ",codigos);

}
