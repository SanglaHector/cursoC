#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador;
    int numero[] = {3,2,4,5,2,6,5,4,7,1,9,3};
    FILE* f;
    int* pNum = numero;
    printf("\nDeclare las variables");
    f =  fopen("./archivoNumeros.txt","w");

    if(f == NULL)
    {
        printf("\no se consiguio puntero");
    }else
    {
        printf("\nEncontre puntero");

        for(int i = 0; i < 12 ; i++)
        {
                if( (i+1) % 4 != 0)
                {
                    fprintf(f,"%d,",numero[i]);
                }else
                {
                    fprintf(f,"%d\n",numero[i]);
                }
        }
    }

    fclose(f);
    free(f);

    return 0;
}
