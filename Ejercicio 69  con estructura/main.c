#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Se registran de los 50 medicamentos que existen en una farmacia el código de producto ,
el precio y la cantidad en existencia. Se pide:
a- Listado ordenado por código de producto
b- Código del medicamento de precio más bajo
*/
#define TAM 50
typedef struct eRemedio{
    char nombre [30];
    int codigo ;
    int cantidad ;
    float precio ;

}eRemedio;
void getString(char*,char*);
void getInt(char*, int*);
void getFloat(char*, float*);
int buscarPorCodido(int, int*, int);
void imprimirDatos(char*,int,float,int);
void borrarRegistro(char*,int,float,int);


int buscarPorNombre();
int main()
{
    struct eRemedio medicamentos[TAM];
    char aux [100];
    int contadorIndice = 0;
    int indice = 0;
    int opcion = 0;
    int auxCodigo = 0;
    char seguir = 'n';

    do{

            printf("*    Bienvenido al sistema de control de medicamentos  *\n");
            printf("*    Por favor, ingrese una de las siguientes opciones *\n");
            printf("*    1.Registrar nuevo medicamento                     *\n");
            printf("*    2.Modificar medicamento                           *\n");
            printf("*    3.Eliminar medicamento                            *\n");
            printf("*    4.Imprimir planilla de medicamentos               *\n");
            printf("*    5.Salir                                           *\n");
            scanf("%d", &opcion);
    switch(opcion){

        case 1:

            system("cls");

            getString("\nIngrese el nombre del medicamento: " ,medicamentos[contadorIndice].nombre);

            fflush(stdin);
            getInt("\nIngrese el codigo del medicamento: ", &medicamentos[contadorIndice].codigo);

            fflush(stdin);
            getFloat("\nIngrese el precio del medicamento: ", &medicamentos[contadorIndice].precio);

            fflush(stdin);
            getInt("\nIngrese la cantidad en existenacia de este medicamento: ", &medicamentos[contadorIndice].cantidad);

            fflush(stdin);
            printf("\nVerificacion de datos... ... ... ...");
            system("pause");
            system("cls");

            strlwr(medicamentos[contadorIndice].nombre);
            medicamentos[contadorIndice].nombre[0] = toupper(medicamentos[contadorIndice].nombre[0]);

            imprimirDatos(medicamentos[contadorIndice].nombre,medicamentos[contadorIndice].codigo, medicamentos[contadorIndice].precio, medicamentos[contadorIndice].cantidad);

            contadorIndice ++;
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            getInt("\nIngrese 1. Buscar por nombre\nIngrese 2. Burcar por codigo: \n", &opcion);

            if(opcion == 1){

                getString("\nIngrese un nombre: ",aux);
                strlwr(aux);
                aux[0] = toupper(aux[0]);
                indice = -1;

                for (int i = 0; i < TAM ; i++){

                    if (strcmp(medicamentos[i].nombre, aux) == 0){
                        indice = i;
                        }}

                if (indice >= 0 && indice < TAM){

                    imprimirDatos(medicamentos[indice].nombre, medicamentos[indice].codigo, medicamentos[indice].precio, medicamentos[indice].cantidad);

                    printf("\nReingrese los datos por favor");
                    getString("\nIngrese el nombre del medicamento: " ,medicamentos[indice].nombre);

                    fflush(stdin);
                    getInt("\nIngrese el codigo del medicamento: ", &medicamentos[indice].codigo);

                    fflush(stdin);
                    getFloat("\nIngrese el precio del medicamento: ", &medicamentos[indice].precio);

                    fflush(stdin);
                    getInt("\nIngrese la cantidad en existenacia de este medicamento: ", &medicamentos[indice].cantidad);

                    fflush(stdin);
                    printf("\nVerificacion de datos... ... ... ...");
                    system("pause");
                    system("cls");

                    strlwr(medicamentos[indice].nombre);
                    medicamentos[indice].nombre[0] = toupper(medicamentos[indice].nombre[0]);

                    imprimirDatos(medicamentos[indice].nombre, medicamentos[indice].codigo, medicamentos[indice].precio, medicamentos[indice].cantidad);
                }else {
                    printf("\nNo se encuentra medicamento con ese nombre.");}


            }else if(opcion == 2){
                printf("\nImgrese un codigo: ");
                scanf("%d", &auxCodigo);

                indice = buscarPorCodido(auxCodigo,&medicamentos.codigo,TAM);
                if (indice != -1){

                imprimirDatos( medicamentos[indice].nombre, medicamentos[indice].codigo, medicamentos[indice].precio, medicamentos[indice].cantidad);
                printf("\nReingrese los datos por favor");

                getString("\nIngrese el nombre del medicamento: " ,medicamentos[indice].nombre);

                fflush(stdin);
                getInt("\nIngrese el codigo del medicamento: ", &medicamentos[indice].codigo);

                fflush(stdin);
                getFloat("\nIngrese el precio del medicamento: ", &medicamentos[indice].precio);

                fflush(stdin);
                getInt("\nIngrese la cantidad en existenacia de este medicamento: ", &medicamentos[indice].cantidad);

                fflush(stdin);
                printf("\nVerificacion de datos... ... ... ...");
                system("pause");
                system("cls");

                strlwr(medicamentos[indice].nombre);
                medicamentos[indice].nombre[0] = toupper(medicamentos[indice].nombre[0]);

                imprimirDatos(medicamentos[indice].nombre, medicamentos[indice].codigo, medicamentos[indice].precio, medicamentos[indice].cantidad);

                }else {
                    printf("\nNo se encontro medicamento con este codigo");
                      }
            }else
            {
                printf("\nOpcion incorrecta, la oprecaion se ha cancelado");
            }
            system("pause");
            system("cls");
            break;

        case 3:

            system("cls");

            getInt("\nIngrese el codigo del medicamento que desea eliminar: ", &auxCodigo);
            indice = buscarPorCodido(auxCodigo, &medicamentos.codigo, TAM);
            if(indice == -1){
                printf("\nEl codigo no existe, la operacion ha sido cancelada");
            }else{

                imprimirDatos(medicamentos[indice].nombre, medicamentos[indice].codigo, medicamentos[indice].precio, medicamentos[indice].cantidad);
                printf("\nQuiere eliminar este registro?\nResponda S/s para si o N/n para no: ");
                scanf("%c", &seguir);

                if ( seguir == 'S' || seguir == 's'){

                    borrarRegistro(medicamentos[indice].nombre, medicamentos[indice].codigo, medicamentos[indice].precio, medicamentos[indice].cantidad);
                    imprimirDatos(medicamentos[indice].nombre, medicamentos[indice].codigo, medicamentos[indice].precio, medicamentos[indice].cantidad);
                }

            }
            system("pause");
            system("cls");
            break;

        case 4:

            system("cls");

            system("pause");
            system("cls");
            break;

        case 5:
            break;

        default:
            system("pause");
            printf("*    Error, ingrese una opcion correcta!          *\n");
    }
    }while(opcion !=5 );

    return 0;
}
