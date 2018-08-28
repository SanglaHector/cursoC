#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion;
    do
    {
    printf("1.Sumar\n");
    printf("2:Restar\n");
    printf("3.Multiplicacion\n");
    printf("4.Divicion\n");
    printf("5.Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    switch(opcion){
        case 1:
            printf("Es sumando!!");
        break;

        case 2:
            printf("Estoy restando!");
        break;

        case 3:
            printf("Estoy multiplicando");
        break;

        case 4:
            printf("Estoy dividiendo!");
        break;

    }
system("pause");
system("cls");
    }
    while (opcion != 5 ){
    return 0;}
}
