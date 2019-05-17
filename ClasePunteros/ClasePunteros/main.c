#include <stdio.h>
#include <stdlib.h>
//*******************************
int main()
{
    int x = 5;
    int* p = &x;

    modificarNumero(p);

    printf("%d", *p);
    return 0;
}
//     &X SIGNIFICA LA UBICACION DE: X
//     X* SIGNIFICA HACIA A DONDE APUNTA: X
//********************************
void  modificarNumero(int * a){
*a = 25;
}
//********************************
