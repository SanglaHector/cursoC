#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int i;
    int resultado;


    printf("Digite un numero: \n");
    scanf("%d",&numero);

    for( i = 1 ; i<=numero ; i++ )
    {
        resultado = i;
        printf("%d\n",resultado);
    }
    return 0;
}
