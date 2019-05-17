#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra;
    int contadorA = 0;
    int contadorE = 0;
    int contadorI = 0;
    int contadorO = 0;
    int contadorU = 0;
    int i;

    for ( i = 0 ; i < 20 ; i ++){

        printf("Ingrese una letra en minuscula. \n");
        scanf("%c", &letra);


        switch ( letra ){
    case 'a':
        contadorA ++;
        break;

    case 'e':
        contadorE ++;
        break;

    case 'i':
        contadorI ++;
        break;

    case 'o':
        contadorO ++;
        break;

    case 'u':
        contadorU ++ ;
        break;
        }
    }

    printf("La cantidad de latras A es de: %d\n", contadorA);
    printf("La cantiada de letras E es de :%d \n" , contadorE);
    printf("La cantidad de letras I es de: %d \n", contadorI);
    printf("La cantidad de letras O es de: %d \n", contadorO);
    printf("La cantidad de letras U es de: %d \n" , contadorU);

    return 0;
}
