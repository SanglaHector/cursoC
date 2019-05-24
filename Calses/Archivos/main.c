#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;
    char x;
    char cadena[] = "Esto es una cadena\n";

    f = fopen("./Archivo.txt", "a");

    if( f == NULL)
    {
        printf("\nNo se pudo abrir el archivo!");
    }else
    {
        fprintf(f,cadena);
    }

    while(!feof(f))
    {
        x = fgetc(f);
        printf("%c", x);
    }
    return 0;
}
