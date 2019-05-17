#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}
void insertion (int data[], int len)
{
    int i , j;
    int temp; // auxilar
    for(i=1; i<len  ; i++) // i arranca en uno, y guardo el valor en el temporal
    {   temp = data [i];
        j = i - 1;//j esta antes de i
            while(j>=0 && temp< data [j]) // temp < data////j esta mayor igual a cero y temp(donde esta i) es menor que j
            {
                data [j+1] = data [j];//
                j --;
            }
        data [j+1] = temp; // insercion
    }
}
